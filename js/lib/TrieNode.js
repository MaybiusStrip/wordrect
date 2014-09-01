function TrieNode(character, parent, depth) {
  this.children = {};
  this.character = character;
  this.parent = parent;
  this.depth = depth || 0;
}

TrieNode.prototype.addWord = function (word) {

  if (!word.length) {
    this.isTerminal = true;
    return;
  }

  var head = word[0];
  var tail = word.slice(1, word.length);

  this.children[head] = this.children[head] || new TrieNode(head, this, this.depth + 1);

  this.children[head].addWord(tail);

};

TrieNode.prototype.getNodeForPrefix = function (prefix) {

  var head = prefix[0];
  var tail = prefix.slice(1, prefix.length);
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
