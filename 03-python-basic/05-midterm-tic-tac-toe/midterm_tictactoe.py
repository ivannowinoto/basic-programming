# B11107035 黃偉智
# 期中程式專案

from tkinter import *
import random

def next_turn(row, column):
    global player
    if buttons[row][column]['text'] == "" and check_winner() is False:
        if player == players[0]:
            buttons[row][column]['text'] = player
            if check_winner() is False:
                player = players[1]
                label.config(text = (players[1] + " turn"))
            elif check_winner() is True:
                label.config(text = ("Player " + players[0] + " wins!"))
            elif check_winner() == "Tie":
                label.config(text = "Tie!")
        else:
            buttons[row][column]['text'] = player
            if check_winner() is False:
                player = players[0]
                label.config(text = (players[0] + " turn"))
            elif check_winner() is True:
                label.config(text = ("Player " + players[1] + " wins!"))
            elif check_winner() == "Tie":
                label.config(text = "Tie!")

def check_winner():
    for row in range(3):
        if buttons[row][0]['text'] == buttons[row][1]['text'] == buttons[row][2]['text'] != "":
            buttons[row][0].config(bg = "#EE6677")
            buttons[row][1].config(bg = "#EE6677")
            buttons[row][2].config(bg = "#EE6677")
            return True
    for column in range(3):
        if buttons[0][column]['text'] == buttons[1][column]['text'] == buttons[2][column]['text'] != "":
            buttons[0][column].config(bg = "#EE6677")
            buttons[1][column].config(bg = "#EE6677")
            buttons[2][column].config(bg = "#EE6677")
            return True
    if buttons[0][0]['text'] == buttons[1][1]['text'] == buttons[2][2]['text'] != "":
        buttons[0][0].config(bg = "#EE6677")
        buttons[1][1].config(bg = "#EE6677")
        buttons[2][2].config(bg = "#EE6677")
        return True
    elif buttons[0][2]['text'] == buttons[1][1]['text'] == buttons[2][0]['text'] != "":
        buttons[0][2].config(bg = "#EE6677")
        buttons[1][1].config(bg = "#EE6677")
        buttons[2][0].config(bg = "#EE6677")
        return True
    elif empty_spaces() is False:
        for row in range(3):
            for column in range(3):
                buttons[row][column].config(bg = "#EE6677")
        return "Tie"
    else:
        return False

def empty_spaces():
    spaces = 9
    for row in range(3):
        for column in range(3):
            if buttons[row][column]['text'] != "":
                spaces -= 1
    if spaces == 0:
        return False
    else:
        return True

def restart():
    global player
    player = random.choice(players)
    label.config(text = player + " turn")
    for row in range(3):
        for column in range(3):
            buttons[row][column].config(text = "", bg = "#0C141D")

window = Tk()
window.title("Python Midterm Project: Tic-Tac-Toe")
window.geometry("600x725")
window.configure(bg = "#101B27")

players = ["X","O"]
player = random.choice(players)
buttons = [[0,0,0], [0,0,0], [0,0,0]]

label = Label(text = player + " turn", font = ('serif', 40, 'bold'), fg = "white", bg = "#101B27", pady = 25)
label.pack(side = "top")
reset_button = Button(text = "Restart game", font = ('serif', 19, 'bold'), fg = "white", command = restart, bg = "#18BC9C", padx = 5, pady = 5)
reset_button.pack(side = "bottom")

frame = Frame(window)
frame.pack()

for row in range(3):
    for column in range(3):
        buttons[row][column] = Button(frame, text = "", font = ('serif', 40, 'bold'), fg = "white", bg = "#0C141D", width = 5, height = 2, command = lambda row = row, column = column: next_turn(row, column))
        buttons[row][column].grid(row = row, column = column)

window.mainloop()