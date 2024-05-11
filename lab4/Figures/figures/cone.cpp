#include "cone.h"
#include <sstream>
#define _USE_MATH_DEFINES
#include <math.h>

CCone::CCone(std::istream& in, std::ostream& out, double density, double baseRadius, double height)
	: CBody("Cone", density, in, out)
	, m_baseRadius(baseRadius)
	, m_height(height)
{
}

CCone::CCone(std::istream& in, std::ostream& out)
	: CBody("Cone", in, out)
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
	return (pow(m_baseRadius, 2) * M_PI) * m_height / 3.0;
}

void CCone::AppendProperties(std::ostream& strm) const
{
	strm << "\tbase radius = " << GetBaseRadius() << std::endl
		<< "\theight = " << GetHeight() << std::endl;
}

void CCone::AddProperties()
{
	while (true) {
		m_output << "Enter the base radius and height of the cone" << std::endl;
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
