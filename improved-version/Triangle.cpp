#include "Triangle.h"
#include "ShapeVisitor.h"
#include <stdexcept>

namespace visitor_sample {
Triangle::Triangle(double sideA, double sideB, double sideC) : a(sideA), b(sideB), c(sideC) {
    if (a + b <= c || a + c <= b || b + c <= a) {
        throw std::invalid_argument("Invalid triangle sides: The sum of any two sides must be greater than the third side.");
    }
}
double Triangle::getA() const { return a; }
double Triangle::getB() const { return b; }
double Triangle::getC() const { return c; }
void Triangle::accept(ShapeVisitor& visitor) { visitor.visit(*this); }
} 