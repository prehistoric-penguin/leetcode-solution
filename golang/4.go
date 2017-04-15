package main

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
	l1 := len(nums1)
	l2 := len(nums2)
	l3 := l1 + l2
	nums3 := make([]int, len(nums1)+len(nums2))

	copy(nums3[:], nums1[:])
	copy(nums3[l1:], nums2[:])

	sort.Ints(nums3)

	mid := l3 / 2
	if l3%2 != 0 {
		return float64(nums3[mid])
	} else {
		return float64((nums3[mid-1] + nums3[mid])) / 2
	}
}
