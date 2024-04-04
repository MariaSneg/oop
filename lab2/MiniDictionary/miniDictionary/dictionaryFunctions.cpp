#pragma once
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <optional>
#include "dictionaryFunctions.h"

std::optional<std::string> ParseArgs(int argc, char* argv[])
{
	if (argc != 2)
	{
		throw std::runtime_error("Invalid arguments count\n Usage: findtext.exe <file name> \"text to search\"\n");
	}
	std::string inputFileName = argv[1];
	return inputFileName;
}

std::string ToLower(std::string const& str)
{
	std::string lowerStr;
	for (char ch : str)
	{
		lowerStr += std::tolower(ch);
	}
	return lowerStr;
}

std::map<std::string, std::string> ParseDictionary(std::string const& fileName)
{
	std::ifstream input(fileName);

	std::map<std::string, std::string> dictionary;

	if (!input)
	{
		return dictionary;
	}
	if (!input.is_open())
	{
		throw std::runtime_error("Failed to open dictionary.txt for reading\n");
	}
	
	std::string data;
	while (getline(input, data))
	{
		auto searchWordIdx = data.find(":");
		std::string searchWord = data.substr(0, searchWordIdx);
		std::string translateWord = data.substr(searchWordIdx + 1);
		dictionary.emplace(searchWord, translateWord);
	}

	input.close();
	return dictionary;
}

void AddNewWord(std::string const& word, std::map<std::string, std::string>& dictionary, bool& isChanged)
{
	std::string translate;
	std::cout << "Неизвестное слово \"" + word + "\". Введите перевод или пустую строку для игнорирования" << std::endl;
	std::cin.ignore();
	getline(std::cin, translate);

	std::cout << translate;

	if (!translate.empty())
	{
		dictionary.emplace(word, translate);
		std::cout << "Слово \"" + word + "\" добавлено в словарь" << std::endl;
		isChanged = true;
	}
	else
	{
		std::cout << "Слово проигнорировано" << std::endl;
	}
}

std::string TranslateWord(std::string& word, std::map<std::string, std::string>& dictionary, bool& isChanged)
{
	word = ToLower(word);
	if (dictionary.count(word))
	{
		return dictionary[word];
	}
	else
	{
		AddNewWord(word, dictionary, isChanged);
		return "";
	}
}

void SaveChanges(std::map<std::string, std::string>& dictionary, std::string const& fileName)
{
	std::ofstream output("d.txt");

	if (!output.is_open())
	{
		throw std::runtime_error("Failed to open dictionary.txt for reading\n");
	}

	for (const auto& translate : dictionary)
	{
		output << translate.first << ":" << translate.second << std::endl;
	}

	output.close();

	std::cout << "Сохранения сохранены" << std::endl;
}
