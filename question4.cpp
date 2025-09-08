#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

// Define the TaylorTerm struct with order, coeff, and value
struct TaylorTerm {
    int order;    // The order of the term (2n+1)
    double coeff; // The coefficient of the term (-1)^n / (2n+1)!
    double value; // The value of the term (-1)^n * x^(2n+1) / (2n+1)!
};

// Function to print individual Taylor terms
void print_taylor_term(int index, int order, double coeff, double value) {
    cout << "Term[" << index << "]: "
         << "order=" << order << ", "
         << "coeff=" << coeff << ", "
         << "value=" << value << "\n";
}

// Function to print the final Taylor series result
void print_taylor_result(const char* function_name, double x,
                         int terms, double approximation) {
    cout << "Approximation of " << function_name
         << "(x) at x=" << x
         << " with " << terms << " terms: "
         << approximation << "\n";
}

// Function to compute factorial
double factorial(int n) {
    double result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
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

    double x;
    int terms;
    input >> x >> terms;

    // Create an array of TaylorTerm to store the terms
    TaylorTerm series[terms];

    double approximation = 0.0;

    // Compute each Taylor term and store it in the array
    for (int n = 0; n < terms; n++) {
        int order = 2 * n + 1;  // Order of the term (2n+1)
        double coeff = pow(-1, n) / factorial(order);  // Coefficient (-1)^n / (2n+1)!
        double value = coeff * pow(x, order);  // Term value (-1)^n * x^(2n+1) / (2n+1)!

        // Store in the series array
        series[n] = {order, coeff, value};

        // Add the value of the term to the approximation
        approximation += value;

        // Print the current term
        print_taylor_term(n, series[n].order, series[n].coeff, series[n].value);
    }

    // Print the final approximation
    print_taylor_result("sin", x, terms, approximation);

    return 0;
}
