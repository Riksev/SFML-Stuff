#include "button.h"

Button::Button() {
	this->defaultSize = sf::Vector2f(300.f, 150.f);
	this->_hasSprite = false;
	this->goldProportion = 1.618f;
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
	this->text.setOrigin(btnText.length() / 2.f * charSize / this->goldProportion, charSize / 2.f);
	this->text.setPosition(position);
	this->text.setFillColor(textColor);
}

void Button::setSprite(sf::Texture* texture) {
	this->buttonSprite.setTexture(*texture);
	this->buttonSprite.setTextureRect(sf::IntRect(0, this->defaultSize.x, this->defaultSize.x, this->defaultSize.y));//Optional, I just use tile map
	this->buttonSprite.setOrigin(this->buttonSprite.getTextureRect().width / 2, this->buttonSprite.getTextureRect().height / 2);
	this->buttonSprite.setPosition(this->button.getPosition());
	this->_hasSprite = true;
}

void Button::setText(std::string info) {
	this->text.setString(info);
	this->text.setOrigin(info.length() / 2 * this->text.getCharacterSize() / this->goldProportion, this->text.getCharacterSize() / 2.f);
}

void Button::setSize(sf::Vector2f size) {
	if (!this->_hasSprite) {
		this->button.setSize(size);
		this->button.setOrigin(size.x / 2.f, size.y / 2.f);
	} else this->buttonSprite.setScale(size.x / this->defaultSize.x, size.y / this->defaultSize.y);
}

void Button::setCharSize(unsigned int charSize) {
	this->text.setCharacterSize(charSize);
	this->text.setOrigin(this->text.getString().getSize() / 2.f * charSize / this->goldProportion, charSize / 2.f);
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
	if (!this->_hasSprite) this->button.setPosition(position);
	else this->buttonSprite.setPosition(position);
	this->text.setPosition(position);
}

void Button::render(sf::RenderWindow* window) {
	if(!this->_hasSprite) window->draw(this->button);
	else window->draw(this->buttonSprite);
	window->draw(this->text);
}

bool Button::isMouseIn(sf::RenderWindow* window) {
	if (this->button.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(*window).x), static_cast<float>(sf::Mouse::getPosition(*window).y))) {
		if (!this->_hasSprite) this->button.setFillColor(sf::Color::Green);
		else this->buttonSprite.setColor(sf::Color::Green);
		this->text.setFillColor(sf::Color::Green);
		return true;
	}
	else {
		if (!this->_hasSprite) this->button.setFillColor(sf::Color::White);
		else this->buttonSprite.setColor(sf::Color::White);
		this->text.setFillColor(this->textColor);
		return false;
	}
}
