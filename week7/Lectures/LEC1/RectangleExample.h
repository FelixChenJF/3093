#ifndef RectangleExample_h
#define RectangleExample_h

#include <iostream>
using namespace std;

class rectangle{ // Keyword class; Defintion inside braces
protected: // Protected(private) members: these are the inner parts of the object
    double sideA, sideB; // member variables
    double area;
    double perimeter;

    // initialization flag
    bool init_flag;

    void computeArea(){ // member function
        area = sideA * sideB;
    }

    void computePerimeter(){
        perimeter = 2 * (sideA + sideB);
    }

public: // public member functions: openly accessible to the user (interface)
    // constructor
    rectangle(){
        init_flag=false;
    }
    double getArea(){return area;} // public members

    double getPerimeter(){return perimeter;}

    bool isInitialized(){return init_flag;}
    double getSide(int sidenum) {
        double out;
        if(isInitialized()){
            switch (sidenum)
                {
                case 1:
                    out=sideA;
                    break;
                case 2:
                    out=sideB;
                    break;
                default:
                    cout << "Error in getSide(): Incorrect sidenum values" << endl;
                    out=-1;
            }
        }else{
            cout << "Error in getSide(): The triangle is not initialized" << endl;
            out=-1;
        }           
        return out;
    }

    void inputsides(double in_sideA, double in_sideB) {
        if(in_sideA>0 && in_sideB>0){
            sideA=in_sideA;
            sideB=in_sideB;
            init_flag=true;
            computeArea();
            computePerimeter();
        }else{
            cout << "Error in inputSides(): Incorrect input values" << endl;
            init_flag=false;
        }
    }

    void inputSidesFromKeyboard(){
        double in_sideA, in_sideB;
        cout << "Please enter dimension of side A of the Rectangle (then hit Enter)" << endl;
        cin >> in_sideA;
        cout << "Please enter dimension of side B of the Rectangle (then hit Enter)" << endl;
        cin >> in_sideB;

        inputsides(in_sideA, in_sideB);
    }
    double getArea();
}; // Terminate with semicolon

class right_triangle{
protected:
    rectangle SideAandSideB;

    double sideC;

    double area;
    double perimeter;

    void computeArea(){
        area = SideAandSideB.getArea()/2;
    }

    void computePerimeter(){
        perimeter = SideAandSideB.getPerimeter()/2 + sideC;
    }

    void computeHypontenus(){ // 斜边
        if(SideAandSideB.isInitialized()){
            double in_sideA=SideAandSideB.getSide(1);
            double in_sideB=SideAandSideB.getSide(2);
            sideC = sqrt(in_sideA * in_sideA + in_sideB + in_sideB);
        }
    }
public:
    double getPerimeter(){
        if(SideAandSideB.isInitialized()){
            return perimeter;
        }else{
            cout << "Error in getPerimeter(): Triangle is not initialized" << endl;
        }
        return 0;
    }

    double getArea(){
        if(SideAandSideB.isInitialized()){
            return area;
        } else{
            cout << "Error in getArea(): Triangle is not initialized" << endl;
        }
        return 0;
    }

    bool isInitialized(){
        return SideAandSideB.isInitialized();
    }

    double getSide(int sidenum) {
        double out;
        if(isInitialized()){
            switch(sidenum){
                case 1:
                case 2:
                    out=SideAandSideB.getSide(sidenum);
                    break;
                case 3:
                    out=sideC;
                    break;
                default:
                    cout << "Error in getSides(): Incorrect sidenum value" << endl;
                }
            }else{
                cout << "Error in getSide(): Triangke is not initialized" << endl;
                out=-1;
        }
        return out;
    }
    void inputSides(double in_sideA, double in_sideB){
        if(!isInitialized()){
            if(in_sideA>0 && in_sideB>0){
                SideAandSideB.inputsides(in_sideA, in_sideB);

                computeHypontenus();

                computeArea();
                computePerimeter();
            }else{
                cout << "Error in inputSides(): Incorrect input values" << endl;
            }
        }else{
            cout << "Error in inputSides(): Triangle is already initialized" << endl;
        }
    }

    void inputSidesFromKeyboard(){
        double in_sideA, in_sideB;
        cout << "Please enter dimension of side A of the Triangle (then hit Enter)" << endl;
        cin >> in_sideA;
        cout << "Please enter dimension of side B of the Triangle (then hit Enter)" << endl;
        cin >> in_sideB;

        inputSides(in_sideA, in_sideB);

        if(isInitialized()){
            cout << "Dimension of size C of the triangle is: " << sideC << endl; 
        }else{
            cout << "Error in inputSidesFromKeyboard(): Triangle is already initialized. " << endl; 
        }

    }
};
#endif
