#include <iostream>
#define BOOST_TEST_DYN_LINK
#include "Projectile_simple.hpp"
#include "Rectangle.hpp"
#include "Protagoniste.hpp"
#include "Friend.hpp"
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
/*********************

*************************/

BOOST_AUTO_TEST_CASE(trying)
{
	Joueur<int> j ;
	std::vector<Projectile<int>* > v;
	j.shootMissile(v);
	j.shootFlamme(v);
	j.shoot(v);
	
	Friend<int> f;
	f.shootMissile(v);
	f.shootFlamme(v);
	
	Corps<int> c=Corps<int>();
	std::vector<Forme<int>* > f2;
	Rectangle<int> rp2= Rectangle<int>(1, 1, Point<int>());
	f2.push_back(&rp2);
	c.setForme(f2,0);
	
	Joueur<int>jou(20, c, Point<int>());
	
	Projectile_alien<int> proli(-1,Point<int>(0,0));
	Projectile_simple<int> proli2(-1,Point<int>(0,0));
	Projectile_simple<int> proli3(-1,Point<int>(45,0));
	Projectile<int>* proj=&proli;
	Projectile<int>* proj2=&proli2;
	Projectile<int>* proj3=&proli3;
	Protagoniste<int>* prop=&jou;
	
	BOOST_CHECK_EQUAL(prop->collide(*proj),true);
	BOOST_CHECK_EQUAL(prop->collide(*proj2),true);
	BOOST_CHECK_EQUAL(prop->collide(*proj3),false);
	
	
}
