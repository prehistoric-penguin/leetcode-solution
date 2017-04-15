package main

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
type ListNodePtrHeap []*ListNode

func (h ListNodePtrHeap) Len() int           { return len(h) }
func (h ListNodePtrHeap) Less(i, j int) bool { return h[i].Val < h[j].Val }
func (h ListNodePtrHeap) Swap(i, j int)      { h[i], h[j] = h[j], h[i] }
func (h *ListNodePtrHeap) Push(x interface{}) {
	// Push and Pop use pointer receivers because they modify the slice's length,
	// not just its contents.
	*h = append(*h, x.(*ListNode))
}
func (h *ListNodePtrHeap) Pop() interface{} {
	old := *h
	n := len(old)
	x := old[n-1]
	*h = old[0 : n-1]
	return x
}
func mergeKLists(lists []*ListNode) *ListNode {
	dummy := ListNode{}
	tail := &dummy

	h := &ListNodePtrHeap{}
	heap.Init(h)

	for _, v := range lists {
		if v != nil {
			heap.Push(h, v)
		}
	}
	for h.Len() != 0 {
		top := heap.Pop(h)
		tail.Next = top.(*ListNode)
		tail = tail.Next

		if tail.Next != nil {
			heap.Push(h, tail.Next)
		}
	}
	tail.Next = nil
	return dummy.Next
}
