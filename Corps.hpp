#ifndef CORPS_HPP
#define CORPS_HPP

#include <iostream>
#include <vector>
#include "Forme.hpp"
#include "Rectangle.hpp"
#include "Point.hpp"

template <typename T>
class Corps
{
	private :
	std::vector<Forme<T>*> _forme_l;
	int _pointeur;
	public :
	//Constructeur
	Corps() : _pointeur(1){
		std::vector<Forme<T>*> vec;
		Rectangle<T>* r= new Rectangle<T>(0, 0, Point<T>());//penser à le detruire.
		vec.push_back(r);
		_forme_l=vec;
		}
		
	Corps(const std::vector<Forme<T>*>& vec, int pointeur) : _forme_l(vec), _pointeur(pointeur){};
	
	virtual ~Corps(){
		std::cout << "trying to ERASE crosp "<<std::endl;
		if(_pointeur==1){
			std::cout << "ERASE crosp "<<std::endl;
			this->erase();
		};
	}
	
	//Methode
	const std::vector<Forme<T>*>& getAllForme() const {return this->_forme_l;}
	int getForme(const Forme<T>& f) const ;
	//On pet modifier l'objet retourné, mais la fonction ne modifie pas l'objet... !!
	Forme<T>& getForme(int i) const {return *(_forme_l[i]);}
	
	bool collide(const Corps<T>& cor) const ;
	void erase();
	//Demande si la forme courrante remplacé possède un pointeur.
	void setForme(std::vector<Forme<T>*>& f, int pointeur);
	//Attentino ANTOINE
	void move(const Point<T>& p){
		for(size_t i=0;i<_forme_l.size();++i){
			_forme_l[i]->move(p);
		}
	}
	virtual void affiche(){
		for(size_t i=0;i<_forme_l.size();++i){
			_forme_l[i]->affiche();
		}
	}
};

template <typename T>
inline void Corps<T>::setForme(std::vector<Forme<T>*>& f, int nouvpointeur){
	if(_pointeur==1){
		this->erase();
	}
	_forme_l=f;
	_pointeur=nouvpointeur;
}

template <typename T>
inline void Corps<T>::erase(){
	int i=0;
	if(_forme_l.size()!=0){
		while(i<static_cast<int>(_forme_l.size())){
			std::cout <<"delete rec "<< i << " " << static_cast<int>(_forme_l.size()) << std::endl;
			delete _forme_l[i];
			++i;
		}
	}
}


template <typename T>
inline int Corps<T>::getForme(const Forme<T>& f) const {

	for(size_t j=0;j<_forme_l.size();++j){
		if(&f==this->_forme_l[j]){
			return j;
		}
	}
	return -1;
}

template <typename T>
inline bool Corps<T>::collide(const Corps<T>& cor) const {
	bool b=false;
	for(size_t i =0;i<_forme_l.size();i++){
		for(size_t j =0;j< cor.getAllForme().size();j++){
			
			b=_forme_l[i]->collide(cor.getForme(j));
			
			if (b==true){
			std::cout<<"Vrai j "<< j << std::endl;
				break;
			}
		}
		if (b==true){
			std::cout<<"Vrai i "<< i << std::endl;
			break;
		}
	}
	return b;
}

#endif
