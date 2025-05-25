
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 500                      // Nombre maximal d'etudiants
#define FICHIER "etudiants.txt"      // Nom du fichier de sauvegarde

// Structure representant un etudiant
typedef struct
{
    int num_carte;                  // Numero de carte etudiant (identifiant unique)
    char nom[30];                   // Nom de l'etudiant
    char prenom[30];                // Prenom
    int jour_naiss, mois_naiss, annee_naiss;  // Date de naissance
    char lieu_naiss[30];            // Lieu de naissance
    char genre[10];                 // Genre (masculin, feminin...)
    char filiere[30];               // Filiere d'etudes
    float moyenne;                  // Moyenne au BAC
    int tel;                        // Numero de telephone
    int jour_insc, mois_insc, annee_insc;      // Date d'inscription
} Etudiant;

Etudiant Tab_etud[MAX];             // Tableau d'etudiants
int Total = 0,i=0;                      // Nombre total d'etudiants enregistres

// Prototypes des fonctions
void charger_depuis_fichier();
void sauvegarder_dans_fichier();
void ajout_etudiant();
void affiche_etudiant();
void recherche_etudiant();
void modifier_donnees_etudiant();
void supprimer_etudiant();
void trier_par_nom();
void trier_par_moyenne();
void trier_par_numero();
int verifier_numero_unique(int num);

int main()
{
    int choix, save;

    charger_depuis_fichier(); // Chargement des etudiants depuis le fichier texte a l'ouverture

    // Menu principal
    do
    {
        printf("\n======= MENU GESTIONNAIRE D'ETUDIANT EN C =======");
        printf("\n\t1 : AJOUTER UN ETUDIANT ");
        printf("\n\t2 : AFFICHER TOUT LES ETUDIANTS");
        printf("\n\t3 : RECHERCHER UN ETUDIANT ");
        printf("\n\t4 : MODIFIER LES DONNEES D'UN ETUDIANT ");
        printf("\n\t5 : SUPPRIMER UN ETUDIANT");
        printf("\n\t6 : SAUVEGARDER LES DONNEES");
        printf("\n\n 0 : Quitter");
        printf("\n\nEntrer votre choix(0-6) : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            ajout_etudiant();
            break;
        case 2:
            affiche_etudiant();
            break;
        case 3:
            recherche_etudiant();
            break;
        case 4:
            modifier_donnees_etudiant();
            break;
        case 5:
            supprimer_etudiant();
            break;
        case 6:
            sauvegarder_dans_fichier();
            break;
        case 0:
            printf("Voulez-vous sauvegarder avant de quitter ? (1=Oui / 2=Non) : ");
            scanf("%d", &save);
            if (save == 1) sauvegarder_dans_fichier();
            break;
        default:
            printf("Choix invalide.\n");
        }
    }
    while (choix != 0);

    return 0;
}

// Fonction pour charger les etudiants a partir d'un fichier texte
void charger_depuis_fichier()
{
    FILE *f = fopen(FICHIER, "r");
    if (!f)
    {
        printf("Aucun fichier existant a charger.\n");
        return;
    }

    while (fscanf(f, "%d %s %s %d/%d/%d %s %s %s %f %d %d/%d/%d\n",
                  &Tab_etud[Total].num_carte,
                  Tab_etud[Total].nom,
                  Tab_etud[Total].prenom,
                  &Tab_etud[Total].jour_naiss,
                  &Tab_etud[Total].mois_naiss,
                  &Tab_etud[Total].annee_naiss,
                  Tab_etud[Total].lieu_naiss,
                  Tab_etud[Total].genre,
                  Tab_etud[Total].filiere,
                  &Tab_etud[Total].moyenne,
                  &Tab_etud[Total].tel,
                  &Tab_etud[Total].jour_insc,
                  &Tab_etud[Total].mois_insc,
                  &Tab_etud[Total].annee_insc) == 14)
    {
        Total++;
    }

    fclose(f);
    printf("[  %d etudiants charges depuis le fichier 'etudiant.txt' ].\n", Total);
}

// Fonction pour sauvegarder les etudiants dans le fichier texte
void sauvegarder_dans_fichier()
{
    FILE *f = fopen(FICHIER, "w");
    if (!f)
    {
        printf("Erreur d'ouverture du fichier.\n");
        return;
    }

    for (int i = 0; i < Total; i++)
    {
        fprintf(f, "%d %s %s %d/%d/%d %s %s %s %.2f %d %d/%d/%d\n",
                Tab_etud[i].num_carte, Tab_etud[i].nom, Tab_etud[i].prenom,
                Tab_etud[i].jour_naiss, Tab_etud[i].mois_naiss, Tab_etud[i].annee_naiss,
                Tab_etud[i].lieu_naiss, Tab_etud[i].genre, Tab_etud[i].filiere,
                Tab_etud[i].moyenne, Tab_etud[i].tel,
                Tab_etud[i].jour_insc, Tab_etud[i].mois_insc, Tab_etud[i].annee_insc);
    }

    fclose(f);
    printf("\nDonnees sauvegardees avec succes.\n");
}

//Fonction qui verifie si un numero numero de carte n'est pas en double dans le fichier etudiant.txt
int verifier_numero_unique(int num)
{
    for (int i = 0; i < Total; i++)
    {
        if (Tab_etud[i].num_carte == num)
            return 0; // numero deja existant
    }
    return 1; // numero unique
}

// Fonction pour ajouter un etudiant au tableau
void ajout_etudiant()
{
    if (Total >= MAX)
    {
        printf("\nCapacite maximale atteinte.\n");
        return;
    }

   //  génère un nombre aléatoire compris entre 100 et 9100 non existant dans le fichier
    srand(time(NULL));
    int num_genere;
    do {
        num_genere = 100 + rand() % 9000;
    } while (!verifier_numero_unique(num_genere));
    Tab_etud[Total].num_carte = num_genere;

    printf("\n--- Ajout d'un etudiant ---\n");
    printf("Nom : ");
    scanf("%s", Tab_etud[Total].nom);
    printf("Prenom : ");
    scanf("%s", Tab_etud[Total].prenom);
    printf("Date de naissance (jj mm aaaa) : ");
    scanf("%d %d %d", &Tab_etud[Total].jour_naiss, &Tab_etud[Total].mois_naiss, &Tab_etud[Total].annee_naiss);
    printf("Lieu de naissance : ");
    scanf("%s", Tab_etud[Total].lieu_naiss);
    printf("Genre : ");
    scanf("%s", Tab_etud[Total].genre);
    printf("Filiere : ");
    scanf("%s", Tab_etud[Total].filiere);
    printf("Moyenne BAC : ");
    scanf("%f", &Tab_etud[Total].moyenne);
    printf("Telephone : ");
    scanf("%d", &Tab_etud[Total].tel);
    printf("Date d'inscription (jj mm aaaa) : ");
    scanf("%d %d %d", &Tab_etud[Total].jour_insc, &Tab_etud[Total].mois_insc, &Tab_etud[Total].annee_insc);

    Total++;
    printf("Etudiant ajoute avec succes.\n");
}

// Fonctions de tri par nom
void trier_par_nom()
{
    for (int i = 0; i < Total - 1; i++)
    {
        for (int j = i + 1; j < Total; j++)
        {
            if (strcmp(Tab_etud[i].nom, Tab_etud[j].nom) > 0)
            {
                Etudiant temp = Tab_etud[i];
                Tab_etud[i] = Tab_etud[j];
                Tab_etud[j] = temp;
            }
        }
    }
}

//fonction  qiu tri les etudiant par moyenne
void trier_par_moyenne()
{
    for (int i = 0; i < Total - 1; i++)
    {
        for (int j = i + 1; j < Total; j++)
        {
            if (Tab_etud[i].moyenne < Tab_etud[j].moyenne)
            {
                Etudiant temp = Tab_etud[i];
                Tab_etud[i] = Tab_etud[j];
                Tab_etud[j] = temp;
            }
        }
    }
}

//fonction dui tru les etudiant par numero de carte
void trier_par_numero()
{
    for (int i = 0; i < Total - 1; i++)
    {
        for (int j = i + 1; j < Total; j++)
        {
            if (Tab_etud[i].num_carte > Tab_etud[j].num_carte)
            {
                Etudiant temp = Tab_etud[i];
                Tab_etud[i] = Tab_etud[j];
                Tab_etud[j] = temp;
            }
        }
    }
}

// Fonction d'affichage de tous les etudiants
void affiche_etudiant()
{
    if (Total == 0)
    {
        printf("Aucun etudiant a afficher.\n");
        return;
    }

    int choix_tri;
    printf("\n Choisir le tri :\n\t1 - Par nom (A-Z)\n\t2 - Par moyenne (decroissante)\n\t3 - Par numero de carte (croissant)\n\t\tVotre choix : ");
    scanf("%d", &choix_tri);

    if (choix_tri == 1) trier_par_nom();
    else if (choix_tri == 2) trier_par_moyenne();
    else if (choix_tri == 3) trier_par_numero();

    printf("\n--- Liste des etudiants ---\n");
    for (int i = 0; i < Total; i++)
    {
        printf("\n\n ==-- ' Numero de Carte : %d ' --==",Tab_etud[i].num_carte);
                printf("\n\tNom: %s",Tab_etud[i].nom);
                printf("\n\tPrenom: %s",Tab_etud[i].prenom);
                printf("\n\tDate de Naissance: %d/%d/%d ",Tab_etud[i].jour_naiss,Tab_etud[i].mois_naiss,Tab_etud[i].annee_naiss);
                printf("\n\tLieu de Naissance: %s",Tab_etud[i].lieu_naiss);
                printf("\n\tGenre: %s",Tab_etud[i].genre);
                printf("\n\tFiliere: %s ",Tab_etud[i].filiere);
                printf("\n\tMoyenne au BAC: %.2f ",Tab_etud[i].moyenne);
                printf("\n\tNumero de Telephone: %d ",Tab_etud[i].tel);
                printf("\n\tDate d'Inscription: %d/%d/%d \n\t",Tab_etud[i].jour_insc,Tab_etud[i].mois_insc,Tab_etud[i].annee_insc);
    }
    printf("\n\nTotal : %d etudiants affichers.\n", Total);
}

//Fonction de rechrche d'un etudiant
void recherche_etudiant()
{
    int choix, numcarte;
    char name[30];
    printf("\n1 - Recherche par Nom \n2 - Recherche par numero de carte\n\tVotre choix : ");
    scanf("%d", &choix);

    if (choix == 1)
    {
        printf("Entrez le nom : ");
        scanf("%s", name);
        for ( i = 0; i < Total; i++)
        {
            if (strcmp(Tab_etud[i].nom, name) == 0)
            {
                printf("\n\n ==-- ' Numero de Carte : %d ' --==",Tab_etud[i].num_carte);
                printf("\n\tNom: %s",Tab_etud[i].nom);
                printf("\n\tPrenom: %s",Tab_etud[i].prenom);
                printf("\n\tDate de Naissance: %d/%d/%d ",Tab_etud[i].jour_naiss,Tab_etud[i].mois_naiss,Tab_etud[i].annee_naiss);
                printf("\n\tLieu de Naissance: %s",Tab_etud[i].lieu_naiss);
                printf("\n\tGenre: %s",Tab_etud[i].genre);
                printf("\n\tFiliere: %s ",Tab_etud[i].filiere);
                printf("\n\tMoyenne au BAC: %.2f ",Tab_etud[i].moyenne);
                printf("\n\tNumero de Telephone: %d ",Tab_etud[i].tel);
                printf("\n\tDate d'Inscription: %d/%d/%d \n\t",Tab_etud[i].jour_insc,Tab_etud[i].mois_insc,Tab_etud[i].annee_insc);

                return;
            }
        }
        printf("Etudiant non trouve.\n");
    }
    else if (choix == 2)
    {
        printf("\nEntrez le numero de carte : ");
        scanf("%d", &numcarte);
        for (i = 0; i < Total; i++)
        {
            if (Tab_etud[i].num_carte == numcarte)
            {
                printf("\n\n ==-- ' Numero de Carte : %d ' --==",Tab_etud[i].num_carte);
                printf("\n\tNom: %s",Tab_etud[i].nom);
                printf("\n\tPrenom: %s",Tab_etud[i].prenom);
                printf("\n\tDate de Naissance: %d/%d/%d ",Tab_etud[i].jour_naiss,Tab_etud[i].mois_naiss,Tab_etud[i].annee_naiss);
                printf("\n\tLieu de Naissance: %s",Tab_etud[i].lieu_naiss);
                printf("\n\tGenre: %s",Tab_etud[i].genre);
                printf("\n\tFiliere: %s ",Tab_etud[i].filiere);
                printf("\n\tMoyenne au BAC: %.2f ",Tab_etud[i].moyenne);
                printf("\n\tNumero de Telephone: %d ",Tab_etud[i].tel);
                printf("\n\tDate d'Inscription: %d/%d/%d \n\t",Tab_etud[i].jour_insc,Tab_etud[i].mois_insc,Tab_etud[i].annee_insc);

                return;
            }
        }
        printf("\nEtudiant non trouver.\n");
    }
}

//Fonction de suppression d'un etudiant
void supprimer_etudiant()
{
    int id, Trouve = 0;
    printf("\nEntrez le numero de carte de l'etudiant a supprimer : ");
    scanf("%d", &id);

    for (i = 0; i < Total; i++)
    {
        if (Tab_etud[i].num_carte == id)
        {
            Trouve = 1;
            for (int j = i; j < Total - 1; j++)
            {
                Tab_etud[j] = Tab_etud[j + 1];
            }
            Total--;
            printf("\nEtudiant supprimer avec succes.\n");
            return;
        }
    }
    if (!Trouve)
        printf("\nEtudiant introuvable.\n");
}

//Fonction qui modifie les donnees d'un etudiant
void modifier_donnees_etudiant()
{
    int numcarte, Trouve = 0;
    printf("\n\nEntrez le numero de carte de l'etudiant a modifier : ");
    scanf("%d", &numcarte);

    for (i = 0; i < Total; i++)
    {
        if (Tab_etud[i].num_carte == numcarte)
        {
            printf("\tNouveau Nom : ");
            scanf("%s", Tab_etud[i].nom);
            printf("\tNouveau Prenom : ");
            scanf("%s", Tab_etud[i].prenom);
            printf("\tNouvelle moyenne : ");
            scanf("%f", &Tab_etud[i].moyenne);
            printf("\nDonnees modifiees avec succes.\n");
            return;
        }
    }
    printf("\nEtudiant introuvable.\n");
}
