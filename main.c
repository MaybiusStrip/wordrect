#include <stdio.h>
#include "trie.h"

int main(void) {
  TrieNode *node = makeTrie("WORDS.LST", 1);
  sortTrie(node);
}
