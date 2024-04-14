#pragma once
#include "Tool.h"

class BuildPlan : public Tool{
private:
	sf::Texture* invIcon;

public:
	BuildPlan(sf::Texture* icon);
	~BuildPlan();

	sf::Texture* getTexture();

	void saveToFile(std::string savePath);
	void loadFromSave(std::string savePath);
};

