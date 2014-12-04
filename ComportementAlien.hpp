#ifndef COMPOALIEN_HPP
#define COMPOALIEN_HPP

#include <iostream>
#include <vector>
#include "Jeu.hpp"
#include "Comportement.hpp"
#include "Alien.hpp"

template<typename T>
class ComportementAlien : public Comportement<T>
{
	protected :
	int _sens;
	int _compte;
	int _Vmax;
	int _nstill;
	int _nmax;
	public :
	ComportementAlien(int max) : _sens(1), _compte(0), _Vmax(-1), _nstill(-1), _nmax(-1){};
	virtual ~ComportementAlien(){};
	virtual const Point<T>* generic(Jeu<T>& jeu);
	int getSens(){return _sens;};
	int get_nmax(){return _nmax;};
	int get_Vmax(){return _Vmax;};
	T maxDistance(const std::vector<Alien<T>*>& aliens);
	T minDistance(const std::vector<Alien<T>*>& aliens, Jeu<T>& jeu);
	
};
	
template <typename T>
const Point<T>* ComportementAlien<T>::generic(Jeu<T>& jeu){
	//Calcul la vitesse de deplacement des aliens
	//std::cout<<"GET IN "<<std::endl;
	if(_nstill==-1){
		_nstill=jeu.getAllAlien().size();
	}
	if(_nmax==-1){
		_nmax=jeu.getAllAlien().size();
	}
	if(_Vmax==-1){
		_Vmax=-9*sin(_nstill*PI/(2*_nmax))+10;
	}
	if(jeu.getAllAlien().size()<size_t(_nstill)){
		_nstill=jeu.getAllAlien().size();
		_Vmax=-9*sin(_nstill*PI/(2*_nmax))+10;
	}
	//Vois le maximum est minimum pour vérifier le sens.	
	T max=jeu.getLon();
	T maxD=maxDistance(jeu.getAllAlien());
	T minD=minDistance(jeu.getAllAlien(), jeu);
	std::cout << " le maximum est de "<<maxD<< " et le min "<<minD<< " et la largeur "<< max << " le nmxax " <<_nmax << " le Vmax " <<_Vmax <<" le still " << _nstill<<std::endl;
	std::cout << "ON a alors sens *V = "<<_sens*_Vmax <<std::endl;
	_compte=_compte+_sens;
	if(maxD+(_sens*_Vmax)>=max || minD+(_sens*_Vmax)<0)
	{
		std::cout <<"In there "<<std::endl;
		Point<T>* p=new Point<T>(0,20);
		_sens=-_sens;
		return p;
	}
	else{
		std::cout <<"That was it "<<std::endl;
		Point<T>* p=new Point<T>(_sens*_Vmax,0);
		return p;
	}
}



template <typename T>
T ComportementAlien<T>::maxDistance(const std::vector<Alien<T>* >& aliens){
	int max=0;
	for(typename std::vector<Alien<T>*>::const_iterator it=aliens.begin();it!=aliens.end();){
		for(typename std::vector<Forme<T>*>::const_iterator itforme=(*it)->getCorps().getAllForme().begin();itforme!=(*it)->getCorps().getAllForme().end();){
			if((*itforme)->getCentre().getX()>max){
				max=(*itforme)->getCentre().getX();
			}
			++itforme;
		}
		++it;
	}
	return max;
}

template <typename T>
T ComportementAlien<T>::minDistance(const std::vector<Alien<T>* >& aliens, Jeu<T>& jeu){
	int min=jeu.getLon();
	for(typename std::vector<Alien<T>*>::const_iterator it=aliens.begin();it!=aliens.end();){
		for(typename std::vector<Forme<T>*>::const_iterator itforme=(*it)->getCorps().getAllForme().begin();itforme!=(*it)->getCorps().getAllForme().end();){
			if((*itforme)->getCentre().getX()<min){
				min=(*itforme)->getCentre().getX();
			}
			++itforme;
		}
		++it;
	}
	return min;
}

#endif
