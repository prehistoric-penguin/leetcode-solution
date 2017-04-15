package main

func searchRange(nums []int, target int) []int {
	idx1 := sort.Search(len(nums), func(i int) bool { return nums[i] >= target })
	idx2 := sort.Search(len(nums), func(i int) bool { return nums[i] > target })

	fmt.Println(idx1, idx2)
	l := len(nums)

	if idx1 == l || nums[idx1] != target {
		return []int{-1, -1}
	}

	return []int{idx1, idx2 - 1}
}
