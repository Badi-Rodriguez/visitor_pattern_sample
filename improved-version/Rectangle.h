#pragma once
#include "BaseShape.h"

namespace visitor_sample {
class Rectangle : public BaseShape {
private:
    double width, height;
public:
    Rectangle(double w, double h);
    double getWidth() const;
    double getHeight() const;
    void accept(ShapeVisitor& visitor) override;
};
} 