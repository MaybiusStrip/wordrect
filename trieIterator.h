#ifndef TRIEITER_H
#define TRIEITER_H

#include "trie.h"
#define LONGEST_WORD 10

typedef struct {
  int depth;
  TrieNode *prefixes[LONGEST_WORD];
  TrieNode *currentNode;
} TrieIterator;

TrieIterator *makeTrieIterator(char *solution[], TrieNode *root);
TrieNode *next(TrieIterator *iter);

void initPrefixes(TrieIterator *iter, char* solution[], TrieNode *root);
void goToFirstLeaf(TrieIterator *iter);

#endif
