# B11107035 黃偉智

students = set(['John', 'Mary', 'Tina', 'Fiona', 'Claire', 'Eva', 'Ben', 'Bill', 'Bert'])
pass_english = set(['John', 'Mary', 'Fiona', 'Claire', 'Ben', 'Bill'])
pass_math = set(['Mary', 'Fiona', 'Claire', 'Eva', 'Ben'])

print('英文與數學都及格', pass_english & pass_math)
print('數學不及格', students - pass_math)
print('英文及格與數學不及格', pass_english & (students - pass_math))
