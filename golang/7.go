package main

func reverse(x int) int {
	ans := 0
	for {
		ans = ans*10 + x%10
		if x /= 10; x == 0 {
			break
		}
	}
	if ans < math.MinInt32 || ans > math.MaxInt32 {
		ans = 0
	}
	return ans
}
