/* Author: Marcus Ross
 *         MR867434
 */

#include <stdio.h>
#include <stdlib.h>
#include "const.h"
#include "bst.h"

/* This function takes a pointer to a struct treeNode as its first argument, a string as its second argument, and outputs to the file named by the string various statistics of the binary search tree given by the treeNode. */
int getTreeStats(treeNode *rootNode, char *fOutName) {
	FILE *fOut = fopen(fOutName, "w"); // open second arg for writing

	if (fOut == NULL) { /* if failed to open output file */
		perror("Failed to open output file");
		exit(-1); /* then kill program */
	}

	int strings = 0, height = 0, leaves = 0, heightLeft = 0, stringsLeft = 0, heightRight = 0, stringsRight = 0; /* all vars are initialised to zero to accomodate the following recursive functions */

	strings = getQtyStrings(rootNode, strings);
	height = getHeight(rootNode, height);
	leaves = getQtyLeaves(rootNode, leaves);
	heightLeft = getHeightLeft(rootNode, heightLeft);
	stringsLeft = getQtyStringsLeft(rootNode, stringsLeft);
	heightRight = getHeightRight(rootNode, heightRight);
	stringsRight = getQtyStringsRight(rootNode, stringsRight);

	fprintf(fOut, "%-33s %2d\n", "Strings in input file:", strings);
	fprintf(fOut, "%-33s %2d\n", "Height of binary search tree:", height);
	fprintf(fOut, "%-33s %2d\n", "Leaves in binary search tree:", leaves);
	fprintf(fOut, "%-33s %2d\n", "Height of left subtree of root:", heightLeft);
	fprintf(fOut, "%-33s %2d\n", "Strings in left subtree of root:", stringsLeft);
	fprintf(fOut, "%-33s %2d\n", "Height of right subtree of root:", heightRight);
	fprintf(fOut, "%-33s %2d\n", "Strings in right subtree of root:", stringsRight);

	fclose(fOut);
}

/* This function takes a struct treeNode as its first argument, an int initialised to zero as its second argument, recursively counts the quantity of strings in the binary search tree given by the treeNode, then returns the quantity. */
int getQtyStrings(treeNode *node, int qty) {
	if (node->string) { /* if the node has a string */
		qty++; /* increment the counter */
	}

	if (node->leftChild) { /* if left child exists */
		qty = getQtyStrings(node->leftChild, qty); /* get the # of strings in left subtree */
	}

	if (node->rightChild) { /* if right child exists */
		qty = getQtyStrings(node->rightChild, qty); /* get the # of strings in right subtree */
	}

	return qty;
}

/* This function takes a struct treeNode as its first argument, an int initialised to zero as its second argument, recursively determines the height of the binary search tree given by the treeNode by counting the maximum number of links between the root and a leaf, then returns the height. */
int getHeight(treeNode *node, int height) {
	int leftHeight = 0, rightHeight = 0;

	if (node->leftChild) { /* if left child exists */
		leftHeight = 1 + getHeight(node->leftChild, leftHeight); /* get height of left subtree */
	}

	if (node->rightChild) { /* if right child exists */
		rightHeight = 1 + getHeight(node->rightChild, rightHeight); /* get height of right subtree */
	}

	height = leftHeight > rightHeight ? leftHeight : rightHeight; /* return the highest of left and right heights */

	return height;
}

/* This function takes a struct treeNode as its first argument, an int initialised to zero as its second argument, recursively counts the quantity of leaves in the binary search tree given by the treeNode, then returns the quantity. */
int getQtyLeaves(treeNode *node, int qty) {
	if (!node->leftChild && !node->rightChild) { /* if node has no children */
		return ++ qty; /* then the node is a leaf, so increment counter */
	}

	if (node->leftChild) { /* if left child exists */
		qty = getQtyLeaves(node->leftChild, qty); /* get # of leaves under it */
	}

	if (node->rightChild) { /* if right child exists */
		qty = getQtyLeaves(node->rightChild, qty); /* get # of leaves under it */
	}

	return qty;
}

/* This function takes a struct treeNode as its first argument, an int initialised to zero as its second argument, recursively determines the height of the binary search tree given by the left child of the treeNode by counting the maximum number of links between the root and a leaf, then returns the height. */
int getHeightLeft(treeNode *node, int height) {
	if (node->leftChild) { /* if left child exists */
		height = getHeight(node->leftChild, height); /* get the height of its subtree */
	}

	return height;
}

/* This function takes a struct treeNode as its first argument, an int initialised to zero as its second argument, recursively counts the quantity of strings in the binary search tree given by the left child of the treeNode, then returns the quantity. */
int getQtyStringsLeft(treeNode *node, int qty) {
	if (node->leftChild) { /* if left child exists */
		qty = getQtyStrings(node->leftChild, qty); /* get the # of strings strings under it */
	}

	return qty;
}

/* This function takes a struct treeNode as its first argument, an int initialised to zero as its second argument, recursively determines the height of the binary search tree given by the right child of the treeNode by counting the maximum number of links between the root and a leaf, then returns the height. */
int getHeightRight(treeNode *node, int height) {
	if (node->rightChild) { /* if right child exists */
		height = getHeight(node->rightChild, height); /* get the height of its subtree */
	}

	return height;
}

/* This function takes a struct treeNode as its first argument, an int initialised to zero as its second argument, recursively counts the quantity of strings in the binary search tree given by the right child of the treeNode, then returns the quantity. */
int getQtyStringsRight(treeNode *node, int qty) {
	if (node->rightChild) { /* if right child exists */
		qty = getQtyStrings(node->rightChild, qty); /* get the # of strings under it */
	}

	return qty;
}