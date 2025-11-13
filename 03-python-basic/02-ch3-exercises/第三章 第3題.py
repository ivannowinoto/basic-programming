# B11107035 黃偉智

s1 = '紅豆生南國，春來發幾枝？願君多采擷，此物最相思。'
s2 = '春眠不覺曉，處處聞啼鳥。夜來風雨聲，花落知多少。'

set1 = set(s1)
set1.remove('，')
set1.remove('。')
set1.remove('？')

set2 = set(s2)
set2.remove('，')
set2.remove('。')

print(set1 & set2)

# B11107035 黃偉智

# s1 = "Mr. Smith called you last night, right?"
# s2 = "No, he called my brother."

# set1 = set(s1)
# set1.remove(',')
# set1.remove('.')
# set1.remove('?')

# set2 = set(s2)
# set2.remove(',')
# set2.remove('.')

# print(set1 & set2)