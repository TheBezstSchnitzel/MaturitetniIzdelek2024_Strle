#include "stdafx.h"
#include "Cow.h"

Cow::Cow(sf::Texture* texture, int amount) :
	Item(0,"ITEM_ANIMALS_COW") {
	this->invIcon = texture;
	this->amount = amount;
	this->maxAmount = 6;
}

Cow::~Cow(){
}

sf::Texture* Cow::getTexture(){
	return this->invIcon;
}

int Cow::addAmount(int amount){
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

int Cow::removeAmount(int amount){
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

int Cow::getAmount(){
	return this->amount;
}

void Cow::setAmount(int n){
	if (this->maxAmount > n) {
		this->amount = n;
	}
}

void Cow::saveToFile(std::string savePath){
	std::ofstream saveOFile(savePath);
	saveOFile << this->amount << std::endl;
	saveOFile.close();
}

void Cow::loadFromSave(std::string savePath){
	std::ifstream saveIFile(savePath);
	saveIFile >> this->amount;
	saveIFile.close();
}
