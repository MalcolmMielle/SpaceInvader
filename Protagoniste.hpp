#ifndef PROT_HPP
#define PROT_HPP

#include <iostream>
#include <vector>
#include "Corps.hpp"
#include "Point.hpp"
#include "Projectile_alien.hpp"

template <typename T>
class Protagoniste
{
	 
	protected : 
	int _ptvie;
	Corps<T> _corps;
	Point<T> _canon;
	public : 
	Protagoniste() : _ptvie(0), _corps(Corps<T>()), _canon(Point<T>()){};
	Protagoniste(int pt, const Corps<T>& corps, const Point<T>& canon) : _ptvie(pt), _corps(corps), _canon(canon){};
	//Nouveau constructeur
	Protagoniste(int pt, const Point<T>& p) : _ptvie(pt), _corps(Corps<T>()), _canon(p){};
	
	virtual ~Protagoniste(){};
	
	//Accesseur
	const Corps<T>& getCorps() const {return _corps;}
	const Point<T>& getCanon() const {return _canon;}	
	virtual int getVie(){return _ptvie;}
	virtual void setVie(int p){ _ptvie=p;};
	virtual void minusVie(int p) {_ptvie=_ptvie-p;};
		
	virtual void shoot(std::vector<Projectile<T>* >& pro)=0;
	virtual void move(const Point<T>& p);
	virtual bool collide(const Projectile<T>& p) const {
	std::cout<<"START"<< std::endl;
		return p.collide(*this);
	}
	virtual bool collide(const Projectile_simple<T>& p) const {
		return this->_corps.collide(p.getCorps());
	}
	virtual bool collide(const Projectile_alien<T>& p) const {
		return this->_corps.collide(p.getCorps());
	}
};

template <typename T>
inline void Protagoniste<T>::move(const Point<T>& p){
	_corps.move(p);
	AddP<T> add;
	_canon=add(_canon,p);
}
#endif

