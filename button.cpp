#include "button.h"

Button::Button() {
	this->defaultSize = sf::Vector2f(300.f, 150.f);
	this->_hasSprite = false;
	this->_selected = false;
}

Button::~Button() {

}

void Button::create(std::string btnText, sf::Vector2f buttonSize, sf::Vector2f position, int charSize, sf::Color bgColor, sf::Color txtColor, sf::Font* font, bool selectedStatus) {
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

	if (selectedStatus)
	{
		this->_selected = true;
		if (!this->_hasSprite) this->button.setFillColor(sf::Color::Blue);
		else this->buttonSprite.setColor(sf::Color::Blue);
		this->text.setFillColor(sf::Color::Blue);
	}
}

void Button::setSprite(sf::Texture* texture, bool selectedStatus) {
	this->buttonSprite.setTexture(*texture);
	this->buttonSprite.setTextureRect(sf::IntRect(0, this->defaultSize.x, this->defaultSize.x, this->defaultSize.y));
	this->buttonSprite.setOrigin(this->buttonSprite.getTextureRect().width / 2, this->buttonSprite.getTextureRect().height / 2);
	this->buttonSprite.setPosition(this->button.getPosition());
	this->_hasSprite = true;
	if (selectedStatus)
	{
		this->_selected = true;
		if (!this->_hasSprite) this->button.setFillColor(sf::Color::Blue);
		else this->buttonSprite.setColor(sf::Color::Blue);
		this->text.setFillColor(sf::Color::Blue);
	}
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


void Button::setSelectedStatus(const bool status) {
	this->_selected = status;
	if (!this->_selected)
	{
		if (!this->_hasSprite) this->button.setFillColor(sf::Color::White);
		else this->buttonSprite.setColor(sf::Color::White);
		this->text.setFillColor(this->textColor);
	}
	else
	{
		if (!this->_hasSprite) this->button.setFillColor(sf::Color::Blue);
		else this->buttonSprite.setColor(sf::Color::Blue);
		this->text.setFillColor(sf::Color::Blue);
	}
}

void Button::setSpriteScale(const float value) {
	this->buttonSprite.setScale(this->buttonSprite.getScale() * value);
}

void Button::setScale(const float value) {
	if (this->_hasSprite) this->buttonSprite.setScale(this->buttonSprite.getScale() * value);
	this->button.setScale(this->button.getScale() * value);
}

void Button::update(sf::RenderWindow* window) {
	if (this->isMouseIn(window)) {
		if (!this->_hasSprite) this->button.setFillColor(sf::Color::Green);
		else this->buttonSprite.setColor(sf::Color::Green);
		this->text.setFillColor(sf::Color::Green);
	}
	else {
		if(!this->_selected)
		{ 
			if (!this->_hasSprite) this->button.setFillColor(sf::Color::White);
			else this->buttonSprite.setColor(sf::Color::White);
			this->text.setFillColor(this->textColor);
		}
		else
		{
			if (!this->_hasSprite) this->button.setFillColor(sf::Color::Blue);
			else this->buttonSprite.setColor(sf::Color::Blue);
			this->text.setFillColor(sf::Color::Blue);
		}
	}
}

void Button::render(sf::RenderWindow* window) {
	if(!this->_hasSprite) window->draw(this->button);
	else window->draw(this->buttonSprite);
	window->draw(this->text);
}

bool sf::Button::isMouseIn(sf::RenderWindow* window) {
	if (this->button.getGlobalBounds().contains(static_cast<float>(sf::Mouse::getPosition(*window).x * (window->getView().getSize().x / window->getSize().x)), static_cast<float>(sf::Mouse::getPosition(*window).y * (window->getView().getSize().y / window->getSize().y)))) return true;
	return false;
}
