/* Vitor Nagata RA 178499 
 *	This program receives a stream of numbers followed
 * by a char '\n', and ends the sequency with a -1. The
 * program then sorts the input in decreasing order and
 * prints the non prime numbers received.
 */

#include <stdio.h>
#include <stdlib.h>

int primo(int x){
	
	int aux=0;
	
	if (x == 0 || x == 1) {	// casos base (0 e 1 nao sao primos)
		return (0);
	}
	
	for(int i=1; i <= x/2; i++){	// varredura pelos divisores (seria necessario percorrer apenas ate raiz(x)
		if (!(x%i)){	// eh divisor
			aux++;
		}
		
		if (aux > 1){
			return (0);		// nao eh primo
		}
	}
	
	if (aux == 1){		// eh primo
		return (1);
	}
	
}

int main() {

  int x = 0;
  FILE *pipe_sort;
  
  if (( pipe_sort = popen("sort -r -n", "r")) == NULL){	// Verifica se o fork foi bem sucedido
		perror("popen");
		exit(1);
	}
	
	while (1){
		fscanf(pipe_sort,"%d\n", &x	);	// ordena entrada 
		
		if (x == -1){
			break;
		} else if (!(primo(x))){
			printf("%d\n",x);		// imprime nao primos ja ordenados
		}
	
	}
	
	pclose(pipe_sort);
  
}







