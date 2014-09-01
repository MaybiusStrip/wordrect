var TrieNode = require('./lib/TrieNode');
var fs = require('fs');
var Lazy = require('lazy');

_createTrie('./WORD.LST', 4, function (err, trie) {
  if (err) { return console.err(err); }
  console.log(trie.hasWord('zyme'));
});

