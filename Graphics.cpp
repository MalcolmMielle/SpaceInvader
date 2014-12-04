#include "Graphics.hpp"
/*
void Graphics :: drawCarre(int longeur, int largeur, Point centre, Shape carre) {
    carre.AddPoint(centre.getX() , centre.getY(), Color(255, 255, 0), Color(255,255,255));
    carre.AddPoint(centre.getX()+longeur, centre.getY(), Color(255, 255, 0), Color(255,0,0));
    carre.AddPoint(centre.getX()+longeur, centre.getY()+largeur, Color(0, 255, 255), Color(0,255,0));
    carre.AddPoint(centre.getX(), centre.getY()+largeur, Color(0, 255, 255), Color(0,0,255));
    carre.EnableFill(true); // Remplissage activé


}
*/

void Graphics::Police( const sf::Font& font,std::string nom,sf::String& text){

	text.SetText(nom); // Texte
	text.SetFont(font); // Fonte
	text.SetSize(20); // Taille de police
}

void Graphics::Loadbibli(repertoireImage& repertoireImag){
	sf::Image image;
	std::string contenu, cle;
	std::ifstream fichier("srcimages.txt");  
	fichier.clear();
	int i=0;
	char caractere;  // notre variable où sera stocké le caractère
                
  	while(!fichier.eof()){
		if(fichier) 
		{  
			fichier >> contenu >>cle;
			std::cout << contenu<< i <<" "<< cle<<std::endl;  
			  
		}
		else  
		        std::cout << "Impossible d'ouvrir le fichier !" << std::endl; 
		if(image.LoadFromFile(contenu))
	 repertoireImag.insert(std::make_pair(cle, new sf::Image(image)));
	 else 
	 	
	std::cout << "Chargement de l'image impossible" << std::endl;
	 fichier.get(caractere);
	std::cout << caractere;
	 i++;
 	}
 	fichier.close();
}
void Graphics::LoadSprite(repertoireSprite& repSprite,std::string nomfich){
	std::ifstream fichier("srcsprite.txt");
	fichier.clear();
	while(!fichier.eof()){// Ne s'arrete pas au premier tour !
		sf::Sprite *sprite = new sf::Sprite();
		std::string cle;
		  
		if(fichier) 
		{  
			fichier >> cle ;
			std::cout << cle<<" coucou "<<std::endl;  
			it = repImage.find(cle);
			if (it == repImage.end())
				
	std::cout << "Plopinet echec critique la cata" << std::endl;  
		}
		else  
		        std::cout << "Impossible d'ouvrir le fichier de Sprite!" << std::endl; 
		if(!(cle == "")){      
		sprite->SetImage(*it->second);
	 	repSprite.insert(std::make_pair(cle, sprite));
	 	}
	 	else
	 	std::cout << "Impossible de lire la clé de Sprite!" << std::endl;
	}
	fichier.close();

}


int Graphics::LoadImage(std::string cle,std::map<std::string,sf::Image>& repertoireImage){

	sf::Image image;
	if (!image.LoadFromFile(cle)) // Si le chargement du fichier a échoué
	{
	   //std:: cout<<"Erreur durant le chargement de l'image"<<endl;
	    return EXIT_FAILURE; // On ferme le programme
	}
	repertoireImage[cle] = image;
	return EXIT_SUCCESS;
}


sf::Image Graphics::LoadImage(std::string cle){

	sf::Image image;
	
	if (!image.LoadFromFile(cle)) // Si le chargement du fichier a échoué
	{
	   std:: cout<<"Erreur durant le chargement de l'image"<<std::endl;
	     // On ferme le programme
	}
	else
	return image;
}
