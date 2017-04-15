package main

type Byte []byte

func (b Byte) Len() int {
	return len(b)
}

func (b Byte) Less(i, j int) bool {
	if b[i] < b[j] {
		return true
	} else {
		return false
	}
}

func (b Byte) Swap(i, j int) {
	b[i], b[j] = b[j], b[i]
}

func isAnagram(s string, t string) bool {
	bs := Byte(s)
	bt := Byte(t)

	sort.Sort(bs)
	sort.Sort(bt)

	return reflect.DeepEqual(bs, bt)
}
