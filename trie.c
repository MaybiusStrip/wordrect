/* A Trie data structure optimized to solve the world rectangle problem.
 * It aims to be fast, not beautiful ;).
 *
 * This trie makes the assumption that it will be populated once and iterated 
 * over many times, in the same order. As such, the internal data structure
 * is different during population and iteration, so new words cannot be added
 * once the trie has been populated. 
 */

#define LEN_ALPHABET 26

struct TrieNode {
  struct TrieEdge *edges[LEN_ALPHABET];
}

struct TrieEdge {
  int weight;
  struct TrieNode *node;
}

