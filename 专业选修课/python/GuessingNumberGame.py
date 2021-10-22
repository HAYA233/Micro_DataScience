import random
random.seed(125)
num = random.randint(0, 100)
N = 0

while True:
    try:
        x = eval(input("Please input:"))
    except:
        print("Please input integer!")
        continue
    N += 1
    if x > num:
        print("Too big! ")
    elif x < num:
        print("Too small!")
    else:
        print(N, " times,you got it!")
        break
