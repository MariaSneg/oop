#include "parallelepiped.h"
#include <sstream>

CParallelepiped::CParallelepiped(double density, double width, double height, double depth)
	: CBody("Parallelepiped", density)
	, m_width(width)
	, m_height(height)
	, m_depth(depth)
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

void CParallelepiped::AddProperties(std::istream& in, std::ostream& out)
{
	out << "Enter the width, height and depth of the parallelepiped" << std::endl;
	in >> m_width >> m_height >> m_depth;
}