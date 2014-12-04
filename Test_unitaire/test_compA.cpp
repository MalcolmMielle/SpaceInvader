#include <iostream>
#define BOOST_TEST_DYN_LINK
#include "Rectangle.hpp"
#include "Forme.hpp"
#include "Alien.hpp"
#include "ComportementAlien.hpp"
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
/*********************
*************************/
BOOST_AUTO_TEST_CASE(trying)
{
	ComportementAlien<int>* cA= new ComportementAlien<int>(3);
	Alien<int> ali(20, Point<int>(2,3));
/*	ali.affiche();
	int i=0;
	while(i<10){
		ali.Protagoniste::move(Point<int>(2,3));
		ali.affiche();
		++i;
	}*/
	std::vector<Alien<int>*> al;
	al.push_back(&ali);
	cA->maxDistance(al);
	delete cA;
	
	ComportementAlien<int>* cA2=new ComportementAlien<int>(3);
	Jeu<int> jeu(30, 30, cA2);
	Alien<int>* alien= new Alien<int>(20, Point<int>(5,3));
	Alien<int>* alien2= new Alien<int>(20, Point<int>(2,3));
	Alien<int>* alien3= new Alien<int>(20, Point<int>(9,3));
	
	jeu.add(alien);
	jeu.add(alien2);
	jeu.add(alien3);
	
	const Point<int>* p=cA2->generic(jeu);
	BOOST_CHECK_EQUAL(p->getX(),1);
	BOOST_CHECK_EQUAL(p->getY(),0);
	int pro=p->getX();
	std::cout<<"PRO : "<<pro<<std::endl;
	delete(p);
	
	//test de la fonction de jeu;
	jeu.deplaceAlien();
	BOOST_CHECK_EQUAL(alien->getCorps().getForme(0).getCentre().getX(), 6);
	BOOST_CHECK_EQUAL(alien2->getCorps().getForme(0).getCentre().getX(), 3);
	BOOST_CHECK_EQUAL(alien3->getCorps().getForme(0).getCentre().getX(), 10);
	BOOST_CHECK_EQUAL(alien->getCorps().getForme(0).getCentre().getY(), 3);
	BOOST_CHECK_EQUAL(alien2->getCorps().getForme(0).getCentre().getY(), 3);
	BOOST_CHECK_EQUAL(alien3->getCorps().getForme(0).getCentre().getY(), 3);

	
	jeu.erase(alien2);
	p=cA2->generic(jeu);
	BOOST_CHECK(pro<p->getX());
	delete(p);
	
	jeu.erase(alien);
	p=cA2->generic(jeu);
	BOOST_CHECK_EQUAL(p->getX(),5);
	
	delete(p);
	
	//Cas du Bord
	ComportementAlien<int>* cA3=new ComportementAlien<int>(3);
	BOOST_CHECK_EQUAL(cA3->getSens(),1);
	Jeu<int> jeu2(5, 5, cA3);
	Alien<int>* alien4= new Alien<int>(20, Point<int>(4,3));
	jeu2.add(alien4);
	jeu2.deplaceAlien();
	BOOST_CHECK_EQUAL(alien4->getCorps().getForme(0).getCentre().getX(), 4);
	BOOST_CHECK_EQUAL(alien4->getCorps().getForme(0).getCentre().getY(), 4);
	BOOST_CHECK_EQUAL(cA3->getSens(),-1);
	
	jeu2.deplaceAlien();
	BOOST_CHECK_EQUAL(alien4->getCorps().getForme(0).getCentre().getX(), 3);
	BOOST_CHECK_EQUAL(alien4->getCorps().getForme(0).getCentre().getY(), 4);
	
	jeu2.deplaceAlien();
	BOOST_CHECK_EQUAL(alien4->getCorps().getForme(0).getCentre().getX(), 2);
	BOOST_CHECK_EQUAL(alien4->getCorps().getForme(0).getCentre().getY(), 4);
	
	jeu2.deplaceAlien();
	BOOST_CHECK_EQUAL(alien4->getCorps().getForme(0).getCentre().getX(), 1);
	BOOST_CHECK_EQUAL(alien4->getCorps().getForme(0).getCentre().getY(), 4);
	
	jeu2.deplaceAlien();
	BOOST_CHECK_EQUAL(alien4->getCorps().getForme(0).getCentre().getX(), 0);
	BOOST_CHECK_EQUAL(alien4->getCorps().getForme(0).getCentre().getY(), 4);
	
	jeu2.deplaceAlien();
	BOOST_CHECK_EQUAL(alien4->getCorps().getForme(0).getCentre().getX(), 0);
	BOOST_CHECK_EQUAL(alien4->getCorps().getForme(0).getCentre().getY(), 5);
	
	jeu2.deplaceAlien();
	BOOST_CHECK_EQUAL(alien4->getCorps().getForme(0).getCentre().getX(), 1);
	BOOST_CHECK_EQUAL(alien4->getCorps().getForme(0).getCentre().getY(), 5);

}
