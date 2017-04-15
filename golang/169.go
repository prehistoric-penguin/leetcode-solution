package main

// Better to implement a nth_element function here,
// to avoid a full array sort
func majorityElement(nums []int) int {
	sort.Ints(nums)

	return nums[len(nums)/2]
}
