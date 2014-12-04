#ifndef PROJEC_HPP
#define PROJEC_HPP

#include <iostream>
#include <vector>
#include "Corps.hpp"
#include "Projectile.hpp"
#include "Rectangle.hpp"
#include "Obstacle.hpp"
template <typename T>
class Projectile_alien;

template <typename T>
class Projectile_simple : public Projectile<T>
{
	//Attributs
	private :
	//Constucteurs
	public :
	Projectile_simple() : Projectile<T>(){};
	
	Projectile_simple(int etat,const Point<T>& p) : Projectile<T>(etat) {
		Rectangle<T>* rec= new Rectangle<T>(30,10, p);
		std::vector<Forme<T>* > f;
		f.push_back(rec);
		this->_corps.setForme(f,1);
	};
	
	/*virtual ~Projectile_simple(){
		std::cout << "trying to ERASE projectile_simpe "<<std::endl;
		};*/
	//methodes
	void move();
	virtual bool collide(const Projectile<T>& pro) const;
	virtual bool collide(const Protagoniste<T>& cor) const ;
	virtual bool collide(const Obstacle<T>& cor) const ;
	virtual bool collide(const Projectile_simple<T>& pro) const;
	virtual bool collide(const Projectile_alien<T>& pro) const;
	void affiche() const{
		std::cout<<"Je suis en projectile en "<< this->_corps.getForme(0).getCentre().getX() << " et " <<this->_corps.getForme(0).getCentre().getY() << std::endl;
	}
};

template <typename T>
inline void Projectile_simple<T>::move(){

	for(size_t i =0;i<this->_corps.getAllForme().size();i++){
		this->_corps.getForme(i).move(Point<T>(0,this->_etat));
	}
}

template <typename T>
inline bool Projectile_simple<T>::collide(const Projectile<T>& pro) const {
		std::cout << "Not NIce1"<<std::endl;	
		//return this->_corps.collide(pro.getCorps());
		return pro.collide(*this);		
}

template <typename T>
inline bool Projectile_simple<T>::collide(const Protagoniste<T>& pro) const {
		std::cout << "Not NIce2"<<std::endl;	
		//return this->_corps.collide(pro.getCorps());
		return pro.collide(*this);
}

template <typename T>
inline bool Projectile_simple<T>::collide(const Obstacle<T>& pro) const {
		return this->_corps.collide(pro.getCorps());
}

template <typename T>
inline bool Projectile_simple<T>::collide(const Projectile_simple<T>& pro) const {
		
		return this->_corps.collide(pro.getCorps());
}

template <typename T>
inline bool Projectile_simple<T>::collide(const Projectile_alien<T>& pro) const {
		
		return this->_corps.collide(pro.getCorps());
}


#endif
