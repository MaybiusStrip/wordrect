function WordSquareSolver(trie, size) {
  this.trie = trie;
  this.size = size;
}

// Recursively try to fill the square, stopping at dead ends
WordSquareSolver.prototype.solve = function (solution) {

  if (solution.length === this.size) {
    return solution;
  }

  var iter = new SolutionIterator(solution);

  var nextCandidateWord = iter.next();
  while (nextCandidateWord) {
    var candidateSolution = solution.push(nextCandidateWord);
    var completeSolution = this.solve(candidateSolution);
    if (completeSolution) { return completeSolution; }
    nextCandidateWord = iter.next();
  }

  return null;

};

// Iterates over potential words that could be a valid next word in the solution.
// A solution has to:
//    Start with the prefix (letters filled in so far) in the position where the word will go
//    Form valid prefixes going the other direction for the other letters.
// For example:
//  1  2  3  4
//  M  O  A  N
//  O  N  C  E
//  A  C [x]
//  N  E [y]
// We want to fill in a word in position 3, so fill out letters [x] and [y], so:
//    "A C [x] [y]" has to be a valid word
//    "A C [x]" and "N E [y]" have to be valid prefixes
function SolutionIterator(solution) {
}
