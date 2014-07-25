/* A Trie data structure optimized to solve the world rectangle problem.
 *
 * This trie makes the assumption that it will be populated once and iterated 
 * over many times, in the same order. As such, the trie is sorted once after 
 * population, so new words cannot be added once the trie has been populated. 
 *
 * This trie only supports words of the same length.
 */

#include <stdio.h>
#include <stdlib.h>
#include "trie.h"
#include "sort.h"


TrieNode *makeTrie(char* filename, ssize_t lenWord) {

  TrieNode *root = malloc(sizeof(TrieNode));
  root->isTerminal = 0;
  
  FILE *fp;
  char *line = NULL;
  size_t lenAlloc = 0;
  ssize_t lenLine;

  fp = fopen(filename, "r");
  if (fp == NULL) exit(EXIT_FAILURE);

  while ((lenLine = getline(&line, &lenAlloc, fp)) != -1) {
    if (lenLine - 1 == lenWord) {
      addWordToTrie(root, line);
    }
  }

  if (line) free(line);

  return root;
}


void addWordToTrie(TrieNode *node, char *word) {

  // Recursive step
  if (*word && *word != '\0' && *word != '\n') {
    int charIndex = *word - 97;

    // Create edge for this character if it doesn't exist
    if (node->edges[charIndex] == NULL) {
      TrieEdge *edge = malloc(sizeof(TrieEdge));
      edge->c = *word;
      edge->numLeaves = 0;
      edge->node = malloc(sizeof(TrieNode));

      node->edges[charIndex] = edge;
    } 

    // Follow edge and repeat for rest of the word
    node->edges[charIndex]->numLeaves++;
    TrieNode *nextNode = node->edges[charIndex]->node;
    addWordToTrie(nextNode, ++word);

  // Base case
  } else {
    node->isTerminal = 1;
  }

  return;
}

// Traverse the tree sorting sorting children by their weights in
void sortTrie(TrieNode *node) {
  
  // TODO: Optimize put on stack until sorted
  char *sortedEdgeChars = malloc(LEN_ALPHABET * sizeof(char));
  int sortedWeights[LEN_ALPHABET];

  if (node->isTerminal) {
    return;
  }

  int j = 0;
  for (int i = 0; i < LEN_ALPHABET; i++) {
    if (node->edges[i] != NULL) {
      sortTrie(node->edges[i]->node);
      sortedEdgeChars[j] = node->edges[i]->c;
      sortedWeights[j] = node->edges[i]->numLeaves;
      j++;
    }
  }

  sortCharactersByWeight(sortedWeights, sortedEdgeChars, 0, j - 1);
  sortedEdgeChars[j] = '\0';
  sortedEdgeChars = realloc(sortedEdgeChars, (j + 1) * sizeof(char));
  node->sortedEdgesByWeight = sortedEdgeChars;
}


