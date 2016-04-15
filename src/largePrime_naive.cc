/*
 * largePrime_naive.c
 *
 *  Created on: Apr 13, 2016
 *      Author: littlegirle
 */

#include "largePrime.h"





/**
 * Generates all the prime numbers lower than "targetSize".</br>
 * Returns one of them randomly picked
 */
mpz_t* LargePrime::getPrime_seiveErathosten(mpz_t targetSize)
{
	size_t	sizeOfMPZ		= sizeof(mpz_t);
	List	*rawInteger		= new List();
	List	*primeInteger	= new List();
	List	*tailRawInteger, *tailPrimeInteger, *nonPrimeElem;
	mpz_t i, j, nbrPrime, *res;
	gmp_randstate_t state;

	mpz_init_set_ui	(i,		2);
//TODO	mpz_init_set_ui	(max,	0);
//TODO	mpz_sqrt		(max, 	targetSize);

	tailRawInteger = rawInteger;										// Initialize the list of all integers
	while (mpz_cmp(i, targetSize) <= 0)
	{
		tailRawInteger->elem	= (mpz_t*)malloc(sizeOfMPZ);
		mpz_set(*(tailRawInteger->elem), i);
		tailRawInteger->next	= new List();
		tailRawInteger			= tailRawInteger->next;
		mpz_add_ui(i, i, 1);
	}

	tailRawInteger	= rawInteger;										// Seive execution
	tailPrimeInteger= primeInteger;
	mpz_init_set_ui	(i,	2);
	mpz_init_set_ui	(nbrPrime, 0);
//TODO	while (mpz_cmp(i, max) <= 0)
	while (mpz_cmp(i, targetSize) <= 0)
	{
		if (tailRawInteger->elem != NULL)
		{
std::cout << "\tPrime: " << mpz_get_str(NULL, 10, *tailRawInteger->elem) << "\n";
			tailPrimeInteger->elem	= (mpz_t*)malloc(sizeOfMPZ);		//		Mark the element as prime
			mpz_set(*(tailPrimeInteger->elem), i);
			tailPrimeInteger->next	= new List();
			tailPrimeInteger		= tailPrimeInteger->next;
			mpz_add_ui(nbrPrime, nbrPrime, 1);

			mpz_init_set(j, i);
			mpz_pow_ui(j, j, 2);
			while (mpz_cmp(j, targetSize) <= 0)
			{
				nonPrimeElem = tailRawInteger->findElemByValue(j);
				if ((nonPrimeElem != NULL) && (nonPrimeElem->elem != NULL))
				{
					free(nonPrimeElem->elem);
					nonPrimeElem->elem = NULL;
				}
				mpz_add(j, j, i);
			}
		}
		tailRawInteger = tailRawInteger->next;
		mpz_add_ui(i, i, 1);
	}

	gmp_randinit_default (state);										// Pick an element randomly among the primes
	mpz_urandomm (i, state, nbrPrime);
	res = (mpz_t*)malloc(sizeOfMPZ);
	res = primeInteger->findElemByIndex(i)->elem;

	delete (rawInteger);												// Free all the used data
	delete (primeInteger);

	return res;
}
