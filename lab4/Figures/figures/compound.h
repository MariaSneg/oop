#pragma once
#include "Body.h"
#include <vector>
#include <memory>

class CCompound final : public CBody
{
public:
	CCompound(std::istream& in, std::ostream& out);

	void AddChildBody(std::unique_ptr<CBody>& child);
	double GetVolume() const override;
	double GetDensity() const override;

private:
	void AppendProperties(std::ostream& strm) const override;
	void AddProperties() override;
	std::vector<std::unique_ptr<CBody>> m_bodies;
};