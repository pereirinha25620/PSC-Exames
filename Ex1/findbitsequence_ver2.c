/*
 *
 * VERSÃO COM SUGESTÕES DO PROFESSOR
 *
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
	printf("%d\n", find_bit_sequence(0xA0, 0xA, 4)); 		/* Expected 4 */
	printf("%d\n", find_bit_sequence(0x1A0, 0x1A, 5)); 		/* Expected 4 */
	printf("%d\n", find_bit_sequence(0x1A0090, 0x1A, 5)); 	/* Expected 16 */
}


/* Function find_bit_sequence */
int find_bit_sequence(unsigned long data, unsigned int seq, size_t seq_len)
{
	unsigned long mask;
	short i;

	/* Generate a mask with the length of the sequence */
	mask = ~(~0 << seq_len);	

	/* Search for the sequence in data from less significant bit to most (Right -> Left) */
	for (i = 0; i < (64 - seq_len); i++, mask <<= 1, seq <<= 1)
		if ((data & mask) == seq)
			return i;

	/* If the loop ends no match was found. Return -1 */
	return -1;
}