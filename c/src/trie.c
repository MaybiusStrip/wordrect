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


/*
 * Build a trie of a certain wordsize
 * params:
 *    filename: filename of the dictionary
 *    lenWord: length of words to be stored in trie
 * returns: 
 *     the root of the trie
 */
TrieNode *trie_constructor(char* filename, ssize_t lenWord) {

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
      trie_addWord(root, line);
    }
  }

  if (line) free(line);

  return root;
}


/*
 * Add a word to the trie (recursive)
 * params:
 *    node: the trie to add a word to
 *    word: the word to add
 */
void trie_addWord(TrieNode *node, char *word) {

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
    trie_addWord(nextNode, ++word);

  // Base case
  } else {
    node->isTerminal = 1;
  }

  return;
}

/*
 * For each node in the trie, store a sorted array of the characters
 * based on the number of children for that character
 * params:
 *   node: the trie to sort
 */
void trie_sort(TrieNode *node) {
  
  // TODO: Optimize put on stack until sorted
  char *sortedEdgeChars = malloc(LEN_ALPHABET * sizeof(char));
  int sortedWeights[LEN_ALPHABET];

  if (node->isTerminal) {
    return;
  }

  int j = 0;
  for (int i = 0; i < LEN_ALPHABET; i++) {
    if (node->edges[i] != NULL) {
      trie_sort(node->edges[i]->node);
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


