import random

inside_circle = 0

for i in range(1000000):
    x = random.uniform(-1, 1)
    y = random.uniform(-1, 1)
    if x * x + y * y <= 1:
        inside_circle += 1

pi = 4 * inside_circle / 1000000
print(f"估算的π值: {pi}")
