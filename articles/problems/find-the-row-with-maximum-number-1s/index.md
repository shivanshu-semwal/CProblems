---
title: Find the row with maximum 1's matrix
hide:
  - navigation
---

## Problem

- Given a boolean 2D array, where each row is sorted.
- Find the row with the maximum number of 1s.

### Input and Output

!!! example "Test Case"

    === "Case 1"

        ```txt
        4 4
        0 1 1 1
        0 0 1 1
        1 1 1 1
        0 0 0 0
        ```

        ```txt
        2
        ```

## Solutions

### Naive Approach

A simple method is to do a row-wise traversal of the matrix, count the number of
1s in each row, and compare the count with max. Finally, return the index of the
row with maximum 1s.

=== "C++"

    ```cpp
    {{ include_file('naive.cpp') }}
    ```

!!! notes ""

    - Time Complexity: $O(m*n)$
    - Space Complexity:  $O(1)$
    - $m$ - no of columns of matrix
    - $n$ - no of rows of matrix

### Binary Search

We can do better. Since each row is sorted, we can use Binary Search to count of
1s in each row. We find the index of first instance of 1 in each row. The count
of 1s will be equal to total number of columns minus the index of first 1.

=== "C++"

    ```cpp
    {{ include_file('bs.cpp') }}
    ```

!!! notes ""

    - Time Complexity: $O(m \log n)$ where m is number of rows and n is number of columns in matrix.
    - Auxiliary Space:  $O(\log n)$, as implicit stack is created due to recursion.
    - $m$ - no of columns of matrix
    - $n$ - no of rows of matrix

### Linear Search only on some rows

The above solution can be optimized further. Instead of doing binary search in
every row, we first check whether the row has more 1s than max so far. If the
row has more 1s, then only count 1s in the row. Also, to count 1s in a row, we
don't do binary search in complete row, we do search in before the index of last
max.

=== "C++"

    ```cpp
    {{ include_file('bs-o.cpp') }}
    ```

!!! note ""

    - Time Complexity: $O(m+n)$ where m is number of rows and n is number of columns in matrix.
    - Auxiliary Space:  $O(1)$, as implicit stack is created due to recursion.
    - $m$ - no of columns of matrix
    - $n$ - no of rows of matrix
