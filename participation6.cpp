#include <iostream>
#include <cmath>
#include <vector>
double function(double t) {
    return t*t;   //Function will be t^2
}
// integration function, Used GBT for integration function
double Integration(double (func)(double), double a, double b, int n) {
    double h = (b - a) / n; // step size
    double sum = 0.5 * (func(a) + func(b)); // iterating with the limits
    for (int i = 1; i < n; ++i) {
        sum += func(a + i * h);}
    return sum * h; // multiply by step size
}
// Recommending Gimbal, Strapdown 
void methods(double h) {
    if (h >= 0.1) {
        std::cout << "For step size " << h << ", Use Gimbal method.\n";}
    else {
        std::cout << "For step size " << h << ", Use strapdown method.\n";}
}
int main() {
    std::vector<double> stepSizes = {0.2, 0.1, 0.025, 0.0125}; // Required dt values
    double a = 0.0; 
    double b = 1; // Setting my limits
    for (double h : stepSizes) {
        int n = static_cast<int>((b - a) / h); // number of intervals
        double result = Integration(function, a, b, n);
        std::cout << "With step size " << h << ": " << result << std::endl;
        methods(h);}
    return 0;
}