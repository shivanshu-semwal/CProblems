---
title: Job Sequencing Problem
hide:
  - navigation
tags:
  - greedy
---

## Problem

- Given an array of jobs where every job has a deadline and associated profit if
  the job is finished before the deadline.
- It is also given that every job takes a single unit of time,
  so the minimum possible deadline for any job is 1.
- Maximize the total profit if only one job can be scheduled at a time.

### Input and Output

- Input Format
    - First line contains $n$ denoting the number of jobs
    - Next $n$ line each contain job-id, deadline and profit of jobs.

!!! example "Test Case"

    === "Case 1"

        ```txt
        4
        a 4 20
        b 1 10
        c 1 40
        d 1 30
        ```
        
        ```txt
        c a
        ```

    === "Case 2"

        ```txt
        5
        a 2 100
        b 1 19
        c 2 27
        d 1 25
        e 3 15
        ```

        ```txt
        c a e
        ```

## Solutions

### Naive Approach

- Generate all subsets of a given set of jobs
- and check individual subsets for the feasibility of jobs in that subset.
- Keep track of maximum profit among all feasible subsets.

=== "C++"

    ```cpp
    {{ include_file('naive.cpp') }}
    ```

!!! note ""

    - Time Complexity: $O(2^n)$
    - Auxiliary Space: $O(n)$
    - $n$ - no of jobs

### Greedy approach

Greedily choose the jobs with maximum profit first, by sorting the jobs in
decreasing order of their profit. This would help to maximize the total profit
as choosing the job with maximum profit for every time slot will eventually
maximize the total profit

Follow the given steps to solve the problem:

- Sort all jobs in decreasing order of profit.
- Iterate on jobs in decreasing order of profit.For each job , do the following :
- Find a time slot i, such that slot is empty and i < deadline and i is greatest.
  Put the job in this slot and mark this slot filled.
- If no such i exists, then ignore the job.

=== "C++"

    ```cpp
    {{ include_file('greedy.cpp') }}
    ```

!!! note ""

    - Time Complexity: $O(n^2)$
    - Auxiliary Space: $O(n)$
    - $n$ - no of jobs

### Priority-Queue (Max-Heap)

- Sort the jobs in the increasing order of their deadlines and
- then calculate the available slots between every two consecutive deadlines
  while iterating from the end.
- Include the profit of the job at the root of the Max-Heap while the empty
  slots are available and Heap is not empty, as this would help to choose the jobs
  with maximum profit for every set of available slots.

Follow the given steps to solve the problem:

- Sort the jobs based on their deadlines.
- Iterate from the end and calculate the available slots between every two
  consecutive deadlines.
- Insert the profit, deadline, and job ID of ith job in the max heap.
- While the slots are available and there are jobs left in the max heap,
  include the job ID with maximum profit and deadline in the result.
- Sort the result array based on their deadlines.

=== "C++"

    ```cpp
    {{ include_file('pq.cpp') }}
    ```

!!! note ""

    - Time Complexity: $O(n \log n)$
    - Auxiliary Space: $O(n)$
    - $n$ - number of jobs

## References and External Links

- <https://en.wikipedia.org/wiki/Job-shop_scheduling>
- <https://en.wikipedia.org/wiki/Interval_scheduling>
- <https://www.geeksforgeeks.org/job-sequencing-problem/>
- <https://practice.geeksforgeeks.org/problems/job-sequencing-problem/0>
- <https://www.techiedelight.com/job-sequencing-problem-deadlines/>
