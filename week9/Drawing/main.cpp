#include "DrawingKiteExample.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */



void drawKiteExample()
{
	kite test_kt;
	point_f centre;
	float width, height;
	
	
	// for drawing: 
	lineDrawingCanvas test_LDC;
	// to set directory and file name
	string baseDirectoryName, fileName;
	
	// Use this when working on campus PCs;
	// baseDirectoryName = "S:\\temp";
	
	// Alernatively Use this when working on VDI;
	//baseDirectoryName = "C:\\temp\\EE3093\\scripts";	
	//baseDirectoryName = "H:\\C++\\week3\\LAB\\Drawing";	
	
	// Use a different baseDirectoryName if working from your laptop 	
	//baseDirectoryName = "C:\\Mydir\\mysubdir\\mytest";
	baseDirectoryName = "\\Users\\chenjingfeng\\Desktop\\3093\\week9\\Drawing\\ResultForDrawing";
	
	// Now set the filename to be used by the canvas object
	fileName = "EE3093_test_Drawing";
	test_LDC.setFilename(fileName, baseDirectoryName);	
	
	
	// other settings (leave as is or ask staff)
	// set the unit ticks on axes every K_units
	cout << "*************************** " << endl;
	int K_units = 5;
	test_LDC.draw_CartesianAxes(K_units);	
	cout << "* Drawing Canvas Axes marked with ticks that are " << K_units << " units apart" << endl;
	float canv_x_min, canv_x_max, canv_y_min, canv_y_max, canv_pplu;
	test_LDC.getCanvasParams(canv_x_min, canv_x_max, canv_y_min, canv_y_max, canv_pplu);
	cout << "* Drawing Canvas: x range within " << canv_x_min << " and " << canv_x_max << endl;
	cout << "* Drawing Canvas: y range within " << canv_y_min << " and " << canv_y_max << endl;
	cout << "* Drawing Canvas: " << canv_pplu << " points can be drawn per length unit" << endl;
	cout << "* "; test_LDC.printInfo();
	cout << "**************************** " << endl;
	
	
	
	// set some sensible values for kite to be drawn
	centre.x=0; centre.y=0;
	width = 40; height = 60;		
	test_kt.setKite(centre, width, height);
	test_kt.printInfo();
	// now draw:
	bool result = test_kt.drawOnCanvas(test_LDC);
	if(result)
	{
		result = test_LDC.save_bitmapFile();
		if(result)
			cout << " Drawing suceeded, check file: " << test_LDC.getBitmapFileName() << endl;
		else
			cout << " Saving to file failed." << endl;
	}		
	else
		cout << " Drawing failed." << endl;
	
	
}



int main(int argc, char** argv) {
	drawKiteExample();
	return 0;
}
