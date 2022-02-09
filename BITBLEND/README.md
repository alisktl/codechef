# BITBLEND: Bitwise Blend

The task is [here](https://www.codechef.com/FEB221C/problems/BITBLEND)

## Solution
* A sequence is `tasty` if the elements have alternating parity.
* In one operation, we can change the parity of any element `i` by choosing a `j` such that `A𝚓` is odd.
* The answer is `-1` if the sequence has no odd elements.
* To find minimum operations, we can assume the sequence to start from an odd/even element and check the number of mismatches in each case.
* To find a sequence of operations, choose one odd element and correct all other elements using this element. Keep in mind, you might also need to correct the chosen odd element.