#include "Rectangle.h"
#include "ShapeVisitor.h"

namespace visitor_sample {
Rectangle::Rectangle(double w, double h) : width(w), height(h) {}
double Rectangle::getWidth() const { return width; }
double Rectangle::getHeight() const { return height; }
void Rectangle::accept(ShapeVisitor& visitor) { visitor.visit(*this); }
} 