#include <iostream>
#include <cmath>
#include <fstream>
#include <iomanip>

using namespace std;

// Define TaylorTerm struct
struct TaylorTerm {
    int order;
    double coeff;
    double value;
};

// Function to print the terms in the series
void print_taylor_term(int index, int order, double coeff, double value) {
    cout << "Term[" << index << "]: "
         << "order=" << order << ", "
         << "coeff=" << coeff << ", "
         << "value=" << value << "\n";
}

// Function to print the final approximation
void print_taylor_result(const char* function_name, double x,
                         int terms, double approximation) {
    cout << "Approximation of " << function_name
         << "(x) at x=" << x
         << " with " << terms << " terms: "
         << approximation << "\n";
}

// Function to calculate the factorial
double factorial(int n) {
    double result = 1.0;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Function to compute the Taylor series for cosine
double compute_cosine_taylor(double x, int terms) {
    double approximation = 0.0;
    TaylorTerm series[terms];

    for (int n = 0; n < terms; n++) {
        int order = 2 * n;  // Even powers for cosine
        double coeff = pow(-1, n) / factorial(order);  // Coefficients for cosine
        double value = coeff * pow(x, order);  // The term value

        // Store the term
        series[n] = {order, coeff, value};

        // Add to the approximation
        approximation += value;

        // Print each term
        print_taylor_term(n, order, coeff, value);
    }

    return approximation;
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

    // Compute the Taylor series for cosine
    double approximation = compute_cosine_taylor(x, terms);

    // Print the final result
    print_taylor_result("cos", x, terms, approximation);

    return 0;
}
