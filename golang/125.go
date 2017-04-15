package main

func isPalindrome(s string) bool {
	buf := []byte(s)
	idx := 0
	l := len(buf)
	isalphnum := func(c byte) bool {
		return 'a' <= c && c <= 'z' || 'A' <= c && c <= 'Z' || '0' <= c && c <= '9'
	}
	for i := 0; i < l; i++ {
		if isalphnum(buf[i]) {
			buf[idx] = buf[i]
			idx++
		}
	}
	for i := idx/2 - 1; i >= 0; i-- {
		opp := idx - 1 - i
		if unicode.ToLower(rune(buf[i])) != unicode.ToLower(rune(buf[opp])) {
			return false
		}
	}
	return true
}
