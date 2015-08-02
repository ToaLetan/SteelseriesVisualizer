#include "MouseManager.h"
#include <iostream>
#include <fstream>

MouseManager::MouseManager()
{
	//Populate mouse data
	/*
	Json::Value fromScratch;
	Json::Value array;
	array.append("game: ");
	array.append("event: ");
	fromScratch["game: "] = "MY_GAME";
	fromScratch["number"] = 2;
	fromScratch["array"] = array;
	fromScratch["object"]["game: "] = "world";
	*/

	//OutputDataTest(fromScratch);

	Json::Value root;   // will contain the root value after parsing.
    Json::CharReaderBuilder builder;
    std::ifstream test("%ProgramData%\SteelSeries\SteelSeries Engine 3\coreProps.json", std::ifstream::binary);
    std::string errors;

    bool didCompile = Json::parseFromStream(builder, test, &root, &errors);

    if ( !didCompile )
    {
        // report to the user the failure and their locations in the document.
        std::cout  << errors << "\n";
    }

    std::string encoding = root.get("encoding", "UTF-8" ).asString();
    std::cout << encoding << "\n";

	SetMouseValues(100);
}

MouseManager::~MouseManager()
{

}

void MouseManager::OutputDataTest(const Json::Value & value)
{
	std::cout << value["game: "];
    std::cout << value["number"];
    std::cout << value["array"][0] << value["array"][1];
    std::cout << value["object"]["game: "];
}

void MouseManager::SetMouseValues(int value)
{
	Json::Value array;
	Json::Value values;

	array.append("game: ");
	array.append("event: ");
	array.append("data: ");

	values["game: "] = "GAME";
	values["event: "] ="HEALTH";
	values["data: "] = value;
	values["array"] = array;
	//values["object"]["game: "] = "world";

	//Write to the JSON file CURRENTLY WRITES TO NOTHING
	Json::StyledWriter styledWriter;
	//std::cout << styledWriter.write(values);

	Json::FastWriter fastWriter;
	std::string jsonMessage = fastWriter.write(values);

	Json::Value parsedFromString;
	Json::Reader reader;

	bool parsingSuccessful = reader.parse(jsonMessage, parsedFromString);
	if (parsingSuccessful)
	{
		std::ifstream test("%ProgramData%\SteelSeries\SteelSeries Engine 3\coreProps.json/game_event", std::ifstream::binary);

		test>>styledWriter.write(parsedFromString);
	}
}