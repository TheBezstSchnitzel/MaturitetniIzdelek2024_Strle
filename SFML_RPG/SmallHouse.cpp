#include "stdafx.h"
#include "SmallHouse.h"

void SmallHouse::initHitbox(){
	sf::RectangleShape* hitbox = this->getHitbox();
	sf::Vector2f temp = this->getPos();
	temp.y += 58.f;
	hitbox->setPosition(temp);
	hitbox->setSize(sf::Vector2f(62.f, 22.f));
	hitbox->setFillColor(sf::Color::Transparent);
	//debug
	//hitbox->setOutlineThickness(1.f); 
	//hitbox->setOutlineColor(sf::Color::Red);
}

void SmallHouse::initTextureRect(){
	this->textureRect.width = 64;
	this->textureRect.height = 80;
	this->textureRect.left = 0;
	this->textureRect.top = 0;
	this->deafultLeft = 0;
	this->deafultTop = 0;
}

void SmallHouse::initInteractZone(){
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

void SmallHouse::updateTextureRect(int season, bool day, Player* player){
	if (day) {
		this->textureRect.top = this->deafultTop;
	}
	else {
		this->textureRect.top = this->textureRect.height + this->deafultTop;
	}
	switch (season) {
	case 1:
		this->textureRect.left = this->deafultLeft;
		break;
	case 2:
		this->textureRect.left = this->textureRect.width + this->deafultLeft;
		break;
	case 3:
		this->textureRect.left = this->textureRect.width * 2 + this->deafultLeft;
		break;
	case 4:
		this->textureRect.left = this->textureRect.width * 3 + this->deafultLeft;
		break;
	}
	if (this->isAvailable && this->isInteractable(player)) {
		this->textureRect.left = this->textureRect.width * 4;
	}
	if (this->checkIfPlayerBehind(player)) {
		this->renderRect.setFillColor(sf::Color(255, 255, 255, 150));
	}
	else {
		this->renderRect.setFillColor(sf::Color(255, 255, 255, 255));
	}
	this->renderRect.setTextureRect(this->textureRect);
}

SmallHouse::SmallHouse(sf::Vector2f pos) :
	Building(pos, sf::Vector2f(64.f, 80.f), "SmallHouse", sf::RectangleShape(), true){
	this->initHitbox();
	this->initTextureRect();
	this->initInteractZone();
}

SmallHouse::~SmallHouse(){

}

void SmallHouse::update(int season, bool day, Player* player){
	if (day)this->isAvailable = false; //tu se razlikuje pr usakmu buildingu
	else this->isAvailable = true;
	this->updateTextureRect(season, day, player);
}

void SmallHouse::render(sf::RenderTarget* target){
	Structure::render(target);
}

void SmallHouse::saveToFile(std::string file){
	std::ofstream saveOFile(file);
	sf::Vector2f tempPos = this->getPos();
	saveOFile << tempPos.x << "  " << tempPos.y << std::endl;
	saveOFile.close();
}

void SmallHouse::loadFromFile(std::string file){
	std::ifstream saveIFile(file);
	float x;
	float y;
	saveIFile >> x >> y;
	this->setPos(sf::Vector2f(x, y));
	saveIFile.close();
	this->initHitbox();
	this->initInteractZone();
}
