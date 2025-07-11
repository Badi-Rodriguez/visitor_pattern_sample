#pragma once
#include "BaseShape.h"
#include <vector>
#include <memory>

namespace visitor_sample {
class CompoundShape : public BaseShape {
private:
    std::vector<std::unique_ptr<BaseShape>> shapeList;
public:
    void addShape(std::unique_ptr<BaseShape> shape);
    const std::vector<std::unique_ptr<BaseShape>>& getShapes() const;
    void accept(ShapeVisitor& visitor) override;
};
} 