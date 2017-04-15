package main

func maxArea(height []int) int {
	max := func(i, j int) int {
		if i >= j {
			return i
		} else {
			return j
		}
	}
	min := func(i, j int) int {
		if i < j {
			return i
		} else {
			return j
		}
	}

	l := len(height)
	i := 0
	j := l - 1
	maxcap := 0

	for i < j {
		maxcap = max(maxcap, min(height[i], height[j])*(j-i))
		if height[i] > height[j] {
			j--
		} else {
			i++
		}
	}
	return maxcap
}
