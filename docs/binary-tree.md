# Binary Tree

## Table of content
- [1. Introduction](#1-introduction)
- [2. m-ary Tree](#2-m-ary-tree)
  - [2.1. Definitions](#21-definitions)

## 1. Introduction
The list is a sequential data structure. Operations over list implies sequential access and sequential elaboration time. In the worst case, the complessity is **O(N)**, which means a lot of time for big list structures.
To overcome the timing issues, you need to implement a linked data structure, which is useful to manage large amount of data.

## 2. M-ary Tree
Trees are the most used not sequential data structure.
Data is stored into **nodes**. Hierarchical relationships are defined by
**arcs**, which connect the nodes.

A [tree](https://en.wikipedia.org/wiki/Tree_(graph_theory)) is a [DAG](https://en.wikipedia.org/wiki/Directed_acyclic_graph) (Directed Acyclic Graph) such that:
1. exists a node called **root** which has degree of entry equal to zero (a node without a parent)
2. each other node has degree of entry equal to one

### 2.1. Definitions
- **leaves**: nodes with degree of exit equal to `0`
- **node level**: the length of the path from the root to the given node 
- **tree height**: the length of the longest path from the root to a leaf
- if an **arc** connects node `A` to node `B`, node `A` is called the **parent node** of `B`, which is called a **child node** (or direct descendant) of `A`

Since, in a tree, the degree of entry of each node is known beforehand, instead of **degree of exit** you can simply call it **degree**.

Consequently:
- there is exactly one path from root to any another nodes.
- except the root, all nodes have exactly one parent
- a father can have zero or more children
- among the children of a node there is an order that distinguishes the first node, the second node, etc (usually drawn from left to right).