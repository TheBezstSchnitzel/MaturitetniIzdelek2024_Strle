#pragma once

#include "Entity.h"
#include "Items.h"
#include "Inventory.h"

class Entity;

class Player : public Entity{
private:
	//Lastnosti
	Inventory* inventory;

	bool initAttack;
	bool attacking;

	sf::Clock damageTimer;
	sf::Int32 damageTimerMax;

	//Inicialozacija
	void initVariables();
	void initComponents(sf::Texture& texture_sheet);
	void initAnimations();
	void initInventory();

	bool lastStateUse;

public:
	bool useItem;

	Player(float x, float y, sf::Texture& texture_sheet,bool fromSave);
	virtual ~Player();
	
	//shranjevanje
	void save(std::string savePath);

	//Dostop
	const bool& getInitAttack() const;

	const bool getDamageTimer();

	Inventory* getInventory();
	std::string itemInHand;

	void setNewMaxVelocity(float newMaxVelocity);

	//Interface
	void setInitAttack(const bool initAttack);

	//Funkcije
	void updateAnimation(const float& dt);
	void update(const float& dt, sf::Vector2f& mouse_pos_view, const sf::View& view);

	void render(sf::RenderTarget& target, sf::Shader* shader = NULL, const sf::Vector2f light_position = sf::Vector2f(), const bool show_hitbox = false);
};