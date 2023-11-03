#include<stdio.h>
#include<conio.h>
#include<myconio.h>
#include <string.h>
void code(void);

main(){
	code();
}
void code(void)
{
	cadre(1,1, 90, 23);
	entete();
	cadre(20,5, 70, 15);
	gotoxy(40,6); printf("Mot de passe");
	gotoxy(43,10);
	char c;
	char pwd[10];
	int i=0;
	while(c!=13 && i<= 3)
	{
		c= getch();  
		
		printf("*");
		pwd[i] = c;
		i++;
	}
	if(strcmp(pwd,"1234")!= 0)
		message("Mot de passe incorrect...");
	else
		menu();
		pied();
}

