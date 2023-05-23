---
title: "Competetive Programming Learning Notes"
author: Zhifeng Wang
date: May 17th, 2023
geometry: "left=2cm,right=2cm,top=2cm,bottom=2cm"
output: pdf_document
---

# Leetcode

---

## Leetcode.347. Top K Frequent Elements (Independently solved, but slow)

- 20230522

I used unordered map and priority queue to solve it.

---

## Leetcode.399. Evaluate Division (Independently solved)

- 20230520

Not completely sure how I managed to solve it independently. I'm just having a intuition that all variables can link to a "base" variable and use it to quickly calculate the answer to queries. Therefore, I think a modified version of union-find algorithm would be useful.

---

## Leetcode.785. Is Graph Bipartite (Independently solved)

- 20230519

I used BFS to solve this problem. I forgot that the graphs might have multiple components at first, and then I added the outer for-loop to check through all graph components.

---

## <span class="LC.703">Leetcode.703.</span> Kth Largest Element In A Stream (Independently solved)

- 20230523

I used a map, a binary search tree, to solve this problem. This question is a good practice for iterators.

---

## Leetcode.934. Shortest Bridge (Independently solved)

- 20230521

This question tests the idea of using BFS with multiple starting points. I first find a single starting point of one of the islands, identify all the nodes of the island, and finally use BFS with multiple starting points to find the distance between the two islands.

---

## Leetcode.1557. Minimum Number of Vertices to Reach All Nodes (Independently solved)

- 20230518

At first, I thought I should try "Union Find" with "merging by size" or other similar ideas. But later, I figured out that I must include all the nodes with zero in-going edges and shouldn't include any nodes with in-going edges.