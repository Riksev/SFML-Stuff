#include "button.h"

Button::Button() {

}

Button::Button(std::string btnText, sf::Vector2f buttonSize, sf::Vector2f position, int charSize, sf::Color bgColor, sf::Color textColor, sf::Font* font) {
	this->button.setSize(buttonSize);
	this->button.setFillColor(bgColor);
	this->button.setOrigin(buttonSize.x / 2.f, buttonSize.y / 2.f);
	this->button.setPosition(position);

	this->text.setFont(*font);
	this->text.setCharacterSize(charSize);
	this->text.setString(btnText);
	this->text.setOrigin(sizeof(btnText) * charSize / 2.f, charSize / 2.f);
	this->text.setPosition(position);
	this->text.setColor(textColor);
}

void Button::setText(std::string info) {
	this->text.setString(info);
}

void Button::setSize(sf::Vector2f size) {
	this->button.setSize(size);
	this->button.setOrigin(size.x / 2.f, size.y / 2.f);
}

void Button::setCharSize(unsigned int charSize) {
	this->text.setCharacterSize(charSize);
}

void Button::setFont(sf::Font* font) {
	this->text.setFont(*font);
}

void Button::setBackColor(sf::Color color) {
	this->button.setFillColor(color);
}

void Button::setTextColor(sf::Color color) {
	this->text.setColor(color);
}

void Button::setPosition(sf::Vector2f position) {
	this->button.setPosition(position);
	this->text.setOrigin(sizeof(this->text.getString()) * this->text.getCharacterSize() / 2.f, this->text.getCharacterSize() / 2.f);
	this->text.setPosition(position);
}

void Button::render(sf::RenderTarget* target) {
	target->draw(button);
	target->draw(text);
}

bool Button::isMouseIn(sf::RenderWindow* target) {
	sf::Vector2i mouseCoords(sf::Mouse::getPosition(*target));

	sf::Vector2f realCoords = target->mapPixelToCoords(mouseCoords);
	

	if (this->button.getGlobalBounds().contains(sf::Mouse::getPosition(*target).x, sf::Mouse::getPosition(*target).y)) {
		return true;
	}
	return false;
}
