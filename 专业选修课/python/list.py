import numpy as np
a = [1, 2, 3, 4, 5]
a = [i+1 for i in a]
b = [2, 3, 4, 5, 6]
c = np.array(a) + np.array(b)
print(list(c))
