---
title: "Competetive Programming Learning Notes"
author: Zhifeng Wang
date: May 17th, 2023
geometry: "left=2cm,right=2cm,top=2cm,bottom=2cm"
output: pdf_document
---

# Leetcode

---

## Leetcode.785. Is Graph Bipartite

I used BFS to solve this problem. I forgot that the graphs might have multiple components at first, and then I added the outer for-loop to check through all graph components.

---

## Leetcode.1557. Minimum Number of Vertices to Reach All Nodes

At first, I thought I should try "Union Find" with "merging by size" or other similar ideas. But later, I figured out that I must include all the nodes with zero in-going edges and shouldn't include any nodes with in-going edges.