import numpy as np

a = np.random.randint(0, 500000, 500000)

np.savetxt('Five_hundred_thousand.txt', a, fmt='%d')
