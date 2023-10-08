#include <iostream>
#include <fstream>
#include "svgpp/svgpp.hpp"

int main() {
    // Create an SVG document
    svgpp::Document doc(200, 200);
    
    // Rectangle Block
    svgpp::Rect rect(10, 10, 180, 80);  // (x, y, width, height)
    rect.setFill(svgpp::Color(0, 0, 255));  // Blue fill color
    doc << rect;
    
    // Rectangle with Border
    svgpp::Rect rectWithBorder(10, 120, 180, 80);
    rectWithBorder.setFill(svgpp::Color(255, 255, 0));  // Yellow fill color
    rectWithBorder.setStroke(svgpp::Color(255, 0, 0));  // Red border color
    rectWithBorder.setStrokeWidth(5);  // Border width
    doc << rectWithBorder;
    
    // Triangle
    svgpp::Polygon triangle;
    triangle.addPoint(100, 30);  // Vertex 1
    triangle.addPoint(40, 170);  // Vertex 2
    triangle.addPoint(160, 170); // Vertex 3
    triangle.setFill(svgpp::Color(0, 128, 0));  // Green fill color
    doc << triangle;

    // Save the SVG to a file
    std::ofstream svgFile("shapes.svg");
    svgFile << doc;

    std::cout << "SVG file 'shapes.svg' created!" << std::endl;

    return 0;
}
