class Singleton
{
public: static Singleton& instance()
{
    // 객체를 사용할때까지 초기화를 미룬다.
    if (instance_ == nullptr)
    {
        instance_ = new Singleton();
    }
    return *instance_;
}
private: 
    Singleton() {}
    static Singleton* instance_;
};

class Singleton
{
public:
    static Singleton& instance()
    {
        static Singleton* instance = new Singleton();
        return *instance;
    }
private:
    Singleton() {}
};