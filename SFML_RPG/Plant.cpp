#include "stdafx.h"
#include "Plant.h"

sf::Texture* Plant::textureSheet = nullptr;

void Plant::initClock(){
	this->growClock.restart();
	this->randomGrowTimeMax = std::rand() % 5 + 1;
}

void Plant::initGrowStage(){
	this->growStage = static_cast<GrowStage>(0);
	this->dead = false;
}

void Plant::initInteractZone(){
	this->interactZone.setPosition(sf::Vector2f(this->getPos().x - 2.f, this->getPos().y - 2.f));
	this->interactZone.setSize(sf::Vector2f(20.f, 20.f));
	this->interactZone.setFillColor(sf::Color::Transparent);
}

void Plant::updateTextureRect(){
	if (this->dead) {
		int tempX = 16 * static_cast<int>(this->growStage) + 32 + 5*16;
		this->textureRect.left = tempX;
	}
	else {
		int tempX = 16 * static_cast<int>(this->growStage) + 32;
		this->textureRect.left = tempX;
	}
}

bool Plant::randomEvent(){
	int tmp = std::rand() % 100 + 1;
	if (tmp > 0 && tmp < 6) {
		return true;
	}
	return false;
}

Plant::Plant(sf::Vector2f pos, sf::Vector2f size, std::string type, sf::RectangleShape hitbox, bool hasHitBox) :
	Structure(textureSheet, pos, size, type, hitbox, hasHitBox){
	this->initClock();
	this->initGrowStage();
	this->initInteractZone();
}

Plant::~Plant(){
}
bool Plant::isPickable(Player* player){
	if (static_cast<int>(this->growStage) == 4 || this->dead) {
		sf::FloatRect playerPos = player->getGlobalBounds();
		sf::FloatRect carrotPos = this->interactZone.getGlobalBounds();
		if (carrotPos.intersects(playerPos)) {
			return true;
		}
	}
	return false;
}

bool Plant::isDead(){
	return this->dead;
}

void Plant::updateClock(){
	if (this->growClock.getElapsedTime().asSeconds() / 60 >= randomGrowTimeMax) {
		this->dead = this->randomEvent();
		if (!this->dead) {
			this->growStage = static_cast<GrowStage>(static_cast<int>(this->growStage) + 1); //growa plant
			this->initClock(); //resetira clock
		}
		this->updateTextureRect();
	}
}

void Plant::update(){
	if(!this->dead && this->growStage != static_cast<GrowStage>(4))this->updateClock();
}

void Plant::saveToFile(std::string file){
	std::ofstream saveOFile(file);
	sf::Vector2f tempPos = this->getPos();
	saveOFile << tempPos.x << "  " << tempPos.y << std::endl;
	saveOFile << static_cast<int>(this->growStage) << std::endl;
	saveOFile << this->randomGrowTimeMax << std::endl;
	saveOFile << this->dead << std::endl;
	saveOFile.close();
}

void Plant::loadFromFile(std::string file){
	std::ifstream saveIFile(file);
	float x;
	float y;
	int tempGrowStage = 0;
	saveIFile >> x >> y >> tempGrowStage >> this->randomGrowTimeMax >> this->dead;
	this->setPos(sf::Vector2f(x, y));
	this->growStage = static_cast<GrowStage>(tempGrowStage);
	this->updateTextureRect();
	this->initInteractZone();
	saveIFile.close();
}

