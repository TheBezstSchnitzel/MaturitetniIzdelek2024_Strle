#include "stdafx.h"
#include "PlayerGUI.h"

void PlayerGUI::initShopTextures(){
	if (!this->shopBasicTexture.loadFromFile("Resources/Images/Gui/shopBasic.png", sf::IntRect(sf::Vector2i(0, 3), sf::Vector2i(210, 124)))) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_ShopBasic_TEXTURE";
	}
	if (!this->shopPlantsSite.loadFromFile("Resources/Images/Gui/shopMenu_plants.png", sf::IntRect(sf::Vector2i(0, 3), sf::Vector2i(210, 124)))) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_shopPlants_TEXTURE";
	}
	if (!this->shopToolsSite.loadFromFile("Resources/Images/Gui/shopMenu_tools.png", sf::IntRect(sf::Vector2i(0, 3), sf::Vector2i(210, 124)))) {
		throw "ERROR::GAME_STATE::COULD_NOT_LOAD_shopPlants_TEXTURE";
	}
}

void PlayerGUI::initButtons(){
	this->buttonsShop["DownSlide"] = new gui::Button(
		gui::p2pX(28.5f, vm), gui::p2pY(13.f, vm),
		gui::p2pX(4.2f, vm), gui::p2pY(9.4f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 0), sf::Color(255, 255, 255, 0), sf::Color(20, 20, 20, 0),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
	);
	this->buttonsShop["UpSlide"] = new gui::Button(
		gui::p2pX(67.f, vm), gui::p2pY(13.f, vm),
		gui::p2pX(4.2f, vm), gui::p2pY(9.4f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
	);
	this->buttonsShop["Plus1"] = new gui::Button(
		gui::p2pX(30.9f, vm), gui::p2pY(31.9f, vm),
		gui::p2pX(2.f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//,sf::Color::Red,sf::Color::Red
	);
	this->buttonsShop["Plus2"] = new gui::Button(
		gui::p2pX(30.9f, vm), gui::p2pY(43.8f, vm),
		gui::p2pX(2.f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//,sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Plus3"] = new gui::Button(
		gui::p2pX(30.9f, vm), gui::p2pY(56.3f, vm),
		gui::p2pX(2.f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//,sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Plus4"] = new gui::Button(
		gui::p2pX(55.8f, vm), gui::p2pY(31.9f, vm),
		gui::p2pX(2.f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//,sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Plus5"] = new gui::Button(
		gui::p2pX(55.8f, vm), gui::p2pY(43.8f, vm),
		gui::p2pX(2.f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//,sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Plus6"] = new gui::Button(
		gui::p2pX(55.8f, vm), gui::p2pY(56.3f, vm),
		gui::p2pX(2.f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//,sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Minus1"] = new gui::Button(
		gui::p2pX(38.8f, vm), gui::p2pY(31.9f, vm),
		gui::p2pX(2.f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//,sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Minus2"] = new gui::Button(
		gui::p2pX(38.8f, vm), gui::p2pY(43.8f, vm),
		gui::p2pX(2.f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//,sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Minus3"] = new gui::Button(
		gui::p2pX(38.8f, vm), gui::p2pY(56.3f, vm),
		gui::p2pX(2.f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//,sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Minus4"] = new gui::Button(
		gui::p2pX(63.6f, vm), gui::p2pY(31.9f, vm),
		gui::p2pX(2.f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//,sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Minus5"] = new gui::Button(
		gui::p2pX(63.6f, vm), gui::p2pY(43.8f, vm),
		gui::p2pX(2.f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//,sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Minus6"] = new gui::Button(
		gui::p2pX(63.6f, vm), gui::p2pY(56.3f, vm),
		gui::p2pX(2.f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//,sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Buy1"] = new gui::Button(
		gui::p2pX(41.3f, vm), gui::p2pY(29.3f, vm),
		gui::p2pX(4.9f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//,sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Sell1"] = new gui::Button(
		gui::p2pX(41.3f, vm), gui::p2pY(33.9f, vm),
		gui::p2pX(4.9f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//, sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Buy2"] = new gui::Button(
		gui::p2pX(41.3f, vm), gui::p2pY(41.3f, vm),
		gui::p2pX(4.9f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//, sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Sell2"] = new gui::Button(
		gui::p2pX(41.3f, vm), gui::p2pY(45.9f, vm),
		gui::p2pX(4.9f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//, sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Buy3"] = new gui::Button(
		gui::p2pX(41.3f, vm), gui::p2pY(54.1f, vm),
		gui::p2pX(4.9f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//, sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Sell3"] = new gui::Button(
		gui::p2pX(41.3f, vm), gui::p2pY(58.7f, vm),
		gui::p2pX(4.9f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//, sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Buy4"] = new gui::Button(
		gui::p2pX(66.3f, vm), gui::p2pY(29.3f, vm),
		gui::p2pX(4.9f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//, sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Sell4"] = new gui::Button(
		gui::p2pX(66.3f, vm), gui::p2pY(33.9f, vm),
		gui::p2pX(4.9f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//, sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Buy5"] = new gui::Button(
		gui::p2pX(66.3f, vm), gui::p2pY(41.3f, vm),
		gui::p2pX(4.9f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//, sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Sell5"] = new gui::Button(
		gui::p2pX(66.3f, vm), gui::p2pY(45.9f, vm),
		gui::p2pX(4.9f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//, sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Buy6"] = new gui::Button(
		gui::p2pX(66.3f, vm), gui::p2pY(54.1f, vm),
		gui::p2pX(4.9f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//, sf::Color::Red, sf::Color::Red
	);
	this->buttonsShop["Sell6"] = new gui::Button(
		gui::p2pX(66.3f, vm), gui::p2pY(58.7f, vm),
		gui::p2pX(4.9f, vm), gui::p2pY(3.8f, vm),
		&this->font, "", gui::calcCharSize(vm),
		sf::Color(200, 200, 200, 200), sf::Color(255, 255, 255, 255), sf::Color(20, 20, 20, 50),
		sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0), sf::Color(255, 255, 255, 0)
		//, sf::Color::Red, sf::Color::Red
	);
	//66.3f
}

void PlayerGUI::initTexts(){
	this->texts["Amount1"].setCharacterSize(gui::calcCharSize(vm, 45U));
	this->texts["Amount1"].setPosition(sf::Vector2f(gui::p2pX(34.f,vm), gui::p2pY(29.8f,vm)));
	this->texts["Amount1"].setFont(font);
	this->texts["Amount1"].setFillColor(sf::Color::White);
	this->texts["Amount1"].setString("00");
	this->texts["Amount1"].setStyle(sf::Text::Bold);

	this->texts["Amount2"].setCharacterSize(gui::calcCharSize(vm, 45U));
	this->texts["Amount2"].setPosition(sf::Vector2f(gui::p2pX(34.f, vm), gui::p2pY(41.8f, vm)));
	this->texts["Amount2"].setFont(font);
	this->texts["Amount2"].setFillColor(sf::Color::White);
	this->texts["Amount2"].setString("00");
	this->texts["Amount2"].setStyle(sf::Text::Bold);

	this->texts["Amount3"].setCharacterSize(gui::calcCharSize(vm, 45U));
	this->texts["Amount3"].setPosition(sf::Vector2f(gui::p2pX(34.f, vm), gui::p2pY(54.5f, vm)));
	this->texts["Amount3"].setFont(font);
	this->texts["Amount3"].setFillColor(sf::Color::White);
	this->texts["Amount3"].setString("00");
	this->texts["Amount3"].setStyle(sf::Text::Bold);

	this->texts["Amount4"].setCharacterSize(gui::calcCharSize(vm, 45U));
	this->texts["Amount4"].setPosition(sf::Vector2f(gui::p2pX(59.f, vm), gui::p2pY(29.8f, vm)));
	this->texts["Amount4"].setFont(font);
	this->texts["Amount4"].setFillColor(sf::Color::White);
	this->texts["Amount4"].setString("00");
	this->texts["Amount4"].setStyle(sf::Text::Bold);

	this->texts["Amount5"].setCharacterSize(gui::calcCharSize(vm, 45U));
	this->texts["Amount5"].setPosition(sf::Vector2f(gui::p2pX(59.f, vm), gui::p2pY(41.8f, vm)));
	this->texts["Amount5"].setFont(font);
	this->texts["Amount5"].setFillColor(sf::Color::White);
	this->texts["Amount5"].setString("00");
	this->texts["Amount5"].setStyle(sf::Text::Bold);

	this->texts["Amount6"].setCharacterSize(gui::calcCharSize(vm, 45U));
	this->texts["Amount6"].setPosition(sf::Vector2f(gui::p2pX(59.f, vm), gui::p2pY(54.5f, vm)));
	this->texts["Amount6"].setFont(font);
	this->texts["Amount6"].setFillColor(sf::Color::White);
	this->texts["Amount6"].setString("00");
	this->texts["Amount6"].setStyle(sf::Text::Bold);

	this->texts["Price1"].setCharacterSize(gui::calcCharSize(vm, 100U));
	this->texts["Price1"].setPosition(sf::Vector2f(gui::p2pX(47.f, vm), gui::p2pY(31.8f, vm)));
	this->texts["Price1"].setFont(font);
	this->texts["Price1"].setFillColor(sf::Color::White);
	this->texts["Price1"].setString("00");
	this->texts["Price1"].setStyle(sf::Text::Bold);

	this->texts["Price2"].setCharacterSize(gui::calcCharSize(vm, 100U));
	this->texts["Price2"].setPosition(sf::Vector2f(gui::p2pX(47.f, vm), gui::p2pY(44.0f, vm)));
	this->texts["Price2"].setFont(font);
	this->texts["Price2"].setFillColor(sf::Color::White);
	this->texts["Price2"].setString("00");
	this->texts["Price2"].setStyle(sf::Text::Bold);

	this->texts["Price3"].setCharacterSize(gui::calcCharSize(vm, 100U));
	this->texts["Price3"].setPosition(sf::Vector2f(gui::p2pX(47.f, vm), gui::p2pY(56.6f, vm)));
	this->texts["Price3"].setFont(font);
	this->texts["Price3"].setFillColor(sf::Color::White);
	this->texts["Price3"].setString("00");
	this->texts["Price3"].setStyle(sf::Text::Bold);

	this->texts["Price4"].setCharacterSize(gui::calcCharSize(vm, 100U));
	this->texts["Price4"].setPosition(sf::Vector2f(gui::p2pX(72.f, vm), gui::p2pY(31.8f, vm)));
	this->texts["Price4"].setFont(font);
	this->texts["Price4"].setFillColor(sf::Color::White);
	this->texts["Price4"].setString("00");
	this->texts["Price4"].setStyle(sf::Text::Bold);

	this->texts["Price5"].setCharacterSize(gui::calcCharSize(vm, 100U));
	this->texts["Price5"].setPosition(sf::Vector2f(gui::p2pX(72.f, vm), gui::p2pY(44.0f, vm)));
	this->texts["Price5"].setFont(font);
	this->texts["Price5"].setFillColor(sf::Color::White);
	this->texts["Price5"].setString("00");
	this->texts["Price5"].setStyle(sf::Text::Bold);

	this->texts["Price6"].setCharacterSize(gui::calcCharSize(vm, 100U));
	this->texts["Price6"].setPosition(sf::Vector2f(gui::p2pX(72.f, vm), gui::p2pY(56.6f, vm)));
	this->texts["Price6"].setFont(font);
	this->texts["Price6"].setFillColor(sf::Color::White);
	this->texts["Price6"].setString("00");
	this->texts["Price6"].setStyle(sf::Text::Bold);
}

void PlayerGUI::initShop(){
	this->initShopTextures();
	this->basicShopRect.setFillColor(sf::Color::White);
	this->basicShopRect.setTexture(&this->shopBasicTexture);
	this->basicShopRect.setSize(sf::Vector2f(gui::p2pX(55.f, vm), gui::p2pY(60.f, vm)));
	this->basicShopRect.setPosition(sf::Vector2f(gui::p2pX(22.5f,vm), gui::p2pY(10.f,vm)));
	this->currShopSite = Plants;
	this->initButtons();
	this->siteShopRect = sf::RectangleShape(this->basicShopRect);
	this->initTexts();
}

void PlayerGUI::resetTexts(){
	this->texts["Amount1"].setString("00");
	this->texts["Amount2"].setString("00");
	this->texts["Amount3"].setString("00");
	this->texts["Amount4"].setString("00");
	this->texts["Amount5"].setString("00");
	this->texts["Amount6"].setString("00");
	this->texts["Price1"].setString("00");
	this->texts["Price2"].setString("00");
	this->texts["Price3"].setString("00");
	this->texts["Price4"].setString("00");
	this->texts["Price5"].setString("00");
	this->texts["Price6"].setString("00");
}

std::string PlayerGUI::addOne(std::string id){
	int i = std::stoi(this->texts[id].getString().toAnsiString());
	std::string temp = "";
	if(i != 60)i++;
	if (i < 10) {
		temp = "0" + std::to_string(i);
	}
	else temp = std::to_string(i);
	return temp;
}

std::string PlayerGUI::removeOne(std::string id){
	int i = std::stoi(this->texts[id].getString().toAnsiString());
	std::string temp = "";
	if (i != 0)i--;
	if (i < 10) {
		temp = "0" + std::to_string(i);
	}
	else temp = std::to_string(i);
	return temp;
}

bool PlayerGUI::buy(std::string what, int amount, int price){
	Inventory* inv = this->player->getInventory();
	if (inv->hasEnoughMoney(price)) {
		inv->takeMoney(price);
		int a = amount;
		int max = 0;
		std::string id = "";
		if (what == "Carrot") {
			max = 60;
			id = "ITEM_VEGISE_CARROT";
		}
		else if (what == "Potato") {
			max = 60;
			id = "ITEM_VEGISE_POTATO";
		}
		else if (what == "Hoe") {
			if (!inv->isFull()) {
				inv->add(new Hoe(&this->textures->at("HoeIcon"), a));
				return true;
			}
		}
		else if (what == "CarrotSeed") {
			max = 100;
			id = "ITEM_TOOL_CARROTSEED";
		}
		else if (what == "PotatoSeed") {
			max = 100;
			id = "ITEM_TOOL_POTATOSEED";
		}
		else if (what == "BuildPlan") {
			for (int j = 0; j < a; j++) {
				if (!inv->isFull()) {
					inv->add(new BuildPlan(&this->textures->at("BuildPlanIcon")));
				}
				else return false;
			}
			return true;
		}
		else if (what == "Cow") {
			max = 6;
			id = "ITEM_ANIMALS_COW";
		}
		else if (what == "Pig") {
			max = 8;
			id = "ITEM_ANIMALS_PIG";
		}
		else if (what == "Chicken") {
			max = 9;
			id = "ITEM_ANIMALS_CHICKEN";
		}
		else if (what == "Milk") {
			max = 6;
			id = "ITEM_MILK";
		}
		else if (what == "Bacon") {
			max = 9;
			id = "ITEM_BACON";
		}
		else if (what == "Egg") {
			max = 12;
			id = "ITEM_EGG";
		}

		for (int i = 0; i < inv->maxSize(); i++) {
			if (inv->getItem(i) != nullptr && inv->getItem(i)->getID() == id) {
				if (what == "Carrot") {
					Carrot* temp = static_cast<Carrot*>(inv->getItem(i));
					if (!temp->isFull()) {
						a = temp->addAmount(a);
						if (a == 0)return true;
					}
				}
				else if (what == "Potato") {
					Potato* temp = static_cast<Potato*>(inv->getItem(i));
					if (!temp->isFull()) {
						a = temp->addAmount(a);
						if (a == 0)return true;
					}
				}
				else if (what == "CarrotSeed") {
					CarrotSeed* temp = static_cast<CarrotSeed*>(inv->getItem(i));
					if (temp->getDurability() < max) {
						int c = 0;
						if ((max - temp->getDurability()) < a) {
							c = a - (max - temp->getDurability());
						}
						temp->healDurability(a);
						a = c;
						if(a == 0)return true;
					}
				}
				else if (what == "PotatoSeed") {
					PotatoSeed* temp = static_cast<PotatoSeed*>(inv->getItem(i));
					if (temp->getDurability() < max) {
						int c = 0;
						if ((max - temp->getDurability()) < a) {
							c = a - (max - temp->getDurability());
						}
						temp->healDurability(a);
						a = c;
						if (a == 0)return true;
					}
				}
				else if (what == "Cow") {
					Cow* temp = static_cast<Cow*>(inv->getItem(i));
					if (!temp->isFull()) {
						a = temp->addAmount(a);
						if (a == 0)return true;
					}
				}
				else if (what == "Pig") {
					Pig* temp = static_cast<Pig*>(inv->getItem(i));
					if (!temp->isFull()) {
						a = temp->addAmount(a);
						if (a == 0)return true;
					}
				}
				else if (what == "Chicken") {
					Chicken* temp = static_cast<Chicken*>(inv->getItem(i));
					if (!temp->isFull()) {
						a = temp->addAmount(a);
						if (a == 0)return true;
					}
				}
				else if (what == "Milk") {
					Milk* temp = static_cast<Milk*>(inv->getItem(i));
					if (!temp->isFull()) {
						a = temp->addAmount(a);
						if (a == 0)return true;
					}
				}
				else if (what == "Bacon") {
					Bacon* temp = static_cast<Bacon*>(inv->getItem(i));
					if (!temp->isFull()) {
						a = temp->addAmount(a);
						if (a == 0)return true;
					}
				}
				else if (what == "Egg") {
					Egg* temp = static_cast<Egg*>(inv->getItem(i));
					if (!temp->isFull()) {
						a = temp->addAmount(a);
						if (a == 0)return true;
					}
				}
			}
		}
		if (a != 0 && !inv->isFull()) {
			if (a <= max) {
				if (what == "Carrot")inv->add(new Carrot(&this->textures->at("carrot"), a));
				else if (what == "Potato")inv->add(new Potato(&this->textures->at("potato"), a));
				else if (what == "CarrotSeed")inv->add(new CarrotSeed(&this->textures->at("carrot_seed"), a));
				else if (what == "CarrotSeed")inv->add(new PotatoSeed(&this->textures->at("potato_seed"), a));
				else if (what == "Cow")inv->add(new Cow(&this->textures->at("cow"), a));
				else if (what == "Pig")inv->add(new Pig(&this->textures->at("pig"), a));
				else if (what == "Chicken")inv->add(new Chicken(&this->textures->at("chicken"), a));
				else if (what == "Milk")inv->add(new Milk(&this->textures->at("milk"), a));
				else if (what == "Bacon")inv->add(new Bacon(&this->textures->at("bacon"), a));
				else if (what == "Egg")inv->add(new Egg(&this->textures->at("egg"), a));
				return true;
			}
			else {
				for (; a == 0 && !inv->isFull();) {
					if (a / max != 0) {
						if (what == "Carrot")inv->add(new Carrot(&this->textures->at("carrot"), max));
						else if (what == "Potato")inv->add(new Potato(&this->textures->at("potato"), max));
						else if (what == "CarrotSeed")inv->add(new CarrotSeed(&this->textures->at("carrot_seed"), max));
						else if (what == "PotatoSeed")inv->add(new PotatoSeed(&this->textures->at("potato_seed"), max));
						else if (what == "Cow")inv->add(new Cow(&this->textures->at("cow"), max));
						else if (what == "Pig")inv->add(new Pig(&this->textures->at("pig"), max));
						else if (what == "Chicken")inv->add(new Chicken(&this->textures->at("chicken"), max));
						else if (what == "Milk")inv->add(new Milk(&this->textures->at("milk"), max));
						else if (what == "Bacon")inv->add(new Bacon(&this->textures->at("bacon"), max));
						else if (what == "Egg")inv->add(new Egg(&this->textures->at("egg"), max));
						a -= max;
					}
					else {
						if (what == "Carrot")inv->add(new Carrot(&this->textures->at("carrot"), a));
						else if (what == "Potato")inv->add(new Potato(&this->textures->at("potato"), a));
						else if (what == "CarrotSeed")inv->add(new CarrotSeed(&this->textures->at("carrot_seed"), a));
						else if (what == "PotatoSeed")inv->add(new PotatoSeed(&this->textures->at("potato_seed"), a));
						else if (what == "Cow")inv->add(new Cow(&this->textures->at("cow"), a));
						else if (what == "Pig")inv->add(new Pig(&this->textures->at("pig"), a));
						else if (what == "Chicken")inv->add(new Chicken(&this->textures->at("chicken"), a));
						else if (what == "Milk")inv->add(new Milk(&this->textures->at("milk"), a));
						else if (what == "Bacon")inv->add(new Bacon(&this->textures->at("bacon"), a));
						else if (what == "Egg")inv->add(new Egg(&this->textures->at("egg"), a));
						return true;
					}
				}
			}
		}

	}
	return false;
}

bool PlayerGUI::sell(std::string what, int amount, int price){
	std::string id = "";
	if (what == "Carrot") { 
		id = "ITEM_VEGISE_CARROT";
	}
	else if (what == "Potato") { 
		id = "ITEM_VEGISE_POTATO";
	}
	else if (what == "Hoe") {
		id = "ITEM_TOOL_HOE";
	}
	else if (what == "CarrotSeed") { 
		id = "ITEM_TOOL_CARROTSEED";
	}
	else if (what == "PotatoSeed") { 
		id = "ITEM_TOOL_POTATOSEED";
	}
	else if (what == "BuildPlan") {
		id = "ITEM_TOOL_BUILDPLAN";
	}
	else if (what == "Cow") { 
		id = "ITEM_ANIMALS_COW";
	}
	else if (what == "Pig") { 
		id = "ITEM_ANIMALS_PIG";
	}
	else if (what == "Chicken") { 
		id = "ITEM_ANIMALS_CHICKEN";
	}
	else if (what == "Milk") { 
		id = "ITEM_MILK";
	}
	else if (what == "Bacon") { 
		id = "ITEM_BACON";
	}
	else if (what == "Egg") { 
		id = "ITEM_EGG";
	}
	int a = amount;
	int has = 0;
	Inventory* inv = this->player->getInventory();
	for (int i = 0; i < inv->maxSize(); i++) {
		if (inv->hasItem(i)) {
			if (inv->getItem(i)->getID() == id) {
				if (what == "Carrot") {
					Carrot* temp = static_cast<Carrot*>(inv->getItem(i));
					has += temp->getAmount();
				}
				if (what == "Potato") {
					Potato* temp = static_cast<Potato*>(inv->getItem(i));
					has += temp->getAmount();
				}
				if (what == "CarrotSeed") {
					CarrotSeed* temp = static_cast<CarrotSeed*>(inv->getItem(i));
					has += temp->getDurability();
				}
				if (what == "PotatoSeed") {
					PotatoSeed* temp = static_cast<PotatoSeed*>(inv->getItem(i));
					has += temp->getDurability();
				}
				if (what == "Cow") {
					Cow* temp = static_cast<Cow*>(inv->getItem(i));
					has += temp->getAmount();
				}
				if (what == "Pig") {
					Pig* temp = static_cast<Pig*>(inv->getItem(i));
					has += temp->getAmount();
				}
				if (what == "Chicken") {
					Chicken* temp = static_cast<Chicken*>(inv->getItem(i));
					has += temp->getAmount();
				}
				if (what == "Milk") {
					Milk* temp = static_cast<Milk*>(inv->getItem(i));
					has += temp->getAmount();
				}
				if (what == "Bacon") {
					Bacon* temp = static_cast<Bacon*>(inv->getItem(i));
					has += temp->getAmount();
				}
				if (what == "Egg") {
					Egg* temp = static_cast<Egg*>(inv->getItem(i));
					has += temp->getAmount();
				}
				if (what == "Hoe") {
					has++;
				}
				if (what == "BuildPlan") {
					has++;
				}
			}
		}
	}
	if (has >= a) { //check ce ma zadost takih itemou
		for (int i = 0; i < inv->maxSize(); i++) {
			if (inv->hasItem(i)) {
				if (inv->getItem(i)->getID() == id) {
					if (what == "Carrot") {
						Carrot* temp = static_cast<Carrot*>(inv->getItem(i));
						a = temp->removeAmount(a);
						if (a == 0) {
							inv->addMoney(price);
							return true;
						}
					}
					if (what == "Potato") {
						Potato* temp = static_cast<Potato*>(inv->getItem(i));
						a = temp->removeAmount(a);
						if (a == 0) {
							inv->addMoney(price);
							return true;
						}
					}
					if (what == "CarrotSeed") {
						CarrotSeed* temp = static_cast<CarrotSeed*>(inv->getItem(i));
						int c = 0;
						if (temp->getDurability() < a) {
							c = a - temp->getDurability();
						}
						temp->damageDurability(a);
						a = c;
						if (a == 0) {
							inv->addMoney(price);
							return true;
						}
					}
					if (what == "PotatoSeed") {
						PotatoSeed* temp = static_cast<PotatoSeed*>(inv->getItem(i));
						int c = 0;
						if (temp->getDurability() < a) {
							c = a - temp->getDurability();
						}
						temp->damageDurability(a);
						a = c;
						if (a == 0) {
							inv->addMoney(price);
							return true;
						}
					}
					if (what == "Cow") {
						Cow* temp = static_cast<Cow*>(inv->getItem(i));
						a = temp->removeAmount(a);
						if (a == 0) {
							inv->addMoney(price);
							return true;
						}
					}
					if (what == "Pig") {
						Pig* temp = static_cast<Pig*>(inv->getItem(i));
						a = temp->removeAmount(a);
						if (a == 0) {
							inv->addMoney(price);
							return true;
						}
					}
					if (what == "Chicken") {
						Chicken* temp = static_cast<Chicken*>(inv->getItem(i));
						a = temp->removeAmount(a);
						if (a == 0) {
							inv->addMoney(price);
							return true;
						}
					}
					if (what == "Milk") {
						Milk* temp = static_cast<Milk*>(inv->getItem(i));
						a = temp->removeAmount(a);
						if (a == 0) {
							inv->addMoney(price);
							return true;
						}
					}
					if (what == "Bacon") {
						Bacon* temp = static_cast<Bacon*>(inv->getItem(i));
						a = temp->removeAmount(a);
						if (a == 0) {
							inv->addMoney(price);
							return true;
						}
					}
					if (what == "Egg") {
						Egg* temp = static_cast<Egg*>(inv->getItem(i));
						a = temp->removeAmount(a);
						if (a == 0) {
							inv->addMoney(price);
							return true;
						}
					}
					if (what == "Hoe") {
						inv->remove(i);
						a--;
						if (a == 0) {
							inv->addMoney(price);
							return true;
						}
					}
					if (what == "BuildPlan") {
						inv->remove(i);
						a--;
						if (a == 0) {
							inv->addMoney(price);
							return true;
						}
					}
				}
			}
		}
	}
	else return false;
	return false;
}

void PlayerGUI::initTextures(){
	if (!this->gameTimeDisplay_Texture.loadFromFile("Resources/Images/Gui/gameTimeSprite.png")) {
		throw "ERROR::PLAYERGUI::COULD_NOT_LOAD_TIMEDISPLAY_TEXTURE";
	}
	if (!this->gameTimeNum_Texture.loadFromFile("Resources/Images/Gui/numbers.png")) {
		throw "ERROR::PLAYERGUI::COULD_NOT_LOAD_TIMEDISPLAYNUMHOUR_TEXTURE";
	}
	if (!this->gameTimeDayText_Texture.loadFromFile("Resources/Images/Gui/daySign.png")) {
		throw "ERROR::PLAYERGUI::COULD_NOT_LOAD_TIMEDISPLAYDAYTEXT_TEXTURE";
	}
	//hotbar
	if (!this->hotbarText.loadFromFile("Resources/Images/Gui/hotbar_Layer0.png")) {
		throw "ERROR::PLAYERGUI::COULD_NOT_LOAD_HOTBAR_TEXTURE";
	}
	if (!this->hotbarTextSelected.loadFromFile("Resources/Images/Gui/hotbar_Layer1.png")) {
		throw "ERROR::PLAYERGUI::COULD_NOT_LOAD_HOTBAR_TEXTURE";
	}
	//inventory
	if (!this->inventoryText.loadFromFile("Resources/Images/Gui/inventory.png")) {
		throw "ERROR::PLAYERGUI::COULD_NOT_LOAD_INVENTORY_TEXTURE";
	}
}

void PlayerGUI::initGameClockDisplay(){
	this->gameTimeDisplay.setTexture(&this->gameTimeDisplay_Texture);
	this->gameTimeDisplay.setSize(sf::Vector2f(gui::p2pX(10.f,vm),gui::p2pY(16.f,vm)));
	this->gameTimeDisplay.setPosition(gui::p2pX(88.f,vm), gui::p2pY(2.f,vm));
}

void PlayerGUI::initGameClockNumbers(){
	//hours ===========================
	//texture Rect
	this->gameTimeNum_Hour_TexRect.width = 16;
	this->gameTimeNum_Hour_TexRect.height = 9;
	this->gameTimeNum_Hour_TexRect.left = 0;
	this->gameTimeNum_Hour_TexRect.top = 0;
	//display rect
	this->gameTimeNum_Hour.setTexture(&this->gameTimeNum_Texture);
	this->gameTimeNum_Hour.setTextureRect(this->gameTimeNum_Hour_TexRect);
	this->gameTimeNum_Hour.setSize(sf::Vector2f(gui::p2pX(3.f, vm), gui::p2pY(3.f, vm)));
	this->gameTimeNum_Hour.setPosition(gui::p2pX(89.5f, vm), gui::p2pY(8.5f, vm));

	//minute ===========================
	//texture Rect
	this->gameTimeNum_Minute_TexRect.width = 16;
	this->gameTimeNum_Minute_TexRect.height = 9;
	this->gameTimeNum_Minute_TexRect.left = 0;
	this->gameTimeNum_Minute_TexRect.top = 0;
	//display rect
	this->gameTimeNum_Minute.setTexture(&this->gameTimeNum_Texture);
	this->gameTimeNum_Minute.setTextureRect(this->gameTimeNum_Minute_TexRect);
	this->gameTimeNum_Minute.setSize(sf::Vector2f(gui::p2pX(3.f, vm), gui::p2pY(3.f, vm)));
	this->gameTimeNum_Minute.setPosition(gui::p2pX(93.7f, vm), gui::p2pY(8.5f, vm));
}

void PlayerGUI::initGameSeasonDisplay(){
	this->currSeason.setFont(this->font);
	this->currSeason.setCharacterSize(gui::calcCharSize(vm,120));
	this->currSeason.setString("Pomlad");
	this->currSeason.setPosition(sf::Vector2f(gui::p2pX(91.5f, vm), gui::p2pY(14.8f, vm)));
	this->currSeason.setColor(sf::Color(80,62,54,255));
	this->currSeason.setStyle(1);
}

void PlayerGUI::initGameDayDisplay(){
	//Display
	this->gameTimeDay.setSize(sf::Vector2f(gui::p2pX(2.5f, vm), gui::p2pY(2.6f, vm)));
	this->gameTimeDay.setPosition(gui::p2pX(93.5f, vm), gui::p2pY(3.55f, vm));
	//texture Rect
	this->gameTimeDay_TexRect.width = 16;
	this->gameTimeDay_TexRect.height = 9;
	this->gameTimeDay_TexRect.left = 0;
	this->gameTimeDay_TexRect.top = 0;
	//Textur gor
	this->gameTimeDay.setTexture(&this->gameTimeNum_Texture);
	this->gameTimeDay.setTextureRect(this->gameTimeDay_TexRect);

	//day text
	this->gameTimeDayText.setSize(sf::Vector2f(gui::p2pX(2.5f, vm), gui::p2pY(2.7f, vm)));
	this->gameTimeDayText.setPosition(gui::p2pX(90.f, vm), gui::p2pY(3.55f, vm));
	this->gameTimeDayText.setTexture(&this->gameTimeDayText_Texture);
}

void PlayerGUI::initHB(){
	this->hotbarRect.setSize(
		sf::Vector2f(
			gui::p2pX(50.f, vm),
			gui::p2pY(11.f, vm)
		)
	);
	this->hotbarRect.setPosition(
		sf::Vector2f(
			gui::p2pX(25.f, vm),
			gui::p2pY(86.f, vm)
		)
	);
	this->hotbarRect.setTexture(&this->hotbarText);
	this->hotbarRectSelected = sf::RectangleShape(this->hotbarRect);
	this->hotbarRectSelected.setTexture(&this->hotbarTextSelected);
}

void PlayerGUI::initCoinIcon(){
	this->coinIconTex = new sf::Texture();
	this->coinIconTex->loadFromFile("Resources/Images/Gui/coin.png");
	sf::Vector2f pos = this->moneySlot.getPosition();
	pos.x -= gui::p2pX(1.8f, vm);
	pos.y += gui::p2pX(0.44f, vm);
	this->coinIcon.setPosition(pos);
	this->coinIcon.setSize(sf::Vector2f(gui::p2pX(1.8f, vm), gui::p2pY(2.5f, vm)));
	this->coinIcon.setTexture(this->coinIconTex);
	this->coinIcon.setFillColor(sf::Color::White);
}

void PlayerGUI::initPossible(){
	this->possible.setFillColor(sf::Color(255,255,255,150));
	this->possible.setPosition(sf::Vector2f(0.f, 0.f));
	this->possible.setSize(sf::Vector2f(16.f, 16.f));
	this->possible.setOutlineColor(sf::Color::Green);
	this->possible.setOutlineThickness(0.5f);
	this->isPlaceble = false;
}

void PlayerGUI::initMousRect(){
	this->mouseHasItem = false;
	this->mouseRect.setFillColor(sf::Color::Transparent);
	this->mouseRect.setSize(sf::Vector2f(gui::p2pX(4.1f, vm), gui::p2pY(7.1f, vm)));
	//mouseoff
	this->mouseOffset.x = 0;
	this->mouseOffset.y = 0;
}

void PlayerGUI::initINVSlots() {
	//inventory
	float width = 4.1f;
	float height = 7.1f;
	float x = 26.f;
	float y = 32.f;
	float offsetX = width + 1.4f;
	float offsetY = height + 3.5f;
	int tmpID = 0;
	for (int j = 0; j < 3; j++) {
		if (j != 0)y += offsetY;
		for (int i = 0; i < 9; i++) {
			if (i != 0)x += offsetX;
			this->inventorySlots[j][i].isHovered = false;
			this->inventorySlots[j][i].isSelected = false;
			this->inventorySlots[j][i].isFull = false;
			this->inventorySlots[j][i].lastMouseState = false;
			this->inventorySlots[j][i].inventoryID = tmpID;
			this->inventorySlots[j][i].shape.setFillColor(sf::Color::Transparent);
			this->inventorySlots[j][i].shape.setSize(sf::Vector2f(gui::p2pX(width, vm), gui::p2pY(height, vm)));
			this->inventorySlots[j][i].shape.setPosition(sf::Vector2f(gui::p2pX(x, vm), gui::p2pY(y, vm)));
			this->inventorySlots[j][i].hasDurability = false;
			this->inventorySlots[j][i].durability.setCharacterSize(gui::calcCharSize(vm,100U));
			this->inventorySlots[j][i].durability.setPosition(sf::Vector2f(gui::p2pX(x, vm), gui::p2pY((y + 5.f), vm)));
			this->inventorySlots[j][i].durability.setFont(font);
			this->inventorySlots[j][i].durability.setString("");
			this->inventorySlots[j][i].durability.setColor(sf::Color::White);
			tmpID++;
		}
		x = 26.f;
	}
	//hotbar
	width = 3.9f;
	height = 6.7f;
	x = 26.7f;
	y = 88.14f;
	offsetX = width + 1.45f;
	for (int j = 3; j < 4; j++) {
		for (int i = 0; i < 9; i++) {
			if (i != 0)x += offsetX;
			this->inventorySlots[j][i].isHovered = false;
			this->inventorySlots[j][i].isSelected = false;
			this->inventorySlots[j][i].isFull = false;
			this->inventorySlots[j][i].lastMouseState = false;
			this->inventorySlots[j][i].inventoryID = tmpID;
			this->inventorySlots[j][i].shape.setFillColor(sf::Color::Transparent);
			this->inventorySlots[j][i].shape.setSize(sf::Vector2f(gui::p2pX(width, vm), gui::p2pY(height, vm)));
			this->inventorySlots[j][i].shape.setPosition(sf::Vector2f(gui::p2pX(x, vm), gui::p2pY(y, vm)));
			this->inventorySlots[j][i].hasDurability = false;
			this->inventorySlots[j][i].durability.setCharacterSize(gui::calcCharSize(vm, 100U));
			this->inventorySlots[j][i].durability.setPosition(sf::Vector2f(gui::p2pX(x, vm), gui::p2pY((y + 5.f), vm)));
			this->inventorySlots[j][i].durability.setFont(font);
			this->inventorySlots[j][i].durability.setString("");
			this->inventorySlots[j][i].durability.setColor(sf::Color::White);
			tmpID++;
		}
	}
}

void PlayerGUI::initMoneySlot(){
	this->moneySlot.setCharacterSize(gui::calcCharSize(vm, 90U));
	this->moneySlot.setPosition(sf::Vector2f(gui::p2pX(60.f, vm), gui::p2pY(23.6f, vm)));
	this->moneySlot.setString("");
	this->moneySlot.setColor(sf::Color::Black);
	this->moneySlot.setFont(font);
	this->moneySlot.setStyle(sf::Text::Bold);
}

void PlayerGUI::initINV(){
	this->inventoryRect.setSize(
		sf::Vector2f(
			gui::p2pX(55.f, vm),
			gui::p2pY(60.f, vm)
		)
	);
	this->inventoryRect.setPosition(
		sf::Vector2f(
			gui::p2pX(22.5f, vm),
			gui::p2pY(10.f, vm)
		)
	);
	this->inventoryRect.setTexture(&this->inventoryText);
	this->initINVSlots();
	this->initMousRect();
	this->initMoneySlot();
}

PlayerGUI::PlayerGUI(Player* player, sf::VideoMode& vm, sf::Font& font, std::map<std::string, sf::Texture>* textures) : vm(vm){
	this->player = player;
	this->textures = textures;
	this->font = font;
	this->initTextures();
	
	this->initGameClockDisplay();
	this->initGameClockNumbers();
	this->initGameSeasonDisplay();
	this->initGameDayDisplay();

	//hotbar
	this->initHB();
	//inventory
	this->initINV();
	this->initCoinIcon();
	//items
	this->initPossible();
	//shop
	this->initShop();
	//buildplan
	this->initSelectorBP();
}

PlayerGUI::~PlayerGUI(){
	delete this->coinIconTex;
}

//Funkcije

void PlayerGUI::updateClockDisplay(int hour, int minute){
	//hour
	int tmpX = 0;
	int tmpY = 0;
	tmpX = ((hour % 10) * this->gameTimeNum_Hour_TexRect.width);
	tmpY = ((hour / 10) * this->gameTimeNum_Hour_TexRect.height);
	this->gameTimeNum_Hour_TexRect.left = tmpX;
	this->gameTimeNum_Hour_TexRect.top = tmpY;
	this->gameTimeNum_Hour.setTextureRect(this->gameTimeNum_Hour_TexRect);
	//minute
	tmpX = ((minute % 10) * this->gameTimeNum_Minute_TexRect.width);
	tmpY = ((minute / 10) * this->gameTimeNum_Minute_TexRect.height);
	this->gameTimeNum_Minute_TexRect.left = tmpX;
	this->gameTimeNum_Minute_TexRect.top = tmpY;
	this->gameTimeNum_Minute.setTextureRect(this->gameTimeNum_Minute_TexRect);
}

void PlayerGUI::updateSeasonDisplay(short unsigned seasonNum){
	switch (seasonNum) {
	case 1:this->currSeason.setString("Pomlad");break;//pomlad
	case 2:this->currSeason.setString("Poletje");break;//poletje
	case 3:this->currSeason.setString("Jesen"); break;//jesen
	case 4:this->currSeason.setString("Zima"); break;//zima
	}
}

void PlayerGUI::updateGameTimeDay(int daysElapsed){
	int tmpX = 0;
	int tmpY = 0;
	tmpX = ((daysElapsed % 10) * this->gameTimeDay_TexRect.width);
	tmpY = ((daysElapsed / 10) * this->gameTimeDay_TexRect.height);
	this->gameTimeDay_TexRect.left = tmpX;
	this->gameTimeDay_TexRect.top = tmpY;
	this->gameTimeDay.setTextureRect(this->gameTimeDay_TexRect);
}

void PlayerGUI::updateHB(){
	unsigned short id = this->player->getInventory()->getIDSelectedHB() + 1;
	std::string path = "Resources/Images/Gui/hotbar_Layer" + std::to_string(id) + ".png";
	this->hotbarTextSelected.loadFromFile(path);
	this->hotbarRectSelected.setTexture(&this->hotbarTextSelected);

	//sloti
	//hotbar
	for (int j = 3; j < 4; j++) {
		for (int i = 0; i < 9; i++) {
			if (this->player->getInventory()->hasItem(this->inventorySlots[j][i].inventoryID)) {
				this->inventorySlots[j][i].isFull = true;
				if (this->inventorySlots[j][i].hasDurability) {
					Item* item = this->player->getInventory()->getItem(this->inventorySlots[j][i].inventoryID);
					if (Tool* temp = dynamic_cast<Tool*>(item)) {
						std::string dur = std::to_string(temp->getDurability());
						this->inventorySlots[j][i].durability.setString(dur);
						if (temp->getID() == "ITEM_TOOL_BUILDPLAN") {
							this->inventorySlots[j][i].durability.setString(""); 
						}
					}
				}
			}
			else {
				this->inventorySlots[j][i].isFull = false;
				this->inventorySlots[j][i].hasDurability = false;
			}
		}
	}

}

void PlayerGUI::swapINVPlace(int from, int to){
	Inventory* inv = this->player->getInventory();
	bool dva = false;
	//preveri ce je "to" mesto zasedeno
	if (inv->hasItem(to)) {
		//je zasedenu
		dva = true;
		Item* fromTMP = inv->getItem(from);
		inv->clean(from);
		inv->add(inv->getItem(to), from);
		inv->clean(to);
		inv->add(fromTMP, to);
	}
	else {
		//ni zasedenu
		inv->add(inv->getItem(from), to);
		//inv->remove(from);
		inv->clean(from);
	}
	//posodobi se isFull atribute
	for (int y = 0; y < 3; y++) {
		for (int x = 0; x < 9; x++) {
			if (!dva) { //je sam en item
				if (this->inventorySlots[y][x].inventoryID == from)this->inventorySlots[y][x].isFull = false; //ta nima vec itema
				else if (this->inventorySlots[y][x].inventoryID == to)this->inventorySlots[y][x].isFull = true; //ta ga je pa dubu
			}
			//else ce sta dva itema sta bla ze prej obadva full
		}
	}
}

void PlayerGUI::updateINVSlots(const sf::Vector2i& mousePosWindow){
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 9; i++) {
			//prever ce je poun =============================================//
			if (this->player->getInventory()->hasItem(this->inventorySlots[j][i].inventoryID)) {
				//je poun
				this->inventorySlots[j][i].isFull = true;
				this->inventorySlots[j][i].hasDurability = true; //ker majo usi sam enim je amount
				Item* item = this->player->getInventory()->getItem(this->inventorySlots[j][i].inventoryID);
				if (Tool* temp = dynamic_cast<Tool*>(item)) {
					std::string dur = std::to_string(temp->getDurability());
					this->inventorySlots[j][i].durability.setString(dur);
					if (temp->getID() == "ITEM_TOOL_BUILDPLAN") {
						this->inventorySlots[j][i].durability.setString("");
					}
				}
				if (Carrot* temp = dynamic_cast<Carrot*>(item)) {
					std::string dur = std::to_string(temp->getAmount());
					this->inventorySlots[j][i].durability.setString(dur);
				}
				if (item->getID() == "ITEM_VEGISE_POTATO") {
					Potato* temp = dynamic_cast<Potato*>(item);
					std::string dur = std::to_string(temp->getAmount());
					this->inventorySlots[j][i].durability.setString(dur);
				}
				if (Milk* temp = dynamic_cast<Milk*>(item)) {
					std::string dur = std::to_string(temp->getAmount());
					this->inventorySlots[j][i].durability.setString(dur);
				}
				if (item->getID() == "ITEM_ANIMALS_COW") {
					Cow* temp = dynamic_cast<Cow*>(item);
					std::string dur = std::to_string(temp->getAmount());
					this->inventorySlots[j][i].durability.setString(dur);
				}
				if (item->getID() == "ITEM_BACON") {
					Bacon* temp = dynamic_cast<Bacon*>(item);
					std::string dur = std::to_string(temp->getAmount());
					this->inventorySlots[j][i].durability.setString(dur);
				}
				if (item->getID() == "ITEM_ANIMALS_PIG") {
					Pig* temp = dynamic_cast<Pig*>(item);
					std::string dur = std::to_string(temp->getAmount());
					this->inventorySlots[j][i].durability.setString(dur);
				}
				if (item->getID() == "ITEM_EGG") {
					Egg* temp = dynamic_cast<Egg*>(item);
					std::string dur = std::to_string(temp->getAmount());
					this->inventorySlots[j][i].durability.setString(dur);
				}
				if (item->getID() == "ITEM_ANIMALS_CHICKEN") {
					Chicken* temp = dynamic_cast<Chicken*>(item);
					std::string dur = std::to_string(temp->getAmount());
					this->inventorySlots[j][i].durability.setString(dur);
				}
			}
			else {
				this->inventorySlots[j][i].isFull = false; //ni poun
				this->inventorySlots[j][i].hasDurability = false;
			}
			//==============================================================//
			//preveri ce je miska nad njim =================================//
			if (this->inventorySlots[j][i].shape.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePosWindow))) {
				//miska je nad njim
				this->inventorySlots[j][i].isHovered = true;
			}
			else if (this->inventorySlots[j][i].isHovered)this->inventorySlots[j][i].isHovered = false; //miska ni vec nad njim
			//==============================================================//
			//preveri ce je biu kliknen med tem ko je bil hoveran ==========//
			if (this->inventorySlots[j][i].isHovered &&
				sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
				this->inventorySlots[j][i].lastMouseState = true;
			}
			else { //ko spustis misko se sele izvede da se ne ponavlja izvajanje
				if (this->inventorySlots[j][i].lastMouseState) { //preveri da je biu kliknjen
					if (this->inventorySlots[j][i].isSelected) {//ce je ze zbran ga unzberes
						this->inventorySlots[j][i].isSelected = false;
						this->mouseHasItem = false;
						this->idMouseItem = -1;
					}
					else{ //biu je kliknen slot k se ni biu zbran
						if (this->inventorySlots[j][i].isFull && !this->mouseHasItem) { //preveri ce je biu ta kliknen pa ma item in miska ga nima
							this->inventorySlots[j][i].isSelected = true;
							this->mouseHasItem = true;
							this->idMouseItem = this->inventorySlots[j][i].inventoryID;
							this->mouseOffset = this->inventorySlots[j][i].shape.getPosition() - static_cast<sf::Vector2f>(mousePosWindow);
							this->mouseRect.setTexture(this->inventorySlots[j][i].shape.getTexture());
							this->mouseRect.setFillColor(sf::Color(153, 151, 150, 255));
						}
						else if (this->mouseHasItem && this->idMouseItem != this->inventorySlots[j][i].inventoryID) { //ce ma miska ze item in ni isti slot iz kerga ma ta item
							this->swapINVPlace(this->idMouseItem, this->inventorySlots[j][i].inventoryID); //zamena ta slota
							//ponastavi vse vrednosti
							for (int y = 0; y < 3; y++) {
								for (int x = 0; x < 9; x++) {
									if (this->inventorySlots[y][x].inventoryID == this->idMouseItem) {
										this->inventorySlots[y][x].isSelected = false;
									}
								}
							}
							this->mouseHasItem = false;
							this->idMouseItem = -1;
							this->inventorySlots[j][i].isSelected = false;
						}
					}
					this->inventorySlots[j][i].lastMouseState = false; //ko konca sz spremembami da nazaj na false
				}
			}
			//==============================================================//
		}
	}
	//preveri za klike izven slotou
	bool isIn = false;
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
		for (int j = 0; j < 4 && !isIn; j++) {
			for (int i = 0; i < 9 && !isIn; i++) {
				if (this->inventorySlots[j][i].isHovered) {
					isIn = true;
				}
			}
		}
		if (!isIn) {
			this->mouseHasItem = false;
			for (int j = 0; j < 4; j++) {
				for (int i = 0; i < 9; i++) {
					if (this->inventorySlots[j][i].inventoryID == this->idMouseItem) {
						this->inventorySlots[j][i].isSelected = false;
					}
				}
			}
		}
	}
}

void PlayerGUI::updateMousRect(const sf::Vector2i& mousePosWindow) {
	this->mouseRect.setPosition(static_cast<sf::Vector2f>(mousePosWindow) + this->mouseOffset);
	if (!this->mouseHasItem) {
		this->mouseRect.setTexture(nullptr);
		this->mouseRect.setFillColor(sf::Color::Transparent);
	}
}

void PlayerGUI::updateINV(const sf::Vector2i& mousePosWindow){
	//se klice po potrebi (k je inventory odprrt)
	this->updateMousRect(mousePosWindow);
	this->updateINVSlots(mousePosWindow);
}

void PlayerGUI::updateButtons(const sf::Vector2i& mousePosWindow){
	for (const auto& pair : this->buttonsShop) {
		pair.second->update(mousePosWindow);
	}
	if (this->buttonsShop["DownSlide"]->isPressed()) {
		this->buttonsShop["DownSlide"]->makeSound();
		if (static_cast<int>(this->currShopSite) == 0)this->currShopSite = Tools;
		else this->currShopSite = static_cast<ShopSite>(static_cast<int>(this->currShopSite)-1);
		this->resetTexts();
	}
	if (this->buttonsShop["UpSlide"]->isPressed()) {
		this->buttonsShop["UpSlide"]->makeSound();
		if (static_cast<int>(this->currShopSite) == 1)this->currShopSite = Plants;
		else this->currShopSite = static_cast<ShopSite>(static_cast<int>(this->currShopSite) + 1);
		this->resetTexts();
	}
	if (this->buttonsShop["Plus1"]->isPressed()) {
		this->buttonsShop["Plus1"]->makeSound();
		this->texts["Amount1"].setString(this->addOne("Amount1"));
		if (this->currShopSite == Plants) {
			for(int i = 0;i<2;i++)this->texts["Price1"].setString(this->addOne("Price1"));
		}
		else {
			for (int i = 0; i < 4; i++)this->texts["Price1"].setString(this->addOne("Price1"));
		}
	}
	if (this->buttonsShop["Plus2"]->isPressed()) {
		this->buttonsShop["Plus2"]->makeSound();
		this->texts["Amount2"].setString(this->addOne("Amount2"));
		if (this->currShopSite == Plants) {
			for (int i = 0; i < 4; i++)this->texts["Price2"].setString(this->addOne("Price2"));
		}
		else {
			for (int i = 0; i < 5; i++)this->texts["Price2"].setString(this->addOne("Price2"));
		}
	}
	if (this->buttonsShop["Plus3"]->isPressed()) {
		this->buttonsShop["Plus3"]->makeSound();
		this->texts["Amount3"].setString(this->addOne("Amount3"));
		if (this->currShopSite == Plants) {
			for (int i = 0; i < 1; i++)this->texts["Price3"].setString(this->addOne("Price3"));
		}
		else {
			for (int i = 0; i < 6; i++)this->texts["Price3"].setString(this->addOne("Price3"));
		}
	}
	if (this->buttonsShop["Plus4"]->isPressed()) {
		this->buttonsShop["Plus4"]->makeSound();
		this->texts["Amount4"].setString(this->addOne("Amount4"));
		if (this->currShopSite == Plants) {
			for (int i = 0; i < 1; i++)this->texts["Price4"].setString(this->addOne("Price4"));
		}
		else {
			for (int i = 0; i < 4; i++)this->texts["Price4"].setString(this->addOne("Price4"));
		}
	}
	if (this->buttonsShop["Plus5"]->isPressed()) {
		this->buttonsShop["Plus5"]->makeSound();
		this->texts["Amount5"].setString(this->addOne("Amount5"));
		if (this->currShopSite == Plants) {
			for (int i = 0; i < 2; i++)this->texts["Price5"].setString(this->addOne("Price5"));
		}
		else {
			for (int i = 0; i < 6; i++)this->texts["Price5"].setString(this->addOne("Price5"));
		}
	}
	if (this->buttonsShop["Plus6"]->isPressed()) {
		this->buttonsShop["Plus6"]->makeSound();
		this->texts["Amount6"].setString(this->addOne("Amount6"));
		if (this->currShopSite == Plants) {
			for (int i = 0; i < 15; i++)this->texts["Price6"].setString(this->addOne("Price6"));
		}
		else {
			for (int i = 0; i < 5; i++)this->texts["Price6"].setString(this->addOne("Price6"));
		}
	}
	if (this->buttonsShop["Minus1"]->isPressed()) {
		this->buttonsShop["Minus1"]->makeSound();
		this->texts["Amount1"].setString(this->removeOne("Amount1"));
		if (this->currShopSite == Plants) {
			for (int i = 0; i < 2; i++)this->texts["Price1"].setString(this->removeOne("Price1"));
		}
		else {
			for (int i = 0; i < 4; i++)this->texts["Price1"].setString(this->removeOne("Price1"));
		}
	}
	if (this->buttonsShop["Minus2"]->isPressed()) {
		this->buttonsShop["Minus2"]->makeSound();
		this->texts["Amount2"].setString(this->removeOne("Amount2"));
		if (this->currShopSite == Plants) {
			for (int i = 0; i < 4; i++)this->texts["Price2"].setString(this->removeOne("Price2"));
		}
		else {
			for (int i = 0; i < 5; i++)this->texts["Price2"].setString(this->removeOne("Price2"));
		}
	}
	if (this->buttonsShop["Minus3"]->isPressed()) {
		this->buttonsShop["Minus3"]->makeSound();
		this->texts["Amount3"].setString(this->removeOne("Amount3"));
		if (this->currShopSite == Plants) {
			for (int i = 0; i < 1; i++)this->texts["Price3"].setString(this->removeOne("Price3"));
		}
		else {
			for (int i = 0; i < 6; i++)this->texts["Price3"].setString(this->removeOne("Price3"));
		}
	}
	if (this->buttonsShop["Minus4"]->isPressed()) {
		this->buttonsShop["Minus4"]->makeSound();
		this->texts["Amount4"].setString(this->removeOne("Amount4"));
		if (this->currShopSite == Plants) {
			for (int i = 0; i < 1; i++)this->texts["Price4"].setString(this->removeOne("Price4"));
		}
		else {
			for (int i = 0; i < 4; i++)this->texts["Price4"].setString(this->removeOne("Price4"));
		}
	}
	if (this->buttonsShop["Minus5"]->isPressed()) {
		this->buttonsShop["Minus5"]->makeSound();
		this->texts["Amount5"].setString(this->removeOne("Amount5"));
		if (this->currShopSite == Plants) {
			for (int i = 0; i < 2; i++)this->texts["Price5"].setString(this->removeOne("Price5"));
		}
		else {
			for (int i = 0; i < 6; i++)this->texts["Price5"].setString(this->removeOne("Price5"));
		}
	}
	if (this->buttonsShop["Minus6"]->isPressed()) {
		this->buttonsShop["Minus6"]->makeSound();
		this->texts["Amount6"].setString(this->removeOne("Amount6"));
		if (this->currShopSite == Plants) {
			for (int i = 0; i < 15; i++)this->texts["Price6"].setString(this->removeOne("Price6"));
		}
		else {
			for (int i = 0; i < 5; i++)this->texts["Price6"].setString(this->removeOne("Price6"));
		}
	}
	std::string what = "";
	if (this->buttonsShop["Buy1"]->isPressed()) {
		this->buttonsShop["Buy1"]->makeSound();
		if (this->currShopSite == Plants)what = "Carrot";
		else what = "Cow";
		if (this->buy(what,
			std::stoi(this->texts["Amount1"].getString().toAnsiString()),
			std::stoi(this->texts["Price1"].getString().toAnsiString()))) {
			this->texts["Amount1"].setString("00");
			this->texts["Price1"].setString("00");
		}
	}
	if (this->buttonsShop["Sell1"]->isPressed()) {
		this->buttonsShop["Sell1"]->makeSound();
		if (this->currShopSite == Plants)what = "Carrot";
		else what = "Cow";
			if (this->sell(what,
				std::stoi(this->texts["Amount1"].getString().toAnsiString()),
				std::stoi(this->texts["Price1"].getString().toAnsiString()))) {
				this->updateINVSlots(mousePosWindow);
				this->texts["Amount1"].setString("00");
				this->texts["Price1"].setString("00");
			}
	}
	if (this->buttonsShop["Buy2"]->isPressed()) {
		this->buttonsShop["Buy2"]->makeSound();
		if (this->currShopSite == Plants)what = "Potato";
		else what = "Pig";
		if (this->buy(what,
			std::stoi(this->texts["Amount2"].getString().toAnsiString()),
			std::stoi(this->texts["Price2"].getString().toAnsiString()))) {
			this->texts["Amount2"].setString("00");
			this->texts["Price2"].setString("00");
		}
	}
	if (this->buttonsShop["Sell2"]->isPressed()) {
		this->buttonsShop["Sell2"]->makeSound();
		if (this->currShopSite == Plants)what = "Potato";
		else what = "Pig";
		if (this->sell(what,
			std::stoi(this->texts["Amount2"].getString().toAnsiString()),
			std::stoi(this->texts["Price2"].getString().toAnsiString()))) {
			this->texts["Amount2"].setString("00");
			this->texts["Price2"].setString("00");
		}
	}
	if (this->buttonsShop["Buy3"]->isPressed()) {
		this->buttonsShop["Buy3"]->makeSound();
		if (this->currShopSite == Plants)what = "Hoe";
		else what = "Chicken";
		if (this->buy(what,
			std::stoi(this->texts["Amount3"].getString().toAnsiString()),
			std::stoi(this->texts["Price3"].getString().toAnsiString()))) {
			this->texts["Amount3"].setString("00");
			this->texts["Price3"].setString("00");
		}
	}
	if (this->buttonsShop["Sell3"]->isPressed()) {
		this->buttonsShop["Sell3"]->makeSound();
		if (this->currShopSite == Plants)what = "Hoe";
		else what = "Chicken";
		if (this->sell(what,
			std::stoi(this->texts["Amount3"].getString().toAnsiString()),
			std::stoi(this->texts["Price3"].getString().toAnsiString()))) {
			this->texts["Amount3"].setString("00");
			this->texts["Price3"].setString("00");
		}
	}
	if (this->buttonsShop["Buy4"]->isPressed()) {
		this->buttonsShop["Buy4"]->makeSound();
		if (this->currShopSite == Plants)what = "CarrotSeed";
		else what = "Milk";
		if (this->buy(what,
			std::stoi(this->texts["Amount4"].getString().toAnsiString()),
			std::stoi(this->texts["Price4"].getString().toAnsiString()))) {
			this->texts["Amount4"].setString("00");
			this->texts["Price4"].setString("00");
		}
	}
	if (this->buttonsShop["Sell4"]->isPressed()) {
		this->buttonsShop["Sell4"]->makeSound();
		if (this->currShopSite == Plants)what = "CarrotSeed";
		else what = "Milk";
		if (this->sell(what,
			std::stoi(this->texts["Amount4"].getString().toAnsiString()),
			std::stoi(this->texts["Price4"].getString().toAnsiString()))) {
			this->texts["Amount4"].setString("00");
			this->texts["Price4"].setString("00");
		}
	}
	if (this->buttonsShop["Buy5"]->isPressed()) {
		this->buttonsShop["Buy5"]->makeSound();
		if (this->currShopSite == Plants)what = "PotatoSeed";
		else what = "Bacon";
		if (this->buy(what,
			std::stoi(this->texts["Amount5"].getString().toAnsiString()),
			std::stoi(this->texts["Price5"].getString().toAnsiString()))) {
			this->texts["Amount5"].setString("00");
			this->texts["Price5"].setString("00");
		}
	}
	if (this->buttonsShop["Sell5"]->isPressed()) {
		this->buttonsShop["Sell5"]->makeSound();
		if (this->currShopSite == Plants)what = "PotatoSeed";
		else what = "Bacon";
		if (this->sell(what,
			std::stoi(this->texts["Amount5"].getString().toAnsiString()),
			std::stoi(this->texts["Price5"].getString().toAnsiString()))) {
			this->texts["Amount5"].setString("00");
			this->texts["Price5"].setString("00");
		}
	}
	if (this->buttonsShop["Buy6"]->isPressed()) {
		this->buttonsShop["Buy6"]->makeSound();
		if (this->currShopSite == Plants)what = "BuildPlan";
		else what = "Egg";
		if (this->buy(what,
			std::stoi(this->texts["Amount6"].getString().toAnsiString()),
			std::stoi(this->texts["Price6"].getString().toAnsiString()))) {
			this->texts["Amount6"].setString("00");
			this->texts["Price6"].setString("00");
		}
	}
	if (this->buttonsShop["Sell6"]->isPressed()) {
		this->buttonsShop["Sell6"]->makeSound();
		if (this->currShopSite == Plants)what = "BuildPlan";
		else what = "Egg";
		if (this->sell(what,
			std::stoi(this->texts["Amount6"].getString().toAnsiString()),
			std::stoi(this->texts["Price6"].getString().toAnsiString()))) {
			this->texts["Amount6"].setString("00");
			this->texts["Price6"].setString("00");
		}
	}
}

void PlayerGUI::updateSites(){
	switch (this->currShopSite) {
	case Plants:
		this->siteShopRect.setTexture(&this->shopPlantsSite);
		break;
	case Tools:
		this->siteShopRect.setTexture(&this->shopToolsSite);
		break;
	}
}

void PlayerGUI::updateShop(const sf::Vector2i& mousePosWindow){
	this->updateButtons(mousePosWindow);
	this->updateSites();
}

void PlayerGUI::update(const float & dt){
	this->updateHB();
}

void PlayerGUI::renderGameClock(sf::RenderTarget& target){
	target.draw(this->gameTimeDisplay);
	target.draw(this->gameTimeNum_Hour);
	target.draw(this->gameTimeNum_Minute);
	target.draw(this->currSeason);
	target.draw(this->gameTimeDay);
	target.draw(this->gameTimeDayText);
}

void PlayerGUI::renderHB(sf::RenderTarget& target){
	target.draw(this->hotbarRect);
	target.draw(this->hotbarRectSelected);
	for (int j = 3; j < 4; j++) {
		for (int i = 0; i < 9; i++) {
			//ureja barvo
			if (this->inventorySlots[j][i].isFull)this->inventorySlots[j][i].shape.setFillColor(sf::Color::White);
			else this->inventorySlots[j][i].shape.setFillColor(sf::Color::Transparent);
			//ureja teksturo
			if (this->inventorySlots[j][i].isFull) {
				sf::Texture* tmp = this->player->getInventory()->getItemIcon(this->inventorySlots[j][i].inventoryID);
				this->inventorySlots[j][i].shape.setTexture(tmp);
			}
			else {
				this->inventorySlots[j][i].shape.setTexture(nullptr);
			}
			//narise
			target.draw(this->inventorySlots[j][i].shape);
			if (this->inventorySlots[j][i].hasDurability) {
				target.draw(this->inventorySlots[j][i].durability);
			}
		}
	}
}

void PlayerGUI::renderINVSlots(sf::RenderTarget& target){
	Inventory* tmp = this->player->getInventory();
	for (int j = 0; j < 4; j++) {
		for (int i = 0; i < 9; i++) {
			//spremeni barvo
			if (this->inventorySlots[j][i].isSelected) {
				this->inventorySlots[j][i].shape.setFillColor(sf::Color(92, 84, 64, 50));
			}
			else if (this->inventorySlots[j][i].isHovered) {
				if (this->inventorySlots[j][i].isFull)this->inventorySlots[j][i].shape.setFillColor(sf::Color(153, 151, 150, 255));
				else this->inventorySlots[j][i].shape.setFillColor(sf::Color::Transparent);
			}
			else {
				if (this->inventorySlots[j][i].isFull) {
					this->inventorySlots[j][i].shape.setFillColor(sf::Color::White);
					//ubistvu majo usi sam da eni majo amount eni pa durability
					this->inventorySlots[j][i].hasDurability = true;
				}
				else this->inventorySlots[j][i].shape.setFillColor(sf::Color::Transparent);
			}
			//========
			//Ce ma item doda teksturo
			if (this->inventorySlots[j][i].isFull) {
				sf::Texture* tmp = this->player->getInventory()->getItemIcon(this->inventorySlots[j][i].inventoryID);
				this->inventorySlots[j][i].shape.setTexture(tmp);
			}
			else {
				this->inventorySlots[j][i].shape.setTexture(nullptr);
			}
			target.draw(this->inventorySlots[j][i].shape);
			//ce ma durability
			if (this->inventorySlots[j][i].hasDurability) {
				target.draw(this->inventorySlots[j][i].durability);
			}
		}
	}
}

void PlayerGUI::renderMoney(sf::RenderTarget& target){
	std::string tmp = std::to_string(this->player->getInventory()->getMoney());
	this->moneySlot.setString(tmp);
	target.draw(this->moneySlot);
	target.draw(this->coinIcon);
}

void PlayerGUI::renderINV(sf::RenderTarget& target){
	//se klice po potrebi (k je inventory odprrt)
	target.draw(this->inventoryRect);
	target.draw(this->mouseRect);
	this->renderINVSlots(target);
	this->renderMoney(target);
}

void PlayerGUI::renderButtons(sf::RenderTarget& target){
	for (const auto& pair : this->buttonsShop) {
		pair.second->render(target);
	}
}

void PlayerGUI::renderTexts(sf::RenderTarget& target){
	for (const auto& pair : this->texts) {
		target.draw(pair.second);
	}
}

void PlayerGUI::renderSite(sf::RenderTarget& target){
	target.draw(this->siteShopRect);
}

void PlayerGUI::renderShop(sf::RenderTarget& target){
	target.draw(this->basicShopRect);
	this->renderButtons(target);
	this->renderSite(target);
	this->renderTexts(target);
}

void PlayerGUI::render(sf::RenderTarget & target){
	this->renderGameClock(target);
	this->renderHB(target);
	if (this->player->itemInHand == "buildplan") {
		target.draw(this->selectorBP);
		target.draw(this->buildingPrice);
	}
}


//tools

float calculateDistance2D(sf::Vector2f pos1, sf::Vector2f pos2) {
	float dx = pos2.x - pos1.x;
	float dy = pos2.y - pos1.y;
	dx = std::abs(dx);
	dy = std::abs(dy);
	return std::sqrt(dx * dx + dy * dy);
}

bool PlayerGUI::checkBuild(std::string buildingType, std::map<std::string, std::map<int, Structure*>>* buildings) {
	sf::FloatRect marketBounds = sf::FloatRect(buildings->at("Market")[0]->getHitbox()->getPosition(), buildings->at("Market")[0]->getHitbox()->getSize());
	if (marketBounds.intersects(this->possible.getGlobalBounds()))return false; //prever da ni market tam bo treba popravt da bo za vse buildinge
	if (buildingType == "farmland") { //checka ce placas farmland
		//prever ostale buildinge
		for (const auto& pair : *buildings) {
			if (pair.first == "farmland" || pair.first == "carrotPlant" || pair.first == "potatoPlant")continue;
			for (const auto& value : pair.second) {
				if (value.second->getGlobalBounds().intersects(this->possible.getGlobalBounds()))return false;
			}
		}
		for (const auto& value : buildings->at("farmland")) { //prever da ne placa na se en farmland
			if (value.second->getPos() == this->possible.getPosition())return false;
		}
		return true;
	}
	if (buildingType == "carrotPlant" || buildingType == "potatoPlant") { //checka ce placas carrotPlant al pa krompir
		for (const auto& value : buildings->at("farmland")) {
			if (value.second->getPos() == this->possible.getPosition()) { //preveri da se placa na farmland
				for (const auto& v : buildings->at("carrotPlant")) {
					if (v.second->getPos() == this->possible.getPosition())return false;//preveri da se ne placa na se en korencek
				}
				for (const auto& v : buildings->at("potatoPlant")) {
					if (v.second->getPos() == this->possible.getPosition())return false;//preveri da se ne placa na se en potato
				}
				return true;
			}
		}
		return false;
	}
}

void PlayerGUI::updateItemPossibles(const sf::Vector2f& mousePosWindow, TileMap* map,sf::Texture* texture, std::string item, std::map<std::string, std::map<int, Structure*>>* buildings){
	sf::Vector2f temp = map->getPosOfRectWithMousOver(mousePosWindow);
	if (item == "hoe") {
		if (calculateDistance2D(mousePosWindow, player->getPosition()) < 32.f) {
			this->possible.setPosition(temp);
			this->possible.setTexture(texture);
			if (checkBuild("farmland", buildings)) {
				this->possible.setFillColor(sf::Color(255, 255, 255, 150));
				this->possible.setOutlineColor(sf::Color::Green);
				this->isPlaceble = true;
			}
			else {
				this->possible.setFillColor(sf::Color(212, 23, 13, 200));
				this->possible.setOutlineColor(sf::Color::Red);
				this->isPlaceble = false;
			}
		}
		else {
			this->possible.setFillColor(sf::Color::Transparent);
			this->possible.setOutlineColor(sf::Color::Transparent);
			this->isPlaceble = false;
		}
	}
	if (item == "carrotSeed") {
		if (calculateDistance2D(mousePosWindow, player->getPosition()) < 32.f) {
			this->possible.setPosition(temp);
			this->possible.setTexture(texture);
			if (checkBuild("carrotPlant", buildings)) {
				this->possible.setFillColor(sf::Color(255, 255, 255, 150));
				this->possible.setOutlineColor(sf::Color::Green);
				this->isPlaceble = true;
			}
			else {
				this->possible.setFillColor(sf::Color(212, 23, 13, 200));
				this->possible.setOutlineColor(sf::Color::Red);
				this->isPlaceble = false;
			}
		}
		else {
			this->possible.setFillColor(sf::Color::Transparent);
			this->possible.setOutlineColor(sf::Color::Transparent);
			this->isPlaceble = false;
		}
	}
	if (item == "potatoSeed") {
		if (calculateDistance2D(mousePosWindow, player->getPosition()) < 32.f) {
			this->possible.setPosition(temp);
			this->possible.setTexture(texture);
			if (checkBuild("potatoPlant", buildings)) {
				this->possible.setFillColor(sf::Color(255, 255, 255, 150));
				this->possible.setOutlineColor(sf::Color::Green);
				this->isPlaceble = true;
			}
			else {
				this->possible.setFillColor(sf::Color(212, 23, 13, 200));
				this->possible.setOutlineColor(sf::Color::Red);
				this->isPlaceble = false;
			}
		}
		else {
			this->possible.setFillColor(sf::Color::Transparent);
			this->possible.setOutlineColor(sf::Color::Transparent);
			this->isPlaceble = false;
		}
	}
}

bool PlayerGUI::getIsPlaceble(){
	return this->isPlaceble;
}

bool PlayerGUI::getSelectorCanPlace(){
	return this->selectorCanPlace;
}

int PlayerGUI::getSelectedBuilding(){
	return this->selectedBuilding;
}

sf::Vector2f PlayerGUI::getSelectorPos(){
	return this->selectorPossible.getPosition();
}

void PlayerGUI::renderItemPossibles(sf::RenderTarget& target){
	target.draw(this->possible);
}


//buildplan

void PlayerGUI::initSelectorBP(){
	this->selectorCanPlace = true;
	this->selectedBuilding = 0;
	this->selectorBP.setTexture(Building::textureSheet);
	this->selectorBP.setTextureRect(sf::IntRect(sf::Vector2i(0,0), sf::Vector2i(64,80)));
	this->selectorBP.setFillColor(sf::Color::White);
	this->selectorBP.setSize(sf::Vector2f(gui::p2pX(5.f, vm), gui::p2pY(11.f, vm)));
	this->selectorBP.setPosition(sf::Vector2f(gui::p2pX(5.f, vm), gui::p2pY(85.f, vm)));
	this->initSelectorPossible();
	this->buildingPrice.setCharacterSize(gui::calcCharSize(vm,70U));
	this->buildingPrice.setColor(sf::Color::White);
	this->buildingPrice.setFont(this->font);
	this->buildingPrice.setPosition(sf::Vector2f(gui::p2pX(10.f, vm), gui::p2pY(85.f, vm)));
	this->buildingPrice.setString("Cost: 1500");
}

void PlayerGUI::initSelectorPossible(){
	this->selectorPossible.setTexture(Building::textureSheet);
}

void PlayerGUI::moveSelector(){
	if (this->selectedBuilding == 4)this->selectedBuilding = 0;
	else this->selectedBuilding++;
	switch (this->selectedBuilding){
	case 0: //smal house
		this->selectorBP.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(64, 80)));
		this->buildingPrice.setString("Cost: 1500");
		break;
	case 1: //cow barn
		this->selectorBP.setTextureRect(sf::IntRect(sf::Vector2i(0, 160), sf::Vector2i(80, 80)));
		this->buildingPrice.setString("Cost: 2500");
		break;
	case 2: //medium house
		this->selectorBP.setTextureRect(sf::IntRect(sf::Vector2i(0, 401), sf::Vector2i(80, 79)));
		this->buildingPrice.setString("Cost: 2000");
		break;
	case 3: //pig barn
		this->selectorBP.setTextureRect(sf::IntRect(sf::Vector2i(0, 480), sf::Vector2i(80, 80)));
		this->buildingPrice.setString("Cost: 3000");
		break;
	case 4: //chicken coop
		this->selectorBP.setTextureRect(sf::IntRect(sf::Vector2i(0, 560), sf::Vector2i(64, 64)));
		this->buildingPrice.setString("Cost: 3500");
		break;
	}
}

void PlayerGUI::updateSelectorBP(TileMap* map,
	const sf::Vector2f& mousePosView,
	std::map<std::string, std::map<int, Structure*>>& buildings){
	switch (this->selectedBuilding) { //nastima ta prau texture
	case 0:
		this->selectorPossible.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(64, 80)));
		this->selectorPossible.setSize(sf::Vector2f(64.f,80.f));
		break;
	case 1:
		this->selectorPossible.setTextureRect(sf::IntRect(sf::Vector2i(0, 160), sf::Vector2i(80, 80)));
		this->selectorPossible.setSize(sf::Vector2f(80.f, 80.f));
		break;
	case 2:
		this->selectorPossible.setTextureRect(sf::IntRect(sf::Vector2i(0, 401), sf::Vector2i(80, 79)));
		this->selectorPossible.setSize(sf::Vector2f(80.f, 79.f));
		break;
	case 3:
		this->selectorPossible.setTextureRect(sf::IntRect(sf::Vector2i(0, 480), sf::Vector2i(80, 80)));
		this->selectorPossible.setSize(sf::Vector2f(80.f, 80.f));
		break;
	case 4:
		this->selectorPossible.setTextureRect(sf::IntRect(sf::Vector2i(0, 560), sf::Vector2i(64, 64)));
		this->selectorPossible.setSize(sf::Vector2f(64.f, 64.f));
		break;
	}
	sf::Vector2f temp = map->getPosOfRectWithMousOver(mousePosView);
	temp.x -= this->selectorPossible.getSize().x / 2;
	temp.y -= this->selectorPossible.getSize().y;
	this->selectorPossible.setPosition(temp);
	//prever a se lahko postavi
	this->selectorCanPlace = true;
	if (calculateDistance2D(mousePosView, player->getPosition()) < 32.f) {
		//prever ce ni u playerju
		if (this->player->getGlobalBounds().intersects(this->selectorPossible.getGlobalBounds())) {
			this->selectorCanPlace = false;
		}
		//prever ostale buildinge
		for (const auto& pair : buildings) {
			for (const auto& value : pair.second) {
				if (value.second->getGlobalBounds().intersects(this->selectorPossible.getGlobalBounds())) {
					this->selectorCanPlace = false;
				}
			}
		}
	}
	else this->selectorCanPlace = false;
	if (this->selectorCanPlace)this->selectorPossible.setFillColor(sf::Color(14, 237, 51, 50)); //zelena
	else this->selectorPossible.setFillColor(sf::Color(237, 14, 14, 50)); //rdeca
}

void PlayerGUI::renderSelectorBP(sf::RenderTarget& target){
	target.draw(this->selectorPossible);
}