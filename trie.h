#ifndef TRIE_H
#define TRIE_H

#define LEN_ALPHABET 26

struct trieEdge;

typedef struct {
  int isTerminal;
  char *sortedEdges; /* For O(n) traversal */
  struct trieEdge *edges[LEN_ALPHABET]; /* For 0(1) access */
} TrieNode;

typedef struct trieEdge {
  char c;
  int numLeaves;
  TrieNode *node;
} TrieEdge;


TrieNode *makeTrie(char* filename, ssize_t lenWord);
void addWord(TrieNode *node, char *line);


#endif
