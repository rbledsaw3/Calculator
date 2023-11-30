#include <iostream>
#include <limits>

class Calculator {
  public:
    static int add(int aNum, int bNum) {
      return aNum + bNum;
    }

    static float add(float aNum, float bNum) {
      return aNum + bNum;
    }  // overload to produce float results

    static int subtract(int aNum, int bNum) {
      return aNum - bNum;
    }

    static float subtract(float aNum, float bNum) {
      return aNum - bNum;
    }

    static int multiply(int aNum, int bNum) {
      return aNum * bNum;
    }

    static float multiply(float aNum, float bNum) {
      return aNum * bNum;
    }

    static float divide(float aNum, float bNum) {
      float result {};
      try {
        result = aNum / bNum;
      } catch (const char* msg) {
        std::cerr << msg << std::endl;
        return 0;
      }
      return result;
    }

    static int abs(int aNum) {
      return aNum < 0 ? -aNum : aNum;
    }

    static float abs(float aNum) {
      return aNum < 0 ? -aNum : aNum;
    }

    static double abs(double aNum) {
      return aNum < 0 ? -aNum : aNum;
    }

    static double power(double aNum, int bNum) {
      if (bNum == 1) {
        return aNum;
      }
      if (bNum == 0) {
        return 1;
      }

      if (bNum < 0) {
        aNum = 1 / aNum;
        bNum = -bNum;
      }
      double result = 1.0;
      auto bNumUnsigned = static_cast<unsigned int>(bNum);

      while (static_cast<bool>(bNumUnsigned)) {
        if (bNumUnsigned & 0b1) {
          result *= aNum;
        }
        bNumUnsigned >>= 0b1;
        aNum *= aNum;
      }

      return result;
    }
};

int main() {
  int aNum = 5;
  int bNum = 2;
  int cNum = 4;
  float dNum = 2.54;
  float eNum = 42.069;
  float fNum = 31.419;
  int gNum = bNum;
  double hNum = 5.5;
  int iNum = -aNum;
  float jNum = -dNum;
  double kNum = -hNum;

  int sum = Calculator::add(aNum, bNum);
  float sumf = Calculator::add(dNum, eNum);
  int product = Calculator::multiply(cNum, bNum);
  float productf = Calculator::multiply(dNum, fNum);
  int difference = Calculator::subtract(aNum, bNum);
  float differencef = Calculator::subtract(eNum, fNum);
  float quotient = Calculator::divide(static_cast<float>(cNum), dNum);
  double power = Calculator::power(hNum, gNum);
  int absi = Calculator::abs(iNum);
  float absf = Calculator::abs(jNum);
  double absd = Calculator::abs(kNum);
  double power2 = Calculator::power(hNum, iNum);

  std::cout << "Sum of " << aNum << " and " << bNum << ": " << sum << "\n";
  std::cout << "Sum of " << dNum << " and " << eNum << ": " << sumf << "\n";
  std::cout << "Product of " << cNum << " and " << bNum << ": " << product << "\n";
  std::cout << "Product of " << dNum << " and " << fNum << ": " << productf << "\n";
  std::cout << "Difference of " << aNum << " and " << bNum << ": " << difference << "\n";
  std::cout << "Difference of " << eNum << " and " << fNum << ": " << differencef << "\n";
  std::cout << "Quotient of " << cNum << " divided by " << dNum << ": " << quotient << "\n";
  std::cout << hNum << " to the power of " << gNum << " = " << power << "\n";
  std::cout << "Absolute value of " << iNum << ": " << absi << "\n";
  std::cout << "Absolute value of " << jNum << ": " << absf << "\n";
  std::cout << "Absolute value of " << kNum << ": " << absd << "\n";
  std::cout << hNum << " to the power of " << iNum << " = " << power2 << "\n";

  return 0;
}
