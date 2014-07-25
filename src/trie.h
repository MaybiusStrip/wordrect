#ifndef TRIE_H
#define TRIE_H

#define LEN_ALPHABET 26

struct trieEdge;

typedef struct {
  int isTerminal;
  char *sortedEdgesByWeight;
  char *sortedEdgesForTraversal; /* For O(n) traversal */
  struct trieEdge *parent;
  struct trieEdge *edges[LEN_ALPHABET]; /* For 0(1) access */
} TrieNode;

typedef struct trieEdge {
  char c;
  int numLeaves;
  TrieNode *node;
} TrieEdge;


TrieNode *makeTrie(char* filename, ssize_t lenWord);
void addWordToTrie(TrieNode *node, char *line);
void sortTrie(TrieNode *node);
void quickSort(int weights[], char characters[], int left, int right);
int partition(int weights[], char characters[], int left, int right);
void swap(int iarray[], char carray[], int i, int j);

#endif
