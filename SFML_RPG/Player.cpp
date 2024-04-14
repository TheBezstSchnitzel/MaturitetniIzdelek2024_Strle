#include "stdafx.h"
#include "Player.h"

//Inicializacija
void Player::initVariables(){
	this->initAttack = false;
	this->attacking = false;
	this->sprite.setScale(sf::Vector2f(0.5f, 0.5f));
	this->damageTimerMax = 500;
	this->useItem = false;
	this->lastStateUse = false;
}

void Player::initComponents(sf::Texture& texture_sheet){
	this->createHitboxComponent(this->sprite, 8.5f, 24.5f, 15.f, 7.5f);
	this->createMovementComponent(100.f, 1400.f, 1000.f); //150.f
	this->createAnimationComponent(texture_sheet);
}

void Player::initAnimations(){
	this->animationComponent->addAnimation("IDLE", 15.f, 0, 2, 0, 2, 64, 64);
	this->animationComponent->addAnimation("WALK_DOWN", 5.0f, 0, 6, 8, 6, 64, 64);
	this->animationComponent->addAnimation("WALK_LEFT", 5.0f, 0, 5, 8, 5, 64, 64);
	this->animationComponent->addAnimation("WALK_RIGHT", 5.0f, 0, 7, 8, 7, 64, 64);
	this->animationComponent->addAnimation("WALK_UP", 5.0f, 0, 4, 8, 4, 64, 64);
	this->animationComponent->addAnimation("IDLE_HOE", 5.0f, 0, 14, 0, 14, 64, 64);
	this->animationComponent->addAnimation("WALK_DOWN_HOE", 5.0f, 0, 18, 8, 18, 64, 64);
	this->animationComponent->addAnimation("WALK_LEFT_HOE", 5.0f, 0, 17, 8, 17, 64, 64);
	this->animationComponent->addAnimation("WALK_RIGHT_HOE", 5.0f, 0, 19, 8, 19, 64, 64);
	this->animationComponent->addAnimation("WALK_UP_HOE", 5.0f, 0, 16, 8, 16, 64, 64);
	this->animationComponent->addAnimation("USE_HOE", 10.0f, 0, 14, 7, 14, 64, 64);
}

void Player::initInventory(){
	this->inventory = new Inventory();
}

//Konstruktor / Destruktor
Player::Player(float x, float y, sf::Texture& texture_sheet,bool fromSave){
	this->initVariables();

	this->initComponents(texture_sheet);

	this->setPosition(x, y);
	this->initAnimations();

	this->initInventory();
}

Player::~Player(){
	delete this->inventory;
}

void Player::save(std::string savePath){ //path = "../game/player/"
	//shranjuje podatke o playerju
	//not zapisuj brez da brises kar je ze v datoteki ce dajes v info.txt
	this->inventory->saveToFile(savePath + "/inventory.txt");
}

//Dostop

const bool& Player::getInitAttack() const{
	return this->initAttack;
}

const bool Player::getDamageTimer(){
	if(this->damageTimer.getElapsedTime().asMilliseconds() >= this->damageTimerMax){ 
		this->damageTimer.restart();
		return true;
	}
	return false;
}

Inventory* Player::getInventory(){
	return this->inventory;
}

void Player::setNewMaxVelocity(float newMaxVelocity){
	this->getMovementComponent()->setNewMaxVelocity(newMaxVelocity);
}

void Player::setInitAttack(const bool initAttack){
	this->initAttack = initAttack;
}

//Funkcije
void Player::updateAnimation(const float & dt){
	if (this->useItem){
		if (this->itemInHand == "hoe") {
			if (this->animationComponent->isDone("USE_HOE") && !this->lastStateUse) {
				this->useItem = false;
				this->lastStateUse = true;
			}
			else {
				this->animationComponent->play("USE_HOE", dt, true);
				this->lastStateUse = false;
			}
		}
	}
	if (this->movementComponent->getState(IDLE)){
		if (this->itemInHand == "hoe") {
			this->animationComponent->play("IDLE_HOE", dt);
		}
		else this->animationComponent->play("IDLE", dt);
	}
	else if (this->movementComponent->getState(MOVING_LEFT)){
		if (this->itemInHand == "hoe") {
			this->animationComponent->play("WALK_LEFT_HOE", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
		}
		else this->animationComponent->play("WALK_LEFT", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(MOVING_RIGHT)){
		if (this->itemInHand == "hoe") {
			this->animationComponent->play("WALK_RIGHT_HOE", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
		}
		else this->animationComponent->play("WALK_RIGHT", dt, this->movementComponent->getVelocity().x, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(MOVING_UP)){
		if (this->itemInHand == "hoe") {
			this->animationComponent->play("WALK_UP_HOE", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
		}
		else this->animationComponent->play("WALK_UP", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
	}
	else if (this->movementComponent->getState(MOVING_DOWN)){
		if (this->itemInHand == "hoe") {
			this->animationComponent->play("WALK_DOWN_HOE", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
		}
		else this->animationComponent->play("WALK_DOWN", dt, this->movementComponent->getVelocity().y, this->movementComponent->getMaxVelocity());
	}
}

void Player::update(const float & dt, sf::Vector2f& mouse_pos_view, const sf::View& view){
	this->movementComponent->update(dt);

	this->updateAnimation(dt);
	
	this->hitboxComponent->update();
}

void Player::render(sf::RenderTarget & target, sf::Shader* shader, const sf::Vector2f light_position, const bool show_hitbox){
	if (shader){
		shader->setUniform("hasTexture", true);
		shader->setUniform("lightPos", light_position);
		target.draw(this->sprite, shader);
	}
	else {
		target.draw(this->sprite);
	}
	
	if(show_hitbox)
		this->hitboxComponent->render(target);
}
