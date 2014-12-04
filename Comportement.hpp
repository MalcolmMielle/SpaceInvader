#ifndef COMPO_HPP
#define COMPO_HPP

#include <iostream>
#include <vector>

template <typename T>
class Jeu;

template <typename T>
class Comportement{
	public : 
	Comportement(){};
	virtual ~Comportement(){};
	//Fonction de base de reflection
	virtual const Point<T>* generic(Jeu<T>& jeu)=0;
};
#endif
