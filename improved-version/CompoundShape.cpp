#include "CompoundShape.h"
#include "ShapeVisitor.h"

namespace visitor_sample {
void CompoundShape::addShape(std::unique_ptr<BaseShape> shape) {
    shapeList.push_back(std::move(shape));
}
const std::vector<std::unique_ptr<BaseShape>>& CompoundShape::getShapes() const {
    return shapeList;
}
void CompoundShape::accept(ShapeVisitor& visitor) {
    visitor.visit(*this);
    for (const auto& shape : shapeList) {
        shape->accept(visitor);
    }
}
} 