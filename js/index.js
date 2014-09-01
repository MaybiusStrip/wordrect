var trieFactory = require('./lib/trieFactory');
var WordSquareSolver = require('./lib/WordSquareSolver');


trieFactory.createTrieFromFile('./WORD.LST', 4, function (err, trie) {
  if (err) { return console.err(err); }
  solver = new WordSquareSolver(trie, 4);
  var solution = solver.solve();
  console.log(solution.toString());
});

