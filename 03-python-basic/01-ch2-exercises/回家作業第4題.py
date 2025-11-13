# B11107035 黃偉智
# 回家作業 第四題

amount = int(input("Enter the number of drinks you want to buy: "))

cans = amount % 12
dozen = int((amount - cans) / 12)

price = dozen * 200 + cans * 20
print("Total cost is", price)