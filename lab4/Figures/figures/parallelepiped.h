#pragma once
#include "Body.h"

class CParallelepiped final : public CBody
{
public:
	CParallelepiped(double density, double width, double height, double depth);

	double GetWidth() const;
	double GetHeight() const;
	double GetDepth() const;
	double GetVolume() const override;

private:
	void AppendProperties(std::ostream& strm) const override;
	void AddProperties(std::istream& in, std::ostream& out) override;
	double m_width;
	double m_height;
	double m_depth;
};