#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Graphics.hpp"
#include "Menu.hpp"
#include "Environnement.hpp"

 



int main()
{	
	// On charge l'interface graphique ici
	Graphics G; // Ici on charge le manager Graphics
	Menu menu; 	// On charge un objet du type Menu
	
	int nbj=1;
	G.Loadbibli(G.repImage); // Chargement des toutes les images 
	
	G.app.Create(sf::VideoMode(G.getLargeure(), G.getLongeure(), 32), "Space Invader !");

 
    // Fenêtre de rendu
    
       switch( menu.affichageMenu(G)){
       		case 1 : // on a un seul joueur
       		{
       			// Initialisation du Jeu avec un seul joueur !		
       			G.app.Clear();
       			std::cout<<"Je rentre dans MainGame"<<std::endl;
       		
       			nbj=1;
       			
       			break;
       		}
       		case 2 : // On a deux joueur
       		{
       			// inisiitailisation du jeu avec 2 ou plus faut voir Joueur
       				nbj=2;
       			break;
       		}
       		default :
       		break;
        
        }
        Environnement<int> env(nbj);
        G.LoadSprite(G.repSprite,"srcsprite.txt");
        env.mainGame(G);
         // FOnction principale de jeu
    
    return EXIT_SUCCESS;

}



