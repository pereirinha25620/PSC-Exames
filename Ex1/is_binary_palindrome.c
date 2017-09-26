/*
 * Exercício 1 - Teste Global de 2a Época, Inverno de 2016/2017
 * Implemente em linguagem C a função  is_binary_palindrome que determina se a sequência de
 * 32  bits passada como argumento é um palíndromo binário. Consideram-se palíndromos as 
 * sequências de símbolos cuja leitura é a mesma quando são lidos da esquerda para a direita
 * ou vice-versa. (Por exemplo, a sequência de 32  bits  0xa0000005 é um palíndromo binário
 * e a sequência  0xa000000a é um palíndromo hexadecimal, mas não é um palíndromo binário.)
 *
 *	 int is_binary_palindrome(unsigned int bits);
 */

#include <stdio.h>

/* Test cases */
# define 	CASE1	0xAA018055	/* Expected TRUE */
# define 	CASE2	0xAA011055	/* Expected FALSE */
# define 	CASE3	0xCC0A5033	/* Expected TRUE */

/* Function prototype */
int is_binary_palindrome(unsigned int bits);


/* Run tests */
int main()
{
	printf("0x%x: %s\n", CASE1, is_binary_palindrome(CASE1) ? "TRUE" : "FALSE");
	printf("0x%x: %s\n", CASE2, is_binary_palindrome(CASE2) ? "TRUE" : "FALSE");
	printf("0x%x: %s\n", CASE3, is_binary_palindrome(CASE3) ? "TRUE" : "FALSE");
}


/* 
 * Functions that checks if a given 32-bit binary sequence is a palindrome. 
 * Returns 1 if TRUE and 0 if FALSE.
 */
int is_binary_palindrome(unsigned int bits)
{
	unsigned int mh, ml;
	short i;

	/* Initialize masks for high and low parts of the sequence */
	mh = 1 << 31;
	ml = 1;

	/* Start comparing bits from the furthermost positions inwards */
	for (i = 0; i < 16; i++, mh >>= 1, ml <<= 1)
		/* If two bits are different return 0 (FALSE) */
		if (((bits & mh) >> (31 - i*2)) != (bits & ml))
			return 0;

	/* IS PALINDROME */
	return 1;
}