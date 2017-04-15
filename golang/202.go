package main

func isHappy(n int) bool {
	visited := make(map[int]int)
	for n != 1 && visited[n] == 0 {
		visited[n] += 1
		tmp := 0
		for n != 0 {
			tmp += (n % 10) * (n % 10)
			n /= 10
		}
		n = tmp
	}
	return n == 1
}
