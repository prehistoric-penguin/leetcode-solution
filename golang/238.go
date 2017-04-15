package main

func productExceptSelf(nums []int) []int {
	l := len(nums)
	vec := make([]int, l)
	vec[0] = 1

	for i := 1; i < l; i++ {
		vec[i] = nums[i-1] * vec[i-1]
	}

	calfromright := 1
	for i := l - 1; i >= 0; i-- {
		vec[i] *= calfromright
		calfromright *= nums[i]
	}

	return vec
}
