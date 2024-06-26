#include "stdafx.h"
#include "EditorState.h"

//Inicializacija
void EditorState::initVariables(){
	this->cameraSpeed = 500.f; //morde 1000.f
}

void EditorState::initEditorStateData(){
	this->editorStateData.view = &this->view;
	this->editorStateData.font = &this->font;
	this->editorStateData.keytime = &this->keytime;
	this->editorStateData.keytimeMax = &this->keytimeMax;
	this->editorStateData.keybinds = &this->keybinds;
	this->editorStateData.mousePosGrid = &this->mousePosGrid;
	this->editorStateData.mousePosScreen = &this->mousePosScreen;
	this->editorStateData.mousePosView = &this->mousePosView;
	this->editorStateData.mousePosWindow = &this->mousePosWindow;
}

void EditorState::initView(){
	this->view.setSize(
		sf::Vector2f(
			static_cast<float>(this->stateData->gfxSettings->resolution.width),
			static_cast<float>(this->stateData->gfxSettings->resolution.height)
		)
	);

	this->view.setCenter(
		static_cast<float>(this->stateData->gfxSettings->resolution.width) / 2.f,
		static_cast<float>(this->stateData->gfxSettings->resolution.height) / 2.f
	);

	this->view.zoom(0.25f); //morde 0.5f
}

void EditorState::initFonts(){
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf")){
		throw("ERROR::EDITORSTATE::COULD NOT LOAD FONT");
	}
}

void EditorState::initKeybinds(){
	std::ifstream ifs("Config/editorstate_keybinds.ini");

	if (ifs.is_open()){
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2){
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}

	ifs.close();
}

void EditorState::initPauseMenu(){
	const sf::VideoMode& vm = this->stateData->gfxSettings->resolution;
	this->pmenu = new PauseMenu(this->stateData->gfxSettings->resolution, this->font);

	this->pmenu->addButton("QUIT", gui::p2pY(74.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), gui::calcCharSize(vm), "Quit");
	this->pmenu->addButton("SAVE", gui::p2pY(36.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), gui::calcCharSize(vm), "Save");
	this->pmenu->addButton("LOAD", gui::p2pY(27.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm), gui::calcCharSize(vm), "Load");

	std::vector<std::string> modes_str;
	modes_str.push_back("POMLAD");
	modes_str.push_back("POLETJE");
	modes_str.push_back("JESEN");
	modes_str.push_back("ZIMA");

	this->pmenu->addDropDownList("SEASON", gui::p2pY(45.f, vm), gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),modes_str.data(), modes_str.size());
}

void EditorState::initTileMap(){
	this->tileMap = new TileMap(this->stateData->gridSize, 100, 100, "Resources/Images/Tiles/newFloorTiles_Pomlad.png");
}

void EditorState::initModes(){
	this->mode =new DefaultEditorMode(this->stateData, this->tileMap, &this->editorStateData);
}

EditorState::EditorState(StateData* state_data) : State(state_data){
	this->initVariables();
	this->initEditorStateData();
	this->initView();
	this->initFonts();
	this->initKeybinds();
	this->initPauseMenu();
	this->initTileMap();
	this->initModes();
}

EditorState::~EditorState(){

	delete this->pmenu;

	delete this->tileMap;

	delete this->mode;
}

//Funkcije
void EditorState::updateInput(const float & dt){
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("CLOSE"))) && this->getKeytime()){
		if (!this->paused)
			this->pauseState();
		else
			this->unpauseState();
	}
}

void EditorState::updateEditorInput(const float& dt){
	//Premakne pogled
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_CAMERA_UP")))){
		this->view.move(0.f, -this->cameraSpeed * dt);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_CAMERA_DOWN")))){
		this->view.move(0.f, this->cameraSpeed * dt);
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_CAMERA_LEFT")))){
		this->view.move(-this->cameraSpeed * dt, 0.f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key(this->keybinds.at("MOVE_CAMERA_RIGHT")))){
		this->view.move(this->cameraSpeed * dt, 0.f);
	}
}

void EditorState::updatePauseMenuButtons(){
	if (this->pmenu->isButtonPressed("QUIT")) {
		this->pmenu->makeSound("QUIT");
		while (true)if (this->pmenu->getStatus("QUIT") == 0)break;
		this->endState();
	}
	if (this->pmenu->isButtonPressed("SAVE")) {
		this->pmenu->makeSound("SAVE");
		this->tileMap->saveToFile("Config/map.slmp");
	}
	if (this->pmenu->isButtonPressed("LOAD")) {
		this->pmenu->makeSound("LOAD");
		std::string textureFile;
		switch (this->pmenu->getDropDownList("SEASON")->getActiveElementId()) {
		case 0:
			textureFile = "Resources/Images/Tiles/newFloorTiles_Pomlad.png";
			break;
		case 1:
			textureFile = "Resources/Images/Tiles/newFloorTiles_Poletje.png";
			break;
		case 2:
			textureFile = "Resources/Images/Tiles/newFloorTiles_Jesen.png";
			break;
		case 3:
			textureFile = "Resources/Images/Tiles/newFloorTiles_Zima.png";
			break;
		default:textureFile = "Resources/Images/Tiles/newFloorTiles_Pomlad.png";
		}
		this->tileMap->loadFromFile("Config/map.slmp",textureFile);
	}
}

void EditorState::updateModes(const float & dt){
	this->mode->update(dt);
}

void EditorState::update(const float& dt){
	this->updateMousePositions(&this->view);
	this->updateKeytime(dt);
	this->updateInput(dt);

	if (!this->paused){	
		this->updateEditorInput(dt);
		this->updateModes(dt);		
	}
	else{
		this->pmenu->update(this->mousePosWindow,dt);
		this->updatePauseMenuButtons();
	}
}

void EditorState::renderModes(sf::RenderTarget & target){
	this->mode->render(target);
}

void EditorState::render(sf::RenderTarget* target){
	if (!target)
		target = this->window;

	target->setView(this->view);
	this->tileMap->render(*target, this->mousePosGrid, this->stateData->gfxSettings->resolution,
	NULL, sf::Vector2f(), true);
	this->tileMap->renderDeferred(*target);

	target->setView(this->window->getDefaultView());

	this->renderModes(*target);

	if (this->paused){
		target->setView(this->window->getDefaultView());
		this->pmenu->render(*target);
	}	
}