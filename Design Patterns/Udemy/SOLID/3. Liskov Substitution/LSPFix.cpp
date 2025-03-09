#include <iostream>

class Shape
{
public:
    virtual int area() const = 0;
    virtual ~Shape() = default;
};

class Rectangle : public Shape
{
protected:
    int width, height;
public:
    Rectangle(const int width, const int height)
        : width{width}, height{height} { }

    int get_width() const { return width; }
    void set_width(const int width) { this->width = width; }
    int get_height() const { return height; }
    void set_height(const int height) { this->height = height; }

    int area() const override { return width * height; }
};

class Square : public Shape
{
private:
    int size;
public:
    Square(int size) : size{size} {}

    void set_size(int newSize) { size = newSize; }
    int area() const override { return size * size; }
};

struct ShapeFactory
{
    static Rectangle create_rectangle(int w, int h) { return Rectangle(w, h); }
    static Square create_square(int size) { return Square(size); }
};

void process(Shape& shape)
{
    std::cout << "Area = " << shape.area() << std::endl;
}

int main()
{
    Rectangle r = ShapeFactory::create_rectangle(5, 5);
    process(r);

    Square s = ShapeFactory::create_square(5);
    process(s);

    return 0;
}
