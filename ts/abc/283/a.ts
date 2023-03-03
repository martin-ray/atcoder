import * as fs from "fs";
import * as readline from "readline";
import { Stack } from "tstl";

function main() {
  const lines = AtCoderUtil.readAllInput();

  const [A, B] = lines[0].split(" ").map((v) => parseInt(v));

  console.log(A ** B);
}

/* ------ library ------ */
export module AtCoderUtil {
  export function readAllInput() {
    return fs.readFileSync("/dev/stdin", "utf8").trim().split("\n");
  }

  export function copeWithInteractiveInput(func: (line: string) => void) {
    const reader = readline.createInterface({
      input: process.stdin,
      output: process.stdout,
    });

    reader.on("line", func);
  }
}
export module MathUtil {
  export function isPrime(n: number) {
    assertInteger(n);
    assertPositiveNumber(n);

    if (n === 1) return false;
    if (n === 2) return true;

    if (n % 2 === 0) return false;

    for (let i = 3; i * i <= n; i += 2) {
      if (n % i === 0) return false;
    }

    return true;
  }

  export function gcd(a: number, b: number) {
    assertInteger(a);
    assertInteger(b);

    assertPositiveNumber(a);
    assertPositiveNumber(b);

    while (a >= 1 && b >= 1) {
      if (a < b) {
        b = b % a;
      } else {
        a = a % b;
      }
    }

    if (a >= 1) {
      return a;
    }
    return b;
  }

  function assertPositiveNumber(n: number) {
    if (n <= 0) {
      throw new Error(`Not a positive number: ${n}`);
    }
  }

  function assertInteger(n: number) {
    if (!Number.isInteger(n)) {
      throw new Error(`Not an integer: ${n}`);
    }
  }
}
export module BigIntUtil {
  /**
   * bigintの平方根を計算する
   * @param val
   * @returns 戻り値はbigint(整数)となる
   */
  export function sqrt(val: bigint) {
    if (val < 0n) {
      throw new Error(`Not a positive number: ${val}`);
    }

    if (val <= 1n) return val;

    if (val <= Number.MAX_SAFE_INTEGER) {
      const _v = Number.parseInt(val.toString());
      return BigInt(Math.sqrt(_v));
    }

    function _sqrt(n: bigint, x0: bigint): bigint {
      const x1 = (n / x0 + x0) >> 1n;
      if (x0 === x1 || x0 === x1 - 1n) {
        return x0;
      }
      return _sqrt(n, x1);
    }

    return _sqrt(val, 1n);
  }
}

export module GraphUtil {
  type NodeType = string | number | symbol;
  type Nodes<Node extends NodeType> = Record<Node, Node[]>;
  interface Graph<T extends NodeType> {
    readonly findNeighbours: (current: T) => T[];
  }

  /**
   * 無向グラフ
   */
  export class NDGraph<T extends NodeType> implements Graph<T> {
    readonly nodes: Nodes<T>;

    static of<T extends NodeType>(edges: T[][]) {
      const graph = {} as Nodes<T>;

      for (const e of edges) {
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
    }

    public findNeighbours(current: T): T[] {
      return this.nodes[current];
    }

    private constructor(nodes: Nodes<T>) {
      this.nodes = nodes;
    }
  }

  /**
   * 深さ優先探索
   * @param graph グラフ
   * @param start 探索開始ノード
   * @param onVisited ノード到達時に実行される関数。
   * @param breakIf trueを返すと探索を打ち切る
   */
  export function dfs<T extends NodeType>(
    graph: Graph<T>,
    start: T,
    onVisited: (node: T) => void,
    breakIf?: (node: T) => boolean
  ) {
    const visited = new Set<T>();
    const queue = new Stack<T>();

    const _dfs = () => {
      while (!queue.empty()) {
        const current = queue.top();
        queue.pop();

        visited.add(current);
        onVisited(current);
        if (breakIf && breakIf(current)) {
          break;
        }

        const neighbours = graph.findNeighbours(current);
        if (neighbours) {
          neighbours.forEach((n) => {
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
}

main();
