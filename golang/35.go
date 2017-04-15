package main

func searchInsert(nums []int, target int) int {
	l := len(nums)
	idx1 := sort.Search(l, func(i int) bool { return nums[i] >= target })
	idx2 := sort.Search(l, func(i int) bool { return nums[i] > target })

	if idx1 == l || nums[idx1] == target {
		return idx1
	} else {
		return idx2
	}
}
