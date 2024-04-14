#include"stdafx.h"
#include"GraphicsSettings.h"

GraphicsSettings::GraphicsSettings(){
	this->title = "DEFAULT";
	this->resolution = sf::VideoMode::getDesktopMode();
	this->fullscreen = false;
	this->frameRateLimit = 120;
	this->contextSettings.antialiasingLevel = 0;
	this->videoModes = sf::VideoMode::getFullscreenModes();
}

//Funkcija
void GraphicsSettings::saveToFile(const std::string path){
	std::ofstream ofs(path);

	if (ofs.is_open()){
		ofs << this->title << std::endl;
		ofs << this->resolution.width << " " << this->resolution.height << std::endl;
		ofs << this->fullscreen << std::endl;
		ofs << this->frameRateLimit << std::endl;
		ofs << this->contextSettings.antialiasingLevel << std::endl;
	}

	ofs.close();
}

void GraphicsSettings::loadFromFile(const std::string path){
	std::ifstream ifs(path);

	if (ifs.is_open()){
		std::getline(ifs, this->title);
		ifs >> this->resolution.width >> this->resolution.height;
		ifs >> this->fullscreen;
		ifs >> this->frameRateLimit;
		ifs >> this->contextSettings.antialiasingLevel;
	}

	ifs.close();
}