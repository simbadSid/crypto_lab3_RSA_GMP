#ifndef LARGE_PRIME
#define LARGE_PRIME


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>
#include <iostream>
#include "list.h"



class LargePrime
{
// -----------------------------
// Local methods
// -----------------------------
	public:
		static mpz_t*	string_to_int	(char* s, mpz_t n);
		static char*	int_to_string	(mpz_t* vec, mpz_t n);

		/**
		 * Generates all the prime numbers lower than "targetSize".</br>
		 * Returns one of them randomly picked
		 */
		static mpz_t *getPrime_seiveErathosten	(mpz_t targetSize, List *outputPrime);
		static mpz_t *getPrime_trialDivision	(mpz_t targetSize, List *outputPrime);
};


#endif
