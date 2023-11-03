#include<stdio.h>
#include<conio.h>
#include <string.h>
#include<stdbool.h>
#include"propos.h"

void a_propos(void)
{
	system("cls");
   	cadre(1,1, 90, 23);
   	entete();
   	pied();
   	gotoxy(3,5); printf("MENU PRINCIPAL > A PROPOS");
   	gotoxy(3,7); printf("LOCAMOTO Version 1.0 est une application realisee par Prenom NOM, Etudiant en");
   	gotoxy(3,8); printf("1ere annee a l Institut Superieur de Genie Information en vue de l obtention du Mastere");
   	gotoxy(3,9); printf("Europeen en Informatique : Manager de projets informatiques. Diplome d etat Français");
   	gotoxy(3,10); printf("et Europeen. ");
   	gotoxy(3,12); printf("LOCAMOTO 1.0 permet de garder une trace des locations des motos et etabli");
   	gotoxy(3,13); printf("des recettespar dates.");
   	gotoxy(3,15); printf("LOCAMOTO utilise la programmation procedurale en langage C et exploite la technique ");
   	gotoxy(3,16); printf("des fichiers de donnees de type .dat.");
   	message("Message | Appuyer sur une touche pour continuer...");
	getch();
}
