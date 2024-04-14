#include "stdafx.h"
#include "CarrotPlant.h"

sf::Texture* CarrotPlant::possible = nullptr;

void CarrotPlant::initTextureRect() {
	this->textureRect = sf::IntRect(sf::Vector2i(32, 0), sf::Vector2i(16, 16));
}

CarrotPlant::CarrotPlant(sf::Vector2f pos) :
	Plant(pos, sf::Vector2f(16.f, 16.f),"carrotPlant"){
	this->initTextureRect();
}

CarrotPlant::~CarrotPlant(){
}

void CarrotPlant::update(){
	Plant::update();
}

void CarrotPlant::render(sf::RenderTarget* target, sf::Shader* shader, const sf::Vector2f light_position){
	this->renderRect.setTextureRect(this->textureRect);
	Structure::render(target,shader,light_position);
}
