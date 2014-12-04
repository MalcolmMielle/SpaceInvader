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
	//Forme f;
	Point<int> p;
	BOOST_CHECK_EQUAL(p.getX(),0);
	BOOST_CHECK_EQUAL(p.getY(),0);
	Point<int> p3(2,3);
	BOOST_CHECK_EQUAL(p3.getX(),2);
	BOOST_CHECK_EQUAL(p3.getY(),3);
	p=p3;
	BOOST_CHECK_EQUAL(p.getX(),2);
	BOOST_CHECK_EQUAL(p.getY(),3);
	p.setY(p.getY()+1);
	BOOST_CHECK_EQUAL(p.getY(),4);
	
	//test template
	Point<double> p4(2.3,4.2);
	Point<double> p5(2.3,4.2);;
	BOOST_CHECK_EQUAL(p4.getX(),2.3);
	BOOST_CHECK_EQUAL(p4.getY(),4.2);
	BOOST_CHECK_EQUAL(p5.getX(),2.3);
	BOOST_CHECK_EQUAL(p5.getY(),4.2);
	Point<double> pf;
	AddP<double> add;
	pf=add(p4,p5);
	BOOST_CHECK_EQUAL(pf.getX(),4.6);
	BOOST_CHECK_EQUAL(pf.getY(),8.4);
	BOOST_CHECK(p5==p4);
	p4=pf;
	BOOST_CHECK(p4==pf);
	
	
}
