//----------------------- P01 : LOCAMOTO1.0 ------------------------------//
//-------------------------BEN ABBOU Yasser------------------------------//
#include<stdio.h>
#include<myconio.h>
//Liste de prototypes -------------------------------------------------------//
void cadre(int,int,int,int);
void ligneducadre(int); //la ligne est dans le cadre de la 1ère col (1) à la dernière col (90)
void ligne(int, int, int); //pour tracer une ligne à une ligne d'écran de la colonne début ) la colonne finale
void entete(void);
void pied(void);
void message(char *);
main(){
	cadre(1,1, 90, 23);
	entete();
	pied();
	ligne(5,10, 30); //Trace une ligne à la 5ème ligne de la col 10 à 30
	message("Message :  Veuillez choisir une operation(0 : Quitter) : ");
	getch();
}
void cadre(int ch,int lh,int cb,int lb){
	gotoxy(ch,lh); printf("%c",218);
	for (int i=1; i<=cb-ch-1; i++) printf("%c",196);
	gotoxy(cb,lh);printf("%c",191);
	for (int i=1; i<=lb-lh-1; i++) {gotoxy(cb, lh+i); printf("%c",179);}
	gotoxy(cb,lb); printf("%c",217);
	for (int i=cb-1; i>=ch+1; i--) {gotoxy(i, lb); printf("%c",196);}
	gotoxy(ch,lb); printf("%c",192);
	for (int i=lb-1; i>=lh+1; i--) {gotoxy(ch, i); printf("%c",179);}
}
void entete(void){
	gotoxy(2,2); printf("LOCAMOTO 1.0 | Application desktop de gestion des locations des moto");ligneducadre(3);
}
void pied(void){
	ligneducadre(21);
	gotoxy(2,22);printf("#2022 | R%calis%ce par BEN ABBOU Yasser", 130, 130);
}
void message(char txt[])
{
	gotoxy(2, 20); printf(txt);
}
void ligneducadre(int l){ //t : taille : nombre de colonnes de la ligne
	gotoxy(1,l); printf("%c",195);
	for (int i=1; i<=89; i++) printf("%c",196);
	gotoxy(90,l); printf("%c", 180);
}
void ligne(int l, int cd, int cf){ //l : ligne - cd : col début - cf : col final
	for (int i=1; i<=cf; i++) { gotoxy(cd+i,l); printf("%c",196);}
}

