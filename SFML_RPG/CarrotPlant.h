#pragma once
#include "Structures.h"

class CarrotPlant : public Plant{
private:

	void initTextureRect();

public:
	static sf::Texture* possible;

	CarrotPlant(sf::Vector2f pos);
	~CarrotPlant();

	void update();
	void render(sf::RenderTarget* target, sf::Shader* shader = NULL, const sf::Vector2f light_position = sf::Vector2f());
};

