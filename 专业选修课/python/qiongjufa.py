for x in range(0, 101):
    for y in range(0, 101):
        for z in range(0, 101):
            if 3*x + 5*y + 6*z == 100:
                print("x={},y={},z={}\n".format(x, y, z))
