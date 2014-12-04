#include <iostream>
#define BOOST_TEST_DYN_LINK
#include "Projectile_simple.hpp"
#include "Rectangle.hpp"
//#include "Friend.hpp"
#include "Alien.hpp"
#include "Comportement.hpp"
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
/*********************

*************************/

BOOST_AUTO_TEST_CASE(trying)
{
	//Test du projectile
		
	Projectile_simple<int> p3(1, Point<int>(2,2));
	BOOST_CHECK_EQUAL(p3.getCorps().getForme(0).getCentre().getX(),2);
	BOOST_CHECK_EQUAL(p3.getCorps().getForme(0).getCentre().getY(),2);
	Rectangle<int>& pet = dynamic_cast<Rectangle<int>& > (p3.getCorps().getForme(0));
	BOOST_CHECK_EQUAL(pet.getLargeur(),2);
	
	Projectile_simple<int> p2;
	BOOST_CHECK_EQUAL(p2.getCorps().getForme(0).getCentre().getX(),0);
	BOOST_CHECK_EQUAL(p2.getCorps().getForme(0).getCentre().getY(),0);
	
	p2.move();
	BOOST_CHECK_EQUAL(p2.getCorps().getForme(0).getCentre().getX(),0);
	BOOST_CHECK_EQUAL(p2.getCorps().getForme(0).getCentre().getY(),1);
			
	p2.changeEtat();
	p2.move();
	BOOST_CHECK_EQUAL(p2.getCorps().getForme(0).getCentre().getX(),0);
	BOOST_CHECK_EQUAL(p2.getCorps().getForme(0).getCentre().getY(),0);
	p2.changeEtat();
	
	//Test destruction
	Projectile_simple<int> p;
	
	//Test collision
	Projectile_simple<int> pet1(1,Point<int>(2,3));
	Projectile_simple<int> pet2(-1,Point<int>(2,3));
	pet1.affiche();
	pet2.affiche();
	BOOST_CHECK(pet1.collide(pet2));
	pet1.move();
	pet1.move();
	pet1.affiche();
	pet2.affiche();
	BOOST_CHECK_EQUAL(pet1.collide(pet2),false);
	
	Rectangle<int> rec= Rectangle<int>(2,2, Point<int>());
	std::vector<Forme<int>* > f;
	f.push_back(&rec);
	Corps<int> c= Corps<int>(f, 0);
	Alien<int>* alip= new Alien<int>(20,c,Point<int>());
	Protagoniste<int>* ali =dynamic_cast<Protagoniste<int> *>(alip);
//	BOOST_CHECK_EQUAL(pet1.collide(*ali), false);
	Projectile_simple<int> coo(1,Point<int>());
	BOOST_CHECK_EQUAL(coo.collide(*ali), true);
	delete alip;
	
	//Test du mouvement et de la collision
	Rectangle<int> r(1,1,Point<int>(0,0));
	std::vector<Forme<int>*> f1;
	f1.push_back(&r);
	Alien<int> alib(20,Corps<int>(f1,0), Point<int>(0,0));
	Projectile_simple<int> ps(-1,Point<int>(0,3));
	int i=0;
	while(ps.collide(alib)==false && i<5){
		ps.move();
		i++;
		alib.affiche();
		ps.affiche();
	}
	BOOST_CHECK_EQUAL(i,3);
	
	
	
}
