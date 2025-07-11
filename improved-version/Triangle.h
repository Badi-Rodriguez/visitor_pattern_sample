#pragma once
#include "BaseShape.h"
#include <stdexcept>

namespace visitor_sample {
class Triangle : public BaseShape {
private:
    double a, b, c;
public:
    Triangle(double sideA, double sideB, double sideC);
    double getA() const;
    double getB() const;
    double getC() const;
    void accept(ShapeVisitor& visitor) override;
};
} 