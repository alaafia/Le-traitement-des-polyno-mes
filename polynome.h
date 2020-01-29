
/* * Fichier source décrivant les structures et les différentes fonctions des polynomes * */
typedef struct mon{
	int degre;
	float coef;
	}mon;
typedef mon*monome;

typedef struct elem{
    monome valeur;
    struct elem *suivant;
}poly;

typedef poly*polynome;
	

monome creerMonome(float r, int e);
polynome creerPolynome();
polynome ajouterMonome(polynome p, monome m);
polynome supprimerMonome(polynome p, int e);
polynome additionner(polynome p1, polynome p2);
polynome copier(polynome p);
polynome multiplier(polynome p1, polynome p2);
monome mderiver (monome m,int e);
monome mderiverR(monome m, int e);
polynome pderiver(polynome p, int e);
void ecrireMR(monome m);
void ecrireMI(monome m);
void ecrirePolynomeR(polynome p);
void ecrirePolynome(polynome p);
polynome creationPolynome();
