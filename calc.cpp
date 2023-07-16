#include <iostream>

class Calculator {
    public:
        int add(int a, int b) { return a + b; } 
        float add(float a, float b) { return a + b; } //overload to produce float results
        int subtract(int a, int b) { return a - b; }
        float subtract(float a, float b) { return a - b; }
        int multiply(int a, int b) { return a * b; }
        float multiply(float a, float b) { return a * b; }
        float divide(float a, float b) { 
            float result;
            try {
                result = a / b;
            } catch (const char* msg) {
                std::cerr << msg << std::endl;
                return 0;
            }
            return result;
        }
        double power(double a, int b) {
            double result = a;
            if ((int) b == 1) { return result; }
            for (int i=2; i <= (int) b; i++){
               result *= a;
            }
            return result;
        }
};

int main() {
    int a = 5;
    int b = 2;
    int c = 4;
    float d = 2.54;
    float e = 42.069;
    float f = 31.419;
    double g = 2;
    double h = 5.5;

    Calculator calc;

    int sum = calc.add(a, b);
    float sumf = calc.add(d, e);
    int product = calc.multiply(c, b);
    float productf = calc.multiply(d, f);
    int difference = calc.subtract(a, b);
    float differencef = calc.subtract(e, f);
    float quotient = calc.divide(c, d);
    double power = calc.power(h, g);

    std::cout << "Sum of ints: " << sum << "\n";
    std::cout << "Sum of floats: " << sumf << "\n";
    std::cout << "Product of ints: " << product << "\n";
    std::cout << "Product of floats: " << productf << "\n";
    std::cout << "Difference of ints: " << difference << "\n";
    std::cout << "Difference of floats: " << differencef << "\n";
    std::cout << "Quotient of " << c << " divided by " << d << ": " << quotient << "\n";
    std::cout << h << " to the power of " << g << " = " << power << "\n";

    return 0;

}
