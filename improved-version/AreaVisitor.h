#pragma once
#include "ShapeVisitor.h"

namespace visitor_sample {
class AreaVisitor : public ShapeVisitor {
public:
    static constexpr double pi = 3.14159265358979323846;
    void visit(Circle& c) override;
    void visit(Rectangle& r) override;
    void visit(Triangle& t) override;
    void visit(CompoundShape& cs) override;
};
} 