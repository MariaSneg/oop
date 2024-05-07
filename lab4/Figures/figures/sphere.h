#pragma once
#include "Body.h"

class CSphere final : public CBody
{
public:
	CSphere(double density, double radius);

	double GetRadius() const;
	double GetVolume() const override;

private:
	void AppendProperties(std::ostream& strm) const override;
	void AddProperties(std::istream& in, std::ostream& out) override;
	double m_radius;
};