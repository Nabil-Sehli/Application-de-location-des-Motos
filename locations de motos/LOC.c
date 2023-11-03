#include<stdio.h>
#include<stdbool.h>
#include"LOC.h"
typedef	struct{
	int id;
	char modele[100];
	int kilometrage;
	char disponible;
	}moto;
typedef struct{
	int jour;
	int mois;
	int annee;
}date;
typedef struct{
	int nclocation;
	int idmoto;
	char nomclient[50];
	date datelocation;
	int durre;
	float prix;
}location;
	location l;
	moto m;
void menu_location(void)
{
	int choix;
	do{	
		system ("cls");
		cadre(1,1, 90, 23);
		entete();
		pied();
		cadre(20,5, 70, 15);
		gotoxy(34,6); printf("Menu Principal > LOCATION");
		ligne(7,22,45);
		gotoxy(25,9); printf("1. Nouvelle location");
		gotoxy(25,10); printf("2. Toutes les locations");
		gotoxy(25,11); printf("3. Les recettes entre 2 annees");
		message("Entrez votre choix [   ]");
		gotoxy(23,20);
		scanf("%d",&choix);
		if (choix == 1) Ajouter_une_loc();
		if (choix == 2) aff_loc();
		if (choix == 3) recettes();
	}
	while(choix != 0);
}
void Ajouter_une_loc(void)
{
	system("cls");
	cadre(1,1, 90, 23);
	entete();
	pied(); 
	gotoxy(25, 6); printf("Menu principale > LOCATION > Ajouter Une LOCATION");
	gotoxy(19, 8); printf("Numero de location : ");
	gotoxy(19, 9); printf("Id Moto: ");
	gotoxy(19, 10); printf("Client : ");
	gotoxy(19, 11); printf("Date de location : ");
	gotoxy(19, 12); printf("Duree : ");
	gotoxy(19, 13); printf("Prix : ");
	
	
	gotoxy(41, 8); scanf("%d", &l.nclocation);
	gotoxy(41, 9); scanf("%d", &l.idmoto);
	bool trouve = false, dispo = false;
	FILE *f=fopen("moto.dat","r");
	do
	{
		fread(&m,sizeof(m),1,f);
		if(l.idmoto==m.id) 
		{ 
			trouve =true;
			if (m.disponible=='o' || m.disponible=='O') dispo = true;
		}
	}
	while(!feof(f) && !trouve);
	fclose(f);
	if (!trouve) {gotoxy(3, 20); printf("Message | MOTO INTROUVABE..."); getch();}
	if (trouve && !dispo) {gotoxy(3, 20); printf("Message | MOTO EN COURS DE LOCATION..."); getch();}
	if (dispo)
	{
		gotoxy(41, 10); fflush(stdin); gets(l.nomclient);
		gotoxy(41, 11); scanf("%d", &l.datelocation.jour);
		gotoxy(48, 11); scanf("%d", &l.datelocation.mois);
		gotoxy(55, 11); scanf("%d", &l.datelocation.annee);
		gotoxy(41, 12); scanf("%d", &l.durre);
		gotoxy(41, 13); scanf("%f", &l.prix);
		gotoxy(3, 20); printf("Donnees ajoutes!");
		FILE *f=fopen("location.dat", "a+");
	    fwrite(&l,sizeof(l),1,f);
	    fclose(f);	
		getch();
	}
}
void aff_loc(void)
{
	system("cls");
	cadre(1,1, 90, 23);
	entete();
	pied();
	tableau(4,5,7, 10, "Tableau d'affichage.");
	tete_tableau7(7, 5, 10, "Nc", "Id", "Nom","Dl", "duree", "pu", "PAP");
	FILE *f=fopen("location.dat", "r");
	fread(&l, sizeof(l), 1, f);
	int i=1;
	float pap;
	int s=0;
		while(!feof(f))
		{
			gotoxy(4, 7+i); printf("%c",179); printf("%d", l.nclocation);
			gotoxy(15, 7+i); printf("%c",179); printf("%d", l.idmoto);
			gotoxy(26, 7+i); printf("%c",179); printf("%s", l.nomclient);
			gotoxy(37, 7+i); printf("%c",179); printf("%d/%d/%d", l.datelocation.jour, l.datelocation.mois, l.datelocation.annee);
			gotoxy(48, 7+i); printf("%c",179); printf("%d", l.durre);
			gotoxy(59, 7+i); printf("%c",179); printf("%.2f", l.prix);
			gotoxy(70, 7+i); printf("%c",179); printf("%.2f", l.prix*l.durre);
			fread(&l, sizeof(l), 1, f);
			i++;
		}
	fclose(f);
	gotoxy(3, 20); printf("Message | Appuyer sur une touche pour continuer...");
	pied_tableau(4,4,7,10,i--);
	getch();
}
void recettes(void)
{	
	system("cls");
	cadre(1,1, 90, 23);
	entete();
	date x, y;
	gotoxy(18, 6); printf("Menu principale > LOCATION > Les recettes entre 2 annees");
	gotoxy(22, 8); printf("Entrez l'annee de debut : "); 
	gotoxy(22, 10); printf("Entrez l'annee de fin : "); 
	gotoxy(3, 20); printf("Message | Saisir les annees ..");
	pied();
	FILE *f=fopen("location.dat", "r");
	
	gotoxy(54, 8); scanf("%d", &x.annee); 
	gotoxy(52, 10); scanf("%d", &y.annee);
	fread(&l, sizeof(l), 1, f);
		int i=1;
	while(!feof(f))
	{
		if(l.datelocation.annee>=x.annee && l.datelocation.annee<=y.annee)
		{
			
			tableau(4,5,7, 10, "Tableau d'affichage.");
			tete_tableau7(7, 5, 10, "Nc", "Id", "Nom","Dl", "duree", "pu", "PAP");
		
					gotoxy(4, 7+i); printf("%c",179); printf("%d", l.nclocation);
					gotoxy(15, 7+i); printf("%c",179); printf("%d", l.idmoto);
					gotoxy(26, 7+i); printf("%c",179); printf("%s", l.nomclient);
					gotoxy(37, 7+i); printf("%c",179); printf("%d/%d/%d", l.datelocation.jour, l.datelocation.mois, l.datelocation.annee);
					gotoxy(48, 7+i); printf("%c",179); printf("%d", l.durre);
					gotoxy(59, 7+i); printf("%c",179); printf("%.2f", l.prix);
					gotoxy(70, 7+i); printf("%c",179); printf("%.2f", l.prix*l.durre);
					i++;
			
		}
		fread(&l, sizeof(l), 1, f);
	}
	gotoxy(3, 20); printf("Message | Appuyer sur une touche pour continuer...");
			pied_tableau(4,4,7,10,i--);
	fclose(f);
	getch();
}



























