#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

// Define the Point struct with x and y coordinates
struct Point {
    double x, y;
};

// Function to print the point before and after rotation
void print_point_rotation(double x_before, double y_before,
                          double theta, double x_after, double y_after) {
    cout << "Before rotation: (x=" << x_before << ", y=" << y_before << ")\n";
    cout << "After rotation (θ=" << theta << " rad): "
         << "(x=" << x_after << ", y=" << y_after << ")\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1;
    }

    ifstream input(argv[1]);
    if (!input) {
        cerr << "Error opening " << argv[1] << endl;
        return 1;
    }

    // Declare point, pivot, and angle variables
    Point p, pivot;

    double theta;

    // Read input from file: x, y, theta, px, py
    input >> p.x >> p.y;    // Point to be rotated
    input >> theta;          // Rotation angle in radians
    input >> pivot.x >> pivot.y;  // Pivot point

    // Compute rotated coordinates around pivot using the rotation formula
    double x_after = pivot.x + (p.x - pivot.x) * cos(theta) - (p.y - pivot.y) * sin(theta);
    double y_after = pivot.y + (p.x - pivot.x) * sin(theta) + (p.y - pivot.y) * cos(theta);

    // Print the point before and after rotation
    print_point_rotation(p.x, p.y, theta, x_after, y_after);

    return 0;
}
