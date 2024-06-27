#include <iostream>
#include <cmath>
#include <vector>
#include <sstream>
using namespace std;

struct Calculation {
    string operation;
    double result;
};

vector<Calculation> history; 

void displayMenu() {
    cout << "===========================" << endl;
    cout << "  Scientific Calculator" << endl;
    cout << "===========================" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Sine" << endl;
    cout << "6. Cosine" << endl;
    cout << "7. Tangent" << endl;
    cout << "8. Logarithm" << endl;
    cout << "9. Square Root" << endl; 
    cout << "10. Power" << endl;
    cout << "11. Exponential" << endl;
    cout << "12. Factorial" << endl;
    cout << "13. Hyperbolic Sine" << endl;
    cout << "14. Hyperbolic Cosine" << endl;
    cout << "15. Hyperbolic Tangent" << endl;
    cout << "16. Differentiation" << endl;
    cout << "17. Integration" << endl;
    cout << "18. Calculate Roots" << endl;
    cout << "19. History" << endl;
    cout << "20. Exit" << endl;
    cout << "===========================" << endl;
}

void addToHistory(string operation, double result) {
    Calculation calc;
    calc.operation = operation;
    calc.result = result;
    history.push_back(calc);
}

void displayHistory() {
    if (history.empty()) {
        cout << "History is empty." << endl;
    } else {
        cout << "Calculation History:" << endl;
        for (unsigned int i = 0; i < history.size(); ++i) {
            cout << "[" << i + 1 << "] " << history[i].operation << " = " << history[i].result << endl;
        }
    }
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        cout << "Error: Division by zero" << endl;
        return 0;
    }
}

double sine(double a) {
    return sin(a);
}

double cosine(double a) {
    return cos(a);
}

double tangent(double a) {
    return tan(a);
}

double logarithm(double a) {
    if (a > 0) {
        return log(a);
    } else {
        cout << "Error: Logarithm of non-positive number" << endl;
        return 0;
    }
}

double squareRoot(double a) {
    if (a >= 0) {
        return sqrt(a);
    } else {
        cout << "Error: Square root of negative number" << endl;
        return 0;
    }
}

double power(double base, double exponent) {
    return pow(base, exponent);
}

double exponential(double a) {
    return exp(a);
}

unsigned long long factorial(int n) {
    if (n < 0) {
        cout << "Error: Factorial of a negative number is not defined" << endl;
        return 0;
    }
    unsigned long long fact = 1;
    for (int i = 1; i <= n; ++i) {
        fact *= i;
    }
    return fact;
}

double hyperbolicSine(double a) {
    return sinh(a);
}

double hyperbolicCosine(double a) {
    return cosh(a);
}

double hyperbolicTangent(double a) {
    return tanh(a);
}

double differentiate(double (*func)(double), double x) {  //forward difference rule 
    double h = 0.001;
    return (func(x + h) - func(x)) / h;
}

double integrate(double (*func)(double), double a, double b, int n) {  //Trapezoidal rule
    double h = (b - a) / n;
    double sum = 0.5 * (func(a) + func(b));
    for (int i = 1; i < n; ++i) {
        sum += func(a + i * h);
    }
    return sum * h;
}

double sampleFunction(double x) {
    return x * x - 3; //f(x) = x^2 - 3
}

void calculateRoots(double a, double b, double c) {     //Quadratic Formula. 
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        double root1 = (-b + sqrt(discriminant)) / (2 * a);
        double root2 = (-b - sqrt(discriminant)) / (2 * a);
        cout << "Roots are real and different." << endl;
        cout << "Root 1 = " << root1 << endl;
        cout << "Root 2 = " << root2 << endl;
        addToHistory("roots(" + to_string(a) + "x^2 + " + to_string(b) + "x + " + to_string(c) + ")", root1);
        addToHistory("roots(" + to_string(a) + "x^2 + " + to_string(b) + "x + " + to_string(c) + ")", root2);
    } else if (discriminant == 0) {
        double root = -b / (2 * a);
        cout << "Roots are real and same." << endl;
        cout << "Root = " << root << endl;
        addToHistory("roots(" + to_string(a) + "x^2 + " + to_string(b) + "x + " + to_string(c) + ")", root);
    } else {
        cout << "Roots are complex and different." << endl;
        double realPart = -b / (2 * a);
        double imaginaryPart = sqrt(-discriminant) / (2 * a);
        cout << "Root 1 = " << realPart << " + " << imaginaryPart << "i" << endl;
        cout << "Root 2 = " << realPart << " - " << imaginaryPart << "i" << endl;
        addToHistory("roots(" + to_string(a) + "x^2 + " + to_string(b) + "x + " + to_string(c) + ")", realPart);
    }
}

int main() {
    int choice;
    double num1, num2, num3;
    int intNum;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 20) {
            break;
        }

        switch (choice) {
            case 1:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << add(num1, num2) << endl;
                addToHistory(to_string(num1) + " + " + to_string(num2), add(num1, num2));
                break;
            case 2:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << subtract(num1, num2) << endl;
                addToHistory(to_string(num1) + " - " + to_string(num2), subtract(num1, num2));
                break;
            case 3:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << multiply(num1, num2) << endl;
                addToHistory(to_string(num1) + " * " + to_string(num2), multiply(num1, num2));
                break;
            case 4:
                cout << "Enter two numbers: ";
                cin >> num1 >> num2;
                cout << "Result: " << divide(num1, num2) << endl;
                addToHistory(to_string(num1) + " / " + to_string(num2), divide(num1, num2));
                break;
            case 5:
                cout << "Enter an angle in radians: ";
                cin >> num1;
                cout << "Result: " << sine(num1) << endl;
                addToHistory("sin(" + to_string(num1) + ")", sine(num1));
                break;
            case 6:
                cout << "Enter an angle in radians: ";
                cin >> num1;
                cout << "Result: " << cosine(num1) << endl;
                addToHistory("cos(" + to_string(num1) + ")", cosine(num1));
                break;
            case 7:
                cout << "Enter an angle in radians: ";
                cin >> num1;
                cout << "Result: " << tangent(num1) << endl;
                addToHistory("tan(" + to_string(num1) + ")", tangent(num1));
                break;
            case 8:
                cout << "Enter a number: ";
                cin >> num1;
                cout << "Result: " << logarithm(num1) << endl;
                addToHistory("log(" + to_string(num1) + ")", logarithm(num1));
                break;
            case 9:
                cout << "Enter a number: ";
                cin >> num1;
                cout << "Result: " << squareRoot(num1) << endl;
                addToHistory("sqrt(" + to_string(num1) + ")", squareRoot(num1));
                break;
            case 10:
                cout << "Enter base and exponent: ";
                cin >> num1 >> num2;
                cout << "Result: " << power(num1, num2) << endl;
                addToHistory(to_string(num1) + "^" + to_string(num2), power(num1, num2));
                break;
            case 11:
                cout << "Enter a number: ";
                cin >> num1;
                cout << "Result: " << exponential(num1) << endl;
                addToHistory("exp(" + to_string(num1) + ")", exponential(num1));
                break;
            case 12:
                cout << "Enter a number: ";
                cin >> intNum;
                cout << "Result: " << factorial(intNum) << endl;
                addToHistory(to_string(intNum) + "!", factorial(intNum));
                break;
            case 13:
                cout << "Enter a number: ";
                cin >> num1;
                cout << "Result: " << hyperbolicSine(num1) << endl;
                addToHistory("sinh(" + to_string(num1) + ")", hyperbolicSine(num1));
                break;
            case 14:
                cout << "Enter a number: ";
                cin >> num1;
                cout << "Result: " << hyperbolicCosine(num1) << endl;
                addToHistory("cosh(" + to_string(num1) + ")", hyperbolicCosine(num1));
                break;
            case 15:
                cout << "Enter a number: ";
                cin >> num1;
                cout << "Result: " << hyperbolicTangent(num1) << endl;
                addToHistory("tanh(" + to_string(num1) + ")", hyperbolicTangent(num1));
                break;
            case 16:
                cout << "Enter a value of x to differentiate at: ";
                cin >> num1;
                cout << "Result: " << differentiate(sampleFunction, num1) << endl;
                addToHistory("differentiate(f(x)) at x=" + to_string(num1), differentiate(sampleFunction, num1));
                break;
            case 17:
                double a, b;
                int n;
                cout << "Enter lower limit, upper limit, and number of intervals: ";
                cin >> a >> b >> n;
                cout << "Result: " << integrate(sampleFunction, a, b, n) << endl;
                addToHistory("integrate(f(x)) from " + to_string(a) + " to " + to_string(b) + " with " + to_string(n) + " intervals", integrate(sampleFunction, a, b, n));
                break;
            case 18:
                cout << "Enter coefficients (a, b, c) of quadratic equation (ax^2 + bx + c = 0): ";
                cin >> num1 >> num2 >> num3;
                calculateRoots(num1, num2, num3);
                break;
            case 19:
                displayHistory();
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    cout << "Exiting the calculator. Thank you!" << endl;
    return 0;
}
