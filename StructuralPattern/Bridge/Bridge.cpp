#include<iostream>

class Drawing
{
public:
    virtual void drawLine(int x, int y) = 0;
    virtual void fill() = 0;
};

class RectDrawing : public Drawing
{
    void drawLine(int x, int y)
    {
        std::cout << "Rect Draw line from " << x << " to " << y << std::endl;
    }

    void fill()
    {
        std::cout << "Rect fill" << std::endl;
    }
};

class CircleDrawing : public Drawing
{
    void drawLine(int x, int y)
    {
        std::cout << "Circle Draw line from " << x << " to " << y << std::endl;
    }

    void fill()
    {
        std::cout << "Circle fill" << std::endl;
    }
};

class Shape {
public:
    virtual void draw() = 0;
    virtual ~Shape() = default;
    Shape(Drawing* drawing)
    {
        this->drawing = drawing;
    }
    void drawLine(int x, int y)
    {
        drawing->drawLine(x, y);
    }
    void fill()
    {
        drawing->fill();
    }
private:
    Drawing* drawing;
};

class Rectangle : public Shape
{
public:
    Rectangle(Drawing* drawing) : Shape(drawing) { }

    void draw()
    {
        std::cout << "Rect draw extend" << std::endl;
    }
};

class Circle : public Shape
{
public:
    Circle(Drawing* drawing) : Shape(drawing) { }

    void draw()
    {
        std::cout << "Circle draw extend" << std::endl;
    }
};

int main()
{
    Shape* rectangle = new Rectangle(new RectDrawing());
    Shape* circle = new Circle(new CircleDrawing());

    rectangle->drawLine(1, 2);
    rectangle->fill();
    rectangle->draw();

    circle->drawLine(3, 4);
    circle->fill();
    circle->draw();

    delete rectangle;
    delete circle;
    return 0;
}