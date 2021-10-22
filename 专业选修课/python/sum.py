count = 0
a = input()
while a not in ['n', 'N']:
    count += int(a)
    a = input()
print(count)
