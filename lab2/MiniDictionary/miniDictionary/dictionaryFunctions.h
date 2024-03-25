#pragma once
#include <iostream>
#include <map>
#include <string>

std::string ToLower(std::string const& str);

std::map<std::string, std::string> ParseDictionary(std::string const& fileName);

void AddNewWord(std::string const& word, std::map<std::string, std::string>& dictionary, bool& isChanged);

std::string TranslateWord(std::string const& word, std::map<std::string, std::string>& dictionary, bool& isChanged);

void SaveChanges(std::map<std::string, std::string>& dictionary, std::string const& fileName);