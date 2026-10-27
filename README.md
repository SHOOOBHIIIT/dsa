# DSA in C++ — Practice Collection

A hands-on collection of Data Structures & Algorithms written in C++ while learning and revising core CS concepts. The repository covers arrays, linked lists, stacks, queues, trees, recursion, sorting algorithms, and a few classic physics/aptitude programs.

![Language](https://img.shields.io/badge/language-C%2B%2B-00599C?style=flat-square&logo=cplusplus)
![Repo](https://img.shields.io/badge/repo-SHOOOBHIIIT%2Fdsa-181717?style=flat-square&logo=github)
![Status](https://img.shields.io/badge/status-actively%20learning-blue?style=flat-square)

---

## About This Repository

This repo is my personal DSA notebook in code form. Every `.cpp` file is a small, self-contained program that focuses on one idea — implementing a data structure from scratch, applying an algorithm, or solving a classic interview-style problem.

Most programs are menu-driven or take input from the user, and every file compiles independently. The goal is not to build one large project, but to keep each concept isolated, readable, and easy to run again later.

What you will find here:

- **Linear data structures** — arrays, singly linked lists, stacks, queues.
- **Non-linear data structures** — binary trees, binary search trees, AVL trees.
- **Sorting algorithms** — merge sort, quick-style nested sorts, heap sort, bucket sort, radix sort.
- **Recursion** — Tower of Hanoi and recursive tree traversals.
- **Array problems** — duplicates, zero shifting, merging sorted arrays.
- **Classic math/physics programs** — projectile motion, quadratic roots, bouncing ball.

---

## Table of Contents

- [Repository Structure](#repository-structure)
- [Topics at a Glance](#topics-at-a-glance)
- [Array & ADT Programs](#array--adt-programs)
- [Sorting Algorithms](#sorting-algorithms)
- [Linked List Programs](#linked-list-programs)
- [Stack & Queue Programs](#stack--queue-programs)
- [Tree Programs](#tree-programs)
- [Recursion](#recursion)
- [Math & Physics Programs](#math--physics-programs)
- [Complexity Cheat Sheet](#complexity-cheat-sheet)
- [How to Compile & Run](#how-to-compile--run)
- [Repository Conventions](#repository-conventions)
- [Known Issues / Incomplete Files](#known-issues--incomplete-files)

---

## Repository Structure

```text
dsa/
│
├── Array & ADT
│   ├── AbstactDatatype.cpp      # Unsorted array ADT (insert/delete)
│   ├── adt_list.cpp             # Array-based list (insert/delete/search/update)
│   ├── firstdup.cpp             # First duplicate element
│   ├── shiftzero.cpp            # Move all zeros to the end
│   ├── mergesorted.cpp          # Merge two sorted arrays
│   └── mergetwo.cpp             # Merge two sorted arrays (helper version)
│
├── Sorting
│   ├── mergesort.cpp            # Merge sort on an array
│   ├── MergeSortLL.cpp          # Merge sort on a linked list
│   ├── HeapSortArray.cpp        # Heap sort on an array
│   ├── HeapSortLL.cpp           # Max-heap construction on a linked tree
│   ├── BucketSort.cpp           # Bucket sort using linked-list buckets
│   ├── redix_sort.cpp           # Radix sort using linked-list buckets
│   └── bin_sort.cpp             # Bin sort skeleton (incomplete)
│
├── Linked List
│   ├── eyi.cpp                  # Indexed linked list + bubble sort
│   └── select.cpp               # Linked-list skeleton (incomplete)
│
├── Stack & Queue
│   ├── Queue.cpp                # Linear queue using an array
│   └── circularqueue.cpp        # Circular queue using an array
│
├── Trees
│   ├── BinaryTree.cpp           # Binary tree + traversals + metrics
│   ├── BST.cpp                  # Binary search tree
│   ├── AVLTrees.cpp             # Self-balancing AVL tree
│   ├── binarytreedelel.cpp      # BST with parent pointers (interactive)
│   └── TREE.CPP                 # Interactive binary tree (incomplete)
│
├── Recursion
│   └── towerhanoi.cpp           # Tower of Hanoi
│
├── Math & Physics
│   ├── quadroots.cpp            # Roots of a quadratic equation
│   ├── timeflight.cpp           # Projectile time of flight
│   ├── maxheight.cpp            # Projectile maximum height
│   ├── hrange.cpp               # Projectile horizontal range
│   └── balltips.cpp             # Number of bounces of a ball
│
├── .vscode/
│   ├── tasks.json               # MSVC (cl.exe) build task
│   └── settings.json
└── .gitignore
```

---

## Topics at a Glance

| Category | Concepts Practiced | Files |
| --- | --- | --- |
| Arrays / ADT | Insertion, deletion, search, update, shifting | `AbstactDatatype.cpp`, `adt_list.cpp` |
| Array problems | Duplicates, zero shifting, merging | `firstdup.cpp`, `shiftzero.cpp`, `mergesorted.cpp`, `mergetwo.cpp` |
| Sorting | Divide & conquer, heap, buckets, radix | `mergesort.cpp`, `MergeSortLL.cpp`, `HeapSortArray.cpp`, `HeapSortLL.cpp`, `BucketSort.cpp`, `redix_sort.cpp` |
| Linked lists | Node linking, traversal, in-place sorting | `eyi.cpp`, `MergeSortLL.cpp`, `redix_sort.cpp` |
| Stacks / Queues | FIFO, circular indexing | `Queue.cpp`, `circularqueue.cpp` |
| Trees | Traversals, height, diameter, balancing | `BinaryTree.cpp`, `BST.cpp`, `AVLTrees.cpp`, `binarytreedelel.cpp` |
| Recursion | Base case + recursive reduction | `towerhanoi.cpp`, tree traversals |
| Math / Physics | Formulas, conditionals, loops | `quadroots.cpp`, `timeflight.cpp`, `maxheight.cpp`, `hrange.cpp`, `balltips.cpp` |

---

## Array & ADT Programs

### 1. Unsorted Array ADT — `AbstactDatatype.cpp`

**Purpose:** Demonstrates the idea of an Abstract Data Type on an *unsorted* array through a menu.

**Operations implemented:**

1. Insert at the beginning — shift all elements right.
2. Insert at a given position — shift elements from that position right.
3. Insert at the end — write at the next free index.
4. Delete a value — linear search, then shift elements left.

**How it works:** `main()` calls `unsortedADT(5)`, which reads five elements and prints a menu. A `switch` statement performs the selected operation and prints the updated array.

**Complexity:**

| Operation | Time | Space |
| --- | --- | --- |
| Insert at beginning / middle | `O(n)` | `O(1)` |
| Insert at end | `O(1)` | `O(1)` |
| Delete (search + shift) | `O(n)` | `O(1)` |

> **Note:** The array is declared as `int arr[n]`, so inserting a new element writes one slot past the valid range. A fixed-size buffer like `arr[100]` with a separate `size` variable would be safer.

---

### 2. Array-Based List — `adt_list.cpp`

**Purpose:** A clean class-based implementation of a list using a fixed array of size `100`.

**Class `list`:**

- `insert(p, x)` — insert `x` at position `p`.
- `del(p)` — delete the element at position `p`.
- `search(x)` — return the index of `x`, or `-1`.
- `update(p, x)` — replace the value at position `p`.
- `display()` — print the current list.

**How it works:** A `do-while` loop shows a numbered menu and calls the matching method. Bounds checks handle a full list, an empty list, and invalid positions.

**Complexity:**

| Operation | Time | Space |
| --- | --- | --- |
| Insert | `O(n)` | `O(1)` |
| Delete | `O(n)` | `O(1)` |
| Search | `O(n)` | `O(1)` |
| Update | `O(1)` | `O(1)` |

---

### 3. First Duplicate Element — `firstdup.cpp`

**Purpose:** Find the first value that appears more than once in an array.

**Approach:** Two nested loops. For each index `i`, compare `a[i]` with every later element `a[j]`. The first match is returned immediately.

```text
Input : 4 2 7 2 4
Output: 2
```

**Complexity:** `O(n²)` time, `O(1)` extra space.

---

### 4. Move Zeros to the End — `shiftzero.cpp`

**Purpose:** Push all zero values to the end while keeping the order of non-zero elements.

**Approach:**

1. Use a write pointer `c` starting at `0`.
2. Copy every non-zero element to `a[c]` and increment `c`.
3. Fill the remaining positions with zeros.

```text
Input : 0 5 0 3 8
Output: 5 3 8 0 0
```

**Complexity:** `O(n)` time, `O(1)` extra space (in-place).

---

### 5. Merge Two Sorted Arrays — `mergesorted.cpp` & `mergetwo.cpp`

**Purpose:** Merge two already-sorted arrays into one sorted array.

**Approach:**

1. Read both sorted arrays.
2. Keep two pointers `i` and `j` at the start of each array.
3. Copy the smaller current value into the result and advance that pointer.
4. When one array is exhausted, copy the remaining elements of the other.

**Complexity:** `O(n + m)` time, `O(n + m)` space for the merged array.

> `mergetwo.cpp` is the more organized version; it moves the input logic into a reusable `readarr()` helper.

---

## Sorting Algorithms

### 1. Merge Sort (Array) — `mergesort.cpp`

**Idea:** Divide the array into two halves, sort each half recursively, then merge the two sorted halves.

- `msort(a, l, r)` — recursive split until `l >= r`.
- `merge(a, l, m, r)` — merge using a temporary array.

**Complexity:** `O(n log n)` time in all cases, `O(n)` auxiliary space.

---

### 2. Merge Sort (Linked List) — `MergeSortLL.cpp`

**Idea:** Merge sort is a natural fit for linked lists because splitting and merging only requires pointer changes.

- `splitAtMid()` — slow and fast pointer technique to find the middle.
- `mergeSort()` — recursively sort both halves.
- `merge()` — merge two sorted lists into a new list.

**Complexity:** `O(n log n)` time, `O(log n)` recursion depth. This implementation allocates new nodes during `merge`, so it uses extra node memory as well.

---

### 3. Heap Sort (Array) — `HeapSortArray.cpp`

**Idea:** Build a max heap, then repeatedly move the largest element (root) to the end.

- `maxHeapify(arr, n, i)` — restore the heap property for one node.
- `buildHeap(arr, n)` — heapify from the last parent down to the root.
- `sortMaxHeap(arr, n)` — swap root with the last element, shrink the heap, heapify again.

For index `i`, children are at `2*i + 1` and `2*i + 2`.

**Complexity:** `O(n log n)` time, `O(1)` extra space (ignoring recursion stack).

---

### 4. Max Heap on a Linked Tree — `HeapSortLL.cpp`

**Purpose:** Build a complete binary tree using level-order insertion, then convert it into a max heap.

**How it works:**

1. `insert()` uses a queue to attach each new node to the first available child slot.
2. `maxHeapify()` compares a node with its children and swaps values so the parent is largest.
3. `preOrder()` and `inOrder()` display the heap.

> This file demonstrates the *heap property* on linked nodes; it builds a max heap but does not perform the full extraction phase of heap sort.

**Complexity:** `O(n)` to insert `n` nodes (level-order), `O(n)` to heapify the tree.

---

### 5. Bucket Sort — `BucketSort.cpp`

**Idea:** Distribute values into ten buckets, sort each bucket, then concatenate.

1. Find the maximum value.
2. Compute the bucket index with `(value * 10) / (max + 1)`.
3. Push values into linked-list buckets.
4. Sort each bucket with nested loops (selection-style).
5. Copy values back to the array from bucket `0` to `9`.

**Complexity:** `O(n + Σ bᵢ²)` time; `O(n²)` worst case if all values land in one bucket. `O(n)` space for nodes.

---

### 6. Radix Sort (Linked List) — `redix_sort.cpp`

**Idea:** Sort non-negative integers digit by digit, starting from the ones place.

1. Find the maximum value to know the number of digit passes.
2. For each digit (`exp = 1, 10, 100, ...`), place values into buckets `0–9` by `(value / exp) % 10`.
3. Re-link the buckets in order.
4. Repeat for the next digit.

**Complexity:** `O(d · (n + 10))` time, where `d` is the number of digits. `O(n)` space.

---

### 7. Bin Sort — `bin_sort.cpp`

**Status:** This file only defines a `node` class and a `linkedlist` class with `insert()` and `display()`. The actual bin-sort logic and `main()` are not implemented yet. It serves as a starting skeleton.

---

## Linked List Programs

### 1. Indexed Linked List — `eyi.cpp`

**Purpose:** A singly linked list where each node stores an `index` in addition to its data.

**Features:**

- `add(val)` — append a node and assign it the next index.
- `goto_index(i)` — linear search by stored index.
- `val(node)` — safely read a node's data.
- `swap(a, b)` — swap the data of two nodes.
- `print()` — display the list.

**Behavior:** The program reads values until `0` is entered, then sorts the list using nested loops (`O(n²)`) by swapping node data.

> The `goto_index()` lookup is `O(n)`, so the overall sort is slower than a normal linked-list sort — a good example of how a hidden linear scan inside a loop affects performance.

---

### 2. Linked List Skeleton — `select.cpp`

**Status:** Only the `node` and `list` classes with an `add()` method are present. There is no sorting logic or `main()`, so this file is a work-in-progress scaffold.

---

## Stack & Queue Programs

### 1. Linear Queue — `Queue.cpp`

**Purpose:** A bounded queue implemented with an array.

**Class `LinearQueue`:**

- `enQueue(value)` — insert at the rear.
- `deQueue()` — remove from the front.
- `peek()` — read the front value.
- `isEmpty()` — check whether the queue has no elements.

`front` and `rear` both start at `-1`, and reset when the last element is removed.

**Complexity:** `O(1)` for all operations.

---

### 2. Circular Queue — `circularqueue.cpp`

**Purpose:** A queue that reuses freed slots by wrapping indices around the array.

**Approach:**

- Keep `front`, `rear`, and `count`.
- Enqueue: `rear = (rear + 1) % capacity`.
- Dequeue: `front = (front + 1) % capacity`.
- Display: iterate `count` times from `(front + i) % capacity`.

**Complexity:** `O(1)` for push/pop, `O(n)` to display.

---

## Tree Programs

### 1. Binary Tree — `BinaryTree.cpp`

**Purpose:** Build a binary tree from a preorder-style vector, where `-1` marks a missing node.

**Operations:**

- `buildTree()` — recursive construction.
- `inOrder()`, `preOrder()`, `postOrder()` — recursive traversals.
- `levelOrder()` — BFS traversal using a queue.
- `heightOfTree()` — number of levels.
- `countNodes()` — total node count.
- `sumOfNodes()` — sum of all values.
- `diamOfTree()` — longest path between any two nodes.

**Complexity:** Traversals and metrics are `O(n)` time; recursive traversals use `O(h)` stack space, where `h` is the tree height.

---

### 2. Binary Search Tree — `BST.cpp`

**Purpose:** A BST where every left descendant is smaller and every right descendant is larger.

**Operations:**

- `insert()` — place a value using the BST rule.
- `buildBST()` — build a tree from an array.
- `search()` — recursive lookup.
- `inOrder()`, `preOrder()`, `postOrder()` — traversals.
- `deletionOfNode()` — handles leaf, single-child, and two-child cases using the inorder successor.

**Complexity:** `O(log n)` average and `O(n)` worst case (skewed tree) for insert/search/delete. Inorder traversal prints values in sorted order.

---

### 3. AVL Tree — `AVLTrees.cpp`

**Purpose:** A self-balancing BST that keeps the height difference between subtrees small.

**Key pieces:**

- `height()` and `balanceFactor()` — compute the balance state.
- `rightRotation()` / `leftRotation()` — fix imbalance.
- `insert()` — BST insert followed by LL / RR / LR / RL rotations.
- `deletionOfNode()` — BST delete followed by rebalancing.
- `preOrder()` — display the tree.

```
balance factor = height(left) - height(right)
valid range    = -1 ... +1
```

**Complexity:** `O(log n)` for insert, delete, and search because the tree stays balanced. Recursion uses `O(log n)` stack space.

---

### 4. BST with Parent Pointers — `binarytreedelel.cpp`

**Purpose:** An interactive BST that also stores a `parent` pointer on every node.

**Features:**

- `create_bt()` — repeatedly inserts user-supplied values.
- `insert()` — recursive insertion that fixes parent links.
- `delete_node()` — deletes a node and updates parent/child pointers.
- `inorder()` — displays the tree in sorted order.

> **Note:** Deleting the root (which has no parent) or deleting from an empty tree is not handled, so the program assumes the root is never the target.

---

### 5. Interactive Binary Tree — `TREE.CPP`

**Status:** A learning/incomplete file. It builds a tree by asking whether each node has a left or right child, but it uses an undefined `node` type, has a `post orer` function with syntax errors, and contains an unfinished `insertion()` function. It is kept as a record of the learning process.

---

## Recursion

### Tower of Hanoi — `towerhanoi.cpp`

**Problem:** Move `n` disks from the source rod to the destination rod using a helper rod, one disk at a time, never placing a larger disk on a smaller one.

**Recursive idea:**

1. Move `n - 1` disks from source to helper.
2. Move the largest disk from source to destination.
3. Move `n - 1` disks from helper to destination.

**Complexity:** `O(2ⁿ)` moves, `O(n)` recursion depth.

---

## Math & Physics Programs

These programs apply standard formulas and are useful for practicing input, arithmetic, and branching.

| File | Goal | Key Formula / Logic | Time | Space |
| --- | --- | --- | --- | --- |
| `quadroots.cpp` | Roots of `ax² + bx + c` | Discriminant `d = b² - 4ac`; handle `d = 0`, `d > 0`, `d < 0` | `O(1)` | `O(1)` |
| `timeflight.cpp` | Projectile time of flight | `t = (2 · s · sin θ) / g` | `O(1)` | `O(1)` |
| `maxheight.cpp` | Projectile max height | `h = (s² · sin²θ) / (2g)` | `O(1)` | `O(1)` |
| `hrange.cpp` | Projectile horizontal range | `R = (s² · sin 2θ) / g` | `O(1)` | `O(1)` |
| `balltips.cpp` | Number of bounces | Halve speed every bounce until `speed < 0.001` | `O(log s)` | `O(1)` |

All physics programs use `g = 10` and convert degrees to radians with `deg * 3.14 / 180`.

---

## Complexity Cheat Sheet

| Algorithm / Structure | Best | Average | Worst | Space |
| --- | --- | --- | --- | --- |
| Array insert at end | `O(1)` | `O(1)` | `O(1)` | `O(1)` |
| Array insert / delete | `O(1)` | `O(n)` | `O(n)` | `O(1)` |
| Linear search | `O(1)` | `O(n)` | `O(n)` | `O(1)` |
| Merge sort (array) | `O(n log n)` | `O(n log n)` | `O(n log n)` | `O(n)` |
| Merge sort (list) | `O(n log n)` | `O(n log n)` | `O(n log n)` | `O(log n)` stack |
| Heap sort | `O(n log n)` | `O(n log n)` | `O(n log n)` | `O(1)` |
| Bucket sort | `O(n)` | `O(n + k)` | `O(n²)` | `O(n)` |
| Radix sort | `O(d(n + b))` | `O(d(n + b))` | `O(d(n + b))` | `O(n + b)` |
| BST insert / search / delete | `O(log n)` | `O(log n)` | `O(n)` | `O(h)` |
| AVL insert / search / delete | `O(log n)` | `O(log n)` | `O(log n)` | `O(log n)` |
| Tree traversals | `O(n)` | `O(n)` | `O(n)` | `O(h)` |
| Tower of Hanoi | `O(2ⁿ)` | `O(2ⁿ)` | `O(2ⁿ)` | `O(n)` |
| Linear / circular queue ops | `O(1)` | `O(1)` | `O(1)` | `O(n)` |

---

## How to Compile & Run

Every file is standalone. Pick any `.cpp` file and compile it on its own.

### Using g++ (MinGW / GCC)

```bash
g++ BinaryTree.cpp -o BinaryTree
./BinaryTree
```

### Using MSVC (cl.exe)

The included `.vscode/tasks.json` already defines a build task:

```bash
cl.exe /Zi /EHsc /nologo /Fe"BinaryTree.exe" "BinaryTree.cpp"
```

Then run:

```cmd
BinaryTree.exe
```

> On VS Code, open the `.cpp` file and press `Ctrl + Shift + B` to run the default **C/C++: cl.exe build active file** task.

### Requirements

- A C++ compiler (`g++` or MSVC `cl.exe`).
- No external libraries — only the C++ standard library (`iostream`, `vector`, `queue`, `algorithm`, `cmath`).

---

## Repository Conventions

- One concept per file — each program is independent.
- Class names are mostly lowercase (`node`, `list`, `cque`) except for newer tree files (`Node`).
- Menu-driven programs use a `do-while` loop plus a `switch` statement.
- Naming is informal and matches the learning journey (`eyi.cpp`, `redix_sort.cpp`, `AbstactDatatype.cpp`).
- `.exe`, `.obj`, `.ilk`, and `.pdb` build outputs are ignored via `.gitignore`.

---

## Known Issues / Incomplete Files

This repository is a learning log, so a few files are deliberately unfinished or have rough edges. They are documented here rather than deleted so the progress is visible.

| File | Status / Issue |
| --- | --- |
| `bin_sort.cpp` | Only `node` and `linkedlist` classes exist; no sorting logic or `main()`. |
| `select.cpp` | Only an `add()` method exists; no selection sort, no `main()`. |
| `TREE.CPP` | Undefined `node` type, syntax errors in `post order`, unfinished `insertion()`. |
| `AbstactDatatype.cpp` | Filename typo (`Abstact`); writes past the array because `arr[n]` has exactly `n` slots. |
| `BST.cpp` | Has a stray duplicate `#include <iostream>` at the end of the file. |
| `HeapSortLL.cpp` | Builds a max heap but does not implement full extraction/sorting. |
| `redix_sort.cpp` | Filename typo (`redix` instead of `radix`). |
| `binarytreedelel.cpp` | Deleting the root or an empty tree is not handled. |

---

## Why This Repo Exists

Writing each structure by hand makes the details stick:

- How pointers actually move when a node is inserted.
- Why a balanced tree is faster than a skewed one.
- Why shifting an array is `O(n)` but moving a pointer is `O(1)`.
- How recursion turns a big problem into smaller copies of itself.

The collection will keep growing as more topics are covered — graphs, hashing, dynamic programming, and more advanced tree structures are natural next steps.

---

<p align="center">
  <b>Keep learning, keep coding.</b><br>
  <i>“The best way to learn data structures is to build them.”</i>
</p>
