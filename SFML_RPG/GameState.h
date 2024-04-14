#pragma once

#include "State.h"
#include "PauseMenu.h"
#include "TileMap.h"
#include "PlayerGUI.h"
#include "Items.h"
#include "Structures.h"
#include <SFML/Audio.hpp>

class Game;
class Market;

enum letniCasi {
	pomlad = 1, // 12 ur dneva
	poletje = 2, // 14 ur dneva
	jesen = 3, // 12 ur dneva
	zima = 4, // 10 ur dneva
};

class GameState : public State {
private:
	Game* game;

	std::string savePath;

	std::string creationDate;

	sf::View view;
	sf::Vector2i viewGridPosition;
	sf::RenderTexture renderTexture;
	sf::Sprite renderSprite;

	bool isZoomedOut;
	bool isInventoryOpen;

	sf::Font font;
	PauseMenu* pmenu;

	sf::Shader core_shader;
	sf::Shader temp;

	sf::Clock keyTimer;
	float keyTimeMax;

	std::map<std::string, sf::Clock> keybindsTimes;

	//buildings
	std::map<std::string, std::map<int, Structure*>> buildings;

	bool hasItemInHand;
	std::string iteminHand;

	bool isShopOpen;

	//in game time
	int whenIsNightHour; //kdaj se dan spremeni u noc
	int whenIsDayHour; //kdaj se noc spremeni u dan

	int inGameTime_Hours;
	int inGameTime_Minutes;

	bool isDay;

	int gameDaysElapsed;
	letniCasi currentSeason;

	sf::Text debugText;

	bool lastMouseStateR;

	Player* player;
	PlayerGUI* playerGUI;
	sf::Texture texture;

	TileMap* tileMap;

	//Background muzika
	float volume;

	sf::Music dayAudio;
	sf::Music nightAudio;

	void updateAudio();

	//Privatne funkcije
	//inicializacija
	void initVariables();
	void initDeferredRender();
	void initView();
	void initKeybinds();
	void initFonts();
	void initTextures();
	void initPauseMenu();
	void initShaders();
	void initKeyTime();
	void initDebugText();

	void initPlayers();
	void initPlayerGUI();
	void initTileMap();

	void initInGameTime();
	void initInGameTimers();

	void initMarket();

	void initAudio();

	//funkcije za nalaganje iz shrambe
	void loadFromSave_misc();
	void loadFromSave_inGameTime();
	void loadFromSave_player();
	void loadFromSave_items();
	void loadFromSave_buildings();
	void loadFromSave();

	//funkcije za shranjevanje
	void createSaveDir();

	void save_misc();
	void save_inGameTime();
	void save_player();
	void save_items();
	void save_buildings();
	void save();

	//Game time
	sf::Clock minutesTimer;
	float minutesTimerMax;
	void updateHours_Minutes();

	//tools
	void useHoe();
	void useCarrotSeed();
	void usePotatoSeed();
	void useBuildPlan();
	//items
	void addCarrots();
	void addPotatos();

	//house
	void changeToDay();

public:
	GameState(StateData* state_data, Game* game, unsigned short save);
	virtual ~GameState();

	//Dostop
	const bool getKeyTime();

	//Funkcije
	void updateView(const float& dt);
	void updateInput(const float& dt);
	void updatePlayerInput(const float& dt);
	void updatePlayerGUI(const float& dt);
	void updatePauseMenuButtons();
	void updateTileMap(const float& dt);
	void updatePlayer(const float& dt);
	void updateDebugText(const float& dt);
	void updateInGameTime();
	void updateBuildingsColl(const float& dt);
	void updateBuildings();
	void updateItems();
	void update(const float& dt);

	void render(sf::RenderTarget* target = NULL);
};