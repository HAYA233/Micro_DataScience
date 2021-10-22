import random
num = eval(input())
count = 0

for i in range(1, num+1):
    x = random.uniform(0, 3)
    y = random.uniform(0, 9)
    if x*x >= y:
        count = count + 1

value = 27 * count / num
print("{:.1f}".format(value))
