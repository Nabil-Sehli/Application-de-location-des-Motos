#include<stdio.h>
#include<stdbool.h>
#include"moto.h"
typedef	struct{
	int id;
	char modele[100];
	int kilometrage;
	char disponible[1];
	}moto;
moto m;
void menu_moto (void)
{
	int choix;
	do{	
		system ("cls");
		cadre(1,1, 90, 23);
		entete();
		pied();
		cadre(20,5, 70, 15);
		gotoxy(34,6); printf("Menu Principal > MOTO");
		ligne(7,22,45);
		gotoxy(25,9); printf("1. Ajouter une moto");
		gotoxy(25,10); printf("2. Modifier");
		gotoxy(25,11); printf("3. Supprimer");
		gotoxy(25,12); printf("4. Rechercher");
		gotoxy(25,13); printf("5. Afficher les motos");
		message("Entrez votre choix [   ]");
		gotoxy(23,20);
		scanf("%d",&choix);
		if (choix == 1) Ajouter_une_moto();
		if (choix == 2) Modifier();
		if (choix == 3) Supprimer();
		if (choix == 4) Rechercher();
		if (choix == 5) Afficher_les_motos();
	}
	while(choix != 0);
}
void Ajouter_une_moto(void){
	int choix;
	FILE*f;
	f=fopen("moto.dat", "a+");
		system("cls");
		cadre(1,1, 90, 23);
		entete();
		pied();
		gotoxy(25, 6); printf("MENU PRINCIPAL > MOTO > Ajouter Une MOTO");
		gotoxy(19, 8); printf("ID : ");
		gotoxy(19, 9); printf("Modele : ");
		gotoxy(19, 10); printf("Kilometrage : ");
		gotoxy(19, 11); printf("Disponible [O/N]: ");
		gotoxy(3, 20); printf("Message | Veuillez saisir les donnees...");
	
		gotoxy(41, 8); scanf("%d", &m.id);
		gotoxy(41, 9); fflush(stdin); gets(m.modele);
		gotoxy(41, 10); scanf("%d", &m.kilometrage);
		gotoxy(41, 11); fflush(stdin); gets(m.disponible);
		
		gotoxy(20, 14); printf("Donnees ajoutes!");
	fwrite(&m, sizeof(m), 1, f);
	fclose(f);
}
void Modifier(void){
		moto m,x;
		int xid;
		system("cls");
		cadre(1,1, 90, 23);
		entete();
		gotoxy(25, 6); printf("MENU PRINCIPAL > MOTO > Ajouter une moto");
   		gotoxy(19, 8); printf("Entrer le ID de la Moto modifier : "); scanf("%d",&xid);
		pied();
	bool trouve = false;
	FILE *f =f=fopen("moto.dat","r");
	do
	{
		fread(&m, sizeof(m),1, f);
		if (xid==m.id) {trouve = true; x=m;}

	}
	while(!feof(f) && !trouve);
	if (trouve){
	gotoxy(41, 8); printf("%d",xid);
	gotoxy(41, 9); printf("%s",x.modele);
	gotoxy(41, 10); printf("%d",x.kilometrage);
	gotoxy(41, 11); printf("%s",x.disponible);
	gotoxy(3, 20); printf("Etes-vous sure (O/N) ? ");
	char test;
	gotoxy(25,20); test=getch();
	if(test == 'o'){
		system("cls");
		cadre(1,1, 90, 23);
		entete();
		pied();
		gotoxy(25, 6); printf("MENU PRINCIPAL > MOTO > Ajouter une moto");
		rewind(f);
		FILE *g=fopen("tmp.dat","w");
		while (!feof(f))
		{
			fread(&m, sizeof(m), 1, f);
			if (xid != m.id)
				fwrite(&m, sizeof(m), 1,g);
		}
		
		fclose(f); fclose(g);
		remove("moto.dat");
		rename("tmp.dat", "moto.dat");
		gotoxy(19, 8); printf("ID : ");
		gotoxy(19, 9); printf("Modele : ");
		gotoxy(19, 10); printf("Kilometrage : ");
		gotoxy(19, 11); printf("Disponible [O/N]: ");
		gotoxy(3, 20); printf("Message | Veuillez saisir les donnees...");
		
		gotoxy(41, 8); scanf("%d", &m.id);
		gotoxy(41, 9); fflush(stdin); gets(m.modele);
		gotoxy(41, 10); scanf("%d", &m.kilometrage);
		gotoxy(41, 11); fflush(stdin); gets(m.disponible);
		
		FILE *f=fopen("moto.dat","a+");
		fwrite(&m, sizeof(m), 1,f);
		fclose(f);
		}
	}
	
	else{
	gotoxy(2,18);puts("introuvable........");
	gotoxy(55,20);getch();
	
	}
		}
void Supprimer(void){
	system("cls");
	cadre(1,1, 90, 23);
   	entete();
   	gotoxy(25, 6); printf("MENU PRINCIPAL > MOTO > Supprimer une moto");
	
   	pied();
   
   	moto m;
   	int xid ;
   	gotoxy(19, 8); printf("Entrer le ID de la Moto supprimer : "); scanf("%d",&xid);
   	
   	bool trouve = false;
   	FILE *f=fopen("moto.dat","r");
   	do
   	{
   		fread(&m,sizeof(m),1,f);
   		if(xid == m.id) trouve=true;
   	}
   	while (!feof(f) && !trouve);
   	fclose(f);
   	//decision
   	if(trouve)
    	{
            
			message("Etes-vous sure (O/N) ? ");
		
		char rep;
		gotoxy(25,20); rep=getch();
		if (rep == 'o')
		{
			
			f=fopen("moto.dat","r");
			FILE *g=fopen("tmp.dat","w");
			while (!feof(f))
			{
				fread(&m, sizeof(m), 1, f);
				if (xid != m.id) fwrite(&m, sizeof(m), 1, g);	
			}	
			fclose(f); fclose(g);
			remove("moto.dat");
			rename("tmp.dat", "moto.dat");	
		}
	  }
   else
   {
   
	  message("introuvable..."); 
      getch();
      }
}
void Rechercher(void){
	system("cls");
	cadre(1,1, 90, 23);
	entete();
	pied();
	gotoxy(25, 6); printf("MENU PRINCIPAL > MOTO > Rechercher a Une moto");
	int a;
	gotoxy(19, 8); printf("ID : "); gotoxy(41, 8); scanf("%d", &a);
	if(a==m.id)
	{
		gotoxy(19, 9); printf("Modele : "); gotoxy(41, 9); printf("%s", m.modele);
		gotoxy(19, 10); printf("Kilometrage : "); gotoxy(41, 10); printf("%d", m.kilometrage);
		gotoxy(19, 11); printf("Disponible [O/N]: "); gotoxy(41, 11); printf("%s", m.disponible);
		gotoxy(3, 20); printf("Message | Appuyer sur une touche pour continuer...");
	}
	else
	{
		gotoxy(3, 20); printf("Message | Id introuvable...");
	}
	getch();
}
void Afficher_les_motos(void){
	system("cls");
	
	cadre(1,1, 90, 23);
	entete();
	pied();
	tableau(4,5,4,20, "Tableau d'affichage.");
	tete_tableau(4, 5, 20, "id","Modele", "km", "Disponible");
	FILE*f;
	f=fopen("moto.dat", "r");
	fread(&m, sizeof(m), 1, f);
	int i=1;
		while(!feof(f))
		{
			gotoxy(4, 7+i); printf("%c",179); printf("%d", m.id);
			gotoxy(25, 7+i); printf("%c",179); printf("%s", m.modele);
			gotoxy(46, 7+i); printf("%c",179); printf("%d", m.kilometrage);
			gotoxy(67, 7+i); printf("%c",179); printf("%s", m.disponible);
			gotoxy(88, 7+i); printf("%c",179);
			fread(&m, sizeof(m), 1, f);
			i++;
		}
	fclose(f);
	gotoxy(3, 20); printf("Message | Appuyer sur une touche pour continuer...");
	pied_tableau(4,4,4,20,i--);
	getch();
}
