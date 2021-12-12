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




