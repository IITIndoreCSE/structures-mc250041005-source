#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>  // For controlling output precision

using namespace std;

// Define Point struct
struct Point { 
    double x;
    double y;
};

// Function to print the point before and after rotation
void print_point_rotation(double x_before, double y_before,
                          double theta, double x_after, double y_after) {
    // Set precision to 4 decimal places for consistency with the example output
    cout << fixed << setprecision(4);
    
    // Print the original point and rotated point
    cout << "Before rotation: (x=" << x_before << ", y=" << y_before << ")\n";
    cout << "After rotation (θ=" << theta << " rad): "
         << "(x=" << x_after << ", y=" << y_after << ")\n";
}

// Function to perform rotation around a pivot point (px, py) by angle θ
void rotate_point(double x, double y, double px, double py, double theta, double &x_rot, double &y_rot) {
    // Apply the rotation formula
    x_rot = px + (x - px) * cos(theta) - (y - py) * sin(theta);
    y_rot = py + (x - px) * sin(theta) + (y - py) * cos(theta);
}

int main(int argc, char* argv[]) {
    // Check if the correct number of arguments is passed (program name + input file)
    if (argc != 2) {
        cerr << "Usage: " << argv[0] << " <input_file>" << endl;
        return 1; // Return error code 1 if no valid input file is provided
    }

    // Open the input file
    ifstream input(argv[1]);
    if (!input) {
        cerr << "Error opening " << argv[1] << endl;
        return 1; // Return error code 1 if file cannot be opened
    }

    // Read the input values: x, y, theta (angle in radians), and the pivot point (px, py)
    double x, y, theta, px, py;
    input >> x >> y >> theta >> px >> py;

    // If there is an error in reading the data
    if (input.fail()) {
        cerr << "Error reading input data from file." << endl;
        return 1; // Return error code 1 if there is an issue with the input data
    }

    // Variables to store the rotated coordinates
    double x_rot, y_rot;

    // Perform the rotation
    rotate_point(x, y, px, py, theta, x_rot, y_rot);

    // Print the results to standard output
    print_point_rotation(x, y, theta, x_rot, y_rot);

    // Return 0 to indicate successful execution
    return 0;
}
