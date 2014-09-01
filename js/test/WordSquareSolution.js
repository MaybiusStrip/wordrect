var WordSquareSolution = require('../lib/WordSquareSolution');
var TrieNode = require('../lib/TrieNode');
var should = require('should');

describe('WordSquareSolution', function () {

  describe('.getPrefixAtPosition', function () {

    it('should get the prefix at the given index', function () {

      var trie = new TrieNode();
      trie.addWord('abc');
      trie.addWord('ccc');

      var abcNode = trie.getNodeForPrefix('abc');
      var cccNode = trie.getNodeForPrefix('ccc');

      var solution = new WordSquareSolution(3, trie);
      solution.push(abcNode);
      solution.push(abcNode);
      solution.push(abcNode);

      var resultNode = solution.getPrefixAtPosition(2);
      should.exist(resultNode);
      resultNode.should.equal(cccNode);
    });

  });
});
