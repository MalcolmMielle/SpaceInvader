#include <iostream>
#define BOOST_TEST_DYN_LINK
#include "Projectile_simple.hpp"
#include "Rectangle.hpp"
#include "Protagoniste.hpp"
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
/*********************
Les constructeur sans argument ne fonctionne pas
Probablement à cause d'une erreur type "déclarer avant" comme j'ai eu dans d'autre truc...
Un truc comme quoi je peux pas le faire après les : mais je dois le faire entre les accolades... :/
*************************/

BOOST_AUTO_TEST_CASE(trying)
{

	Corps<int> c=Corps<int>();
	c.getForme(0).affiche();
	BOOST_CHECK_EQUAL(c.getForme(0).getCentre().getX(),0);
	BOOST_CHECK_EQUAL(c.getForme(0).getCentre().getY(),0);
	c.move(Point<int>(1,1));
	BOOST_CHECK_EQUAL(c.getForme(0).getCentre().getX(),1);
	BOOST_CHECK_EQUAL(c.getForme(0).getCentre().getY(),1);
	//c.erase();
	
	c.getForme(0).move(Point<int>(1,2));
	BOOST_CHECK_EQUAL(c.getForme(0).getCentre().getX(),2);
	BOOST_CHECK_EQUAL(c.getForme(0).getCentre().getY(),3);
	
	
	std::vector<Forme<int>* > f2;
	Rectangle<int> rp2= Rectangle<int>(1, 1, Point<int>());
	f2.push_back(&rp2);
	c.setForme(f2,0);
	std::vector<Forme<int>* > f;
	Rectangle<int>* rp= new Rectangle<int>(1, 1, Point<int>());
	f.push_back(rp);
	c.setForme(f,1);

	
	
	std::vector<Forme<int> *> recta;
	Rectangle<int> rect(1,1,Point<int>());
	recta.push_back(&rect);
	Corps<int> c2(recta,0);
	BOOST_CHECK_EQUAL(c2.getForme(rect),0);
//	BOOST_CHECK_EQUAL(&(c2.getAllForme()),&recta);
	BOOST_CHECK_EQUAL(c2.getForme(rect),0);

	
	std::vector<Forme<int> *> recta2;
	Rectangle<int> rectap(1,1,Point<int>(3,3));
	Rectangle<int> rectap2(1,1,Point<int>(2,2));
	recta2.push_back(&rectap);
	recta2.push_back(&rectap2);
	Corps<int> c3(recta2,0);
	//Test de la collision
	BOOST_CHECK_EQUAL(c3.collide(c2),false);
	Rectangle<int> rata(1,1,Point<int>());
	recta2.push_back(&rata);
	Corps<int> c4(recta2,0);
	BOOST_CHECK(c4.collide(c2));
	
	//Test du destructeur
	Rectangle<int>* rpe1= new Rectangle<int>(1, 1, Point<int>());
	Rectangle<int>* rpe2= new Rectangle<int>(1, 2, Point<int>());
	Rectangle<int>* rpe3= new Rectangle<int>(1, 3, Point<int>());
	std::vector<Forme<int> *> rototo;
	rototo.push_back(rpe1);
	rototo.push_back(rpe3);
	rototo.push_back(rpe2);
	Corps<int> c5(rototo,1);
	
	Rectangle<int>* rpe4= new Rectangle<int>(1, 1, Point<int>());
	Rectangle<int>* rpe5= new Rectangle<int>(1, 2, Point<int>());
	Rectangle<int>* rpe6= new Rectangle<int>(1, 3, Point<int>());
	std::vector<Forme<int> *> rototo2;
	rototo2.push_back(rpe4);
	rototo2.push_back(rpe5);
	rototo2.push_back(rpe6);
	c5.setForme(rototo2,1);
}
