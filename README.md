# LeetCode Solutions

This document contains my notes for the LeetCode questions I've solved.

## Q1

- As with many situations, it's possible to sacrifice memory in exchange for superior time complexity.
- Storing each element of a vector into a map where the values are indices reduces the algorithm
to a one-pass. Lookup is made constant in this way.

## Q2

- When working with linked lists, it's sometimes useful to have a dummy node at the beginning.
Once you need to return the result, just return `dummy->next`. This technique may simplify loops.
- If you are doing something that produces extra terms to be included into the algorithm,
be careful about whether your conditional clauses need to include said term as well.
For example, when adding two digits, the resulting carry may be stored as an extra term,
in which case, you would need to take into account whether the conditionals should include
the carry beside the two digits.

## Q3

- The *sliding window* technique is great for one-pass solutions.
You should consider the rules of what your left and right pointers mean.
For example, the window may be defined as `[left, right]`, `[left, right)`, or `(left, right]`.
The exclusion of the left pointer may simplify things at times.
- Consider keeping a store of indices according to which you can advance the left pointer.
- Vectors can be used as frequency tables when you're working with a type
that maps easily to integer-based indexing, such as `char`.
When the `char`s are ASCII, use size 26 for `az` or `AZ`, 128 for full ASCII, 256 for extended ASCII.

## Q4

- When working with multiple sorted arrays, you might be able to save both memory and time by
just simulating a merge operation with pointers and setting a breaking condition
such that what you are left with is the answer.

## Q7

- When working with the individual digits of a number, modulo and integer division are your
best friends.
- If possible, instead of keeping track of what you do (multiplier, etc.),
just cut down the number itself to keep track (integer division helps with this).

## Q9

- When trying to validate a palindrome, rather than checking through iteration,
you can reverse the input into another variable and check if `input == reverse`.
- Sometimes, constraints may prevent reversing the entire input. In that case,
you can reverse only one half of the input and check if the remaining input is equal
to the reversed half.

## Q13

- Basic understanding of roman numerals: Each symbol is converted to its integer equivalent and summed. Symbols like I/X/C become negative when positioned right before V/X or L/C or D/M respectively.

## Q14

- Nothing much to add. Just remember to consider edge cases.

## Q20

- Don't access the top of a stack when it's empty, because "calling `back` on an empty container causes UB".
- When processing something "outward to inward", stacks can help.

## Q21

- When merging two linked lists, if you consume one list entirely, you can just have the node at that moment point to the list that still has elements left. In other words, there's no need to construct the remaining result list by hand.

## Q26

- The two pointer technique is commonly used such that one is the "slow-runner" and the other is the "fast-runner".

## Q27

Too easy, nothing to add.



