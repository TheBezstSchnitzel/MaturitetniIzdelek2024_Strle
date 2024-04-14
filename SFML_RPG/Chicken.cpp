#include "stdafx.h"
#include "Chicken.h"

Chicken::Chicken(sf::Texture* texture, int amount) :
	Item(0, "ITEM_ANIMALS_CHICKEN") {
	this->invIcon = texture;
	this->amount = amount;
	this->maxAmount = 9;
}

Chicken::~Chicken(){
}

sf::Texture* Chicken::getTexture(){
	return this->invIcon;
}

int Chicken::addAmount(int amount){
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

int Chicken::removeAmount(int amount){
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

int Chicken::getAmount(){
	return this->amount;
}

void Chicken::setAmount(int n){
	if (this->maxAmount > n) {
		this->amount = n;
	}
}

void Chicken::saveToFile(std::string savePath){
	std::ofstream saveOFile(savePath);
	saveOFile << this->amount << std::endl;
	saveOFile.close();
}

void Chicken::loadFromSave(std::string savePath){
	std::ifstream saveIFile(savePath);
	saveIFile >> this->amount;
	saveIFile.close();
}
