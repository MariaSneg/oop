#include "cone.h"
#include <sstream>
#define _USE_MATH_DEFINES
#include <math.h>

CCone::CCone(double density, double baseRadius, double height)
	: CBody("Cone", density)
	, m_baseRadius(baseRadius)
	, m_height(height)
{
}

double CCone::GetBaseRadius()const
{
	return m_baseRadius;
}

double CCone::GetHeight()const
{
	return m_height;
}

double CCone::GetVolume()const
{
	return (pow(m_baseRadius, 2) * M_PI) * m_height * (1.0 / 3.0);
}

void CCone::AppendProperties(std::ostream& strm) const
{
	strm << "\tbase radius = " << GetBaseRadius() << std::endl
		<< "\theight = " << GetHeight() << std::endl;
}

void CCone::AddProperties(std::istream& in, std::ostream& out)
{
	out << "Enter the base radius and height of the cone" << std::endl;
	in >> m_baseRadius >> m_height;
}
