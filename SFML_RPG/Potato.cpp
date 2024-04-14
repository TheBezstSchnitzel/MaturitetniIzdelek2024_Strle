#include "stdafx.h"
#include "Potato.h"

void Potato::initValue(){
	this->value = this->amount * 4;
}

Potato::Potato(sf::Texture* texture, int amount) :
	Item(0, "ITEM_VEGISE_POTATO") {
	this->invIcon = texture;
	this->amount = amount;
	this->maxAmount = 60;
	this->initValue();
}

Potato::~Potato(){

}

sf::Texture* Potato::getTexture(){
	return this->invIcon;
}

int Potato::addAmount(int amount){
	if (this->amount == this->maxAmount) {
		return amount;
	}
	else {
		if (this->amount + amount > this->maxAmount) {
			int off = this->amount + amount - this->maxAmount;
			this->amount = this->maxAmount;
			this->initValue();
			return off;
		}
		else {
			this->amount += amount;
			this->initValue();
			return 0;
		}
	}
}

int Potato::removeAmount(int amount){
	if (this->amount > amount) {
		this->amount -= amount;
		this->initValue();
		return 0;
	}
	else {
		int off = amount - this->amount;
		this->amount = 0;
		this->value = 0;
		return off;
	}
}

int Potato::getAmount(){
	return this->amount;
}

void Potato::saveToFile(std::string savePath){
	std::ofstream saveOFile(savePath);
	saveOFile << this->amount << std::endl;
	saveOFile.close();
}

void Potato::loadFromSave(std::string savePath){
	std::ifstream saveIFile(savePath);
	saveIFile >> this->amount;
	saveIFile.close();

	this->initValue();
}
