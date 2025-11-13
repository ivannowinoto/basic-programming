# B11107035 黃偉智
# 期末程式專案

import pygame, sys, random

class Fruit:

    def __init__(self):
        self.randomize_fruit()

    def spawn_fruit(self):
        fruit = pygame.Rect(int(self.position.x * cell_size), int(self.position.y * cell_size), cell_size, cell_size)
        window.blit(fruit_img, fruit)

    def randomize_fruit(self):
        self.x = random.randint(0, cell_amount - 1)
        self.y = random.randint(0, cell_amount - 1)
        self.position = pygame.math.Vector2(self.x, self.y)

class Snake:

    def __init__(self):
        self.body = [pygame.math.Vector2(5, 10), pygame.math.Vector2(4, 10), pygame.math.Vector2(3, 10)]
        self.direction = pygame.math.Vector2(0, 0)
        self.new_block = False

        self.head_up = pygame.image.load('python_snake/img/head_up.png').convert_alpha()
        self.head_down = pygame.image.load('python_snake/img/head_down.png').convert_alpha()
        self.head_right = pygame.image.load('python_snake/img/head_right.png').convert_alpha()
        self.head_left = pygame.image.load('python_snake/img/head_left.png').convert_alpha()
		
        self.tail_up = pygame.image.load('python_snake/img/tail_up.png').convert_alpha()
        self.tail_down = pygame.image.load('python_snake/img/tail_down.png').convert_alpha()
        self.tail_right = pygame.image.load('python_snake/img/tail_right.png').convert_alpha()
        self.tail_left = pygame.image.load('python_snake/img/tail_left.png').convert_alpha()

        self.body_vertical = pygame.image.load('python_snake/img/body_vertical.png').convert_alpha()
        self.body_horizontal = pygame.image.load('python_snake/img/body_horizontal.png').convert_alpha()

        self.body_tr = pygame.image.load('python_snake/img/body_tr.png').convert_alpha()
        self.body_tl = pygame.image.load('python_snake/img/body_tl.png').convert_alpha()
        self.body_br = pygame.image.load('python_snake/img/body_br.png').convert_alpha()
        self.body_bl = pygame.image.load('python_snake/img/body_bl.png').convert_alpha()

    def spawn_snake(self):
        self.head_graphics()
        self.tail_graphics()

        for index, new_block in enumerate(self.body):
            xpos = int(new_block.x * cell_size)
            ypos = int(new_block.y * cell_size)
            block_rect = pygame.Rect(xpos, ypos, cell_size, cell_size)

            if index == 0:
                window.blit(self.head, block_rect)
            elif index == len(self.body) - 1:
                window.blit(self.tail, block_rect)
            else:
                previous_block = self.body[index + 1] - new_block
                next_block = self.body[index - 1] - new_block
                if previous_block.x == next_block.x:
                    window.blit(self.body_vertical, block_rect)
                elif previous_block.y == next_block.y:
                    window.blit(self.body_horizontal, block_rect)
                else:
                    if previous_block.x == -1 and next_block.y == -1 or previous_block.y == -1 and next_block.x == -1:
                        window.blit(self.body_tl, block_rect)
                    if previous_block.x == -1 and next_block.y == 1 or previous_block.y == 1 and next_block.x == -1:
                        window.blit(self.body_bl, block_rect)
                    if previous_block.x == 1 and next_block.y == -1 or previous_block.y == -1 and next_block.x == 1:
                        window.blit(self.body_tr, block_rect)
                    if previous_block.x == 1 and next_block.y == 1 or previous_block.y == 1 and next_block.x == 1:
                        window.blit(self.body_br, block_rect)

    def head_graphics(self):
        head_range = self.body[1] - self.body[0]
        if head_range == pygame.math.Vector2(1, 0):
            self.head = self.head_left
        if head_range == pygame.math.Vector2(-1, 0):
            self.head = self.head_right
        if head_range == pygame.math.Vector2(0, 1):
            self.head = self.head_up
        if head_range == pygame.math.Vector2(0, -1):
            self.head = self.head_down

    def tail_graphics(self):
        tail_range = self.body[-2] - self.body[-1]
        if tail_range == pygame.math.Vector2(1, 0):
            self.tail = self.tail_left
        if tail_range == pygame.math.Vector2(-1, 0):
            self.tail = self.tail_right
        if tail_range == pygame.math.Vector2(0, 1):
            self.tail = self.tail_up
        if tail_range == pygame.math.Vector2(0, -1):
            self.tail = self.tail_down

    def move_snake(self):
        if self.new_block == True:
            copy_of_body = self.body[:]
            new_head = copy_of_body[0] + self.direction
            copy_of_body.insert(0, new_head)
            self.body = copy_of_body[:]
            self.new_block = False
        else:
            copy_of_body = self.body[:-1]
            new_head = copy_of_body[0] + self.direction
            copy_of_body.insert(0, new_head)
            self.body = copy_of_body[:]
        
    def add_length(self):
        self.new_block = True

class Main:

    def __init__(self):
        self.snake = Snake()
        self.fruit = Fruit()

    def update(self):
        self.snake.move_snake()
        self.check_eat()
        self.check_gameover()

    def spawn_elements(self):
        self.draw_bg()
        self.draw_score()
        self.fruit.spawn_fruit()
        self.snake.spawn_snake()

    def check_eat(self):
        if self.fruit.position == self.snake.body[0]:
            self.fruit.randomize_fruit()
            self.snake.add_length()

        for block in self.snake.body[1:]:
            if block == self.fruit.position:
                self.fruit.randomize_fruit()

    def check_gameover(self):
        if not 0 <= self.snake.body[0].x < cell_amount:
            self.restart_game()
        elif not 0 <= self.snake.body[0].y < cell_amount:
            self.restart_game()

        for block in self.snake.body[1:]:
            if block == self.snake.body[0]:
                self.restart_game()

    def restart_game(self):
        self.snake.body = [pygame.math.Vector2(5, 10), pygame.math.Vector2(4, 10), pygame.math.Vector2(3, 10)]


    def draw_bg(self):
        bg_color = (167, 209, 61)
        for row in range(cell_amount):
            if row % 2 == 0:
                for col in range(cell_amount):
                    if col % 2 == 0:
                        bg_rect = pygame.Rect(col * cell_size, row * cell_size, cell_size, cell_size)
                        pygame.draw.rect(window, bg_color, bg_rect)
            else:
                for col in range(cell_amount):
                    if col % 2 != 0:
                        bg_rect = pygame.Rect(col * cell_size, row * cell_size, cell_size, cell_size)
                        pygame.draw.rect(window, bg_color, bg_rect)

    def draw_score(self):
        score = str(len(self.snake.body) - 3)
        surface = game_font.render(score, True, (56, 74, 12))
        score_x = int(cell_size * cell_amount - 60)
        score_y = int(cell_size * cell_amount - 40)
        score_rect = surface.get_rect(center = (score_x, score_y)) 
        fruit_rect = fruit_img.get_rect(midright = (score_rect.left, score_rect.centery))
        bg_rect = pygame.Rect(fruit_rect.left, fruit_rect.top, fruit_rect.width + score_rect.width * 2, fruit_rect.height)

        pygame.draw.rect(window, (167, 209, 61), bg_rect )
        window.blit(surface, score_rect)
        window.blit(fruit_img, fruit_rect)
        pygame.draw.rect(window, (56, 74, 12), bg_rect, 2)

pygame.init()
cell_size = 40
cell_amount = 20
width_height = cell_size * cell_amount
window = pygame.display.set_mode((width_height, width_height))
time = pygame.time.Clock()
fruit_img = pygame.image.load('python_snake/img/apple.png').convert_alpha()
game_font = pygame.font.Font('python_snake/font/PoetsenOne-Regular.ttf', 25)

screen_update = pygame.USEREVENT
pygame.time.set_timer(screen_update, 150)

game = Main()

while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()
        if event.type == screen_update:
            game.update()
        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_UP:
                if game.snake.direction.y != 1:
                    game.snake.direction = pygame.math.Vector2(0, -1)
            if event.key == pygame.K_RIGHT:
                if game.snake.direction.x != -1:
                    game.snake.direction = pygame.math.Vector2(1, 0)
            if event.key == pygame.K_DOWN:
                if game.snake.direction.y != -1:    
                    game.snake.direction = pygame.math.Vector2(0, 1)
            if event.key == pygame.K_LEFT:
                if game.snake.direction.x != 1:
                    game.snake.direction = pygame.math.Vector2(-1, 0)

    window.fill((175, 215, 70))
    game.spawn_elements()
    pygame.display.update()
    time.tick(60)
