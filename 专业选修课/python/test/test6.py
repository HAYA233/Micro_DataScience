a = list(eval(input()))
b = eval(input())
temp = a[0::2]
temp.sort(reverse=True)
a[0::2] = temp
print(a)
