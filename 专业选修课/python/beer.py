def sort_str(x):
    a = list(x)
    a.sort()
    return ''.join(a)


d = {}
tag = None
while True:
    tag = input()
    if tag == '00000':
        break
    ta = list(set(tag))
    temp = [sort_str(i + j) for i in ta for j in ta if i != j]
    for i in temp:
        d[i] = d[i] + 1 if i in d else 1
max = 0
key = 0
for i in d:
    if d[i] > max:
        max = d[i]
        key = i
print(key)
