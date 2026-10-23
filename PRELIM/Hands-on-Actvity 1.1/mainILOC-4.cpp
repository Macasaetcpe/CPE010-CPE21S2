#include <iostream>

class Triangle{
    private:
        double totalAngle, angleA, angleB, angleC, sideA, sideB, sideC, base, height;
    public:
        Triangle(double A, double B, double C);
        void setAngles(double A, double B, double C);
        const bool validateTriangle();
        double periTriangle();
        void setSides(double A, double B, double C);
        void triangleTypes();
        void setBh(double A, double B);
        double area();
};

int main(){

    Triangle set1(40,30,110);
    if (set1.validateTriangle()){
        std::cout << "The shape is a valid triangle.\n";
    }else {
        std::cout << "The shape is NOT a valid triangle. \n";
    }
    
    set1.triangleTypes();
    
    
    set1.setSides(10, 20, 25);
    std::cout<< "The perimeter of the triangle is " << set1.periTriangle();
    set1.setBh(20, 30);
    std::cout<< "\nThe area of the triangle is "<< set1.area();


    return 0;
}

Triangle::Triangle(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}
void Triangle::setAngles(double A, double B, double C){
    angleA = A;
    angleB = B;
    angleC = C;
    totalAngle = A + B + C;
}
const bool Triangle::validateTriangle(){
    return (totalAngle <= 180);
}
void Triangle::setSides(double A, double B, double C){
    sideA = A;
    sideB = B;
    sideC = C;
}
double Triangle::periTriangle(){
    double perimeter = sideA + sideB + sideC;
    return perimeter;
}

void Triangle::triangleTypes(){
    int obtuse = (angleA < 90) + (angleB < 90) + (angleC < 90);

    if (angleA < 90 && angleB < 90 && angleC < 90) {
        std::cout << "The triangle is an acute triangle\n";
    }
    else if (obtuse == 2) {
        std::cout << "The triangle is an obtuse triangle\n";
    }else{
        std::cout<<"the triange is neither obtuse or acute triangle\n";
    }
}

void Triangle::setBh(double A, double B){
    base = A;
    height = B;
}
double Triangle::area(){
    double area = (0.5)*base*height;
    return area;
} // This code added 3 new things to ILO B which is getting the area, perimeter, 
// and determing whether a triangle is obtuse, acute, or other. 
// This was done by creating new functions.

