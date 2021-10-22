count = 0
sum = 0
a = eval(input())
while a != 0:
    if a % 3 != 0:
        count = count + a
    a = eval(input())
print(count)
