#include <iostream>
#define BOOST_TEST_DYN_LINK
#include "Rectangle.hpp"
#include "Forme.hpp"
#include "Corps.hpp"
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
/*********************
Les constructeur sans argument ne fonctionne pas
Probablement à cause d'une erreur type "déclarer avant" comme j'ai eu dans d'autre truc...
Un truc comme quoi je peux pas le faire après les : mais je dois le faire entre les accolades... :/
*************************/
BOOST_AUTO_TEST_CASE(trying)
{

	Rectangle<int> rect(3,3,Point<int>(1, 2));
	BOOST_CHECK_EQUAL(rect.getCentre().getX(),1);
	BOOST_CHECK_EQUAL(rect.getCentre().getY(),2);
	BOOST_CHECK_EQUAL(rect.getLargeur(),3);
	BOOST_CHECK_EQUAL(rect.getLongueur(),3);
	Rectangle<int> rect2;
	BOOST_CHECK_EQUAL(rect2.getCentre().getX(),0);
	BOOST_CHECK_EQUAL(rect2.getCentre().getY(),0);
	BOOST_CHECK_EQUAL(rect2.getLargeur(),0);
	BOOST_CHECK_EQUAL(rect2.getLongueur(),0);
	
	//TEST DE LA COLLISION
	Rectangle<int> r3 = Rectangle<int>(1, 1, Point<int>(0,0));
	Rectangle<int> r4 = Rectangle<int>(1, 1, Point<int>(0,0));
	Forme<int>& r2 = dynamic_cast<Forme<int>& >(r3);
	Forme<int>& r = dynamic_cast<Forme<int>& >(r4);
	
	r2.affiche();
	r.affiche();
	BOOST_CHECK_EQUAL(r.collide(r2),true);
	r.setCentre(Point<int>(0,1));
	BOOST_CHECK_EQUAL(r2.collide(r),false);
	r.setCentre(Point<int>(0,-1));
	BOOST_CHECK_EQUAL(r2.collide(r),false);
	r.setCentre(Point<int>(1,0));
	BOOST_CHECK_EQUAL(r2.collide(r),false);
	r.setCentre(Point<int>(-1,0));
	BOOST_CHECK_EQUAL(r2.collide(r),false);
	r.setCentre(Point<int>(1,1));
	BOOST_CHECK_EQUAL(r2.collide(r),false);
	
	//move
	Point<int> movement(1,2);
	rect2.move(movement);
	BOOST_CHECK_EQUAL(rect2.getCentre().getX(),1);
	BOOST_CHECK_EQUAL(rect2.getCentre().getY(),2);
	
	//Detsructeur
	Rectangle<int>* re= new Rectangle<int>();
	delete re;
}	
	
	
	

