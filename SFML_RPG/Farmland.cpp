#include "stdafx.h"
#include "Farmland.h"

Farmland::Farmland(sf::Texture* texture, sf::Vector2f pos) :
Structure(texture,pos, sf::Vector2f(16.f, 16.f),"farmland",sf::RectangleShape()) {

}

Farmland::~Farmland(){
}

void Farmland::update(){
}

void Farmland::render(sf::RenderTarget* target, sf::Shader* shader, const sf::Vector2f light_position){
	Structure::render(target,shader,light_position);
}

void Farmland::saveToFile(std::string file){
	std::ofstream saveOFile(file);
	sf::Vector2f tempPos = this->getPos();
	saveOFile << tempPos.x << "  " << tempPos.y << std::endl;
	saveOFile.close();
}

void Farmland::loadFromFile(std::string file){
	std::ifstream saveIFile(file);
	float x;
	float y;
	saveIFile >> x >> y;
	this->setPos(sf::Vector2f(x,y));
	saveIFile.close();
}
