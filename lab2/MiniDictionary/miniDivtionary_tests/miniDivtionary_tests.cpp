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
			std::map<std::string, std::string> dictionary
			{
				{"dog", "собака"},
				{ "cat",  "кот, кошка" },
				{ "car",  "машина" },
				{ "ball",  "мяч" },
				{ "meat",  "мясо" }
			};
			std::map<std::string, std::string> readDictionary = ParseDictionary("notEmptyDictionary.txt");
			CHECK(dictionary == readDictionary);
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

SCENARIO("Low case word")
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	WHEN("We enter \"DOG\"")
	{
		THEN("We get \"dog\"")
		{
			std::string upCaseWord = "DOG";
			std::string lowCaseWord = ToLower(upCaseWord);
			CHECK(lowCaseWord == "dog");
		}
	}
}

SCENARIO("Translate word")
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	WHEN("We enter \"dog\"")
	{
		THEN("We get translation \"собака\"")
		{
			std::string data = "dog";
			bool isChanged = false;
			std::map<std::string, std::string> dictionary = ParseDictionary("dictionary.txt");
			std::string translateWord = TranslateWord(data, dictionary, isChanged);

			CHECK(translateWord == "собака");
		}
	}
	WHEN("We enter phrase \"The Red Square\"")
	{
		THEN("We get translation \"Красная Площадь\"")
		{
			std::string data = "The Red Square";
			bool isChanged = false;
			std::map<std::string, std::string> dictionary = ParseDictionary("dictionary.txt");
			std::string translateWord = TranslateWord(data, dictionary, isChanged);

			CHECK(translateWord == "Красная Площадь");
		}
	}
}