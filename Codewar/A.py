def ascArrayTransformSteps(arr):
	n = len(arr)
	res = 0
	for i in range(1, n):
		if arr[i - 1] >= arr[i]:
			arr[i] = arr[i - 1] + 1
			res += 1
	return res

# print(ascArrayTransformSteps([1, 2, 1]))