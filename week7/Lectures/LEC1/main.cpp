#include "RectangleExample.h" // include the header file with the class definition
void array_of_object(){
    double test_sideA, test_sideB;
    test_sideA=10;
    test_sideB=15.5;

    static const int arraysize=10; // the size of the array is known to the compiler

    rectangle rct_array[arraysize]; // the constructor is automatically invoked for all 10 elements
    for(int i=0; i<arraysize; i++){
        test_sideA=test_sideA + i;
        test_sideB=test_sideB + i;
        rct_array[i].inputsides(test_sideA,test_sideB);
        cout << "rectangle position: " << i << endl;
        cout << "rectangle(1) side A is: " << rct_array[i].getSide(1) << endl;
        cout << "rectangle(1) side B is: " << rct_array[i].getSide(2) << endl;
        cout << "rectangle(1) area is: " << rct_array[i].getArea() << endl;
        cout << "rectangle(1) perimeter is: " << rct_array[i].getPerimeter() << endl;
    }
}



int main(){
    // Language-defined variable type double
    // double test_sideA, test_sideB;
    // test_sideA = 10;
    // test_sideB = 15.5;

    // User-defined varible type rectangle
    // rectangle testrec1, testrec2;
    // testrec1.inputsides(test_sideA, test_sideB);
    // cout << "rectangle(1) side A is: " << testrec1.getSide(1) << endl;
    // cout << "rectangle(1) side B is: " << testrec1.getSide(2) << endl;
    // cout << "rectangle(1) area is: " << testrec1.getArea() << endl;

    // cout << endl << endl;
    // testrec2.inputSidesFromKeyboard();
    // cout << "rectangle(2) side A is: " << testrec2.getSide(1) << endl;
    // cout << "rectangle(2) side B is: " << testrec2.getSide(2) << endl;
    // cout << "rectangle(2) area is: " << testrec2.getArea() << endl;

    // right_triangle testri1;
    // testri1.inputSidesFromKeyboard();
    // cout << "triangle(1) side A is: " << testri1.getSide(1) << endl;
    // cout << "triangle(1) side B is: " << testri1.getSide(2) << endl;
    // cout << "triangle(1) area is: " << testri1.getArea() << endl;

    array_of_object();

    return 0;
}
