#pragma once
#include <memory>

namespace visitor_sample {
class ShapeVisitor;
class BaseShape {
public:
    virtual void accept(ShapeVisitor& visitor) = 0;
    virtual ~BaseShape() = default;
};
} 