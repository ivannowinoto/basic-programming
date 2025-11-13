user = {}

while True:
    course_name = str(input('Course name: '))
    score = int(input('Score: '))
    credit = int(input('Credits: '))

    user[course_name] = (score, credit)
    total_score = 0
    total_credit = 0

    for m in user.values():
        total_score += m[0]
        total_credit += m[1]
    
    average = total_score / total_credit

    print('Total score is', total_score)
    print('Total credit is', total_credit)
    print('Average score is', average)
    print('-----------------------------------------------')
    
    