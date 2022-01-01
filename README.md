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

### Q1

- As with many situations, it's possible to sacrifice memory in exchange for superior time complexity.
- Storing each element of a vector into a map where the values are indices reduces the algorithm
to a one-pass. Lookup is made constant in this way.

### Q2

- When working with linked lists, it's sometimes useful to have a dummy node at the beginning.
  Once you need to return the result, just return `dummy->next`. This technique may simplify loops.
- If you are doing something that produces extra terms to be included into the algorithm,
  be careful about whether your conditional clauses need to include said term as well.
  For example, when adding two digits, the resulting carry may be stored as an extra term,
  in which case, you would need to take into account whether the conditionals should include
  the carry beside the two digits.

### Q3

- The *sliding window* technique is great for one-pass solutions.
  You should consider the rules of what your left and right pointers mean.
  For example, the window may be defined as `[left, right]`, `[left, right)`, or `(left, right]`.
  The exclusion of the left pointer may simplify things at times.
- Consider keeping a store of indices according to which you can advance the left pointer.
- Vectors can be used as frequency tables when you're working with a type
  that maps easily to integer-based indexing, such as `char`.
  When the `char`s are ASCII, use size 26 for `az` or `AZ`, 128 for full ASCII, 256 for extended ASCII.

### Q4

- When working with multiple sorted arrays, you might be able to save both memory and time by
  just simulating a merge operation with pointers and setting a breaking condition
  such that what you are left with is the answer.

### Q7

- When working with the individual digits of a number, modulo and integer division are your
  best friends.
- If possible, instead of keeping track of what you do (multiplier, etc.),
  just cut down the number itself to keep track (integer division helps with this).

### Q9

- When trying to validate a palindrome, rather than checking through iteration,
  you can reverse the input into another variable and check if `input == reverse`.
- Sometimes, constraints may prevent reversing the entire input. In that case,
  you can reverse only one half of the input and check if the remaining input is equal
  to the reversed half.

### Q13

- Basic understanding of roman numerals: Each symbol is converted to its integer equivalent and summed.
  Symbols like I/X/C become negative when positioned right before V/X or L/C or D/M respectively.

### Q14

- Nothing much to add. Just remember to consider edge cases.

### Q19

**Need to add notes here.**

### Q20

- Don't access the top of a stack when it's empty, because "calling `back` on an empty container causes UB".
- When processing something "outward to inward", stacks can help.

### Q21

- When merging two linked lists, if you consume one list entirely, you can just have the node at that moment point to
  the list that still has elements left. In other words, there's no need to construct the remaining result list by hand.

### Q22

**Need to add notes here.**

### Q26

- The two pointer technique is commonly used such that one is the "slow-runner" and the other is the "fast-runner".

### Q27

Too easy, nothing to add.

### Q28

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

### Q32

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

### Q35

**Need to add notes here.**

### Q39

**Need to add notes here.**

### Q46

**Need to add notes here.**

### Q53

**Need to add notes here.**

### Q56

- In brute-force-like algorithms, it may be helpful to sort the vector and process it afterwards.

### Q66

**Need to add notes here.**

### Q70

**Need to add notes here.**

### Q79

**Need to add notes here.**

### Q88

**Need to add notes here.**

### Q92

**Need to add notes here.**

### Q94

**Need to add notes here.**

### Q102

**Need to add notes here.**

### Q104

**Need to add notes here.**

### Q107

**Need to add notes here.**

### Q111

**Need to add notes here.**

### Q112

**Need to add notes here.**

### Q113

**Need to add notes here.**

### Q121

- One-pass algorithm by keeping track of minimum value at each iteration.
- Doing comparisons to determine the optimized value itself rather than variables that *should* result in
  the most optimal value is useful at times. For example, when looking for max profit,
  do comparisons on the potential max profit itself rather than trying to find a max value from
  which to subtract a min value. Doing final comparisons according to what is already known at that moment
  helps to simplify the flow of the code as well. In other words, work with `maxProfit` and `minValue`
  instead of `maxValue` and `minValue`.

### Q124

**Need to add notes here.**

### Q125

**Need to add notes here.**

### Q136

**Need to add notes here.**

### Q141

**Need to add notes here.**

### Q143

**Need to add notes here.**

### Q146

**Need to add notes here.**

### Q190

**Need to add notes here.**

### Q191

**Need to add notes here.**

### Q200

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

### Q202

**Need to add notes here.**

### Q203

**Need to add notes here.**

### Q206

**Need to add notes here.**

### Q215

**Need to add notes here.**

### Q217

**Need to add notes here.**

### Q230

**Need to add notes here.**

### Q237

**Need to add notes here.**

### Q257

**Need to add notes here.**

### Q258

**Need to add notes here.**

### Q268

**Need to add notes here.**

### Q278

**Need to add notes here.**

### Q322

**Need to add notes here.**

### Q338

**Need to add notes here.**

### Q344

**Need to add notes here.**

### Q345

**Need to add notes here.**

### Q347

**Need to add notes here.**

### Q359

- Using a hashmap to keep track of messages is simple, but over time there is no
  garbage collection on the memory. Instead you can use a queue+set combination
  to wipe all messages that are at the front of the queue with a timestamp difference over the constraints.
  The set serves as the hashmap check in this case.

### Q369

**Need to add notes here.**

### Q371

**Need to add notes here.**

### Q387

**Need to add notes here.**

### Q389

**Need to add notes here.**

### Q394

- You can convert `char`s to `int` by doing `charValue - '0'`.
- Recursive: Mostly straightforward, just beware of your loop conditionals.
  This approach takes away the complexity of managing your own stacks.
- Iterative: Solving a recursive problem with iteration usually involves stacks,
  but beware that you may even need to manage multiple stacks for different things.

### Q412

**Need to add notes here.**

### Q414

**Need to add notes here.**

### Q509

**Need to add notes here.**

### Q540

**Need to add notes here.**

### Q541

**Need to add notes here.**

### Q557

**Need to add notes here.**

### Q559

**Need to add notes here.**

### Q637

**Need to add notes here.**

### Q696

**Need to add notes here.**

### Q703

**Need to add notes here.**

### Q876

**Need to add notes here.**

### Q938

- BST (Binary Search Tree) lets you discard paths that do not meet constraints.
- DFS uses either a stack or recursion, and BFS uses queues.

### Q989

**Need to add notes here.**

### Q1005

**Need to add notes here.**

### Q1051

**Need to add notes here.**

### Q1119

**Need to add notes here.**

### Q1408

**Need to add notes here.**

### Q1985

**Need to add notes here.**

### Q2095

**Need to add notes here.**

### Q2099

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

### The Essential Data Structures & Algorithms

#### Data Structures

##### Arrays - `vector`

##### Linked Lists - `list` & `ListNode`

##### Hash Tables/Sets - `unordered_map`/`unordered_set`/etc

##### Stacks/Queues - `stack`/`queue`

##### Heaps - `priority_queue`

##### Trees - `TreeNode`

#### Concepts (Algorithms, etc.)

##### Breadth-First Search (BFS)

##### Depth-First Search (DFS)

##### Binary Search

##### Merge Sort / Quick Sort

##### Bit Manipulation

##### Dynamic Programming

##### Backtracking

##### Greedy Algorithms

##### NP Problems
