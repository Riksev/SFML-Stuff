#include "button.h"

Button::Button() {
	this->defaultSize = sf::Vector2f(300.f, 150.f);
	this->_hasSprite = false;
}

Button::~Button() {

}

void Button::create(std::string btnText, sf::Vector2f buttonSize, sf::Vector2f position, int charSize, sf::Color bgColor, sf::Color txtColor, sf::Font* font) {
	this->textColor = txtColor;

	this->button.setSize(buttonSize);
	this->button.setFillColor(bgColor);
	this->button.setOrigin(buttonSize.x / 2.f, buttonSize.y / 2.f);
	this->button.setPosition(position);

	this->text.setFont(*font);
	this->text.setCharacterSize(charSize);
	this->text.setString(btnText);
	this->text.setOrigin(this->text.getGlobalBounds().width / 2, this->text.getGlobalBounds().height / 1.25f);
	this->text.setPosition(position);
	this->text.setFillColor(textColor);
}

void Button::setSprite(sf::Texture* texture) {
	this->buttonSprite.setTexture(*texture);
	this->buttonSprite.setTextureRect(sf::IntRect(0, this->defaultSize.x, this->defaultSize.x, this->defaultSize.y));
	this->buttonSprite.setOrigin(this->buttonSprite.getTextureRect().width / 2, this->buttonSprite.getTextureRect().height / 2);
	this->buttonSprite.setPosition(this->button.getPosition());
	this->_hasSprite = true;
}

void Button::setText(std::string info) {
	this->text.setString(info);
	this->text.setOrigin(this->text.getGlobalBounds().width / 2, this->text.getGlobalBounds().height / 1.25f);
}

void Button::setSize(sf::Vector2f size) {
	this->button.setSize(size);
	this->button.setOrigin(size.x / 2.f, size.y / 2.f);
	if (this->_hasSprite) {
		this->buttonSprite.setScale(size.x / this->defaultSize.x, size.y / this->defaultSize.y);
		this->buttonSprite.setOrigin(this->buttonSprite.getTextureRect().width / 2, this->buttonSprite.getTextureRect().height / 2);
	}
}

void Button::setCharSize(unsigned int charSize) {
	this->text.setCharacterSize(charSize);
	this->text.setOrigin(this->text.getGlobalBounds().width / 2, this->text.getGlobalBounds().height / 1.25f);
}

void Button::setFont(sf::Font* font) {
	this->text.setFont(*font);
}

void Button::setBackColor(sf::Color color) {
	if (!this->_hasSprite) this->button.setFillColor(color);
	else this->buttonSprite.setColor(color);
}

void Button::setTextColor(sf::Color color) {
	this->text.setFillColor(color);
}

void Button::setPosition(sf::Vector2f position) {
	this->button.setPosition(position);
	if(this->_hasSprite) this->buttonSprite.setPosition(position);
	this->text.setPosition(position);
}

void Button::update(sf::RenderWindow* window) {
	if (this->isMouseIn(window)) {
		if (!this->_hasSprite) this->button.setFillColor(sf::Color::Green);
		else this->buttonSprite.setColor(sf::Color::Green);
		this->text.setFillColor(sf::Color::Green);
	}
	else {
		if (!this->_hasSprite) this->button.setFillColor(sf::Color::White);
		else this->buttonSprite.setColor(sf::Color::White);
		this->text.setFillColor(this->textColor);
	}
}

void Button::render(sf::RenderWindow* window) {
	if(!this->_hasSprite) window->draw(this->button);
	else window->draw(this->buttonSprite);
	window->draw(this->text);
}

bool Button::isMouseIn(sf::RenderWindow* window) {
	if (this->button.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(*window).x), static_cast<float>(sf::Mouse::getPosition(*window).y))) return true;
	return false;
}
