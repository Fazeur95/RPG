#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Rpg.h"
void Color(int couleurDuTexte,int couleurDeFond)
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}
int Choice(int min, int max)
{
    int entry = -1000;
  while(entry>max||entry<min)
  {
      printf("Entrez un chiffre entre %d et %d \n", min,max);
      scanf("%d", &entry);
  }
    return entry;
}
void Start()
{
    system("cls");
    printf("Vous etes un medecin cherchant un remede contre le coronavirus.\n");
    Sleep(2000);
    printf("Vous commencez votre quete au remede avec 100PV, 200PO, 15 de Force \n");
    inventaire2();
}
void Menu()
{
    Color(2,0);
    printf("                     -==\\\\                    `//~\\\\   ~~~~`---. \n""                ______-==|                    | |  \\\\ \n""          __--~~~  ,-/-==\\\\                   | |   `\\        ,' \n""       _-~       /'    |  \\\\                  / /     \\      / \n""     .'        /       |   \x5C\x5C               /' /       \x5C   /' \n""    /____  /         |    \`\.__/-~~ ~ \\_ _/' /           \\/' \n""   /-'~    ~~~~~---__  |     ~-/~         ( )   /'        _--~` \n""                     \_|      /        _)   ;  ),   __--~~ \n""                       '~~--_/      _-~/-  /   \\ '-~ \\ \n""                      {\__--_/}    / \\\\_>- )<__   \\    \\ \n""                      /'   (_/  _-~  | |__>--<__|      | \n""                     |0  0 _/) )-~    | |__>--<__|     | \n""                     / /~ ,_/      / /__>---<__/      | \n""                    o o _//       /-~_>---<__-~      / \n""                   (^(~          /~_>---<__-      _-~ \n""                  ,/|           /__>--<__/     _-~ \n""               ,//('(          |__>--<__|     /                  .----_ \n""              ( ( '))          |__>--<__|    |                 /' _---_~\\ \n""           `-)) )) (           |__>--<__|    |               /'  /      \\\n""~\\`\\ \n""          ,/,'//( (             \\__>--<__\\    \\            /'  // \n""||\n""        ,( ( ((, ))              ~-__>--<_~-_  ~--____---~' _/'/         /' \n""/'\n""      `~/  )` ) ,/|                 ~-_~>--<_/-__       __-~ _/ \n""    ._-~//( )/ )) `                    ~~-'_/_/ /~~~~~~~__--~ \n""     ;'( ')/ ,)(                              ~~~~~~~~~~ \n""    ' ') '( (/ \n""      '   ' \n\n\n");
    printf("  ______   ______   .______        ______   .__   __.      ___   ____    ____  __  .______       __    __       _______.\n"
           " /      | /  __  \\  |   _  \\      /  __  \\  |  \\ |  |     /   \\  \\   \\  /   / |  | |   _  \\     |  |  |  |     /       |\n"
           "|  ,----'|  |  |  | |  |_)  |    |  |  |  | |   \\|  |    /  ^  \\  \\   \\/   /  |  | |  |_)  |    |  |  |  |    |   (----`\n"
           "|  |     |  |  |  | |      /     |  |  |  | |  . `  |   /  /_\\  \\  \\      /   |  | |      /     |  |  |  |     \\   \\    \n"
           "|  `----.|  `--'  | |  |\\  \\----.|  `--'  | |  |\\   |  /  _____  \\  \\    /    |  | |  |\\  \\----.|  `--'  | .----)   |   \n"
           " \\______| \\______/  | _| `._____| \\______/  |__| \\__| /__/     \\__\\  \\__/     |__| | _| `._____| \\______/  |_______/    \n\n");
    Color(12,0);
    printf( "MAIN MENU : \n\n");
    Color(15,0);
    printf("1. Nouvelle partie\n");
    printf("2. Charger une partie\n");
    printf("3. A propos\n");
    printf("4. Quitter\n\n\n");
    GestionMenu();
}

int GestionMenu()
{
    int entry = Choice(1,4);
    char prenom[100];
    switch(entry)
    {
        case 1:
        system("cls");
        printf("Entrez votre Nom :\n");
        scanf("%s", prenom);
        printf("Bonjour %s ! \nBonne chance dans ta quete au remede!\n ", prenom);
        Sleep(2000);
        Start();
        Sleep(3000);
        system("cls");
        MenuSpawn();
        break;

        case 2:
        system("cls");
        break;

        case 3:
        system("cls");
        printf("\n Ceci est un jeu de type RPG cree par des BG: Zeyid, Marlon, Faouizi, Roy.\n");
        Sleep(5000);
        system("cls");
        Menu();
        break;

        case 4:
        Quitter();
        return 0;
    }
}
void Quitter()
{
    system("cls");
    printf(" A bientot \n");
    Sleep(2000);
}
