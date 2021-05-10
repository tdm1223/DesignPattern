#include<iostream>
#include<memory>
#include<string>

class Robot
{
public:
    virtual ~Robot() = default;
    virtual std::string getName() const = 0;
};

class RobotA : public Robot
{
    std::string getName() const override
    {
        return "RobotA";
    }
};
class RobotB : public Robot
{
    std::string getName() const override
    {
        return "RobotB";
    }
};

class RobotC : public Robot
{
    std::string getName() const override
    {
        return "RobotC";
    }
};

class RobotFactory
{
public:
    virtual ~RobotFactory() = default;
    virtual std::unique_ptr<Robot> MakeRobot() const = 0;
};

class RobotAFactory : public RobotFactory
{
public:
    std::unique_ptr<Robot> MakeRobot() const override
    {
        return std::make_unique<RobotA>();
    }
};
class RobotBFactory : public RobotFactory
{
public:
    std::unique_ptr<Robot> MakeRobot() const override
    {
        return std::make_unique<RobotB>();
    }
};
class RobotCFactory : public RobotFactory
{
public:
    std::unique_ptr<Robot> MakeRobot() const override
    {
        return std::make_unique<RobotC>();
    }
};

class RobotStore final
{
public:
    RobotStore(std::unique_ptr<RobotFactory>&& robotMaker)
        : robotFactory_(std::move(robotMaker))
    {}

    void ChangeRobotMaker(std::unique_ptr<RobotFactory>&& creator)
    {
        robotFactory_ = std::move(creator);
    }

    void PrintRobotName() const
    {
        std::cout << "Maked robot's name : " << robotFactory_->MakeRobot()->getName() << std::endl;
        std::cout << std::endl;
    }

private:
    std::unique_ptr<RobotFactory> robotFactory_;
};

int main()
{
    RobotStore store(std::make_unique<RobotAFactory>());

    std::cout << "==== Robot Factory ====" << std::endl;
    store.PrintRobotName();

    store.ChangeRobotMaker(std::make_unique<RobotBFactory>());
    store.PrintRobotName();

    store.PrintRobotName();

    store.ChangeRobotMaker(std::make_unique<RobotCFactory>());
    store.PrintRobotName();
    return 0;
}