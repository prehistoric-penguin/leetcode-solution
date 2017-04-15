package main

func missingNumber(nums []int) int {
	l := len(nums)
	ans := l
	for i, v := range nums {
		ans ^= i
		ans ^= v
	}

	return ans
}
