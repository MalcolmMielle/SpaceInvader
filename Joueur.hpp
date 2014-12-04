#ifndef JOU_HPP
#define JOU_HPP

#include <iostream>
#include <vector>
#include "Protagoniste.hpp"
#include "Shootspe.hpp"
#include "Graphics.hpp"
#include "Projectile.hpp"

template <typename T>
class Joueur : public Protagoniste<T>, public Shootspe<T>{
	//Protected les bonus

	public : 
	Joueur() : Protagoniste<T>() {};
	Joueur(int pt,const Corps<T>& corps, const Point<T>& canon) : Protagoniste<T>(pt, corps, canon) {};
	Joueur(int pt, const Point<T>& p) : Protagoniste<T>(pt,p) {
		Rectangle<T>* rec = new Rectangle<T>(20,30, p);
		std::vector<Forme<T>* > f;
		f.push_back(rec);
		this->_corps.setForme(f,1);
	}
	
	virtual void shootMissile(std::vector<Projectile<T>* >& pro);
	virtual void shootFlamme(std::vector<Projectile<T>* >& pro);
	virtual void shoot(std::vector<Projectile<T>* >& pro);
	void paint(Graphics& G);

	
};

template <typename T>
void Joueur<T>::paint(Graphics& G){
	repertoireSprite::iterator  it;
	it = G.repSprite.find("joueur");
	if(it == G.repSprite.end())
	std::cout<<"Chargement du sprite alien impossible "<<G.repSprite.size()<<" "<<std::endl;
	sf::Sprite *imD = it->second ;
	//imD->SetPosition(this->_corps.getForme(0).getCentre().getX(),this->_corps.getForme(0).getCentre().getY());
	imD->SetPosition(this->Protagoniste<int>::getCanon().getX(),this->Protagoniste<int>::getCanon().getY());
	G.app.Draw(*imD);
	//std::cout<<"Je paint un Joueur"<<std::endl;
	
}



template <typename T>
inline void Joueur<T>::shoot(std::vector<Projectile<T>* >& pro)
{	
	AddP<T> add;
	Point<T> point = add(this->_canon, Point<T>(0,-30));
	pro.push_back(new Projectile_simple<T>(-1,point));
}
template <typename T>
inline void Joueur<T>::shootMissile(std::vector<Projectile<T>* >& pro){
	Shootspe<T>::shootMissile(pro);
	//std::cout<<"JOueur shoot"<<std::endl;
}

template <typename T>
inline void Joueur<T>::shootFlamme(std::vector<Projectile<T>* >& pro){
	Shootspe<T>::shootFlamme(pro);
	//std::cout<<"JOueur shoot fmalle"<<std::endl;
}

#endif
