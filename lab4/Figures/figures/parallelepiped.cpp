#include "parallelepiped.h"
#include <sstream>

CParallelepiped::CParallelepiped(std::istream& in, std::ostream& out, double density, double width, double height, double depth)
	: CBody("Parallelepiped", density, in, out)
	, m_width(width)
	, m_height(height)
	, m_depth(depth)
{
}

CParallelepiped::CParallelepiped(std::istream& in, std::ostream& out)
	: CBody("Parallelepiped", in, out)
{
}
double CParallelepiped::GetWidth()const
{
	return m_width;
}

double CParallelepiped::GetHeight()const
{
	return m_height;
}

double CParallelepiped::GetDepth()const
{
	return m_depth;
}

double CParallelepiped::GetVolume()const
{
	return m_width * m_height * m_depth;
}

void CParallelepiped::AppendProperties(std::ostream& strm) const
{
	strm << "\twidth = " << GetWidth() << std::endl
		<< "\theight = " << GetHeight() << std::endl
		<< "\tdepth = " << GetDepth() << std::endl;
}

void CParallelepiped::AddProperties()
{
	while (true) {
		m_output << "Enter the width, height and depth of the parallelepiped" << std::endl;

		if (!(m_input >> m_width >> m_height >> m_depth))
		{
			m_output << "Please enter a positive number." << std::endl;
		}
		else if (m_width > 0 && m_height > 0 && m_depth > 0) {
			break; 
		}
		else {
			m_output << "Please enter a positive number." << std::endl;
		}
	}
}