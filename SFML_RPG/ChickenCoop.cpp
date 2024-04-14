#include "stdafx.h"
#include "ChickenCoop.h"

void ChickenCoop::initVariables(){
	this->hasEgg = false;
	this->chickens = 7;
	this->eggTimerMax = 0; //odvisen od kolicine kokoši
	this->eggTimer.restart();
}

void ChickenCoop::initHitbox(){
	sf::RectangleShape* hitbox = this->getHitbox();
	sf::Vector2f temp = this->getPos();
	temp.y += 40.f;
	temp.x += 3.f;
	hitbox->setPosition(temp);
	hitbox->setSize(sf::Vector2f(58.f, 23.f));
	hitbox->setFillColor(sf::Color::Transparent);
	//debug
	//hitbox->setOutlineThickness(1.f);
	//hitbox->setOutlineColor(sf::Color::Red);
}

void ChickenCoop::initTextureRect(){
	this->textureRect.width = 64;
	this->textureRect.height = 64;
	this->textureRect.left = 0;
	this->textureRect.top = 560;
	this->deafultLeft = 0;
	this->deafultTop = 560;
}

void ChickenCoop::initInteractZone(){
	this->interactZone = sf::RectangleShape(*this->getHitbox());
	sf::Vector2f size = this->interactZone.getSize();
	sf::Vector2f pos = this->interactZone.getPosition();
	size.x += 20.f;
	size.y += 25.f;
	pos.x -= 10.f;
	pos.y -= 12.5f;
	this->interactZone.setSize(size);
	this->interactZone.setPosition(pos);
	//DEBUG
	//this->interactZone.setOutlineColor(sf::Color::Red);
	//this->interactZone.setOutlineThickness(1.f);
}

void ChickenCoop::initAmountDisplay(){
	sf::Vector2f pos = this->renderRect.getPosition();
	pos.x += 32.f;
	pos.y += 33.f;
	this->amountDisplay.setPosition(pos);
	this->amountDisplay.setSize(sf::Vector2f(5.f, 5.f));
	this->amountDisplay.setFillColor(sf::Color(255, 255, 255, 150));
	this->amountDisplay.setOutlineThickness(0.f);
	this->amountDisplay.setOutlineColor(sf::Color::Transparent);
}

void ChickenCoop::updateTextureRect(int season, bool day, Player* player){
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
		if (this->hasEgg) {
			this->textureRect.left += this->textureRect.width * 4;
		}
	}
	if (this->checkIfPlayerBehind(player)) {
		this->renderRect.setFillColor(sf::Color(255, 255, 255, 150));
	}
	else {
		this->renderRect.setFillColor(sf::Color(255, 255, 255, 255));
	}
	this->renderRect.setTextureRect(this->textureRect);
}

void ChickenCoop::updateEggTimerMax(){
	if (this->chickens > 0)this->eggTimerMax = 25;
	else return;
	this->eggTimerMax -= this->chickens - 1 * 1;
	this->eggTimerMax *= 60; //v minute
}

void ChickenCoop::updateEgg(){
	if (this->chickens > 0 && this->eggTimerMax > 0 && !this->hasEgg) {
		if (this->eggTimer.getElapsedTime().asSeconds() >= this->eggTimerMax) {
			this->hasEgg = true;
		}
	}
}

void ChickenCoop::updateAmountDisplay(){
	sf::IntRect tmp = sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(10, 10));
	tmp.left = this->chickens * 10;
	this->amountDisplay.setTexture(this->numbers09);
	this->amountDisplay.setTextureRect(tmp);
}

ChickenCoop::ChickenCoop(sf::Vector2f pos) :
	Building(pos, sf::Vector2f(64.f, 64.f), "ChickenCoop", sf::RectangleShape(), true)  {
	this->initTextureRect();
	this->initHitbox();
	this->initInteractZone();
	this->initVariables();
	this->initAmountDisplay();
}

ChickenCoop::~ChickenCoop(){
}

void ChickenCoop::update(int season, bool day, Player* player){
	if (day)this->isAvailable = true;
	else this->isAvailable = false;
	this->updateTextureRect(season, day, player);
	this->updateEgg();
	this->updateAmountDisplay();
}

void ChickenCoop::render(sf::RenderTarget* target, sf::Shader* shader, const sf::Vector2f light_position){
	Structure::render(target, shader, light_position);
	target->draw(this->amountDisplay);
	if (shader) {
		shader->setUniform("hasTexture", true);
		shader->setUniform("lightPos", light_position);
		target->draw(this->amountDisplay, shader);
	}
	else {
		target->draw(this->amountDisplay);
	}
}

bool ChickenCoop::isFull(){
	return (this->chickens == 9);
}

int ChickenCoop::addChickens(int amount){
	if (!this->isFull()) {
		if (this->chickens + amount > 9) {
			amount -= 9 - this->chickens;
			this->chickens = 9;
			this->updateEggTimerMax();
			return amount;
		}
		else {
			this->chickens += amount;
			this->updateEggTimerMax();
			return 0;
		}
	}
	return -1;
}

bool ChickenCoop::Egg(){
	return this->hasEgg;
}

void ChickenCoop::takeEgg(){
	if (this->hasEgg) {
		this->hasEgg = false;
		this->eggTimer.restart();
	}
}

void ChickenCoop::saveToFile(std::string file){
	std::ofstream saveOFile(file);
	sf::Vector2f tempPos = this->getPos();
	saveOFile << tempPos.x << "  " << tempPos.y << std::endl;
	saveOFile << this->hasEgg << std::endl;
	saveOFile << this->chickens << std::endl;
	saveOFile.close();
}

void ChickenCoop::loadFromFile(std::string file){
	std::ifstream saveIFile(file);
	float x;
	float y;
	saveIFile >> x >> y;
	this->setPos(sf::Vector2f(x, y));
	saveIFile >> this->hasEgg;
	saveIFile >> this->chickens;
	saveIFile.close();
	this->initHitbox();
	this->initInteractZone();
	this->updateEggTimerMax();
	this->initAmountDisplay();
}
