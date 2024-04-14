#pragma once
#include "Building.h"
class CowBarn : public Building{
private:
	int deafultTop;
	int deafultLeft;

	bool hasMilk;
	int cows;

	sf::Clock milkTimer;
	int milkTimerMax;

	sf::RectangleShape amountDisplay;

	void initVariables();
	void initHitbox();
	void initTextureRect();
	void initInteractZone();
	void initAmountDisplay();

	void updateTextureRect(int season, bool day, Player* player);
	void updateMilkTimerMax();
	void updateMilk();
	void updateAmountDisplay();

public:

	CowBarn(sf::Vector2f pos);
	~CowBarn();

	void update(int season, bool day, Player* player);
	void render(sf::RenderTarget* target, sf::Shader* shader = NULL, const sf::Vector2f light_position = sf::Vector2f());

	bool isFull();
	int addCows(int amount);
	bool Milk();
	void takeMilk();

	void saveToFile(std::string file);
	void loadFromFile(std::string file);
};

