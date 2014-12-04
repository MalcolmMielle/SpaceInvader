#ifndef ENVI_HPP
#define ENVI_HPP

#include <iostream>
#include <vector>
#include "Jeu.hpp"
#include "Graphics.hpp"

template <typename T>
class Environnement{
	public : 
	Environnement(int nbJ) : nbJoueur(nbJ){};
	Jeu<T>* jeu;
	virtual ~Environnement(){};
	
	Jeu<T>* initJeu();
	void deplace(Jeu<T>& jeu,Graphics& G);
	void shoot(Jeu<T>& jeu);
	void mainGame(Graphics& G);
	void paint(Jeu<T>& jeu, Graphics& G);
	int nbJoueur;
};

template <typename T>
Jeu<T>* Environnement<T>::initJeu(){
	ComportementAlien<int>* comp = new ComportementAlien<int>(15);
	Jeu<int>* jeu = new Jeu<int>(1000, 700,comp);
	for(int i=0;i<3;i++){
		for(int j=0;j<5;++j){
			jeu->add(new Alien<int>(1, Point<int>(j*25, i*25)));
		}
	}
	Joueur<int>* joueur=new Joueur<int>(20, Point<int>(100,600));
	jeu->add(joueur);
	if (nbJoueur>1){
		for (int i = 1; i<nbJoueur;i++){
		Joueur<int>* joueur=new Joueur<int>(20, Point<int>((i+1)*100,600));
		jeu->add(joueur);
		}
	
	}
	return jeu;
}
template <typename T>
void Environnement<T>::paint(Jeu<T>& jeu, Graphics& G){
	jeu.paint(G);

}
template <typename T>
void Environnement<T>::deplace(Jeu<T>& jeu,Graphics& G){
	jeu.deplaceAlien();
	jeu.shootAlien();
	jeu.deplaceJoueur(G);
	jeu.deplaceProj();
	jeu.destroyProj();
	//if (jeu.getAllProj().size()>0)
	jeu.getCollision();
}

template <typename T>
void Environnement<T>::mainGame(Graphics& G){
	Jeu<T>* jeu=initJeu();
	while(jeu->getAllAlien().size()>0 && jeu->getAllJoueur().size()>0){
		deplace(*jeu,G);
		//std::cout<<"On est dans Jeu lol "<<G.repSprite.size()<<" "<<std::endl;
		jeu->affiche();
		G.app.Clear();// On efface l'écran
		paint(*jeu,G);// On repaint tous
		G.app.Display();//On réaffiche tout
	}
}

#endif
	
	
	





