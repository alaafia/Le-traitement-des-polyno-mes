#include "polynome.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    
    monome m;
    polynome p;
    
    /*test du sous-programme creerMonome qui retourne un monome*/
    float r;
    int e;
    printf("\n Test du sous-programme creerMonome \n\n");
    printf("Veuillez entrer le coefficient du Monome : ");
    scanf("%f",&r);
    printf("Veullez entrer le degré du Monome : ");
    scanf("%d",&e);
    m=creerMonome(r,e);
    ecrireMI(m);
    printf("\n");
    /*Permet d'afficher le monome créer et en même temps de testert la fonction d'affichage d'un monome*/
    
    
    
    
    /*Le sous-programme CreerPolynome retourne un polynome NULL*/
    printf("\n Test du sous-programme creerPolynome \n\n");
    p=creerPolynome();
    printf("Le polynome NULL a été créé \n");
    
    
    
    
    
    /*Le prochain test : sous-programme ajouterMonome qui permet l'ajout d'un monome dans un polynome*/
    printf("\n Test du sous-programme ajouterMonome \n\n");
    p=ajouterMonome(p,m);
    ecrirePolynome(p);
    /*ajout du monome m dans le polynome p*/
    
    
    
    
    /*Le prochain sous-programme tester est supprimerMonome*/
    printf("\n Test du sous-programme supprimerMonome \n\n");
    p=supprimerMonome(p,e);
    /*ici on supprimer le monome créer dans le premier sous-programme CreerMonome et ajouter dans le polynome p juste avant*/
    ecrirePolynome(p);
    
    
    
    
    /*Test du sous-programme additionner qui additionne 2 polynomes ensemble*/
    printf("\n Test du sous-programme additionner \n\n");
    
    
    
    
    
    
    
    return 0;
}

