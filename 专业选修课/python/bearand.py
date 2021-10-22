# coding=gbk
def sort(x):
    a = list(x)
    a.sort()
    return ''.join(a)


arr = {}
tag = None

while True:
    tag = input()
    if tag == '00000':
        break
    ta = list(set(tag))
    temp = [sort(i + j) for i in ta for j in ta if i != j]
    for i in temp:
        arr[i] = arr[i] + 1 if i in arr else 1

m = 0
key = 0
for i in arr:
    if arr[i] > m:
        m = arr[i]
        key = i
print(key)
