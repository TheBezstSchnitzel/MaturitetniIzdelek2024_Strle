#pragma once
#include "Tool.h"
class Hoe : public Tool{
private:
	sf::Texture* invIcon;

public:
	Hoe(sf::Texture* icon, int durability);
	~Hoe();

	//dostop

	sf::Texture* getTexture();

	void saveToFile(std::string savePath);
	void loadFromSave(std::string savePath);
};