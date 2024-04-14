#include "stdafx.h"
#include "Tool.h"

Tool::Tool(short unsigned type, int maxDurability, int durability, std::string id) : 
	Item(type,id) {
	this->maxDurability = maxDurability;
	this->durabiltity = durability;
}

Tool::~Tool(){
}

void Tool::damageDurability(int damage){
	if (this->durabiltity - damage <= 0) {
		this->durabiltity = 0;
	}
	else {
		this->durabiltity -= damage;
	}
}

void Tool::healDurability(int heal){
	if (this->durabiltity + heal > this->maxDurability) {
		this->durabiltity = this->maxDurability;
	}
	else {
		this->durabiltity += heal;
	}
}

void Tool::setDurability(int durability){
	this->durabiltity = durability;
}

int Tool::getDurability(){
	return this->durabiltity;
}
