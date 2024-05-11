#pragma once
#include "Body.h"

class CCylinder final : public CBody
{
public:
	CCylinder(std::istream& in, std::ostream& out, double density, double baseRadius, double height);
	CCylinder(std::istream& in, std::ostream& out);

	double GetBaseRadius() const;
	double GetHeight() const;
	double GetVolume() const override;

private:
	void AppendProperties(std::ostream& strm) const override;
	void AddProperties() override;
	double m_baseRadius;
	double m_height;
};