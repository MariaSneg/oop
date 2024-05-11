#include "cylinder.h"
#include <sstream>
#define _USE_MATH_DEFINES
#include <math.h>

CCylinder::CCylinder(std::istream& in, std::ostream& out, double density, double baseRadius, double height)
	: CBody("Cylinder", density, in, out)
	, m_baseRadius(baseRadius)
	, m_height(height)
{
}

CCylinder::CCylinder(std::istream& in, std::ostream& out)
	: CBody("Cylinder", in, out)
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

void CCylinder::AddProperties()
{
	while (true) {
		m_output << "Enter the base radius and height of the cylinder" << std::endl;
		if (!(m_input >> m_baseRadius >> m_height))
		{
			m_output << "Please enter a positive number." << std::endl;
		}
		else if (m_baseRadius > 0 && m_height > 0) {
			break;
		}
		else {
			m_output << "Please enter a positive number." << std::endl;
		}
	}
}
