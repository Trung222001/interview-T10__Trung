#include <iostream>

class Shape {
public:
    // Phương thức ảo pure virtual để tính diện tích
    virtual double calculateArea() const = 0;

    // Phương thức ảo pure virtual để tính chu vi
    virtual double calculatePerimeter() const = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    // Constructor để khởi tạo bán kính
    Circle(double r) : radius(r) {}

    // Override calculateArea để tính diện tích của hình tròn
    double calculateArea() const override {
        return 3.14 * radius * radius;
    }

    // Override calculatePerimeter để tính chu vi của hình tròn
    double calculatePerimeter() const override {
        return 2 * 3.14 * radius;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    // Constructor để khởi tạo chiều dài và chiều rộng
    Rectangle(double l, double w) : length(l), width(w) {}

    // Override calculateArea để tính diện tích của hình chữ nhật
    double calculateArea() const override {
        return length * width;
    }

    // Override calculatePerimeter để tính chu vi của hình chữ nhật
    double calculatePerimeter() const override {
        return 2 * (length + width);
    }
};

int main() {
    // Tạo đối tượng hình tròn và hiển thị diện tích và chu vi
    Circle circle(5);
    std::cout << "dien tich hinh tron: " << circle.calculateArea() << std::endl;
    std::cout << "chu vi hinh tron: " << circle.calculatePerimeter() << std::endl;

    // Tạo đối tượng hình chữ nhật và hiển thị diện tích và chu vi
    Rectangle rectangle(4, 6);
    std::cout << "dien tich hinh chu nhat: " << rectangle.calculateArea() << std::endl;
    std::cout << "chu vi hinh chu nhat: " << rectangle.calculatePerimeter() << std::endl;

    return 0;
}
