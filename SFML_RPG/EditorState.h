#pragma once

#include "State.h"
#include "Gui.h"
#include "PauseMenu.h"
#include "TileMap.h"
#include "DefaultEditorMode.h"

class State;
class StateData;
class Gui;
class PauseMenu;
class TileMap;
class Tile;
class EditorMode;
class DefaultEditorMode;
class EditorStateData;

enum EditorModes {DEFAULT_EDITOR_MODE = 0};

class EditorState : public State{
private:
	//Lastnosti
	EditorStateData editorStateData;

	sf::View view;
	float cameraSpeed;

	sf::Font font;
	PauseMenu* pmenu;

	TileMap* tileMap;

	EditorMode* mode;

	//Privatne funkcije
	void initVariables();
	void initEditorStateData();
	void initView();
	void initFonts();
	void initKeybinds();
	void initPauseMenu();
	void initTileMap();
	void initModes();

public:
	EditorState(StateData* state_data);
	virtual ~EditorState();

	//Funkcije
	void updateInput(const float& dt);
	void updateEditorInput(const float& dt);
	void updatePauseMenuButtons();
	void updateModes(const float& dt);
	void update(const float& dt);
	void renderModes(sf::RenderTarget& target);
	void render(sf::RenderTarget* target = NULL);
};