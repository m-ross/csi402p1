/* Author: Marcus Ross
 * Description: This program reads a text file, creates a binary search tree based on its content, then outputs a text file containing various metrics of the binary search tree. The program's first argument is to be the name of a text file containing only strings no longer than 15 characters. The second argument is to be the name of a text file to be created and which will be overwritten if it exists.
*/

#include <stdio.h>
#include "const.h"
#include "bst.h"
#include "proto.h"

int main(int argc, char **argv) {
	if (argc != 3) { /* kill program if two arguments are not given */
		printf("Two filename arguments are required.\n");
		return -1;
	}

	char stringIn[MAX_LEN + 1]; // container for each string from input file
	treeNode *rootNode = newNode();
	FILE *fIn = fopen(argv[1], "r"); // open first arg as file for reading

	if (fIn == NULL) { /* kill program if fopen wasn't successful */
		perror("Failed to open input file");
		return -1;
	}

	while (fscanf(fIn, "%s", stringIn) == 1) { /* if reading one string from file is successful */
		insert(&rootNode, stringIn); /* insert the string into the tree */
	}

	getTreeStats(rootNode, argv[2]);

	fclose(fIn);

	return 0;
}
