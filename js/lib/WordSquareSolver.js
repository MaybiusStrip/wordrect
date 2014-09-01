var WordSquareSolution = require('./WordSquareSolution');
var SolutionIterator = require('./SolutionIterator');

function WordSquareSolver(trie, size) {
  this.size = size;
  this.trie = trie;
}

// Recursively try to fill the square, stopping at dead ends
// Returns the most filled in partial square if it can't find
// a complete solution.
WordSquareSolver.prototype.solve = function (solution) {

  if (!solution) {
    solution = new WordSquareSolution(this.size, this.trie);
  }

  if (solution.isComplete()) {
    return solution;
  }

  var iter = new SolutionIterator(solution, this.trie);

  var nextCandidateWord = iter.next();
  while (nextCandidateWord) {

    solution.push(nextCandidateWord);
    solution = this.solve(solution);
    if (solution.isComplete()) { return solution; }

    solution.pop();
    nextCandidateWord = iter.next();
  }

  return solution;

};

module.exports = WordSquareSolver;

