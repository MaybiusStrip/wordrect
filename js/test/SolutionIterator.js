var TrieNode = require('../lib/TrieNode');
var trieFactory = require('../lib/trieFactory');
var SolutionIterator = require('../lib/SolutionIterator');
var WordSquareSolution = require('../lib/WordSquareSolution');
require('should');

describe('SolutionIterator', function () {

  describe('.next()', function () {

    it('should be null if there is no next word that starts with the right letter', function () {
      var trie = trieFactory.createTrieFromList(['abc']);
      var solution = _createSolution(3, trie, ['abc']);
      var solutionIterator = new SolutionIterator(solution, trie);

      (solutionIterator.next() === null).should.be.true;
    });

    it('should be null if there is a word that starts with the right letter but no valid prefixes can be formed', function () {
      var trie = trieFactory.createTrieFromList(['abc', 'bcd']);
      var solution = _createSolution(3, trie, ['abc']);
      var solutionIterator = new SolutionIterator(solution, trie);

      (solutionIterator.next() === null).should.be.true;
    });

    it('should return a valid solution and then null if there is only one valid solution', function () {
      var trie = trieFactory.createTrieFromList(['abc', 'bcd', 'cde']);
      var solution = _createSolution(3, trie, ['abc']);
      var solutionIterator = new SolutionIterator(solution, trie);

      solutionIterator.next().toString().should.equal('bcd');
    });

  });


  function _createSolution(size, trie, words) {
    var solution = new WordSquareSolution(size, trie);
    words.forEach(function (word) {
      solution.push(trie.getNodeForPrefix('abc'));
    });
    return solution;
  }

});
