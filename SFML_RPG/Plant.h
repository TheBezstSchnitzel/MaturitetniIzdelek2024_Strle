#pragma once

#include "Structure.h"

enum GrowStage { Seed = 0, LowMid, Mid, HighMid, Grown };

class Plant : public Structure{
private:
	sf::Clock growClock;
	int randomGrowTimeMax; //v minutah

	bool dead;

	GrowStage growStage;

	sf::RectangleShape interactZone;

	void initClock();
	void initGrowStage();
	void initInteractZone();

	void updateTextureRect();
	bool randomEvent(); //5% da se plant unici

protected:
	sf::IntRect textureRect; //da zbere ta prau texture

public:
	static sf::Texture* textureSheet;

	Plant(sf::Vector2f pos, sf::Vector2f size, std::string type, sf::RectangleShape hitbox = sf::RectangleShape(), bool hasHitBox = false);
	~Plant();

	//dostop
	bool isPickable(Player* player);
	bool isDead();

	void updateClock();

	virtual void update();
	virtual void render(sf::RenderTarget* target, sf::Shader* shader = NULL, const sf::Vector2f light_position = sf::Vector2f()) = 0;
	
	virtual void saveToFile(std::string file);
	virtual void loadFromFile(std::string file);

};
