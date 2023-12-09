#pragma once

//*
#include <iostream>
using namespace std;
#include <stdint.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string>
// NOTE: some functions (e.g. to_string() ) and syntax (e.g. enum class) used below require the compiler to enable C++11 features. 
// By default, Dev-Cpp does not enable C++11. In order to enable those features (and compile this file), set your Dev project as follows:
// Select Menu: Project 
// select: Project Option
// Select tab: Compiler
// Select tab: Code Genration
// From: language standard dropdown menu
// select:  ISO C++11
//
// The menu looks similar (but not identical) to this: https://cplusplus.com/doc/tutorial/introduction/devcpp/devcpp2.png

// point integer coordinates 
struct point_i {
	int x, y;	
	string point2string() const
	{
		string result;
		result += "x = ";
		result += to_string(x);
		result += " ; y = ";
		result += to_string(y);

		return result;
	}
};

struct point_f {
	float x, y;	
	string point2string() const
	{
		string result;
		result += "x = ";
		result += to_string(x);
		result += " ; y = ";		
		result += to_string(y);

		return result;
	}
	void rotateBy(float angle_rad)
	{
		float rotated_x, rotated_y;
		// new coordinates: rotate by angle_rad
		rotated_x = (x * cos(angle_rad)) - ((y * sin(angle_rad)));
		rotated_y = (x * sin(angle_rad)) + ((y * cos(angle_rad)));
		// set as new coordinates
		x = rotated_x;
		y = rotated_y;
	}
	//
	const static double PI_rad;
};

const double point_f::PI_rad = (2 * asin(1.0));

// enums for the colors;
enum class DrawingColor_Code {
	black = 0, red, blue, green, cyan, yellow, purple, pink, LAST_NOT_VALID
};	

struct bmp_header {
	uint16_t signature; // 'B' followed by 'M'
	uint32_t img_size;	// File Size (4 B)
	uint32_t rsvd;		// Reserved"1+2" (4 B tot)
	uint32_t img_offs;	// File Offset to PixelArray (4 B): the value appears set to 54 (not sure why).
	
	// DIB header - bitmap information header: Windows BITMAPINFOHEADER
	uint32_t hdr_size;	// Header size (4 B): the value is set to 40 bytes.
	uint32_t width;		// image width in pixels (4 B)
	uint32_t height;	// image height in pixels (4 B)
	uint16_t planes;	// number of colr planes (2 B): the value is set to 1
	uint16_t depth;		// color depth of the image, i.e. bits per pixel (2 B): set to 32 (4 bytes)
	
	uint32_t unused[6]; // 6 fields (4 B each): 
						// the compression method used: value = 0 <=> BI_RGB, i.e. none.
						// the compression method used: value = 0 <=> BI_RGB, i.e. none.
						// Size of the raw bitmap data; a dummy 0 can be given for BI_RGB bitmaps.
						// Horizontal resolution of the image. (pixel per metre, signed integer)
						// Verical resolution of the image. (pixel per metre, signed integer)
						// Number of colors in the color palette; 0 to default to 2n
						// Number of important colors used; 0 when every color is important
	bmp_header() 
	{ 
		signature = 0; img_size = 0; rsvd = 0; img_offs = 0; hdr_size = 0;
		width = 0; height = 0; planes = 0; depth= 0;
		unused[0] = 0; unused[1] = 0; unused[2] = 0;
		unused[3] = 0; unused[4] = 0; unused[5] = 0;
	}
};

class basicDrawingCanvas {
protected:
	//static const uint32_t correct_cmap[];
	uint32_t* map;
	uint32_t width, height;
	static const int default_width = 640;
	static const int default_height = 400;
	bool mem_allocated;
	//
	bmp_header header;
	inline uint32_t color_map(DrawingColor_Code color)
	{
		uint32_t AARRGGBB;
		switch (color) {
		case DrawingColor_Code::red:
			AARRGGBB = 0x00FF0000;
			break;
		case DrawingColor_Code::blue:
			AARRGGBB = 0x000000FF;
			break;		
		case DrawingColor_Code::cyan:
			AARRGGBB = 0x0000FFFF;
			break;
		case DrawingColor_Code::green:
			AARRGGBB = 0x0000FF00;
			break;
		case DrawingColor_Code::yellow:
			AARRGGBB = 0x00FFFF00;
			break;
		case DrawingColor_Code::purple:
			AARRGGBB = 0x00FF00FF;
			break;
		case DrawingColor_Code::pink:
			AARRGGBB = 0x00FFC0CB;
			break;
		case DrawingColor_Code::black:
			;
		default:
			AARRGGBB = 0x00000000;
		}
		return AARRGGBB;
	}
	// 
	// Write 32 Litte Endian 
	uint32_t write32le(uint32_t x)
	{
		const uint32_t test = 0x00000001;
		if (*(uint8_t*)&test) return x;
		return x << 24 | x >> 24 |
			(0x00FF0000 & x) << 8 |
			(0x0000FF00 & x) << 8;
	}

	// Write 16 Litte Endian 
	uint16_t write16le(uint16_t x)
	{
		const uint16_t test = 0x0001;
		if (*(uint8_t*)&test) return x;
		return x << 8 | x >> 8;
	}
	virtual bool format_and_write_header(FILE* fp)
	{
		// based on (BI_RGB):
		// https://en.wikipedia.org/wiki/BMP_file_format
		// https://upload.wikimedia.org/wikipedia/commons/7/75/BMPfileFormat.svg
		
		bool result = false;
		if (mem_allocated && (fp!=NULL))
		{
			uint32_t w = width, h = height;
			header.signature = write16le(0x4d42);
			header.img_size = write32le(54 + 4 * w * h);
			header.img_offs = write32le(54);//54
			header.hdr_size = write32le(40);
			header.width = write32le(w);
			header.height = write32le(h);

			// test introduce the two lines below
			header.planes = write16le(1);
			header.depth = write16le(32);

			// test: set to 0 the "unused fields" and the reserved.
			for (int i = 0; i < 6; i++)
				header.unused[i] = write32le(0);
			header.rsvd = write32le(0);

			// test: write the header field-by-field in the correct order
			fwrite(&header.signature, 1, 2, fp);
			fwrite(&header.img_size, 1, 4, fp);
			fwrite(&header.rsvd, 1, 4, fp);
			fwrite(&header.img_offs, 1, 4, fp);
			fwrite(&header.hdr_size, 1, 4, fp);
			fwrite(&header.width, 1, 4, fp);
			fwrite(&header.height, 1, 4, fp);
			fwrite(&header.planes, 1, 2, fp);
			fwrite(&header.depth, 1, 2, fp);
			fwrite(&header.unused[0], 6, 4, fp);

			result = true;
		}
		return result;
	}
	virtual void check_sizes(uint32_t& in_width, uint32_t& in_height)
	{
		// default check
		if (in_width == 0 || in_height == 0)
		{
			in_width = default_width;
			in_height = default_height;
		}
	}
	void release_mem()
	{
		if (mem_allocated)
		{
			free(map);
			map = NULL;
			mem_allocated = false;
		}
	}
public:
	basicDrawingCanvas()
	{
		mem_allocated = false;
		width = default_width;
		height = default_height; 
		map = NULL;
	}
	~basicDrawingCanvas()
	{
		release_mem();
	}
	bool make_canvas(uint32_t in_width, uint32_t in_height)
	{
		bool result = false;
		if (mem_allocated)
		{
			cout << "Warning in make_canvas(): resetting an existing canvas (any content will be lost)" << endl;
			release_mem();
		}
		check_sizes(in_width, in_height);

		map = (uint32_t*)malloc(((unsigned int)in_width) * ((unsigned int)in_height) * 4);
		if (map != NULL)
		{
			width = in_width;
			height = in_height;
			memset(map, 0xFF, ((unsigned int)in_width) * ((unsigned int)in_height) * 4);
			mem_allocated = true;
			result = true;
		}
		else
			cout << "ERROR: Out of Mem in make_canvas()" << endl;
		
		return result;
	}
	bool make_canvas()
	{
		return make_canvas(default_width, default_height);
	}
	bool draw_point(point_i p, DrawingColor_Code col)
	{
		bool result = false;
		if (mem_allocated)
		{
			if ((0 <= p.x) && (p.x < width) && (0 <= p.y) && (p.y < height))
			{
				map[p.x + (p.y * width)] = write32le(color_map(col));
				result = true;
			}				
		}
		return result;
	}

	bool draw_line(point_i p0, point_i p1, DrawingColor_Code col)
	{
		bool result = false;
		if (mem_allocated)
		{
			point_i w = p0;
			int dx, dy, p, q1, q2;
			int sgn = 1;

			dx = p1.x - p0.x;
			if (dx < 0) {
				// p0 always left point 
				w = p1; p1 = p0; p0 = w;
				dx = -dx;
			}

			dy = p1.y - p0.y;
			if (dy < 0) {
				dy = -dy;
				sgn = -1;
			}

			if (dx > dy) {
				p = 2 * dy - dx;
				while (w.x <= p1.x)
				{
					result = draw_point(w, col);
					if (p >= 0) {
						w.y += sgn;
						p -= 2 * dx;
					}
					w.x++;
					p += 2 * dy;
				}
			}
			else {
				p = 2 * dx - dy;
				while (w.y - p0.y <= dy && w.y - p0.y >= -dy) {
					result = draw_point(w, col);
					if (p >= 0) {
						w.x++;
						p -= 2 * dy;
					}
					w.y += sgn;
					p += 2 * dx;
				}
			}			
		}
		
		return result;
	}

	bool save_bitmap(const string& filename)
	{
		bool result = false;
		if (mem_allocated)
		{
			FILE* fp;
			//uint16_t gap_to_56;			
			const char* cString = filename.c_str();			
			// note: VS 2019 by default complains about "fopen" not being secure.
			// fopen_s does not work either (with this toolkit, C++11).
			// A soplution is to use ofstream instead, but need to check the binary flags first
			// (also, need to check the equivalent of "fwrite" produces the intended result). 
			// 
			// So, for the time being:
			// go to: Project / Properties / C/C++ / Preprocessor 
			// Define Preprocessor Definition: _CRT_SECURE_NO_WARNINGS
			//
			fp = fopen(cString, "wb");
			if (fp != NULL)
			{
				// bmp header 
				if (format_and_write_header(fp))
				{
					fwrite(map, (((int)width) * ((int)height)), 4, fp);   // write map
					fclose(fp);
					result = true;
				}
				
			}
			else
				cout << "Error in save_bitmap(), can't open file: " << endl << filename;
		}	
		return result;
	}	 
};




class lineDrawingCanvas {
protected:
	basicDrawingCanvas canvas;
	bool paramsSetFlag;
	float x_min, x_max, y_min, y_max;
	float pixelsPerLengtUnit;	
	static const int default_x_max = 100;
	static const int default_y_max = 100;
	static const int default_pplu = 30;
	string fileName, basedirName, slash;
	// determine size/position of arrow tipand marks  
	int L_points; float tick_unit;
	bool draw_C_Axes(int L_points)
	{	// float unit_x, float unit_y
		bool result = false;
		// local variable to determine size (and position) of "arrow tip"  		
		float L_length = L_points / pixelsPerLengtUnit;
		point_f xLeft, xRight, yTop, yBottom;

		xLeft.x = x_min + L_length; xLeft.y = 0;
		xRight.x = x_max - L_length; xRight.y = 0;
		yTop.y = y_max - L_length; yTop.x = 0;
		yBottom.y = y_min + L_length; yBottom.x = 0;

		// x axis
		result = draw_line(xLeft, xRight, DrawingColor_Code::black);
		// y axis
		result = (result && draw_line(yTop, yBottom, DrawingColor_Code::black));

		// draw edges of "arrow tips"
		point_f xArrowEdgeUp, xArrowEdgeDown, yArrowEdgeLeft, yArrowEdgeRight;
		// x axis
		xArrowEdgeUp.x = xRight.x - (3 * L_length); xArrowEdgeUp.y = 2 * L_length;
		xArrowEdgeDown.x = xRight.x - (3 * L_length); xArrowEdgeDown.y = -2 * L_length;
		result = (result && draw_line(xArrowEdgeUp, xRight, DrawingColor_Code::black));
		result = (result && draw_line(xArrowEdgeDown, xRight, DrawingColor_Code::black));
		// y axis
		yArrowEdgeLeft.y = yTop.y - (3 * L_length); yArrowEdgeLeft.x = 2 * L_length;
		yArrowEdgeRight.y = yTop.y - (3 * L_length); yArrowEdgeRight.x = -2 * L_length;
		result = (result && draw_line(yArrowEdgeLeft, yTop, DrawingColor_Code::black));
		result = (result && draw_line(yArrowEdgeRight, yTop, DrawingColor_Code::black));
		return result;
	}
public:
	lineDrawingCanvas() 
	{
		paramsSetFlag = false; 
		L_points= -1;
		tick_unit = -1;
	};
	// setters
	bool setCanvasParams(float canv_x_min, float canv_x_max, float canv_y_min, float canv_y_max, float canv_pplu)
	{
		bool result = false;
		uint32_t in_width, in_height;
		// check input values are consistent: otherwise use default
		if (canv_x_min >= canv_x_max)
		{
			canv_x_min = -default_x_max;
			canv_x_max = default_x_max;
		}
		if (canv_y_min >= canv_y_max)
		{
			canv_y_min = -default_y_max;
			canv_y_max = default_y_max;
		}
		if (canv_pplu <= 0)
			canv_pplu = default_pplu;
		//
		
		int canv_width = (canv_x_max - canv_x_min) * canv_pplu + 0.4999;// round up
		int canv_height = (canv_y_max - canv_y_min) * canv_pplu + 0.4999;// round up
		in_width = canv_width; in_height = canv_height;
		
		// Ensure size can be represented with 32 bits (limited by the bitmap header)
		if (((canv_width - in_width) == 0) && ((canv_height - in_height) == 0))
		{
			x_min = canv_x_min; x_max = canv_x_max; 
			y_min = canv_y_min; y_max = canv_y_max;
			pixelsPerLengtUnit = canv_pplu;
			paramsSetFlag = canvas.make_canvas(in_width, in_height);
			result = paramsSetFlag;
		}
		else
			cout << "Error in setCanvasParams: canvas dimentions not supported" << endl;
		return result;		
	}
	bool setCanvasParams()
	{
		return setCanvasParams(-default_x_max, default_x_max, -default_y_max, default_y_max, default_pplu);
	}
	void setFilename(string in_fileName)
	{
		fileName = in_fileName + ".bmp";
	}
	void setFilename(string in_fileName, string in_basedirName, bool windSlash = true)
	{
		setFilename(in_fileName);
		basedirName = in_basedirName;
		if (windSlash)
			slash = "\\";
		else
			slash = "//";
	}
	// getters
	bool isCanvasSet() const { return paramsSetFlag;}
	bool getCanvasParams(float& canv_x_min, float& canv_x_max, float& canv_y_min, float& canv_y_max, float& canv_pplu) const
	{ 
		bool result = false; 
		if (isCanvasSet())
		{
			canv_x_min = x_min; canv_x_max = x_max;
			canv_y_min = y_min; canv_y_max = y_max;
			canv_pplu = pixelsPerLengtUnit;
			result = true;
		}
		return result;
	}
	//
	void printInfo()
	{
		float canv_x_min, canv_x_max, canv_y_min, canv_y_max, canv_pplu;
		cout << "Line Drawing Canvas Paramters: ";
		if (getCanvasParams(canv_x_min, canv_x_max, canv_y_min, canv_y_max, canv_pplu))
		{
			cout << endl;
			cout << " Canvas X range = [ " << canv_x_min << " , " << canv_x_max << " ];" << endl;
			cout << " Canvas Y range = [ " << canv_y_min << " , " << canv_y_max << " ];" << endl;
			cout << " Canvas Pixels Per Lengt Unit = " << canv_pplu << endl;
			cout << " Output File Name = ";			
			if (basedirName.length()==0)
				cout << fileName << endl;
			else
				cout << (basedirName + slash + fileName) << endl;
			if(tick_unit>0)
				cout << " Tick unit on axes = " << tick_unit << endl;
		}
		else
			cout << "NOT set" << endl;	
	}
	
	// function to draw a line on the canvas
	bool draw_line(point_f p0, point_f p1, DrawingColor_Code col)
	{
		bool result = false;
		// if canvas is not set, use default values
		if (!isCanvasSet())
		{
			cout << "Canvas has not been set: assuming default values" << endl;
			result = setCanvasParams();			
			if (!result)
				return result;
		}

		// check limits
		if (p0.x > x_min && p0.x < x_max && p0.y > y_min && p0.y < y_max)
		{
			if (p1.x > x_min && p1.x < x_max && p1.y > y_min && p1.y < y_max)
			{
				// now offset to (0,0);
				point_i p0_i, p1_i;
				p0_i.x = pixelsPerLengtUnit * (p0.x - x_min);
				p0_i.y = pixelsPerLengtUnit * (p0.y - y_min);
				p1_i.x = pixelsPerLengtUnit * (p1.x - x_min);
				p1_i.y = pixelsPerLengtUnit * (p1.y - y_min);
				result = canvas.draw_line(p0_i, p1_i, col);
			}
			else
				cout << "Error: p1 is outside the range" << endl;
		}
		else
			cout << "Error: p0 is outside the range" << endl;

		return result;
	}
	
	// function to draw axis line on the canvas
	bool draw_CartesianAxes()
	{	// float unit_x, float unit_y
		bool result = false;
		// if canvas is not set, use default values
		if (!isCanvasSet())
		{
			cout << "Canvas has not been set: assuming default values" << endl;
			result = setCanvasParams();
			if (!result)
				return result;
		}

		// set variable to determine size (and position) of "arrow tip"
		if(L_points<0)
			L_points = 5;		
		
		result = draw_C_Axes(L_points);

		return result;
	}
	bool draw_CartesianAxes(float unit)
	{	
		bool result = false;		
		float unit_x, unit_y;
		// draw axes first
		result = draw_CartesianAxes();
		if (!result)
			return result;
		
		if (unit > 0)
		{// if "unit" is inconsistent: skip 
			
			// if "y unit" is inconsistent or missing: use "x unit"			
			//if (unit_y <= 0)
			//	unit_y = unit_x;

			// for the time being, use the same unit on both axes
			unit_x = unit;
			unit_y = unit_x;
			
			// set param for printing.
			tick_unit = unit;

			float L_length = L_points / pixelsPerLengtUnit;

			// x axis 
			{
				point_f xTickEdgeUp, xTickEdgeDown;
				// x>0 
				xTickEdgeUp.y = L_length; xTickEdgeDown.y = -L_length;
				result = true;
				for (float xTick_x = unit_x; xTick_x < x_max; xTick_x += unit_x)
				{
					xTickEdgeUp.x = xTick_x; xTickEdgeDown.x = xTick_x;
					result = (result && draw_line(xTickEdgeUp, xTickEdgeDown, DrawingColor_Code::black));
					if (!result)
						return result;

				}
				// x<0 
				for (float xTick_x = -unit_x; xTick_x > x_min; xTick_x -= unit_x)
				{
					xTickEdgeUp.x = xTick_x; xTickEdgeDown.x = xTick_x;
					result = (result && draw_line(xTickEdgeUp, xTickEdgeDown, DrawingColor_Code::black));
					if (!result)
						return result;

				}
			}
			
			// Y axis 
			{
				point_f yTickEdgeLeft, yTickEdgeRight;
				// y>0 
				yTickEdgeLeft.x = -L_length; yTickEdgeRight.x = L_length;
				//result = true;
				for (float yTick_y = unit_y; yTick_y < y_max; yTick_y += unit_y)
				{
					yTickEdgeLeft.y = yTick_y; yTickEdgeRight.y = yTick_y;
					result = (result && draw_line(yTickEdgeLeft, yTickEdgeRight, DrawingColor_Code::black));
					if (!result)
						return result;

				}
				// y<0 
				for (float yTick_y = -unit_y; yTick_y > y_min; yTick_y -= unit_y)
				{
					yTickEdgeLeft.y = yTick_y; yTickEdgeRight.y = yTick_y;
					result = (result && draw_line(yTickEdgeLeft, yTickEdgeRight, DrawingColor_Code::black));
					if (!result)
						return result;

				}
			}			
		}

		return result;
	}

	// function to store the canvas to file
	bool save_bitmapFile()
	{
		bool result;
		if (fileName.length() == 0)
			setFilename("drawing");
		
		result = canvas.save_bitmap(basedirName + slash + fileName);
		
		return result;		
	}
	string getBitmapFileName()
	{
		string result = basedirName + slash + fileName;
		return result;

	}
	// sets existing canvas to blank (including Axes)
	bool wipe_Canvas()
	{
		if(isCanvasSet())
			return setCanvasParams(x_min, x_max, y_min, y_max, pixelsPerLengtUnit);
		return true;
	}
	// utility to print the color to screen
	static string getColorNameFromCode(DrawingColor_Code color) 
	{
		string result;
		switch (color) {
		case DrawingColor_Code::red:
			result = "Red";
			break;
		case DrawingColor_Code::blue:
			result = "Blue";
			break;
		case DrawingColor_Code::cyan:
			result = "Cyan";
			break;
		case DrawingColor_Code::green:
			result = "Green";
			break;
		case DrawingColor_Code::yellow:
			result = "Yellow";
			break;
		case DrawingColor_Code::purple:
			result = "Purple";
			break;
		case DrawingColor_Code::pink:
			result = "Pink";
			break;
		case DrawingColor_Code::black:
			result = "Black";
			break;
		default:
			result = "Not Recognized";
			break;
		}
		return result;
	}
};


//lineDrawingCanvas EE3093_lineDrawingCanvas;
