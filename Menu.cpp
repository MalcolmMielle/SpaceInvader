#include "Menu.hpp"

int Menu::affichageMenu( Graphics& G){
	sf::Font font ;
	sf::Image image;
	
	std::string yoyo = "salutttttttttttttttttttttttt";
	sf::String lol;
	G.LoadSprite(sprite,"srcsprite.txt");
	
	 
	const sf::Input & input = G.app.GetInput();
	if(!font.LoadFromFile("arial.ttf"))
	{
	    // Traitement de l'erreur
	}
	
//RenderWindow app(VideoMode(600, 600, 32), "Space Invader !");
MoveSprite("bouton1Jfree",200,400);
MoveSprite("bouton1Jhold",200,400);
MoveSprite("bouton2Jfree",600,400);
MoveSprite("bouton2Jhold",600,400);
while (G.app.IsOpened())
    {
    	G.app.Clear();
        sf::Event event;
	while (G.app.GetEvent(event))
        {
        	switch (event.Type){
        	
			case  sf::Event::Closed :
				G.app.Close();
				break;
				
			case sf::Event::KeyPressed :
			{
				switch(event.Key.Code)
				{
				case sf::Key::Escape :
				{
				 return 0;	
				break;
				}
				default :
				break;
				}
				
			  	 }
			  	 default :
					break;	
	       		 }
 		}

        // Efface l'écran (remplissage avec du noir)
        
 
        // Affichage de notre carre dans la fenêtre
        //app.Draw(sprite);
       drawfixe(G);
       int Joueur = eventMouse(input,G);
       if (Joueur == 0)
       		return 1;
       	else if (Joueur ==1)
       		return 2;
       
        //app.Draw(*G.its->second); 

    
        
        // Affichage du contenu de la fenêtre à l'écran
        G.app.Display();
	}
	// Delete sprite !
	return 0;
}
int Menu::eventMouse(const sf::Input& input,Graphics& G){
	int mouseX = input.GetMouseX(); 
	int mouseY = input.GetMouseY(); 
	const sf::Input & inpu = G.app.GetInput();
	repertoireSprite::iterator itGauche, itDroit;
		if (mouseX> 200 && mouseX<350 && mouseY >400 && mouseY<470){
			itGauche = sprite.find("bouton1Jhold");
			itDroit = sprite.find("bouton2Jfree");
	    }
		else if (mouseX> 600 && mouseX<750 && mouseY >400 && mouseY<470) {
			itGauche = sprite.find("bouton1Jfree");
			itDroit = sprite.find("bouton2Jhold");
		}
		else{
			itGauche = sprite.find("bouton1Jfree");
			itDroit = sprite.find("bouton2Jfree");
		}
		if (input.IsMouseButtonDown(sf::Mouse::Left)&& (mouseX> 200 && mouseX<350 && mouseY >400 && mouseY<470))
			{
				return 0;		
			}
			else if(input.IsMouseButtonDown(sf::Mouse::Left)&&(mouseX> 600 && mouseX<750 && mouseY >400 && mouseY<470)){
				return 1;
				}	
					if(it ==sprite.end())
		std::cout<<"Erreur interne dans le chargement du sprite"<<std::endl;
		else
		G.app.Draw(*itGauche->second);
		G.app.Draw(*itDroit->second);
				if (inpu.IsKeyDown(sf::Key::Left))
		{
		std::cout<<"COOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO"<<std::endl;
		}
		return 2;	

}
void Menu::drawfixe(Graphics& G){
	repertoireSprite::iterator itTitre, itDroit;
	itTitre = sprite.find("fond");
	sf::Sprite *im = itTitre->second ;
	im->SetPosition(G.getLargeure() /2-100,G.getLongeure() /2 -200);
	//MoveSprite("boutonfree",600,600);
	G.app.Draw(*im);

}
void Menu::MoveSprite(std::string nomSprite,float x, float y){
	repertoireSprite::iterator  itDroit;
	itDroit = sprite.find(nomSprite);
	sf::Sprite *imD = itDroit->second ;
	imD->SetPosition(x,y);

}
/*	
sf::Image *image2 = new sf::Image(*G.it->second);
        std::cout<<"loool  oioijuj  "<<std::endl;
        sf::Sprite *sprite2 = new sf::Sprite();
        //sprite2->SetImage(*G.it->second);
        
        G.its = G.repSprite.find("fond");
        //if(&sprite == NULL)
        
       // app.Draw(*G.its->second);
 	std::cout<<"loool"<<std::endl;
*/
