#include <iostream>
#include <sstream>
#include <map>
#define CATCH_CONFIG_MAIN
#include "../../../catch2/catch.hpp"

#include "../miniDictionary/dictionaryFunctions.h"

SCENARIO("Read Vector")
{
	WHEN("Dictionary is empty")
	{
		THEN("Map is empty")
		{
			std::map<std::string, std::string> dictionary = ParseDictionary("empty.txt");
			CHECK(dictionary.empty());
		}
	}

	WHEN("Dictionary contains some words")
	{
		THEN("Map contains some pairs")
		{
			std::map<std::string, std::string> dictionary = ParseDictionary("notEmptyDictionary.txt");
			CHECK(dictionary.size() == 5);
		}
	}
}

SCENARIO("Save changes to dictionary")
{
	WHEN("Dictionary is changing")
	{
		THEN("File also is changing")
		{
			std::map<std::string, std::string> dictionary = ParseDictionary("changedDictionary.txt");
			dictionary.emplace("apple", "яблоко");

			SaveChanges(dictionary, "changedDictionary.txt");

			std::map<std::string, std::string> changedDictionary = ParseDictionary("changedDictionary.txt");

			CHECK(dictionary.size() == changedDictionary.size());
		}
	}
}

SCENARIO("Translate word")
{
	WHEN("We enter \"dog\"")
	{
		THEN("We get translation \"собака\"")
		{
			setlocale(LC_ALL, "Russian");
			std::string data = "dog";
			bool isChanged = false;
			std::map<std::string, std::string> dictionary = ParseDictionary("notEmptyDictionary.txt");
			std::string translateWord = TranslateWord(data, dictionary, isChanged);

			CHECK(translateWord == "собака");
		}
	}
}