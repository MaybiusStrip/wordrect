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
  return (this.getCurrentSize() === this.getGoalSize());
};

WordSquareSolution.prototype.push = function (node) {
  this.solution.push(node);
};

WordSquareSolution.prototype.pop = function () {
  this.solution.pop();
};

WordSquareSolution.prototype.getCurrentSize = function () {
  return this.solution.length;
};

WordSquareSolution.prototype.getGoalSize = function () {
  return this.size;
};

WordSquareSolution.prototype.toString = function () {
  var s = '';
  this.solution.forEach(function(word) {
    s += word.toString() + '\n';
  });
  return s;
};


module.exports = WordSquareSolution;
