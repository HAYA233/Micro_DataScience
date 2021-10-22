def divide_cake(num):
    if num == 1:
        return 2
    else:
        return divide_cake(num-1) + num


x = eval(input())
print(divide_cake(x))
