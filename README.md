---
title: "Competetive Programming Learning Notes"
author: Zhifeng Wang
date: May 17th, 2023
geometry: "left=2cm,right=2cm,top=2cm,bottom=2cm"
output: pdf_document
---

# Leetcode

---

## Leetcode.17. Letter Combinations Of A phone Number

- Independently solved; 20230803

Similar to the Problem about Permutation(LC.46), I used DFS to solve it.

---

## Leetcode.33. Search in Rotated Sorted Array

- Archived(I); 20230110

An interesting Binary Search Problem. The pivot value will always be at the first, and I used that value to determine the search direction.

---

## Leetcode.46. Permutation

- Independently solved; 20230802

Similar to the Problem about Combination, I used DFS to solve it, but instead of passing the index of a previously selected element, I passed an integer to track which numbers have been selected.

---

## Leetcode.50. Pow(x, n)

- Independently solved; 20230724

The standard quick power algorithm would solve the problem with a small modification for the negative n. A corner case is that the min integer can't flip to the max integer.

---

## Leetcode.63. Unique Path II

- Archived; 20220818

I used dynamic programming to solve it. I guess I can use a 1-d array to represent the dp table now.

---

## Leetcode.74. Search A 2d Matrix

- Independently solved; 20220906

A Binary Search would solve this problem, using an 1-d representation of the index of the 2-d matrix.

---

## Leetcode.77. Combinations

- Independently solved; 20230801

I used DFS to solve this problem, using a path vector to track the current selection and pushing it to the answer vector when all k integers are selected.

---

## Leetcode.81. Search In Rotated Sorted Array II

- Independently solved(based on LC.33); 20230810

I still used Binary Search to solve this problem but with one alternation. When the "mid_value" is equal to the "pivot_value", the target could be at either side of the "mid_value."

---

## Leetcode.86. Partition List

- Independently solved; 20230815

I used two lists to store the partitioned nodes and merged the lists at the end. I think using a pointer pointing to the middle of the list as the head of the second list would also work, but it's harder to manage the cases.

---

## Leetcode.95. Unique Binary Search Tree II

- Archived; 20220817

Recursively combining the results of subproblems solve the problem. I guess this can be accelerated by a DP table, which I was not familiar with at the time I solved it.

---

## Leetcode.97. Interleaving String

- Learned from solution; 20220825

A Dynamic Programming question. The cell at the ith row and jth column of the table represents whether the substring with length i of the first string and the substring with length j of the second string can be interleaved by the third string.

---

## Leetcode.135. Candy

- Independently solved; 20230913

I used the updatable topology priority queue from my Graph-Layout project to solve this problem. I got a one-pass!!! (faster than 5% hahahaha)

---

## Leetcode.137. Single Number II

- Independently solved; 20230704

Similar to the previous Single Number I, every bit will be flipped 3n + 1 times. I need to make those numbers that occurred three times cancel with themselves, and therefore I used a ternary integer consisting of two binary integers to solve this problem.

---

## Leetcode.138. Copy List with Random Pointer

- Independently solved; 20230904

I used a map to record the mapping between old and new copied list nodes. An interesting problem.

---

## Leetcode.139. Word Break

- Learned from solution; 20230803

At first, I tried to solve it, recursively searching from the beginning with a Prefix tree. Then, I learned how to apply Dynamic Programming to this context while still using a Prefix tree: at each index, trying to find a word to fit in from behind while the substring at the front is still word-breakable.

---

## Leetcode.146. LRU Cache

- Independently solved(check previous LFU cache); 20230718

I used a doubly-linked list to solve this. DDL can move any known element to the front of the list and pop an element at the back of the list in constant time. To solve those problems with complexity requirements, I need to find out data structures with smaller time complexities.

---

## Leetcode.207. Course Schedule

- Independently solved; 20230713

Similar to the previous daily problem [Leetcode.802](#leetcode802-find-eventual-safe-states), using a degree array to track the in-ward edges and pushing the "unlocked" nodes to a BFS queue can solve this problem.

---

## Leetocde.209. Minimum Size Subarray Sum

- Independently solved; 20230706

A slide window problem. The idea is to calculate the minimum length of valid subarrays starting from each index, and the length of valid subarrays will never shrink when all numbers in the array are positive.

---

## Leetcode.215. Kth Largest Element in an Array

- Independently solved; 20230814

I have always being thinking about using the heap idea to sort an array inplace. It indeed works.

---

## Leetcode.225. Implement Stack using Queues

- Independently solved; 20220814

You can re-push poped out elements into the queue util the "top"(tail) one is reached.

---

## Leetcode.228. Summary Ranges

- Unknown, probably Independently solved; 20220814

Simply looping through the vector and keeping track of continuous numbers.

---

## Leetcode.239. Sliding Window Maximum

- Independently solved, but slow; 20230816

I used a map to calculate the maximum value in range, the right-most node always store the largest value.

---

## Leetcode.332. Reconstruct Itinerary

- Learned from solution; 20230914

With my summer experience of reading MTX graph files, I think mapping strings to integers is a good approach for performance improvement.

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

## Leetcode.377. Combination Sum IV

- Independently solved; 20230908

A dynamic programming problem. The combination sum of target is the sum of combination sums of subproblems of all target minus numbers stored in nums. But, I think actually the author recommends using a top-down approach because some numbers other than the target might have super large values compared to the combination sum of the target.

---

## Leetcode.399. Evaluate Division

- Independently solved; 20230520

Not completely sure how I managed to solve it independently. I'm just having a intuition that all variables can link to a "base" variable and use it to quickly calculate the answer to queries. Therefore, I think a modified version of union-find algorithm would be useful.

---

## Leetcode.403. Frog Jump

- Learned from solution; 20230826

I think I should be able to solve it independently, but today is Saturday. A Dynamic Programming problem. The key point is to use the previous index of the previous stone to record the previous distance of jump.

---

## Leetcode.435. Non-overlapping Intervals

- Learned from solution; 20230719

Sorting the intervals first is the key to solve this problem.

---

## Leetcode.445. Add Two Numbers II

- Independently solved (read the follow up); 20230717

First reverse the number list, and then add them up with a carry number.

---

## Leetcode.459. Repeated Substring Pattern

- Independently solved; 20230820

A string problem. My solution is looping through all the possible length of substring and checking if its the correct substring.

---

## Leetcode.486. Predict The Winner

- Independently solved; 20230728

Dynamic Programming solves this problem. I used a 2D array to represent the difference between the scores of the first-hand player and the second player of each game state.

---

## Leetcode.518. Coin Change II

- Independently solved; 20230811

I used Dynamic Programming to solve this problem. Be careful with the duplicated cases since the question is asking for the number of combinations.

---

## Leetcode.530. Minimum Absolute Difference in BST

- Independently solved; 20230614

Textbook Binary Search Tree in order traversal (and keeping track of the previous element). (No need to calculate the absolute value)

---

## Leetcode.542. 01 Matrix

- Independently solved; 20230817

A textbook "BFS from multiple starting point" problem.

---

## Leetcode.547. Number Of Provinces

This problem is about counting the connected component of a graph. I used Union Find to solve it. BFS would also work.

---

## Leetcode.646. Maximum Length of Pair Chain

- Independently solved; 20230825

A Dynamic Programming problem. I used a DP array to keep track of the length of the chain end at the pair at that index. Sort the pairs beforehand, and then loop through the pairs to see if a pair can be concatenated behind another pair.

---

## Leetcode.664. Strange Printer

- Learned from soluion; 20230730

I used dynamic programming to solve this problem. The key to solving this problem is combining the results of several sub-problems.

---

## Leetcode.673. Number Of Longest Increasing Subsequence

- Independently solved; 20230721

An upgraded Dynamic Programming technique from the Length of the Longest Increasing Subsequence. Instead of only keeping track of the length at each index, also tracking the number of subsequences with that length solves the problem.

---

## Leetcode.688. Knight Probability In Chessboard

- Independently solved; 20230722

Recursion with dynamic programming would solve the problem. I also used the symmetry of the board to accelerate the process.

---

## Leetcode.703. Kth Largest Element In A Stream

- Independently solved; 20230523

I used a map, a binary search tree, to solve this problem. This question is a good practice for iterators.

---

## Leetcode.712. Minimum ASCII Delete Sum for Two Strings

- Hinted from hints; 20230731

I used a bottom-up DP array which each element tracks the minimum ASCII to match the two substrings from the original strings to solve this problem.

---

## Leetcode.714. Best Time to Buy and Sell stock with Transaction fee

- Copied from solution; 20230622

Travelling and not understanding. I guess this a-few-line solution requires some math intuitive proofs to understand.

---

## Leetcode.735. Asteroid Collision

- Independently solved(learned to use stack); 20230720

Simulating the process by adding asteroids one by one solves this problem. But using an array and using zeros as an empty flag is too slow.

---

## Leetcode.744. Find Smallest Letter Greater Than Target

- Independently solved; 20230609

A textbook Binary Search question.

---

## Leetcode.785. Is Graph Bipartite

- Independently solved; 20230519

I used BFS to solve this problem. I forgot that the graphs might have multiple components at first, and then I added the outer for-loop to check through all graph components.

---

## Leetcode.802. Find Eventual Safe States

- Refined from solution; 20230712

I have considered a similar question about determining the winner of a small game. Maintaining a list of degrees to help check which state can be fully determined is very helpful for determining which state should be in-queued.

---

## Leetcode.808. Soup Servings

- Learned from solution (the 4600); 20230729

Top-down dynamic programming solves this problem. At first, I thought using DP to solve this problem was impossible because of the problem size.

---

## Leetcode.837. New 21 Game

- Independently solved (Hinted by Big O); 20230525

Following the main idea of the previous few days, this question also tests the concept of maintaining some data structure of a specific size, popping old elements when new elements arrive.

In this question, while also examing the basic idea of dynamic programming, the critical point is calculating the sum of probabilities of previously calculated information. To achieve that, instead of looping through, I use a circular queue to quickly calculate the sum of the previous "maxPts" number of probability. The circular queue allows me to update the sum of probabilities in constant time. You can maintain a sum in a variable, deduct the sum of the first element of the queue, and add the incoming new probability to quickly update the sum.

---

## Leetcode.852. Peak Index in a Mountain Array

- Independently solved (old); 20230101

A binary search problem.

---

## Leetcode.859. Buddy Strings

- Independently solved; 20230703

Handling the case of swapping identical characters is the key to solve this problem.

---

## Leetcode.863. All nodes distance K in Binary Tree

- Independently solved; 20230711

I first find the path of nodes to the target node and then trace back the track and BFS along the path while handling duplicated cases by memorizing the path direction.

---

## Leetcode.864. Shortest Path to Get All Keys

- Learned from solution; 20230629

The main takeaway from this question is the idea of putting other information like the currently obtained keys into the state of the BFS queue.

---

## Leetcode.894. All Possible Binary Tree

- Independently solved; 20220821

All full binary tree of size $n$ can be derived from all permutations of full left binary trees and full right binary trees that have a sum of size $n - 1$;

---

## Leetcode.920. Number of Music Playlists

- Independently solved; 20230806

A top-down DP would solve it. I actually didn't fully understand the details of the solution I have read. I modified it with my own understanding of the two subcases: listen to "new" songs or relisten old songs "k" songs before.

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

## Leetcode.1125. Smallest Sufficient Team

- Learned? from solution; 20230716

The key is how to update the dynamic programming array.

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

## Leetcode.1203. Sort Items By Groups Respecting dependencies

- Learned fro solution; 20230819

An interesting problem. Constructing extra nodes to group a group of nodes together is brilliant. I guess I can make a ton of graphs for my graph-layout algorithm.

---

## Leetcode.1218. Longest arithmetic Subsequence Of Given Difference

- Learned from solution (busy today); 20230714

A dynamic programming question. The maximum length ending at the current equals the maximum length ending at a previous element with the correct difference plus one.

---

## Leetcode.1231. Check If It Is A Straight Line

- Independently solved; 20230605

I constructed a direction struct to help me handle vertical cases.

---

## Leetcode.1282. Group the People Given the Group Size They Belong To

- Hinted; 20230910

I sorted the groupSizes along with their indices and group these indices together.

---

## Leetcode.1318. Minimum Flips To Make A or B Equal To C

- Independently solved; 20230607

My solution loops through every bit of a,b, and c and checks whether I need to flip some bits in a and/or b. This problem provides a good chance to practice bitwise manipulations.

---

## Leetcode.1326. Minimum Number of Taps to Open to Water a Garden

- Learned from solution; 20230830

A hard question during weekdays. I chose the DP approach. In the DP array, the value at index "i" represents the minimal value to cover this length. I loop through the taps and update the DP array. Note that the taps are sorted by nature to make this approach available.(I guess)

---

## Leetcode.1351. Count Negative Numbers In A sorted Matrix

- Independently solved; 20230608

Since the matrix is sorted from top left to bottom right, if we can find an element with a negative value, all elements from the bottom right area would be negative. So, we can start from the bottom left and follow along the "stairs" to get the number of negative numbers.

---

## Leetcode.1359. Count All Valid Pickup and Delivery Options

- Independently solved; 20230909

Given the previous number of valid options, you can insert the pick-up timeslot into 2 \* n + 1 and insert the delivery timeslot behind the pickup timeslot. And that leads to an arithmetic sum.

---

## Leetcode.1376. Time Needed To Inform All Employees

- Independently solved; 20230603

I used recursion to solve this problem. The time to inform a tree of employees equals inform time of the current head plus the maximum time for its sub-division heads to inform their employees.

---

## Leetcode.1489. Find Critical And Pseudo-critical edges in MST

- Hinted; 20230818

A good question to review the concept of MST and Union Find. The key is to tell whether an edge is critical or pseudo-critical by checking the MST value with or without that edge. Be careful with the case that the graph having multiple components after the removal of a certain edge.

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

## Leetcode.1584. Min Cost To Connect All Points

- Independently solved; 20230914

I used Minimum Spanning Tree with Union-Find and Priority Queue to solve this problem.

---

## Leetcode.1601. Maximum Number Of Achievable Transfer Requests

- Learned from solution; 20230702

I used Brute Force to iterate through all combinations of requests selection.

---

## Leetcode.1603. Design Parking System

- Independently solved; 20230529

It's a simple counting problem. Keeping track of the number of remaining parking slots for each type of car and deducting the number of available slots respectively are the keys to solving this problem.

---

## Leetcode.1615. Maximal Network Rank

- Independently solved; 20230817

A good problem with edge cases to clam down the maddness from a 30h long flight.

---

## Leetcode.1647. Minimum Deletions to Make Character Frequencies Unique

- Independently solved; 20230912

I would consider this problem a Dynamic Programming problem: when adding a new larger(or equal to) frequency to a valid array of frequencies, how will the result count change?

---

## Leetcode.1732. Find the Highest Altitude

- Independently solved; 20230619

Looping through the gains and calculating the absolute altitude.

---

## Leetcode.1751. Maximum Number Of Events that Can be Attended II

- Learned from solution(busy); 20230715

Dynamic programming. Using 1D arrays to represent rectangular 2D or more arrays seems to be more space and time efficient.

---

## Leetcode.1802. Maximum Value At A Given Index In A Bounded Array

- Independently solved; 20230610

This is a textbook Binary Search question. Be careful with integer overflows.

---

## Leetcode.1870. Minimum Speed to Arrive on Time

- Hinted; 20230726

This is another Binary Search question. The last trip is the most important one.

---

## Leetcode.1970. Last Day Where You Can Still Cross

- Independently solved (verified my idea through tags); 20230630

This is a textbook Union Find problem.

---

## Leetcode.2024. Maximize The Confusion Of An Exam

- Independently solved (checked hints but didn't understand); 20230707

My idea follows the core idea of my solution to the previous daily problem. I designed two pointers and let them keep tracking of the length and used swaps. But I need to first check the maximum length of only swapping Ts and then check the maximum length of only swapping Fs.

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

## Leetcode.2141. Maximum Running Time of N Computers

- Learned from solution; 20230727

Binary Search can solve this problem. The key is how to calculate whether a time is valid for the computers to run with given batteries.

---

## Leetcode.2272. Substring with Largest Variance

- Learned from solution; 20230709

This problem can be transformed into a form of the Largest Sum ContigUous Subarray problem. There are two difficulties. The variance is defined by differences instead of sums, and all pairs of characters must be looped through.

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

## Leetcode.2366. Minimum Replacements to Sort the Array

- Learned from solution; 20230829

A hard question during weekdays. Iterating through the nums from the end, I need to make sure that every element is smaller or equal to the previous one, and there is a way to calculate how to break down a num to smaller than a particular number.

---

## Leetcode.2369. Check If There Is A Valid Partition For the Array

- Independently solved; 20230813

A textbook Dynamic Programming problem. The key idea of DP is using the results of previous subproblems to get the answer for the current problem.

---

## Leetcode.2448. Minimum Cost To Make Array Equal

- Hinted(but had technical issues about MLE); 20230621

I independently figured out using prefix-sum to calculate the next cost sum in O(1). But it seems using a lambda function to sort the indices vector led to a Memory Limit Exceed.

---

## Leetcode.2462. Total Cost to Hire K Workers

- Independently solved; 20230626

I used priority queue to select the candidates with the lowest cost.

---

## Leetcode.2483. Minimum Penalty for a Shop

- Independently solved; 20230828

I used Prefix sum to quickly find out penalties for different closing hours and therefore the best hour.

---

## Leetcode.2542. Maximum Subsequent Score

- Learned from solution; 20230524

The basic idea is the same as Leetcode.703 from yesterday. You need to maintain some data structure of size k and pop something out when the size is over k.

---

## Leetcode.2551. Put Marbles In Bags

- Learned from solution; 20230708

This is an interesting problem. The core idea to solve this problem is the "stars and bars" idea from the CS173 course. One possible selection of subarrays can be defined by the pivots of subarrays.

## Leetcode.2616. Minimize The Maximum Difference Of Pairs

- Hinted (learned the Binary Search Solution)

The official hint told me to use DP, but it seems DP can't pass the final few testcases. Good question though. It helped me to practice DP with space optimization.

## Leetcode.2707. Extra CHaracters in a String

- Hinted; 20230901

Dynamic Programming Question: how can we build upon subproblems? With a new character in the string, we can search through the dictionary to see if we have something matched and then put the previous answer here.
