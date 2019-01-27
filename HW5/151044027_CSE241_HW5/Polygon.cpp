#include "Polygon.h"

namespace PatogluShape
{
	void Polygon::Point2D::setTwoDx(double theTwoDx)
	{
		twoDx = theTwoDx;
	}
	void Polygon::Point2D::setTwoDy(double theTwoDy)
	{
		twoDy = theTwoDy;
	}
	double Polygon::Point2D::getTwoDx() const
	{
		return twoDx;
	}
	double Polygon::Point2D::getTwoDy() const
	{
		return twoDy;
	}
	Polygon::Point2D::Point2D()
	{
		twoDx = 10;
		twoDy = 10;
	}

	ostream& operator << (ostream &output, const Shape *shape);
}