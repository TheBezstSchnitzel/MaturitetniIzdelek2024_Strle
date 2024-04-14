#include "stdafx.h"
#include "BuildPlan.h"

BuildPlan::BuildPlan(sf::Texture* icon) : 
	Tool(1, 1, 1, "ITEM_TOOL_BUILDPLAN") {
	this->invIcon = icon;
}

BuildPlan::~BuildPlan(){

}

sf::Texture* BuildPlan::getTexture(){
	return this->invIcon;
}

void BuildPlan::saveToFile(std::string savePath){

}

void BuildPlan::loadFromSave(std::string savePath){

}
