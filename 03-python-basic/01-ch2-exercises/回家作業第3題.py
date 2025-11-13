# B11107035 黃偉智
# 回家作業 第三題

seat = int(input("Enter your seat number: "))

if (seat % 5 == 0):
    group = int(seat / 5)
else:
    group = int(seat / 5 + 1)

print("You are in Group", group)
