#pragma once
#include "Building.h"

//class Building;

class Market : public Building {
private:
	int deafultTop;
	int deafultLeft;

	void initHitbox();
	void initTextureRect();
	void initInteractZone();

	void updateTextureRect(int season, bool day, Player* player);
public:

	Market(sf::Vector2f pos);
	~Market();

	void update(int season, bool day, Player* player);
	void render(sf::RenderTarget* target, sf::Shader* shader = NULL, const sf::Vector2f light_position = sf::Vector2f());

	void saveToFile(std::string file);
	void loadFromFile(std::string file);
};

