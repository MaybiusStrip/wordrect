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


TrieNode *trie_constructor(char* filename, ssize_t lenWord);
void trie_addWord(TrieNode *node, char *line);
void trie_sort(TrieNode *node);

#endif
