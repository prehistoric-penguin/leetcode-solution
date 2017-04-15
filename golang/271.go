package main

func containsDuplicate(nums []int) bool {
	mp := make(map[int]int)
	for _, v := range nums {
		mp[v] += 1
	}
	for _, v := range mp {
		if v > 1 {
			return true
		}
	}
	return false
}

// --------------------
func containsDuplicate(nums []int) bool {
	sort.Ints(nums[:])

	n := len(nums)
	for i, v := range nums {
		if i == n-1 {
			return false
		}

		if v == nums[i+1] {
			return true
		}
	}

	return false
}
