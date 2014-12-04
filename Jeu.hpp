#ifndef JEU_HPP
#define JEU_HPP

#ifndef PI
#define PI 3.14159265358979323846
#endif

#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>
#include <stdexcept>
#include <time.h>
#include <cstdlib>  
#include "Protagoniste.hpp"
#include "Obstacle.hpp"
#include "Projectile_simple.hpp"
#include "Protagoniste.hpp"
#include "Comportement.hpp"
#include "ComportementAlien.hpp"
#include "Joueur.hpp"
#include "Alien.hpp"
#include "Graphics.hpp"
#include "Menu.hpp"

template <typename T>
class Jeu
{
	protected : 
	std::vector<Projectile<T> *> _projlist;
	std::vector<Obstacle<T> *> _obslist;
	std::vector<Alien<T>* > _alienlist;
	std::vector<Joueur<T>* > _joulist;
	T _longeur;
	T _largeur;
	Comportement<T>* _comp;
	private : 
	int _first;
	
	public : 
	Jeu() : _longeur(0), _largeur(0), _comp(), _first(0){
	}
	
	Jeu(T lon, T lar, Comportement<T>* comp) : _longeur(lon), _largeur(lar), _comp(comp), _first(0){};
	
	Jeu(T lon, T lar, std::vector<Projectile<T> *> projlist, std::vector<Obstacle<T> *> obslist, std::vector<Alien<T>* > alienlist, std::vector<Joueur<T>* > joulist, Comportement<T>* comp) : _projlist(projlist), _obslist(obslist), _alienlist(alienlist), _joulist(joulist), _largeur(lar), _longeur(lon), _comp(comp), _first(0){};
	
	~Jeu(){
		for(typename std::vector<Projectile<T>*>::iterator it=_projlist.begin();it!=_projlist.end();){
			delete(*it);
			_projlist.erase(it);
		}
		for(typename std::vector<Alien<T>*>::iterator it=_alienlist.begin();it!=_alienlist.end();){
			delete(*it);
			_alienlist.erase(it);
		}
		for(typename std::vector<Joueur<T>*>::iterator it=_joulist.begin();it!=_joulist.end();){
			delete(*it);
			_joulist.erase(it);
		}
		for(typename std::vector<Obstacle<T>*>::iterator it=_obslist.begin();it!=_obslist.end();){
			delete(*it);
			_obslist.erase(it);
		}
		delete _comp;
	}
	
	//Accesseurs.
	std::vector<Alien<T>*>& getAllAlien() {return this->_alienlist;}
	//Sert à faire un get avec const correctness actif et pouvoir aussi le modifier des fois :/...
	/*std::vector<Alien<T>*>& getAllAlien() {
		return const_cast<std::vector<Alien<T>*>&>(static_cast<const Jeu*>(this)->getAllAlien());	
	}*/
	
	std::vector<Obstacle<T>*>& getAllObs() {return this->_obslist;}
	std::vector<Projectile<T>*>& getAllProj() {return this->_projlist;}
	std::vector<Joueur<T>*>& getAllJoueur() {return this->_joulist;}
	
	int get(const Projectile<T>* p) const ;
	int get(const Obstacle<T>* p) const ;
	int get(const Alien<T>* p) const ;
	int get(const Joueur<T>* p) const;
	int getLon() {return _longeur;};
	int getLar() {return _largeur;};
	/*int getLar()
	{
		return const_cast<int>(static_cast<const Jeu*>(this)->getLar());
	}*/
	
	void eraseAlien(int i);
	void eraseJoueur(int i);
	void eraseObs(int i);
	void eraseProj(int i);
	
	void erase(Projectile<T>* p);
	void erase(Obstacle<T>* p);
	void erase(Alien<T>* p);
	void erase(Joueur<T>* p);
	
	void add(Projectile<T>* p);
	void add(Obstacle<T>* p);
	void add(Alien<T>* p);
	void add(Joueur<T>* p);
	
	//void paint(Graphics G);
	
	
	//On peut modifier l'objet retourné, mais la fonction ne modifie pas l'objet... !!
	Projectile<T>& getPro(int i) const {return *(_projlist[i]);}
	Obstacle<T>& getObs(int i) const {return *(_obslist[i]);}
	Alien<T>& getAlien(int i) const {return *(_alienlist[i]);}
	Joueur<T>& getJoueur(int i) const {return *(_joulist[i]);}
	
	void deplaceAlien();
	void deplaceJoueur(Graphics& G);
	void getCollision();
	void deplaceProj();
	void destroyProj();
	

	void affiche(){
		std::cout<<"Je suis le jeu et j'ai : "<< _alienlist.size() << " Alien " << _joulist.size() <<" Joueur(s) "<<_obslist.size()<< "Obstacle(s) "<<_projlist.size()<<" Projectile demort lancés è_é !!! " << std::endl;
	}
	
	void shootAlien();
	void paint(Graphics& G);
};

template <typename T>
void Jeu<T>::deplaceJoueur(Graphics& G){
		//std::cout<<"Ca amrche pas dans la boucle ca"<<std::endl;
		
	int nb_joueur=0;
	for(typename std::vector<Joueur<T>*>::iterator it=_joulist.begin();it!=_joulist.end();){
	sf::Event event;
		if (G.app.GetEvent(event))//&& nb_joueur==0)
		{
			
				switch (event.Type){
				case sf::Event::KeyPressed :
				{
				switch(event.Key.Code){
					case sf::Key::Escape :
					{	
					exit(0);// A ne pas utilisé; fuite mémoire
					break;
					}
					case sf::Key::Left :
					{	
				const Point<T>* p= new Point<T>(-10,0);
					if((*it)->getCorps().getForme(0).getCentre().getX()-10>0){
							(*it)->Protagoniste<T>::move(*p);
						}
					delete(p);
					break;
					}
					case sf::Key::Right :
					{	
					const Point<T>* p= new Point<T>(10,0);
					if((*it)->getCorps().getForme(0).getCentre().getX()+30<_longeur){
							(*it)->Protagoniste<T>::move(*p);
						}
					delete(p);
					break;
					}
					case sf::Key::Space ://tire
					{
					(*it)->Joueur<T>::shoot(_projlist);
					break;
					}
					case sf::Key::G :
						{
						//if(!nb_joueur==0){	
						const Point<T>* p= new Point<T>(-10,0);	
						it = _joulist.end()-1;
						if((*it)->getCorps().getForme(0).getCentre().getX()-10>0){
							(*it)->Protagoniste<T>::move(*p);
						}
						delete(p);
						//}
						break;
						}
					case sf::Key::D :
						{	
						const Point<T>* p= new Point<T>(10,0);
						it = _joulist.end()-1;
						if((*it)->getCorps().getForme(0).getCentre().getX()+30<_longeur){
							(*it)->Protagoniste<T>::move(*p);
						}
						delete(p);
						break;
						}
					case sf::Key::F :
					{//tire
					it = _joulist.end()-1;
					(*it)->Joueur<T>::shoot(_projlist);
						
					break;
					}
					default:
					break;
					}
					}
				default:
				break;
				}
			//}
			//else if (G.app.GetEvent(event)){
			std::cout<<"Ca amrche pas dans la bouclelooooooooooooo ca"<<std::endl;
				/*switch (event.Type){
					case sf::Event::KeyPressed :
					{
					switch(event.Key.Code){
						case sf::Key::Escape :
						{	
						exit(0);// A ne pas utilisé; fuite mémoire
						break;
						}
						case sf::Key::Up :
						{
						if(!nb_joueur==0){	
						const Point<T>* p= new Point<T>(-10,0);
						(*it)->Protagoniste<T>::move(*p);
						delete(p);
						}
						break;
						}
						case sf::Key::D :
						{	
						const Point<T>* p= new Point<T>(10,0);
						(*it)->Protagoniste<T>::move(*p);
						delete(p);
						break;
						}
						case sf::Key::F ://tire
						{
						break;
						}
						default:
						break;
						}
					}
					default:
					break;
				}*/
			//}//else
		}//if G.app
		nb_joueur ++;
		it++;
	
	}//For

}

template <typename T>
void Jeu<T>::paint(Graphics& G){

// On paint les joueur
for(typename std::vector<Joueur<T>*>::iterator it=_joulist.begin();it!=_joulist.end();){
	(*it)->Joueur<T>::paint(G);
	it++;
		}
		/*
// On paint les Obstacle
for(typename std::vector<Obstacle<T>*>::iterator it=_obslist.begin();it!=_obslist.end();){
	(*it)->paint(G);
	it++;
		}*/
// On paint les Alien
for(typename std::vector<Alien<T>*>::iterator it=_alienlist.begin();it!=_alienlist.end();){
	(*it)-> Alien<T>::paint(G);
	it++;
		}
//std::cout<<"Erreur projectileOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOo "<< _projlist.size()<<std::endl;	
for(typename std::vector<Projectile<T>*>::iterator it=_projlist.begin();it!=_projlist.end();){


	(*it)-> Projectile<T>::paint(G);
	it++;	
	}
}

template<typename T>
void Jeu<T>::deplaceProj(){
	for(typename std::vector<Projectile<T>*>::iterator it=_projlist.begin();it!=_projlist.end();){
		(**it).move();
		it++;
	}
}

template <typename T>
int Jeu<T>::get(const Projectile<T>* p) const{
	for (size_t i =0; i<_projlist.size();++i){
		if(p==_projlist[i]){
			return i;
		}
	}
	return -1;
}

template <typename T>
int Jeu<T>::get(const Obstacle<T>* p) const{
	for (size_t i =0; i<_obslist.size();++i){
		if(p==_obslist[i]){
			return i;
		}
	}
	return -1;
}

template <typename T>
int Jeu<T>::get(const Alien<T>* p) const{
	for (size_t i =0; i<_alienlist.size();++i){
		if(p==_alienlist[i]){
			return i;
		}
	}
	return -1;
}

template <typename T>
int Jeu<T>::get(const Joueur<T>* p) const{
	for (size_t i =0; i<_joulist.size();++i){
		if(p==_joulist[i]){
			return i;
		}
	}
	return -1;
}
	
template<typename T>
void Jeu<T>::eraseAlien(int i){
	if(size_t(i)<_alienlist.size()){
		typename std::vector<Alien<T>*>::iterator it=_alienlist.begin()+i;
		delete(*it);
		_alienlist.erase(it);
	}
	else{
		throw std::out_of_range("indices hors limite");
	}
}

template<typename T>
void Jeu<T>::eraseJoueur(int i){
	if(size_t(i)<_joulist.size()){
		typename std::vector<Joueur<T>*>::iterator it=_joulist.begin()+i;
		delete(*it);
		_joulist.erase(it);
	}
	else{
		throw std::out_of_range("indices hors limite");
	}
}

template<typename T>
void Jeu<T>::eraseObs(int i){
	if(size_t(i)<_obslist.size()){
		typename std::vector<Obstacle<T>*>::iterator it=_obslist.begin()+i;
		delete(*it);
		_obslist.erase(it);
	}
	else{
		throw std::out_of_range("indices hors limite");
	}
}

template<typename T>
void Jeu<T>::eraseProj(int i){
	if(size_t(i)<_projlist.size()){
		typename std::vector<Projectile<T>*>::iterator it=_projlist.begin()+i;
		delete(*it);
		_projlist.erase(it);
	}
	else{
		throw std::out_of_range("indices hors limite");
	}
}

template<typename T>
void Jeu<T>::erase(Projectile<T>* p){
//Met les element en fin de liste (remove_if pour une fonction, remove pour un objet en troisième element) puis les supprime (erase)
	for(typename std::vector<Projectile<T>*>::iterator it=_projlist.begin();it!=_projlist.end();){
		if(*it==p){
			delete(*it);
			_projlist.erase(it);
		}
		else{
			it++;
		}
	}
}

template<typename T>
void Jeu<T>::erase(Obstacle<T>* p){
//Met les element en fin de liste (remove_if) puis les supprime (erase)
	for(typename std::vector<Obstacle<T>*>::iterator it=_obslist.begin();it!=_obslist.end();){
		if(*it==p){
			delete(*it);
			_obslist.erase(it);
		}
		else{
			it++;
		}
	}
}

template<typename T>
void Jeu<T>::erase(Alien<T>* p){
//Met les element en fin de liste (remove_if) puis les supprime (erase)
	for(typename std::vector<Alien<T>*>::iterator it=_alienlist.begin();it!=_alienlist.end();){
		if(*it==p){
			delete(*it);
			_alienlist.erase(it);
		}
		else{
			it++;
		}
	}
//Attention ce sont des pointeurs...	_perslist.erase(std::remove(_perslist.begin(), _perslist.end(), &p), _perslist.end());
}

template<typename T>
void Jeu<T>::erase(Joueur<T>* p){
//Met les element en fin de liste (remove_if) puis les supprime (erase)
	for(typename std::vector<Joueur<T>*>::iterator it=_joulist.begin();it!=_joulist.end();){
		if(*it==p){
			delete(*it);
			_joulist.erase(it);
		}
		else{
			it++;
		}
	}
//Attention ce sont des pointeurs...	_perslist.erase(std::remove(_perslist.begin(), _perslist.end(), &p), _perslist.end());
}
	
template<typename T>
void Jeu<T>::add(Projectile<T>* p){
//Met les element en fin de liste (remove_if) puis les supprime (erase)
	_projlist.push_back(p);
}

template<typename T>
void Jeu<T>::add(Obstacle<T>* p){
//Met les element en fin de liste (remove_if) puis les supprime (erase)
	_obslist.push_back(p);
}

template<typename T>
void Jeu<T>::add(Alien<T>* p){
//Met les element en fin de liste (remove_if) puis les supprime (erase)
	_alienlist.push_back(p);
}

template<typename T>
void Jeu<T>::add(Joueur<T>* p){
//Met les element en fin de liste (remove_if) puis les supprime (erase)
	_joulist.push_back(p);
}

template<typename T>
void Jeu<T>::deplaceAlien(){
	//Mise à jour de la vitesse de déplacement.
	//std::cout<<"Debut de fonction"<<std::endl;
	const Point<T>* p= _comp->generic(*this);
	
	for(typename std::vector<Alien<T>*>::iterator it=_alienlist.begin();it!=_alienlist.end();){
		(*it)->Protagoniste<T>::move(*p);
		++it;
	};
	delete(p);
}

template<typename T>
void Jeu<T>::shootAlien(){
	int random;
	if(_first==0){
		srand(time(NULL));
		_first=1;
	}
	for(size_t i=0;i<_alienlist.size();++i){
		random=rand()%100;
		//std::cout<<"Nombre alea "<<random<<std::endl;
		if(random<1){
			//std::cout<<"Shooting"<<std::endl;
			_alienlist[i]->shoot(_projlist);
		}
	}
}

template<typename T>
void Jeu<T>::destroyProj(){
	for(typename std::vector<Projectile<T>*>::iterator it=_projlist.begin();it!=_projlist.end();){
		if((**it).getCorps().getForme(0).getCentre().getY()>_longeur ||(**it).getCorps().getForme(0).getCentre().getY()<0){
			 delete(*it);
			_projlist.erase(it);
		}
		else{
			++it;
		}
	}
}

template<typename T>
void Jeu<T>::getCollision(){
	bool result;
	for(typename std::vector<Projectile<T>*>::iterator it=_projlist.begin();it!=_projlist.end();){
		for(typename std::vector<Obstacle<T>*>::iterator ito=_obslist.begin();ito!=_obslist.end();){
			if(it!=_projlist.end()){
				result = (*it)->collide(**ito);
				//std::cout<<"SORTIE 1"<<std::endl;
				if(result==true){
					//std::cout<<"true"<<std::endl;
					delete(*ito);
					_obslist.erase(ito);
					delete(*it);
					_projlist.erase(it);
				}
				else{
					//std::cout<<"false"<<std::endl;
						++ito;
				}
			}
			else{
				break;
			}
		}
		if(it!=_projlist.end()){
			++it;
		}
	}
	
	for(typename std::vector<Projectile<T>*>::iterator it=_projlist.begin();it!=_projlist.end();){
		for(typename std::vector<Alien<T>*>::iterator ito=_alienlist.begin();ito!=_alienlist.end();){
			if(it!=_projlist.end()){
				result = (*it)->collide(**ito);
				if(result==true){
					(**ito).minusVie((**it).getPuissance());
					if((**ito).getVie()<=0){
						delete(*ito);
						_alienlist.erase(ito);
					}
					delete(*it);
					_projlist.erase(it);
				}
				else{
						++ito;
				}
			}
			else{
				break;
			}
		}
		if(it!=_projlist.end()){
			++it;
		}
	}
	
	for(typename std::vector<Projectile<T>*>::iterator it=_projlist.begin();it!=_projlist.end();){
		for(typename std::vector<Joueur<T>*>::iterator ito=_joulist.begin();ito!=_joulist.end();){
			if(it!=_projlist.end()){
				result = (*it)->collide(**ito);
				//std::cout<<"SORTIE 3"<<std::endl;
				if(result==true){
					//std::cout<<"true"<<std::endl;
					(**ito).minusVie((**it).getPuissance());
					if((**ito).getVie()<=0){
						delete(*ito);
						_joulist.erase(ito);
					}
					delete(*it);
					_projlist.erase(it);
				}
				else{
					//std::cout<<"false"<<std::endl;
						++ito;
				}
			}
			else{
				break;
			}
		}
		if(it!=_projlist.end()){
			++it;
		}
	}
}


	

#endif
