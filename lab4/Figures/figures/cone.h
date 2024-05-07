#pragma once
#include "Body.h"

class CCone final : public CBody
{
public:
	CCone(double density, double baseRadius, double height);

	double GetBaseRadius() const;
	double GetHeight() const;
	double GetVolume() const override;

private:
	void AppendProperties(std::ostream& strm) const override;
	void AddProperties(std::istream& in, std::ostream& out) override;
	double m_baseRadius;
	double m_height;
};