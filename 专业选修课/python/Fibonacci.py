def Fibonacci(num):
    if num == 1:
        return 1
    elif num == 2:
        return 1
    else:
        return Fibonacci(num-1) + Fibonacci(num-2)


x = eval(input())
print(Fibonacci(x))
