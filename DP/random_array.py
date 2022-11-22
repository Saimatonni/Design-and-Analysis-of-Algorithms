from numpy import random
import sys
x = random.randint(100, size=(2, 100))
file_path = 'input.txt'
sys.stdout = open(file_path, "w")
print(x)