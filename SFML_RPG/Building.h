#pragma once

#include "Structure.h"

class Building : public Structure {
private:

protected:
	bool isAvailable;

	sf::IntRect textureRect;
	sf::RectangleShape interactZone;

public:
	static sf::Texture* textureSheet;
	static sf::Texture* numbers09;

	Building(sf::Vector2f pos, sf::Vector2f size, std::string type, sf::RectangleShape hitbox, bool hasHitBox);
	~Building();

	bool checkIfPlayerBehind(Player* player);
	bool isInteractable(Player* player);

	virtual void update(int season, bool day, Player* player) = 0;
};

