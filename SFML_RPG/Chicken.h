#pragma once
#include "Item.h"
class Chicken : public Item {
private:

	sf::Texture* invIcon;

	int amount;
	int maxAmount;

public:
	Chicken(sf::Texture* texture, int amount);
	~Chicken();

	sf::Texture* getTexture();
	int addAmount(int amount);
	int removeAmount(int amount);
	bool isFull() { return (this->amount == this->maxAmount); }
	int getAmount();
	void setAmount(int n);


	void saveToFile(std::string savePath);
	void loadFromSave(std::string savePath);
};

