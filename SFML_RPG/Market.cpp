#include "stdafx.h"
#include "Market.h"

void Market::initHitbox(){
	sf::RectangleShape* hitbox = this->getHitbox();
	sf::Vector2f temp = this->getPos();
	temp.y += 47.f;
	hitbox->setPosition(temp);
	hitbox->setSize(sf::Vector2f(94.f, 29.f));
	hitbox->setFillColor(sf::Color::Transparent);
	//debug
	//hitbox->setOutlineThickness(1.f);
	//hitbox->setOutlineColor(sf::Color::Red);
}

void Market::initTextureRect(){
	this->textureRect.width = 96;
	this->textureRect.height = 80;
	this->textureRect.left = 0;
	this->textureRect.top = 240;
	this->deafultLeft = 0;
	this->deafultTop = 240;
}

void Market::initInteractZone(){
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

void Market::updateTextureRect(int season, bool day, Player* player){
	sf::RectangleShape* hitbox = this->getHitbox();
	sf::Vector2f size = hitbox->getSize();
	if (day) {
		this->textureRect.top = this->deafultTop;
	}
	else {
		this->textureRect.top = this->textureRect.height + this->deafultTop;
	}
	switch (season) {
	case 1:
		this->textureRect.left = this->deafultLeft;
		size.x = 91.f;
		break;
	case 2:
		this->textureRect.left = this->textureRect.width + this->deafultLeft;
		size.x = 91.f;
		break;
	case 3:
		this->textureRect.left = this->textureRect.width * 2 + this->deafultLeft;
		size.x = 91.f;
		break;
	case 4:
		this->textureRect.left = this->textureRect.width * 3 + this->deafultLeft;
		size.x = 94.f;
		break;
	}
	if (this->isAvailable && this->isInteractable(player)) {
		this->textureRect.left = this->textureRect.width * 4;
	}
	hitbox->setSize(size);
	if (this->checkIfPlayerBehind(player)) {
		this->renderRect.setFillColor(sf::Color(255, 255, 255, 150));
	}
	else {
		this->renderRect.setFillColor(sf::Color(255, 255, 255, 255));
	}
	this->renderRect.setTextureRect(this->textureRect);
}

Market::Market(sf::Vector2f pos) :
	Building(pos,sf::Vector2f(94.f,76.f),"Market",sf::RectangleShape(),true) {
	this->initHitbox();
	this->initTextureRect();
	this->initInteractZone();
}

Market::~Market(){

}

void Market::update(int season, bool day, Player* player){
	if (day)this->isAvailable = true; //tu se razlikuje pr usakmu buildingu
	else this->isAvailable = false; 
	this->updateTextureRect(season, day, player);
}

void Market::render(sf::RenderTarget* target, sf::Shader* shader, const sf::Vector2f light_position) {
	Structure::render(target,shader,light_position);
}

void Market::saveToFile(std::string file){
	//ne rabm kr je zmer na istmu mestu in se nc ne spreminja more bit pa deklerirana zarad abstraktou
}

void Market::loadFromFile(std::string file){
	//ne rabm kr je zmer na istmu mestu in se nc ne spreminja more bit pa deklerirana zarad abstraktou
}
