#include "stdafx.h"
#include "PotatoPlant.h"

sf::Texture* PotatoPlant::possible = nullptr;

void PotatoPlant::initTextureRect(){
	this->textureRect = sf::IntRect(sf::Vector2i(32, 80), sf::Vector2i(16, 16));
}

PotatoPlant::PotatoPlant(sf::Vector2f pos) :
	Plant(pos, sf::Vector2f(16.f, 16.f), "potatoPlant") {
	this->initTextureRect();
}

PotatoPlant::~PotatoPlant()
{
}

void PotatoPlant::update(){
	Plant::update();
}

void PotatoPlant::render(sf::RenderTarget* target, sf::Shader* shader, const sf::Vector2f light_position){
	this->renderRect.setTextureRect(this->textureRect);
	Structure::render(target, shader, light_position);
}
