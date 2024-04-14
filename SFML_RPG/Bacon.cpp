#include "stdafx.h"
#include "Bacon.h"

void Bacon::initValue(){
	this->value = this->amount * 6;
}

Bacon::Bacon(sf::Texture* texture, int amount) :
	Item(0, "ITEM_BACON") {
	this->invIcon = texture;
	this->amount = amount;
	this->maxAmount = 9;
	this->initValue();
}

Bacon::~Bacon(){
}

sf::Texture* Bacon::getTexture(){
	return this->invIcon;
}

int Bacon::addAmount(int amount){
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

int Bacon::removeAmount(int amount){
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

int Bacon::getAmount(){
	return this->amount;
}

void Bacon::saveToFile(std::string savePath){
	std::ofstream saveOFile(savePath);
	saveOFile << this->amount << std::endl;
	saveOFile.close();
}

void Bacon::loadFromSave(std::string savePath){
	std::ifstream saveIFile(savePath);
	saveIFile >> this->amount;
	saveIFile.close();

	this->initValue();
}
