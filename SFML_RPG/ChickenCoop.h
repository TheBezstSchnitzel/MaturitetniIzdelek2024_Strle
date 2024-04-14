#pragma once
#include "Building.h"

class ChickenCoop : public Building {
private:
	int deafultTop;
	int deafultLeft;

	bool hasEgg;
	int chickens;

	sf::Clock eggTimer;
	int eggTimerMax;

	sf::RectangleShape amountDisplay;

	void initVariables();
	void initHitbox();
	void initTextureRect();
	void initInteractZone();
	void initAmountDisplay();

	void updateTextureRect(int season, bool day, Player* player);
	void updateEggTimerMax();
	void updateEgg();
	void updateAmountDisplay();

public:

	ChickenCoop(sf::Vector2f pos);
	~ChickenCoop();

	void update(int season, bool day, Player* player);
	void render(sf::RenderTarget* target, sf::Shader* shader = NULL, const sf::Vector2f light_position = sf::Vector2f());

	bool isFull();
	int addChickens(int amount);
	bool Egg();
	void takeEgg();

	void saveToFile(std::string file);
	void loadFromFile(std::string file);
};

