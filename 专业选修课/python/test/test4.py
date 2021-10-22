def go(num):
    if num == 1:
        return 4
    else:
        return go(num-1)+2*num-1


n = eval(input())
print(go(n))
