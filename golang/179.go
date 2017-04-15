package main

// The golang version is 1.7
// this code gets compiling error
func largestNumber(nums []int) string {
	sort.Slice(nums, func(i, j int) bool {
		si := strconv.Itoa(nums[i])
		sj := strconv.Itoa(nums[j])

		return si+sj > sj+si
	})
	l := len(nums)
	if l != 0 && nums[0] == 0 {
		return "0"
	}
	strs := make([]string, l)
	for i, v := range nums {
		strs[i] = strconv.Itoa(v)
	}
	return strings.Join(strs, "")
}
