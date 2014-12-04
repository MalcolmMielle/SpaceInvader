#include <iostream>
#define BOOST_TEST_DYN_LINK
#include <time.h>
#include <cstdlib>
#include "Projectile_simple.hpp"
#include "Obstacle.hpp"
#include "Alien.hpp"
#include "Jeu.hpp"
#include "ComportementAlien.hpp"
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
/*********************

*************************/

BOOST_AUTO_TEST_CASE(trying)
{
	
	Jeu<int> j;
	Alien<int>* al=new Alien<int>();
	Projectile_simple<int>* p=new Projectile_simple<int>();
	Obstacle<int> *o=new Obstacle<int>();
	Joueur<int>* joueur= new Joueur<int>;
	j.add(p);
	j.add(o);
	j.add(joueur);
	j.deplaceProj();
	j.getAllAlien().push_back(al);
	BOOST_CHECK_EQUAL(j.getAllAlien().size(),1);
	BOOST_CHECK_EQUAL(j.getAllObs().size(),1);
	BOOST_CHECK_EQUAL(j.getAllProj().size(),1);
	BOOST_CHECK_EQUAL(j.getAllJoueur().size(),1);
	BOOST_CHECK_EQUAL(j.get(al),0);
	BOOST_CHECK_EQUAL(j.get(o),0);
	BOOST_CHECK_EQUAL(j.get(p),0);
	BOOST_CHECK_EQUAL(j.get(joueur),0);

	j.eraseAlien(0);
	j.eraseObs(0);
	j.eraseProj(0);
	j.eraseJoueur(0);
	BOOST_CHECK_EQUAL(j.getAllAlien().size(),0);
	BOOST_CHECK_EQUAL(j.getAllObs().size(),0);
	BOOST_CHECK_EQUAL(j.getAllProj().size(),0);
	BOOST_CHECK_EQUAL(j.getAllJoueur().size(),0);
	
	Alien<int>* ali=new Alien<int>();
	BOOST_CHECK_EQUAL(j.get(ali),-1);
	j.add(ali);
	BOOST_CHECK_EQUAL(j.get(ali),0);

	//j.erasePers(0);
	//Test du pointeur
	Alien<int>* al2=new Alien<int>();
	j.add(al2);
	j.affiche();
	j.eraseAlien(0);
	Alien<int>* al3=new Alien<int>();
	j.add(al3);
	j.erase(al3);
	j.affiche();
	Alien<int>* alili2=new Alien<int>(20,Point<int>(6,6));
	j.add(alili2);
	j.affiche();
	
	ComportementAlien<int>* comp = new ComportementAlien<int>(1);
	delete comp;
	j.shootAlien();
	j.shootAlien();
	j.shootAlien();
	j.shootAlien();
	j.shootAlien();
	j.shootAlien();
	j.shootAlien();
	j.shootAlien();
	j.shootAlien();
	j.shootAlien();
	j.affiche();
	
	//test collision
	Alien<int>* alili=new Alien<int>(2,Point<int>(5,5));
	Alien<int>* alili3=new Alien<int>(20,Point<int>(5,5));
	Projectile_simple<int>* propro = new Projectile_simple<int>(1, Point<int>(5,5));
	ComportementAlien<int>* cA2=new ComportementAlien<int>(3);
	Jeu<int> jeu(30, 30, cA2);
	jeu.add(alili);
	jeu.add(propro);
	jeu.add(alili3);

	jeu.affiche();
	jeu.getCollision();
	jeu.affiche();
	BOOST_CHECK_EQUAL(alili->getVie(),1);
	BOOST_CHECK_EQUAL(alili3->getVie(),20);
	jeu.add(new Projectile_simple<int>(1, Point<int>(5,5)))²;
	jeu.getCollision();
	jeu.affiche();
	BOOST_CHECK_EQUAL(jeu.getAllAlien().size(),1);
	BOOST_CHECK_EQUAL(alili3->getVie(),20);


	
}
