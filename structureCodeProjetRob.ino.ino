#include <Servo.h>

#define seuil 

// PIN ASSIGNMENT
uint8_t position_pince=A0;
uint8_t commande_pince=10;

/*
3 moteurs
1 servomoteur
2 capteurs distances
*/
void tournerDroite(){//precisement
	//peut-etre avec delay (stop le programme pour le temps de la fonction)

}


void avancerParallementAuMur(){

}


void aucunMouvement(){


}

void ouvrirPrince(){
	moteur.write(0);
}

void fermerPince(){
	moteur.write(180);
}

void detecterPlot(){

	//seuil de difference > ... 

	//faire la manoeuvre (tourner à droite)

}


void trouverPositionPince(){
	//peut-etre avec delay (stop le programme pour le temps de la fonction)

}

void saisirObjet(){

}

void poserObjet(){
	//correctement se positionner (vehicule + pince)
	//lacher
	//se retirer (reculer)

}


void etape0(){
	//moteurs à l'arrêt
	aucunMouvement();
	//build-in led qui clignote
}


void etape1(distance_avant){
	/*
	avancer jusqu'à une certaine distance 
	puis tourner à droite (90deg)
	*/
	if (distance_avant > seuil)
	{
		avancerParallementAuMur();
	}
	if (distance_avant <= seuil)
	{
		tournerDroite();
		EtatRobot++;
	}
	//modifier l'état de la variable etape1 quand fini
}

void etape2(){
	//avancer tout droite jusqu'à trouver le premier plot et tourner à droite
	avancerParallementAuMur();

	if (detecterPlot() == 1)
	{
		tournerDroite();
		EtatRobot++;
	}

}

void etape3(){

	if (distance_avant > seuil){
		avancerParallementAuMur();
	}
	if (distance_avant <= seuil){
		if(trouverPositionPince() == 1){
			saisirObjet();
			//+tourner a droite
			//EtatRobot++;
		}
		else{
			//recommencer la recherche
			//peut-etre en reculant d'abord
		}

	}

}


void etape4(){
	//avancer tout droite jusqu'à trouver le premier plot et tourner à droite
	avancerParallementAuMur();

	if (detecterPlot() == 1)
	{
		tournerDroite();
		EtatRobot++;
	}
}


void etape5(){
	//avancer tout droite jusqu'à trouver le premier plot et tourner à droite
	avancerParallementAuMur();

	if (detecterPlot() == 1)
	{
		poserObjet();
		EtatRobot++;
	}
}

void etape6(){
	//se reculer un peu et stopper les moteurs
}



void setup(){

	//init capteurs et actionneurs
	pinMode(commande_pince, OUTPUT);
	pinMode(position_pince, INPUT);
  
	moteur.attach(commande_pince);
}


void loop(){

	//bouton poussoir qui reset les variables

	distance_avant;
	distance_droite;


	int EtatRobot = 0;


	switch (EtatRobot) : 
	case 0 :
		etape0();
		break;
	case 1 : 
		etape1();
		break;
	case 2 : 
		etape2();
		break;
	case 3 : 
		etape3();
		break;
	case 4 : 
		etape4();
		break;
	case 5 : 
		etape5();
		break;
	case 6 : 
		etape6();
		break;



}
