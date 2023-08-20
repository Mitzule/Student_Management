#include<stdio.h>
struct studentiir
{
    int matricol,notap,notam,notaa;
    char nume[100];
}IR[30];
struct studentiie
{
    int matricol,notap,notam,notaa;
    char nume[100];
}IE[30];
struct studentiia
{
    int matricol,notap,notam,notaa;
    char nume[100];
}IA[30];
void selectie_an(int n)
{
    if(n==1)+
        printf("Ati selectat anul 1\n");
    if(n==2)
        printf("Ati selectat anul 2\n");
    if(n==3)
        printf("Ati selectat anul 3\n");
}
void selectie_profil(int n)
{
    if(n==1)
        printf("Ati selectat profilul - Informatica in limba romana\n");
    if(n==2)
        printf("Ati selectat profilul - Informatica in limba engleza\n");
    if(n==3)
        printf("Ati selectat profilul - Informatica Aplicata\n");
}

int meniu_profil()
{
    printf("==============================\n");
    printf("=                            =\n");
    printf("=          MENIU             =\n");
    printf("=                            =\n");
    printf("= Va rugam selectati profilul=\n");
    printf("= 1 - Informatica Romana     =\n");
    printf("= 2 - Informatica Engleza    =\n");
    printf("= 3 - Informatica Aplicata   =\n");
    printf("=                            =\n");
    printf("= 0 - Iesire                 =\n");
    printf("=                            =\n");
    printf("==============================\n");  
    int n,ok=1;
    printf("Introduceti optiunea dumneavoastra: ");
    while(ok)
    {
        scanf("%d",&n);
        if(n==1 || n==2 || n==3 || n==9 || n==0)
            ok=0;
        else 
            printf("Va rugam selctati o optiune valida\n");
    }
    printf("\n");
    selectie_profil(n);
    return n;
}

int nr_matricol()
{
    int matricol;
    printf("Introduceti numarul matricol al elevului: ");
    scanf("%d",&matricol);
    printf("Numarul matricol selectat este: %d",matricol);
    return matricol;
}
void elev(int an, int profil, int matricol)
{   
    if(an==1)
        {
            if(profil==1)
                printf("Ati selectat elevul cu numarul matricol %d,anul 1, profilul Informatica Romana\n",matricol);
            else if(profil==2)
                printf("Ati selectat elevul cu numarul matricol %d,anul 1, profilul Informatica Engleza\n",matricol);
            else if(profil==3)
                printf("Ati selectat elevul cu numarul matricol %d,anul 1, profilul Informatica Aplicata\n",matricol);
        }
    else if(an==2)
        {
            if(profil==1)
                printf("Ati selectat elevul cu numarul matricol %d,anul 2, profilul Informatica Romana\n",matricol);
            else if(profil==2)
                printf("Ati selectat elevul cu numarul matricol %d,anul 2, profilul Informatica Engleza\n",matricol);
            else if(profil==3)
                printf("Ati selectat elevul cu numarul matricol %d,anul 2, profilul Informatica Aplicata\n",matricol);
        }
    else if(an==3)
        {
            if(profil==1)
                printf("Ati selectat elevul cu numarul matricol %d,anul 3, profilul Informatica Romana\n",matricol);
            else if(profil==2)
                printf("Ati selectat elevul cu numarul matricol %d,anul 3, profilul Informatica Engleza\n",matricol);
            else if(profil==3)
                printf("Ati selectat elevul cu numarul matricol %d\n,anul 3, profilul Informatica Aplicata\n",matricol);
        }
}
int meniu_note()
{
    int n;
    printf("==============================\n");
    printf("=                            =\n");
    printf("=          MENIU             =\n");
    printf("=                            =\n");
    printf("= Selectati optiunea dorita  =\n");
    printf("= 1 - Adaugare nota          =\n");
    printf("= 2 - Stergere nota          =\n");
    printf("= 3 - Modificare nota        =\n");
    printf("=                            =\n");
    printf("= 9 - Inapoi                 =\n");
    printf("= 0 - Iesire                 =\n");
    printf("=                            =\n");
    printf("==============================\n");  
    printf("Optiunea dumneavoastra: ");
    scanf("%d",&n);
    printf("\n");
    return n;
}

int meniu_materie()
{
    int n;
    printf("==============================\n");
    printf("=                            =\n");
    printf("=          MENIU             =\n");
    printf("=                            =\n");
    printf("= Selectati optiunea dorita  =\n");
    printf("= 1 - Programare             =\n");
    printf("= 2 - Matematica             =\n");
    printf("= 3 - ASD                    =\n");
    printf("=                            =\n");
    printf("= 9 - Inapoi                 =\n");
    printf("= 0 - Iesire                 =\n");
    printf("=                            =\n");
    printf("==============================\n");  
    printf("Optiunea dumneavoastra: ");
    scanf("%d",&n);
    printf("\n");
    return n;
}

void modificare_note(struct studentiir *IR, struct studentiie *IE, struct studentiia *IA)
{
    int nota_veche,n;
    if(materie==1)//programare
        {
            nota_veche=note_p[matricol];
            if(modificare==1)
                {
                    printf("Introduceti nota dorita pentru adaugare: ");
                    scanf("%d",&n);
                    note_p[matricol]=n;
                }
            if(modificare==2)
                {
                    printf("Ati sters nota studentului %d",matricol);
                    note_m[matricol]=0;
                }
            if(modificare==3)
                {   
                    int nota_noua;
                    printf("Introduceti nota dorita pentru modificare: ");
                    scanf("%d",&n); 
                    note_p[matricol]=n;
                    printf("Ati modificat nota studentului %d, din %d in %d",matricol,nota_veche,note_p[matricol]);
                }
        }
    if(materie==2)//matematica
        {
            nota_veche=note_m[matricol];
            if(modificare==1)
                {
                    printf("Introduceti nota dorita pentru adaugare: ");
                    scanf("%d",&n);
                    note_m[matricol]=n;
                }
            if(modificare==2)
                {
                    printf("Ati sters nota studentului %d",matricol);
                    note_m[matricol]=0;
                }
            if(modificare==3)
                {   
                    int nota_noua;
                    printf("Introduceti nota dorita pentru modificare: ");
                    scanf("%d",&n); 
                    note_m[matricol]=n;
                    printf("Ati modificat nota studentului %d, din %d in %d",matricol,nota_veche,note_m[matricol]);
                }
        }
    if(materie==3)//asd
        {
            nota_veche=note_asd[matricol];
            if(modificare==1)
                {
                    printf("Introduceti nota dorita pentru adaugare: ");
                    scanf("%d",&n);
                    note_asd[matricol]=n;
                }
            if(modificare==2)
                {
                    printf("Ati sters nota studentului %d",matricol);
                    note_asd[matricol]=0;
                }
            if(modificare==3)
                {   
                    int nota_noua;
                    printf("Introduceti nota dorita pentru modificare: ");
                    scanf("%d",&n); 
                    note_asd[matricol]=n;
                    printf("Ati modificat nota studentului %d, din %d in %d",matricol,nota_veche,note_asd[matricol]);
                }
        }
}
int main()
{
    int an,profil;
    profil=meniu_profil();// 1 2 3 (ir ie ia)
    if(profil==0)
        return 0;

    matricol=nr_matricol();// n

    elev(an,profil,matricol);// an profil nr
    modificare=meniu_note();// 1 2 3 (+ - ~)

    materie=meniu_materie();// 1 2 3 (p m a)

    modificare_note(note_p,note_m,note_asd,modificare,materie,matricol);

    return 0;
}

