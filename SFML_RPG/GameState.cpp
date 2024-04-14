#include "stdafx.h"
#include "GameState.h"
#include "Game.h"
#include <filesystem>

void GameState::initVariables(){
	this->isZoomedOut = false;
}

//Inicializacija
void GameState::initDeferredRender(){
	this->renderTexture.create(
		this->stateData->gfxSettings->resolution.width,
		this->stateData->gfxSettings->resolution.height
	);

	this->renderSprite.setTexture(this->renderTexture.getTexture());
	this->renderSprite.setTextureRect(
		sf::IntRect(
			0, 
			0, 
			this->stateData->gfxSettings->resolution.width, 
			this->stateData->gfxSettings->resolution.height
		)
	);
}

void GameState::initView(){
	this->view.setSize(
		sf::Vector2f(
			static_cast<float>(this->stateData->gfxSettings->resolution.width / 2),
			static_cast<float>(this->stateData->gfxSettings->resolution.height / 2)
		)
	);

	this->view.setCenter(
		sf::Vector2f(
			static_cast<float>(this->stateData->gfxSettings->resolution.width) / 2.f,
			static_cast<float>(this->stateData->gfxSettings->resolution.height) / 2.f
		)
	);
	if (!this->isZoomedOut) {
		this->view.zoom(0.5f);
	}
	else {
		this->player->setNewMaxVelocity(140.f);
	}
}

void GameState::initKeybinds(){
	std::ifstream ifs("Config/gamestate_keybinds.ini");

	if (ifs.is_open()){
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2){
			this->keybinds[key] = this->supportedKeys->at(key2);
			if(key == "ZOOM")this->keybindsTimes[key] = sf::Clock();
			if (key == "INVENTORY")this->keybindsTimes[key] = sf::Clock();
			if(key == "PICKUP")this->keybindsTimes[key] = sf::Clock();
			if(key == "CHANGE_SELECTOR")this->keybindsTimes[key] = sf::Clock();
		}
	}

	ifs.close();
}

void GameState::initFonts(){
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf")){
		throw("ERROR::MAINMENUSTATE::COULD NOT LOAD FONT");
	}
}

void GameState::initTextures(){
	//player
	if (!this->textures["PLAYER_SHEET"].loadFromFile("Resources/Images/Sprites/Player/PLAYER_SHEET2.png")) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PLAYER_TEXTURE";
	}
	//items
	if (!this->textures["HoeIcon"].loadFromFile("Resources/Images/Gui/hoeIcon.png")) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_HOE_ICON_TEXTURE";
	}
	if (!this->textures["BuildPlanIcon"].loadFromFile("Resources/Images/Mixed/blueprint.png")) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_HOE_ICON_TEXTURE";
	}
	if (!this->textures["carrot_seed"].loadFromFile("Resources/Images/Mixed/crops_all.png", sf::IntRect(sf::Vector2i(0,0),sf::Vector2i(16,16)))) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_plants_all_TEXTURE";
	}
	if (!this->textures["potato_seed"].loadFromFile("Resources/Images/Mixed/crops_all.png", sf::IntRect(sf::Vector2i(0, 80), sf::Vector2i(16, 16)))) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_plants_all_TEXTURE";
	}
	if (!this->textures["carrot"].loadFromFile("Resources/Images/Mixed/items.png", sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(16, 16)))) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_plants_all_TEXTURE";
	}
	if (!this->textures["potato"].loadFromFile("Resources/Images/Mixed/items.png", sf::IntRect(sf::Vector2i(80, 0), sf::Vector2i(16, 16)))) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_items_potato_TEXTURE";
	}
	if (!this->textures["milk"].loadFromFile("Resources/Images/Mixed/items.png", sf::IntRect(sf::Vector2i(0, 48), sf::Vector2i(16, 16)))) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_milk_TEXTURE";
	}
	if (!this->textures["cow"].loadFromFile("Resources/Images/Mixed/cowIcon.png", sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(16, 16)))) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_cowIcon_TEXTURE";
	}
	if (!this->textures["bacon"].loadFromFile("Resources/Images/Mixed/items.png", sf::IntRect(sf::Vector2i(96, 48), sf::Vector2i(16, 16)))) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_bacon_TEXTURE";
	}
	if (!this->textures["pig"].loadFromFile("Resources/Images/Mixed/pigIcon.png", sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(16, 16)))) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_pigIcon_TEXTURE";
	}
	if (!this->textures["egg"].loadFromFile("Resources/Images/Mixed/items.png", sf::IntRect(sf::Vector2i(0, 64), sf::Vector2i(16, 16)))) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_egg_TEXTURE";
	}
	if (!this->textures["chicken"].loadFromFile("Resources/Images/Mixed/chickenIcon.png", sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(16, 16)))) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_pigIcon_TEXTURE";
	}
	//buildings
	if (!this->textures["Farmland"].loadFromFile("Resources/Images/Buildings/farmland.png")){
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_Farmland_TEXTURE";
	}
	Building::textureSheet = new sf::Texture();
	if (!Building::textureSheet->loadFromFile("Resources/Images/Buildings/all.png")) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_Building_TEXTURE_sheet";
	}
	//plants
	Plant::textureSheet = new sf::Texture();
	if (!Plant::textureSheet->loadFromFile("Resources/Images/Mixed/crops_all.png")){
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_plants_texture_sheet_TEXTURE";
	}
	//carrot
	CarrotPlant::possible = new sf::Texture();
	if (!CarrotPlant::possible->loadFromFile("Resources/Images/Mixed/crops_all.png", sf::IntRect(sf::Vector2i(32, 0), sf::Vector2i(16, 16)))) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_CarrotPlantPossible_TEXTURE";
	}
	//potato
	PotatoPlant::possible = new sf::Texture();
	if (!PotatoPlant::possible->loadFromFile("Resources/Images/Mixed/crops_all.png", sf::IntRect(sf::Vector2i(32, 80), sf::Vector2i(16, 16)))) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_PotatoPlantPossible_TEXTURE";
	}

	//gui
	Building::numbers09 = new sf::Texture();
	if (!Building::numbers09->loadFromFile("Resources/Images/Gui/numbers09.png")) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_numbers09_TEXTURE";
	}
}

void GameState::initMarket(){
	this->buildings["Market"][0] = new Market(sf::Vector2f(100.f, 100.f));
}

void GameState::initAudio(){
	//dan
	this->dayAudio.openFromFile("Resources/Audio/background1.wav");
	this->dayAudio.setVolume(this->volume);
	this->dayAudio.setLoop(true);
	//noc
	this->nightAudio.openFromFile("Resources/Audio/background2.wav");
	this->nightAudio.setVolume(this->volume);
	this->nightAudio.setLoop(true);
}

void GameState::updateAudio() {
	//2 je za playing
	if (this->isDay && this->dayAudio.getStatus() != 2) {
		this->nightAudio.pause();
		this->dayAudio.play();
	}
	else if (!this->isDay && this->nightAudio.getStatus() != 2) {
		this->dayAudio.pause();
		this->nightAudio.play();
	}
}

void GameState::initPauseMenu(){
	const sf::VideoMode& vm = this->stateData->gfxSettings->resolution;
	this->pmenu = new PauseMenu(this->stateData->gfxSettings->resolution, this->font);

	this->pmenu->addButton("RESUME", gui::p2pY(30.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), gui::calcCharSize(vm), "Resume");
	this->pmenu->addButton("SAVE", gui::p2pY(62.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), gui::calcCharSize(vm), "Save");
	this->pmenu->addButton("QUIT", gui::p2pY(74.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), gui::calcCharSize(vm), "Quit");

	this->pmenu->addButton("VolumeText", gui::p2pY(42.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), gui::calcCharSize(vm), "Volume:");

	this->pmenu->addSlider("Volume", gui::p2pY(53.f, vm), gui::p2pX(12.f, vm), gui::p2pY(1.4f, vm), gui::calcCharSize(vm));
	this->pmenu->getSlider("Volume")->setValue(this->volume);
}

void GameState::initShaders(){
	if (!this->core_shader.loadFromFile("vertex_shader.vert", "fragment_shader.frag")){
		std::cout << "ERROR::GAMESTATE::COULD NOT LOAD SHADER." << "\n";
	}
}

void GameState::initKeyTime(){
	this->keyTimeMax = 0.75f;
	this->keyTimer.restart();
}

void GameState::initDebugText(){
	this->debugText.setFont(this->font);
	this->debugText.setFillColor(sf::Color::White);
	this->debugText.setCharacterSize(16);
	this->debugText.setPosition(15.f, this->window->getSize().y / 2.f);
}

void GameState::initPlayers() {
	this->player = new Player(300, 220, this->textures["PLAYER_SHEET"],false);
}

void GameState::initPlayerGUI(){
	this->playerGUI = new PlayerGUI(this->player, this->stateData->gfxSettings->resolution, this->font,&this->textures);
}

void GameState::initTileMap(){
	switch (this->currentSeason) {
	case pomlad:
		this->tileMap = new TileMap("Config/map.slmp", "Resources/Images/Tiles/newFloorTiles_Pomlad.png");
		break;
	case poletje:
		this->tileMap = new TileMap("Config/map.slmp", "Resources/Images/Tiles/newFloorTiles_Poletje.png");
		break;
	case jesen:
		this->tileMap = new TileMap("Config/map.slmp", "Resources/Images/Tiles/newFloorTiles_Jesen.png");
		break;
	case zima:
		this->tileMap = new TileMap("Config/map.slmp","Resources/Images/Tiles/newFloorTiles_Zima.png");
		break;
	}
}

void GameState::initInGameTime(){
	//ce ni prejsnega progressa se klice ta funkcija
	this->isDay = true;
	this->gameDaysElapsed = 0;
	this->currentSeason = pomlad;
	
	this->inGameTime_Hours = 6;
	this->inGameTime_Minutes = 0;
}

void GameState::initInGameTimers(){
	switch (this->currentSeason) {
	case pomlad:this->whenIsNightHour = 18; this->whenIsDayHour = 6; break;
	case poletje:this->whenIsNightHour = 19; this->whenIsDayHour = 5; break;
	case jesen:this->whenIsNightHour = 18; this->whenIsDayHour = 6; break;
	case zima:this->whenIsNightHour = 17; this->whenIsDayHour = 7; break;
	}

	this->minutesTimer.restart();
	this->minutesTimerMax = 1.f; //1s = 1min; 1min = 1h
}

//funkcije za branje shranjenih podatkov
void GameState::loadFromSave_misc(){
	std::string miscPath = this->savePath + "/misc.txt";
	std::ifstream saveIFile(miscPath);
	//prebere podatke
	if (saveIFile.is_open()) {
		//Zapisovanje podatkov
		std::getline(saveIFile, this->creationDate);
		saveIFile >> this->isZoomedOut >> this->volume;
		saveIFile.close();
	}
	else {
		throw("ERROR::GameState::loadFromSave_misc::FILE_NOT_OPEN");
	}
}

void GameState::loadFromSave_inGameTime(){
	std::string timePath = this->savePath + "/game/time.txt";
	std::ifstream saveIFile(timePath);

	//prebere podatke
	if (saveIFile.is_open()) {
		//Zapisovanje podatkov
		std::string seasonTmp = "";
		saveIFile >> this->isDay;
		saveIFile >> this->inGameTime_Hours >> this->inGameTime_Minutes;
		saveIFile >> this->gameDaysElapsed >> seasonTmp;
		this->currentSeason = static_cast<letniCasi>(std::stoi(seasonTmp));
		
		saveIFile.close();
	}
	else {
		throw("ERROR::GameState::loadFromSave_inGameTime::FILE_NOT_OPEN");
	}
}

void GameState::loadFromSave_player(){
	std::string playerPath = this->savePath + "/game/player/info.txt";
	std::ifstream saveIFile(playerPath);

	//prebere podatke
	if (saveIFile.is_open()) {
		//Branje podatkov
		float x, y;
		saveIFile >> x >> y;

		saveIFile.close();
		//zapisovanje podatkov
		this->player = new Player(x, y, this->textures["PLAYER_SHEET"],true);
		this->player->getInventory()->loadFromFile(this->savePath + "/game/player/inventory.txt");
	}
	else {
		throw("ERROR::GameState::loadFromSave_inGameTime::FILE_NOT_OPEN");
	}
}

void GameState::loadFromSave_items(){
	Inventory* inv = this->player->getInventory();
	std::ifstream saveIFile(this->savePath + "/game/items/itemsList.txt");
	std::string className = "";
	int i = 0;
	while (saveIFile >> className >> i) {
		if (className == "Hoe") {
			inv->add(new Hoe(&this->textures["HoeIcon"], 120), i);
			inv->getItem(i)->loadFromSave(this->savePath + "/game/items/item" + std::to_string(i) + ".txt");
			continue;
		}
		if (className == "CarrotSeed") {
			this->player->getInventory()->add(new CarrotSeed(&this->textures["carrot_seed"], 100), i);
			inv->getItem(i)->loadFromSave(this->savePath + "/game/items/item" + std::to_string(i) + ".txt");
			continue;
		}
		if (className == "PotatoSeed") {
			this->player->getInventory()->add(new PotatoSeed(&this->textures["potato_seed"], 100), i);
			inv->getItem(i)->loadFromSave(this->savePath + "/game/items/item" + std::to_string(i) + ".txt");
			continue;
		}
		if (className == "Carrot") {
			this->player->getInventory()->add(new Carrot(&this->textures["carrot"], 0), i);
			inv->getItem(i)->loadFromSave(this->savePath + "/game/items/item" + std::to_string(i) + ".txt");
			continue;
		}
		if (className == "Potato") {
			this->player->getInventory()->add(new Potato(&this->textures["potato"], 0), i);
			inv->getItem(i)->loadFromSave(this->savePath + "/game/items/item" + std::to_string(i) + ".txt");
			continue;
		}
		if (className == "BuildPlan") {
			this->player->getInventory()->add(new BuildPlan(&this->textures["BuildPlanIcon"]), i);
			continue;
		}
		if (className == "Cow") {
			this->player->getInventory()->add(new Cow(&this->textures["cow"], 0),i);
			inv->getItem(i)->loadFromSave(this->savePath + "/game/items/item" + std::to_string(i) + ".txt");
			continue;
		}
		if (className == "Milk") {
			this->player->getInventory()->add(new Milk(&this->textures["milk"], 0), i);
			inv->getItem(i)->loadFromSave(this->savePath + "/game/items/item" + std::to_string(i) + ".txt");
			continue;
		}
		if (className == "Bacon") {
			this->player->getInventory()->add(new Bacon(&this->textures["bacon"], 0), i);
			inv->getItem(i)->loadFromSave(this->savePath + "/game/items/item" + std::to_string(i) + ".txt");
			continue;
		}
		if (className == "Pig") {
			this->player->getInventory()->add(new Pig(&this->textures["pig"], 0), i);
			inv->getItem(i)->loadFromSave(this->savePath + "/game/items/item" + std::to_string(i) + ".txt");
			continue;
		}
		if (className == "Egg") {
			this->player->getInventory()->add(new Egg(&this->textures["egg"], 0), i);
			inv->getItem(i)->loadFromSave(this->savePath + "/game/items/item" + std::to_string(i) + ".txt");
			continue;
		}
		if (className == "Chicken") {
			this->player->getInventory()->add(new Chicken(&this->textures["chicken"], 0), i);
			inv->getItem(i)->loadFromSave(this->savePath + "/game/items/item" + std::to_string(i) + ".txt");
			continue;
		}
		std::cout << "mors popraut gamestate loadSaveItems" << std::endl;
	}
	saveIFile.close();
	
}

void GameState::loadFromSave_buildings() {
	std::ifstream saveIFile(this->savePath + "/game/buildings/buildingsList.txt");
	std::string buildingType = "";
	int n = 0;
	while (saveIFile >> buildingType >> n) {
		if (buildingType == "farmland") {
			for (int i = 0; i < n; i++) {
				this->buildings["farmland"][i] = new Farmland(&this->textures["Farmland"], sf::Vector2f(0.f, 0.f));
				this->buildings["farmland"][i]->loadFromFile(this->savePath + "/game/buildings/" + buildingType + std::to_string(i) + ".txt");
			}
			continue;
		}
		if (buildingType == "carrotPlant") {
			for (int i = 0; i < n; i++) {
				this->buildings["carrotPlant"][i] = new CarrotPlant(sf::Vector2f(0.f, 0.f));
				this->buildings["carrotPlant"][i]->loadFromFile(this->savePath + "/game/buildings/" + buildingType + std::to_string(i) + ".txt");
			}
			continue;
		}
		if (buildingType == "SmallHouse") {
			for (int i = 0; i < n; i++) {
				this->buildings["SmallHouse"][i] = new SmallHouse(sf::Vector2f(0.f, 0.f));
				this->buildings["SmallHouse"][i]->loadFromFile(this->savePath + "/game/buildings/" + buildingType + std::to_string(i) + ".txt");
			}
			continue;
		}
		if (buildingType == "CowBarn") {
			for (int i = 0; i < n; i++) {
				this->buildings["CowBarn"][i] = new CowBarn(sf::Vector2f(0.f, 0.f));
				this->buildings["CowBarn"][i]->loadFromFile(this->savePath + "/game/buildings/" + buildingType + std::to_string(i) + ".txt");
			}
			continue;
		}
		if (buildingType == "MediumHouse") {
			for (int i = 0; i < n; i++) {
				this->buildings["MediumHouse"][i] = new MediumHouse(sf::Vector2f(0.f, 0.f));
				this->buildings["MediumHouse"][i]->loadFromFile(this->savePath + "/game/buildings/" + buildingType + std::to_string(i) + ".txt");
			}
			continue;
		}
		if (buildingType == "PigBarn") {
			for (int i = 0; i < n; i++) {
				this->buildings["PigBarn"][i] = new PigBarn(sf::Vector2f(0.f, 0.f));
				this->buildings["PigBarn"][i]->loadFromFile(this->savePath + "/game/buildings/" + buildingType + std::to_string(i) + ".txt");
			}
			continue;
		}
		if (buildingType == "potatoPlant") {
			for (int i = 0; i < n; i++) {
				this->buildings["potatoPlant"][i] = new PotatoPlant(sf::Vector2f(0.f, 0.f));
				this->buildings["potatoPlant"][i]->loadFromFile(this->savePath + "/game/buildings/" + buildingType + std::to_string(i) + ".txt");
			}
			continue;
		}
		if (buildingType == "ChickenCoop") {
			for (int i = 0; i < n; i++) {
				this->buildings["ChickenCoop"][i] = new ChickenCoop(sf::Vector2f(0.f, 0.f));
				this->buildings["ChickenCoop"][i]->loadFromFile(this->savePath + "/game/buildings/" + buildingType + std::to_string(i) + ".txt");
			}
			continue;
		}
		std::cout << "Popravt mors loadFromSave buildings" << std::endl;
	}
	saveIFile.close();
}

void GameState::loadFromSave(){
	//klièe vse funkcije za loudanje iz save
	this->loadFromSave_inGameTime();
	this->loadFromSave_misc();
	this->loadFromSave_player();
	this->loadFromSave_items();
	this->loadFromSave_buildings();
}

void GameState::createSaveDir(){
	//prever ce mapa obstaja (da ni prvoi shranjevanj)
	std::string path = this->savePath + "/game";
	if (!std::filesystem::is_directory(path)) {
		//ustvari novo mapo ce je prvo shranjevanje
		std::filesystem::create_directory(path);
	}
	path = path + "/player";
	if (!std::filesystem::is_directory(path)) {
		//ustvari novo mapo ce je prvo shranjevanje
		std::filesystem::create_directory(path);
	}
	path = this->savePath + "/game/items";
	if (!std::filesystem::is_directory(path)) {
		//ustvari novo mapo ce je prvo shranjevanje
		std::filesystem::create_directory(path);
	}
	path = this->savePath + "/game/buildings";
	if (!std::filesystem::is_directory(path)) {
		//ustvari novo mapo ce je prvo shranjevanje
		std::filesystem::create_directory(path);
	}
}

//funkcije za shranjevanje
void GameState::save_misc(){
	std::string miscPath = this->savePath + "/misc.txt";
	std::ofstream saveOFile(miscPath);
	//shrani podatke
	if (saveOFile.is_open()) {
		//shranjevanje
		saveOFile << this->creationDate << std::endl;
		saveOFile << this->isZoomedOut << std::endl;
		saveOFile << this->volume << std::endl;
		saveOFile.close();
	}
	else {
		throw("ERROR::GameState::save_misc::FILE_NOT_OPEN");
	}
}

void GameState::save_inGameTime(){
	//shrani podatke
	std::string timePath = this->savePath+"/game/time.txt";
	std::ofstream saveOFile(timePath);
	if (saveOFile.is_open()) {
		//Shranjevanje
		saveOFile << this->isDay << std::endl;
		saveOFile << this->inGameTime_Hours << std::endl;
		saveOFile << this->inGameTime_Minutes << std::endl;
		saveOFile << this->gameDaysElapsed << std::endl;
		saveOFile << this->currentSeason << std::endl;

		saveOFile.close();
	}
	else {
		throw("ERROR::GameState::save_inGameTime::FILE_NOT_OPEN");
	}
}

void GameState::save_player(){
	sf::Vector2f playerPosition = this->player->getPosition();
	std::string playerPath = this->savePath + "/game/player/info.txt";
	std::ofstream saveOFile(playerPath);
	if (saveOFile.is_open()) {
		//shranjevanje
		saveOFile << playerPosition.x << std::endl;
		saveOFile << playerPosition.y << std::endl;

		saveOFile.close();
	}
	else {
		throw("ERROR::GameState::save_player::FILE_NOT_OPEN");
	}
	this->player->save(this->savePath + "/game/player");
}

void GameState::save_items(){
	Inventory* inv = this->player->getInventory();
	std::ofstream saveOFile(this->savePath + "/game/items/itemsList.txt", std::ios::out | std::ios::trunc);
	for (int i = 0; i < inv->maxSize(); i++) {
		if (inv->hasItem(i)) {
			//ce je tam item ga shrani
			std::string tempSave = this->savePath + "/game/items/item" + std::to_string(i) + ".txt";
			inv->getItem(i)->saveToFile(tempSave);
			if (inv->getItem(i)->getID() == "ITEM_TOOL_HOE") {
				saveOFile << "Hoe" << " " << std::to_string(i) << std::endl;
				continue;
			}
			if (inv->getItem(i)->getID() == "ITEM_TOOL_CARROTSEED") {
				saveOFile << "CarrotSeed" << " " << std::to_string(i) << std::endl;
				continue;
			}
			if (inv->getItem(i)->getID() == "ITEM_TOOL_POTATOSEED") {
				saveOFile << "PotatoSeed" << " " << std::to_string(i) << std::endl;
				continue;
			}
			if (inv->getItem(i)->getID() == "ITEM_VEGISE_CARROT") {
				saveOFile << "Carrot" << " " << std::to_string(i) << std::endl;
				continue;
			}
			if (inv->getItem(i)->getID() == "ITEM_VEGISE_POTATO") {
				saveOFile << "Potato" << " " << std::to_string(i) << std::endl;
				continue;
			}
			if (inv->getItem(i)->getID() == "ITEM_TOOL_BUILDPLAN") {
				saveOFile << "BuildPlan" << " " << std::to_string(i) << std::endl;
				continue;
			}
			if (inv->getItem(i)->getID() == "ITEM_ANIMALS_COW") {
				saveOFile << "Cow" << " " << std::to_string(i) << std::endl;
				continue;
			}
			if (inv->getItem(i)->getID() == "ITEM_MILK") {
				saveOFile << "Milk" << " " << std::to_string(i) << std::endl;
				continue;
			}
			if (inv->getItem(i)->getID() == "ITEM_BACON") {
				saveOFile << "Bacon" << " " << std::to_string(i) << std::endl;
				continue;
			}
			if (inv->getItem(i)->getID() == "ITEM_ANIMALS_PIG") {
				saveOFile << "Pig" << " " << std::to_string(i) << std::endl;
				continue;
			}
			if (inv->getItem(i)->getID() == "ITEM_EGG") {
				saveOFile << "Egg" << " " << std::to_string(i) << std::endl;
				continue;
			}
			if (inv->getItem(i)->getID() == "ITEM_ANIMALS_CHICKEN") {
				saveOFile << "Chicken" << " " << std::to_string(i) << std::endl;
				continue;
			}
			std::cout << "Game state save mors popraut" << std::endl;
		}
	}
	saveOFile.close();
}

void GameState::save_buildings(){
	std::ofstream saveOFile(this->savePath + "/game/buildings/buildingsList.txt");
	int id = 0;
	for (const auto& pair : this->buildings) {
		if (pair.first == "Market")continue;
		saveOFile << pair.first << std::endl;
		for (const auto& value : pair.second) {
			value.second->saveToFile(this->savePath + "/game/buildings/"+ pair.first + std::to_string(id) +".txt");
			id++;
		}
		saveOFile << id << std::endl;
		id = 0;
	}
	saveOFile.close();
}

void GameState::save(){
	this->createSaveDir();
	//klièe vse funkcije za shranjevanje
	this->save_inGameTime();
	this->save_misc();
	this->save_player();
	this->save_items();
	this->save_buildings();
}

void GameState::updateHours_Minutes(){
	if (this->minutesTimer.getElapsedTime().asSeconds() >= this->minutesTimerMax) {
		//spreminjanje minut
		if (this->inGameTime_Minutes + 1 == 60) { //ce je poteklu 60min dodaje eno uro
			this->inGameTime_Minutes = 0;
			if (this->inGameTime_Hours + 1 == 24) { //ce potece 24 ur doda en dan
				this->inGameTime_Hours = 0;
				this->gameDaysElapsed++;
			}
			else this->inGameTime_Hours++;
		}
		else this->inGameTime_Minutes++;
		this->minutesTimer.restart();
	}
}

std::string whatTime() {
	auto time = std::chrono::system_clock::now();
	std::time_t end_time = std::chrono::system_clock::to_time_t(time);
	return std::string(std::ctime(&end_time));
}

//Konstruktor / destruktor
GameState::GameState(StateData* state_data,Game*game, unsigned short save) : State(state_data){
	this->initTextures();
	this->savePath = "Saves/save" + std::to_string(save);
	this->game = game;
	std::filesystem::path savefilePath = this->savePath + "/game";
	//preveri ce ze sploh obstaja save
	if (std::filesystem::exists(savefilePath))this->loadFromSave();
	else {
		//save se ne obstaja
		this->initVariables();
		this->initPlayers();
		this->creationDate = whatTime();
		this->initInGameTime();
		this->volume = 50;
	}
	//te se u sakmu primeru na novo kreairajo
	this->initDeferredRender();
	this->initView();
	this->initKeybinds();
	this->initFonts();
	this->initPauseMenu();
	this->initShaders();
	this->initKeyTime();
	this->initPlayerGUI();
	this->initTileMap();
	this->initInGameTimers();
	this->isInventoryOpen = false;
	this->playerGUI->updateINV(this->mousePosWindow); //sam enkrat rabm za hb kazat
	this->hasItemInHand = false;
	this->lastMouseStateR = false;
	this->initMarket();
	this->isShopOpen = false;
	this->initAudio();
}

GameState::~GameState(){
	delete this->pmenu;
	delete this->player;
	delete this->playerGUI;
	delete this->tileMap;
	delete Plant::textureSheet;
	delete CarrotPlant::possible;
	delete Building::textureSheet;
	delete PotatoPlant::possible;
	delete Building::numbers09;
	std::ifstream saveIFile("Config/audio.ini");
	bool isPlaying = false;
	if (saveIFile.is_open()) {
		saveIFile >> isPlaying;
		saveIFile.close();
	}
	if (isPlaying)this->game->playTheme();
}

const bool GameState::getKeyTime(){	
	if (this->keyTimer.getElapsedTime().asSeconds() >= this->keyTimeMax){
		this->keyTimer.restart();
		return true;
	}

	return false;	
}

//Funkcija
void GameState::updateView(const float & dt){
	this->view.setCenter(
		std::floor(this->player->getPosition().x + (static_cast<float>(this->mousePosWindow.x) - static_cast<float>(this->stateData->gfxSettings->resolution.width / 2)) / 10.f),
		std::floor(this->player->getPosition().y + (static_cast<float>(this->mousePosWindow.y) - static_cast<float>(this->stateData->gfxSettings->resolution.height / 2)) / 10.f)
	);

	if (this->tileMap->getMaxSizeF().x >= this->view.getSize().x){
		if (this->view.getCenter().x - this->view.getSize().x / 2.f < 0.f){
			this->view.setCenter(0.f + this->view.getSize().x / 2.f, this->view.getCenter().y);
		}
		else if (this->view.getCenter().x + this->view.getSize().x / 2.f > this->tileMap->getMaxSizeF().x){
			this->view.setCenter(this->tileMap->getMaxSizeF().x - this->view.getSize().x / 2.f, this->view.getCenter().y);
		}
	}

	if (this->tileMap->getMaxSizeF().y >= this->view.getSize().y){
		if (this->view.getCenter().y - this->view.getSize().y / 2.f < 0.f){
			this->view.setCenter(this->view.getCenter().x, 0.f + this->view.getSize().y / 2.f);
		}
		else if (this->view.getCenter().y + this->view.getSize().y / 2.f > this->tileMap->getMaxSizeF().y){
			this->view.setCenter(this->view.getCenter().x, this->tileMap->getMaxSizeF().y - this->view.getSize().y / 2.f);
		}
	}

	this->viewGridPosition.x = static_cast<int>(this->view.getCenter().x) / static_cast<int>(this->stateData->gridSize);
	this->viewGridPosition.y = static_cast<int>(this->view.getCenter().y) / static_cast<int>(this->stateData->gridSize);
}

void GameState::updateInput(const float & dt){
	if (!this->isInventoryOpen) {
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))) && this->getKeytime()) {
			if (!this->paused)this->pauseState();
			else this->unpauseState();
			this->isShopOpen = false;
		}
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))) && this->getKeytime() && this->isInventoryOpen) {
		this->isInventoryOpen = false;
		this->paused = false;
	}
	//inventory
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("INVENTORY"))) &&
		this->keybindsTimes.at("INVENTORY").getElapsedTime().asSeconds() >= this->keyTimeMax && !this->isShopOpen) {
		this->keybindsTimes.at("INVENTORY").restart();
		//odpre inventory
		this->isInventoryOpen = !this->isInventoryOpen;
		this->paused = this->isInventoryOpen;
	}
}

void GameState::addCarrots() {
	Inventory* inv = this->player->getInventory();
	int a = std::rand() % 5 + 1;
	for (int i = 0; i < inv->maxSize(); i++) {
		if (inv->getItem(i) != nullptr && inv->getItem(i)->getID() == "ITEM_VEGISE_CARROT") {
			Carrot* carr = static_cast<Carrot*>(inv->getItem(i));
			if (!carr->isFull()) {
				a = carr->addAmount(a);
				if (a == 0)break;
			}
		}
	}
	if (a != 0 && !inv->isFull())inv->add(new Carrot(&this->textures["carrot"], a));
}

void GameState::addPotatos(){
	Inventory* inv = this->player->getInventory();
	int a = std::rand() % 9 + 1;
	for (int i = 0; i < inv->maxSize(); i++) {
		if (inv->getItem(i) != nullptr && inv->getItem(i)->getID() == "ITEM_VEGISE_POTATO") {
			Potato* pot = static_cast<Potato*>(inv->getItem(i));
			if (!pot->isFull()) {
				a = pot->addAmount(a);
				if (a == 0)break;
			}
		}
	}
	if (a != 0 && !inv->isFull())inv->add(new Potato(&this->textures["potato"], a));
}

void GameState::changeToDay(){
	if (this->inGameTime_Hours < 24 && this->inGameTime_Hours > 9)this->gameDaysElapsed++;
	this->inGameTime_Hours = this->whenIsDayHour;
	this->inGameTime_Minutes = 0;
	this->updateInGameTime();
}

void GameState::updatePlayerInput(const float & dt){
	//Updata player input
	if (!this->player->useItem) { //ce uporabla item ne mors nc delat
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_LEFT"))))
			this->player->move(-1.f, 0.f, dt);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_RIGHT"))))
			this->player->move(1.f, 0.f, dt);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_UP")))) {
			this->player->move(0.f, -1.f, dt);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_DOWN")))) {
			this->player->move(0.f, 1.f, dt);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("ZOOM"))) &&
			this->keybindsTimes.at("ZOOM").getElapsedTime().asSeconds() >= this->keyTimeMax) {
			//ta drug pogoj sam preverja da ne spemas zooma
			this->keybindsTimes.at("ZOOM").restart();
			if (this->isZoomedOut) {
				//zoom in
				this->view.zoom(0.5f);
				this->player->setNewMaxVelocity(100.f);
			}
			else {
				//zoom out
				this->view.zoom(2.f);
				this->player->setNewMaxVelocity(140.f);
			}
			this->isZoomedOut = !this->isZoomedOut;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("HB1")))) {
			this->player->getInventory()->setSelectedHB(0);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("HB2")))) {
			this->player->getInventory()->setSelectedHB(1);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("HB3")))) {
			this->player->getInventory()->setSelectedHB(2);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("HB4")))) {
			this->player->getInventory()->setSelectedHB(3);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("HB5")))) {
			this->player->getInventory()->setSelectedHB(4);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("HB6")))) {
			this->player->getInventory()->setSelectedHB(5);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("HB7")))) {
			this->player->getInventory()->setSelectedHB(6);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("HB8")))) {
			this->player->getInventory()->setSelectedHB(7);
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("HB9")))) {
			this->player->getInventory()->setSelectedHB(8);
		}
		if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
			if (this->player->getDamageTimer()) {
				if (!this->player->useItem) {
					//uporabi item
					if (this->iteminHand == "hoe")this->useHoe();
					else if (this->iteminHand == "carrotSeed")this->useCarrotSeed();
					else if (this->iteminHand == "buildplan") this->useBuildPlan();
					else if (this->iteminHand == "potatoSeed")this->usePotatoSeed();
				}
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("PICKUP"))) &&
			this->keybindsTimes.at("PICKUP").getElapsedTime().asSeconds() >= this->keyTimeMax) {
			this->keybindsTimes.at("PICKUP").restart(); //da ne spemas
			//prever za market ==================
			if (static_cast<Market*>(this->buildings["Market"][0])->isInteractable(this->player)) {
				this->isShopOpen = true;
				this->paused = true;
			}
			// =============================
			else {
				//prever za pobrat carrote =======================================
				auto it = this->buildings["carrotPlant"].begin(); // Get the iterator to the beginning of the map
				while (it != this->buildings["carrotPlant"].end()) { // Iterate through the map
					CarrotPlant* tmp = static_cast<CarrotPlant*>(it->second);
					if (tmp->isPickable(this->player) && !this->player->getInventory()->isFull()) {
						if (!tmp->isDead())addCarrots();
						delete it->second; // Delete the object
						it = this->buildings["carrotPlant"].erase(it); // Remove the element from the map and advance the iterator
					}
					else {
						++it; // Move to the next element in the map
					}
				}
				//======================================
				//prever za pobrat potato =======================================
				it = this->buildings["potatoPlant"].begin(); // Get the iterator to the beginning of the map
				while (it != this->buildings["potatoPlant"].end()) { // Iterate through the map
					PotatoPlant* tmp = static_cast<PotatoPlant*>(it->second);
					if (tmp->isPickable(this->player) && !this->player->getInventory()->isFull()) {
						if (!tmp->isDead())this->addPotatos();
						delete it->second; // Delete the object
						it = this->buildings["potatoPlant"].erase(it); // Remove the element from the map and advance the iterator
					}
					else {
						++it; // Move to the next element in the map
					}
				}
				//======================================
			}
			//prever za house ===============================
			auto it = this->buildings["SmallHouse"].begin(); // Get the iterator to the beginning of the map
			while (it != this->buildings["SmallHouse"].end()) { // Iterate through the map
				SmallHouse* tmp = static_cast<SmallHouse*>(it->second);
				if (tmp->isInteractable(this->player)) {
					this->changeToDay();
				}
				++it; // Move to the next element in the map
			}
			it = this->buildings["MediumHouse"].begin(); // Get the iterator to the beginning of the map
			while (it != this->buildings["MediumHouse"].end()) { // Iterate through the map
				MediumHouse* tmp = static_cast<MediumHouse*>(it->second);
				if (tmp->isInteractable(this->player)) {
					this->changeToDay();
				}
				++it; // Move to the next element in the map
			}
			// ======================================
			//prever za cowBarn ===============================
			it = this->buildings["CowBarn"].begin(); // Get the iterator to the beginning of the map
			while (it != this->buildings["CowBarn"].end()) { // Iterate through the map
				CowBarn* tmp = static_cast<CowBarn*>(it->second);
				if (tmp->isInteractable(this->player)) {
					if (tmp->Milk()) {
						Inventory* inv = this->player->getInventory();
						tmp->takeMilk();
						for (int i = 0; i < inv->maxSize(); i++) {
							if (inv->hasItem(i) && inv->getItem(i)->getID() == "ITEM_MILK") {
								Milk* milk = static_cast<Milk*>(inv->getItem(i));
								if (!milk->isFull()) {
									milk->addAmount(1);
									return;
								}
							}
						}
						if(!inv->isFull())inv->add(new Milk(&this->textures["milk"], 1));
					}
					else {
						if (!tmp->isFull()) {
							Inventory* inv = this->player->getInventory();
							for (int i = 0; i < inv->maxSize(); i++) {
								if (inv->hasItem(i) && inv->getItem(i)->getID() == "ITEM_ANIMALS_COW") {
									Cow* cow = static_cast<Cow*>(inv->getItem(i));
									int ostanek = tmp->addCows(cow->getAmount());
									cow->setAmount(ostanek);
									return;
								}
							}
						}
					}
				}
				++it; // Move to the next element in the map
			}
			// ======================================
			//prever za pigBarn ===============================
			it = this->buildings["PigBarn"].begin(); // Get the iterator to the beginning of the map
			while (it != this->buildings["PigBarn"].end()) { // Iterate through the map
				PigBarn* tmp = static_cast<PigBarn*>(it->second);
				if (tmp->isInteractable(this->player)) {
					if (tmp->Bacon()) {
						Inventory* inv = this->player->getInventory();
						tmp->takeBacon();
						for (int i = 0; i < inv->maxSize(); i++) {
							if (inv->hasItem(i) && inv->getItem(i)->getID() == "ITEM_BACON") {
								Bacon* bacon = static_cast<Bacon*>(inv->getItem(i));
								if (!bacon->isFull()) {
									bacon->addAmount(1);
									return;
								}
							}
						}
						if (!inv->isFull())inv->add(new Bacon(&this->textures["bacon"], 1));
					}
					else {
						if (!tmp->isFull()) {
							Inventory* inv = this->player->getInventory();
							for (int i = 0; i < inv->maxSize(); i++) {
								if (inv->hasItem(i) && inv->getItem(i)->getID() == "ITEM_ANIMALS_PIG") {
									Pig* pig = static_cast<Pig*>(inv->getItem(i));
									int ostanek = tmp->addPigs(pig->getAmount());
									pig->setAmount(ostanek);
									return;
								}
							}
						}
					}
				}
				++it; // Move to the next element in the map
			}
			// ======================================
			//prever za chickenCoop ===============================
			it = this->buildings["ChickenCoop"].begin(); // Get the iterator to the beginning of the map
			while (it != this->buildings["ChickenCoop"].end()) { // Iterate through the map
				ChickenCoop* tmp = static_cast<ChickenCoop*>(it->second);
				if (tmp->isInteractable(this->player)) {
					if (tmp->Egg()) {
						Inventory* inv = this->player->getInventory();
						tmp->takeEgg();
						for (int i = 0; i < inv->maxSize(); i++) {
							if (inv->hasItem(i) && inv->getItem(i)->getID() == "ITEM_EGG") {
								Egg* egg = static_cast<Egg*>(inv->getItem(i));
								if (!egg->isFull()) {
									egg->addAmount(1);
									return;
								}
							}
						}
						if (!inv->isFull())inv->add(new Egg(&this->textures["egg"], 1));
					}
					else {
						if (!tmp->isFull()) {
							Inventory* inv = this->player->getInventory();
							for (int i = 0; i < inv->maxSize(); i++) {
								if (inv->hasItem(i) && inv->getItem(i)->getID() == "ITEM_ANIMALS_CHICKEN") {
									Chicken* chi = static_cast<Chicken*>(inv->getItem(i));
									int ostanek = tmp->addChickens(chi->getAmount());
									chi->setAmount(ostanek);
									return;
								}
							}
						}
					}
				}
				++it; // Move to the next element in the map
			}
			// ======================================
		}
		if (this->player->itemInHand == "buildplan") { //CHANGE_SELECTOR
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CHANGE_SELECTOR"))) &&
				this->keybindsTimes.at("CHANGE_SELECTOR").getElapsedTime().asSeconds() >= this->keyTimeMax) {
				this->keybindsTimes.at("CHANGE_SELECTOR").restart();
				//spremeni selection
				this->playerGUI->moveSelector();
			}
		}
	}
}

void GameState::useHoe(){
	Item* item = this->player->getInventory()->getHBSelectedItem();
	Tool* tool = static_cast<Tool*>(item);
	if (this->playerGUI->getIsPlaceble()) {
		//uporabi item ==============================
		this->player->useItem = true;
		//dobi id
		int id = 0;
		if (!this->buildings["farmland"].empty()) {
			auto zadn = this->buildings["farmland"].rbegin();
			id = zadn->first + 1;
		}
		//doda v mapo
		this->buildings["farmland"][id] = new Farmland(&this->textures["Farmland"], this->tileMap->getPosOfRectWithMousOver(this->mousePosView));
		//===========================================
		//mu odbije durability =====
		tool->damageDurability(2);
	}
}

void GameState::useCarrotSeed(){
	Item* item = this->player->getInventory()->getHBSelectedItem();
	Tool* tool = static_cast<Tool*>(item);
	if (this->playerGUI->getIsPlaceble()) {
		//uporabi item ==============================
		//dobi id
		int id = 0;
		if (!this->buildings["carrotPlant"].empty()) {
			auto zadn = this->buildings["carrotPlant"].rbegin();
			id = zadn->first + 1;
		}
		//doda v mapo
		this->buildings["carrotPlant"][id] = new CarrotPlant(this->tileMap->getPosOfRectWithMousOver(this->mousePosView));
		//===========================================
		//mu odbije durability =====
		tool->damageDurability(1);
	}
}

void GameState::usePotatoSeed(){
	Item* item = this->player->getInventory()->getHBSelectedItem();
	Tool* tool = static_cast<Tool*>(item);
	if (this->playerGUI->getIsPlaceble()) {
		//uporabi item ==============================
		//dobi id
		int id = 0;
		if (!this->buildings["potatoPlant"].empty()) {
			auto zadn = this->buildings["potatoPlant"].rbegin();
			id = zadn->first + 1;
		}
		//doda v mapo
		this->buildings["potatoPlant"][id] = new PotatoPlant(this->tileMap->getPosOfRectWithMousOver(this->mousePosView));
		//===========================================
		//mu odbije durability =====
		tool->damageDurability(1);
	}
}

void GameState::useBuildPlan(){
	if (this->playerGUI->getSelectorCanPlace()) { //prever veljavnost placanja
		int id = 0;
		switch (this->playerGUI->getSelectedBuilding()) { //ker building
		case 0:
			if (!this->player->getInventory()->hasEnoughMoney(1500))return;//preveri ce ma player zadosti denarja
			if (!this->buildings["SmallHouse"].empty()) {
				auto zadn = this->buildings["SmallHouse"].rbegin();
				id = zadn->first + 1;
			}
			this->buildings["SmallHouse"][id] = new SmallHouse(this->playerGUI->getSelectorPos());
			this->player->getInventory()->takeMoney(1500);
			break;
		case 1:
			if (!this->player->getInventory()->hasEnoughMoney(2500))return;//preveri ce ma player zadosti denarja
			if (!this->buildings["CowBarn"].empty()) {
				auto zadn = this->buildings["CowBarn"].rbegin();
				id = zadn->first + 1;
			}
			this->buildings["CowBarn"][id] = new CowBarn(this->playerGUI->getSelectorPos());
			this->player->getInventory()->takeMoney(2500);
			break;
		case 2:
			if (!this->player->getInventory()->hasEnoughMoney(2000))return;//preveri ce ma player zadosti denarja
			if (!this->buildings["MediumHouse"].empty()) {
				auto zadn = this->buildings["MediumHouse"].rbegin();
				id = zadn->first + 1;
			}
			this->buildings["MediumHouse"][id] = new MediumHouse(this->playerGUI->getSelectorPos());
			this->player->getInventory()->takeMoney(2000);
			break;
		case 3:
			if (!this->player->getInventory()->hasEnoughMoney(3000))return;//preveri ce ma player zadosti denarja
			if (!this->buildings["PigBarn"].empty()) {
				auto zadn = this->buildings["PigBarn"].rbegin();
				id = zadn->first + 1;
			}
			this->buildings["PigBarn"][id] = new PigBarn(this->playerGUI->getSelectorPos());
			this->player->getInventory()->takeMoney(3000);
			break;
		case 4:
			if (!this->player->getInventory()->hasEnoughMoney(3500))return;//preveri ce ma player zadosti denarja
			if (!this->buildings["ChickenCoop"].empty()) {
				auto zadn = this->buildings["ChickenCoop"].rbegin();
				id = zadn->first + 1;
			}
			this->buildings["ChickenCoop"][id] = new ChickenCoop(this->playerGUI->getSelectorPos());
			this->player->getInventory()->takeMoney(3500);
			break;
		}
	}
}

void GameState::updatePlayerGUI(const float & dt){
	this->playerGUI->update(dt);
	Item* equipedItem = this->player->getInventory()->getHBSelectedItem();
	if (equipedItem != nullptr) {
		this->hasItemInHand = true;
		if (equipedItem->getID() == "ITEM_TOOL_HOE") {
			//item je class hoe
			this->iteminHand = "hoe";
			this->player->itemInHand = this->iteminHand;
			return;
		}
		if (equipedItem->getID() == "ITEM_TOOL_CARROTSEED") {
			this->iteminHand = "carrotSeed";
			this->player->itemInHand = this->iteminHand;
			return;
		}
		if (equipedItem->getID() == "ITEM_TOOL_BUILDPLAN") {
			this->iteminHand = "buildplan";
			this->player->itemInHand = this->iteminHand;
			this->playerGUI->updateSelectorBP(this->tileMap,this->mousePosView,this->buildings);
			return;
		}
		if (equipedItem->getID() == "ITEM_TOOL_POTATOSEED") {
			this->iteminHand = "potatoSeed";
			this->player->itemInHand = this->iteminHand;
			this->playerGUI->updateSelectorBP(this->tileMap, this->mousePosView, this->buildings);
			return;
		}
	}
	else {
		this->hasItemInHand = false;
		this->player->itemInHand = "";
	}
}

void GameState::updatePauseMenuButtons(){
	if (this->pmenu->isButtonPressed("RESUME")) {
		this->pmenu->makeSound("RESUME");
		this->unpauseState();
	}
	if (this->pmenu->isButtonPressed("SAVE")) {
		this->pmenu->makeSound("SAVE");
		this->save();
	}
	if (this->pmenu->isButtonPressed("QUIT")) {
		this->pmenu->makeSound("QUIT");
		this->save();
		while (true)if (this->pmenu->getStatus("QUIT") == 0)break;
		this->endState();
	}
	//volume
	float v = this->pmenu->getSlider("Volume")->getValue();
	if (v != this->dayAudio.getVolume()) { //prever ce se je spremenil da mau spara resourse
		this->dayAudio.setVolume(v);
		this->nightAudio.setVolume(v);
		this->volume = v;
	}
}

void GameState::updateTileMap(const float & dt){
	this->tileMap->updateWorldBoundsCollision(this->player, dt); 
	this->tileMap->updateTileCollision(this->player, dt);
}

void GameState::updatePlayer(const float & dt){
	this->player->update(dt, this->mousePosView, this->view);
}

void GameState::updateDebugText(const float& dt){
	std::stringstream ss;

	ss << "Mouse Pos View: " << this->mousePosView.x << " " << this->mousePosView.y << "\n"
		<< "Active Enemies: " << 0 << "\n";
	this->debugText.setString(ss.str());
}

void GameState::updateInGameTime(){
	this->updateHours_Minutes();
	if (this->isDay && this->inGameTime_Hours == this->whenIsNightHour) {
		//dan se je koncau torej bo zdej noc
		this->isDay = false;
	}
	if (!(this->isDay) && this->inGameTime_Hours == this->whenIsDayHour) {
		this->isDay = true;
	}
	if ((this->gameDaysElapsed % 45) == 0 && this->gameDaysElapsed != 0) {
		//resetira dneve
		this->gameDaysElapsed = 0;
		//spremeni letni cas
		if (static_cast<int>(this->currentSeason) == 4)this->currentSeason = pomlad;
		else this->currentSeason = static_cast<letniCasi>(static_cast<int>(this->currentSeason) + 1);
		//posodobi dolzine dneva in noci in se mapo
		switch (this->currentSeason) {
		case pomlad:
			this->whenIsNightHour = 18; 
			this->whenIsDayHour = 6;
			delete this->tileMap;
			this->tileMap = new TileMap("Config/text.slmp", "Resources/Images/Tiles/newFloorTiles_Pomlad.png");
			break;
		case poletje:
			this->whenIsNightHour = 19; 
			this->whenIsDayHour = 5;
			delete this->tileMap;
			this->tileMap = new TileMap("Config/text.slmp", "Resources/Images/Tiles/newFloorTiles_Poletje.png");
			break;
		case jesen:
			this->whenIsNightHour = 18; 
			this->whenIsDayHour = 6;
			delete this->tileMap;
			this->tileMap = new TileMap("Config/text.slmp", "Resources/Images/Tiles/newFloorTiles_Jesen.png");
			break;
		case zima:
			this->whenIsNightHour = 17; 
			this->whenIsDayHour = 7; 
			delete this->tileMap;
			this->tileMap = new TileMap("Config/text.slmp", "Resources/Images/Tiles/newFloorTiles_Zima.png");
			break;
		}
	}
	this->playerGUI->updateClockDisplay(this->inGameTime_Hours, this->inGameTime_Minutes);
	this->playerGUI->updateSeasonDisplay(static_cast<int>(this->currentSeason));
	this->playerGUI->updateGameTimeDay(this->gameDaysElapsed);
}

void GameState::updateBuildingsColl(const float& dt){
	for (const auto& pair : this->buildings) {
		if (pair.first == "Market")continue;
		for (const auto& value : pair.second) {
			value.second->checkCollisionPlayer(this->player, dt);
		}
	}
	this->buildings["Market"][0]->checkCollisionPlayer(this->player, dt);
}

void GameState::updateBuildings() {
	for (const auto& pair : this->buildings) {
		if (pair.first == "Market")continue;
		if (pair.first == "SmallHouse") {
			for (const auto& value : pair.second) {
				static_cast<SmallHouse*>(value.second)->update(static_cast<int>(this->currentSeason), this->isDay, this->player);
			}
		}
		if (pair.first == "CowBarn") {
			for (const auto& value : pair.second) {
				static_cast<CowBarn*>(value.second)->update(static_cast<int>(this->currentSeason), this->isDay, this->player);
			}
		}
		if (pair.first == "MediumHouse") {
			for (const auto& value : pair.second) {
				static_cast<MediumHouse*>(value.second)->update(static_cast<int>(this->currentSeason), this->isDay, this->player);
			}
		}
		if (pair.first == "PigBarn") {
			for (const auto& value : pair.second) {
				static_cast<PigBarn*>(value.second)->update(static_cast<int>(this->currentSeason), this->isDay, this->player);
			}
		}
		if (pair.first == "ChickenCoop") {
			for (const auto& value : pair.second) {
				static_cast<ChickenCoop*>(value.second)->update(static_cast<int>(this->currentSeason), this->isDay, this->player);
			}
		}
		for (const auto& value : pair.second) {
			value.second->update();
		}
	}
	static_cast<Market*>(this->buildings["Market"][0])->update(static_cast<int>(this->currentSeason), this->isDay, this->player);
}

void GameState::updateItems(){
	if (!this->player->useItem) {
		Inventory* inv = this->player->getInventory();
		//items
		for (int i = 0; i < inv->maxSize(); i++) {
			if (inv->getItem(i) != nullptr) {
				std::string temp = inv->getItem(i)->getID();
				if (temp == "ITEM_TOOL_CARROTSEED" || temp == "ITEM_TOOL_HOE" || temp == "ITEM_TOOL_POTATOSEED") {
					//tooli imajo usi isto funkcijo
					Tool* tmp = static_cast<Tool*>(inv->getItem(i));
					if (tmp->getDurability() == 0) {
						inv->remove(i);
					}
				}
				else if (temp == "ITEM_VEGISE_CARROT") {
					Carrot* tmp = static_cast<Carrot*>(inv->getItem(i));
					if (tmp->getAmount() == 0) {
						inv->remove(i);
					}
				}
				else if (temp == "ITEM_VEGISE_POTATO") {
					Potato* tmp = static_cast<Potato*>(inv->getItem(i));
					if (tmp->getAmount() == 0) {
						inv->remove(i);
					}
				}
				else if (temp == "ITEM_ANIMALS_COW") {
					Cow* tmp = static_cast<Cow*>(inv->getItem(i));
					if (tmp->getAmount() == 0) {
						inv->remove(i);
					}
				}
				else if (temp == "ITEM_ANIMALS_PIG") {
					Pig* tmp = static_cast<Pig*>(inv->getItem(i));
					if (tmp->getAmount() == 0) {
						inv->remove(i);
					}
				}
				else if (temp == "ITEM_ANIMALS_CHICKEN") {
					Chicken* tmp = static_cast<Chicken*>(inv->getItem(i));
					if (tmp->getAmount() == 0) {
						inv->remove(i);
					}
				}
				else if (temp == "ITEM_EGG") {
					Egg* tmp = static_cast<Egg*>(inv->getItem(i));
					if (tmp->getAmount() == 0) {
						inv->remove(i);
					}
				}
				else if (temp == "ITEM_MILK") {
					Milk* tmp = static_cast<Milk*>(inv->getItem(i));
					if (tmp->getAmount() == 0) {
						inv->remove(i);
					}
				}
				else if (temp == "ITEM_BACON") {
					Bacon* tmp = static_cast<Bacon*>(inv->getItem(i));
					if (tmp->getAmount() == 0) {
						inv->remove(i);
					}
				}
			}
		}
	}
}

void GameState::update(const float& dt){
	this->updateMousePositions(&this->view);
	this->updateKeytime(dt);
	this->updateInput(dt);
	//this->updateDebugText(dt); //DEBUG
	if (!this->paused){ //Unpausan update
		this->updateAudio();

		this->updateView(dt);

		this->updatePlayerInput(dt);

		this->updateTileMap(dt);

		//buildings
		this->updateBuildingsColl(dt);
		this->updateBuildings();

		this->updatePlayer(dt);

		this->updateItems();

		this->updatePlayerGUI(dt);

		//updata inGametime
		this->updateInGameTime();


		//Items DEBUG =======================================


		if (this->hasItemInHand) {
			sf::Texture* possibleIcon = nullptr;
			if (this->iteminHand == "hoe") {
				possibleIcon = &this->textures["Farmland"];
			}
			if (this->iteminHand == "carrotSeed") {
				possibleIcon = CarrotPlant::possible;
			}
			if (this->iteminHand == "potatoSeed") {
				possibleIcon = PotatoPlant::possible;
			}
			this->playerGUI->updateItemPossibles(this->mousePosView, this->tileMap, possibleIcon, this->iteminHand,&this->buildings);
		}

		//===================================================

	}
	else{ //Pausan update
		if (!this->isInventoryOpen && !this->isShopOpen) {
			this->pmenu->update(this->mousePosWindow, dt);
			this->updatePauseMenuButtons();
		}
		else {
			if(this->isInventoryOpen)this->playerGUI->updateINV(this->mousePosWindow);
			if (this->isShopOpen)this->playerGUI->updateShop(this->mousePosWindow);
		}
	}
}

void GameState::render(sf::RenderTarget* target){
	if (!target)
		target = this->window;

	this->renderTexture.clear();

	this->renderTexture.setView(this->view);
	
	this->tileMap->render(
		this->renderTexture, 
		this->viewGridPosition,
		this->stateData->gfxSettings->resolution,
		this->isDay ? &this->temp : &this->core_shader,
		this->player->getCenter(),
		false, this->isZoomedOut
	);

	this->tileMap->renderDeferred(this->renderTexture, this->isDay ? &this->temp : &this->core_shader, this->player->getCenter());

	//buildings =======================================

	for (const auto& value : this->buildings["farmland"]) {
		value.second->render(&this->renderTexture, this->isDay ? &this->temp : &this->core_shader, this->player->getCenter());
	}
	for (const auto& value : this->buildings["carrotPlant"]) {
		value.second->render(&this->renderTexture, this->isDay ? &this->temp : &this->core_shader, this->player->getCenter());
	}
	for (const auto& value : this->buildings["potatoPlant"]) {
		value.second->render(&this->renderTexture, this->isDay ? &this->temp : &this->core_shader, this->player->getCenter());
	}
	
	//rendira buildinge ce je player zadi !!!!!!!!!!!!!!!!!!!!

	for (const auto& value : this->buildings["SmallHouse"]) {
		if (!static_cast<SmallHouse*>(value.second)->checkIfPlayerBehind(this->player)) {
			static_cast<SmallHouse*>(value.second)->render(&this->renderTexture);
		}
	}
	for (const auto& value : this->buildings["CowBarn"]) {
		if (!static_cast<CowBarn*>(value.second)->checkIfPlayerBehind(this->player)) {
			static_cast<CowBarn*>(value.second)->render(&this->renderTexture, this->isDay ? &this->temp : &this->core_shader, this->player->getCenter());
		}
	}
	for (const auto& value : this->buildings["MediumHouse"]) {
		if (!static_cast<MediumHouse*>(value.second)->checkIfPlayerBehind(this->player)) {
			static_cast<MediumHouse*>(value.second)->render(&this->renderTexture);
		}
	}
	for (const auto& value : this->buildings["PigBarn"]) {
		if (!static_cast<PigBarn*>(value.second)->checkIfPlayerBehind(this->player)) {
			static_cast<PigBarn*>(value.second)->render(&this->renderTexture, this->isDay ? &this->temp : &this->core_shader, this->player->getCenter());
		}
	}
	for (const auto& value : this->buildings["ChickenCoop"]) {
		if (!static_cast<ChickenCoop*>(value.second)->checkIfPlayerBehind(this->player)) {
			static_cast<ChickenCoop*>(value.second)->render(&this->renderTexture, this->isDay ? &this->temp : &this->core_shader, this->player->getCenter());
		}
	}

	if(!static_cast<Market*>(this->buildings["Market"][0])->checkIfPlayerBehind(this->player))static_cast<Market*>(this->buildings["Market"][0])->render(&this->renderTexture, this->isDay ? &this->temp : &this->core_shader, this->player->getCenter());

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//==============================================

	//Items DEBUG =======================================

	if (this->hasItemInHand) {
		this->playerGUI->renderItemPossibles(this->renderTexture);
	}
	if (this->player->itemInHand == "buildplan")this->playerGUI->renderSelectorBP(this->renderTexture);
	//===================================================


	this->player->render(this->renderTexture, this->isDay ? &this->temp : &this->core_shader, this->player->getCenter(), false); // ta zadna je za rendiranje hitboxa k je debug sam

	//rendira ce je player odspredi !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	for (const auto& value : this->buildings["SmallHouse"]) {
		if (static_cast<SmallHouse*>(value.second)->checkIfPlayerBehind(this->player)) {
			static_cast<SmallHouse*>(value.second)->render(&this->renderTexture);
		}
	}
	for (const auto& value : this->buildings["CowBarn"]) {
		if (static_cast<CowBarn*>(value.second)->checkIfPlayerBehind(this->player)) {
			static_cast<CowBarn*>(value.second)->render(&this->renderTexture, this->isDay ? &this->temp : &this->core_shader, this->player->getCenter());
		}
	}
	for (const auto& value : this->buildings["MediumHouse"]) {
		if (static_cast<MediumHouse*>(value.second)->checkIfPlayerBehind(this->player)) {
			static_cast<MediumHouse*>(value.second)->render(&this->renderTexture);
		}
	}
	for (const auto& value : this->buildings["PigBarn"]) {
		if (static_cast<PigBarn*>(value.second)->checkIfPlayerBehind(this->player)) {
			static_cast<PigBarn*>(value.second)->render(&this->renderTexture, this->isDay ? &this->temp : &this->core_shader, this->player->getCenter());
		}
	}
	for (const auto& value : this->buildings["ChickenCoop"]) {
		if (static_cast<ChickenCoop*>(value.second)->checkIfPlayerBehind(this->player)) {
			static_cast<ChickenCoop*>(value.second)->render(&this->renderTexture, this->isDay ? &this->temp : &this->core_shader, this->player->getCenter());
		}
	}

	if (static_cast<Market*>(this->buildings["Market"][0])->checkIfPlayerBehind(this->player))static_cast<Market*>(this->buildings["Market"][0])->render(&this->renderTexture, this->isDay ? &this->temp : &this->core_shader, this->player->getCenter());

	//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

	//Rendera GUI
	this->renderTexture.setView(this->renderTexture.getDefaultView());
	this->playerGUI->render(this->renderTexture);

	if (this->isInventoryOpen) {
		this->playerGUI->renderINV(this->renderTexture);
	}
	if (this->isShopOpen) {
		this->playerGUI->renderShop(this->renderTexture);
	}
	if (this->paused && !this->isInventoryOpen && !this->isShopOpen){
		this->pmenu->render(this->renderTexture);
	}

	//this->renderTexture.draw(this->debugText);

	//Koncni render
	this->renderTexture.display();
	target->draw(this->renderSprite);
}