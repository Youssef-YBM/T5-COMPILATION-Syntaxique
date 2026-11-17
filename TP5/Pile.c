#include "Pile.h"
#include <stdlib.h>


int empty(Pile* maPile)
{
	return (maPile == 0);
}

void empiler(Pile** maPile, char _symbole[8])
{
	Pile* NE = allocate(_symbole);
	NE->svt = *maPile;
	*maPile = NE;
}

Pile* allocate(char _symbole[8])
{
	Pile* NE = (Pile*)malloc(sizeof(Pile));
	if (!NE)
		exit(-1);
	NE->symbole = (char*)malloc(8 * sizeof(char));
	strcpy(NE->symbole, _symbole);
	NE->svt = 0;
	return NE;
}

void depiler(Pile** maPile)
{
	Pile* tmp;
	if (!empty(*maPile))
	{
		tmp = *maPile;
		*maPile = (*maPile)->svt;
		free(tmp->symbole);
		tmp->svt = 0;
		free(tmp);
	}
}


int print(Pile** pile)
{
	int taille = 0;
	char _symbole[8];
	if (*pile)
	{
		strcpy(_symbole, (*pile)->symbole);
		depiler(pile);
		taille = print(pile);
		printf("%s", _symbole);
	    strlen(_symbole);
		empiler(pile, _symbole);

		return taille + strlen(_symbole);
;	}
	return 0;
}

