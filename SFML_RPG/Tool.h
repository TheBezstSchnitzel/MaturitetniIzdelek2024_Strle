#pragma once
#include "Item.h"

class Tool : public Item{
private:
	int maxDurability;
	int durabiltity;

public:
	Tool(short unsigned type, int maxDurability, int durability, std::string id);
	~Tool();
	
	void damageDurability(int damage);
	void healDurability(int heal);
	void setDurability(int durability);

	//dostop
	int getDurability();
};

