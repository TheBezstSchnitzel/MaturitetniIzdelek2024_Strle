#pragma once

enum button_states{BTN_IDLE = 0, BTN_HOVER, BTN_ACTIVE, BTN_DISABLED};

namespace gui{

	const float p2pX(const float perc, const sf::VideoMode& vm);
	const float p2pY(const float perc, const sf::VideoMode& vm);
	const unsigned calcCharSize(const sf::VideoMode& vm, const unsigned modifier = 60);

	class Button{
	private:
		short unsigned buttonState;
		short unsigned id;
		bool lastMouseState;

		sf::RectangleShape shape;
		sf::Font* font;
		sf::Text text;

		sf::Color textIdleColor;
		sf::Color textHoverColor;
		sf::Color textActiveColor;

		sf::Color idleColor;
		sf::Color hoverColor;
		sf::Color activeColor;

		sf::Color outlineIdleColor;
		sf::Color outlineHoverColor;
		sf::Color outlineActiveColor;

		//klik sound
		sf::SoundBuffer buffer;
		sf::Sound click;

	public:
		Button(float x, float y, float width, float height,
			sf::Font* font, std::string text, unsigned character_size,
			sf::Color text_idle_color, sf::Color text_hover_color, sf::Color text_active_color,
			sf::Color idle_color, sf::Color hover_color, sf::Color active_color,
			sf::Color outline_idle_color = sf::Color::Transparent, sf::Color outline_hover_color = sf::Color::Transparent, sf::Color outline_active_color = sf::Color::Transparent,
			short unsigned id = 0);
		~Button();

		//Dostop
		const bool isPressed() const;
		const std::string getText() const;
		const short unsigned& getId() const;

		//Interface
		void setText(const std::string text);
		void setId(const short unsigned id);

		//Funkcije
		void update(const sf::Vector2i& mousePosWindow);
		void render(sf::RenderTarget& target);

		void disable();
		void enable();

		//zvok
		void makeSound();
		short getStatus();
	};

	class DropDownList{
	private:
		float keytime;
		float keytimeMax;

		sf::Font& font;
		gui::Button* activeElement;
		std::vector<gui::Button*> list;
		bool showList;

	public:
		DropDownList(float x, float y, float width, float height, 
			sf::Font& font, std::string list[], 
			unsigned nrOfElements, unsigned default_index = 0);
		~DropDownList();

		//Dostop
		const unsigned short& getActiveElementId() const;

		//Funkcije
		const bool getKeytime();
		void updateKeytime(const float& dt);
		void update(const sf::Vector2i& mousePosWindow, const float& dt);
		void render(sf::RenderTarget& target);
	};
	
	class Slider {
	private:
		float startmousePosX;
		float value;

		sf::RectangleShape sliderBar;

		sf::CircleShape sliderButton;

		short unsigned buttonState;
		short unsigned lastButtonState;

		sf::Font* font;
		sf::Text leftText;
		sf::Text textCurrentValue;

		//inicializacija
		void initSliderBar(float x, float y, float width, float height, sf::Color outline, sf::Color fill);
		void initSliderButton(float x, float y, float width, float height, sf::Color fill);
		void initTexts(sf::Font* font, unsigned character_size,sf::Color text_color);
		void initVariables();
		
		void moveButton(const sf::Vector2i& mousePosWindow);

		float calucalateValue();
		float calculatePos();
	public:
		Slider(float x, float y, float width, float height,
			sf::Font* font, unsigned character_size, 
			sf::Color slider_bar_outline_color,sf::Color slider_bar_color, sf::Color slider_button_color,
			sf::Color text_color);
		~Slider();

		//dostop
		void setValue(float newValue);
		float getValue();

		//funkcije
		void update(const sf::Vector2i& mousePosWindow);
		void render(sf::RenderTarget& target);
	};
	
	class TextureSelector{
	private:
		float keytime;
		const float keytimeMax;
		float gridSize;
		bool active;
		bool hidden;
		gui::Button* hide_btn;
		sf::RectangleShape bounds;
		sf::Sprite sheet;
		sf::RectangleShape selector;
		sf::Vector2u mousePosGrid;
		sf::IntRect textureRect;

	public:
		TextureSelector(float x, float y, float width, float height, 
			float gridSize, const sf::Texture* texture_sheet, 
			sf::Font& font, std::string text);
		~TextureSelector();

		//Dostop
		const bool& getActive() const;
		const sf::IntRect& getTextureRect() const;

		//Funkcije
		const bool getKeytime();
		void updateKeytime(const float& dt);
		void update(const sf::Vector2i& mousePosWindow, const float& dt);
		void render(sf::RenderTarget& target);
	};
}
