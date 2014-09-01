var trieFactory = require('../lib/trieFactory');
var WordSquareSolver = require('../lib/WordSquareSolver');
var WordSquareSolution = require('../lib/WordSquareSolution');
require('should');

describe('WordSquareSolver', function () {

  it('should solve a simple square', function () {
      var trie = trieFactory.createTrieFromList(['aaa']);
      var solver = new WordSquareSolver(trie, 3);
      var solution = solver.solve();

      var expectedSolution = _createSolution(3, trie, ['aaa', 'aaa', 'aaa']);
      solution.toString().should.eql(expectedSolution.toString());
  });

  //it('should solve a simple square', function () {
      //var trie = trieFactory.createTrieFromList(['abc', 'bbb']);
      //var solver = new WordSquareSolver(trie, 3);
      //var solution = solver.solve();

      //var expectedSolution = _createSolution(3, trie, ['bbb', 'bbb', 'bbb']);
      //solution.toString().should.eql(expectedSolution.toString());
  //});

  function _createSolution(size, trie, words) {
    var solution = new WordSquareSolution(size, trie);
    words.forEach(function (word) {
      solution.push(trie.getNodeForPrefix(word));
    });
    return solution;
  }
});
