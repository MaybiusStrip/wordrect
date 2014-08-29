function TrieNode(character, parent) {
  this.children = {};
  this.character = character;
  this.parent = parent;
}

TrieNode.prototype.addWord = function (word) {

  var head = word[0];
  var tail = word.slice(1, word.length);

  this.children[head] = this.children[firstChar] || new TrieNode(head, this);

  if (tail.length) {
    this.children[head].addWord(tail);
  } else {
    this.isTerminal = true;
  }

};

TrieNode.prototype.getNodeForPrefix = function (prefix) {

  var head = word[0];
  var tail = word.slice(1, word.length);
  var child = this.children[head];

  if (tail.length === 0) { return child; }
  if (!child) { return null; }
  return child.getNodeForPrefix(tail);

};

TrieNode.prototype.hasPrefix = function (prefix) {
  return Boolean(this.getNodeForPrefix(prefix));
};

TrieNode.prototype.hasWord = function (word) {
  var node = this.getNodeForPrefix(prefix);
  return Boolean(node && node.isTerminal);
};

TrieNode.prototype.toString = function () {
  if (!this.character) { return ''; }
  else { return this.parent.toString() + this.character; }
};


module.exports = TrieNode;
