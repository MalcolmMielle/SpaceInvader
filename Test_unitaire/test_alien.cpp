#include <iostream>
#define BOOST_TEST_DYN_LINK
#include "Projectile_alien.hpp"
#include "Rectangle.hpp"
#include "Alien.hpp"
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
/*********************

*************************/


BOOST_AUTO_TEST_CASE(trying)
{
	//Test du protagoniste sans la fonction virtuelle.
	Alien<int> pro;
	std::vector<Projectile<int>* > sho;
	pro.shoot(sho);
	BOOST_CHECK_EQUAL(sho.size(), 1);
	BOOST_CHECK_EQUAL(sho[0]->getCorps().getForme(0).getCentre().getX(),0);
	BOOST_CHECK_EQUAL(pro.getCanon().getX(),0);
	pro.shoot(sho);
	pro.shoot(sho);
	pro.shoot(sho);
	sho[0]->move();
	BOOST_CHECK_EQUAL(sho[0]->getCorps().getForme(0).getCentre().getY(),23);
	for(size_t i =0;i<sho.size();i++){
		delete sho[i];
	}
	Alien<int> Ali(20, Point<int>(2,4));
	Ali.move(Point<int>(1,5));
	BOOST_CHECK_EQUAL(Ali.getCorps().getForme(0).getCentre().getX(), 3);
	BOOST_CHECK_EQUAL(Ali.getCorps().getForme(0).getCentre().getY(), 9);
	
	
	Alien<int> Alili(20,Point<int>(2,3));
	std::vector<Projectile<int>* > sho2;
	BOOST_CHECK_EQUAL(Alili.getCanon().getX(),2);
	BOOST_CHECK_EQUAL(Alili.getCanon().getY(),3);
	Alili.shoot(sho2);
	BOOST_CHECK_EQUAL(Alili.getVie(),20);
	Alili.setVie(30);
	BOOST_CHECK_EQUAL(Alili.getVie(),30);
	Alili.minusVie(5);
	BOOST_CHECK_EQUAL(Alili.getVie(),25);
	
	BOOST_CHECK_EQUAL(sho2[0]->getCorps().getForme(0).getCentre().getX(),2);
	BOOST_CHECK_EQUAL(sho2[0]->getCorps().getForme(0).getCentre().getY(),25);
	
	Projectile_alien<int> proli(-1,Point<int>(2,3));
	Projectile_simple<int> proli2(-1,Point<int>(2,3));
	Projectile<int>* proj=&proli;
	Projectile<int>* proj2=&proli2;
	Protagoniste<int>* prop=&Alili;
	BOOST_CHECK_EQUAL(prop->collide(*proj),false);
	BOOST_CHECK_EQUAL(prop->collide(*proj2),true);
	
	
}
	
