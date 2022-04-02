#ifndef _BUTTON_H_
#define _BUTTON_H_
#include <string>
#include "SFML/Graphics.hpp"
class Button {
private:
	sf::RectangleShape button;
	sf::Text text;

public:
	//Constructors
	Button();
	Button(std::string btnText, sf::Vector2f btnSize, sf::Vector2f position, int charSize, sf::Color bgColor, sf::Color textColor, sf::Font* font);

	//Status
	bool isMouseIn(sf::RenderWindow* target);

	//Methods
	void setText(std::string info);
	void setSize(sf::Vector2f size);
	void setCharSize(unsigned int charSize);
	void setFont(sf::Font* font);
	void setBackColor(sf::Color color);
	void setTextColor(sf::Color color);
	void setPosition(sf::Vector2f position);
	void render(sf::RenderTarget* target);
};
#endif
