#ifndef OBS_HPP
#define OBS_HPP

#include "Corps.hpp"

template <typename T>
class Obstacle
{
	protected :
	Corps<T> _corps;
	public :
	Obstacle(){};
	Obstacle( const Corps<T>& cor) : _corps(cor){};
	const Corps<T>& getCorps() const {return _corps;};
};

#endif
	

