#include "hash.h"
#include <time.h>

int primo(int n);

int main(){
	HashTableAberta hA;
	HashTableFechada hF;
	int tam, M, *vet, r; //NColFec = 0, NColAbe = 0;

	printf("Qual o tamanho que você deseja de entrada?\n");
	scanf("%d", &tam);
	while(tam < 0){
		printf("O tamanho precisa ser maior que 0\n");
		scanf("%d", &tam);
	}

	vet =  (int*) malloc (tam * sizeof(int));

	M = 2*tam + 1;
	while(primo(M) == 0){
		M++;
	}

	srand(time(NULL));
	printf("\n");

	printf("Tamanho da Hash: %d\n", M);

	InitializeAberta(&hA, M);
	InitializeFechada(&hF, M);
	printf("Hash Aberta Vazia:\n");
	ImprimeAberta(&hA);
	printf("\n\n");
	printf("Hash Fechada Vazia:\n");
	ImprimeFechada(&hF);
	printf("\n\n");

	for(int i = 0; i < tam; i++){
		vet[i] = rand()%(tam*M);
		InsertAberta(&hA, vet[i], i+1);
		InsertFechada(&hF, vet[i], i+1);
	}

	printf("Hash Aberta:\n");
	ImprimeAberta(&hA);
	printf("\n\n");
	printf("Hash Fechada:\n");
	ImprimeFechada(&hF);
	printf("\n\n");

	printf("O número de colisões da aberta foi igual a: %d\n", hA.col);
	printf("O número de colisões da fechada foi igual a: %d\n", hF.col);

	printf("Teste de busca de um valor qualquer para testar se a busca funciona.\n");
	r = rand()%tam;
	printf("Buscando vet[%d] = Key: %d\n", r, vet[r]);
	printf("Pela Hash Aberta: %d\n", getValueAberta(&hA,vet[r]));
	printf("Pela Hash Fechada: %d\n", getValueFechada(&hF,vet[r]));
	return 0;	
}

int primo(int n){ // Retorna 0 se não for primo, retorna 1 se for primo
	for(int i=2;i<=n/2;i++){
		if(n%i==0)
			return 0;
	}
	return 1;
}