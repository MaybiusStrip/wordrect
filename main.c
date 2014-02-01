#include <stdio.h>
#include "trie.h"
#include "trieIterator.h"

const int wordLength = 5;

int main(void) {
  TrieNode *node = makeTrie("WORD.LST", wordLength);
  sortTrie(node);
  printf("%s\n", node->sortedEdgesByWeight);
  /*solveSquare(node, 0, char[wordLength + 1][wordLength])*/
}

/*solveSquare(TrieNode *node, int index, char *result) {*/
  /*if (index == wordsquare - 1) {*/
    /*printf("done");*/
  /*}*/

  /*firstWord = */

  
/*}*/


