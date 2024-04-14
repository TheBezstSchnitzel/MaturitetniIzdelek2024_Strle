#include "stdafx.h"
#include "PotatoSeed.h"

PotatoSeed::PotatoSeed(sf::Texture* icon, int durability) :
	Tool(1, 100, durability, "ITEM_TOOL_POTATOSEED") {
	this->invIcon = icon;
}

PotatoSeed::~PotatoSeed(){
}

sf::Texture* PotatoSeed::getTexture(){
	return this->invIcon;
}

void PotatoSeed::saveToFile(std::string savePath){
	std::ofstream saveOFile(savePath);
	if (saveOFile.is_open()) {
		//shranjevanje
		saveOFile << this->getDurability() << std::endl;

		saveOFile.close();
	}
	else {
		throw("ERROR::PotatoSeed::saveToFile::FILE_NOT_OPEN");
	}
}

void PotatoSeed::loadFromSave(std::string savePath){
	std::ifstream saveIFile(savePath);
	if (saveIFile.is_open()) {
		//shranjevanje
		int dur;
		saveIFile >> dur;
		this->setDurability(dur);

		saveIFile.close();
	}
	else {
		throw("ERROR::PotatoSeed::saveToFile::FILE_NOT_OPEN");
	}
}
