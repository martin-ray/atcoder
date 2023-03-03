// vector (use Array<number> instead)

/* 
const a: Array<number> = []
vector.pushback(n) == a.push(n);
*/



// stack
class stack<T> {
    
    a :Array<T>;

    constructor(){
        this.a = Array<T>();
    };

    public push(n: T){
        this.a.push(n);
    }

    public pop(n: T){
        this.a.pop();
    };

    public peep(): T{
        return this.a[this.a.length-1];
    };


}

// dequeue
export default class Deque<T> {
    private count: number;
    private lowestCount: number;
    private items: any;
  
    constructor() {
      this.count = 0;
      this.lowestCount = 0;
      this.items = {};
    }
  
    addFront(element: T) {
      if (this.isEmpty()) {
        this.addBack(element);
      } else if (this.lowestCount > 0) {
        this.lowestCount--;
        this.items[this.lowestCount] = element;
      } else {
        for (let i = this.count; i > 0; i--) {
          this.items[i] = this.items[i - 1];
        }
        this.count++;
        this.items[0] = element;
      }
    }
  
    addBack(element: T) {
      this.items[this.count] = element;
      this.count++;
    }
  
    removeFront() {
      if (this.isEmpty()) {
        return undefined;
      }
      const result = this.items[this.lowestCount];
      delete this.items[this.lowestCount];
      this.lowestCount++;
      return result;
    }
  
    removeBack() {
      if (this.isEmpty()) {
        return undefined;
      }
      this.count--;
      const result = this.items[this.count];
      delete this.items[this.count];
      return result;
    }
  
    peekFront() {
      if (this.isEmpty()) {
        return undefined;
      }
      return this.items[this.lowestCount];
    }
  
    peekBack() {
      if (this.isEmpty()) {
        return undefined;
      }
      return this.items[this.count - 1];
    }
  
    isEmpty() {
      return this.size() === 0;
    }
  
    clear() {
      this.items = {};
      this.count = 0;
      this.lowestCount = 0;
    }
  
    size() {
      return this.count - this.lowestCount;
    }
  
    toString() {
      if (this.isEmpty()) {
        return '';
      }
      let objString = `${this.items[this.lowestCount]}`;
      for (let i = this.lowestCount + 1; i < this.count; i++) {
        objString = `${objString},${this.items[i]}`;
      }
      return objString;
    }
}

// priority_queue

// set(use default one like this)

/*
const fruits = new Set(["apple", "orange", "banana"]);
console.log(fruits);

const fruits = new Set<string>();
fruits.add("apple");
fruits.add("apple");
console.log(fruits);

const numbers = new Set([1, 2, 3]);
numbers.delete(3);
console.log(numbers);

const numbers = new Set([1, 2, 3]);
console.log(numbers.has(1));
console.log(numbers.has(999));

const fruits = new Set(["apple", "orange", "banana"]);

// iteration
for (const fruit of fruits) {
  console.log(fruit); // "apple"、"orange"、"banana"の順で出力される
}
*/


// map (use default one like this)
// it is defferent from object type

/*
1. Mapは宣言した型しか使えないがオブジェクトは型が自由。
2. Mapは直接JSON化できないが、オブジェクトは直接JSON化が可能である。
*/

/*
const map = new Map<string, number>();
map.set("a", 1);
console.log(map.get("a"));
// get certain element 
console.log(map.get("a"));

// delete certain element 
map.delete("a");

// check if the certain element exists
map.has("a")

// get the size of the elements
map.size

// iteration 
for (const [key, value] of map) {
  console.log(key, value);
  // "a", 1
  // "b", 2
  // "c", 3 の順で出力される
}

*/

// uf
class UnionFind {
    
    private parents: Array<number>;

    constructor(n: number){
        this.parents = new Array<number>(n);
        for(let i = 0; i < n; i++){
            this.parents[i] = -1;
        }
    }

    // root
    public root(a: number): number {
        if(this.parents[a] != -1){
            return this.root(this.parents[a]);
        } else {
            return a;
        }
    }

    // unite
    public unite(a: number, b: number): void{
        let ra = this.root(a);
        let rb = this.root(b);
        if (ra == rb) return;


    }

    // IsUnion
    public IsUnion(a: number, b: number): boolean {
        return this.root(a) == this.root(b);
    }

}

// segment tree


class SegmentTree {

    private numbers: number[][];
    private log: number; // 段の高さ

    constructor(size: number) {
        this.log = Math.ceil(Math.log2(size));
        this.numbers = new Array(this.log);
        for (let l = 0; l <= this.log; l++) {
            const m = Math.pow(2, l);
            const p = Math.ceil(size / m);
            this.numbers[l] = new Array(p);
            for (let j = 0; j < p; j++) this.numbers[l][j] = 0;
        }
    }

    public set(index: number, value: number) {
        this.numbers[0][index] = value;
        for (let layer = 1; layer <= this.log; layer++) {
            let li = Math.floor(index / Math.pow(2, layer));
            let lj1 = li * 2; //　左上のマスのindex
            let lj2 = li * 2 + 1; // 右上のマスのindex

            // 配列の長さを超えることがあるので、その場合は0とみなす
            let lv1 = lj1 >= this.numbers[layer - 1].length ? 0 : this.numbers[layer - 1][lj1];
            let lv2 = lj2 >= this.numbers[layer - 1].length ? 0 : this.numbers[layer - 1][lj2];

            this.numbers[layer][li] = lv1 + lv2;

        }
    }

    // 半開区間
    public query(start: number, end: number) {
        return this.recursive(start, end, this.log, 0);
    }


    public recursive(start: number, end: number, layer: number, index: number): any {
        // この段は１マスあたり何要素を受け持つか
        const layerCellCount = Math.pow(2, layer);

        // このマスが受け持つ要素たちの右端と左端
        const layerCellStart = index * layerCellCount;
        const layerCellEnd = layerCellStart + layerCellCount;

        // マスの長さと完全に一致する場合
        if (start == layerCellStart && end == layerCellEnd) {
            return this.numbers[layer][index];
        }

        // この段の上の段は1マスあたり何要素を受け持つか
        const childLayerCellCount = Math.pow(2, layer - 1);
        // 左上のインデックス
        const leftChildIndex = index * 2;
        // 右上のインデックス
        const rightChildIndex = leftChildIndex + 1;

        // 左上・右上のマスが受け持つ要素たちの右端と左端
        const leftChildStart = leftChildIndex * childLayerCellCount;
        const leftChildEnd = leftChildStart + childLayerCellCount;
        const rightChildStart = leftChildEnd;
        const rightChildEnd = rightChildStart + childLayerCellCount;

        // 左上のマスだけに用事がある
        if (end <= leftChildEnd) {
            return this.recursive(start, end, layer - 1, leftChildIndex);
        }

        // 右上のマスだけに用事がある
        if (rightChildStart <= start) {
            return this.recursive(start, end, layer - 1, rightChildIndex);
        }

        // 左上と右上のマスを足す
        return this.recursive(start, leftChildEnd, layer - 1, leftChildIndex)
            + this.recursive(rightChildStart, end, layer - 1, rightChildIndex);
    }
}

