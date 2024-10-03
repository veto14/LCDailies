package main

import (
	"fmt"
	"math"
)

func minSubarray(nums []int, p int) int {
	totalSum := 0

	// Calculate the total sum of the array
	for _, num := range nums {
		totalSum += num
	}

	// Calculate remainder when total sum is divided by p
	remainder := totalSum % p

	// If the sum is already divisible by p, return 0
	if remainder == 0 {
		return 0
	}

	// HashMap to store prefix sums modulo p and their indices
	prefixMap := make(map[int]int)
	prefixMap[0] = -1 // Initialize for prefix sum of 0

	prefixSum := 0
	minLen := math.MaxInt32

	// Traverse through the array and compute prefix sums
	for i, num := range nums {
		prefixSum = (prefixSum + num) % p

		// Calculate target remainder that we want to find
		target := (prefixSum - remainder + p) % p

		// If the target remainder is found in the map, update the min length
		if idx, found := prefixMap[target]; found {
			minLen = min(minLen, i-idx)
		}

		// Update the map with the current prefix sum modulo p
		prefixMap[prefixSum] = i
	}

	// If the minLen is still MaxInt32, it means no valid subarray was found
	if minLen == math.MaxInt32 || minLen == len(nums) {
		return -1
	}
	return minLen
}

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func main() {
	// Test case
	nums := []int{8, 32, 31, 18, 34, 20, 21, 13, 1, 27, 23, 22, 11, 15, 30, 4, 2}
	p := 148

	// Expected output: 7
	fmt.Println(minSubarray(nums, p))
}
