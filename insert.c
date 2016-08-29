/* Author: Marcus Ross
 *         MR867434
 */

#include <string.h>
#include "bst.h"
#include "proto.h"

/* This function accepts a pointer to a pointer to a struct treeNode as its first argument, a string as its second argument, and inserts the string into the binary search tree given by the node, with the left-most node being first in alphabetical order and the right-most node being the last. */
void insert(treeNode **node, char *stringIn) {
	if (!*node) { /* assign a pointer to the node if nothing is already pointed to */
		*node = newNode();
	}

	if (strlen((*node)->string) == 0) { /* if node has no string */
		strcpy((*node)->string, stringIn); /* then give it the current input */
		return;
	}
	else { /* if node has a string */
		if (strcmp((*node)->string, stringIn) > 0) { /* then compare input to the node's string */
			insert(&((*node)->leftChild), stringIn); /* if node > input, insert input on left */
			return;
		}
		else {
			insert(&((*node)->rightChild), stringIn); /* otherwise, insert input on right */
			return;
		}
	}
}