#ifndef GRAPHICS_HPP
#define GRAPHICS_HPP

#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Config.hpp>
#include "Point.hpp"
#include <iostream>
#include <map>
#include <string>
#include <fstream>

//using namespace sf;


typedef std::map<std::string,const sf::Image*> repertoireImage;
typedef std::map<std::string,sf::Sprite*> repertoireSprite;

class Graphics
{
	public :
 		repertoireImage repImage;
	 	repertoireSprite repSprite;
	 	repertoireImage::iterator it;
	 	repertoireSprite::iterator its;
	 	sf::RenderWindow app;
 	private :
 		unsigned int largeur;
 		unsigned int longeur;
 		int  resolution;
 	public :
	// COnstructeur
 	Graphics(): largeur(1072), longeur(700), resolution(32){};
 	
 	// void drawCarre(intmakelongueur, int largeur, Point centre,Shape carre);
 	
 	void Police(const sf::Font& font,std::string nom,sf::String& text);
 	int LoadImage(std::string cle,std::map<std::string,sf::Image>& repertoireImage
 	);
 	void Loadbibli(repertoireImage& repertoireImag);
 	void LoadSprite(repertoireSprite& repSprite,std::string nomfich);
 	sf::Image LoadImage(std::string cle);
 	unsigned int getLargeure(){ return largeur;};
 	unsigned int getLongeure(){ return longeur;};
 	
 	
 };
 
 #endif
