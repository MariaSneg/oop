#include "Body.h"
#include <sstream>
#include <iomanip>

CBody::CBody(const std::string& type, double density)
	: m_density(density)
	, m_type(type)
{
}

double CBody::GetDensity()const
{
	return m_density;
}

double CBody::GetMass()const
{
	return GetVolume() * GetDensity();
}

std::string CBody::ToString()const
{
	std::ostringstream strm;
	strm << m_type << ":" << std::endl << std::setprecision(10)
		<< "\tdensity = " << GetDensity() << std::endl
		<< "\tvolume = " << GetVolume() << std::endl
		<< "\tmass = " << GetMass() << std::endl;
	AppendProperties(strm);
	return strm.str();
}

void CBody::ReadProperties(std::istream& in, std::ostream& out)
{
	out << "Enter the density" << std::endl;
	in >> m_density;
	AddProperties(in, out);
	return;
}