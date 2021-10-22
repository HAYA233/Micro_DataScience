list1=eval(input())
list2=list(set(list1))
list2.sort()
for i in list2:
    print(i)
