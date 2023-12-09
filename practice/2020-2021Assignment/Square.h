#ifndef Square_h
#define Square_h
// empty test header to start experimenting
class Square{

    bool init_flag;

public:
    double getArea(){};

    double getPerimeter(){};

    double getSide(){};

    bool getCoord(double& out_Cx, double& out_Cy){};

    void printShapeAndCoordinfo(){};

    void printInfo(){};

    bool inputSide(double in_side){};

    bool inputCoord(double in_Cx, double in_Cy){};

    void resetShape(){};

    void resetCoord(){};

    bool inputSideFromKeyboard(){};

    bool inputRandomSide(double max_val = 10){};

    bool inputRandomCoord(double max_val = 25){};

};
#endif

