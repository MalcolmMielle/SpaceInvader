#ifndef SHOO_HPP
#define SHOO_HPP

#include <iostream>
#include <vector>
/************************
Impplémentation en interface de toutes les fonctions de tires
*************************/
template <typename T>
class Shootspe{
public : 
	//Constructeur useless
	Shootspe(){};
	// Methodes de tire
	virtual void shootMissile(std::vector<Projectile<T>* >& pro)=0;
	virtual void shootFlamme(std::vector<Projectile<T>* >& pro)=0;
	
};
#endif

template <typename T>
void Shootspe<T>::shootMissile(std::vector<Projectile<T>* >& pro){
	std::cout<<"shootspe"<<std::endl;
}

template <typename T>
void Shootspe<T>::shootFlamme(std::vector<Projectile<T>* >& pro){
}
