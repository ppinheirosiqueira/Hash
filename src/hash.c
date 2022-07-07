#include "hash.h"

void InitializeAberta(HashTableAberta *h, int M){
	h->table = (DataTable*) malloc (M * sizeof(DataTable));

	for(int i=0; i<M; i++){
		h->table[i].key = -1;
		h->table[i].value = 0;
	}

	h->M = M;
	h->col = 0;
}

void InitializeFechada(HashTableFechada *h, int M){
	h->table = (Lista*) malloc (M * sizeof(Lista));

	for(int i=0; i<M; i++){
		h->table[i].first = (Block*) malloc (sizeof(Block));
		h->table[i].last  = h->table[i].first;
		h->table[i].first->prox = NULL;
	}

	h->M = M;
	h->col = 0;
}


void ImprimeAberta(HashTableAberta *h){
	for(int i=0; i<h->M; i++)
		printf("KEY:%d - VALUE:%d\n", h->table[i].key, h->table[i].value);
}

void ImprimeFechada(HashTableFechada *h){
	Block *Aux;
	for(int i=0; i<h->M; i++){
		printf("Indice: %d - Lista: ", i);
		Aux = h->table[i].first;
		if (Aux->prox == NULL){
			printf("Vazia\n");
		}
		else{
			Aux = Aux->prox;
			do{
				printf("KEY: %d - ", Aux->data.key);
				Aux = Aux->prox;
			}while(Aux != NULL);
			printf("\n");
		}
	}
}


int getValueAberta(HashTableAberta *h, int key){
	int idx = hash(key, h->M);
	int aux = 1;
	
	if(h->table[idx].key != key){
		idx = hash2(key, h->M);
		aux += 1;
		while (h->table[idx].key != key){
			idx = (idx + 1) % h->M;
			if (aux == h->M){
				return -1;
			}
		}
	}
	return h->table[idx].value;
}

int getValueFechada(HashTableFechada *h, int key){
	int idx = hash(key, h->M);
	Block *Aux;

	if(h->table[idx].first == h->table[idx].last)
		return -1;

	Aux = h->table[idx].first->prox;

	do{
		if(Aux->data.key == key){
			return Aux->data.value;
		}
		Aux = Aux->prox;
	}while (Aux != NULL);

	return -1;
}

void InsertAberta(HashTableAberta *h, int key, int value){
	int idx = hash(key, h->M);
	int aux = 1;

	if(h->table[idx].key != -1){
		h->col += 1;
		idx = hash2(key, h->M);
		aux += 1;
		while (h->table[idx].key != -1){
			h->col += 1;
			idx = (idx + 1) % h->M;
			aux += 1;
			if (aux == h->M){
				printf("OPENED HASH IS FULL!\n");
				return;
			}
		}	
	}
	
	h->table[idx].key = key;
	h->table[idx].value = value;
}

void InsertFechada(HashTableFechada *h, int key, int value){
	int idx = hash(key, h->M);
	
	if(	h->table[idx].first != h->table[idx].last){
		h->col += 1;
	}

	h->table[idx].last->prox = (Block*) malloc (sizeof(Block));
	h->table[idx].last = h->table[idx].last->prox;
	h->table[idx].last->data.key = key;
	h->table[idx].last->data.value = value;
	h->table[idx].last->prox = NULL;
}