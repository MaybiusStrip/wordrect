#include <stdio.h>
#include "trie.h"
#include "trieIterator.h"


const int wordLength = 5;

int main(void) {
  TrieNode *node = makeTrie("wordlists/WORD.LST", wordLength);
  sortTrie(node);
  printf("%s\n", node->sortedEdgesByWeight);
  /*solveSquare(node, 0, char[wordLength + 1][wordLength])*/
}

/*solveSquare(TrieNode *wordTrie, int index, char *solution[]) {*/
  /*if (index == wordLength - 1) {*/
    /*printf("done");*/
    /*return solution;*/
  /*}*/

  /*TrieIterator *iter = makeTrieIterator(solution, wordTrie);*/
  /*char* word = iter->next();*/
  /*index++;*/

  /*while (word) {*/
    /*solution[index - 1] = word;*/
    /*char *potentialSolution[wordLength] = solveSquare;*/
    /*if (solveSquare != null) {*/
      /*return potentialSolution;*/
    /*} else {*/
      /*solution = iter->next();*/
    /*}*/
  /*}*/

  /*return NULL;*/
/*}*/


