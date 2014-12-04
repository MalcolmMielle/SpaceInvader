#ifndef MENU_HPP
#define MENU_HPP

#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Graphics.hpp"


class Menu
{
	public :
	//Constructeur
	Menu(){};
	int affichageMenu(Graphics& G);
	int eventMouse(const sf::Input& input,Graphics& G);
	void drawfixe(Graphics& G);
	void MoveSprite(std::string nomSprite,float x, float y);
	//void initSpriteMenu(repertoireSprite& sprite);
	
	// Attribut
	private :
		repertoireSprite sprite;
		repertoireSprite::iterator it;

};
#endif
