#ifndef HASHTABLE_H 
#define HASHTABLE_H

#include<stdio.h>
#include<stdlib.h>

#define hash(v, M) (v % M)
#define hash2(v, M) ((42*v) % M)

typedef struct DataTable DataTable;
typedef struct HashTableAberta HashTableAberta;
typedef struct HashTableFechada HashTableFechada;
typedef struct Block Block;
typedef struct Lista Lista;

struct DataTable{
	int key;
	int value;
};


struct HashTableAberta{
	DataTable *table;
	int M;
	int col;
};

struct HashTableFechada{
	Lista *table;
	int M;
	int col;
};

struct Lista{
	Block *first;
	Block *last;
};

struct Block{
	DataTable data;
	Block *prox;
};

void InitializeAberta(HashTableAberta *h, int M);
void ImprimeAberta(HashTableAberta *h);
int getValueAberta(HashTableAberta *h, int key);
void InsertAberta(HashTableAberta *h, int key, int value);
void InitializeFechada(HashTableFechada *h, int M);
void ImprimeFechada(HashTableFechada *h);
int getValueFechada(HashTableFechada *h, int key);
void InsertFechada(HashTableFechada *h, int key, int value);

#endif