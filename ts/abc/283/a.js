"use strict";
exports.__esModule = true;
exports.GraphUtil = exports.BigIntUtil = exports.MathUtil = exports.AtCoderUtil = void 0;
var fs = require("fs");
var readline = require("readline");
var tstl_1 = require("tstl");
function main() {
    var lines = AtCoderUtil.readAllInput();
    var _a = lines[0].split(" ").map(function (v) { return parseInt(v); }), A = _a[0], B = _a[1];
    console.log(Math.pow(A, B));
}
/* ------ library ------ */
var AtCoderUtil;
(function (AtCoderUtil) {
    function readAllInput() {
        return fs.readFileSync("/dev/stdin", "utf8").trim().split("\n");
    }
    AtCoderUtil.readAllInput = readAllInput;
    function copeWithInteractiveInput(func) {
        var reader = readline.createInterface({
            input: process.stdin,
            output: process.stdout
        });
        reader.on("line", func);
    }
    AtCoderUtil.copeWithInteractiveInput = copeWithInteractiveInput;
})(AtCoderUtil = exports.AtCoderUtil || (exports.AtCoderUtil = {}));
var MathUtil;
(function (MathUtil) {
    function isPrime(n) {
        assertInteger(n);
        assertPositiveNumber(n);
        if (n === 1)
            return false;
        if (n === 2)
            return true;
        if (n % 2 === 0)
            return false;
        for (var i = 3; i * i <= n; i += 2) {
            if (n % i === 0)
                return false;
        }
        return true;
    }
    MathUtil.isPrime = isPrime;
    function gcd(a, b) {
        assertInteger(a);
        assertInteger(b);
        assertPositiveNumber(a);
        assertPositiveNumber(b);
        while (a >= 1 && b >= 1) {
            if (a < b) {
                b = b % a;
            }
            else {
                a = a % b;
            }
        }
        if (a >= 1) {
            return a;
        }
        return b;
    }
    MathUtil.gcd = gcd;
    function assertPositiveNumber(n) {
        if (n <= 0) {
            throw new Error("Not a positive number: ".concat(n));
        }
    }
    function assertInteger(n) {
        if (!Number.isInteger(n)) {
            throw new Error("Not an integer: ".concat(n));
        }
    }
})(MathUtil = exports.MathUtil || (exports.MathUtil = {}));
var BigIntUtil;
(function (BigIntUtil) {
    /**
     * bigintの平方根を計算する
     * @param val
     * @returns 戻り値はbigint(整数)となる
     */
    function sqrt(val) {
        if (val < 0n) {
            throw new Error("Not a positive number: ".concat(val));
        }
        if (val <= 1n)
            return val;
        if (val <= Number.MAX_SAFE_INTEGER) {
            var _v = Number.parseInt(val.toString());
            return BigInt(Math.sqrt(_v));
        }
        function _sqrt(n, x0) {
            var x1 = (n / x0 + x0) >> 1n;
            if (x0 === x1 || x0 === x1 - 1n) {
                return x0;
            }
            return _sqrt(n, x1);
        }
        return _sqrt(val, 1n);
    }
    BigIntUtil.sqrt = sqrt;
})(BigIntUtil = exports.BigIntUtil || (exports.BigIntUtil = {}));
var GraphUtil;
(function (GraphUtil) {
    /**
     * 無向グラフ
     */
    var NDGraph = /** @class */ (function () {
        function NDGraph(nodes) {
            this.nodes = nodes;
        }
        NDGraph.of = function (edges) {
            var graph = {};
            for (var _i = 0, edges_1 = edges; _i < edges_1.length; _i++) {
                var e = edges_1[_i];
                if (!graph[e[0]]) {
                    graph[e[0]] = [];
                }
                if (!graph[e[1]]) {
                    graph[e[1]] = [];
                }
                graph[e[0]].push(e[1]);
                graph[e[1]].push(e[0]);
            }
            return new NDGraph(graph);
        };
        NDGraph.prototype.findNeighbours = function (current) {
            return this.nodes[current];
        };
        return NDGraph;
    }());
    GraphUtil.NDGraph = NDGraph;
    /**
     * 深さ優先探索
     * @param graph グラフ
     * @param start 探索開始ノード
     * @param onVisited ノード到達時に実行される関数。
     * @param breakIf trueを返すと探索を打ち切る
     */
    function dfs(graph, start, onVisited, breakIf) {
        var visited = new Set();
        var queue = new tstl_1.Stack();
        var _dfs = function () {
            while (!queue.empty()) {
                var current = queue.top();
                queue.pop();
                visited.add(current);
                onVisited(current);
                if (breakIf && breakIf(current)) {
                    break;
                }
                var neighbours = graph.findNeighbours(current);
                if (neighbours) {
                    neighbours.forEach(function (n) {
                        if (!visited.has(n)) {
                            queue.push(n);
                        }
                    });
                }
            }
        };
        queue.push(start);
        _dfs();
    }
    GraphUtil.dfs = dfs;
})(GraphUtil = exports.GraphUtil || (exports.GraphUtil = {}));
main();
