#pragma once
#include <iostream>
#include <fstream>
#include <functional>
#include <map>

class CIdentifier;

class CVar
{
public:
	CVar(float value);
	bool GetVar(std::istream& args) const;
	bool Setvar(std::istream& args) const;
private:
	//using Handler = std::function<bool(std::istream& args)>;

	//using ActionMap = std::map<std::string, Handler>;
	float value;
};