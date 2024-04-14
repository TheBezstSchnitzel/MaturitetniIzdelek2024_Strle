#pragma once
#include "Item.h"
class Bacon : public Item {
private:
	sf::Texture* invIcon;

	int amount;
	int maxAmount;

	int value;

	void initValue();

public:
	Bacon(sf::Texture* texture, int amount);
	~Bacon();

	//dostop
	sf::Texture* getTexture();
	int addAmount(int amount);
	int removeAmount(int amount);
	bool isFull() { return (this->amount == this->maxAmount); }
	int getAmount();

	void saveToFile(std::string savePath);
	void loadFromSave(std::string savePath);
};

