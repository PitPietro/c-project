# Binary Tree

## Table of content
- [1. Introduction](#1-introduction)
- [2. m-ary Tree](#2-m-ary-tree)

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

