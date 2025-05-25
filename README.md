#  Projet C – Gestionnaire D'etudiant

Ce projet est un **Gestionnaire D'etudiant** écrite en langage C.
C'est une application de gestionnaire etudiant multifonctionnelle écrite en langage C.
 Il propose un menu interactif permettant d'effectuer plusieurs action comme ajouter un etudiant, accessibles à partir de l'invitecommande.
Elle offre différentes fonctionnalités  dans un cadre éducatif et illustrant les bases de la programmation structurée notamment :

- Utilisation des Structure,des tableaux de structures
- Lecture et ecriture dans un fichier
- Utilisation des fonctions (void)
- Boucles do-while et for
- Tri et filtrage depuis un fichier
- Conditions if-else et switch
- Utilisation de tableaux
- Entrée / sortie standard (scanf, printf)
- Utilisation de strcmp qui compare deux chaine
- Utilisation de srand pour generer un nombre aleatoire 
- Manipulation des fichier 
- Utilisation des Blibliotheques stdio.h,sdlib.h.time.h,string.h;


## Objectif pédagogique

- Apprendre à organiser un projet C en équipe
- Se répartir les fonctionnalités de manière claire
- Travailler en autonomie sur des modules
- Utiliser des fonctions et la structure du langage C
- Manipuler des fichiers en language c


## Organisation du projet

Chaque fonctionnalité est implémentée sous forme de **procédure (`void`) indépendante** dans le fichier `student_manager.c`.


### Répartition suggérée des fonctionnalités

La participation de chaque menbre du rush est  reportées dans le tableau suivant :

### Membre                                   | Fonctionnalité
- AKALETE    ('Chef de Rush')
- -   Afficher les etudiants(tri inclut),sauvegarder,fusion et mise en propre du code ,README
- Ismael Moctar
-  -  Modifier un etudiant
- Attahir
- -   Ajouter un etudiant
- Karki Mahaman
-  -  Rechercher un etudiant
- Souley Adamou
-  -  supprimer  un etudiant


## Fonctionnalités

Le programme propose les options suivantes via un menu :

 1. **AJOUTER UN ETUDIANT**  
   ajouter un etudiant

 2. **AFFICHER TOUT LES ETUDIANTS**  
afficher les etudiants en trient par nom , moyenne ou numero de carte

 3. **RECHERCHER UN ETUDIANT**  
   rechercher un etudiant specifique

 4. **MODIFIER LES DONNEES D'UN ETUDIANT**  
mofidifier les donnees d'un etudiant specifique

5. **SUPPRIMER UN ETUDIANT**  
 supplimer un etudiant precis en entrent son numero de carte

6. **SAUVEGARDER LES DONNEES**  
  Sauvegarder les donnees dans le fichier etudiants.txt

0. **Quitter**  
   Permet de quitter le programme.


##  Structure du fichier

Le fichier `student_manager.c` contient :

- Un menu principal (dans `main`) qui redirige vers chaque fonction selon le choix de l’utilisateur

- Une fonction par fonctionnalité


##  Note Test

- Le programme est entièrement interactif : il affiche un menu, lit les entrées utilisateur et affiche les résultats à l'écran.

- Certaines entrées utilisateur ne sont pas protégées (pas de validation de type par exemple), donc il faut éviter d'entrer des valeurs non numériques.

- Les commentaires sont en français et le programme est bien structuré avec des procédures pour chaque fonctionnalité.


##  Compilation

Utilisez `gcc` pour compiler ce projet :

```bash
gcc codecalc_c.c -o codecalc -lm

```code-bloks
build and run

```autres
vous pouvez aussi utilisez dev-c, VS - Code si vous avez les extension requis, C++ Builder

