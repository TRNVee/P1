#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class SVGObject {
public:
    // Define properties and methods for your SVG objects
    SVGObject() {}
};

class Circle : public SVGObject {
public:
    double cx, cy, r;
    Circle(double x, double y, double radius) : cx(x), cy(y), r(radius) {}
};

int main() {
    std::ifstream inputFile("input1.txt");
    if (inputFile.is_open()) {
        std::string line;
        std::vector<SVGObject*> objects; // Store SVG objects

        while (std::getline(inputFile, line)) {
            // Parse and create SVG objects from the lines in the file
            double x, y, radius;
            if (sscanf(line.c_str(), "circle %lf %lf %lf", &x, &y, &radius) == 3) {
                objects.push_back(new Circle(x, y, radius));
            }
        }

        inputFile.close();

        // Process the SVG objects (for example, print their properties)
        for (const SVGObject* obj : objects) {
            if (const Circle* circle = dynamic_cast<const Circle*>(obj)) {
                std::cout << "Circle: cx=" << circle->cx << " cy=" << circle->cy << " r=" << circle->r << std::endl;
            }
        }

        // Clean up allocated memory
        for (SVGObject* obj : objects) {
            delete obj;
        }
    } else {
        std::cerr << "Unable to open input file." << std::endl;
        return 1;
    }

    return 0;
}
