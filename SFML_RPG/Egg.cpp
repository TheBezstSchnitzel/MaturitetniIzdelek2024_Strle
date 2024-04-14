#include "stdafx.h"
#include "Egg.h"

void Egg::initValue(){
	this->value = this->amount * 5;
}

Egg::Egg(sf::Texture* texture, int amount) :
	Item(0, "ITEM_EGG") {
	this->invIcon = texture;
	this->amount = amount;
	this->maxAmount = 12;
	this->initValue();
}

Egg::~Egg(){
}

sf::Texture* Egg::getTexture(){
	return this->invIcon;
}

int Egg::addAmount(int amount){
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

int Egg::removeAmount(int amount){
	if (this->amount > amount) {
		this->amount -= amount;
		this->initValue();
		return 0;
	}
	else {
		int off = amount - this->amount;
		this->amount = 0;
		this->value = 0;
		std::cout << off << std::endl;
		return off;
	}
}

int Egg::getAmount(){
	return this->amount;
}

void Egg::saveToFile(std::string savePath){
	std::ofstream saveOFile(savePath);
	saveOFile << this->amount << std::endl;
	saveOFile.close();
}

void Egg::loadFromSave(std::string savePath){
	std::ifstream saveIFile(savePath);
	saveIFile >> this->amount;
	saveIFile.close();

	this->initValue();
}
