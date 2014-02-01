all: main.c trie.c trieIterator.c
	gcc -o wordsquare main.c trie.c trieIterator.c -I. -std=gnu99 -g
