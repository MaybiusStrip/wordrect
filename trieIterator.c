#include <stdio.h>
#include <stdlib.h>
#include "trieIterator.h"

TrieIterator *makeTrieIterator(char* solution[], TrieNode *root){

  TrieIterator *iter = malloc(sizeof(TrieIterator));
  initPrefixes(iter, solution, root);
  /*goToFirstLeaf(iter);*/
  return iter;
}

/*next (node) {*/

  /*node = node.sibling*/

  /*if (node == null) {*/
    /*if (node.parent == null) return null // it's over*/
    /*node = node.parent*/
    /*return next(node)*/
  /*}*/

  /*if (node isnt leaf) {*/
    /*node = node.firstChild*/
    /*return next(node)*/
  /*}*/

  /*return node*/
/*}*/


void initPrefixes(TrieIterator *iter, char* solution[], TrieNode *root) {

  // TODO: optimize this by passing it instead of calculating it
  int lenSolutions = sizeof(solution[0]) / sizeof(solution[0][0]);
  int numSolutions = sizeof(solution) / sizeof(solution[0]);

  for (int i = 0; i < lenSolutions; i++) {

    // Don't calculate these prefixes because square has same words in both directions
    if (i < numSolutions) { break; }

    iter->prefixes[i] = root;
    for (int j = 0; j < numSolutions; j++) {
      iter->prefixes[i] = iter->prefixes[i]->edges[solution[j][i]]->node;
    }
  }

}
