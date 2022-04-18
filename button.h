#ifndef _BUTTON_H_
#define _BUTTON_H_
#include <string>
#include "SFML/Graphics.hpp"
class Button {
private:
	sf::Vector2f defaultSize;
	sf::RectangleShape button;
	sf::Text text;
	sf::Sprite buttonSprite;
	sf::Color textColor;
	bool _hasSprite;
	bool _selected;

public:
	//Constructors
	Button();
	virtual ~Button();

	//Status
	bool isMouseIn(sf::RenderWindow* target);

	//Setters
	void setSprite(sf::Texture* texture, bool selectedStatus = false);
	void setText(std::string info);
	void setSize(sf::Vector2f size);
	void setCharSize(unsigned int charSize);
	void setFont(sf::Font* font);
	void setBackColor(sf::Color color);
	void setTextColor(sf::Color color);
	void setPosition(sf::Vector2f position);
	void setSelectedStatus(const bool status);
	void setScale(const float value);
	void setSpriteScale(const float value);

	//Methods
	void create(std::string btnText, sf::Vector2f btnSize, sf::Vector2f position, int charSize, sf::Color bgColor, sf::Color textColor, sf::Font* font, bool selectedStatus = false);
	void update(sf::RenderWindow* window);
	void render(sf::RenderWindow* window);
};
#endif
