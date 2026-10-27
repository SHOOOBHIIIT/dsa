# Data Structures & Algorithms Lab — C++ Programs

This repository contains the C++ programs completed for the Data Structures and Algorithms lab. Each program is written as a standalone file, so it can be compiled and executed on its own.

---

## Question 1 — Number of Ball Tips ([`balltips.cpp`](balltips.cpp))

**Aim:** If a ball is dropped with an initial speed `s`, find the number of tips (bounces) it takes before it stops, given that its speed becomes half after every tip.

**Working:**

1. We read the initial speed of the ball from the user in a variable `s`.
2. We create a counter variable `c` and initialize it with `0`.
3. We run a `while` loop with the condition `s > 0.001`, so the loop continues as long as the speed is not almost zero.
4. Inside the loop, we increase the counter by one and divide the speed by two.
5. After the loop ends, we print the total number of tips taken by the ball.

**Time Complexity:** **O(log s)** because the speed becomes half in every step.

**Space Complexity:** **O(1)** because only a few variables are used.

---

## Question 2 — Roots of a Quadratic Equation ([`quadroots.cpp`](quadroots.cpp))

**Aim:** To find the roots of a quadratic equation of the form `ax² + bx + c = 0`.

**Working:**

1. We read the three coefficients `a`, `b`, and `c` from the user.
2. We calculate the discriminant using the formula `d = b² - 4ac`.
3. If `d == 0`, both roots are real and equal, so we print `-b / (2a)`.
4. If `d > 0`, the roots are real and distinct, so we calculate them using `(-b ± √d) / 2a`.
5. If `d < 0`, the roots are imaginary and the program prints that the roots are imaginary.

**Time Complexity:** **O(1)** because only a fixed number of calculations are performed.

**Space Complexity:** **O(1)** because only a fixed number of variables are used.

---

## Question 3 — Unsorted Array ADT ([`AbstactDatatype.cpp`](AbstactDatatype.cpp))

**Aim:** To perform the basic operations of an Abstract Data Type on an unsorted array:

1. Inserting an element at the beginning.
2. Inserting an element in the middle.
3. Inserting an element at the last position.
4. Deleting an element from the array.

**Working:**

1. We create a function named `unsortedADT` which takes `n` as an argument.
2. We take `n` array elements from the user and print the array.
3. We display a menu with four choices and read the user's choice in a `switch` statement.
4. For insertion at the beginning, we shift every element one position to the right and place the new element at `arr[0]`.
5. For insertion in the middle, we read the position, shift elements from that position onward to the right, and place the new element at `arr[pos]`.
6. For insertion at the last position, we write the new element at `arr[n]` and increase the size.
7. For deletion, we search for the element using linear search. If it is found, we shift the following elements one position to the left and decrease the size.
8. If the element is not found, the program prints `Element not found`.
9. At the end, the updated array is printed.

**Time Complexity:** Insertion at the beginning and middle, and deletion, are **O(n)** because elements are shifted. Insertion at the end is **O(1)**.

**Space Complexity:** **O(n)** for the array.

**Note:** The array is created as `int arr[n]`, which has exactly `n` positions. Inserting a new element writes at `arr[n]`, which is outside the valid range. A fixed-size array with a separate size variable would be safer.

---

## Question 4 — List Implementation Using an Array ([`adt_list.cpp`](adt_list.cpp))

**Aim:** To implement a list using an array with the operations insert, delete, search, update, and display.

**Working:**

1. We create a class named `list` containing an integer array `a[100]` and a size variable `n`.
2. The `insert` function takes a position and a value. It checks whether the list is full or the position is invalid, shifts elements to the right, and places the new value.
3. The `del` function takes a position, checks whether the list is empty or the position is invalid, shifts elements to the left, and decreases the size.
4. The `search` function compares the given value with every element and returns its index, or `-1` if it is not found.
5. The `update` function replaces the value at a given position after checking the position.
6. The `display` function prints all elements of the list.
7. In `main`, a `do-while` loop shows a menu and calls the correct function based on the user's choice.

**Time Complexity:** Insert and delete are **O(n)** because elements are shifted. Search is **O(n)**. Update is **O(1)**.

**Space Complexity:** **O(n)** for the array.

---

## Question 5 — Time of Flight of a Projectile ([`timeflight.cpp`](timeflight.cpp))

**Aim:** To find the time of flight of a projectile.

**Working:**

1. We include the `cmath` library for the `sin` function.
2. We read the initial speed and the angle in degrees from the user.
3. We convert the angle from degrees to radians using `rad = deg * 3.14 / 180`.
4. We calculate the time of flight using the formula `t = (2 * s * sin(rad)) / 10`, where `g` is taken as `10`.
5. The calculated time is printed in seconds.

**Time Complexity:** **O(1)** because only fixed calculations are performed.

**Space Complexity:** **O(1)** because only a fixed number of variables are used.

---

## Question 6 — Maximum Height of a Projectile ([`maxheight.cpp`](maxheight.cpp))

**Aim:** To find the maximum height attained by a projectile.

**Working:**

1. We include the `cmath` library for the `sin` function.
2. We create a function named `hmax` which takes speed and angle as arguments.
3. Inside the function, we convert the angle from degrees to radians using `rad = deg * 3.14 / 180`.
4. We calculate the maximum height using the formula `h = (s² * sin²(rad)) / 20`, where `g` is taken as `10`.
5. The result is printed from inside the function, which is called from `main`.

**Time Complexity:** **O(1)** because only fixed calculations are performed.

**Space Complexity:** **O(1)** because only a fixed number of variables are used.

---

## Question 7 — Horizontal Range of a Projectile ([`hrange.cpp`](hrange.cpp))

**Aim:** To find the horizontal range of a projectile.

**Working:**

1. We include the `cmath` library for the `sin` function.
2. We create a function named `rng` which takes speed and angle as arguments.
3. Inside the function, we convert the angle from degrees to radians using `rad = deg * 3.14 / 180`.
4. We calculate the horizontal range using the formula `R = (s² * sin(2 * rad)) / 10`, where `g` is taken as `10`.
5. The result is returned to `main` and printed.

**Time Complexity:** **O(1)** because only fixed calculations are performed.

**Space Complexity:** **O(1)** because only a fixed number of variables are used.

---

## Question 8 — Shift Zeros to the End of an Array ([`shiftzero.cpp`](shiftzero.cpp))

**Aim:** To shift all zero elements of an array to the end while keeping the order of the non-zero elements.

**Working:**

1. We create a function named `shiftzero` which takes an array and its size `n`.
2. We create a variable `c` and initialize it with `0`. It stores the position where the next non-zero element should go.
3. We traverse the array with a `for` loop and check `a[i] != 0`.
4. When the element is not zero, we copy it to `a[c]` and increase `c`.
5. After the first loop, we fill all remaining positions from `c` to `n - 1` with zeros.
6. We call the function from `main` and print the updated array.

**Time Complexity:** **O(n)** because the array is traversed with linear scans.

**Space Complexity:** **O(1)** because the array is modified in place.

---

## Question 9 — First Duplicate Element in an Array ([`firstdup.cpp`](firstdup.cpp))

**Aim:** To find the first duplicate element in an array.

**Working:**

1. We create a function named `finddup` which takes an array and its size `n`.
2. We use two nested loops. The outer loop runs from `i = 0` to `n - 1`.
3. The inner loop runs from `j = i + 1` to `n - 1`.
4. Inside the inner loop, we compare `a[i]` with `a[j]`.
5. When two equal elements are found, we immediately return `a[i]`.
6. If no duplicate is found, the function returns `-1`.
7. In `main`, we print the duplicate value or a message saying no duplicate exists.

**Time Complexity:** **O(n²)** because two nested loops are used.

**Space Complexity:** **O(1)** because no extra array is used.

---

## Question 10 — Merge Two Sorted Arrays ([`mergesorted.cpp`](mergesorted.cpp))

**Aim:** To merge two sorted arrays into a single sorted array.

**Working:**

1. We read the size and elements of the first sorted array.
2. We read the size and elements of the second sorted array.
3. We create a third array `m1` to store the merged result.
4. We use three variables: `i` for the first array, `j` for the second array, and `k` for the result.
5. While both arrays have elements left, we compare `a1[i]` and `a2[j]` and copy the smaller value into `m1`.
6. When one array is finished, we copy all remaining elements of the other array.
7. Finally, we print the merged array.

**Time Complexity:** **O(n + m)**, where `n` and `m` are the sizes of the two arrays.

**Space Complexity:** **O(n + m)** for the merged array.

**Note:** This method works only if both input arrays are already sorted.

---

## Question 11 — Merge Two Sorted Arrays Using a Helper Function ([`mergetwo.cpp`](mergetwo.cpp))

**Aim:** To merge two sorted arrays into one sorted array using a reusable input function.

**Working:**

1. We create a function named `readarr` which takes an array, its size, and a name, and reads the elements from the user.
2. We read the size of the first array and call `readarr` to fill it.
3. We read the size of the second array and call `readarr` again.
4. We use two pointers `p` and `q` for the two arrays and a pointer `k` for the result array `z`.
5. While both arrays have elements left, the smaller current element is copied into `z` and its pointer is advanced.
6. The remaining elements of the unfinished array are copied after the loop.
7. The merged sorted array is printed.

**Time Complexity:** **O(n + m)** because each element is visited once.

**Space Complexity:** **O(n + m)** for the result array.

---

## Question 12 — Merge Sort Using an Array ([`mergesort.cpp`](mergesort.cpp))

**Aim:** To sort an array using the merge sort algorithm.

**Working:**

1. We create a `merge` function which takes the array and the left, middle, and right indices.
2. Inside `merge`, a temporary array is used to compare elements from the two sorted halves.
3. The smaller element is copied first, and the remaining elements are copied afterwards.
4. The sorted part is copied back into the original array.
5. We create a recursive `msort` function which divides the array into two halves until a subarray has one element.
6. Then it calls `merge` to combine the sorted halves.
7. In `main`, we read `n` elements, call `msort(a, 0, n - 1)`, and print the sorted array.

**Time Complexity:** **O(n log n)** in the best, average, and worst cases.

**Space Complexity:** **O(n)** for the temporary array used during merging.

---

## Question 13 — Merge Sort Using a Linked List ([`MergeSortLL.cpp`](MergeSortLL.cpp))

**Aim:** To sort a singly linked list using merge sort.

**Working:**

1. We create a `Node` class with a data value and a `next` pointer.
2. We create a `MergeSort` class with `head` and `tail` pointers and functions to insert at the front and back.
3. The `splitAtMid` function uses slow and fast pointers to find the middle node and breaks the list into two parts.
4. The `mergeSort` function recursively sorts the left and right halves.
5. The `merge` function compares the values of both lists and appends the smaller value to a new list.
6. The sorted list is printed before and after sorting.

**Time Complexity:** **O(n log n)** because the list is divided into halves and merged at every level.

**Space Complexity:** **O(log n)** recursion stack space. This implementation also creates new nodes during `merge`, so it uses additional node memory.

---

## Question 14 — Radix Sort Using a Linked List ([`redix_sort.cpp`](redix_sort.cpp))

**Aim:** To sort non-negative integers using radix sort with ten linked-list buckets.

**Working:**

1. We create `node` and `linkedlist` classes. The list supports insertion at the back, display, and finding the maximum value.
2. The `radix_sort` function first finds the maximum value to know how many digit positions are needed.
3. For every digit position (`exp = 1, 10, 100, ...`), we create ten linked-list buckets.
4. Each value is placed into bucket `(data / exp) % 10`.
5. The buckets are then joined from `0` to `9` to rebuild the list.
6. The process repeats for the next digit until all digit positions are processed.
7. The sorted list is displayed.

**Time Complexity:** **O(d · (n + 10))**, where `d` is the number of digits in the largest value.

**Space Complexity:** **O(n + 10)** for the nodes and buckets.

---

## Question 15 — Bucket Sort ([`BucketSort.cpp`](BucketSort.cpp))

**Aim:** To sort an array using bucket sort with linked-list buckets.

**Working:**

1. We create a `Node` class and a `LinkedList` class with a `push` function and a `sort` function.
2. In `bucketSort`, we first find the maximum value of the array.
3. We create ten buckets, where each bucket is a linked list.
4. For every element, we calculate its bucket index using `(arr[i] * 10) / (max + 1)`.
5. The element is pushed into the matching bucket.
6. Each bucket is sorted individually using nested loops that swap values.
7. Finally, the buckets are visited from `0` to `9` and their values are copied back into the array.

**Time Complexity:** Finding the maximum and distributing values is **O(n)**. Sorting the buckets is **O(Σ bᵢ²)**, which becomes **O(n²)** in the worst case when all values fall into one bucket.

**Space Complexity:** **O(n + 10)**, which is **O(n)**, for the bucket nodes.

---

## Question 16 — Bin Sort ([`bin_sort.cpp`](bin_sort.cpp))

**Aim:** To implement bin sort using linked lists.

**Working:**

1. A `node` class is created with a data value and a `next` pointer.
2. A `linkedlist` class is created with a `head` pointer.
3. The `insert` function appends a new node at the end of the list.
4. The `display` function prints all the values in the list.
5. The actual bin-sort logic and the `main` function have not been added yet.

**Time Complexity:** Not applicable yet, because the sorting part is incomplete.

**Space Complexity:** **O(n)** for the linked-list nodes.

**Note:** This file is an incomplete skeleton kept for practice.

---

## Question 17 — Heap Sort Using an Array ([`HeapSortArray.cpp`](HeapSortArray.cpp))

**Aim:** To sort an array using heap sort.

**Working:**

1. We create a `maxHeapify` function which compares a node with its left and right children.
2. If a child is larger than the parent, the values are swapped and `maxHeapify` is called again on that child.
3. For a node at index `i`, the left child is at `2*i + 1` and the right child is at `2*i + 2`.
4. The `buildHeap` function calls `maxHeapify` from the last parent down to the root, so the largest value reaches index `0`.
5. The `sortMaxHeap` function swaps the root with the last unsorted element, reduces the heap size, and calls `maxHeapify` again.
6. This process repeats until the array is sorted in ascending order.

**Time Complexity:** Building the heap is **O(n)** and sorting is **O(n log n)**, so the total is **O(n log n)**.

**Space Complexity:** **O(1)** extra space, excluding the recursion stack used by `maxHeapify`.

---

## Question 18 — Max Heap Using Linked Nodes ([`HeapSortLL.cpp`](HeapSortLL.cpp))

**Aim:** To build a complete binary tree using linked nodes and convert it into a max heap.

**Working:**

1. We create a `Node` class with data, left, and right pointers.
2. The `insert` function uses a queue to add each new node at the first empty child position, which keeps the tree complete.
3. The `maxHeapify` function compares a node with its children and swaps the largest value to the top.
4. It then calls itself recursively on the affected child.
5. The `preOrder` and `inOrder` functions display the tree.
6. In `main`, the values are inserted one by one, `maxHeapify` is called on the root, and the tree is printed.

**Time Complexity:** Inserting `n` nodes takes **O(n)**, and heapifying the tree takes **O(n)**.

**Space Complexity:** **O(n)** for the linked nodes and the queue.

**Note:** This program builds a max heap but does not perform the full extraction phase of heap sort.

---

## Question 19 — Linked List with Index and Bubble Sort ([`eyi.cpp`](eyi.cpp))

**Aim:** To create a linked list where every node stores an index, and to sort the list using bubble-sort-style swapping.

**Working:**

1. We create a `node` class with `data`, `index`, and `next` members.
2. We create a `list` class with `head` and `tail` pointers.
3. The `add` function appends a new node and assigns it the next index.
4. The `goto_index` function moves through the list and returns the node with the requested index.
5. The `val` function returns a node's data, and the `swap` function exchanges the data of two nodes.
6. The `print` function displays the list.
7. In `main`, values are added until the user enters `0`.
8. Two nested loops compare every pair of indexed nodes and swap them if they are out of order.
9. The list is printed before and after sorting.

**Time Complexity:** The sorting uses two loops, and each `goto_index` lookup is **O(n)**, so the total is **O(n²)** or slower.

**Space Complexity:** **O(n)** for the linked-list nodes.

---

## Question 20 — Selection Sort Using a Linked List ([`select.cpp`](select.cpp))

**Aim:** To sort a linked list using selection sort.

**Working:**

1. A `node` class is created with a data value and a `next` pointer.
2. A `list` class is created with a `head` pointer.
3. The `add` function appends a new node at the end of the list.
4. The selection-sort logic and the `main` function have not been added yet.

**Time Complexity:** Not applicable yet, because the sorting part is incomplete.

**Space Complexity:** **O(n)** for the linked-list nodes.

**Note:** This file is an incomplete skeleton kept for practice.

---

## Question 21 — Linear Queue Using an Array ([`Queue.cpp`](Queue.cpp))

**Aim:** To implement a linear queue using an array with `enQueue`, `deQueue`, `peek`, and `isEmpty` operations.

**Working:**

1. We create a class named `LinearQueue` with an array of size 10, a capacity, and `front` and `rear` variables.
2. Both `front` and `rear` are initialized to `-1`, which means the queue is empty.
3. The `enQueue` function checks whether the queue is full. If not, it sets `front` to `0` when needed and inserts the value at `rear + 1`.
4. The `deQueue` function checks whether the queue is empty. If not, it moves `front` forward, or resets both pointers when the last element is removed.
5. The `peek` function returns the value at `front` without removing it.
6. The `isEmpty` function checks whether the queue has no elements.
7. In `main`, five values are inserted and then removed one by one while printing the front value.

**Time Complexity:** **O(1)** for `enQueue`, `deQueue`, `peek`, and `isEmpty`.

**Space Complexity:** **O(capacity)** for the array.

---

## Question 22 — Circular Queue Using an Array ([`circularqueue.cpp`](circularqueue.cpp))

**Aim:** To implement a circular queue so that freed positions at the front can be reused.

**Working:**

1. We create a class named `cque` with an array of size 5, a front index, a rear index, and a count.
2. The `push` function checks whether the queue is full using `count`.
3. If it is not full, the rear moves using `r = (r + 1) % cap` and the value is inserted.
4. The `pop` function checks whether the queue is empty, then moves the front using `f = (f + 1) % cap`.
5. The `show` function prints the elements starting from the front and wraps around using `(f + i) % cap`.
6. In `main`, five values are pushed, two are popped, and the queue is printed after each stage.

**Time Complexity:** `push` and `pop` are **O(1)**. Displaying the queue is **O(n)**.

**Space Complexity:** **O(capacity)** for the array.

---

## Question 23 — Tower of Hanoi ([`towerhanoi.cpp`](towerhanoi.cpp))

**Aim:** To display the steps required to move `n` disks from the source rod to the destination rod using a helper rod.

**Working:**

1. We create a recursive function named `toh` which takes the number of disks and three rod names.
2. If there is only one disk, we print the move from the source rod to the destination rod.
3. Otherwise, we move `n - 1` disks from the source to the helper rod.
4. Then we move the largest disk from the source to the destination rod.
5. Finally, we move the `n - 1` disks from the helper rod to the destination rod.
6. In `main`, we read the number of disks and call `toh(n, 'S', 'U', 'D')`.

**Time Complexity:** **O(2ⁿ)** because the number of moves doubles with every extra disk.

**Space Complexity:** **O(n)** for the recursion stack.

---

## Question 24 — Binary Tree and Its Operations ([`BinaryTree.cpp`](BinaryTree.cpp))

**Aim:** To build a binary tree and perform traversals and other basic operations on it.

**Working:**

1. We create a `Node` class with data, left, and right pointers.
2. A static variable `idx` is used to track the current position in the input vector.
3. The `buildTree` function reads the vector in preorder style. A value of `-1` means the node is missing.
4. Inorder, preorder, and postorder traversals are implemented using recursion.
5. The `levelOrder` function uses a queue to print the tree level by level.
6. The `heightOfTree` function returns the height, and `countNodes` returns the number of nodes.
7. The `sumOfNodes` function returns the sum of all values, and `diamOfTree` finds the longest path between two nodes.
8. In `main`, a sample vector is used to build the tree and all operations are printed.

**Time Complexity:** The traversals, height, node count, and sum are **O(n)**. The diameter is **O(n²)** in this implementation because `heightOfTree` is called repeatedly for each node.

**Space Complexity:** **O(h)** recursion stack space for the traversals, where `h` is the height of the tree. The level-order traversal uses **O(w)** space, where `w` is the maximum width.

---

## Question 25 — Binary Search Tree ([`BST.cpp`](BST.cpp))

**Aim:** To implement a binary search tree with insertion, search, deletion, and traversals.

**Working:**

1. We create a `Node` class with data, left, and right pointers.
2. The `insert` function places smaller values in the left subtree and larger values in the right subtree.
3. The `buildBST` function inserts every element of an array into the tree.
4. Inorder, preorder, and postorder traversals are implemented using recursion.
5. The `search` function compares the value with the current node and moves left or right accordingly.
6. The `deletionOfNode` function handles three cases: a leaf node, a node with one child, and a node with two children.
7. For a node with two children, the inorder successor is found in the right subtree and its value replaces the deleted value.
8. In `main`, a sample array is used to build the tree, and then searching, deletion, and inorder traversal are performed.

**Time Complexity:** Average case **O(log n)** for insertion, search, and deletion. Worst case **O(n)** when the tree becomes skewed.

**Space Complexity:** **O(h)** recursion stack space, where `h` is the height of the tree.

---

## Question 26 — AVL Tree ([`AVLTrees.cpp`](AVLTrees.cpp))

**Aim:** To implement a self-balancing binary search tree using AVL rotations.

**Working:**

1. We create a `Node` class which stores data, left and right pointers, and a height value.
2. The `height` function returns the stored height of a node, or `0` for a null node.
3. The `balanceFactor` function calculates `height(left) - height(right)`.
4. The `rightRotation` and `leftRotation` functions are used to restore balance.
5. The `insert` function inserts a value like a normal BST and then checks the balance factor.
6. If the tree is left-heavy and the value is in the left subtree, an LL or LR rotation is applied.
7. If the tree is right-heavy and the value is in the right subtree, an RR or RL rotation is applied.
8. The `deletionOfNode` function deletes a value and rebalances the tree in the same way.
9. The `preOrder` function displays the tree, and `main` inserts and deletes sample values.

**Time Complexity:** **O(log n)** for insertion, deletion, and search because the tree remains balanced.

**Space Complexity:** **O(log n)** recursion stack space.

---

## Question 27 — Binary Search Tree with Parent Pointers ([`binarytreedelel.cpp`](binarytreedelel.cpp))

**Aim:** To implement an interactive binary search tree that stores a parent pointer in every node and supports insertion and deletion.

**Working:**

1. We create a `node` class with data, left, right, and parent pointers.
2. The `create_node` function creates a node with the given value and sets all pointers to `NULL`.
3. The `insert` function inserts a value using the BST rule and updates the parent pointer of the new node.
4. The `create_bt` function repeatedly reads values and inserts them until the user chooses to stop.
5. The `delete_node` function finds the required node and handles the leaf, one-child, and two-child cases.
6. Parent pointers are updated whenever a child is removed or replaced.
7. For a node with two children, the smallest value in the right subtree replaces the deleted value.
8. In `main`, the user can delete a node, insert a node, or display the tree using inorder traversal.

**Time Complexity:** Average case **O(log n)** for insertion and deletion. Worst case **O(n)** for a skewed tree.

**Space Complexity:** **O(h)** recursion stack space, where `h` is the height of the tree.

**Note:** Deleting the root is not handled because the root has no parent pointer.

---

## Question 28 — Interactive Binary Tree Creation ([`TREE.CPP`](TREE.CPP))

**Aim:** To create a binary tree interactively by asking the user whether each node has a left or right child.

**Working:**

1. We create a `Node` class with data, left, right, and parent pointers.
2. The `create_node` function reads a value and creates a new node.
3. The `create_BT` function asks whether a left child exists. If yes, it creates the child and recurses.
4. It then asks whether a right child exists and repeats the same process.
5. Inorder and preorder traversal functions are written.
6. In `main`, a root is created and `create_BT` is called.

**Time Complexity:** **O(n)** for creating `n` nodes.

**Space Complexity:** **O(h)** recursion stack space.

**Note:** This file is incomplete. It uses an undefined `node` type in the traversal functions, the `post order` function has syntax errors, and the `insertion` function is unfinished.

---

## How to Compile and Run

Every program is independent, so any file can be compiled on its own.

**Using g++:**

```bash
g++ BinaryTree.cpp -o BinaryTree
./BinaryTree
```

**Using MSVC (`cl.exe`):**

```bash
cl.exe /Zi /EHsc /nologo /Fe"BinaryTree.exe" "BinaryTree.cpp"
BinaryTree.exe
```

The `.vscode/tasks.json` file also provides a default build task for the active file in VS Code.

---

## Notes

- All programs use only the C++ standard library.
- The `.exe`, `.obj`, `.ilk`, and `.pdb` build files are ignored through `.gitignore`.
- Some files (`bin_sort.cpp`, `select.cpp`, and `TREE.CPP`) are incomplete and are kept as practice work.
- The filename `AbstactDatatype.cpp` uses `Abstact` instead of `Abstract`, and `redix_sort.cpp` uses `redix` instead of `radix`. These names are kept as they were originally written.
