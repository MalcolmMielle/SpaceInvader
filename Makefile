all: test

test : Interface.o Graphics.o Graphics.hpp Menu.o Menu.hpp Jeu.hpp Alien.hpp Protagoniste.hpp
	g++ Interface.o Graphics.o Menu.o  Menu.hpp Graphics.hpp Jeu.hpp Alien.hpp Protagoniste.hpp  Environnement.hpp Joueur.hpp ComportementAlien.hpp Projectile.hpp Projectile_simple.hpp -o test -lsfml-audio -lsfml-graphics -lsfml-window -lsfml-system 
	
Interface.o : Interface.cpp Graphics.hpp Jeu.hpp Alien.hpp  Protagoniste.hpp Joueur.hpp Environnement.hpp Projectile.hpp Projectile_simple.hpp ComportementAlien.hpp
	g++ -g -c -Wall Interface.cpp
	
Menu.o : Menu.cpp Menu.hpp
	g++ -g -c -Wall Menu.cpp

Graphics.o : Graphics.cpp Graphics.hpp	
	g++ -g -c -Wall Graphics.cpp

clean:
	rm -f *.o
	rm -f *~

vclean: clean
	rm -f TP
	rm -f test

vvclean: all clean
