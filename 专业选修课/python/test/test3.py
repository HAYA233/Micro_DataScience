import random
count = 0
result = 0
num = eval(input())
for i in range(num+1):
    x = random.uniform(2, 5)
    y = random.uniform(0, 150)
    if x**3-1<=y:
        count = count+1
result = 0.5 * 450 * count / num
print(int(result))
