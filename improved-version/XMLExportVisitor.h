#pragma once
#include "ShapeVisitor.h"

namespace visitor_sample {
class XMLExportVisitor : public ShapeVisitor {
    int indentLevel = 0;
    void printIndent() const;
public:
    void visit(Circle& c) override;
    void visit(Rectangle& r) override;
    void visit(Triangle& t) override;
    void visit(CompoundShape& cs) override;
};
} 