#pragma once

enum ItemTypes { IT_UNUSABLE = 0, IT_USABLE };
/*UNUSABLE: kt na foro pridelki kej kar ne vpliva na svet al pa kar kol
USUABLE pa nasprotnu ksna orodja itd*/

class Item{
private:

	//inicializacija
	void initVariables(short unsigned type);

protected:
	//Lastnosti
	short unsigned type;
	std::string id;

public:
	Item(short unsigned type, std::string id);
	~Item();

	//Dostop
	const short unsigned& getType() const { return this->type;}
	std::string getID() { return this->id; }

	//Funkcije
	virtual sf::Texture* getTexture() = 0;

	virtual void saveToFile(std::string savePath) = 0;
	virtual void loadFromSave(std::string savePath) = 0;
};