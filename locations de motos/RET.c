#include<stdio.h>
#include<conio.h>
#include <string.h>
#include<stdbool.h>
#include"RET.h"
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
	
	
	
	
void retour (void)
{
   system("cls");
   cadre(1,1, 90, 23);
   entete();
   pied();
   gotoxy(3,5); printf("MENU PRINCIPAL > LOCATION > Retour d une moto");
			
			gotoxy(3,7); printf("Num%cro de location: ",130);
			gotoxy(3,9); printf("Id: ");
			gotoxy(3,11); printf("Client: "); 
			gotoxy(3,13); printf("Date de location: ");
			gotoxy(3,15); printf("Duree: ");
			gotoxy(3,17); printf("Prix: ");
			
		    gotoxy(3,20); printf("Message |Veuillez saisir les donn%ces ",130); gotoxy(50,20); 
		
			
			//je cherche s il existe
			 //chercher le id dans le fishier
	location l;
	int xndl;
   gotoxy(23,7);scanf("%d",&xndl);
   bool trouve = false;
   FILE *f=fopen("location.dat","r");
   do
   {
   	fread(&l,sizeof(l),1,f);
   	if(xndl == l.nclocation) trouve=true; 
   }
   while (!feof(f) && !trouve);
   fclose(f);
   //decision
   if(trouve)
      {		
      		system("cls");
   			cadre(1,1, 90, 23);
   			entete();
   			pied();
   			gotoxy(3,5); printf("MENU PRINCIPAL > LOCATION > Retour d une moto");
   			gotoxy(3,7); printf("Num%cro de location: ",130);
			gotoxy(3,9); printf("Id: ");
			gotoxy(3,11); printf("Client: "); 
			gotoxy(3,13); printf("Date de location: ");
			gotoxy(3,15); printf("Duree: ");
			gotoxy(3,17); printf("Prix: ");
      	    gotoxy(23,7);printf("%d",l.nclocation);
			gotoxy(7,9); printf("%d", l.idmoto);
            gotoxy(11,11); printf("%s", l.nomclient);
			gotoxy(23,13); printf("%d %d %d", l.datelocation.jour, l.datelocation.mois, l.datelocation.annee);
			gotoxy(9,15); printf("%d", l.durre);
			gotoxy(8,17); printf("%d", l.prix);
			
			message("Etes-vous sur (O/N) ?");
		   char rep;
		   gotoxy(25,20); rep=getch();
		   if (rep == 'o') 
		{
		       f = fopen("moto.dat", "r");
	        		FILE *g = fopen("tmp1.dat", "w");
	        		moto m;
	        		fread(&m,sizeof(m),1,f);
					while (!feof(f))
					{
					   	if(l.idmoto != m.id) fwrite(&m,sizeof(m),1,g);
					   		else {m.disponible='o'; fwrite(&m,sizeof(m),1,g);}
					   	fread(&m,sizeof(m),1,f);
					}
					   
					   fclose(f);fclose(g);
					   remove("moto.dat");
					   rename("tmp1.dat","moto.dat");
			   
		}
		
		
	  }
   else
	  {
	  		system("cls");
   			cadre(1,1, 90, 23);
   			entete();
   			pied();
   			gotoxy(3,5); printf("MENU PRINCIPAL > LOCATION > Retour d une moto");
   			gotoxy(3,7); printf("Num%cro de location: ",130);
			gotoxy(3,9); printf("Id: ");
			gotoxy(3,11); printf("Client: "); 
			gotoxy(3,13); printf("Date de location: ");
			gotoxy(3,15); printf("Duree: ");
			gotoxy(3,17); printf("Prix: ");
			message("introuvable...");
			getch();
	  }
	   
   
}
