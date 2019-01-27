
#ifndef POLYGON_H_
#define POLYGON_H_
#include <iostream>
#include <fstream> //Including required libraries.
#include <stdlib.h>
#include "Shape.h"
using namespace std;
namespace PatogluShape
{
	class Polygon:public Shape
	{
	public:
		class Point2D
		{
			public:
				Point2D();
				void setTwoDx(double the2Dx);
				void setTwoDy(double the2Dy);
				double getTwoDx() const;
				double getTwoDy() const;
			private:
				double twoDx;
				double twoDy;
		};	
	};
}
#endif 


