var TrieNode = require('./TrieNode');
var fs = require('fs');
var Lazy = require('lazy');

module.exports.createTrieFromFile = function (path, wordLength, callback) {
  var trie = new TrieNode();
  var rs = fs.createReadStream('./WORD.LST');
  var lazyReader = new Lazy(rs);

  lazyReader.lines.forEach(function (line) {
    var word = line.toString();
    if (word.length === wordLength) {
      trie.addWord(line.toString());
    }
  }).join(function () {
    callback(null, trie);
  });
};

module.exports.createTrieFromList = function (words) {
  var trie = new TrieNode();
  words.forEach(trie.addWord.bind(trie));
  return trie;
};

