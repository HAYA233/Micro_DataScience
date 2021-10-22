s = input()
letter = 0
number = 0
space = 0
other = 0
i = 0

while i < len(s):
    c = s[i]
    if c.isalpha():
        letter += 1
    elif c.isspace():
        space += 1
    elif c.isdigit():
        number += 1
    else:
        other += 1
    i += 1

print("letter={},number={},space={},other={}".format(letter, number, space, other))
