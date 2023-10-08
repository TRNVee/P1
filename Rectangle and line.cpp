#include <iostream>
#include <fstream>
#include <string>
#include <vector>

class SVGObject {
public:
    // Define properties and methods for your SVG objects
    virtual void draw(std::ostream& out) const = 0;
    virtual ~SVGObject() {} // Add a virtual destructor for polymorphism
};

class Circle : public SVGObject {
public:
    double cx, cy, r;
    Circle(double x, double y, double radius) : cx(x), cy(y), r(radius) {}

    void draw(std::ostream& out) const override {
        out << "<circle cx=\"" << cx << "\" cy=\"" << cy << "\" r=\"" << r << "\" />\n";
    }
};

class Rectangle : public SVGObject {
public:
    double x, y, width, height;
    Rectangle(double _x, double _y, double _width, double _height)
        : x(_x), y(_y), width(_width), height(_height) {}

    void draw(std::ostream& out) const override {
        out << "<rect x=\"" << x << "\" y=\"" << y << "\" width=\"" << width << "\" height=\"" << height << "\" />\n";
    }
};

class Line : public SVGObject {
public:
    double x1, y1, x2, y2;
    Line(double _x1, double _y1, double _x2, double _y2) : x1(_x1), y1(_y1), x2(_x2), y2(_y2) {}

    void draw(std::ostream& out) const override {
        out << "<line x1=\"" << x1 << "\" y1=\"" << y1 << "\" x2=\"" << x2 << "\" y2=\"" << y2 << "\" />\n";
    }
};

int main() {
    std::ifstream inputFile("input1.txt");
    if (inputFile.is_open()) {
        std::string line;
        std::vector<SVGObject*> objects; // Store SVG objects

        while (std::getline(inputFile, line)) {
            // Parse and create SVG objects from the lines in the file
            double x, y, radius, width, height, x1, y1, x2, y2;
            if (sscanf(line.c_str(), "circle %lf %lf %lf", &x, &y, &radius) == 3) {
                objects.push_back(new Circle(x, y, radius));
            } else if (sscanf(line.c_str(), "rect %lf %lf %lf %lf", &x, &y, &width, &height) == 4) {
                objects.push_back(new Rectangle(x, y, width, height));
            } else if (sscanf(line.c_str(), "line %lf %lf %lf %lf", &x1, &y1, &x2, &y2) == 4) {
                objects.push_back(new Line(x1, y1, x2, y2));
            }
        }

        inputFile.close();

        // HTML Generation
        std::ofstream outputFile("output.html");
        if (outputFile.is_open()) {
            outputFile << "<html><body>\n";
            // Write HTML and SVG code for each SVG object
            for (const SVGObject* obj : objects) {
                obj->draw(outputFile);
            }
            outputFile << "</body></html>\n";
            outputFile.close();
        } else {
            std::cerr << "Unable to create output HTML file." << std::endl;
            return 1;
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
