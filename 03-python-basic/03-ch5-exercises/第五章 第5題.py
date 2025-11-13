# 黃偉智 B11107035
# Chapter 5 Q5

for i in range(1, 1001):
    sum = 0
    for j in range(1, i):
        if i % j == 0:
            sum = sum + j
    if sum == i:
        print(i, "is a perfect number")
