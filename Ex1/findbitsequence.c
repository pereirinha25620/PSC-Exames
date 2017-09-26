/*
 * Exercício 1 do Teste Global de 1º Época, Inverno de 2016/ 2017
 *
 * Implemente a função find_bit_sequence que pesquisa no array de 64 bits especificado pelo
 * argumento data a primeira ocorrência da sequência de bits especificada pelos argumentos
 * seq e seq_len.
 * A função devolve o índice do primeiro bit da sequência (0..63) em data ou -1 no caso da
 * sequência de bits especificada não ser encontrada.
 */

#include <stdio.h>

int find_bit_sequence(unsigned long data, unsigned int seq, size_t seq_len);

/* Test: */
int main()
{
	printf("%d\n", find_bit_sequence(0xA0, 0xA, 4)); 		/* Expected 64 - 8 = 56 */
	printf("%d\n", find_bit_sequence(0x1A0, 0x1A, 5)); 		/* Expected 64 - 9 = 55 */
	printf("%d\n", find_bit_sequence(0x1A0090, 0x1A, 5)); 	/* Expected 64 - 21 = 43 */
}


/* Function find_bit_sequence */
int find_bit_sequence(unsigned long data, unsigned int seq, size_t seq_len)
{
	unsigned long mask, bits;
	int i;

	/* Generate a mask with the length of the sequence */
	mask = 0;
	for (i = 0; i < seq_len; i++)
		mask = ((mask << 1)+1);		

	/* Search for the sequence in data from less significant bit to most (Right -> Left) */
	for (i = 63; i >= (seq_len - 1); i--, mask <<= 1, seq <<= 1) {
		/* Select the bits from data to evaluate */
		bits = data & mask;

		/* If bits XOR seq is zero we have a match. Return the leftmost index where the sequence starts */
		if (!(bits ^ seq))
			return (i - (seq_len - 1));
	}

	/* If the loop ends no match was found. Return -1 */
	return -1;
}