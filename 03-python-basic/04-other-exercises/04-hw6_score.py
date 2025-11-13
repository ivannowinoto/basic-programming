import random

eng = {}
math = {}

n = int(input('Number of students: '))

for x in range(n):
    eng_score = random.randrange(0,100)
    if eng_score >= 60:
        eng[1100000 + x] = eng_score

    math_score = random.randrange(0,100)
    if math_score >= 60:
        math[1100000 + x] = math_score

set_eng = set(eng)
set_math = set(math)

print("There are", len(set_math & set_eng), "students who passed both English and Math:", (set_math & set_eng))
print("There are", len(set_math ^ set_eng), "students who passed either English or Math:", (set_math ^ set_eng))
print("There are", len(set_math - set_eng), "students who passed English:", (set_math - set_eng))
print("There are", len(set_eng - set_math), "students who passed Math:", (set_eng - set_math))
print("Pass rate of English:", len(set_eng) / n * 100, "%")
print("Pass rate of Math:", len(set_math) / n * 100, "%")
print("Pass rate of all subjects:", (len(set_eng) + len(set_math)) / 2 / n * 100, "%")



