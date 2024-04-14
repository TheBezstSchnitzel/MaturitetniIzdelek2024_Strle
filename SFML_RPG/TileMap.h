#pragma once

#include "Player.h"
#include "RegularTile.h"

class TileMap{
private:
	void clear();

	float gridSizeF;
	int gridSizeI;
	sf::Vector2i maxSizeWorldGrid;
	sf::Vector2f maxSizeWorldF;
	int layers;
	std::vector< std::vector< std::vector< std::vector<Tile*> > > > map;
	std::stack<Tile*> deferredRenderStack;
	std::string textureFile;
	sf::Texture tileSheet;
	sf::RectangleShape collisionBox;

	int fromX;
	int toX;
	int fromY;
	int toY;
	int layer;

public:
	TileMap(float gridSize, int width, int height, std::string texture_file);
	TileMap(const std::string file_name, const std::string textureFile = "");
	virtual ~TileMap();

	//Dostop
	const bool tileEmpty(const int x, const int y, const int z) const;
	const sf::Texture* getTileSheet() const;
	const int getLayerSize(const int x, const int y, const int layer) const;
	const sf::Vector2i& getMaxSizeGrid() const;
	const sf::Vector2f& getMaxSizeF() const;


	//Funkcije
	void addTile(const int x, const int y, const int z, const sf::IntRect& texture_rect, const bool& collision, const short& type);
	void removeTile(const int x, const int y, const int z, const int type = -1);
	void saveToFile(const std::string file_name);
	void loadFromFile(const std::string file_name, const std::string textureFile = "");
	const bool checkType(const int x, const int y, const int z, const int type) const;

	void updateWorldBoundsCollision(Entity* entity, const float& dt);
	void updateTileCollision(Entity* entity, const float& dt);
	void updateTiles(Entity* entity, const float& dt);
	void update(Entity* entity, const float& dt);

	sf::Vector2f getPosOfRectWithMousOver(const sf::Vector2f& mousePosWindow);
	
	void render(
		sf::RenderTarget& target,
		const sf::Vector2i& gridPosition,
		sf::VideoMode vm,
		sf::Shader* shader = NULL,
		const sf::Vector2f playerPosition = sf::Vector2f(),
		const bool show_collision = false,
		const bool isZoomedOut = false
	);
	void renderDeferred(sf::RenderTarget& target, sf::Shader* shader = NULL, const sf::Vector2f playerPosition = sf::Vector2f());
};