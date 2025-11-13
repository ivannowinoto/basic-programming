# Week 3 Homework
# 黃偉智 B11107035

import random

class Hero:
    def __init__(self, HP):
        self.skill_1 = random.randint(100, 180)
        self.skill_2 = random.randint(100, 180)
        self.skill_3 = random.randint(100, 180)
        self.HP = HP
    
    def skill(self):
        print(f"Skill 1 base damage is {self.skill_1}.")
        print(f"Skill 2 base damage is {self.skill_2}.")
        print(f"Skill 3 base damage is {self.skill_3}.")

    def floatValue(self):
        return random.uniform(0.3, 1.5)

    def totalDmg(self, n, floatValue):
        if n == 1:
            total_dmg = self.skill_1 * floatValue
        elif n == 2:
            total_dmg = self.skill_2 * floatValue
        elif n == 3:
            total_dmg = self.skill_3 * floatValue
        else:
            total_dmg = 0
            print("Invalid input") 
        print(f"Damage inflicted by hero: {total_dmg}")   
        return total_dmg


class Devil:
    def __init__(self, HP, attack):
        self.HP = HP
        self.attack = attack

    def floatValue(self):
        return random.uniform(0.3, 1.5)

    def totalDmg(self, floatValue):
        total_dmg = self.attack * floatValue

        print(f"Damage inflicted by devil: {total_dmg}")
        return total_dmg


hero = Hero(100)        # creating a hero with 100HP
devil = Devil(1500, 10) # creating a devil with 1500HP and 10 attack points

print("-------- Skill Base Damage --------")
hero.skill()    # output each skill's damage

round = 1
while hero.HP > 0 and devil.HP > 0:
    print(f"\n-------- Round {round} --------")
    round = round + 1

    x = int(input("Enter skill number: "))
    if x > 3 or x < 1:
        print("Input invalid!")
        break
    
    hero_mtp = hero.floatValue()
    hero_damage = hero.totalDmg(x, hero_mtp)

    devil.HP -= hero_damage
    if devil.HP <= 0:
        print("Devil HP is now 0")
        print("-------- You win! --------")
        break
    else:
        print(f"Devil HP is now {devil.HP}")
        devil_mtp = devil.floatValue()
        devil_damage = devil.totalDmg(devil_mtp)
        hero.HP -= devil_damage

        if hero.HP <= 0:
            print("Hero HP is now 0")
            print("-------- You lose! --------")
        else:
            print(f"Hero HP is now {hero.HP}")
