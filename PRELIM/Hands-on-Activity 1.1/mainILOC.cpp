#include <iostream>
#include <cmath>
#include <iomanip>
float toFahrenheit(float kelvin);
float distance(float x1, float x2, float y1, float y2);

int main() {
    int a, b;
    std::cout<< "SWAPPING TWO NUMBERS\n";
    std::cout <<"Enter first number(a): ";
    std::cin >> a;
    std::cout << "Enter second number(b): ";
    std::cin >> b;

    int c = a;
    a = b;
    b = c;
    
    std::cout << "Swapped:\n" << "a = "<< a <<std::endl;
    std::cout << "b = "<< b;
    std::cout << "\n------------------\n";
    // This code swaps two values from two different variables by using a third variable
    // to store the first variable. 

    std::cout <<"KELVIN TO FAHRENHEIT CONVERTER\n";
    float kelvin;
    std::cout << "Enter a Kelvin value: ";
    std::cin >> kelvin;

    std::cout<< kelvin << " Kelvin is equivalent to "<< toFahrenheit(kelvin) << " Fahrenheit";
    std::cout << "\n------------------\n";

    float x1, x2, y1, y2;
    std::cout <<"DISTANCE BETWEEN TWO POINTS\n";
    std::cout<< "Enter x1: ";
    std::cin >> x1;
    std::cout<< "Enter y1: ";
    std::cin >> y1;
    std::cout << "Enter x2: ";
    std::cin >> x2;
    std::cout <<"Enter y2: ";
    std::cin >> y2;

    std::cout << "The distance between (" << x1 << ", "<< y1<< ") and ("<< x2 <<", "<< y2<< ") is ";
    std::cout << std::setprecision(3) << distance(x1,x2,y1,y2);
    return 0;
}
float toFahrenheit(float kelvin){
    float fahrenheit = (kelvin - 273.15) *(1.8)+ 32;
  return fahrenheit;
} // This converts a kelvin value to fahrenheit using the formula above.  
float distance(float x1, float x2, float y1, float y2){
    float dx = x2 - x1;
    float dy = y2 - y1;
    return sqrt((dx * dx) + (dy * dy));
} // Using the distance formula I were able to get the distance between two points. 