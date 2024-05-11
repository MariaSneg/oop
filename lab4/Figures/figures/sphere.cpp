#include "Sphere.h"
#include <sstream>
#define _USE_MATH_DEFINES
#include <math.h>

CSphere::CSphere(std::istream& in, std::ostream& out, double density, double radius)
	: CBody("Sphere", density, in, out)
	, m_radius(radius)
{
}

CSphere::CSphere(std::istream& in, std::ostream& out)
	: CBody("Sphere", in, out)
{
}

double CSphere::GetRadius()const
{
	return m_radius;
}

double CSphere::GetVolume()const
{
	return (pow(m_radius, 3) * M_PI) * 4.0 / 3.0;
}

void CSphere::AppendProperties(std::ostream& strm) const
{
	strm << "\tradius = " << GetRadius() << std::endl;
}

void CSphere::AddProperties()
{
    while (true) {
        m_output << "Enter the radius of the sphere" << std::endl;
        if (!(m_input >> m_radius))
        {
            m_output << "Please enter a positive number." << std::endl;
        }
        else if (m_radius > 0) {
            break;
        }
        else {
            m_output << "Please enter a positive number for the radius." << std::endl;
        }
    }
}