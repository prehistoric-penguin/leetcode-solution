package main

type LRUCache struct {
	Data     *list.List
	Index    map[int]*list.Element
	Num      int
	Capacity int
}
type Pair struct {
	Key   int
	Value int
}

func Constructor(capacity int) LRUCache {
	cache := LRUCache{
		list.New(),
		make(map[int]*list.Element),
		0,
		capacity,
	}
	return cache
}
func (this *LRUCache) Get(key int) int {
	elem, ok := this.Index[key]
	if ok == false {
		return -1
	}
	this.SetMostRecent(elem)
	return elem.Value.(Pair).Value
}
func (this *LRUCache) Put(key int, value int) {
	elem, ok := this.Index[key]
	if ok == false {
		// full
		if this.Num == this.Capacity {
			delete(this.Index, this.Data.Front().Value.(Pair).Key)
			this.Data.Remove(this.Data.Front())
		} else {
			this.Num++
		}
		this.Data.PushBack(Pair{key, value})
		this.Index[key] = this.Data.Back()
	} else {
		elem.Value = Pair{key, value}
		this.SetMostRecent(elem)
	}
}
func (this *LRUCache) SetMostRecent(elem *list.Element) {
	d := this.Data
	d.MoveToBack(elem)
}
