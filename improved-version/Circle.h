#pragma once
#include "BaseShape.h"

namespace visitor_sample {
class Circle : public BaseShape {
private:
    double radius;
public:
    Circle(double r);
    double getRadius() const;
    void accept(ShapeVisitor& visitor) override;
};
} 