n = eval(input())
l = input()

if len(l) % n > 0:
    l += ' ' * (n - len(l) % n)

for i in range(n):
    row = l[i::n]
    print(row[::-1])
