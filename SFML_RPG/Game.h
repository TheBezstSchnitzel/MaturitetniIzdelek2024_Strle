#pragma once

#include "MainMenuState.h"

class Game{
private:
	//Lastnosti
	GraphicsSettings gfxSettings;
	StateData stateData;
	sf::RenderWindow *window;
	sf::Event sfEvent;

	sf::Clock dtClock;
	float dt;

	std::stack<State*> states;

	std::map<std::string, int> supportedKeys;

	float gridSize;

	//Tematska pesem
	sf::Music theme;
	float volume;

	//Inicializacija
	void initVariables();
	void initGraphicsSettings();
	void initWindow();
	void initKeys();
	void initStateData();
	void initStates();
	void initAudio();

public:
	//Konstuktor / destruktor
	Game();
	virtual ~Game();

	//Funkcije

	//Update
	void updateDt();
	void updateSFMLEvents();
	void update();

	//Zvok
	void playTheme(bool what=true);
	void restartTheme(bool go=true);
	int getThemeStatus();
	void setThemeVolume(float newVolume);
	float getThemeVolume();
	//shranjevanje
	void saveAudio();

	//Render
	void render();

	//Core
	void run();
};