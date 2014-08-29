var TrieNode = require('TrieNode');
var fs = require('fs');
var Lazy = require('lazy');

_createTrie('./WORD.LST', 4, function (err, trie) {
  if (err) { return console.err(err); }
  console.log(trie.hasWord('zyme'));
});

function _createTrie(path, wordLength, callback) {
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
}
