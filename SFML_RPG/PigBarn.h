#pragma once
#include "Building.h"

class PigBarn : public Building {
private:
	int deafultTop;
	int deafultLeft;

	bool hasBacon;
	int pigs;

	sf::Clock baconTimer;
	int baconTimerMax;

	sf::RectangleShape amountDisplay;

	void initVariables();
	void initHitbox();
	void initTextureRect();
	void initInteractZone();
	void initAmountDisplay();

	void updateTextureRect(int season, bool day, Player* player);
	void updateBaconTimerMax();
	void updateBacon();
	void updateAmountDisplay();

public:

	PigBarn(sf::Vector2f pos);
	~PigBarn();

	void update(int season, bool day, Player* player);
	void render(sf::RenderTarget* target, sf::Shader* shader = NULL, const sf::Vector2f light_position = sf::Vector2f());

	bool isFull();
	int addPigs(int amount);
	bool Bacon();
	void takeBacon();

	void saveToFile(std::string file);
	void loadFromFile(std::string file);
};

