#include "stdafx.h"
#include "Building.h"

sf::Texture* Building::textureSheet = nullptr;
sf::Texture* Building::numbers09 = nullptr;

Building::Building(sf::Vector2f pos, sf::Vector2f size, std::string type, sf::RectangleShape hitbox, bool hasHitBox) :
	Structure(textureSheet, pos, size, type, hitbox, true){
	this->isAvailable = false;
}

Building::~Building(){
}

bool Building::checkIfPlayerBehind(Player* player){
	sf::Vector2f playerPos = player->getPosition();
	sf::Vector2f posHb = this->getHitbox()->getPosition();
	sf::Vector2f sizeHb = this->getHitbox()->getSize();
	sf::Vector2f pos = this->getPos();
	if (playerPos.y < posHb.y) {
		//ce je player nad tm hitboxom
		if (playerPos.y + 5.f >= pos.y) {
			//prever da je tam ker bi ga tekstura motla od spodi
			if (playerPos.x < posHb.x + sizeHb.x) {
				//prever da je desna stran notr
				if (playerPos.x + 15.f > posHb.x) {
					return true;
				}
			}
		}
	}
	return false;
}

bool Building::isInteractable(Player* player){
	if (this->isAvailable) {
		sf::FloatRect playerPos = player->getGlobalBounds();
		sf::FloatRect pos = this->interactZone.getGlobalBounds();
		if (pos.intersects(playerPos)) {
			return true;
		}
	}
	return false;
}