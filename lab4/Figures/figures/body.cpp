#include "Body.h"
#include <sstream>
#include <iomanip>

CBody::CBody(const std::string& type, double density, std::istream& in, std::ostream& out)
	: m_density(density)
	, m_type(type)
	, m_input(in)
	, m_output(out)
{
}

CBody::CBody(const std::string& type, std::istream& in, std::ostream& out)
	: m_type(type)
	, m_input(in)
	, m_output(out)
	, m_density(0)
{
}

double CBody::GetDensity()const
{
	return m_density;
}

double CBody::GetMass()const
{
	if (m_type == "Compound")
	{
		return 0.0;
	}
	return GetVolume() * GetDensity();
}

double CBody::GetMassInWater()const
{
	return GetVolume() * (GetDensity() - 1000) * 10.0;
}

std::string CBody::ToString()const
{
	std::ostringstream strm;
	strm << m_type << ":" << std::endl << std::setprecision(10)
		<< "\tdensity = " << GetDensity() << std::endl
		<< "\tvolume = " << GetVolume() << std::endl
		<< "\tmass = " << GetMass() << std::endl
		<< "\tmass in water = " << GetMassInWater() << std::endl;
	AppendProperties(strm);
	return strm.str();
}

void CBody::ReadProperties()
{
	if (m_type != "Compound")
	{
		while (true) {
			m_output << "Enter the density" << std::endl;
			if (!(m_input >> m_density))
			{
				m_output << "Please enter a positive number for the density." << std::endl;
			}
			else if (m_density > 0) {
				break;
			}
			else{
				m_output << "Please enter a positive number for the density." << std::endl;
			}
		}
		AddProperties();
	}
	else
	{
		AddProperties();
	}
	return;
}