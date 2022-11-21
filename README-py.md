# Interview Prep Notes (w/ Python)

I've switched over to Python as my preferred language for interviewing/leetcoding.
The reasons are, well, obvious and easily found all over the internet.

## Key Guidelines

- Always at least *consider* the brute-force solution initially.
- Try not to get hung up trying to solve a problem, look up the solution if needed and comprehend it thoroughly.

## LeetCode Solutions

### Q1 - Two Sum

- Simply use a dictionary, store indices of past items.

### Q9 - Palindrome Number

- Many ways to verify palindromes. One way is to reverse entire input, check for equality.
- `divmod(a, b) -> (a // b, a % b)`

### Q11 - Container With Most Water

- Initialize pointers at both ends of input.
  Keep track of maximum while iterating.
  Move the pointer that has less effect on the maximum value.

### Q20 - Valid Parentheses

- Use a list as a stack.
  Remember to ensure the stack is empty at the end.

### Q21 - Merge Two Sorted Lists

- Use a dummy node to keep track of the result's head node.

### Q58 - Length of Last Word

- Trivial with `split`.

### Q94 - Binary Tree Inorder Traversal

- For recursive solutions, local function definitions are useful and allow not passing arguments around.
- For the iterative solution, a helper variable for the current node helps to imitate the function callstack behavior.

### Q121 - Best Time to Buy and Sell Stock

- You can use either some item from input as initial min/max value, or `float("inf")`
- Visualize the graph. The ideal time may be to sell at current time after having **bought at minimum**.
  Keep track of max profit and min price.

### Q206 - Reverse Linked List

- Not much to say, just be mindful of the steps.

### Q217 - Contains Duplicate

- Extremely simple with dictionary, though keep the sorting solution in mind.

