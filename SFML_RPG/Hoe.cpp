#include "stdafx.h"
#include "Hoe.h"


Hoe::Hoe(sf::Texture* icon, int durability) : Tool(1,120,durability,"ITEM_TOOL_HOE") {
	this->invIcon = icon;
} 

Hoe::~Hoe(){
}

sf::Texture* Hoe::getTexture(){
	return this->invIcon;
}

void Hoe::saveToFile(std::string savePath){
	std::ofstream saveOFile(savePath);
	if (saveOFile.is_open()) {
		//shranjevanje
		saveOFile << this->getDurability() << std::endl;

		saveOFile.close();
	}
	else {
		throw("ERROR::Hoe::saveToFile::FILE_NOT_OPEN");
	}
}

void Hoe::loadFromSave(std::string savePath){
	std::ifstream saveIFile(savePath);
	if (saveIFile.is_open()) {
		//shranjevanje
		int dur;
		saveIFile >> dur;
		this->setDurability(dur);

		saveIFile.close();
	}
	else {
		throw("ERROR::Hoe::saveToFile::FILE_NOT_OPEN");
	}
}

