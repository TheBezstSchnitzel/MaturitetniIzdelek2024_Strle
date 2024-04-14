#include "stdafx.h"
#include "PigBarn.h"

void PigBarn::initVariables(){
	this->hasBacon = false;
	this->pigs = 0;
	this->baconTimerMax = 0; //odvisen od kolicine prasicou
	this->baconTimer.restart();
}

void PigBarn::initHitbox(){
	sf::RectangleShape* hitbox = this->getHitbox();
	sf::Vector2f temp = this->getPos();
	temp.y += 35.f;
	hitbox->setPosition(temp);
	hitbox->setSize(sf::Vector2f(67.f, 45.f));
	hitbox->setFillColor(sf::Color::Transparent);
	//debug
	//hitbox->setOutlineThickness(1.f);
	//hitbox->setOutlineColor(sf::Color::Red);
}

void PigBarn::initTextureRect(){
	this->textureRect.width = 80;
	this->textureRect.height = 80;
	this->textureRect.left = 0;
	this->textureRect.top = 480;
	this->deafultLeft = 0;
	this->deafultTop = 480;
}

void PigBarn::initInteractZone(){
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

void PigBarn::initAmountDisplay(){
	sf::Vector2f pos = this->renderRect.getPosition();
	pos.x += 20.f;
	pos.y += 51.f;
	this->amountDisplay.setPosition(pos);
	this->amountDisplay.setSize(sf::Vector2f(5.f, 5.f));
	this->amountDisplay.setFillColor(sf::Color(255, 255, 255, 150));
	this->amountDisplay.setOutlineThickness(0.f);
	this->amountDisplay.setOutlineColor(sf::Color::Transparent);
}

void PigBarn::updateTextureRect(int season, bool day, Player* player){
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
		if (this->hasBacon) {
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

void PigBarn::updateBaconTimerMax(){
	if (this->pigs > 0)this->baconTimerMax = 20;
	else return;
	this->baconTimerMax -= this->pigs - 1 * 1;
	this->baconTimerMax *= 60; //v minute
}

void PigBarn::updateBacon(){
	if (this->pigs > 0 && this->baconTimerMax > 0 && !this->hasBacon) {
		if (this->baconTimer.getElapsedTime().asSeconds() >= this->baconTimerMax) {
			this->hasBacon = true;
		}
	}
}

void PigBarn::updateAmountDisplay(){
	sf::IntRect tmp = sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(10, 10));
	tmp.left = this->pigs * 10;
	this->amountDisplay.setTexture(this->numbers09);
	this->amountDisplay.setTextureRect(tmp);
}

PigBarn::PigBarn(sf::Vector2f pos) :
	Building(pos, sf::Vector2f(80.f, 80.f), "PigBarn", sf::RectangleShape(), true) {
	this->initTextureRect();
	this->initHitbox();
	this->initInteractZone();
	this->initVariables();
	this->initAmountDisplay();
}

PigBarn::~PigBarn(){
}

void PigBarn::update(int season, bool day, Player* player){
	if (day)this->isAvailable = true;
	else this->isAvailable = false;
	this->updateTextureRect(season, day, player);
	this->updateBacon();
	this->updateAmountDisplay();
}

void PigBarn::render(sf::RenderTarget* target, sf::Shader* shader, const sf::Vector2f light_position){
	Structure::render(target,shader,light_position);
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

bool PigBarn::isFull(){
	return (this->pigs == 8);
}

int PigBarn::addPigs(int amount){
	if (!this->isFull()) {
		if (this->pigs + amount > 8) {
			amount -= 8 - this->pigs;
			this->pigs = 8;
			this->updateBaconTimerMax();
			return amount;
		}
		else {
			this->pigs += amount;
			this->updateBaconTimerMax();
			return 0;
		}
	}
	return -1;
}

bool PigBarn::Bacon(){
	return this->hasBacon;
}

void PigBarn::takeBacon(){
	if (this->hasBacon) {
		this->hasBacon = false;
		this->baconTimer.restart();
	}
}

void PigBarn::saveToFile(std::string file){
	std::ofstream saveOFile(file);
	sf::Vector2f tempPos = this->getPos();
	saveOFile << tempPos.x << "  " << tempPos.y << std::endl;
	saveOFile << this->hasBacon << std::endl;
	saveOFile << this->pigs << std::endl;
	saveOFile.close();
}

void PigBarn::loadFromFile(std::string file){
	std::ifstream saveIFile(file);
	float x;
	float y;
	saveIFile >> x >> y;
	this->setPos(sf::Vector2f(x, y));
	saveIFile >> this->hasBacon;
	saveIFile >> this->pigs;
	saveIFile.close();
	this->initHitbox();
	this->initInteractZone();
	this->updateBaconTimerMax();
	this->initAmountDisplay();
}
