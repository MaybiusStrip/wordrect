#include <stdio.h>
#include "trie.h"

int main(void) {
  TrieNode *node = makeTrie("WORDS.LST", 5);
  sortTrie(node);
}
