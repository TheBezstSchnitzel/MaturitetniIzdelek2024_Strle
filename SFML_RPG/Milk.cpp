#include "stdafx.h"
#include "Milk.h"

void Milk::initValue(){
	this->value = this->amount * 4;
}

Milk::Milk(sf::Texture* texture, int amount) :
	Item(0, "ITEM_MILK") {
	this->invIcon = texture;
	this->amount = amount;
	this->maxAmount = 6;
	this->initValue();
}

Milk::~Milk(){
}

sf::Texture* Milk::getTexture(){
	return this->invIcon;
}

int Milk::addAmount(int amount){
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

int Milk::removeAmount(int amount){
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

int Milk::getAmount(){
	return this->amount;
}

void Milk::saveToFile(std::string savePath){
	std::ofstream saveOFile(savePath);
	saveOFile << this->amount << std::endl;
	saveOFile.close();
}

void Milk::loadFromSave(std::string savePath){
	std::ifstream saveIFile(savePath);
	saveIFile >> this->amount;
	saveIFile.close();

	this->initValue();
}
