var _ = require('lodash');

function WordSquareSolution(size, trie) {
  this.solution = [];
  this.size = size;
  this.trie = trie;
}

WordSquareSolution.prototype.getPrefixAtPosition = function (position) {
  // TODO: not optimized
  var prefixString = '';
  _.each(this.solution, function (trieNode) {
    prefixString += trieNode.toString()[position];
  });
  return this.trie.getNodeForPrefix(prefixString);
};


WordSquareSolution.prototype.isComplete = function () {
  return (this.solution.length === this.size);
};

WordSquareSolution.prototype.push = function (node) {
  this.solution.push(node);
};

WordSquareSolution.prototype.getCurrentSize = function () {
  return this.solution.length;
};

WordSquareSolution.prototype.getGoalSize = function () {
  return this.size;
};


module.exports = WordSquareSolution;
