#pragma once

namespace visitor_sample {
class Circle;
class Rectangle;
class Triangle;
class CompoundShape;

class ShapeVisitor {
public:
    virtual void visit(Circle& c) = 0;
    virtual void visit(Rectangle& r) = 0;
    virtual void visit(Triangle& t) = 0;
    virtual void visit(CompoundShape& cs) = 0;
    virtual ~ShapeVisitor() = default;
};
} 