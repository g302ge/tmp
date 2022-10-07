#include <iostream>

template <typename T>
struct processor;

void handle(double value)
{
    std::cout << "handle the double value " << value << std::endl;
}

template <typename T>
struct Parser
{
    void parse()
    {
        // bind the overread function in double parameter type
        // because the definition is fist appearence at the template definition
        // handle is the non-dependent name in template parameters
        handle(42);
    }
};

void handle(int value)
{
    std::cout << "handle the int value" << value << std::endl;
}

// to fix the name resolve problem we shoul make the dependent relationship exiplictly

template <typename T>
struct handler
{
    void handle(T value)
    {
        std::cout << "handler<T> handle the value" << value << std::endl;
    }
};

template <typename T>
struct CacheParser
{
    void parse(T arg)
    {
        arg.handle(42);
    }
};

template <>
struct handler<double>
{
    void handle(double value)
    {
        std::cout << "handle the double value " << value << std::endl;
    }
};

template <>
struct handler<int>
{
    void handle(int value)
    {
        std::cout << "handle the int value " << value << std::endl;
    }
};

template <typename T>
struct BasicParser
{
    void init()
    {
        std::cout << "init generic" << std::endl;
    }
};

template <typename T>
struct InheritParser : public BasicParser<T>
{
    void handle()
    {
        this->init();
        std::cout << "parsed " << std::endl;
    }
};

template <>
struct BasicParser<double>
{
    void init()
    {
        std::cout << "init in double specialized" << std::endl;
    }
};

template <typename T>
struct CarryTypeBase
{
    using value_type = T;
};

template <typename T>
struct RealParser : public CarryTypeBase<T>
{
    void parse()
    {
        // use the carried name should use the typename prefix
        typename CarryTypeBase<T>::value_type v{};
        std::cout << "init" << std::endl;
    }
};

// nested template
template <typename T>
struct NestedBaseParser
{

    template <typename U>
    void init()
    {
        std::cout << "init in generic" << std::endl;
    }

    template <>
    void init<double>()
    {
        std::cout << "init in specialized" << std::endl;
    }
};

template <typename T>
struct NestedChildParser : public NestedBaseParser<T>
{
    void parse()
    {
        // X::template foo<T>(), this->template foo<T>(),  obj.template foo<T>()
        // is correct usage in nested template
        this->template init<T>();
        std::cout << "parsed " << std::endl;
    }
};

int main()
{
    Parser<int> parser;
    parser.parse();

    std::cout << "fix it " << std::endl;

    // trisition type for the type resloution
    CacheParser<handler<int>> fixed_parser;
    handler<int> handler;
    fixed_parser.parse(handler);

    std::cout << "inherit transition" << std::endl;
    InheritParser<int> int_parser;
    InheritParser<double> double_parser;
    int_parser.handle();
    double_parser.handle();

    std::cout << "carry the type to subclass" << std::endl;
    RealParser<int> real_parse;
    real_parse.parse();

    std::cout << "nested init " << std::endl;
    NestedChildParser<double> nested_parser;
    nested_parser.parse();

    return 0;
}