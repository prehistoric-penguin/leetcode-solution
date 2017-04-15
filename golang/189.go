package main

func reverse(a []int) {
	for i := len(a)/2 - 1; i >= 0; i-- {
		opp := len(a) - 1 - i
		a[i], a[opp] = a[opp], a[i]
	}
}

func rotate(nums []int, k int) {
	l := len(nums)
	k = k % l

	if k == 0 {
		return
	}

	k = l - k

	reverse(nums[:k])
	reverse(nums[k:])
	reverse(nums)
}
