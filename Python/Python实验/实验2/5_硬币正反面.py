import random

heads = 0
tails = 0

for i in range(1000000):
    if random.randint(0, 1) == 0:
        heads += 1
    else:
        tails += 1

print(f"正面次数: {heads}")
print(f"反面次数: {tails}")
