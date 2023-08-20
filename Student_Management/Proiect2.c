#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int length=0;
struct Student
{    
	int numar_matricol;	// Numarul matricol
	char nume_prenume[30];	// Numele complet al elevului 
	float nota;	// Nota elevului 
}s[20];
void meniu_principal()
{
	printf("=================================================\n");
	printf("=                                               =\n");
	printf("==================== MENIU ======================\n");
	printf("=                                               =\n");
	printf("=     1. Adauga informatiile studentului        =\n");
	printf("=     2. Afiseaza informatiile studentilor      =\n");
	printf("=     3. Sorteaza dupa nota                     =\n");
	printf("=     4. Gaseste studentul                      =\n");
	printf("=     5. Sterge studentul                       =\n");
	printf("=     6. Modifica studentul                     =\n");
	printf("=     0. Iesire                                 =\n");
	printf("=                                               =\n");
	printf("=================================================\n");
	printf(" Introduceti optiunea dorita: \n");
}
bool verif_matricol(int n)
{
	//false-neocupat, true-ocuptat
	bool stare_elev=false;
	for(int i=1;i<=length;i++)
		if(n==s[i].numar_matricol)
			stare_elev=true;
	return stare_elev;
}
void Adaugare_date(struct Student *s)
{
    
	printf("Adauga informatiile studentului: \n");
	char yn='Y';
	for(int i=length+1;yn=='Y';i++)
	{
		printf("Introduceti numarul matricol: ");
		while(scanf("%d",&s[i].numar_matricol))
		{
			if(verif_matricol(s[i].numar_matricol))
				printf("Acest numar matricol este folosit, reintroduceti un nou numar matricol \n");
			else
				break;
		}
		printf("Introduceti numele si prenumele studentului: ");
		fflush(stdin);
		gets(s[i].nume_prenume);
		printf("Introduceti nota elevului: ");
		scanf("%f",&s[i].nota);
		fflush(stdin);
		length++;
		printf("Doriti sa continuati sa adaugati alte date ? Y/N\n");
		yn=getchar();	
	}
}
void Afisare_date()
{    
	for(int i=1;i<=length;i++)
		printf(" Numarul matricol al studentului: %d\t Numele studentului: %s\t Nota elevului: %.2f\n",s[i].numar_matricol,s[i].nume_prenume,s[i].nota);
}
void Sort(struct Student *s)
{
	int ok=1;
	for(int i=1;i<length&&ok==1;i++)
	{
		ok=0;
		for(int j=1;j<=length-i;j++)
			if(s[j].nota<s[j+1].nota)
			{
				s[0]=s[j];
				s[j]=s[j+1];
				s[j+1]=s[0];
				ok=1;
			}
	}
	Afisare_date();	//Afisam studentii
}
void Gasire_student(int n)
{    
	int gasit=0;
	for(int i=1;i<=length;i++)
			if(n==s[i].numar_matricol)
			{
				gasit=1;
				printf(" Numarul matricol al studentului: %d\t Numele studentului: %s\t Nota elevului: %.2f\n",s[i].numar_matricol,s[i].nume_prenume,s[i].nota);
				break;
			}	
	if(gasit==0)
		printf("Studentul nu a fost gasit \n");
}
void Sterge_student(int n,struct Student *s)
{    
	int k=0;
	for(int i=1;i<=length;i++)
		if(n==s[i].numar_matricol)
		{
			for(int j=i;j<length;j++)
				s[j]=s[j+1];
			length--;
			k=1;
			printf("Stergere cu succes");
			break;
		}
	if(k==0)
		printf("Studentul nu a fost gasit\n");
}
void modifica_student(int n,struct Student *s)
{    
	int ok=0;
	for(int i=1;i<=length;i++)
	{
		if(n==s[i].numar_matricol)
		{
			ok=1;
			printf("Introduceti numele si prenumele studentului: ");
			fflush(stdin);
			gets(s[i].nume_prenume);
			printf("Introduceti nota elevului: ");
			scanf("%f",&s[i].nota);
			printf("Modificare reusita !\n");
			break;
		}
	}
	if(ok==0)
		printf("Studentul nu a fost gasit !\n");
}
void citire_fisier(struct Student *s)
{
	FILE *fp=fopen("C:\\Users\\mihai\\Desktop\\PROG\\PP\\management.txt","r");
	if(fp==NULL)
	{ 
		printf("Eroare la deschiderea fisierului\n");
		exit(0); 
	}
	for(int i=1;!feof(fp);i++)
	{
		fscanf(fp,"%d %s %f\n",&s[i].numar_matricol,&s[i].nume_prenume,&s[i].nota);
		length++;
	}
	length-=1;
	fclose(fp);
}
void scriere_fisier()
{
	FILE *fp=fopen("C:\\Users\\mihai\\Desktop\\PROG\\PP\\management.txt","w"); 
	if(fp==NULL)
	{
		printf(" Eroare la deschiderea fisierului\n");
		exit(0); 
	}
	for(int i=1;i<=length+1;i++)
		fprintf(fp,"%d %s %.2f\n",s[i].numar_matricol,s[i].nume_prenume,s[i].nota);
	fclose(fp);
}
int main()
{
	citire_fisier(s);
	meniu_principal();
	int n,t;
	while(scanf("%d",&n))
	{
		switch(n)
		{
			case 1:
				Adaugare_date(s);
				system("cls"); 
				meniu_principal();
				break;
			case 2:
				Afisare_date(); 
				system("pause");
				system("cls");
				meniu_principal();
				break;
			case 3:
				Sort(s); 
				system("pause");
				system("cls");
				meniu_principal();
				break;
			case 4:
				printf("Introduceti numarul matricol: ");
				scanf("%d",&t);
				Gasire_student(t);
				system("pause");
				system("cls");
				meniu_principal();
				break;
			case 5:
				printf("Introduceti numarul matricol: ");
				scanf("%d",&t);
				Sterge_student(t,s);
				system("pause");
				system("cls");
				meniu_principal();
				break;
			case 6:
				printf("Introduceti numarul matricol: ");
				scanf("%d",&t);
				modifica_student(t,s); 
				system("pause");
				system("cls");
				meniu_principal();
				break;
			case 0:
				printf("La revedere! \n");
				scriere_fisier();
				exit(0);
			default:
				printf("Reintroduceti !\n");
				break;
		}
	}
	return 0;
}