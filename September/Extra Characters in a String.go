package main

import (
	"fmt"
	"math"
	"strings"
)

func isInDictionary(s string, start, end int, dictionary []string) bool {
	substr := s[start : end+1]
	for _, word := range dictionary {
		if substr == word {
			return true
		}
	}
	return false
}

func minExtraChar(s string, dictionary []string) int {
	n := len(s)
	dp := make([]int, n+1)
	for i := range dp {
		dp[i] = math.MaxInt32
	}
	dp[0] = 0

	for i := 1; i <= n; i++ {
		dp[i] = dp[i-1] + 1
		for j := 0; j < i; j++ {
			if isInDictionary(s, j, i-1, dictionary) {
				if dp[j] < dp[i] {
					dp[i] = dp[j]
				}
			}
		}
	}

	return dp[n]
}