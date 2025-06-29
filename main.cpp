#include <iostream>
#include <vector>
#include <cmath>
#include <stdexcept>

// Forward declarations of Shape classes
class Circle;
class Rectangle;
class Triangle;
class CompoundShape;

// Abstract Visitor class
class ShapeVisitor {
public:
    virtual void visit(Circle& c) = 0;
    virtual void visit(Rectangle& r) = 0;
    virtual void visit(Triangle& t) = 0;
    virtual void visit(CompoundShape& cs) = 0;
};

// Abstract Shape class
class Shape {
public:
    virtual void accept(ShapeVisitor& visitor) = 0;
    virtual ~Shape() = default;  // Virtual destructor
};

// Concrete Shape classes
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getRadius() const { return radius; }

    void accept(ShapeVisitor& visitor) override {
        visitor.visit(*this); // Call the visitor's visit method for Circle
    }
};

class Rectangle : public Shape {
private:
    double width, height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getWidth() const { return width; }
    double getHeight() const { return height; }

    void accept(ShapeVisitor& visitor) override {
        visitor.visit(*this); // Call the visitor's visit method for Rectangle
    }
};

class Triangle : public Shape {
private:
    double a, b, c;

public:
    Triangle(double sideA, double sideB, double sideC) : a(sideA), b(sideB), c(sideC) {
        if (a + b <= c || a + c <= b || b + c <= a) {
            throw std::invalid_argument("Invalid triangle sides: The sum of any two sides must be greater than the third side.");
        }
    }

    double getA() const { return a; }
    double getB() const { return b; }
    double getC() const { return c; }

    void accept(ShapeVisitor& visitor) override {
        visitor.visit(*this); // Call the visitor's visit method for Triangle
    }
};

// CompoundShape: A composite of shapes
class CompoundShape : public Shape {
private:
    std::vector<Shape*> shapes;

public:
    void addShape(Shape* shape) {
        shapes.push_back(shape);
    }

    void accept(ShapeVisitor& visitor) override {
        visitor.visit(*this); // Calls the visitor's visit method for CompoundShape
        for (auto shape : shapes) {
            shape->accept(visitor); // Visit all contained shapes
        }
    }
};

// Concrete Visitor for Area Calculation and XML Export
class ShapeOperationsVisitor : public ShapeVisitor {
public:
    void visit(Circle& c) override {
        double area = 3.14 * c.getRadius() * c.getRadius(); // Area = π * r^2
        std::cout << "Circle Area: " << area << std::endl;
    }

    void visit(Rectangle& r) override {
        double area = r.getWidth() * r.getHeight(); // Area = width * height
        std::cout << "Rectangle Area: " << area << std::endl;
    }

    void visit(Triangle& t) override {
        double s = (t.getA() + t.getB() + t.getC()) / 2;  // Semi-perimeter
        double area = sqrt(s * (s - t.getA()) * (s - t.getB()) * (s - t.getC())); // Heron's formula
        std::cout << "Triangle Area: " << area << std::endl;
    }

    void visit(CompoundShape& cs) override {
        std::cout << "<CompoundShape>" << std::endl;
    }

    // XML export
    void exportXML(Circle& c) {
        std::cout << "<Circle>" << std::endl;
        std::cout << "  <Radius>" << c.getRadius() << "</Radius>" << std::endl;
        std::cout << "</Circle>" << std::endl;
    }

    void exportXML(Rectangle& r) {
        std::cout << "<Rectangle>" << std::endl;
        std::cout << "  <Width>" << r.getWidth() << "</Width>" << std::endl;
        std::cout << "  <Height>" << r.getHeight() << "</Height>" << std::endl;
        std::cout << "</Rectangle>" << std::endl;
    }

    void exportXML(Triangle& t) {
        std::cout << "<Triangle>" << std::endl;
        std::cout << "  <SideA>" << t.getA() << "</SideA>" << std::endl;
        std::cout << "  <SideB>" << t.getB() << "</SideB>" << std::endl;
        std::cout << "  <SideC>" << t.getC() << "</SideC>" << std::endl;
        std::cout << "</Triangle>" << std::endl;
    }
};

// Client code
int main() {
    try {
        // Create shapes with dynamic values
        Circle circle(5.0);
        Rectangle rectangle(4.0, 6.0);
        Triangle triangle(3.0, 4.0, 5.0);  // Valid triangle

        // Create compound shape
        CompoundShape compound;
        compound.addShape(&circle);
        compound.addShape(&rectangle);
        compound.addShape(&triangle);

        // Create the visitor for both area calculation and XML export
        ShapeOperationsVisitor operationsVisitor;

        // Calculate areas and export to XML
        std::cout << "Calculating areas and exporting shapes..." << std::endl;
        circle.accept(operationsVisitor);
        rectangle.accept(operationsVisitor);
        triangle.accept(operationsVisitor);
        compound.accept(operationsVisitor);

        // Export XML
        std::cout << "\nExporting shapes to XML..." << std::endl;
        operationsVisitor.exportXML(circle);
        operationsVisitor.exportXML(rectangle);
        operationsVisitor.exportXML(triangle);

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
