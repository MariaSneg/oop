#pragma once
#include <string>
class CBody
{
public:
	CBody(const std::string& type, double density);

	double GetDensity() const;
	virtual double GetVolume() const = 0;
	double GetMass() const;
	std::string ToString() const;
	void ReadProperties(std::istream& in, std::ostream& out);
	
	virtual ~CBody() = default;

private:
	virtual void AppendProperties(std::ostream& strm) const = 0;
	virtual void AddProperties(std::istream& in, std::ostream& out) = 0;
	double m_density;
	std::string m_type;
};