#pragma once
#include "Body.h"

class CParallelepiped final : public CBody
{
public:
	CParallelepiped(std::istream& in, std::ostream& out, double density, double width, double height, double depth);
	CParallelepiped(std::istream& in, std::ostream& out);

	double GetWidth() const;
	double GetHeight() const;
	double GetDepth() const;
	double GetVolume() const override;

private:
	void AppendProperties(std::ostream& strm) const override;
	void AddProperties() override;
	double m_width;
	double m_height;
	double m_depth;
};