#ifndef ALIEN_HPP
#define ALIEN_HPP

#include <iostream>
#include <vector>
#include "Corps.hpp"
#include "Protagoniste.hpp"
#include "Projectile.hpp"
#include "Rectangle.hpp"
#include "Graphics.hpp"


template <typename T>
class Alien : public Protagoniste<T>
{
	protected :
	
	
	public :
	Alien() : Protagoniste<T>(){};
	Alien(int pt, const Corps<T>& corps, const Point<T>& canon) : Protagoniste<T>(pt, corps, canon){};
	//Definition du corps et du canon
	//L'alien est un corps de 5*5 pour l'instant.
	Alien(int pt, const Point<T>& p) : Protagoniste<T>(pt, p) {
		Rectangle<T>* rec = new Rectangle<T>(20,20, p);
		std::vector<Forme<T>* > f;
		f.push_back(rec);
		this->_corps.setForme(f,1);
	}
	virtual ~Alien(){
	};
	virtual void shoot(std::vector<Projectile<T>* >& pro);
	virtual void affiche(){
		std::cout<<"Je suis un Alien et mon corps est ";
		this->_corps.affiche();
	}
	virtual bool collide(const Projectile_alien<T>& p) const {return false;};
	void paint(Graphics& G);
};

template <typename T>
void Alien<T>::paint(Graphics& G){
	repertoireSprite::iterator  it;
	it = G.repSprite.find("alien");
	if(it == G.repSprite.end())
	std::cout<<"Chargement du sprite alien impossible "<<G.repSprite.size()<<" "<<std::endl;
	sf::Sprite *imD = it->second ;
	imD->SetPosition(this->_corps.getForme(0).getCentre().getX(),this->_corps.getForme(0).getCentre().getY());
	G.app.Draw(*imD);
	//std::cout<<"Je paint un alien"<<std::endl;
	
}

template <typename T>
inline void Alien<T>::shoot(std::vector<Projectile<T>* >& pro)
{	
	AddP<T> add;
	Point<T> point = add(this->_canon, Point<T>(0,22));
	pro.push_back(new Projectile_alien<T>(1,point));
}

/*
template <typename T>
inline void Alien<T>::move(){	
	const Point<T>* p = this->_comp->generic();
	this->Protagoniste<T>::move(*p);
	delete p; 	
}*/
#endif
