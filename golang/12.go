package main

func intToRoman(num int) string {
	kroman := []string{
		"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX",
		"V", "IV", "I",
	}
	knums := []int{
		1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1,
	}

	ans := ""
	for i := 0; num > 0; i++ {
		count := num / knums[i]
		num = num % knums[i]
		for {
			if count--; count < 0 {
				break
			}
			ans += kroman[i]
		}
	}

	return ans
}
