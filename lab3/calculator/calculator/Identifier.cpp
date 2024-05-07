#include "Identifier.h"

CIdentifier::CIdentifier(CVar& var, CFunction& func, std::istream& input, std::ostream& output)
	: m_var(var)
	, m_func(func)
	, m_input(input)
	, m_output(output)
{
}

