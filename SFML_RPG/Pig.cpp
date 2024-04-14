#include "stdafx.h"
#include "Pig.h"

Pig::Pig(sf::Texture* texture, int amount) :
	Item(0, "ITEM_ANIMALS_PIG") {
	this->invIcon = texture;
	this->amount = amount;
	this->maxAmount = 8;
}

Pig::~Pig(){
}

sf::Texture* Pig::getTexture(){
	return this->invIcon;
}

int Pig::addAmount(int amount){
	if (this->amount == this->maxAmount) {
		return amount;
	}
	else {
		if (this->amount + amount > this->maxAmount) {
			int off = this->amount + amount - this->maxAmount;
			this->amount = this->maxAmount;
			return off;
		}
		else {
			this->amount += amount;
			return 0;
		}
	}
}

int Pig::removeAmount(int amount){
	if (this->amount > amount) {
		this->amount -= amount;
		return 0;
	}
	else {
		int off = amount - this->amount;
		this->amount = 0;
		return off;
	}
}

int Pig::getAmount(){
	return this->amount;
}

void Pig::setAmount(int n){
	if (this->maxAmount > n) {
		this->amount = n;
	}
}

void Pig::saveToFile(std::string savePath){
	std::ofstream saveOFile(savePath);
	saveOFile << this->amount << std::endl;
	saveOFile.close();
}

void Pig::loadFromSave(std::string savePath){
	std::ifstream saveIFile(savePath);
	saveIFile >> this->amount;
	saveIFile.close();
}
