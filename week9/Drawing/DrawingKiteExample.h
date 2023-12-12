# pragma once

#include "BasicDrawing.h"

// Kite center: C
// Kite verices: V1, V2, V3, V4
// Width: distance V2-V4 
// height: distance V1-V3

// ^ y
// | 			V1
// |            +
// |          . | .
// |         .  |  .
// |        .   |   .
// |       .    |    .
// |      .     |     .
// |  V2 +------+ C ---+ V4
// |      .     |     .
// |       .    |    .
// |        .   |   .
// |         .  |  .
// |          . | .
// |            +
// | 	 	    V3
// +--------------------------> x


class kite{
protected:
	bool init;
	float width, height;
	point_f centre, V1, V2, V3, V4;	
	void setVertices()
	{
		V1.x = centre.x; 				V1.y = centre.y + (height/2); 
		V2.x = centre.x - (width/2); 	V2.y = centre.y; 
		V3.x = centre.x; 				V3.y = centre.y - (height/2); 
		V4.x = centre.x + (width/2); 	V4.y = centre.y; 
	}
public:
	kite()	{init=false;}
	bool isSet() {return init;}	
	bool setKite(point_f in_centre, float in_width, float in_height)
	{
		bool result = false;
		if(!isSet())
		{
			if(in_width>0 && in_height>0)
			{
				width = in_width; height = in_height;
				centre = in_centre;
				setVertices();
				init = true;
				result = true;				
			}
			else
				cout << "Error: input paramteres not valid" << endl;
		}
		else
			cout << "Error: kite already set" << endl;
		
		return result;
	}
	bool reset(){init=false;}
	void printInfo()
	{
		if(isSet())
		{
			cout << " Kite centre: " << centre.point2string() << endl;
			cout << " width: " << width << ";  height: " << height <<endl;
			cout << " V1: " << V1.point2string() << endl;
			cout << " V2: " << V2.point2string() << endl;
			cout << " V3: " << V3.point2string() << endl;
			cout << " V4: " << V4.point2string() << endl << endl;
		}
		else
			cout << " Kite is not set" << endl;		
	}
	bool drawOnCanvas(lineDrawingCanvas& the_lineDrawingCanvas)
	{
		bool result = false;
		if(isSet())
		{
			// draw a red outline
			// v1 - v2
			the_lineDrawingCanvas.draw_line(V1, V2, DrawingColor_Code::red);
			// v2 - v3
			the_lineDrawingCanvas.draw_line(V2, V3, DrawingColor_Code::red);
			// v3 - v4
			the_lineDrawingCanvas.draw_line(V3, V4, DrawingColor_Code::red);
			// v4 - v1
			the_lineDrawingCanvas.draw_line(V4, V1, DrawingColor_Code::red);
			
			// draw blue interior (cross)
			// v1 - v3
			the_lineDrawingCanvas.draw_line(V1, V3, DrawingColor_Code::blue);
			// v2 - v4
			the_lineDrawingCanvas.draw_line(V2, V4, DrawingColor_Code::blue);	
			result = true;		
		}
		else
			cout << "Error in drawOnCanvas: kite NOT set" << endl;
		return result;
	}	
};


