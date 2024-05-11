#pragma once
#include "Body.h"

class CSphere final : public CBody
{
public:
	CSphere(std::istream& in, std::ostream& out, double density, double radius);
	CSphere(std::istream& in, std::ostream& out);

	double GetRadius() const;
	double GetVolume() const override;

private:
	void AppendProperties(std::ostream& strm) const override;
	void AddProperties() override;
	double m_radius;
};