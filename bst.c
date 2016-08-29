/* Author: Marcus Ross
 *         MR867434
 */

#include <stdlib.h>
#include "bst.h"

/* This function allocates memory for a struct treeNode, allocates memory for the treeNode's string, then returns a pointer to the treeNode. */
treeNode* newNode() {
	treeNode *node = (treeNode *) malloc(sizeof(treeNode));
	node->string = (char *) malloc(sizeof(char *));
	node->leftChild = node->rightChild = NULL;
	return node;
}