#pragma once
#include "ShapeVisitor.h"
#include "BaseShape.h"
#include "AreaVisitor.h"
#include "XMLExportVisitor.h"
#include <string>
#include <fstream>
#include <sstream>

namespace visitor_sample {
class FileOutputVisitor : public ShapeVisitor {
private:
    std::string filename;
    std::ostringstream areaOutput;
    std::ostringstream xmlOutput;
    AreaVisitor areaVisitor;
    XMLExportVisitor xmlVisitor;
    
    // Helper method to capture cout output
    void captureAreaOutput(BaseShape& shape);
    void captureXMLOutput(BaseShape& shape);
    
public:
    FileOutputVisitor(const std::string& filename);
    void visit(Circle& c) override;
    void visit(Rectangle& r) override;
    void visit(Triangle& t) override;
    void visit(CompoundShape& cs) override;
    
    // Method to write all captured output to file
    void writeToFile();
};
} 