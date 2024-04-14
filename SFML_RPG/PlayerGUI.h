#pragma once

#include "Inventory.h"
#include "TileMap.h"
#include "Structures.h"

class PlayerGUI{
private:
	struct InventorySlot {
		bool isHovered;
		bool isSelected;
		bool isFull;
		bool lastMouseState;
		int inventoryID;
		sf::RectangleShape shape;
		bool hasDurability;
		sf::Text durability;
	};

	Player* player;

	sf::VideoMode& vm;
	sf::Font font;

	//Level bar
	std::string levelBarString;
	sf::Text levelBarText;
	sf::RectangleShape levelBarBack;

	//inGameTime Display ======================================
	
	//Ura in minute
	sf::RectangleShape gameTimeDisplay;
	sf::Texture gameTimeDisplay_Texture;
	//inGameTime Numbers
	//ure
	sf::RectangleShape gameTimeNum_Hour;
	sf::IntRect gameTimeNum_Hour_TexRect;
	//minute
	sf::RectangleShape gameTimeNum_Minute;
	sf::IntRect gameTimeNum_Minute_TexRect;
	//tekstura
	sf::Texture gameTimeNum_Texture;

	//letni cas
	sf::Text currSeason;

	//dnevi
	sf::RectangleShape gameTimeDayText;
	sf::Texture gameTimeDayText_Texture;
	sf::RectangleShape gameTimeDay;
	sf::IntRect gameTimeDay_TexRect;
	
	//hotbar(GUI) =======================================================
	sf::RectangleShape hotbarRect;
	sf::Texture hotbarText;
	
	sf::RectangleShape hotbarRectSelected;
	sf::Texture hotbarTextSelected;

	void initHB();

	//inventory(GUI) ====================================================
	bool mouseHasItem;
	int idMouseItem;
	sf::RectangleShape mouseRect;
	sf::Vector2f mouseOffset;
	sf::RectangleShape inventoryRect;
	sf::Texture inventoryText;
	InventorySlot inventorySlots[4][9];
	
	sf::Text moneySlot;
	sf::RectangleShape coinIcon;
	sf::Texture* coinIconTex;

	void initCoinIcon();

	//items ==============================================================
	sf::RectangleShape possible;
	bool isPlaceble;

	void initPossible();

	void initMousRect();
	void initINVSlots();
	void initMoneySlot();
	void initINV();

	void swapINVPlace(int from, int to);

	void updateMousRect(const sf::Vector2i& mousePosWindow);
	void updateINVSlots(const sf::Vector2i& mousePosWindow);

	void renderINVSlots(sf::RenderTarget& target);
	void renderMoney(sf::RenderTarget& target);

	//buildPlan Selector =========================================
	sf::RectangleShape selectorBP;
	int selectedBuilding;
	sf::RectangleShape selectorPossible;
	bool selectorCanPlace;
	sf::Text buildingPrice;

	void initSelectorBP();
	void initSelectorPossible();

	//sf::Color(14, 237, 51, 50) zelena
	//sf::Color(237, 14, 14, 50) rdeca

	//Shop ===========================================================
	sf::RectangleShape basicShopRect;
	sf::Texture shopBasicTexture;

	sf::RectangleShape siteShopRect;
	
	sf::Texture shopPlantsSite;
	sf::Texture shopToolsSite;
	sf::Texture shopBuildingPlansSite;

	std::map<std::string, sf::Texture>* textures;

	enum ShopSite{Plants = 0,Tools};
	ShopSite currShopSite;

	std::map<std::string, gui::Button*>buttonsShop;
	std::map<std::string, sf::Text>texts;

	void initShopTextures();
	void initButtons();
	void initTexts();

	void initShop();

	void resetTexts();
	std::string addOne(std::string id);
	std::string removeOne(std::string id);

	bool buy(std::string what, int amount, int price);
	bool sell(std::string what, int amount, int price);

	void updateButtons(const sf::Vector2i& mousePosWindow);
	//void updateTexts();

	void updateSites();

	void renderButtons(sf::RenderTarget& target);
	void renderTexts(sf::RenderTarget& target);

	void renderSite(sf::RenderTarget& target);

	// ===============================================================
	//inicializacija
	void initTextures();
	void initGameClockDisplay();
	void initGameClockNumbers();
	void initGameSeasonDisplay();
	void initGameDayDisplay();

	bool checkBuild(std::string buildingType, std::map<std::string, std::map<int, Structure*>>* buildings);

public:
	PlayerGUI(Player* player, sf::VideoMode& vm, sf::Font &font, std::map<std::string, sf::Texture>* textures);
	virtual ~PlayerGUI();

	//Dostop
	bool getIsPlaceble();
	bool getSelectorCanPlace();
	int getSelectedBuilding();
	sf::Vector2f getSelectorPos();

	//Funkcije
	void updateClockDisplay(int hour,int minute);
	void updateSeasonDisplay(short unsigned seasonNum);
	void updateGameTimeDay(int daysElapsed);
	void updateHB();
	void updateINV(const sf::Vector2i& mousePosWindow);

	void updateShop(const sf::Vector2i& mousePosWindow);

	void updateSelectorBP(TileMap* map,
		const sf::Vector2f& mousePosView,
		std::map<std::string, std::map<int, Structure*>>& buildings);

	void update(const float& dt);

	void renderGameClock(sf::RenderTarget& target);
	void renderHB(sf::RenderTarget& target);
	void renderINV(sf::RenderTarget& target);

	void renderSelectorBP(sf::RenderTarget& target);

	void renderShop(sf::RenderTarget& target);

	void render(sf::RenderTarget& target);


	//tools
	void updateItemPossibles(const sf::Vector2f& mousePosWindow, TileMap* map, sf::Texture* texture, std::string item, std::map<std::string, std::map<int, Structure*>>* buildings);
	void renderItemPossibles(sf::RenderTarget& target);

	//building plan
	void moveSelector();
};

