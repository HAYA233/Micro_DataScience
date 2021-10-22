n = input()
letter, number, space, other = 0, 0, 0, 0

for i in n:
    if (i >= 'a' and i <= 'z') or (i >= 'A' and i<= 'Z'):
        letter += 1
    elif i in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']:
        number += 1
    elif i == ' ':
        space += 1
other = len(n)-letter-number-space
print('letter=%d,number=%d,space=%d,other=%d' % (letter, number, space, other))
