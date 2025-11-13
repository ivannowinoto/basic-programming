# B11107035 黃偉智

sent = input('請輸入一行英文句子？')
sent.strip('.')
word = sent.split(' ')
print(word[::-1])