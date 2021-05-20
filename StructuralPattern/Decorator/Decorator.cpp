#include<iostream>
#include<memory>

/* Component (interface) */
class Widget
{
public:
    virtual void Draw() = 0;
    virtual ~Widget() = default;
};

/* ConcreteComponent */
class TextField : public Widget
{
private:
    int width;
    int height;

public:
    TextField(int w, int h)
    {
        width = w;
        height = h;
    }

    void Draw() override
    {
        std::cout << "TextField: " << width << ", " << height << '\n';
    }
};

/* Decorator (interface) */
class Decorator : public Widget
{
private:
    Widget* widget; // reference to Widget

public:
    Decorator(Widget* w)
    {
        widget = w;
    }

    void Draw() override
    {
        widget->Draw();
    }

    ~Decorator()
    {
        delete widget;
    }
};

/* ConcreteDecoratorA */
class BorderDecorator : public Decorator
{
public:
    BorderDecorator(Widget* w) : Decorator(w) { }
    void Draw() override
    {
        Decorator::Draw();
        std::cout << "BorderDecorator" << '\n';
    }
};

/* ConcreteDecoratorB */
class ScrollDecorator : public Decorator
{
public:
    ScrollDecorator(Widget* w) : Decorator(w) { }
    void Draw() override
    {
        Decorator::Draw();
        std::cout << "ScrollDecorator" << '\n';
    }
};

int main()
{
    auto widget = std::unique_ptr<Widget>(new BorderDecorator(new ScrollDecorator(new TextField(80, 24))));
    widget->Draw();
    return 0;
}