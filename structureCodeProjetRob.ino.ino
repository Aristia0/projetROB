#include <Servo.h>

//distance pour détecter un mur
#define seuil 
//distance pour être parallèle au mur
#define distance_red 

// PIN ASSIGNMENT
uint8_t position_pince=A0;
uint8_t commande_pince=10;

/*
3 moteurs
1 servomoteur
2 capteurs distances
*/
void tournerGauche(){//precisement
	//peut-etre avec delay (stop le programme pour le temps de la fonction)
	aucunMouvement();
}


void avancer()
{

}


void aucunMouvement(){

}

void ouvrirPrince(){
	moteur.write(0);
}

void fermerPince(){
	moteur.write(180);
}

int detecterPlot(distance_cote){

	if (distance_cote <= seuil){
		return 1;
	}
	else{
		return 0;
	}


}


void saisirObjet(){
	ouvrirPince();
	//déplacer la pince en face de l'objet
	fermerPince();
	//lever la pince 
}

void poserObjet(){
	//correctement se positionner (vehicule + pince)
	ouvrirPince();
	//se retirer (reculer)

}


void etape0(){
	//état d'initialisation
	//moteurs à l'arrêt
	aucunMouvement();
	//build-in led qui clignote
	//mettre la pince en position haute 
	//delay
	EtatRobot ++;
}

void etape1(distance_avant){
	//avancer jusqu'à atteindre le mur pour se positionner parallèlement
	if (distance_avant > distance_ref)
	{
		avancer();
	}
	else {
		tournerGauche();
		EtatRobot ++;
	}
}

void etape2(distance_avant){
	/*
	avancer jusqu'à trouver premier plot sur sa droite
	puis tourner à gauche (90deg)
	*/
	if (distance_avant > seuil && detecterPlot() == 0)
	{
		avancer();
	}
	else if (detecterPlot() == 1)
	{
		//si on détecte un plot on tourne à gauche pour être en face de l'objet
		//et on change d'état
		tournerGauche();
		EtatRobot ++;
	}
	else if ()
	{
		//si on a pas détecter de plot et qu'on a atteint la limite du plateau
	}
	//modifier l'état de la variable etape1 quand fini
}

void etape3(distance_avant){
	//avancer tout droit jusqu'à trouver l'objet

	if (distance_avant > seuil)
	{
		avancer();
	}
	else 
	{
		//s'assurer que le capteur a détecter l'objet et pas le mur
		EtatRobot ++;
	}
}

void etape4(){
	saisirObjet();
	tournerGauche();
	EtatRobot++;
}


void etape5(){
	//avancer tout droit jusqu'à trouver le second plot et tourner à gauche
	avancer();

	if (detecterPlot() == 1)
	{
		tournerGauche();
		EtatRobot++;
	}
}


void etape6(){
	//avancer tout droite jusqu'à trouver le troisième plot et reculer en position pour poser les moteurs
	avancer();

	if (detecterPlot() == 1)
	{
		poserObjet();
	}
}



void setup(){

	//init capteurs et actionneurs
	pinMode(commande_pince, OUTPUT);
	pinMode(position_pince, INPUT);
  
	moteur.attach(commande_pince);
}

int EtatRobot = 0;

void loop(){
	
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
