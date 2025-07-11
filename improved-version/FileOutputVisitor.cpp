#include "FileOutputVisitor.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "CompoundShape.h"
#include "AreaVisitor.h"
#include "XMLExportVisitor.h"
#include <iostream>
#include <streambuf>

namespace visitor_sample {

FileOutputVisitor::FileOutputVisitor(const std::string& filename) : filename(filename) {
    // Add .txt extension if not present
    if (filename.find(".txt") == std::string::npos) {
        this->filename = filename + ".txt";
    }
}

void FileOutputVisitor::captureAreaOutput(BaseShape& shape) {
    // Redirect cout to capture area visitor output
    std::streambuf* coutBuffer = std::cout.rdbuf();
    std::ostringstream tempStream;
    std::cout.rdbuf(tempStream.rdbuf());
    
    // Call area visitor
    shape.accept(areaVisitor);
    
    // Restore cout and capture output
    std::cout.rdbuf(coutBuffer);
    areaOutput << tempStream.str();
}

void FileOutputVisitor::captureXMLOutput(BaseShape& shape) {
    // Redirect cout to capture XML visitor output
    std::streambuf* coutBuffer = std::cout.rdbuf();
    std::ostringstream tempStream;
    std::cout.rdbuf(tempStream.rdbuf());
    
    // Call XML visitor
    shape.accept(xmlVisitor);
    
    // Restore cout and capture output
    std::cout.rdbuf(coutBuffer);
    xmlOutput << tempStream.str();
}

void FileOutputVisitor::visit(Circle& c) {
    captureAreaOutput(c);
    captureXMLOutput(c);
}

void FileOutputVisitor::visit(Rectangle& r) {
    captureAreaOutput(r);
    captureXMLOutput(r);
}

void FileOutputVisitor::visit(Triangle& t) {
    captureAreaOutput(t);
    captureXMLOutput(t);
}

void FileOutputVisitor::visit(CompoundShape& cs) {
    captureAreaOutput(cs);
    captureXMLOutput(cs);
}

void FileOutputVisitor::writeToFile() {
    std::ofstream file(filename);
    if (file.is_open()) {
        file << "=== AREA CALCULATIONS ===" << std::endl;
        file << areaOutput.str();
        file << std::endl;
        file << "=== XML EXPORT ===" << std::endl;
        file << xmlOutput.str();
        file.close();
        std::cout << "Output written to file: " << filename << std::endl;
    } else {
        std::cerr << "Error: Could not open file " << filename << " for writing." << std::endl;
    }
}

} 