# B11107035 黃偉智
# 回家作業 第六題

sentence = input("Enter a sentence: ")

words = sentence.split()
print("Cutting the blank characters:", words)

sen = " ".join(words)
print("Combining the words with blank characters:", sen)

cap = [word.capitalize() for word in words]
cap_sen = " ".join(cap)
print("Capitalizing the initials of each word:", cap_sen)