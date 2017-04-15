package main

func titleToNumber(s string) int {
	l := len(s)
	if l == 0 {
		return 0
	}
	chartonum := func(b rune) int {
		return int(b - 'A' + 1)
	}
	ans := 0
	for _, v := range s {
		ans = ans*26 + chartonum(v)
	}
	return ans
}
