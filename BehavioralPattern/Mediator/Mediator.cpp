#include<iostream>
#include<list>
#include<string>

// Mediator 인터페이스
class Colleague;
class Mediator
{
public:
    virtual void AppendUser(Colleague* colleague) = 0;
    virtual void RemoveUser(Colleague* colleague) = 0;
    virtual void sendMessage(const char* message, Colleague* sender) = 0;
};

// Colleague 인터페이스
class Colleague
{
public:
    Colleague(std::shared_ptr<Mediator> m, const char* name) : name_(name)
    {
        mediator_ = std::move(m);
    }

public:
    virtual void SendMessages(const char* str) = 0;
    virtual void ReceiveMessages(const char* str) = 0;

protected:
    std::shared_ptr<Mediator> mediator_;
    std::string name_;
};

// User 상속 클래스
class User : public Colleague
{
public:
    User(std::shared_ptr<Mediator> m, const char* name) : Colleague(m, name) {}

public:
    void SendMessages(const char* str) override
    {
        std::cout << name_ << " SEND : " << str << std::endl;
        mediator_->sendMessage(str, this);
    }

    void ReceiveMessages(const char* str) override
    {
        std::cout << name_ << " RECEIVE : " << str << std::endl;
    }
};

// ChatMediator 상속 클래스
class ChatMediator : public Mediator
{
public:
    ChatMediator() = default;
    void AppendUser(Colleague* colleague) override
    {
        list_.push_back(colleague);
    }

    void RemoveUser(Colleague* colleague) override
    {
        list_.remove(colleague);
    }

    void sendMessage(const char* message, Colleague* sender)
    {
        for (Colleague* object : list_)
        {
            if (object != sender)
            {
                object->ReceiveMessages(message);
            }
        }
    }

private:
    std::list<Colleague*> list_;
};

int main()
{
    std::shared_ptr<ChatMediator> chatMediator(new ChatMediator());

    User user1(chatMediator, "A");
    User user2(chatMediator, "B");
    User user3(chatMediator, "C");

    chatMediator->AppendUser(&user1);
    chatMediator->AppendUser(&user2);
    chatMediator->AppendUser(&user3);

    user1.SendMessages("HELLO!");
    std::cout << std::endl;

    user2.SendMessages("HI!");
    std::cout << std::endl;

    user3.SendMessages("TEST!");
    std::cout << std::endl;
    return 0;
}