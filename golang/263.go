package main

func isUgly(num int) bool {
	div := func(val *int, to_div int) {
		for {
			if *val == 0 || *val%to_div != 0 {
				break
			}
			*val /= to_div
		}
	}
	div(&num, 2)
	div(&num, 3)
	div(&num, 5)

	return num == 1
}
