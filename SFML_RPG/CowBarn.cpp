#include "stdafx.h"
#include "CowBarn.h"

void CowBarn::initVariables(){
	this->hasMilk = false;
	this->cows = 0;
	this->milkTimerMax = 0; //odvisen od kolicine krav
	this->milkTimer.restart();
}

void CowBarn::initHitbox(){
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

void CowBarn::initTextureRect(){
	this->textureRect.width = 80;
	this->textureRect.height = 80;
	this->textureRect.left = 0;
	this->textureRect.top = 160;
	this->deafultLeft = 0;
	this->deafultTop = 160;
	//this->renderRect.setFillColor(sf::Color(255, 255, 255, 255));
	//this->renderRect.setTextureRect(this->textureRect);
}

void CowBarn::initInteractZone(){
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

void CowBarn::initAmountDisplay(){
	sf::Vector2f pos = this->renderRect.getPosition();
	pos.x += 20.f;
	pos.y += 51.f;
	this->amountDisplay.setPosition(pos);
	this->amountDisplay.setSize(sf::Vector2f(5.f,5.f));
	this->amountDisplay.setFillColor(sf::Color(255,255,255,150));
	this->amountDisplay.setOutlineThickness(0.f);
	this->amountDisplay.setOutlineColor(sf::Color::Transparent);
}

void CowBarn::updateTextureRect(int season, bool day, Player* player){
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
		if (this->hasMilk) {
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

void CowBarn::updateMilkTimerMax(){
	if (this->cows > 0)this->milkTimerMax = 11;
	else return;
	this->milkTimerMax -= this->cows-1 * 1; //10 minut 1 krava, pa usaka krava pohitri za eno minuto
	this->milkTimerMax *= 60; //v minute
}

void CowBarn::updateMilk(){
	if (this->cows > 0 && this->milkTimerMax > 0 && !this->hasMilk) {
		if (this->milkTimer.getElapsedTime().asSeconds() >= this->milkTimerMax) {
			this->hasMilk = true;
		}
	}
}

void CowBarn::updateAmountDisplay(){
	sf::IntRect tmp = sf::IntRect(sf::Vector2i(0,0), sf::Vector2i(10,10));
	tmp.left = this->cows * 10;
	this->amountDisplay.setTexture(this->numbers09);
	this->amountDisplay.setTextureRect(tmp);
}

CowBarn::CowBarn(sf::Vector2f pos) :
	Building(pos, sf::Vector2f(80.f, 80.f), "CowBarn", sf::RectangleShape(), true) {
	this->initTextureRect();
	this->initHitbox();
	this->initInteractZone();
	this->initVariables();
	this->initAmountDisplay();
}

CowBarn::~CowBarn(){

}

void CowBarn::update(int season, bool day, Player* player){
	if (day)this->isAvailable = true;
	else this->isAvailable = false;
	this->updateTextureRect(season, day, player);
	this->updateMilk();
	this->updateAmountDisplay();
}

void CowBarn::render(sf::RenderTarget* target, sf::Shader* shader, const sf::Vector2f light_position){
	Structure::render(target,shader,light_position);
	if (shader) {
		shader->setUniform("hasTexture", true);
		shader->setUniform("lightPos", light_position);
		target->draw(this->amountDisplay, shader);
	}
	else {
		target->draw(this->amountDisplay);
	}
}

bool CowBarn::isFull(){
	return (this->cows == 6);
}

int CowBarn::addCows(int amount){
	if (!this->isFull()) {
		if (this->cows + amount > 6) {
			amount -= 6 - this->cows;
			this->cows = 6;
			this->updateMilkTimerMax();
			return amount;
		}
		else {
			this->cows += amount;
			this->updateMilkTimerMax();
			return 0;
		}
	}
	return -1;
}

bool CowBarn::Milk(){
	return this->hasMilk;
}

void CowBarn::takeMilk(){
	if (this->hasMilk) {
		this->hasMilk = false;
		this->milkTimer.restart();
	}
}

void CowBarn::saveToFile(std::string file){
	std::ofstream saveOFile(file);
	sf::Vector2f tempPos = this->getPos();
	saveOFile << tempPos.x << "  " << tempPos.y << std::endl;
	saveOFile << this->hasMilk << std::endl;
	saveOFile << this->cows << std::endl;
	saveOFile.close();
}

void CowBarn::loadFromFile(std::string file){
	std::ifstream saveIFile(file);
	float x;
	float y;
	saveIFile >> x >> y;
	this->setPos(sf::Vector2f(x, y));
	saveIFile >> this->hasMilk;
	saveIFile >> this->cows;
	saveIFile.close();
	this->initHitbox();
	this->initInteractZone();
	this->updateMilkTimerMax();
	this->initAmountDisplay();
}


