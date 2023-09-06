#include <iostream>
#include <limits>


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
        int abs(int a) { return a < 0 ? -a : a; }
        float abs(float a) { return a < 0 ? -a : a; }
        double abs(double a) { return a < 0 ? -a : a; }
        double power(double a, int b) {
            if (b == 1) { return a; }
            if (b == 0) { return 1; }
            if (b < 0) {
                a = 1 / a;
                b = -b;
            }
            double result = 1.0;

            while (b) {
                if (b & 1) {
                    result *= a;
                }
                b >>= 1;
                a *= a;
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
    int i = -5;
    float j = -2.54;
    double k = -5.5;

    Calculator calc;

    int sum = calc.add(a, b);
    float sumf = calc.add(d, e);
    int product = calc.multiply(c, b);
    float productf = calc.multiply(d, f);
    int difference = calc.subtract(a, b);
    float differencef = calc.subtract(e, f);
    float quotient = calc.divide(c, d);
    double power = calc.power(h, g);
    int absi = calc.abs(i);
    float absf = calc.abs(j);
    double absd = calc.abs(k);
    double power2 = calc.power(h, i);

    std::cout << "Sum of " << a << " and " << b << ": " << sum << "\n";
    std::cout << "Sum of " << d << " and " << e << ": " << sumf << "\n";
    std::cout << "Product of " << c << " and " << b << ": " << product << "\n";
    std::cout << "Product of " << d << " and " << f << ": " << productf << "\n";
    std::cout << "Difference of " << a << " and " << b << ": " << difference << "\n";
    std::cout << "Difference of " << e << " and " << f << ": " << differencef << "\n";
    std::cout << "Quotient of " << c << " divided by " << d << ": " << quotient << "\n";
    std::cout << h << " to the power of " << g << " = " << power << "\n";
    std::cout << "Absolute value of " << i << ": " << absi << "\n";
    std::cout << "Absolute value of " << j << ": " << absf << "\n";
    std::cout << "Absolute value of " << k << ": " << absd << "\n";
    std::cout << h << " to the power of " << i << " = " << power2 << "\n";


    return 0;

}
