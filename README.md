# Interview Prep Notes

This document contains notes to improve my problem solving skills, and possibly other skills
such as system design in the distant future.
The solutions outlined below are not copies of the actual solutions, but rather contain
the intuition or thought process that has one arrive at a solution.
Above all, LeetCode is a matter of being able to recognize and apply patterns,
which this document intends to help with.
Additionally, I do note some implementation tips for myself, such as dummy heads in lists.

## LeetCode Solutions

These are my notes for the LeetCode questions I've solved, with respective code under `solutions/*.cpp`.
All solutions are in **C++**, as it has a phenomenal standard library.

### Q1 - Two Sum

- As with many situations, it's possible to sacrifice memory in exchange for superior time complexity.
- Storing each element of a vector into a map where the values are indices reduces the algorithm
to a one-pass. Lookup is made constant in this way.

### Q2 - Add Two Numbers

- When working with linked lists, it's sometimes useful to have a dummy node at the beginning.
  Once you need to return the result, just return `dummy->next`. This technique may simplify loops.
- If you are doing something that produces extra terms to be included into the algorithm,
  be careful about whether your conditional clauses need to include said term as well.
  For example, when adding two digits, the resulting carry may be stored as an extra term,
  in which case, you would need to take into account whether the conditionals should include
  the carry beside the two digits.

### Q3 - Longest Substring Without Repeating Characters

- The *sliding window* technique is great for one-pass solutions.
  You should consider the rules of what your left and right pointers mean.
  For example, the window may be defined as `[left, right]`, `[left, right)`, or `(left, right]`.
  The exclusion of the left pointer may simplify things at times.
- Consider keeping a store of indices according to which you can advance the left pointer.
- Vectors can be used as frequency tables when you're working with a type
  that maps easily to integer-based indexing, such as `char`.
  When the `char`s are ASCII, use size 26 for `az` or `AZ`, 128 for full ASCII, 256 for extended ASCII.

### Q4 - Median of Two Sorted Arrays

- When working with multiple sorted arrays, you might be able to save both memory and time by
  just simulating a merge operation with pointers and setting a breaking condition
  such that what you are left with is the answer.

### Q7 - Reverse Integer

- When working with the individual digits of a number, modulo and integer division are your
  best friends.
- If possible, instead of keeping track of what you do (multiplier, etc.),
  just cut down the number itself to keep track (integer division helps with this).

### Q9 - Palindrome Number

- When trying to validate a palindrome, rather than checking through iteration,
  you can reverse the input into another variable and check if `input == reverse`.
- Sometimes, constraints may prevent reversing the entire input. In that case,
  you can reverse only one half of the input and check if the remaining input is equal
  to the reversed half.

### Q13 - Roman to Integer

- Basic understanding of roman numerals: Each symbol is converted to its integer equivalent and summed.
  Symbols like I/X/C become negative when positioned right before V/X or L/C or D/M respectively.

### Q14 - Longest Common Prefix

- Nothing much to add. Just remember to consider edge cases.

### Q19 - Remove Nth Node From End of List

- Again, dummy nodes help but be careful picking `dummy->next` instead of `dummy.next`.
- Queues with a fixed size help you keep track of the `n`th most recent element of something.

### Q20 - Valid Parentheses

- Don't access the top of a stack when it's empty, because "calling `back` on an empty container causes UB".
- When processing something "outward to inward", stacks can help.

### Q21 - Merge Two Sorted Lists

- When merging two linked lists, if you consume one list entirely, you can just have the node at that moment point to
  the list that still has elements left. In other words, there's no need to construct the remaining result list by hand.

### Q22 - Generate Parentheses

- One way to approach a recursive backtrack problem is to make sure each recursive call constructs a *valid* subresult,
  and let it run until it hits a base case of *what we are looking for*. If there are two **independent** recursive calls within a recursive,
  the first call is going to exhaust all possibilities, and only then will the second call be run for the first time.
- This kind of recursion is VERY similar to DFS. We exhaust the first option we have, then exhaust the second option.
  Once the second option is exhausted, we backtrack, use a second option instead of a first one, and exhaust that.
  Then just repeat until all possibilities are exhausted.

### Q23 - Merge k Sorted Lists

- When reducing a list of something to a single item, you can iteratively combine the first and last items while reducing the size by
  `size -= size / 2` each time, so you are eventually left with a single item.

### Q26 - Remove Duplicates from Sorted Array

- The two pointer technique is commonly used such that one is the "slow-runner" and the other is the "fast-runner".

### Q27 - Remove Element

Too easy, nothing to add.

### Q28 - Implement strStr()

- String matching is optimally done with KMP or Rabin Karp, but that's a bit of an advanced topic.
- Sometimes it's just better to deal with some edge cases before the main logic.
- For questions where you only need to find the very first instance of something,
  you can return as soon as you find it, and in fact have the default return statement
  return some constant like `-1`.
- You can move the variable declaration statement of a `for` block to the outside of the loop
  so you get to keep it after the `for` block.
- In cases like substring matching where there needs to be a minimum amount of indices left
  to fit in, you can set loop conditionals such that the impossible indices are not iterated over.
  See: `lPtr != haystack.size() - needle.size() + 1` (+1 depending on how the range is to be used).

### Q32 - Longest Valid Parentheses

- Dynamic Programming:
  - In array questions, it's possible to do DP by using another array of the same size.
    You might be able to store information about a certain element by examining patterns.
    This may include using the DP results of the previous elements.
  - Having a base case helps to get the DP array rolling.
- Stacks:
  - Indices are pushed onto an array, and popped once it's verified that that index marks a valid substring.
    Thus, when an element is popped, the top element is one before the largest verified substring index at that time.
  - By pushing invalid indices when the stack becomes empty, we make sure there's always a "one before valid index" element.
- It's sometimes possible to accomplish wizardry by running an algorithm forwards then backwards.

### Q35 - Search Insert Position

- You always need to think of binary search when a sorted array is mentioned.

### Q39 - Combination Sum

- Recursive backtrack solutions have a general pattern of;
  - Lay out a base case to return and *backtrack* on invalid elements,
    and also to record sought results if obtained.
  - Have either a loop or some kind of conditional to go over your **possible options for the next attempt**.
    The new option is added here, then a recursive call is made with the new state, and then the new option is popped away.
- It again helps to think of the process in terms of call stack and DFS.
- Within the options loop of the recursive function, consider where to start your iteration from each time.
  For example, when going over number candidates, you don't need to iterate over previous candidates on the list, but you should
  iterate the current item once more at least.

### Q46 - Permutations

- Generating permutations by backtracking works as a DFS where elements are swapped.
  On each level of the recursion, the current item is swapped with an element on the right.
  The base case occurs when there are no elements left to swap.

### Q53 - Maximum Subarray

- Following Kadane's algorithm, you need to discard any current sum that is negative, as it will never contribute positively.
- To be able to process negative results as well, set the max so `INT_MIN` so that any negative item may still be worth keeping.

### Q56 - Merge Intervals

- In brute-force-like algorithms, it may be helpful to **sort the vector** and process it afterwards.
- Determine when you are going to add the interval as is, and when you are going to merge.
  Setting up a conditional for this is easy. Then, determine what you would need to do to merge two intervals.
  Step by step.

### Q62 - Unique Paths

- Dynamic programming is good for these kinds of counting problems.
  Each position can only be reached from two adjacent directions, so just sum those and put it in a DP variable.
- Before adding a lot of code to cover edge cases, consider whether you can adjust your base case to cover those as well.

### Q63 - Unique Paths II

- Implementing obstacles is as simple as forcing their DP sum to be 0.
- For the first row and column, it's better to do a loop beforehand and determine their values so that you don't have to
  deal with it as an edge case in the main loop.

### Q66 - Plus One

- Straightforward grade-school addition. Notice that you don't need to keep going if the carry is 0, as it will never become 1 again.

### Q70 - Climbing Stairs

- Great fit for DP since the current step depends on the previous two steps.
  Again, make sure you do a good mapping of the DP indices and values, the rest will come naturally.
- Can also be solved with recursion, which can be optimized with memoization.
  As always, you just give it a base case and call the recursion with the necessary increments.

### Q79 - Word Search

- This follows the usual recursive backtracking pattern where you change a thing, run recursion, change it back.
  Of course, there needs to be a base case too. In this problem, the value is changed by invalidating the current cell,
  effectively marking it as visited. The base case is whether the current cell can be part of the word or not.
- The recursive function is actually called for every cell in the grid through simple iteration.
- You can either invalidate a cell by changing its content, or add its address to a set of visited coordinates.
  The latter is slower, but doesn't modify the original grid.

### Q88 - Merge Sorted Array

- Instead of using extra space to store the merged array, there is a trick to do this in constant space (merge in-place).
  Use three pointers (2 for the arrays, 1 for where the item will go), and work from the end to the front.
  This way, no values will be overwritten. In fact, this trick is helpful in any array question where in-place actions are needed.

### Q92 - Reverse Linked List II

- Nothing tricky other than keeping track of what node is pointing where and a few edge cases.

### Q94 - Binary Tree Inorder Traversal

- Inorder traversal is very easy with recursion, but doing it iteratively is a bit trickier.
  For every node, you traverse left and push to stack until you can't anymore.
  Then pop from the stack, visit the node, move to the right node, repeat.

### Q101 - Symmetric Tree

- Simple stuff recursively. Iteratively, it works with a BFS-like queue where the elements are `pair`s of supposedly symmetric nodes.

### Q102 - Binary Tree Level Order Traversal

- Recursion is once again easier. Iterative solution needs BFS where the level is kept track of, perhaps in a `pair` alongside the node.

### Q104 - Maximum Depth of Binary Tree

- Recursion easy, iteration uses `pair` for depth.

### Q107 - Binary Tree Level Order Traversal II

- Pretty much the same solution as Q102, except you reverse the result. Keep that in mind I guess.

### Q111 - Minimum Depth of Binary Tree

- Doable with DFS/BFS/recursion. Note that with BFS, you can keep track of depth/level by using a `for` loop
  within the `while` loop. If you run the loop as many times as the queue has elements *at the beginning*,
  you will have gone through all queue items on the current level. Something like `int n = q.size(); for (int i = 0; i < n; i++) {}`.

### Q112 - Path Sum

- Pretty recursion, or `pair`ed DFS.

### Q113 - Path Sum II

- Once again, the elegant solution is to use recursive backtracking to add in then pop a node on the path.
- If insisting on an iterative DFS, you can use `tuple` to keep track of node/sum/path all at once.

### Q114 - Flatten Binary Tree to Linked List

- Dummy nodes help with trees as well. You can do flattening in `O(1)` space by appending DFS nodes to a dummy node.
- When doing DFS, be **very** careful with the order in which you push the branches to the stack.
  Pushing the left branch *before* the right branch means you explore the right branch **first**.
  In other words, if you want to go left to right, push right then left.

### Q121 - Best Time to Buy and Sell Stock

- One-pass algorithm by keeping track of minimum value at each iteration.
- Doing comparisons to determine the optimized value itself rather than variables that *should* result in
  the most optimal value is useful at times. For example, when looking for max profit,
  do comparisons on the potential max profit itself rather than trying to find a max value from
  which to subtract a min value. Doing final comparisons according to what is already known at that moment
  helps to simplify the flow of the code as well. In other words, work with `maxProfit` and `minValue`
  instead of `maxValue` and `minValue`.

### Q124 - Binary Tree Maximum Path Sum

**Need to add notes here.**

### Q125 - Valid Palindrome

**Need to add notes here.**

### Q136 - Single Number

**Need to add notes here.**

### Q141 - Linked List Cycle

**Need to add notes here.**

### Q143 - Reorder List

**Need to add notes here.**

### Q146 - LRU Cache

**Need to add notes here.**

### Q190 - Reverse Bits

**Need to add notes here.**

### Q191 - Number of 1 Bits

**Need to add notes here.**

### Q200 - Number of Islands

- In certain questions, you can invalidate (destroy) adjacent data to eliminate recounting the same data.
- Rather than destroying the data, it's a better practice to either make a copy or keep track
  of the data that would have been destroyed by putting it in a hashmap etc.
  Additional conditional checks against the "visited" data would be added in this case.
- Both BFS and DFS can be used in a 2D array.
- When you need to access an array at a certain index, check that the index is within the array.
  It's easier to write the conditional once you've written the array expression.
- The index checks mentioned above are sometimes greatly simplified if you can reduce the
  check down to a single point. Instead of checking multiple indices by hand before calling
  a function, instead have the function begin by checking if the input index is valid.
  Doing so reduces the check down to a single location.
- **Read the solution with Union Find.**

### Q202 - Happy Number

**Need to add notes here.**

### Q203 - Remove Linked List Elements

**Need to add notes here.**

### Q206 - Reverse Linked List

**Need to add notes here.**

### Q215 - Kth Largest Element in an Array

**Need to add notes here.**

### Q217 - Contains Duplicate

**Need to add notes here.**

### Q225 - Implement Stack using Queues

- You can keep rotating a single queue to get a stack.
  You would arrive at this solution by writing down the real state of the queue
  and also the ideal stack representation, and compare to see how you might accomplish it.

### Q230 - Kth Smallest Element in a BST

**Need to add notes here.**

### Q232 - Implement Queue using Stacks

**Need to add notes here.**

### Q234 - Palindrome Linked List

- To solve a palindrome linked list question in space `O(1)`, reverse the second half of the list and verify.
- To find the middle of the list, use slow & fast running pointers; if the 2nd pointer moves 2 nodes, and the
  1st pointer moves 1 node; by the time the fast one reaches the end, the slow one will be at the middle.

### Q237 - Delete Node in a Linked List

**Need to add notes here.**

### Q257 - Binary Tree Paths

**Need to add notes here.**

### Q258 - Add Digits

**Need to add notes here.**

### Q268 - Missing Number

**Need to add notes here.**

### Q278 - First Bad Version

**Need to add notes here.**

### Q322 - Coin Change

**Need to add notes here.**

### Q338 - Counting Bits

**Need to add notes here.**

### Q344 - Reverse String

**Need to add notes here.**

### Q345 - Reverse Vowels of a String

**Need to add notes here.**

### Q347 - Top K Frequent Elements

**Need to add notes here.**

### Q359 - Logger Rate Limiter

- Using a hashmap to keep track of messages is simple, but over time there is no
  garbage collection on the memory. Instead you can use a queue+set combination
  to wipe all messages that are at the front of the queue with a timestamp difference over the constraints.
  The set serves as the hashmap check in this case.

### Q366 - Find Leaves of Binary Tree

**Need to add notes here.**

### Q369 - Plus One Linked List

**Need to add notes here.**

### Q371 - Sum of Two Integers

**Need to add notes here.**

### Q382 - Linked List Random Node

**Need to add notes here.**

### Q387 - First Unique Character in a String

**Need to add notes here.**

### Q389 - Find the Difference

**Need to add notes here.**

### Q394 - Decode String

- You can convert `char`s to `int` by doing `charValue - '0'`.
- Recursive: Mostly straightforward, just beware of your loop conditionals.
  This approach takes away the complexity of managing your own stacks.
- Iterative: Solving a recursive problem with iteration usually involves stacks,
  but beware that you may even need to manage multiple stacks for different things.

### Q412 - Fizz Buzz

**Need to add notes here.**

### Q414 - Third Maximum Number

**Need to add notes here.**

### Q415 - Add Strings

**Need to add notes here.**

### Q423 - Reconstruct Original Digits from English

**Need to add notes here.**

### Q509 - Fibonacci Number

**Need to add notes here.**

### Q528 - Random Pick with Weight

**Need to add notes here.**

### Q540 - Single Element in a Sorted Array

**Need to add notes here.**

### Q541 - Reverse String II

**Need to add notes here.**

### Q557 - Reverse Words in a String III

**Need to add notes here.**

### Q559 - Maximum Depth of N-ary Tree

**Need to add notes here.**

### Q637 - Average of Levels in Binary Tree

**Need to add notes here.**

### Q680 - Valid Palindrome II

- If you're validating something, and you're allowed to remove an element at most,
  you can simply feed the subsequence after the deletion into the function,
  to solve it via recursion.

### Q696 - Count Binary Substrings

**Need to add notes here.**

### Q703 - Kth Largest Element in a Stream

**Need to add notes here.**

### Q746 - Min Cost Climbing Stairs

**Need to add notes here.**

### Q811 - Subdomain Visit Count

**Need to add notes here.**

### Q833 - Find And Replace in String

**Need to add notes here.**

### Q876 - Middle of the Linked List

**Need to add notes here.**

### Q938 - Range Sum of BST

- BST (Binary Search Tree) lets you discard paths that do not meet constraints.
- DFS uses either a stack or recursion, and BFS uses queues.

### Q989 - Add to Array-Form of Integer

**Need to add notes here.**

### Q1005 - Maximize Sum Of Array After K Negations

**Need to add notes here.**

### Q1051 - Height Checker

**Need to add notes here.**

### Q1119 - Remove Vowels from a String

**Need to add notes here.**

### Q1408 - String Matching in an Array

**Need to add notes here.**

### Q1985 - Find the Kth Largest Integer in the Array

**Need to add notes here.**

### Q2095 - Delete the Middle Node of a Linked List

**Need to add notes here.**

### Q2099 - Find Subsequence of Length K With the Largest Sum

**Need to add notes here.**

## Cracking the Coding Interview - Notes

### Interview Process

This section includes thoughts from both the book and experiences I've read around the web.

- Always talk out loud throughout the problem and expose your thought process.
- It's okay to receive some assistance from the interviewer, the process is interactive after all.
  If anything, it's better to pay attention to their feedback.
- Communication skills are nearly as important as other skills.
- Going through an example is extremely important both to verify and come up with solutions.
- When looking to find the source of a bug, it's better to go for smaller examples.
- Likewise, to find bugs, it's a good idea to introduce edge cases that are small.
- Ask clarifying questions to the interviewer to really grasp the problem.
  Questions are left vague for a reason. It's a good idea to get together a *Constraints* section
  like the ones LeetCode questions have.
- If you make ANY non-trivial assumptions in your code/algorithm, make sure to bring them up with the interviewer.
- Don't start coding until you have a solution cleared with the interviewer.
- Do a dry-run of the solution to catch bugs and verify.
- If you don't see an optimal solution, start off with the brute-force one and optimize from there.
  In fact, even if you are able to find an optimal solution, it's still a good idea to start with the brute one.
  It's good to let the interview see the alternatives you're able to come up with.
- Often times, it helps to think of what you would do if you were to solve the problem manually with your hands.
  For example, people do binary search on sorted lists almost by reflex. Something similar may occur with other problems.
- You might want to come up with a base case and build up from there. For example, for a permutation question,
  find the base cases `{a}` and `{ab, ba}` then realize that for permutations of `abc` you just need to insert a `c` into it.
- It's a good idea to have some genuine questions prepared for the interviewer.
- Don't forget to go over the items on your resume as it's possible to be asked about them in depth.
- Recommended questions from Google to think about:
  - How do you work best, both as an individual and as part of a team?
  - What challenges have you faced at school or at work and how did you overcome them?
  - Which of your skills or experiences would be assets in the role and why?
  - What is something you learned that made everything that came after easier?
  - Have more of your achievements come as a result of solitary effort or teamwork?
  - What do you enjoy more, solving problems or pushing the discussion forward?
  - What is the most rewarding job you've ever had? Why?
  - Describe the best team you ever worked with. What made that experience stand out?
- Things that get me excited about Google:
  - The flexibility to work the way you want
  - Financial peace of mind
  - The chance to be surrounded by Googlers
  - The room for growth
  - All kinds of perks to enjoy
  - To be able to work on significant projects
  - To experience new things & diversity
  - There's clearly so much more on the inside that I don't know yet

### Big O Notation

Big O is used to describe the efficiency of algorithms. It's concerned more with the growth of complexity
rather than the actual runtime itself. *Time complexity* and *space complexity* can be described with Big O.
Commonly seen are, from best to worst; `O(1)`, `O(logN)`, `O(N)`, `O(NlogN)`, `O(N^2)`, `O(2^N)`, `O(N!)`.
The runtimes may not occur exactly, as in, there may exist best and worst cases. For example,
in code with the possibility of early returns, the best case may be significantly better.

Recursive functions can have their time/space complexities determined by the amount of times they are called,
since each call is added onto the call stack. Other times, it may help to draw a graph with branches of function calls,
to clearly see the complexity by comparing levels.

Constants are dropped from Big O notation. As mentioned, we are only concerned with the rate of increase.
Also drop non-dominant terms, for example, `O(N^2 + N)` is reduced to `O(N^2)`.
However, be careful, as some operations have their complexities multiplied rather than added.
These are usually dependent on one another, such as by being nested.

Sometimes, an aspect of the complexity may not be explicit. For example, a `vector` will need to resize and
copy all elements to a new inner array after some insertions. Similarly, a `string` will need to copy its contents
over to a new memory location, especially when a lot of concatenations are taking place.

A logarithmic time complexity often indicates that the elements in question get halved (or more) upon each iteration.

Be very careful with what variables you use in a Big O notation, using `N` for several unrelated quantities is a common mistake.
The amount of elements in an array and the length of each string in that array cannot both be represented by `N`.

When code runs in a fashion like `1 + 2 + ... + n`, the runtime is still `O(N^2)` because `(N(N+1))/2 -> N^2`.

### The Essential Data Structures & Algorithms

#### Data Structures

##### Arrays - `vector`

- The techniques with arrays almost always apply to strings as well.
- Many languages do not have resizable arrays natively, and instead use library classes like `vector`.
  These provide dynamic resizing, and may multiply their size when they are internally full.
- Be careful with string concatenation as it can result in many internal copies.
  However, since C++ has a mutable `string` class, the resize behavior is similar to that of a `vector`.
- Rabin-Karp substring search is the technique to check if two substrings have the same hash,
  ideally using a rolling hash function.
- `std::vector`;
  - Constructors: `vector()`, `vector(count, value)`, `vector(size)`, `vector(itr_begin, itr_end)`, `vector(vector)`, `vector({init_list})`.
  - `operator[index]` returns reference in `O(1)`.
  - `front` and `back` return references to first and last elements respectively.
  - `begin`/`end` and `rbegin`/`rend` return iterators in respective directions.
  - `empty` and `size` for element count.
  - `clear` (`O(N)`), `erase(itr)` or `erase(itr_begin, itr_end)` (`O(N)`), `push_back` (amortized `O(1)`), `pop_back` (`O(1)`).
  - `insert(itr, value)` for insertion before `itr`, `insert(itr, itr_begin, itr_end)` inserts range before `itr`,
    `insert(itr, {init_list})` inserts list before `itr`. Runtime is linear in the distance to the end of array.
- `std::vector<bool>` is a special case, as it is implemented for use as a dynamic bitset.
  It has a hash function, unlike other `vector` types, and has a member function `flip` to flip all bits.
- `std::string`;
  - Constructors: `string()` and `string(count, char)` (initialized with `count` amount of `char`).
  - `operator[index]` returns reference to `char`.
  - Same as `vector`; `front`, `back`, `begin`/etc, `empty`, `size`, `clear`, `pop_back`.
  - `operator+=` to append `char` or `string`.
  - `insert` has lots of overloads.
  - `erase(i_begin, count)` or `erase(itr)` or `erase(itr_begin, itr_end)`.
  - `substr(i_begin, count = end)` returns substring `[i_begin, i_begin+count)`
  - `find(string/char, i_begin)` returns index to first match, searches from `i_begin`.
  - `to_string` non-member function for numeric values.

##### Linked Lists - `list` & `ListNode`

- Lists don't provide random access, but they do allow inserting/removing items at the head in constant time.
- Lists may be singly or doubly linked.

##### Hash Tables/Sets - `unordered_map`/`unordered_set`/etc

- Hash tables map keys to values for efficient lookup. This is usually done via hashing functions.
  The hash of the key is computed, and the hash is mapped to an index on the internal array.
  This internal array consists of linked lists, which hold the items whose hash is the same.
  If the hash collisions are high, the lookup runtime may increase to linear.
- Hash tables may also be implemented using balanced binary search trees (also called red-black tree).
  This makes most runtimes a `O(logN)`, but the space used potentially decreases.
- `std::unordered_map<Key, Value>`;
  - Constructors: `unordered_map()`, `unordered_map(itr_begin, itr_end)`, `unordered_map({init_list})`.
    The initializers need to be of form `{{key, value}, ...}`.
  - `begin`/`end` return `iterator`s.
  - `empty`/`size`/`clear` are supported.
  - `erase(key)` or `erase(itr)`.
  - `operator[key]` returns reference to value. If no such `key` exists, it's inserted.
  - `count(key)` returns 1 or 0 as this container does not support duplicate keys.
  - `find(key)` returns `iterator` if found, otherwise `end`.
  - `iterator` points to `pair<Key, Value>`.
- `std::unordered_set<Key>`;
  - Mostly similar to `unordered_map`.
  - Insertion is done via `insert(key)`.
- There are also `set` and `map`, which are implemented with trees, and are sorted.
- There are also `multi` versions of these, which allow duplicate keys.

##### Stacks/Queues - `stack`/`queue`

- Stacks are often useful in implementing a recursive function iteratively.
- Queues are good for implementing BFS and caches.
- `std::stack<Value>`;
  - `top` returns reference to top item.
  - `size`/`empty` are supported.
  - `push` adds new items, has runtime of internal container.
  - `pop` removes top item, has runtime of internal container.
- `std::queue<Value>`;
  - `front`/`back` return references to first/last item pushed respectively.
  - `size`/`empty` are supported.
  - `push` adds new items, has runtime of internal container.
  - `pop` removes front item, has runtime of internal container.

##### Heaps - `priority_queue`

- Priority queues are implemented with heaps and are great for finding the max/min of a thing.
- A heap is actually a binary tree that has a specific order among nodes.
  For example, in a min-heap, each node is smaller than its children.
- `std::priority_queue<Value, Container=vector<Value>, Compare=less<Value>>`;
  - Is a max-heap by default, with the largest element at the top.
    Can be made min-heap with `Compare -> greater<Value>`.
    Can also have custom comparison by creating a new class with an overloaded `operator()`.
  - `top` returns top item of the heap tree, value depends on priority criteria.
  - `size`/`empty` are supported.
  - `push` adds new items, in correct order, so has logarithmic runtime and of internal container.
  - `pop` removes top item, then corrects order, so has logarithmic runtime and of internal container.

##### Trees - `TreeNode`

- Not all trees are binary trees.
- A node is called a "leaf" if it has no children.
- A binary search tree is a tree where a specific order is kept:
  `all left descendents <= n < all right descendents`.
- Not all trees are balanced.
- Binary Tree Traversal:
  - **In-Order Traversal:** The visits are done in order of `left branch -> current node -> right branch`.
    When used on a BST, the nodes are in ascending order.
  - **Pre-Order Traversal:** The visits are done in order of `current node -> left branch -> right branch`.
  - **Post-Order Traversal:** The visits are done in order of `left branch -> right branch -> current node`.
- Tries (Prefix Trees) are n-ary trees in whose nodes are the characters to a word.
  The root connects to the first character of a string, which is laid out node to node until its end is marked in some way,
  such as with a "null" character or special termination node.

#### Concepts (Algorithms, etc.)

##### Breadth-First Search (BFS)

- Implemented with queues.
- Starts at the root, each neighbour is explored before moving onto their children.

##### Depth-First Search (DFS)

- Implemented either via recursion or stacks.
- Starts at the root, explores each branch completely before moving onto the next branch.

##### Binary Search

- Look at the middle, determine whether to move left or right next,
  keep going until the middle is the element we need.
- Has runtime `O(logN)`, since it keeps halving.

##### Merge Sort / Quick Sort

- Merge Sort (`O(NlogN)`) keeps dividing the array in half until there are only two elements to be merged,
  and merges them in the correct order.
- Quick Sort (`O(NlogN)` average, `O(N^2)` worst case) picks a random element and partitions the array
  such that it is eventually sorted.
- Radix Sort (`O(kN)` where `k` is the number of passes) works nicely in cases where finite integers are involved.

##### Bit Manipulation

- XOR is useful for addition, AND for carry, shifts for bitmasking and such.
  And bitmasking is great. It's probably preferable to use `uint32_t` if possible.

##### Dynamic Programming

- Usually done by keeping track of previous subproblems within an array,
  and it's useful to map the indices to subproblems that could aid with the current subproblem,
  and the values behind those indices to be the result of that previous subproblem.
  For example, for combination sum, the indices could be a certain sum and the values could
  be the number of ways to reach that sum, and so on.

##### Backtracking

- Usually involves recursion and invalidating a path once you're done with it.

##### Greedy Algorithms

- Simply go for the naive, *greedy* solution that *may* work.

##### NP-complete Problems

- P problems have solutions in polynomial time.
- NP problems have solutions that can be verified in polynomial time.
- NP-complete problems are those that can have other NP problems reduced to them.
- It is unknown whether NP-complete problems can be solved in polynomial time.
