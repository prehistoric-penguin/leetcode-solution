package main

/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func levelOrder(root *TreeNode) (ans [][]int) {
	if root == nil {
		return
	}

	queue := []*TreeNode{}
	queue = append(queue, root)
	queue = append(queue, nil)
	leveldata := []int{}

	for len(queue) != 0 {
		front := queue[0]
		queue = queue[1:]

		if front == nil {
			ans = append(ans, leveldata)
			leveldata = []int{}

			continue
		}

		leveldata = append(leveldata, front.Val)
		if front.Left != nil {
			queue = append(queue, front.Left)
		}
		if front.Right != nil {
			queue = append(queue, front.Right)
		}
		if len(queue) != 1 && queue[0] == nil {
			queue = append(queue, nil)
		}
	}
	return
}
