arr = input().split(",")
# arr = [int(i) for i in arr]
n = len(arr)


for i in range(n):
    for j in range(1, n):
        if i < j:
            print(str(arr[i]) + " " + str(arr[j]))
