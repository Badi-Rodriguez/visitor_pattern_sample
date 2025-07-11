#include "Circle.h"
#include "ShapeVisitor.h"

namespace visitor_sample {
Circle::Circle(double r) : radius(r) {}
double Circle::getRadius() const { return radius; }
void Circle::accept(ShapeVisitor& visitor) { visitor.visit(*this); }
} 