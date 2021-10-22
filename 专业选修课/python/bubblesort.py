arr = input().split(',')
arr = [int(i) for i in arr]
n = len(arr)

for i in range(1, len(arr)):
    for j in range(0, len(arr) - i):
        if arr[j] > arr[j + 1]:
            arr[j], arr[j + 1] = arr[j + 1], arr[j]
arr = str(arr)
print(arr)
# 2,6,8,9,1,6,
