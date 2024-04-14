#include "stdafx.h"
#include "MediumHouse.h"

void MediumHouse::initHitbox(){
	sf::RectangleShape* hitbox = this->getHitbox();
	sf::Vector2f temp = this->getPos();
	temp.y += 58.f;
	hitbox->setPosition(temp);
	hitbox->setSize(sf::Vector2f(70.f, 24.f));
	hitbox->setFillColor(sf::Color::Transparent);
	//debug
	//hitbox->setOutlineThickness(1.f); 
	//hitbox->setOutlineColor(sf::Color::Red);
}

void MediumHouse::initTextureRect(){
	this->textureRect.width = 80;
	this->textureRect.height = 79;
	this->textureRect.left = 0;
	this->textureRect.top = 401;
	this->deafultLeft = 0;
	this->deafultTop = 401;
}

void MediumHouse::initInteractZone(){
	this->interactZone = sf::RectangleShape(*this->getHitbox());
	sf::Vector2f size = this->interactZone.getSize();
	sf::Vector2f pos = this->interactZone.getPosition();
	size.x += 20.f;
	size.y += 20.f;
	pos.x -= 10.f;
	pos.y -= 10.f;
	this->interactZone.setSize(size);
	this->interactZone.setPosition(pos);
	//DEBUG
	//this->interactZone.setOutlineColor(sf::Color::Red);
	//this->interactZone.setOutlineThickness(1.f);
}

void MediumHouse::updateTextureRect(int season, bool day, Player* player){
	switch (season) {
	case 1:
		if (day)this->textureRect.left = this->deafultLeft;
		else this->textureRect.left = this->deafultLeft + this->textureRect.width * 4;
		break;
	case 2:
		if (day)this->textureRect.left = this->deafultLeft + this->textureRect.width;
		else this->textureRect.left = this->deafultLeft + this->textureRect.width * 4 + this->textureRect.width ;
		break;
	case 3:
		if (day)this->textureRect.left = this->deafultLeft + this->textureRect.width * 2;
		else this->textureRect.left = this->deafultLeft + this->textureRect.width * 4 + this->textureRect.width * 2;
		break;
	case 4:
		if (day)this->textureRect.left = this->deafultLeft + this->textureRect.width * 3;
		else this->textureRect.left = this->deafultLeft + this->textureRect.width * 4 + this->textureRect.width * 3;
		break;
	}
	if (this->isAvailable && this->isInteractable(player)) {
		this->textureRect.left += this->textureRect.width * 4;
	}
	if (this->checkIfPlayerBehind(player)) {
		this->renderRect.setFillColor(sf::Color(255, 255, 255, 150));
	}
	else {
		this->renderRect.setFillColor(sf::Color(255, 255, 255, 255));
	}
	this->renderRect.setTextureRect(this->textureRect);
}

MediumHouse::MediumHouse(sf::Vector2f pos) : 
	Building(pos, sf::Vector2f(80.f, 79.f), "MediumHouse", sf::RectangleShape(), true){
	this->initHitbox();
	this->initTextureRect();
	this->initInteractZone();
}

MediumHouse::~MediumHouse(){

}

void MediumHouse::update(int season, bool day, Player* player){
	if (day)this->isAvailable = false; //tu se razlikuje pr usakmu buildingu
	else this->isAvailable = true;
	this->updateTextureRect(season, day, player);
}

void MediumHouse::render(sf::RenderTarget* target){
	Structure::render(target);
	//target->draw(*this->getHitbox());
	//target->draw(this->interactZone);
}

void MediumHouse::saveToFile(std::string file){
	std::ofstream saveOFile(file);
	sf::Vector2f tempPos = this->getPos();
	saveOFile << tempPos.x << "  " << tempPos.y << std::endl;
	saveOFile.close();
}

void MediumHouse::loadFromFile(std::string file){
	std::ifstream saveIFile(file);
	float x;
	float y;
	saveIFile >> x >> y;
	this->setPos(sf::Vector2f(x, y));
	saveIFile.close();
	this->initHitbox();
	this->initInteractZone();
}
