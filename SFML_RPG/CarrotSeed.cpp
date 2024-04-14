#include "stdafx.h"
#include "CarrotSeed.h"

CarrotSeed::CarrotSeed(sf::Texture* icon, int durability) :
	Tool(1,100,durability, "ITEM_TOOL_CARROTSEED"){
	this->invIcon = icon;
}

CarrotSeed::~CarrotSeed(){

}

sf::Texture* CarrotSeed::getTexture(){
	return this->invIcon;
}

void CarrotSeed::saveToFile(std::string savePath){
	std::ofstream saveOFile(savePath);
	if (saveOFile.is_open()) {
		//shranjevanje
		saveOFile << this->getDurability() << std::endl;

		saveOFile.close();
	}
	else {
		throw("ERROR::CarrotSeed::saveToFile::FILE_NOT_OPEN");
	}
}

void CarrotSeed::loadFromSave(std::string savePath){
	std::ifstream saveIFile(savePath);
	if (saveIFile.is_open()) {
		//shranjevanje
		int dur;
		saveIFile >> dur;
		this->setDurability(dur);

		saveIFile.close();
	}
	else {
		throw("ERROR::CarrotSeed::saveToFile::FILE_NOT_OPEN");
	}
}
