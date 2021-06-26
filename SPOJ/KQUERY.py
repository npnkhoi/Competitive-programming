
INF = 1e9

def build_tree(node_index, left, right):
	if left == right: # base case
		# print('a left', left, node_index)
		segment[node_index] = a[left] # or a[right], the same
	else:
		middle_position = (left + right) // 2

		# First, calculate the two children
		build_tree(node_index * 2, left, middle_position)
		build_tree(node_index * 2 + 1, middle_position + 1, right)

		# ... then 'combine' the result for the current node
		segment[node_index] = min(segment[node_index * 2], segment[node_index * 2 + 1])

def query(node_index, left_of_node, right_of_node, left_of_query, right_of_query):
	if left_of_query <= left_of_node and right_of_node <= right_of_query:
		return segment[node_index]
	elif right_of_query < left_of_node or right_of_node < left_of_query:
		return INF
	else:
		middle_position = (left_of_node + right_of_node) // 2
		left_answer = query(node_index * 2, left_of_node, middle_position, left_of_query, right_of_query)
		right_answer = query(node_index * 2 + 1, middle_position + 1, right_of_node, left_of_query, right_of_query)
		return min(left_answer, right_answer)


if __name__ == "__main__":
	n = int(input())
	a = list(map(int, input().split()))
	segment = [1] * (n*4)

	build_tree(node_index=1, left=0, right=n-1)

	m = int(input())
	query = []
	for _ in range(m):
		i, j, k = map(int, input().split())
		query.append((k, i, j))
	sort(query)
	