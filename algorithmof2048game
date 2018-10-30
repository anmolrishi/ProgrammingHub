var n = 4,
	M = new MatrixTransform(n);

var ai = {weights: [1, 1], depth: 1}; // depth=1 by default, but we adjust it on every prediction according to the number of free tiles

var snake= [[10,8,7,6.5],
            [.5,.7,1,3],
            [-.5,-1.5,-1.8,-2],
            [-3.8,-3.7,-3.5,-3]]
snake=snake.map(function(a){return a.map(Math.exp)})

initialize(ai)

function run(ai) {
	var p;
	while ((p = predict(ai)) != null) {
		move(p, ai);
	}
	//console.log(ai.grid , maxValue(ai.grid))
	ai.maxValue = maxValue(ai.grid)
	console.log(ai)
}

function initialize(ai) {
	ai.grid = [];
	for (var i = 0; i < n; i++) {
		ai.grid[i] = []
		for (var j = 0; j < n; j++) {
			ai.grid[i][j] = 0;
		}
	}
	rand(ai.grid)
	rand(ai.grid)
	ai.steps = 0;
}

function move(p, ai) { //0:up, 1:right, 2:down, 3:left
	var newgrid = mv(p, ai.grid);
	if (!equal(newgrid, ai.grid)) {
		//console.log(stats(newgrid, ai.grid))
		ai.grid = newgrid;
		try {
			rand(ai.grid)
			ai.steps++;
		} catch (e) {
			console.log('no room', e)
		}
	}
}

function predict(ai) {
	var free = freeCells(ai.grid);
	ai.depth = free > 7 ? 1 : (free > 4 ? 2 : 3);
	var root = {path: [],prob: 1,grid: ai.grid,children: []};
	var x = expandMove(root, ai)
	//console.log("number of leaves", x)
	//console.log("number of leaves2", countLeaves(root))
	if (!root.children.length) return null
	var values = root.children.map(expectimax);
	var mx = max(values);
	return root.children[mx[1]].path[0]

}

function countLeaves(node) {
	var x = 0;
	if (!node.children.length) return 1;
	for (var n of node.children)
		x += countLeaves(n);
	return x;
}

function expectimax(node) {
	if (!node.children.length) {
		return node.score
	} else {
		var values = node.children.map(expectimax);
		if (node.prob) { //we are at a max node
			return Math.max.apply(null, values)
		} else { // we are at a random node
			var avg = 0;
			for (var i = 0; i < values.length; i++)
				avg += node.children[i].prob * values[i]
			return avg / (values.length / 2)
		}
	}
}

function expandRandom(node, ai) {
	var x = 0;
	for (var i = 0; i < node.grid.length; i++)
		for (var j = 0; j < node.grid.length; j++)
			if (!node.grid[i][j]) {
				var grid2 = M.copy(node.grid),
					grid4 = M.copy(node.grid);
				grid2[i][j] = 2;
				grid4[i][j] = 4;
				var child2 = {grid: grid2,prob: .9,path: node.path,children: []};
				var child4 = {grid: grid4,prob: .1,path: node.path,children: []}
				node.children.push(child2)
				node.children.push(child4)
				x += expandMove(child2, ai)
				x += expandMove(child4, ai)
			}
	return x;
}

function expandMove(node, ai) { // node={grid,path,score}
	var isLeaf = true,
		x = 0;
	if (node.path.length < ai.depth) {
		for (var move of[0, 1, 2, 3]) {
			var grid = mv(move, node.grid);
			if (!equal(grid, node.grid)) {
				isLeaf = false;
				var child = {grid: grid,path: node.path.concat([move]),children: []}
				node.children.push(child)
				x += expandRandom(child, ai)
			}
		}
	}
	if (isLeaf) node.score = dot(ai.weights, stats(node.grid))
	return isLeaf ? 1 : x;
}



var cells = []
var table = document.querySelector("table");
for (var i = 0; i < n; i++) {
	var tr = document.createElement("tr");
	cells[i] = [];
	for (var j = 0; j < n; j++) {
		cells[i][j] = document.createElement("td");
		tr.appendChild(cells[i][j])
	}
	table.appendChild(tr);
}

function updateUI(ai) {
	cells.forEach(function(a, i) {
		a.forEach(function(el, j) {
			el.innerHTML = ai.grid[i][j] || ''
		})
	});
}
updateUI(ai)

function runAI() {
	var p = predict(ai);
	if (p != null && ai.running) {
		move(p, ai)
		updateUI(ai)
		requestAnimationFrame(runAI)
	}
}
runai.onclick = function() {
	if (!ai.running) {
		this.innerHTML = 'stop AI';
		ai.running = true;
		runAI();
	} else {
		this.innerHTML = 'run AI';
		ai.running = false;
	}
}


hint.onclick = function() {
	hintvalue.innerHTML = ['up', 'right', 'down', 'left'][predict(ai)]
}
document.addEventListener("keydown", function(event) {
	if (event.which in map) {
		move(map[event.which], ai)
		console.log(stats(ai.grid))
		updateUI(ai)
	}
})
var map = {
	38: 0, // Up
	39: 1, // Right
	40: 2, // Down
	37: 3, // Left
};
init.onclick = function() {
	initialize(ai);
	updateUI(ai)
}


function stats(grid, previousGrid) {

	var free = freeCells(grid);

	var c = dot2(grid, snake);

	return [c, free * free];
}

function dist2(a, b) { //squared 2D distance
	return Math.pow(a[0] - b[0], 2) + Math.pow(a[1] - b[1], 2)
}

function dot(a, b) {
	var r = 0;
	for (var i = 0; i < a.length; i++)
		r += a[i] * b[i];
	return r
}

function dot2(a, b) {
	var r = 0;
	for (var i = 0; i < a.length; i++)
		for (var j = 0; j < a[0].length; j++)
			r += a[i][j] * b[i][j]
	return r;
}

function product(a) {
	return a.reduce(function(v, x) {
		return v * x
	}, 1)
}

function maxValue(grid) {
	return Math.max.apply(null, grid.map(function(a) {
		return Math.max.apply(null, a)
	}));
}

function freeCells(grid) {
	return grid.reduce(function(v, a) {
		return v + a.reduce(function(t, x) {
			return t + (x == 0)
		}, 0)
	}, 0)
}

function max(arr) { // return [value, index] of the max
	var m = [-Infinity, null];
	for (var i = 0; i < arr.length; i++) {
		if (arr[i] > m[0]) m = [arr[i], i];
	}
	return m
}

function min(arr) { // return [value, index] of the min
	var m = [Infinity, null];
	for (var i = 0; i < arr.length; i++) {
		if (arr[i] < m[0]) m = [arr[i], i];
	}
	return m
}

function maxScore(nodes) {
	var min = {
		score: -Infinity,
		path: []
	};
	for (var node of nodes) {
		if (node.score > min.score) min = node;
	}
	return min;
}


function mv(k, grid) {
	var tgrid = M.itransform(k, grid);
	for (var i = 0; i < tgrid.length; i++) {
		var a = tgrid[i];
		for (var j = 0, jj = 0; j < a.length; j++)
			if (a[j]) a[jj++] = (j < a.length - 1 && a[j] == a[j + 1]) ? 2 * a[j++] : a[j]
		for (; jj < a.length; jj++)
			a[jj] = 0;
	}
	return M.transform(k, tgrid);
}

function rand(grid) {
	var r = Math.floor(Math.random() * freeCells(grid)),
		_r = 0;
	for (var i = 0; i < grid.length; i++) {
		for (var j = 0; j < grid.length; j++) {
			if (!grid[i][j]) {
				if (_r == r) {
					grid[i][j] = Math.random() < .9 ? 2 : 4
				}
				_r++;
			}
		}
	}
}

function equal(grid1, grid2) {
	for (var i = 0; i < grid1.length; i++)
		for (var j = 0; j < grid1.length; j++)
			if (grid1[i][j] != grid2[i][j]) return false;
	return true;
}

function conv44valid(a, b) {
	var r = 0;
	for (var i = 0; i < 4; i++)
		for (var j = 0; j < 4; j++)
			r += a[i][j] * b[3 - i][3 - j]
	return r
}

function MatrixTransform(n) {
	var g = [],
		ig = [];
	for (var i = 0; i < n; i++) {
		g[i] = [];
		ig[i] = [];
		for (var j = 0; j < n; j++) {
			g[i][j] = [[j, i],[i, n-1-j],[j, n-1-i],[i, j]]; // transformation matrix in the 4 directions g[i][j] = [up, right, down, left]
			ig[i][j] = [[j, i],[i, n-1-j],[n-1-j, i],[i, j]]; // the inverse tranformations
		}
	}
	this.transform = function(k, grid) {
		return this.transformer(k, grid, g)
	}
	this.itransform = function(k, grid) { // inverse transform
		return this.transformer(k, grid, ig)
	}
	this.transformer = function(k, grid, mat) {
		var newgrid = [];
		for (var i = 0; i < grid.length; i++) {
			newgrid[i] = [];
			for (var j = 0; j < grid.length; j++)
				newgrid[i][j] = grid[mat[i][j][k][0]][mat[i][j][k][1]];
		}
		return newgrid;
	}
	this.copy = function(grid) {
		return this.transform(3, grid)
	}
}

body {
	text-align: center
}
table, th, td {
    border: 1px solid black;
    margin: 5px auto;
}
td {
    width: 35px;
    height: 35px;
    text-align: center;
}

<table></table>
<button id=init>Init</button><button id=runai>Solve Automatically</button><button id=hint>Hint</button><span id=hintvalue></span>
