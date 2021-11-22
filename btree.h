


#ifndef __BTREE_H
#define __BTREE_H

typedef struct _btree_node {
	
	unsigned long value;
	int height;
	int weight;
	
	struct _btree_node * left;
	struct _btree_node * right;
	
} btree_t;

void insert_btree(btree_t ** root, unsigned long value);
#pragma acc routine(insert_btree) seq
char contains_btree(btree_t * root, unsigned long value);
#pragma acc routine(contains_btree) seq

void free_btree(btree_t * root);
#pragma acc routine(free_btree) seq

int height_btree(btree_t * root);
#pragma acc routine(height_btree) seq
int weight_btree(btree_t * root);
#pragma acc routine(weight_btree) seq

void to_array_btree(btree_t * root, unsigned long * data);
#pragma acc routine(to_array_btree) seq

#endif