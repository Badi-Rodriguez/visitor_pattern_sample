#include "AreaVisitor.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "CompoundShape.h"
#include <iostream>
#include <cmath>

namespace visitor_sample {
void AreaVisitor::visit(Circle& c) {
    double area = pi * c.getRadius() * c.getRadius();
    std::cout << "Circle Area: " << area << std::endl;
}
void AreaVisitor::visit(Rectangle& r) {
    double area = r.getWidth() * r.getHeight();
    std::cout << "Rectangle Area: " << area << std::endl;
}
void AreaVisitor::visit(Triangle& t) {
    double s = (t.getA() + t.getB() + t.getC()) / 2;
    double area = std::sqrt(static_cast<double>(s) * static_cast<double>(s - t.getA()) * static_cast<double>(s - t.getB()) * static_cast<double>(s - t.getC()));
    std::cout << "Triangle Area: " << area << std::endl;
}
void AreaVisitor::visit(CompoundShape& cs) {
    std::cout << "CompoundShape Area: (sum of contained shapes)" << std::endl;
}
} 