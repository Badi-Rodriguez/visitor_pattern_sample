#include "XMLExportVisitor.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "CompoundShape.h"
#include <iostream>

namespace visitor_sample {
void XMLExportVisitor::printIndent() const {
    for (int i = 0; i < indentLevel; ++i) std::cout << "  ";
}
void XMLExportVisitor::visit(Circle& c) {
    printIndent(); std::cout << "<Circle>" << std::endl;
    ++indentLevel;
    printIndent(); std::cout << "<Radius>" << c.getRadius() << "</Radius>" << std::endl;
    --indentLevel;
    printIndent(); std::cout << "</Circle>" << std::endl;
}
void XMLExportVisitor::visit(Rectangle& r) {
    printIndent(); std::cout << "<Rectangle>" << std::endl;
    ++indentLevel;
    printIndent(); std::cout << "<Width>" << r.getWidth() << "</Width>" << std::endl;
    printIndent(); std::cout << "<Height>" << r.getHeight() << "</Height>" << std::endl;
    --indentLevel;
    printIndent(); std::cout << "</Rectangle>" << std::endl;
}
void XMLExportVisitor::visit(Triangle& t) {
    printIndent(); std::cout << "<Triangle>" << std::endl;
    ++indentLevel;
    printIndent(); std::cout << "<SideA>" << t.getA() << "</SideA>" << std::endl;
    printIndent(); std::cout << "<SideB>" << t.getB() << "</SideB>" << std::endl;
    printIndent(); std::cout << "<SideC>" << t.getC() << "</SideC>" << std::endl;
    --indentLevel;
    printIndent(); std::cout << "</Triangle>" << std::endl;
}
void XMLExportVisitor::visit(CompoundShape& cs) {
    printIndent(); std::cout << "<CompoundShape>" << std::endl;
    ++indentLevel;
    const auto& shapes = cs.getShapes();
    for (const auto& shape : shapes) {
        shape->accept(*this);
    }
    --indentLevel;
    printIndent(); std::cout << "</CompoundShape>" << std::endl;
}
} 