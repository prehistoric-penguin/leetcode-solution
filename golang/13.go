package main

func romanToInt(s string) int {
	mapping := map[byte]int{
		'I': 1,
		'V': 5,
		'X': 10,
		'L': 50,
		'C': 100,
		'D': 500,
		'M': 1000,
	}
	pre := s[0]
	sum := mapping[pre]

	for i := 1; i < len(s); i++ {
		valcur := mapping[s[i]]
		valpre := mapping[pre]

		sum += valcur
		if valcur > valpre {
			sum -= (valpre * 2)
		}

		pre = s[i]
	}

	return sum
}
