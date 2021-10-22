num = int(input())
string = input()
while len(string)%num != 0:
    string += ' '
sum_number = len(string)//num
mylist = list()
for i in range(sum_number):
    myslice = string[i*num:(i+1)*num]
    mylist.append(myslice)

mylist = list(reversed(mylist))

result_list = list(zip(*mylist))

for i in result_list:
    for index, j in enumerate(i):
        if index == len(i)-1:
            print(j)
        else:
            print(j, end='')
