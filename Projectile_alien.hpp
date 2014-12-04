#ifndef PROJSimple_HPP
#define PROJSimple_HPP

#include <iostream>
#include <vector>
#include "Corps.hpp"
#include "Projectile_simple.hpp"

template<typename T>
class Alien;

template <typename T>
class Projectile_alien : public Projectile_simple<T>
{
	public :
	Projectile_alien() : Projectile_simple<T>(){};
	
	Projectile_alien(int etat,const Point<T>& p) : Projectile_simple<T>(etat, p) {};
	virtual bool collide(const Projectile<T>& pro) const;
	virtual bool collide(const Protagoniste<T>& cor) const ;
	virtual bool collide(const Obstacle<T>& cor) const ;
	virtual bool collide(const Projectile_simple<T>& pro) const;
	virtual bool collide (const Alien<T>& al){return false;};
	virtual bool collide(const Projectile_alien<T>& pro) const;
};

template <typename T>
inline bool Projectile_alien<T>::collide(const Projectile<T>& pro) const {
		//std::cout << "NIce1"<<std::endl;	
		return pro.collide(*this);		
}

template <typename T>
inline bool Projectile_alien<T>::collide(const Protagoniste<T>& pro) const {
		//std::cout << "NIce2"<<std::endl;	
		//return this->_corps.collide(pro.getCorps());
		return pro.collide(*this);
}

template <typename T>
inline bool Projectile_alien<T>::collide(const Obstacle<T>& pro) const {
		return this->_corps.collide(pro.getCorps());
}

template <typename T>
inline bool Projectile_alien<T>::collide(const Projectile_simple<T>& pro) const {
		
		return this->_corps.collide(pro.getCorps());
}

template <typename T>
inline bool Projectile_alien<T>::collide(const Projectile_alien<T>& pro) const {
		
		return this->_corps.collide(pro.getCorps());
}

#endif
