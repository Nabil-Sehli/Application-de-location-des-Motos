#include<stdio.h>
void ligneducadre(int l)
{ //t : taille : nombre de colonnes de la ligne
	int i;
	gotoxy(1,l); printf("%c",195);
	for (i=1; i<=89; i++) printf("%c",196);
	gotoxy(90,l); printf("%c", 180);
}
void cadre(int ch,int lh,int cb,int lb)
{
	gotoxy(ch,lh); printf("%c",218);
	int i;
	for (i=1; i<=cb-ch-1; i++) printf("%c",196);
	gotoxy(cb,lh);printf("%c",191);
	for (i=1; i<=lb-lh-1; i++) {gotoxy(cb, lh+i); printf("%c",179);}
	gotoxy(cb,lb); printf("%c",217);
	for (i=cb-1; i>=ch+1; i--) {gotoxy(i, lb); printf("%c",196);}
	gotoxy(ch,lb); printf("%c",192);
	for (i=lb-1; i>=lh+1; i--) {gotoxy(ch, i); printf("%c",179);}
}
void entete(void)
{
	gotoxy(2,2); printf("LOCAMOTO 1.0 | Application desktop de gestion des locations des moto");ligneducadre(3);
}
void pied(void)
{
	ligneducadre(21);
	gotoxy(2,22);printf("#2022 | R%calis%ce par : Sehli Nabil", 130, 130);
}
void message(char txt[])
{
	gotoxy(2, 20); printf(txt);
}

void ligne(int l, int cd, int cf)
{ //l : ligne - cd : col début - cf : col final
	int i;
	for (i=1; i<=cf; i++) { gotoxy(cd+i,l); printf("%c",196);}
}
void tableau(int col, int lig, int nbr_col, int taille_col, char titre[])
{
	int milieu= (nbr_col * taille_col)/2; gotoxy(milieu, lig-1); puts(titre);
	int i; int j;
	gotoxy(col, lig); printf("%c",218);
	//LIGNE 1
	for(j=1;j<=nbr_col;j++)
	{
		for(i=1;i<=taille_col;i++) printf("%c", 196);
		if (j!=nbr_col) printf("%c",194); else printf("%c",191);
	}
	//LIGNE 2
	lig++; gotoxy(col, lig); printf("%c",179);
	for(j=1;j<=nbr_col;j++)
	{
		for(i=1;i<=taille_col;i++) printf(" ");
		printf("%c",179);
	}
	//LIGNE 3
	lig++; gotoxy(col, lig); printf("%c",195);
	for(j=1;j<=nbr_col;j++)
	{
		for(i=1;i<=taille_col;i++) {gotoxy(col+i, lig); printf("%c",196);} col+=i;
		if (j!=nbr_col) printf("%c",197); else printf("%c",180);
	}	
}void tete_tableau7(int col, int lig, int taille_col, char c1[20], char c2[20], char c3[20], char c4[20], char c5[20], char c6[20], char c7[20]){
	col++; lig++; gotoxy(col, lig); puts(c1);
	col+=taille_col+1; gotoxy(col, lig); puts(c2);
	col+=taille_col+1; gotoxy(col, lig); puts(c3);
	col+=taille_col+1; gotoxy(col, lig); puts(c4);
	col+=taille_col+1; gotoxy(col, lig); puts(c5);
	col+=taille_col+1; gotoxy(col, lig); puts(c6);
	col+=taille_col+1; gotoxy(col, lig); puts(c7);
	
}
void tete_tableau(int col, int lig, int taille_col, char c1[20], char c2[20], char c3[20], char c4[20]){
	col++; lig++; gotoxy(col, lig); puts(c1);
	col+=taille_col+1; gotoxy(col, lig); puts(c2);
	col+=taille_col+1; gotoxy(col, lig); puts(c3);
	col+=taille_col+1; gotoxy(col, lig); puts(c4);
}
void pied_tableau(int col, int lig, int nbr_col, int taille_col, int nbr_lig){
	int j, i;
	lig+=3; lig+=nbr_lig;
	gotoxy(col, lig); printf("%c",192);
	for(j=1;j<=nbr_col;j++)
	{
		for(i=1;i<=taille_col;i++) {gotoxy(col+i, lig); printf("%c",196);} col+=i;
		if (j!=nbr_col) printf("%c",193); else printf("%c",217);
	}		
}
