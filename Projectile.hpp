#ifndef PROJ_HPP
#define PROJ_HPP

#include <iostream>
#include <vector>
#include "Corps.hpp"
#include "Projectile.hpp"
#include "Rectangle.hpp"
#include "Obstacle.hpp"
#include "Graphics.hpp"

template <typename T>
class Projectile_simple;

template <typename T>
class Projectile_alien;

template <typename T>
class Protagoniste;


template <typename T>
class Projectile
{
	//Attributs
	protected :
	Corps<T> _corps;
	int _etat;
	int _puissance;
	//Constucteurs
	public :
	Projectile() : _etat(1) {};
	Projectile(int etat) : _corps(Corps<T>()), _etat(etat), _puissance(1){};
	
	//Destructeur
	virtual ~Projectile(){
		std::cout << "trying to ERASE projectile "<<std::endl;
	}
	
	
	const Corps<T>& getCorps() const {return _corps;}
	void changeEtat();
	virtual void move()=0;
	virtual int getPuissance(){return _puissance;};
	virtual bool collide(const Projectile<T>& cor) const =0;
	virtual bool collide(const Projectile_alien<T>& cor) const =0;
	virtual bool collide(const Projectile_simple<T>& cor) const =0;
	virtual bool collide(const Protagoniste<T>& cor) const =0;
	virtual bool collide(const Obstacle<T>& cor) const =0;
	//virtual bool collide(const Projectile_alien<T>& pro) const=0;
	virtual void affiche(){};
	void paint(Graphics& G);
};
template <typename T>
void Projectile<T>::paint(Graphics& G){
	repertoireSprite::iterator  it;
	it = G.repSprite.find("projectile");
	if(it == G.repSprite.end())
	std::cout<<"Chargement du sprite Porjectile impossible "<<G.repSprite.size()<<" "<<std::endl;

	sf::Sprite *imD = it->second ;
	imD->SetPosition(this->_corps.getForme(0).getCentre().getX(),this->_corps.getForme(0).getCentre().getY());
	G.app.Draw(*imD);
	//std::cout<<"Je paint un projectile"<<std::endl;
	
}

template <typename T>
inline void Projectile<T>::changeEtat(){
	if(_etat==1){
		_etat=-1;
	}
	else{
		_etat=1;
	}
}
#endif
