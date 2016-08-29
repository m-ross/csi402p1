/* Author: Marcus Ross
 *         MR867434
 */

/* This struct corresponds to each node of a binary search tree, including pointers to the nodes immediately under it and each string from the input file. */
typedef struct treeNode {
  char *string;
  struct treeNode *leftChild, *rightChild;
} treeNode;