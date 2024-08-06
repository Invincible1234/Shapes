#include <iostream>
#include <fstream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

void calculateSquare(double side);
void calculateRectangle(double length, double width);
void calculateCircle(double radius);
void calculateTriangle(double side);
void calculateCube(double side);
void calculateBox(double length, double width, double height);
void calculateCylinder(double radius, double height);
void calculatePrism(double side, double height);

int main() {

    ifstream inputFile("Shapes.input.txt");
    ofstream outputFile("Shapes.output.txt");

    if (!inputFile.is_open()) {
        cout << "Error opening input file." << endl;
        return 1;
    }

    if (!outputFile.is_open()) {
        cout << "Error opening output file." << endl;
        return 1;
    }

    string shape;
    double dim1 = 0.0, dim2 = 0.0, dim3 = 0.0;

    while (inputFile >> shape) {
        if (shape == "EOF") {
            break;  
        }
        else if (shape == "SQUARE") {
            if (inputFile >> dim1) {
                calculateSquare(dim1);
                outputFile << "SQUARE side=" << dim1 << " area=0.00 perimeter=0.00" << endl;
            }
        }
        else if (shape == "RECTANGLE") {
            if (inputFile >> dim1 >> dim2) {
                calculateRectangle(dim1, dim2);
                outputFile << "RECTANGLE length=" << dim1 << " width=" << dim2 << " area=0.00 perimeter=0.00" << endl;
            }
        }
        else if (shape == "CIRCLE") {
            if (inputFile >> dim1) {
                calculateCircle(dim1);
                outputFile << "CIRCLE radius=" << dim1 << " area=0.00 perimeter=0.00" << endl;
            }
        }
        else if (shape == "TRIANGLE") {
            if (inputFile >> dim1) {
                calculateTriangle(dim1);
                outputFile << "TRIANGLE side=" << dim1 << " area=0.00 perimeter=0.00" << endl;
            }
        }
        else if (shape == "CUBE") {
            if (inputFile >> dim1) {
                calculateCube(dim1);
                outputFile << "CUBE side=" << dim1 << " surface area=0.00 volume=0.00" << endl;
            }
        }
        else if (shape == "BOX") {
            if (inputFile >> dim1 >> dim2 >> dim3) {
                calculateBox(dim1, dim2, dim3);
                outputFile << "BOX length=" << dim1 << " width=" << dim2 << " height=" << dim3 << " surface area=0.00 volume=0.00" << endl;
            }
        }
        else if (shape == "CYLINDER") {
            if (inputFile >> dim1 >> dim2) {
                calculateCylinder(dim1, dim2);
                outputFile << "CYLINDER radius=" << dim1 << " height=" << dim2 << " surface area=0.00 volume=0.00" << endl;
            }
        }
        else if (shape == "PRISM") {
            if (inputFile >> dim1 >> dim2) {
                calculatePrism(dim1, dim2);
                outputFile << "PRISM side=" << dim1 << " height=" << dim2 << " surface area=0.00 volume=0.00" << endl;
            }
        }
        else {
            cout << shape << " invalid object" << endl;
            outputFile << shape << " invalid object" << endl;
            // Consume the entire line for an invalid shape
            string invalidLine;
            getline(inputFile, invalidLine);
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}

void calculateSquare(double side) {
    double area = side * side;
    double perimeter = 4 * side;
    cout << "SQUARE side=" << side << " area=" << fixed << setprecision(2) << area << " perimeter=" << fixed << setprecision(2) << perimeter << endl;
}

void calculateRectangle(double length, double width) {
    double area = length * width;
    double perimeter = 2 * (length + width);
    cout << "RECTANGLE length=" << length << " width=" << width << " area=" << fixed << setprecision(2) << area << " perimeter=" << fixed << setprecision(2) << perimeter << endl;
}

void calculateCircle(double radius) {
    double area = 3.14159 * radius * radius;
    double perimeter = 2 * 3.14159 * radius;
    cout << "CIRCLE radius=" << radius << " area=" << fixed << setprecision(2) << area << " perimeter=" << fixed << setprecision(2) << perimeter << endl;
}

void calculateTriangle(double side) {
    double area = (sqrt(3) / 4) * side * side;
    double perimeter = 3 * side;
    cout << "TRIANGLE side=" << side << " area=" << fixed << setprecision(2) << area << " perimeter=" << fixed << setprecision(2) << perimeter << endl;
}

void calculateCube(double side) {
    double surfaceArea = 6 * side * side;
    double volume = side * side * side;
    cout << "CUBE side=" << side << " surface area=" << fixed << setprecision(2) << surfaceArea << " volume=" << fixed << setprecision(2) << volume << endl;
}

void calculateBox(double length, double width, double height) {
    double surfaceArea = 2 * (length * width + length * height + width * height);
    double volume = length * width * height;
    cout << "BOX length=" << length << " width=" << width << " height=" << height << " surface area=" << fixed << setprecision(2) << surfaceArea << " volume=" << fixed << setprecision(2) << volume << endl;
}

void calculateCylinder(double radius, double height) {
    double surfaceArea = 2 * 3.14159 * radius * (radius + height);
    double volume = 3.14159 * radius * radius * height;
    cout << "CYLINDER radius=" << radius << " height=" << height << " surface area=" << fixed << setprecision(2) << surfaceArea << " volume=" << fixed << setprecision(2) << volume << endl;
}

void calculatePrism(double side, double height) {
    double surfaceArea = 2 * side * (side + sqrt(3) * height);
    double volume = 0.5 * side * side * height;
    cout << "PRISM side=" << side << " height=" << height << " surface area=" << fixed << setprecision(2) << surfaceArea << " volume=" << fixed << setprecision(2) << volume << endl;
}
