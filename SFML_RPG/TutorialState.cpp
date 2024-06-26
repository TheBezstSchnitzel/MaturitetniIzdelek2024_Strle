#include "stdafx.h"
#include "TutorialState.h"

//SLIDE =====================================================

Slide::Slide(std::string title) : title(title){
}

Slide::~Slide(){
}

std::string Slide::getTitle(){
	return this->title;
}

void Slide::setText(std::string text){
	this->text = text;
}

std::string Slide::getText(){
	return this->text;
}


//TUTORIAL STATE ====================================================
void TutorialState::initFonts(){
	if (!this->font.loadFromFile("Fonts/Dosis-Light.ttf")) {
		throw("ERROR::TUTORIALSTATE::COULD NOT LOAD FONT");
	}
}

void TutorialState::initTextures(){
	//ozadje
	if (!this->backgroundTexture.loadFromFile("Resources/Images/Backgrounds/bg.png")) {
		throw "ERROR::MAIN_MENU_STATE::FAILED_TO_LOAD_BACKGROUND_TEXTURE";
	}
}

void TutorialState::initGui(){
	const sf::VideoMode& vm = this->stateData->gfxSettings->resolution;

	//Ozadje
	this->background.setSize(
		sf::Vector2f(
			static_cast<float>(vm.width),
			static_cast<float>(vm.height)
		)
	);

	this->background.setTexture(&this->backgroundTexture);

	//Ozadje za Gumbe
	this->btnBackground.setSize(
		sf::Vector2f(
			static_cast<float>(vm.width / 5),
			static_cast<float>(vm.height)
		)
	);

	this->btnBackground.setPosition(gui::p2pX(11.5f, vm), 0.f);
	this->btnBackground.setFillColor(sf::Color(10, 10, 10, 220));

	//Gumbi
	this->buttons["NEXT_SLIDE"] = new gui::Button(
		gui::p2pX(15.6f, vm), gui::p2pY(30.f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Next Slide", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
	
	this->buttons["PREVIOUS_SLIDE"] = new gui::Button(
		gui::p2pX(15.6f, vm), gui::p2pY(45.f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Previous Slide", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));
	
	this->buttons["EXIT_STATE"] = new gui::Button(
		gui::p2pX(15.6f, vm), gui::p2pY(75.f, vm),
		gui::p2pX(13.f, vm), gui::p2pY(6.f, vm),
		&this->font, "Back", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(100, 100, 100, 0), sf::Color(150, 150, 150, 0), sf::Color(20, 20, 20, 0));

	//ozdaje za info
	this->infoBackground.setSize(sf::Vector2f(gui::p2pX(60.f,vm), vm.height / 8 * 7));

	this->infoBackground.setPosition(gui::p2pX(36.5f, vm), vm.height / 16);
	this->infoBackground.setFillColor(sf::Color(168, 163, 148, 220));

	//title
	this->title.setFont(this->font);
	this->title.setPosition(sf::Vector2f(gui::p2pX(59.f, vm), gui::p2pY(8.f, vm)));
	this->title.setCharacterSize(gui::calcCharSize(vm, 40));
	this->title.setFillColor(sf::Color(255, 255, 255, 255));
	this->title.setString(this->slides[this->currSlide]->getTitle());

	//text
	this->infoText.setFont(this->font);
	this->infoText.setPosition(sf::Vector2f(gui::p2pX(40.f, vm), gui::p2pY(20.f, vm)));
	this->infoText.setCharacterSize(gui::calcCharSize(vm, 50));
	this->infoText.setFillColor(sf::Color(255, 255, 255, 255));
	this->infoText.setString(this->slides[this->currSlide]->getText());
}

void TutorialState::initKeybinds(){
	std::ifstream ifs("Config/mainmenustate_keybinds.ini");

	if (ifs.is_open()) {
		std::string key = "";
		std::string key2 = "";

		while (ifs >> key >> key2) {
			this->keybinds[key] = this->supportedKeys->at(key2);
		}
	}

	ifs.close();
}

void TutorialState::initSlides(){
	this->slides[0] = new Slide("BEFOR YOU PLAY");
	this->slides[0]->setText("Current map is very basic so it is suggested that\n\nyou customize it before playing.");
	this->slides[1] = new Slide("MOVEMENT");
	this->slides[1]->setText("W - MOVE UP \n\nS - MOVE DOWN \n\nA - MOVE LEFT\n\nD - MOVE RIGHT\n\n /SAME IN THE EDITOR/");
	this->slides[2] = new Slide("GAMEPLAY");
	this->slides[2]->setText("ESC - PAUSE \n\nG - INVENTORY \n\nV - ZOOM IN/OUT\n\nE - INTERACT\n\nRIGHT MOUSE BUTTON - USE ITEM");
	this->slides[3] = new Slide("GAMEPLAY 2");
	this->slides[3]->setText("1-9 - HOTBAR SLOTS 1-9 \n\nTAB - CHANGE EQUIPED ITEM OPTION\n\nTHE GOAL OF THIS GAME:\n\nbuild your own farm, and have fun doing it.\n\n");
	this->slides[4] = new Slide("HOW TO PLAY");
	this->slides[4]->setText("You start with a set of money that you can use in\n\na Market building to buy the equipment to start.\n\nUse hoe item to make farmland that u can use to\n\nplant seeds in. By using BuildPlan you can build\n\ndiffrent structures.");
	this->slides[5] = new Slide("STRUCTURES");
	this->slides[5]->setText("Plants - when grown can be picked up\n\nHouses - used to skip the night\n\nBarns - fill with pigs,cows => get products\n\nCoop - fill with chickens => get eggs\n\n");
	this->slides[6] = new Slide("EDITOR");
	this->slides[6]->setText("ESC - PAUSE\n\nC - COLLISION ON/OFF\n\nL - TILE LOCK\n\nRIGHT MOUSE BUTTON - REMOVE TILE\n\nLEFT MOUSE BUTTON - PLACE TILE");
	this->slides[7] = new Slide("EDITOR 2");
	this->slides[7]->setText("When you open editor you must first load the\n\nmap from pause menu, and same\n\nwhen changing seasons. When you are done you\n\nmust save the map from pause menu if you\n\nwant to use it.");
}

TutorialState::TutorialState(StateData* state_data, Game* game) : State(state_data), game(game) {
	this->initFonts();
	this->initTextures();
	this->initSlides();
	this->currSlide = 0;
	this->initGui();
}

TutorialState::~TutorialState(){
	auto it = this->buttons.begin();
	for (it = this->buttons.begin(); it != this->buttons.end(); ++it) {
		delete it->second;
	}
	for (int i = 0; i < 7; ++i) {
		delete this->slides[i];
		this->slides[i] = nullptr;
	}
}

void TutorialState::updateInput(const float& dt){
}

void TutorialState::updateButtons(){
	for (auto& it : this->buttons) {
		it.second->update(this->mousePosWindow);
	}
	//funkcijonalnost
	//Next 
	if (this->buttons["NEXT_SLIDE"]->isPressed()) {
		this->buttons["NEXT_SLIDE"]->makeSound();
		this->currSlide++;
		this->updateSlides();
	}
	//Prev 
	if (this->buttons["PREVIOUS_SLIDE"]->isPressed()) {
		this->buttons["PREVIOUS_SLIDE"]->makeSound();
		this->currSlide--;
		this->updateSlides();
	}
	//Exit
	if (this->buttons["EXIT_STATE"]->isPressed()) {
		this->buttons["EXIT_STATE"]->makeSound();
		while (true)if (this->buttons["EXIT_STATE"]->getStatus() == 0)break;
		this->endState();
	}
}

void TutorialState::updateSlides(){
	this->title.setString(this->slides[this->currSlide]->getTitle());
	this->infoText.setString(this->slides[this->currSlide]->getText());
}

void TutorialState::checkSlidesButtons(){
	if (this->currSlide == 0)this->buttons["PREVIOUS_SLIDE"]->disable();
	else this->buttons["PREVIOUS_SLIDE"]->enable();
	if (this->currSlide == 7)this->buttons["NEXT_SLIDE"]->disable();
	else this->buttons["NEXT_SLIDE"]->enable();
}

void TutorialState::update(const float& dt){
	this->updateMousePositions();
	this->checkSlidesButtons();
	this->updateButtons();
}

void TutorialState::renderButtons(sf::RenderTarget& target){
	for (auto& it : this->buttons) {
		it.second->render(target);
	}
}

void TutorialState::render(sf::RenderTarget* target){
	if (!target)
		target = this->window;
	
	target->draw(this->background);

	target->draw(this->btnBackground);

	target->draw(this->infoBackground);
	
	target->draw(this->title);

	target->draw(this->infoText);

	this->renderButtons(*target);
}