#pragma once
#include "Building.h"

class MediumHouse : public Building{
private:
	int deafultTop;
	int deafultLeft;

	void initHitbox();
	void initTextureRect();
	void initInteractZone();

	void updateTextureRect(int season, bool day, Player* player);

public:

	MediumHouse(sf::Vector2f pos);
	~MediumHouse();

	void update(int season, bool day, Player* player);
	void render(sf::RenderTarget* target);

	void saveToFile(std::string file);
	void loadFromFile(std::string file);
};

