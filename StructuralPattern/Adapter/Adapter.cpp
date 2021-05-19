#include<iostream>
#include<string>

class Banner
{
public:
    std::string s;
    Banner() = default;
    Banner(std::string st) : s(st) {}

    void PrintString()
    {
        std::cout << "(" << s << ")" << std::endl;
    }
};

class Print
{
public:
    virtual void PrintWeak() = 0;
    virtual void PrintStrong() = 0;
};

class PrintBanner : public Banner, public Print
{
public:
    PrintBanner(std::string s) : Banner(s) { }

    void PrintStrong() override
    {
        std::cout << "**********************" << std::endl;
        PrintString();
        std::cout << "**********************" << std::endl;
    }

    void PrintWeak() override
    {
        PrintString();
    }
};

int main()
{
    std::string s = "test";
    Print* p = new PrintBanner(s);

    std::cout << "Weak 배너" << std::endl;
    p->PrintStrong();
    std::cout << std::endl << std::endl;
    std::cout << "strong 배너" << std::endl;
    p->PrintWeak();
    return 0;
}