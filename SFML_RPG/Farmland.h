#pragma once
#include "Structures.h"

class Farmland : public Structure{
private:
	

public:
	Farmland(sf::Texture* texture, sf::Vector2f pos);
	~Farmland();

	void update();
	void render(sf::RenderTarget* target, sf::Shader* shader = NULL, const sf::Vector2f light_position = sf::Vector2f());

	void saveToFile(std::string file);
	void loadFromFile(std::string file);
};

