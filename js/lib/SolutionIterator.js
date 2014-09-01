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
function SolutionIterator(solution, trie) {
  this.currentNode = solution.getPrefixAtPosition(solution.getCurrentSize());
  this.solution = solution;
  this.trie = trie;
  this.counters = [];
  for (var i=0; i < solution.getGoalSize(); ++i) {
    this.counters.push(-1);
  }

}

SolutionIterator.prototype.next = function () {
  if (!this.currentNode) { return null; }

  while (true) {
    var depth = this.currentNode.depth;
    this.counters[depth]++;

    if (this.counters[depth] >= 26) {
      this.currentNode = this.currentNode.parent;
      if (!this.currentNode) { return null; }
      else { continue; }
    }

    var childNode = this.currentNode.children[String.fromCharCode(97 + this.counters[depth])];


    if (!childNode) { continue; }
    var horizontalPrefix = this.solution.getPrefixAtPosition(depth);
    var nextHorizontalPrefix = horizontalPrefix + childNode.character;
    if (!this.trie.hasPrefix(nextHorizontalPrefix)) { continue; }
    if (childNode.isTerminal) { return childNode; }
    else { this.currentNode = childNode; }
  }

  return null;
};

module.exports = SolutionIterator;

