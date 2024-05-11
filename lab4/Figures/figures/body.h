#pragma once
#include <string>
class CBody
{
public:
	CBody(const std::string& type, double density, std::istream& in, std::ostream& out);
	CBody(const std::string& type, std::istream& in, std::ostream& out);

	virtual double GetDensity() const;
	virtual double GetVolume() const = 0;
	double GetMass() const;
	double GetMassInWater() const;
	std::string ToString() const;
	void ReadProperties();
	virtual ~CBody() = default;

private:
	virtual void AppendProperties(std::ostream& strm) const = 0;
	virtual void AddProperties() = 0;
	std::string m_type;
	double m_density;
protected:
	std::istream& m_input;
	std::ostream& m_output;
};