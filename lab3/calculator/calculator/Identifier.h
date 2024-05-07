#pragma once
#include <iostream>
#include <fstream>
#include <functional>
#include <map>

class CFunction;
class CVar;

class CIdentifier
{
public:
	CIdentifier(CVar& var, CFunction& func, std::istream& input, std::ostream& output);
	bool GetIFunc(std::istream& args) const;
	bool GetIVar(std::istream& args) const;
	bool SetIFunc(std::istream& args) const;
	bool SetIvar(std::istream& args) const;
private:
	//using Handler = std::function<bool(std::istream& args)>;

	//using ActionMap = std::map<std::string, Handler>;

	CVar& m_var;
	CFunction& m_func;
	std::istream& m_input;
	std::ostream& m_output;
};