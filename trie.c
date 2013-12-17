/* A Trie data structure optimized to solve the world rectangle problem.
 * Speed is favored over memory or elegance.
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


/* Create a trie given a file and a word length */
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
      addWord(root, line);
    }
  }

  if (line) free(line);

  return root;
}


void addWord(TrieNode *node, char *word) {

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
    addWord(nextNode, ++word);

  // Base case
  } else {
    node->isTerminal = 1;
  }

  return;
}
