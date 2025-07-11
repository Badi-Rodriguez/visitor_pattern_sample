#include <iostream>
#include <memory>

std::string WORKING_DIRECTORY = "improved-version";

#include "improved-version/Circle.h"
#include "improved-version/Rectangle.h"
#include "improved-version/Triangle.h"
#include "improved-version/CompoundShape.h"
#include "improved-version/AreaVisitor.h"
#include "improved-version/XMLExportVisitor.h"
#include "improved-version/FileOutputVisitor.h"

using namespace visitor_sample;

int main() {
    try {
        // Create shapes with dynamic values
        auto circle = std::make_unique<Circle>(5.0);
        auto rectangle = std::make_unique<Rectangle>(4.0, 6.0);
        auto triangle = std::make_unique<Triangle>(3.0, 4.0, 5.0);  // Valid triangle

        // Create compound shape
        auto compound = std::make_unique<CompoundShape>();
        compound->addShape(std::make_unique<Circle>(5.0)); // make_unique is akin to signaling ownership by a unique pointer.
        compound->addShape(std::make_unique<Rectangle>(4.0, 6.0)); // so making multiple instances causes no harm
        compound->addShape(std::make_unique<Triangle>(3.0, 4.0, 5.0)); // you can call instances for a unique pointer and avoid memory leaks

        // Area calculation visitor
        AreaVisitor areaVisitor;
        std::cout << "Calculating areas..." << std::endl;
        circle->accept(areaVisitor); // Call the accept method of each figure instance
        rectangle->accept(areaVisitor); // Using it in the instance of the areaVisitor will cause a reading.
        triangle->accept(areaVisitor);
        compound->accept(areaVisitor);

        // XML export visitor
        XMLExportVisitor xmlVisitor;
        std::cout << "\nExporting shapes to XML..." << std::endl;
        circle->accept(xmlVisitor);
        rectangle->accept(xmlVisitor);
        triangle->accept(xmlVisitor);
        compound->accept(xmlVisitor);

        // File output visitor - creates a .txt file with all output
        std::cout << "\nCreating output file..." << std::endl;
        FileOutputVisitor fileVisitor("shape_output");
        circle->accept(fileVisitor);
        rectangle->accept(fileVisitor);
        triangle->accept(fileVisitor);
        compound->accept(fileVisitor);
        fileVisitor.writeToFile();

    } catch (const std::invalid_argument& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
