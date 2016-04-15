#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gmp.h>
#include "largePrime.h"






int Miller_Rabin(mpz_t n, float proba)
{
	return -1;
}


void RSA_keygen(int b, mpz_t e, mpz_t d, mpz_t n)
{

}

int main()
{
	mpz_t size, *prime;

	mpz_init_set_ui(size, 100);
	prime = LargePrime::getPrime_seiveErathosten(size);
std::cout << "\nResult = " << mpz_get_str(NULL, 10, *prime) <<"\n";

	free(prime);
	return 0;
}
