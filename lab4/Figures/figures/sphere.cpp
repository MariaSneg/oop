#include "Sphere.h"
#include <sstream>
#define _USE_MATH_DEFINES
#include <math.h>

CSphere::CSphere(double density, double radius)
	: CBody("Sphere", density)
	, m_radius(radius)
{
}

double CSphere::GetRadius()const
{
	return m_radius;
}

double CSphere::GetVolume()const
{
	return (pow(m_radius, 3) * M_PI) * 4 / 3;
}

void CSphere::AppendProperties(std::ostream& strm) const
{
	strm << "\tradius = " << GetRadius() << std::endl;
}

void CSphere::AddProperties(std::istream& in, std::ostream& out)
{
	out << "Enter the density and radius of the sphere" << std::endl;
	in >> m_radius;
}