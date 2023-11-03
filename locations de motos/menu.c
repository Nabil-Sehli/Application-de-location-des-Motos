#include<stdio.h>
#include"menu.h"
void menu (void)
{
	int choix;
	do{	
		system ("cls");
		cadre(1,1, 90, 23);
		entete();
		pied();
		cadre(20,5, 70, 15);
		gotoxy(38,6); printf("Menu Principal");
		ligne(7,22,45);
		gotoxy(25,9); printf("1. MOTO");
		gotoxy(25,10); printf("2. LOCATION");
		gotoxy(25,11); printf("3. RETOUR MOTO");
		gotoxy(25,12); printf("4. A Propos");
		message("Veuillez choisir une opération (0 : Quitter) [   ]");
		gotoxy(49,20);
		scanf("%d",&choix);
		if (choix == 1) menu_moto();
		if (choix == 2) menu_location();
		if (choix == 3) retour();
		if (choix == 4) a_propos();
	}
	while(choix != 0);	
}


