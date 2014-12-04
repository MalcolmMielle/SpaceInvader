#include <iostream>
#define BOOST_TEST_DYN_LINK
#include <time.h>
#include <cstdlib>
#include "Projectile_simple.hpp"
#include "Obstacle.hpp"
#include "Alien.hpp"
#include "Environnement.hpp"
#include "ComportementAlien.hpp"
#define BOOST_TEST_MODULE MyTest
#include <boost/test/unit_test.hpp>
/*********************

*************************/

BOOST_AUTO_TEST_CASE(trying)
{
	Environnement<int> env;
	env.mainGame();
}
