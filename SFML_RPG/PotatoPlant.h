#pragma once
#include "Plant.h"
class PotatoPlant : public Plant {
private:

	void initTextureRect();

public:
	static sf::Texture* possible;

	PotatoPlant(sf::Vector2f pos);
	~PotatoPlant();

	void update();
	void render(sf::RenderTarget* target, sf::Shader* shader = NULL, const sf::Vector2f light_position = sf::Vector2f());
};

