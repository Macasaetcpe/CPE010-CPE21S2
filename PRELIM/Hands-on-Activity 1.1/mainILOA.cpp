#include <iostream>

int sumOfTwoNum(int fNum, int sNum);
bool greaterThan(int varA, int varB);
bool logicalOperators(bool a, bool b);

//ILO A
int main(){
    std::cout << "SUM OF TWO NUMBERS\n";
    std::cout<< "The sum of 10 and 5 is "<< sumOfTwoNum(10,5);
    std::cout << "\n------------------------\n";
    
    int varA, varB;
    std::cout<< "DETERMING WHICH AMONG TWO NUMBERS IS GREATER THAN THE OTHER\n";
    std::cout<< "Enter first number: ";
    std::cin >> varA;

    std::cout<< "Enter second number: ";
    std::cin >> varB;

    if (greaterThan(varA,varB)){
        std::cout << varA << " is greater than " << varB;
    }else{
        std::cout << varA << " is NOT greater than " << varB;
    }

    std::cout << "\n------------------------\n";
    bool a = true;
    bool b = false;
    std::cout <<"LOGICAL OPERATORS\n"<< "Boolean Values: TRUE, FALSE";
    if (logicalOperators(a,b)){
        std::cout << "\nThe function correctly displayed the results of the logical operators!";
    }else{
       std::cout << "\nThe function failed to display the results.";
    }
    
    return 0;
}
int sumOfTwoNum(int fNum, int sNum){
    int sum = fNum + sNum;
    return sum;
} // a function was created that takes two numbers and displays the sum. 
bool greaterThan(int varA, int varB){
     return varA > varB;
} // if varA is greater than varB then a boolean value of 1 will be returned.
bool logicalOperators(bool a, bool b){
   std::cout << "\nAND: " << ((a && b) ? "True" : "False");
   std::cout << "\nOR: " << ((a || b) ? "True" : "False");
   std::cout << "\nNOT A: " << ((!(a)) ? "True" : "False");
   std::cout << "\nNOT B: " << ((!(b)) ? "True" : "False");
  return true;
}// this code takes two boolean values and passes them though logical operators to see if
// it will result in True or False. 