#include "cylinder.h"
#include <sstream>
#define _USE_MATH_DEFINES
#include <math.h>

CCylinder::CCylinder(double density, double baseRadius, double height)
	: CBody("Cylinder", density)
	, m_baseRadius(baseRadius)
	, m_height(height)
{
}

double CCylinder::GetBaseRadius()const
{
	return m_baseRadius;
}

double CCylinder::GetHeight()const
{
	return m_height;
}

double CCylinder::GetVolume()const
{
	return (pow(m_baseRadius, 2) * M_PI) * m_height;
}

void CCylinder::AppendProperties(std::ostream& strm) const
{
	strm << "\tbase radius = " << GetBaseRadius() << std::endl
		<< "\theight = " << GetHeight() << std::endl;
}

void CCylinder::AddProperties(std::istream& in, std::ostream& out)
{
	out << "Enter the base radius and height of the cylinder" << std::endl;
	in >> m_baseRadius >> m_height;
}
