#pragma once
#include "Tool.h"
class PotatoSeed : public Tool {
private:
	sf::Texture* invIcon;

public:
	PotatoSeed(sf::Texture* icon, int durability);
	~PotatoSeed();

	sf::Texture* getTexture();

	void saveToFile(std::string savePath);
	void loadFromSave(std::string savePath);
};

