x1 = 0
x2 = 1
for day in range(5, 1, -1):
    x1 = (x2 + 1)*2
    x2 = x1
print(x1)
