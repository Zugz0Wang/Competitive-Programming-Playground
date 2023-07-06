---
title: "Competetive Programming Learning Notes"
author: Zhifeng Wang
date: May 17th, 2023
geometry: "left=2cm,right=2cm,top=2cm,bottom=2cm"
output: pdf_document
---

# Leetcode

---

## Leetcode.137. Single Number II

- Independently solved; 20230704

Similar to the previous Single Number I, every bit will be flipped 3n + 1 times. I need to make those numbers that occurred three times cancel with themselves, and therefore I used a ternary integer consisting of two binary integers to solve this problem. 

---

## Leetocde.209. Minimum Size Subarray Sum

- Independently solved; 20230706

A slide window problem. The idea is to calculate the minimum length of valid subarrays starting from each index, and the length of valid subarrays will never shrink when all numbers in the array are positive.

---

## Leetcode.228. Summary Ranges

- Unknown, probably Independently solved; 20220814

Simply looping through the vector and keeping track of continuous numbers.

---

## Leetcode.347. Top K Frequent Elements 

- Independently solved, but slow; 20230522

I used unordered map and priority queue to solve it.

---

## Leetcode.373. Find K Pairs with Smallest Sums

- Independently solved; 20230627

- It's slow because I didn't use heap.

This is an interesting question. I used a 2D plane to help me clean my thoughts. A pair of sum with the i-th of the first and the j-th element of the second can be seen as a coordinate on a 2D plane.

---

## Leetcode.399. Evaluate Division 

- Independently solved; 20230520

Not completely sure how I managed to solve it independently. I'm just having a intuition that all variables can link to a "base" variable and use it to quickly calculate the answer to queries. Therefore, I think a modified version of union-find algorithm would be useful.

---

## Leetcode.530. Minimum Absolute Difference in BST

- Independently solved; 20230614

Textbook Binary Search Tree in order traversal (and keeping track of the previous element). (No need to calculate the absolute value)

---

## Leetcode.547. Number Of Provinces

This problem is about counting the connected component of a graph. I used Union Find to solve it. BFS would also work.

---

## Leetcode.703. Kth Largest Element In A Stream 

- Independently solved; 20230523

I used a map, a binary search tree, to solve this problem. This question is a good practice for iterators.

---

## Leetcode.714. Best Time to Buy and Sell stock with Transaction fee

- Copied from solution; 20230622

Travelling and not understanding. I guess this a-few-line solution requires some math intuitive proofs to understand.

---

## Leetcode.744. Find Smallest Letter Greater Than Target

- Independently solved; 20230609

A textbook Binary Search question.

---

## Leetcode.785. Is Graph Bipartite 

- Independently solved; 20230519

I used BFS to solve this problem. I forgot that the graphs might have multiple components at first, and then I added the outer for-loop to check through all graph components.

---

## Leetcode.837. New 21 Game 

- Independently solved (Hinted by Big O); 20230525

Following the main idea of the previous few days, this question also tests the concept of maintaining some data structure of a specific size, popping old elements when new elements arrive. 

In this question, while also examing the basic idea of dynamic programming, the critical point is calculating the sum of probabilities of previously calculated information. To achieve that, instead of looping through, I use a circular queue to quickly calculate the sum of the previous "maxPts" number of probability. The circular queue allows me to update the sum of probabilities in constant time. You can maintain a sum in a variable, deduct the sum of the first element of the queue, and add the incoming new probability to quickly update the sum. 

---

## Leetcode.859. Buddy Strings

- Independently solved; 20230703

Handling the case of swapping identical characters is the key to solve this problem.

---

## Leetcode.864. Shortest Path to Get All Keys

- Learned from solution; 20230629

The main takeaway from this question is the idea of putting other information like the currently obtained keys into the state of the BFS queue.

---

## Leetcode.934. Shortest Bridge 

- Independently solved; 20230521

This question tests the idea of using BFS with multiple starting points. I first find a single starting point of one of the islands, identify all the nodes of the island, and finally use BFS with multiple starting points to find the distance between the two islands.

---

## Leetcode.956. Tallest Billboard

- Independently solved (hinted by tags and titles); 20230624; Hard

Like the question from yesterday, the key to solve this problem is thinking about what information from the previous rods is helpful when the next length of rod shows up.

---

## Leetcode.1027. Longest Arithmetic Subsequence

- Independently solved (hinted by titles of solutions and tags); 20230623

A strange dynamic programming problem. The small problem size limit reminds me to think about O($n^2$) methods.

---

## Leetcode.1091. Shortest Path In Binary Matrix

- Independently solved; 20230601

A typical question for BFS. I reused the grid matrix as the visited set.

---

## Leetcode.1140. Stone Game II

- Unknown, probably learned; 20220822

This question tests the idea of memorized DFS. The critical trick would be using the suffix sum to quickly calculate the total score one player gets with the total score their opponent gets.

---

## Leetcode.1146. Snapshot Array

- Independently solved; 20230611

This question reminds me of the git architecture. I used a vector of structs to record the change of values of each index from a start snapshot id to an end snapshot id. At first, I chose to change every end value of the last element of every index at every snapshot, which led to a TLE. To improve the time complexity, I chose to use an INF value at the last element of all indices and update the end value only when it's changing, such that I only need to update the snapshot id when the snapshot function is called. 

---

## Leetcode.1161. Maximum Level Sum Of A Binary Tree

- Independently solved; 20230615

Textbook BFS and Binary Tree Level Order Traversal problem. An alternative solution would be using DFS, keeping track of the current level of the recursion calls, and using an array to record the sum of each level of tree nodes.

---

## Leetcode.1187. Make Array Strictly Increasing

- Learned from solution; 20230617

Dynamic Programming. I still don't understand why I need to update i1 to the "upper bound" of the previous largest value before using the array of dynamic programming.

---

## Leetcode.1231. Check If It Is A Straight Line

- Independently solved; 20230605

I constructed a direction struct to help me handle vertical cases.

---

## Leetcode.1318. Minimum Flips To Make A or B Equal To C

- Independently solved; 20230607

My solution loops through every bit of a,b, and c and checks whether I need to flip some bits in a and/or b. This problem provides a good chance to practice bitwise manipulations.

---

## Leetcode.1351. Count Negative Numbers In A sorted Matrix

- Independently solved; 20230608

Since the matrix is sorted from top left to bottom right, if we can find an element with a negative value, all elements from the bottom right area would be negative. So, we can start from the bottom left and follow along the "stairs" to get the number of negative numbers.

---

## Leetcode.1376. Time Needed To Inform All Employees

- Independently solved; 20230603

I used recursion to solve this problem. The time to inform a tree of employees equals inform time of the current head plus the maximum time for its sub-division heads to inform their employees.

---

## Leetcode.1493. Longest Subarray Of 1s After Deleting One Element

- Independently solved; 20230705

The key of this problem is handling base cases, such as all ones and ones with zeros.

---

## Leetcode.1502. Cab anje Arithmetic Progression From Sequence

- Hinted (misread the question); 20230606

In the beginning, I thought a sequence would be valid if all the absolute values of differences between consecutive pairs were the same, for example, 1010101. I wonder how can I solve a problem like that.

---

## Leetcode.1514. Path with Maximum Probability

- Independently solved; 202306

Textbook Dijkstra problem.

---

## Leetcode.1547. Minimum Cost To Cut A Stick

- Independently solved (hinted by tags and titles); 20230528

This problem can be solved by dynamic programming. I came up with a bottom-up dynamic programming technique, which calculates the subproblems with a few cuts and builds up information to solve larger subproblems.

---
## Leetcode.1557. Minimum Number of Vertices to Reach All Nodes 

- Independently solved; 20230518

At first, I thought I should try "Union Find" with "merging by size" or other similar ideas. But later, I figured out that I must include all the nodes with zero in-going edges and shouldn't include any nodes with in-going edges.

---

## Leetcode.1569. Number Of Ways To Reorder Array To Get Same BST

- Independently solved; 20230618
- Searched for calculating "N choose K" and multiplicative inverse.

This is an excellent question that combines the knowledge of Math, recursion, and Binary Search Tree.

---

## Leetcode.1575. Count All Possible Routes

- Independently solved (hinted by tags and titles); 20230625

This is a traditional recursion problem. You need to add one to the answer if the start city equals the end city.

---

## Leetcode.1601. Maximum Number Of Achievable Transfer Requests

- Learned from solution; 20230702

I used Brute Force to iterate through all combinations of requests selection.

---

## Leetcode.1603. Design Parking System

- Independently solved; 20230529

It's a simple counting problem. Keeping track of the number of remaining parking slots for each type of car and deducting the number of available slots respectively are the keys to solving this problem.

---

## Leetcode.1732. Find the Highest Altitude

- Independently solved; 20230619

Looping through the gains and calculating the absolute altitude.

---

## Leetcode.1802. Maximum Value At A Given Index In A Bounded Array

- Independently solved; 20230610

This is a textbook Binary Search question. Be careful with integer overflows.

---

## Leetcode.1970. Last Day Where You Can Still Cross

- Independently solved (verified my idea through tags); 20230630

This is a textbook Union Find problem.

---

## Leetcode.2090. K radius Subarray Averages

- Independently solved; 20230620;

I used a sum variable to keep track of the sums of elements in the range. When I need to move the range of the sum, I can simply deduct the value of the "head" element and add the value of the "tail" element of the current range to the sum to keep track of the next sum. Be careful with integer overflows.

---

## Leetcode.2101. Detonate The Maximum Bombs

- Independently solved; 20230602

I first convert the bomb relationships into a graph and then use BFS to calculate how many bombs can be detonated through the ith bomb. At first, I tried to use Union Find to solve this problem, but then I realized that this graph is directed.

Union Find uses path compression to accelerate the algorithm. I guess I can also use path compression in a graph with multiple components or directed, but that would be unnecessary.

---

## Leetcode.2305. Fair Distribution of Cookies

- Learned from solution; 20230701

A recursion problem. I managed to use a Stack to simulate recursion.

---

## Leetcode.2328. Number Of Increasing Paths In A Grid

- Learned from solution; 20230618

At first, I was thinking in the wrong direction, which elements in the dynamic programming array represent the number of paths that end in that position. But that led to a Time Limit Exceeded. At last, I checked out the solution and found out plain DFS would solve it.

---

## Leetcode.2352. Equal Row And Column Pairs

- Hinted(verified not going to TLE); 20230613

Looping through all the columns and rows and checking whether all elements are the same. An alternative would be transforming vectors into hashable strings. 

---

## Leetcode.2448. Minimum Cost To Make Array Equal

- Hinted(but had technical issues about MLE); 20230621

I independently figured out using prefix-sum to calculate the next cost sum in O(1). But it seems using a lambda function to sort the indices vector led to a Memory Limit Exceed.

---

## Leetcode.2462. Total Cost to Hire K Workers

- Independently solved; 20230626

I used priority queue to select the candidates with the lowest cost.

---

## Leetcode.2542. Maximum Subsequent Score 

- Learned from solution; 20230524

The basic idea is the same as Leetcode.703 from yesterday. You need to maintain some data structure of size k and pop something out when the size is over k.
