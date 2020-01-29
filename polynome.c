//le fichier source doit contenir le corps des différents sous-programmes proposés
#include "polynome.h"
#include <stdio.h>
#include <stdlib.h>


monome creerMonome(float r, int e){
   // Crée un monôme à partir son coefficient et son degré,
    monome temp;
    temp=(mon*)malloc(sizeof(mon));
    temp->degre=e;
    temp->coef=r;
    return temp;
	}



polynome creerPolynome(){
    // Crée un polynôme vide
    return NULL;
}


polynome ajouterMonome(polynome p, monome m){
    /*ce programme ajoute un monome dans un polynome tout en le gardant trié*/
    polynome temp;
    polynome temp2;
    polynome p1=p;
    temp=(poly*)malloc(sizeof(poly));
    temp->valeur=m;
    temp->suivant=NULL;
    if (p==NULL) 
        p=temp;
    else{
        while ((p1->suivant !=NULL) && ((p1->valeur->degre)>(m->degre))){
            	p1=p1->suivant;
        }
        if (p1->valeur->degre==m->degre)
        	p1->valeur->coef=(m->coef)+(p1->valeur->coef);
        else{
            if((p1->valeur->degre)<(m->degre)){
                temp2=(poly*)malloc(sizeof(poly));
                temp2->valeur=p1->valeur;
                temp2->suivant=p1->suivant;
                p1->valeur=m;
                p1->suivant=temp2;
            }
            else
                p1->suivant=temp;
        }
    }
    return p;
}





polynome supprimerMonome(polynome p, int e){
    /*On suppose le polynome non null*/
    polynome p1=p;
    polynome temp;
    if (p!=NULL){
        if(p->valeur->degre==e){
            p=p->suivant;
            free(p1);
        }
        else{
            temp=p->suivant;
            while(temp!=NULL){
                if (temp->valeur->degre==e){
                    p1->suivant=temp->suivant;
                    free(temp);
                }
                p1=temp;
                temp=temp->suivant;
            }
        }
    }
    return p;
}




polynome additionner(polynome p1, polynome p2){
    //Calcule la somme de deux polynômes
	polynome p;
    polynome q1=p1;
    polynome q2=p2;
    p=creerPolynome();
	while((q1) && (q2)){
        monome m=0;
        m=(mon*)malloc(sizeof(mon));
        /*Utilisation des monomes pour ensuite les ajouter dans le polynome à l'aide de la fonction ajouterpolynome(polynome p, int e)*/
		if (q1->valeur->degre==q2->valeur->degre){
            m->coef=(q1->valeur->coef) + (q2->valeur->coef);
            m->degre=q1->valeur->degre;
            p=ajouterMonome(p,m);
			q1=q1->suivant;
			q2=q2->suivant;
		}
		else{
			if ((q1->valeur->degre) > (q2->valeur->degre)){
				m->coef=(q1->valeur->coef);
				m->degre=q1->valeur->degre;
                p=ajouterMonome(p,m);
				q1=q1->suivant;
			}
			else{
				m->coef=(q2->valeur->coef);
				m->degre=q2->valeur->degre;
                p=ajouterMonome(p,m);
				q2=q2->suivant;
			}
		}
	}
    if (q1==NULL && q2!=NULL){
        while (q2){
            monome m=0;
            m=(mon*)malloc(sizeof(mon));
            m->coef=(q2->valeur->coef);
            m->degre=q2->valeur->degre;
            p=ajouterMonome(p,m);
            q2=q2->suivant;
        }
    }
    else{
        if (q1!=NULL && q2==NULL){
            while (q1){
                monome m=0;
                m=(mon*)malloc(sizeof(mon));
                m->coef=(q1->valeur->coef);
                m->degre=q1->valeur->degre;
                p=ajouterMonome(p,m);
                q1=q1->suivant;
            }
        } 
    }
	return p;
}



polynome copier(polynome p){
    // fonction auxiliaire  qui nous permet de copier une polynome 'p' ,pour ne pas repeter le meme code dans plusieurs fonctions 
    polynome p1;
    p1=creerPolynome();
    while(p){
        monome m=0;
        m=(mon*)malloc(sizeof(mon));
        m->degre=(p->valeur->degre);
        m->coef=(p->valeur->coef);
        p1=ajouterMonome(p1,m);
        p=p->suivant;
    }
    return p1;
}






polynome multiplier(polynome p1, polynome p2){
   // Calcule le produit de deux polynômes
    polynome p;
    polynome q1;
    polynome q2;
    q1=copier(p1);
    q2=copier(p2);
    p=creerPolynome();
    while (p2){ /*Cette boucle sert à multiplier le premier Monome de p1 avec chacun des monomes de p2*/
        monome m=0;
        m=(mon*)malloc(sizeof(mon));
        m->degre=(p1->valeur->degre)+(p2->valeur->degre);
        m->coef=(p1->valeur->coef)*(p2->valeur->coef);
        p=ajouterMonome(p,m);
        p2=p2->suivant;
    }
    while (q1){/*ici utilisation d'une copie de p1 dans q1 */
        /* Cela sert à mutliplier tous les autres Monomes de p1 (sauf le premier) avec chacun des monomes de p2*/
        q1=q1->suivant; /*Passage directement au deuxième élément de p1 car le 1er a déja été fait dans la 1ère boucle*/
        while (q2){ /*Utilisation d'une copie de p1 et p2 car sinon cela ne fonctionne pas*/
            monome m=0;
            m=(mon*)malloc(sizeof(mon));
            m->degre=(q1->valeur->degre)+(q2->valeur->degre);
            m->coef=(q1->valeur->coef)*(q2->valeur->coef);
            p=ajouterMonome(p,m);
            q2=q2->suivant;
        }
    }
    return p;
}






monome mderiver (monome m,int e){
    //fonction itérative auxiliaire pour ne pas repeter le meme code dans plusieurs fonctions de dérivation
    //quand degre=0? ->supprimer le monome ??
	int d;
	d=m->degre;
	if (m->degre!=0){
    	while (m->degre!=(d-e)){
       		m->coef=(m->coef)*(m->degre);
        	m->degre=(m->degre)-1;
    	}
    	if (m->degre<=0 && m->coef==0){
    		m->degre=0;
    		m->coef=0;
    	}
    }
    return m;
}


monome mderiverR(monome m, int e){
    //Pourqui pas , une version récursive de mderiver 
    if (m->degre<=0 && m->coef==0){
        m->degre=0;
        m->coef=0;
    }
    else{
        if (e!=0){
            m->coef=(m->coef)*(m->degre);
            m->degre=(m->degre)-1;
            mderiverR(m,e-1);
        }
    }
    return m;
}



polynome pderiver(polynome p, int e){
    //Calcule la k ième dérivé d’un polynôme
    polynome p1=p;
    while (p1!=NULL){
            p1->valeur=mderiver(p1->valeur,e);
            p1=p1->suivant;
    }
    return p;
}





void ecrireMI(monome m){
    //afficher un monome
    printf("(%f,%d),",m->coef,m->degre);
}


void ecrirePolynomeR(polynome p){
    //afficher une polynome "la version récursive"  
    if (p->suivant==NULL)
        ecrireMI(p->valeur);
    else{
        ecrireMI(p->valeur);
        ecrirePolynomeR(p->suivant);
    }
}


void ecrirePolynome(polynome p){
    //  //afficher une polynome "la version itérative"
    polynome p1=p;
    while(p1){
        ecrireMI(p1->valeur);
        p1=p1->suivant;
    }
    printf("\n");
}



polynome creationPolynome(){
    /*Vous pouvez ajouter un sous-programme permettant de
     créer un polynôme par interaction avec l’utilisateur (lecture du coefficient et du degré de chaque monôme) 
     en utilisant les opérations creerPolynome et ajouterMonome.*/
    monome m=0;
    int e=0;
    float r;
    polynome p;
    p=creerPolynome();
    printf("Veuillez entrer le degré du Monome de ce polynome : ");
    printf("%d",e);
    printf("Veuillez entrer le coefficient du Monome de ce polynome : ");
    scanf("%f",&r);
    m->coef=r;
    m->degre=e;
    p=ajouterMonome(p,m);
    return p;
}