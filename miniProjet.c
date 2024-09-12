#include <stdio.h>
#include <string.h>

typedef struct{
    int numero_unique;
    char nom[30];
    char prenom[30];
    char date_naissance[20];
    char departement[30];
    float note_generale;
} etudiant;
etudiant etudiants[300];
int nbr_etudiants = 0;
void ajout_etudiant(){
    printf("Numero unique: ");
    scanf("%d", &etudiants[nbr_etudiants].numero_unique);
    printf("Nom: ");
    scanf(" %[^\n]s", etudiants[nbr_etudiants].nom);
    printf("Prenom: ");
    scanf(" %[^\n]s", etudiants[nbr_etudiants].prenom);
    printf("Date de naissance (JJ/MM/AAAA): ");
    scanf(" %[^\n]s", etudiants[nbr_etudiants].date_naissance);
    printf("Departement: ");
    scanf(" %[^\n]s", etudiants[nbr_etudiants].departement);
    printf("Note generale: ");
    scanf("%f", &etudiants[nbr_etudiants].note_generale);
    nbr_etudiants++;
    printf("etudiant ajoute.\n");
}
void modifier_etudiant()
{
    int numero_unique;
    printf("entrer le numero unique de l'etudiant a modifier: ");
    scanf("%d", &numero_unique);
    for (int i = 0; i < nbr_etudiants; i++)
    {
        if (etudiants[i].numero_unique == numero_unique)
        {
            printf("modifier les informations de l'etudiant:\n");
            printf("Nouveau nom: ");
            scanf(" %[^\n]s", etudiants[i].nom);
            printf("Nouveau prenom: ");
            scanf(" %[^\n]s", etudiants[i].prenom);
            printf("Nouvelle date de naissance (JJ/MM/AAAA): ");
            scanf(" %[^\n]s", etudiants[i].date_naissance);
            printf("Nouveau departement: ");
            scanf(" %[^\n]s", etudiants[i].departement);
            printf("Nouvelle note generale: ");
            scanf("%f", &etudiants[i].note_generale);
            printf("modification effectuee avec succes.\n");
            return;
        }
    }
    printf("Cet etudiant ne se trouve pas.\n");
}
void supprimer_etudiant()
{
    int numero_unique;
    printf("Entrer le numero unique de l'etudiant a supprimer: ");
    scanf("%d", &numero_unique);
    for (int i = 0; i < nbr_etudiants; i++)
    {
        if (etudiants[i].numero_unique == numero_unique)
        {
            for (int j = i; j < nbr_etudiants - 1; j++)
            {
                etudiants[j] = etudiants[j + 1];
            }
            nbr_etudiants--;
            printf("etudiant supprime.\n");
            return;
        }
    }
    printf("Cet etudiant ne se trouve pas.\n");
}
void afficher_etudiant()
{
    int numero_unique;
    printf("Entrer le numero de l'etudiant a afficher: ");
    scanf("%d", &numero_unique);
    for (int i = 0; i < nbr_etudiants; i++)
    {
        if (etudiants[i].numero_unique == numero_unique)
        {
            printf("Les details de cet etudiant sont:\n");
            printf("numero unique: %d\n", etudiants[i].numero_unique);
            printf("Nom: %s\n", etudiants[i].nom);
            printf("Prenom: %s\n", etudiants[i].prenom);
            printf("Date de naissance: %s\n", etudiants[i].date_naissance);
            printf("Departement: %s\n", etudiants[i].departement);
            printf("Note generale: %.2f\n\n", etudiants[i].note_generale);
            return;
        }
    }
}
float calculer_moyenne_departement(){
    float somme;
    char departement[30];
    int count = 0;
    printf("entrer le nom du departement:");
    scanf("%s",departement);
    somme = 0;
    for (int i = 0; i < nbr_etudiants; i++)
    {
        if (strcmp(etudiants[i].departement, departement) == 0)
        {
            somme += etudiants[i].note_generale;
            count++;
        }
    }
    printf("la moyenne generale de departement est: %.2f\n", somme / count);
    return somme / count;
}
float calculer_moyenne_universite()
{
    float somme = 0;
    for (int i = 0; i < nbr_etudiants; i++)
    {
        somme += etudiants[i].note_generale;
    }
    printf("la moyenne generale d'universite est: %.2f\n", somme / nbr_etudiants);
    return somme / nbr_etudiants;
}
void afficher_nombre_total_etudiants()
{
    printf("Le nombre total d'etudiants inscrits: %d\n", nbr_etudiants);
}
void afficher_etudiants_par_departement(){
    char departement[30];
    printf("entrez le nom du departement: ");
    scanf("%s", &departement);
    printf("Liste des etudiants du departement %s :\n", departement);
    for (int i = 0; i < nbr_etudiants; i++)
    {
        if (strcmp(etudiants[i].departement, departement) == 0)
        {
            printf("Etudiant trouve :\n");
            printf("Nom : %s\n", etudiants[i].nom);
            printf("Prenom : %s\n", etudiants[i].prenom);
            printf("Departement : %s\n", etudiants[i].departement);
            printf("Note generale : %.2f\n", etudiants[i].note_generale);
            return;
        }
    }
    printf("cet etudiant n'existe pas dans le departement %s\n", departement);
}
void afficher_etudiants_superieures_seuil()
{
    int reussi;
    float seuil;
    printf("Entrer le seuil de reussite : ");
    scanf("%f", &seuil);
    reussi = 0;
    for (int i = 0; i < nbr_etudiants; i++)
    {
        if (etudiants[i].note_generale >= seuil)
        {
            printf("Nom: %s\nPrenom: %s\nNote_generale: %.2f\n",etudiants[i].nom,etudiants[i].prenom,etudiants[i].note_generale);
            reussi++;
        }
    }
    printf("Nombre detudiants ayant une note superieure ou egale a %.2f: %d", seuil, reussi);
}
void afficher_3_meilleurs_etudiants(){
    etudiant temp;
    for (int i = 0; i < nbr_etudiants - 1; i++){
        for (int j = 0; j < nbr_etudiants - i - 1; j++){
            if (etudiants[j].note_generale < etudiants[j + 1].note_generale){
                temp = etudiants[j];
                etudiants[j] = etudiants[j + 1];
                etudiants[j + 1] = temp;
            }
        }
    }
    printf("Les 3 meilleurs etudiants:\n");
    for (int i = 0; i < 3 && i<nbr_etudiants; i++){
        printf("nom: %s\note_generale: %.2f\n",etudiants[i].nom,etudiants[i].note_generale);
    }
}
void afficher_nombre_etudiants_reussis()
{
    int reussi=0;
    char departement[30];
    printf("Entrer le nom du departement: ");
    scanf("%s",departement);
    for (int i = 0; i < nbr_etudiants; i++)
    {
        if (strcmp(etudiants[i].departement, departement) == 0 && etudiants[i].note_generale >= 10)
        {
            reussi++;
        }
    }
    printf("Le nombre d'etudiants ayant reussi dans le departement %s:%d\n",departement,reussi);
}
void rechercher_etudiant_par_nom()
{
    char nom_recherche[30];
    printf("Entrer le nom d'etudiant a rechercher:");
    scanf("%s", &nom_recherche);
    for (int i = 0; i < nbr_etudiants; i++)
    {
        if (strcmp(etudiants[i].nom, nom_recherche) == 0)
        {
            printf("Etudiant trouve :\n");
            printf("Nom : %s\n", etudiants[i].nom);
            printf("Prenom : %s\n", etudiants[i].prenom);
            printf("Departement : %s\n", etudiants[i].departement);
            printf("Note generale : %.2f\n", etudiants[i].note_generale);
            return;
        }
    }
    printf("Cet etudiant ne se trouve pas.\n");
}
void afficher_nombre_etudiants_par_departement(){
    char departement[30];
    printf("entrez le nom du departement: ");
    scanf("%s", &departement);
    printf("Liste des etudiants du departement %s :\n", departement);
    for (int i = 0; i < nbr_etudiants; i++)
    {
        if (strcmp(etudiants[i].departement, departement) == 0)
        {
            printf("Etudiant trouve :\n");
            printf("Nom : %s\n", etudiants[i].nom);
            printf("Prenom : %s\n", etudiants[i].prenom);
            printf("Departement : %s\n", etudiants[i].departement);
            printf("Note generale : %.2f\n", etudiants[i].note_generale);
        }
    }
    printf("cet etudiant n'existe pas dans le departement %s\n", departement);
}
void trier_etudiants(){
    int choix;
    etudiant temp;
    printf("Choisissez le type de tri:\n");
    printf("1_Tri alphabetique par nom (A-Z)\n");
    printf("2_Tri alphabétique par nom (Z-A)\n");
    printf("3_Tri par moyenne generale (de meilleure note au mauvaise note)\n");
    printf("4_Tri par moyenne generale (de mauvaise note au meilleure note)\n");
    printf("5_Tri selon le statut de réussite.\n");
    printf("6_Quitter.\n");
    printf("entrez votre choix:");
    scanf("%d",&choix);
    /*for (int i = 0; i < nbr_etudiants - 1; i++) {
        for (int j = i + 1; j < nbr_etudiants; j++) {
            if (choix == 1 && strcmp(etudiants[i].nom,etudiants[j].nom) > 0) {
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            } else if (choix == 2 && strcmp(etudiants[i].nom, etudiants[j].nom) < 0) {
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            } else if (choix == 3 && etudiants[i].note_generale < etudiants[j].note_generale) {
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            } else if (choix == 4 && etudiants[i].note_generale > etudiants[j].note_generale) {
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            } else if (choix == 5 && (etudiants[i].note_generale >= 10)) {
                temp = etudiants[i];
                etudiants[i] = etudiants[j];
                etudiants[j] = temp;
            }
        }
    }
    printf("etudiants tries avec succes!\n");*/
}              
int main()
{
    int choix, sub_choix1, sub_choix2, sub_choix3, sub_choix4, sub_choix5;
    do
    {
        printf("\nmenu principale:\n");
        printf("1_Ajouter un etudiant.\n");
        printf("2_Modifier ou supprimer un etudiant.\n");
        printf("3_Afficher les details d'un etudiant.\n");
        printf("4_Calculer la moyenne generale.\n");
        printf("5_Afficher les statistiques.\n");
        printf("6_Rechercher un etudiant.\n");
        printf("7_Trier un etudiant.\n");
        printf("8_Quitter.\n");
        printf("entrez vos choix: ");
        scanf("%d", &choix);
        switch (choix)
        {
        case 1:
            ajout_etudiant();
            break;
        case 2:
            printf("\nsous menu:\n");
            printf("1_Modifier un etudiant.\n");
            printf("2_Supprimer un etudiant.\n");
            printf("3_Quitter.\n");
            printf("entrez vos choix:");
            scanf("%d", &sub_choix1);
            switch (sub_choix1)
            {
            case 1:
                modifier_etudiant();
                break;
            case 2:
                supprimer_etudiant();
                break;
            }
            break;
        case 3:
            afficher_etudiant();
            break;
        case 4:
            printf("\nsous menu pour calculer:\n");
            printf("1_Afficher la moyenne generale de departement.\n");
            printf("2_Afficher la moyenne generale d'universite.\n");
            printf("3_Quitter.\n");
            printf("entrez vos choix:");
            scanf("%d", &sub_choix2);
            switch (sub_choix2)
            {
            case 1:
                calculer_moyenne_departement();
                break;
            case 2:
                calculer_moyenne_universite();
                break;
            }
            break;
        case 5:
            printf("\nsous menu pour afficher:\n");
            printf("1_Afficher le nombre total d'etudiants inscrits.\n");
            printf("2_Afficher le nombre d'etudiants dans chaque departement.\n");
            printf("3_Afficher les etudiants ayant une moyenne generale superieure a un certain seuil.\n");
            printf("4_Afficher les 3 etudiants ayant les meilleures notes.\n");
            printf("5_Afficher le nombre d'etudiants ayant reussi dans chaque departement.\n");
            printf("6_Quitter.\n");
            printf("entrez vos choix:");
            scanf("%d", &sub_choix3);
            switch (sub_choix3)
            {
            case 1:
                afficher_nombre_total_etudiants();
                break;
            case 2:
                afficher_etudiants_par_departement();
                break;
            case 3:
                afficher_etudiants_superieures_seuil();
                break;
            case 4:
                afficher_3_meilleurs_etudiants();
                break;
            case 5:
                afficher_nombre_etudiants_reussis();
                break;
            }
            break;
        case 6:
            printf("\nsous menu pour rechercher\n");
            printf("1_Rechercher l'etudiant par son nom.\n");
            printf("2_Afficher la liste des etudiants inscrits dans un departement specifique.\n");
            printf("3_Quitter.\n");
            printf("entrez vos choix:");
            scanf("%d", &sub_choix4);
            switch (sub_choix4)
            {
            case 1:
                rechercher_etudiant_par_nom();
                break;
            case 2:
                afficher_nombre_etudiants_par_departement();
                break;
            }
            break;
        case 7:
            trier_etudiants();
            break;
        default:
            printf("votre choix est invalide.\n");
            break;
        }
    } while (choix != 0);
    return 0;
}
