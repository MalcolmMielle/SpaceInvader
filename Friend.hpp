#ifndef FRIEND_HPP
#define FRIEND_HPP

#include <iostream>
#include <vector>
#include "Joueur.hpp"

template <typename T>
class Comportement{
	public : 
	Comportement(){};
};

template <typename T>
class Friend : public Joueur<T>
{
	protected : 
	Comportement<T> _comp;
	
	public : 
	Friend() : Joueur<T>(), _comp(Comportement<T>()){};
	Friend(int pt, Corps<T> corps, Point<T> canon) : Joueur<T>(pt, corps, canon), _comp(Comportement<T>()){};
	Friend(int pt, Corps<T> corps, Point<T> canon, Comportement<T> comp) : Joueur<T>(pt, corps, canon), _comp(comp){};
	
	//Accesseur
	const Comportement<T>& getComportement() const {return _comp;};
};

#endif
