#include<iostream>

// SUBSYSTEM
class Bios final
{
public:
    static void operation()
    {
        std::cout << "\t- BIOS Loading..." << std::endl;
    }
};

class Cpu final
{
public:
    static void operation()
    {
        std::cout << "\t- CPU Loading..." << std::endl;
    }
};

class Memory final
{
public:
    static void operation()
    {
        std::cout << "\t- MEMORY Loading..." << std::endl;
    }
};

class Ssd final
{
public:
    static void operation()
    {
        std::cout << "\t- SSD Loading..." << std::endl;
    }
};

// FACADE
class Computer final
{
public:
    Computer() = default;

    void booting()
    {
        std::cout << "+Computer Booting Start" << std::endl;

        Bios::operation();
        Cpu::operation();
        Memory::operation();
        Ssd::operation();
        std::cout << "+Computer Booting Complete" << std::endl;
    }
};

int main()
{
    Computer computer;
    computer.booting();
    return 0;
}