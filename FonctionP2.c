#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include "Rpg.h"
#include"global.h"

void MenuSpawn()
{
    printf("                                             Ou voulez vous commencer ? \n\n");
    printf("1. Chine, Wuhan\n");
    printf("2. France, Argenteuil \n");

}
int GestSpawn()
{
    int entry = Choice(1,2);
    switch(entry)
    {
        case 1:
        printf("Vous etes en Chine, vous avez la possibilite de rendre visite a un charlatan\n\n\n");
        printf("Ce dernier peut vous vendre des objets. \n\n");
        printf("Voulez vous rendre visite au charlatan? \n\n");
        printf("1. Oui\n");
        printf("2. Non\n");
        int entry = Choice(1,2);
        switch(entry)
        {
            case 1:
            Marchand();
            break;
            case 2:
            MenuActions();
            break;
        }
        case 2:
        printf("Vous etes en France, a Argenteuil. Attention a votre porte feuille!\n\n ");
        break;
    }
}

int Actions0()
{
   int entry = Choice(1,5);
   switch(entry)
   {
   case 1:
       system("cls");
       if (entry2 == entry+1)
       {
        printf("Vous revenez sur vos pas");
        Sleep(1000);
        move--;
        Mouvements();
       }
       else
       {
        printf(" Vous avancez en direction du Nord\n ");
        Sleep(1000);
        move++;
        entry2=1;
        Mouvements();
       }
    entry2 = 1;
    break;
   case 2:
    system("cls");
    if (entry2 == entry-1)
    {
        printf("Vous revenez sur vos pas");
        Sleep(1000);
        move--;
        Mouvements();
    }
    else
    {
        printf(" Vous vous deplacez vers le Sud\n ");
        Sleep(1000);
        move++;
        entry2=2;
        Mouvements();
    }
    entry2 = 2;
    break;
   case 3:
    system("cls");
    if (entry2 == entry+1)
    {
        printf("Vous revenez sur vos pas");
        Sleep(1000);
        move--;
        Mouvements();
    }
    else
    {
        printf(" Vous deplacez vers l'Est \n ");
        Sleep(1000);
        move++;
        entry2=3;
        Mouvements();
    }
    entry2 =3;
    break;
   case 4:
    system("cls");
    if (entry2 == entry-1)
    {
        printf("Vous revenez sur vos pas");
        Sleep(1000);
        move--;
        Mouvements();
    }
    else
    {
        printf(" Vous allez a l'Ouest\n ");
        Sleep(1000);
        move++;
        entry2=4;
        Mouvements();
    }
    entry2 = 4;
    break;
   case 5:
    system("cls");
    printf(" Vous cherchez dans votre sac Eastpack acheter chez Sajeegkan\n ");
    Sleep(1000);
    inventaire1();
    MenuActions();
    break;
   }
}
void MenuActions()
{
    printf("Que souhaitez vous faire ?\n\n");
    printf("1. Nord\n");
    printf("2. Sud\n");
    printf("3. Est\n");
    printf("4. Ouest\n");
    printf("5. Inventaire \n");
    Actions0();
}
void Marchand()
{
    system("cls");
    printf("Bonjour, Que souhaitez vous acheter ?\n");
    printf ("Vous disposez de %d PO \n", gold);
    Color(12,0);
    printf("1. Potion de Soin  | 50 PO\n");
    printf("2. Potion de Force | 75 PO \n");
    printf("3. Boost XP        | 50 PO \n");
    printf("4. Rien \n ");
    Color(15,0);
    int entry = Choice(1,4);
    if (entry == 1 && gold >= 50)
    {
        gold -= 50;
        inventaire[0]++;
        printf("Vous avez %d Potion de soins \n", inventaire[0]);
        Sleep(1500);
        Marchand();
    }
    else if (entry == 1 && gold < 50)
    {
        printf("Vous n'avez pas assez d'argent \n");
        Sleep(1500);
        MenuActions();
    }
    if (entry == 2 && gold >= 75)
    {
        gold -= 75;
        inventaire[1]++;
        printf("Vous avez %d Potion de Force \n", inventaire[1]);
        Sleep(1500);
        Marchand();
    }
    else if (entry == 2 && gold < 75)
    {
        printf("Vous n'avez pas assez d'argent \n");
        Sleep(1500);
        MenuActions();
    }
    if (entry == 3 && gold >= 50)
    {
        gold -= 50;
        XP += 200;
        Experience();
        Sleep(3000);
        Marchand();
    }
    else if (entry == 3 && gold < 50)
    {
        printf("Vous n'avez pas assez d'argent \n");
        Sleep(1500);
        MenuActions();
    }
    if (entry == 4)
    {

        MenuActions();
    }

    MenuActions();
}
void Mouvements()
{
    switch(move)
    {
    case 0:
        printf("Vous etes sur la ZUP");
        MenuActions();
        break;
    case 1:
        printf(" Vous arrivez devant la mairie d'Argenteuil,\n\n ");
        MenuActions();
        break;
    case 2:
        printf(" Vous tombez sur un mec de cite !\n ");
        printf(" Vous perdez donc 10PV !\n");
        hp -= 10;
        MenuActions();
        break;
    case 3:
        if (coffre == 1)
        {
            printf("L'Homme n'a plus d'enigme !\n");
            MenuActions();
        }
        else
        {
        coffre = 1;
        printf(" Un Homme etrange, vous propose une enigme pour obtenir une recompense.. \n ");
        printf(" Quel club Francais a remporter la ligue des champions ? \n");
        printf(" 1. Paris  \n");
        printf(" 2. Marseille  \n");
        printf(" 3. Lyon \n");
        printf(" 4. Toulouse \n");
        int entry = Choice(1,4);
        switch(entry)
        {
        case 1:
         system("cls");
         printf(" G A M E  O V E R ! ");
         Sleep(2000);
         Menu();
         break;
        case 2:
            system("cls");
            printf(" Felicitation ! \n");
            printf(" Vous obtenez 100 d'XP !\n");
            XP += 100;
            Experience();
            MenuActions();
            break;
        case 3:
            printf(" Ce n'est pas la bonne reponse !");
            MenuActions();
            break;
        case 4:
            printf(" Bien essaye mais non !");
            MenuActions();
            break;
        }
    break;
    }

    case 4:
        if (BOSS == 1)
        {
            printf("Vous etes deja gueri");
            MenuActions();
        }
        else
        {
        BOSS = 1;
        system("cls");
        printf(" Le COVID-18 apparait \n");
        Combat();
        MenuActions();
        break;
        }
    case 5:
        printf(" Vous trouvez un billet de 50 euros\n\n ");
        gold += 50;
        MenuActions();
        break;
    case 6:
        printf(" Vous croisez Mennan un vendeur de marrons chaud\n\n");
        Mennan(gold);
        MenuActions();
        break;
    case 7:
        printf(" Vous arrivez a Nanterre Universite \n");
        printf(" Le combat ultime se prepare !\n");
        Utilisation();
        break;
    case 8:
    Combat2();
    Menu();
    break;
    }
}
void Mennan()
{
    printf("Que puis-je faire pour vous ?\n");
    printf ("Vous disposez de %d PO \n", gold);
    Color(12,0);
    printf("1. Potion de Soin  | 50 PO\n");
    printf("2. Potion de Force | 75 PO \n");
    printf("3. Rien            | 10 PO \n ");
    Color(15,0);
    int entry = Choice(1,3);
    if (entry == 1 && gold >= 50)
    {
        gold -= 50;
        inventaire[0]++;
        printf("Vous avez %d Potion de soins \n", inventaire[0]);
        Marchand();
    }
    else if (entry == 1 && gold < 50)
    {
        printf("Vous n'avez pas assez d'argent \n");
        MenuActions();
    }
    if (entry == 2 && gold >= 75)
    {
        gold -= 75;
        inventaire[1]++;
        printf("Vous avez %d Potion de Force \n", inventaire[1]);
        Marchand();
    }
    else if (entry == 2 && gold < 75)
    {
        printf("Vous n'avez pas assez d'argent \n");
        MenuActions();
    }
    if (entry == 3)
    {
        gold -= 10;
        MenuActions();
    }
    MenuActions();
}
void inventaire1()
{
for(int i=0;i<6;i++);
printf("Potions de soin x %d \n",inventaire[0]);
printf("Potions de force x %d \n",inventaire[1]);
Utilisation();
}
int Combat()
{
    srand(time(NULL));
    int tour = rand()%2+1;
    switch(tour)
    {
    case 1:
    printf("L'ennemi commence en premier \n");
    break;
    case 2:
    printf("Vous commencez en premier \n");
    break;
    }
while (hp && hpIA > 0)
    {
        if (tour == 1)
        {
            AttaqueIA();
            AttaqueJ();
        }
        else
        {
            AttaqueJ();
            AttaqueIA();
        }

    }
if (hpIA <= 0)
    {
        Sleep(1000);
        system("cls");
        printf("Votre remede est un succes vous gagnez 100 d'experience et recuperez 200 euros\n");
        gold += 200;
        XP += 100;
        Experience();

    }
else if (hp <= 0)
    {
        Sleep(1000);
        system("cls");
        printf(" COVID-18 vous contamine !\n");
        system("cls");
        Menu();
    }
}

void AttaqueIA()
{
    srand(time(NULL));
    int ChoixIA = rand()%2+1;
    switch(ChoixIA)
    {
    case 1:
        Color(4,0);
        printf(" COVID-18 utilise barre de metro  \n");
        Color(15,0);
        if (gold <= 0)
        {
            printf(" Vous n'avez plus d'argent \n");
            hp -= 15;
            printf("Il vous reste %d points de vie \n", hp);
        }
        else
        {
            gold-=30;
            printf(" Vous perdez de l'argent \n");
            printf(" Il vous reste %d euros \n\n", gold);
        }
    break;
    case 2:
        Color(4,0);
        printf(" COVID-18 utilise infection \n\n");
        Color(9,0);
        printf(" Vous etes infecter ! \n\n");
        hp -= 20;
        Color(15,0);
        printf("Il vous reste %d point de vie \n\n", hp);
        break;
    }
}
void AttaqueJ()
{
    printf("Choisissez une attaque : \n\n");
    Color(1,0);
    printf("1. Ca tue pas Africain\n");
    printf("2. Jet de desinfectant \n");
    printf("3. Potions \n");
    Color(15,0);
    int entry = Choice(1,3);
    switch(entry)
    {
    case 1:
        hpIA -= 2*force;
        Color(4,0);
        printf ("Il reste a l'ennemi %d points de vie \n", hpIA);
        Color(15,0);
        printf(" Votre force augmente \n");
        force += 5;
        break;
    case 2:
        srand(time(NULL));
    int chance = rand()%3+1;
    if (chance == 1 || chance == 3)
        {
            printf(" Vous lancez du desinfectant sur l'ennemi \n");
            hpIA -= 3*force;
            printf(" Il le prend en pleine tete, il lui reste %d points de vie\n", hpIA);

        }
    else
        {
            printf(" Le desinfectant vous echappe des mains et vous blesse \n");
            hp -= 10;
            printf(" Il vous reste %d points de vie \n", hp);
        }
        break;
    case 3:
        Utilisation();
        break;
    }
}
void Utilisation()
{
    printf("Voulez vous utiliser : \n");
    printf("1. x1 Potion de Vie (%d Potions de vie restantes)\n", inventaire[0]);
    printf("2. x1 Potion de Force(%d Potions de force restantes) \n", inventaire[1]);
    printf("3. Rien \n");
    int entry = Choice(1,3);
    if(entry == 1 && inventaire[0]>=1)
    {
        hp += 20;
        HpTotal += 20;
        inventaire[0]--;
        printf("Vous venez d'utiliser une Potion de Vie \n");
        printf("Il vous en reste %d\n", inventaire[0]);
        printf("Vous avez %d Points de vie sur %d\n", hp, HpTotal);
        Utilisation();
    }
    else if(entry == 1 && inventaire[0]<1)
    {
        printf("Vous n'avez plus de potions \n");
        Utilisation();
    }
    if(entry == 2 && inventaire[1]>=1)
    {
        inventaire[1]--;
        force += 5;
        printf("Vous venez d'utiliser une Potion de Force \n");
        printf("Il vous en reste %d \n", inventaire[1]);
        printf(" Votre Force est de %d \n", force);
        Utilisation();
    }
    else if(entry ==2 && inventaire[1] < 1)
    {
        printf("Vous n'avez plus de potions\n");
        Utilisation();
    }
}
void inventaire2()
{
inventaire[0] = 1;
inventaire[1] = 1;
for(int i=0;i<6;i++);
printf("Potions de soin x %d \n",inventaire[0]);
printf("Potions de force x %d \n",inventaire[1]);
}
void Combat2()
{
    hpIA = 500;
    srand(time(NULL));
    int tour = rand()%2+1;
    switch(tour)
    {
    case 1:
    printf("L'ennemi commence \n");
    break;
    case 2:
    printf("Vous commencez \n");
    break;
    }
while (hp && hpIA > 0)
    {
        if (tour == 1)
        {
            AttaqueIA2();
            AttaqueJ2();
        }
        else
        {
            AttaqueJ2();
            AttaqueIA2();
        }

    }
if (hpIA <= 0)
    {
        system("cls");
        Color(2,0);
         printf("  ______   ______   .______        ______   .__   __.      ___   ____    ____  __  .______       __    __       _______.\n"
           " /      | /  __  \\  |   _  \\      /  __  \\  |  \\ |  |     /   \\  \\   \\  /   / |  | |   _  \\     |  |  |  |     /       |\n"
           "|  ,----'|  |  |  | |  |_)  |    |  |  |  | |   \\|  |    /  ^  \\  \\   \\/   /  |  | |  |_)  |    |  |  |  |    |   (----`\n"
           "|  |     |  |  |  | |      /     |  |  |  | |  . `  |   /  /_\\  \\  \\      /   |  | |      /     |  |  |  |     \\   \\    \n"
           "|  `----.|  `--'  | |  |\\  \\----.|  `--'  | |  |\\   |  /  _____  \\  \\    /    |  | |  |\\  \\----.|  `--'  | .----)   |   \n"
           " \\______| \\______/  | _| `._____| \\______/  |__| \\__| /__/     \\__\\  \\__/     |__| | _| `._____| \\______/  |_______/    \n\n\n\n\n\n\n");

           Color(12,0);
        printf("Felicitations vous avez terminer le jeu");
        Sleep(5000);
        system("cls");

    }
else if (hp <= 0)
    {
        printf(" Vous etes mort ! Le virus vous a terraser ! ");
        system("cls");
        Menu();
    }
}
void AttaqueIA2()
{
    srand(time(NULL));
    int ChoixIA = rand()%3+1;
    switch(ChoixIA)
    {
    case 1:
        Color(12,0);
        printf(" COVID-19 utilise : explo-coco-virus \n");
        Color(15,0);
        printf("Vous perdez de la sante mentale et commencez a avoir de la fievre...");
        printf(" Il vous reste %d de Sante mentale \n", santeMentale );
        if (santeMentale <= 0)
        {
            printf(" Vous devenez fou et sortez tout nu dans les rues d'Ermont \n");
            hp -= 30;
            printf("Il vous reste %d points de vie \n\n", hp);
        }
    break;
    case 2:
        Color(12,0);
        printf(" \nCOVID-19 utilise : cora aerien  \n");
        Color(15,0);
        printf(" Vous commencez a eternuer \n");
        hp -= 20;
        printf("Il vous reste %d point de vie \n\n", hp);
        break;
    case 3:
        Color(12,0);
        printf(" \nCOVID-19 utilise : execution du corona\n");
        Color(15,0);
        printf(" Vous perdez la moitie de votre sante mentale \n");
        santeMentale/=2;
        hp -= 25;
        printf(" Il vous reste %d de Sante mentale \n", santeMentale );
        printf("Il vous reste %d points de vie \n", hp);
        break;
    }
}
void AttaqueJ2()
{
    Color(9,0);
    printf("1. Distribution de desinfectant \n");
    printf("2. Demander la fermeture des ecoles \n");
    printf("3. Potions \n");
    Color(15,0);
    int entry = Choice(1,3);
    switch(entry)
    {
    case 1:
        hpIA -= 2*force;
        printf ("Il reste a l'ennemi %d points de vie \n", hpIA);
        printf(" Votre force augmente \n");
        force += 5;
        break;
    case 2:
        srand(time(NULL));
    int chance = rand()%3+1;
    if (chance == 1 || chance == 3)
        {
            printf(" Vous demandez la fermeture des ecoles\n");
            hpIA -= 3*force;
            printf(" Cela fonctionne, il reste a l'ennemi %d points de vie\n", hpIA);

        }
    else
        {
            printf(" Cela echoue ! Macron s'en fout ! \n");
            hp -= 10;
            printf(" Il vous reste %d points de vie \n", hp);
        }
        break;
    case 3:
        Utilisation();
        break;
    }
}
void Experience()
{
    if (XP > 100)
    {
        printf("Vous avez atteint le niveau 2 ! \n");
        printf("Vos caracteristiques augmentes : \n");
        printf("Vos points de vie augmentent de 50,  \n");
        printf("Votre force augmente de 2 \n");
        hp += 50;
        HpTotal += 50;
        printf("Votre maximum de points de vie est maintenant de %d\n", HpTotal);
        force += 2;
    }
    else if (XP > 200)
    {
        printf("Vous avez atteint le niveau 3 ! \n");
        hp += 50;
        HpTotal += 50;
        force += 2;
        printf("Vos caracteristiques augmentes : \n");
        printf("Vos points de vie augmentent de 50 \n");
        printf("Votre force augmente de 2 \n");
        printf("Votre maximum de points de vie est maintenant de %d\n", HpTotal);
    }
    else if (XP > 300)
    {
        printf("Vous avez atteint le niveau 4 ! \n");
        hp += 50;
        HpTotal += 50;
        force += 2;
        printf("Vos caracteristiques augmentes : \n");
        printf("Vos points de vie augmentent de 50 \n");
        printf("Votre force augmente de 2 \n");
        printf("Votre maximum de points de vie est maintenant de %d\n", HpTotal);
    }
    else
    {
            printf("Vous avez atteint le niveau maximum !\n");
    }
}
