package main

import (
	"fmt"
	"strconv"
)

type TrieNode struct {
	children map[rune]*TrieNode
}

func newTrieNode() *TrieNode {
	return &TrieNode{children: make(map[rune]*TrieNode)}
}

func buildTrie(arr []int) *TrieNode {
	root := newTrieNode()
	for _, num := range arr {
		node := root
		for _, ch := range strconv.Itoa(num) {
			if node.children[ch] == nil {
				node.children[ch] = newTrieNode()
			}
			node = node.children[ch]
		}
	}
	return root
}

func longestCommonPrefixLength(trie1, trie2 *TrieNode) int {
	maxLen := 0
	var dfs func(node1, node2 *TrieNode, length int)
	dfs = func(node1, node2 *TrieNode, length int) {
		if node1 == nil || node2 == nil {
			return
		}
		if length > maxLen {
			maxLen = length
		}
		for ch, child1 := range node1.children {
			if child2, exists := node2.children[ch]; exists {
				dfs(child1, child2, length+1)
			}
		}
	}
	dfs(trie1, trie2, 0)
	return maxLen
}

func longestCommonPrefix(arr1, arr2 []int) int {
	trie1 := buildTrie(arr1)
	trie2 := buildTrie(arr2)
	return longestCommonPrefixLength(trie1, trie2)
}