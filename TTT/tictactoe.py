import pygame

pygame.init()

#ตั้งขนาดจอของเกม
screen = pygame.display.set_mode((600,600))

#ตั้งชื่อที่แสดงแถบข้างบนเกม
pygame.display.set_caption("Tic Tac Toe")

#ดึงภาพเข้ามาในโปรแกรม
icon_image = pygame.image.load("D:\code\Pyrhon\Pygame\TTT\Logo.png")
Table_image = pygame.image.load("D:\code\Pyrhon\Pygame\TTT\Table.png")
cross_image = pygame.image.load("D:\code\Pyrhon\Pygame\TTT\cross.png")
circle_image = pygame.image.load("D:\code\Pyrhon\Pygame\TTT\circle.png")


#ตั้งไอคอนเกม
pygame.display.set_icon(icon_image)


Running = True
Table = [[0,0,0],[0,0,0],[0,0,0]]
screen.blit(Table_image,(0,0))
Player = 1
show = int()
Playing = True
#################################################################### function

def Refresh():
    global Running
    global Table
    global Player
    global show
    global Playing
    Running = True
    Table = [[0,0,0],[0,0,0],[0,0,0]]
    Player = 1
    show = int()
    Playing = True

    screen.blit(Table_image,(0,0))

def MousePoCheck2(x):
    #y
    if 144 <= mousePo[1] <= 215:
            return x+0
    elif 224 <= mousePo[1] <= 305:
            return x+3
    elif 314 <= mousePo[1] <= 394:
            return x+6

def MousePoCheck():
    #x
    if 144 <= mousePo[0] <= 239:
        return MousePoCheck2(1)
    elif 247 <= mousePo[0] <= 344:
        return MousePoCheck2(2)
    elif 352 <= mousePo[0] <= 447:
        return MousePoCheck2(3)

def Define(Po):
    print(Po)
    global Player
    if Po == 1 : 
        if Table[0][0] == 0: 
            Table[0][0] = Player 
        else: return False
    elif Po == 2 : 
        if Table[0][1] == 0: 
            Table[0][1] = Player 
        else: return False
    elif Po == 3 : 
        if Table[0][2] == 0: 
            Table[0][2] = Player 
        else: return False
    elif Po == 4 : 
        if Table[1][0] == 0: 
            Table[1][0] = Player 
        else: return False
    elif Po == 5 : 
        if Table[1][1] == 0: 
            Table[1][1] = Player 
        else: return False
    elif Po == 6 : 
        if Table[1][2] == 0: 
            Table[1][2] = Player 
        else: return False
    elif Po == 7 : 
        if Table[2][0] == 0: 
            Table[2][0] = Player 
        else: return False
    elif Po == 8 : 
        if Table[2][1] == 0: 
            Table[2][1] = Player 
        else: return False
    elif Po == 9 : 
        if Table[2][2] == 0: 
            Table[2][2] = Player 
        else: return False

    if Player == 1:
        Player = 2
    else:
         Player = 1
    return True

def KeyCheck():
    for event in pygame.event.get():
        if Playing:
            if event.type == pygame.MOUSEBUTTONDOWN:
                global mousePo
                mousePo = pygame.mouse.get_pos()
                if Define(MousePoCheck()):
                    Display()
                    WinCheck()

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_r:
                print("Refresh")
                Refresh()
                Display()
        if event.type == pygame.QUIT:
            print("out")
            global Running
            Running = False

def Draw3(Po):
    if Po == 1 : return PlayerDraw((162,151))
    elif Po == 2 : return PlayerDraw((265,151))
    elif Po == 3 : return PlayerDraw((370,151))
    elif Po == 4 : return PlayerDraw((162,231))
    elif Po == 5 : return PlayerDraw((265,231))
    elif Po == 6 : return PlayerDraw((370,231))
    elif Po == 7 : return PlayerDraw((162,321))
    elif Po == 8 : return PlayerDraw((265,321))
    elif Po == 9 : return PlayerDraw((370,321))

def PlayerDraw(Po):
    global show
    if show - 1:
        screen.blit(cross_image,Po)
    else:
        screen.blit(circle_image,Po)

def Draw2(x,y):
    if y == 0:
        Draw3(x+1)
    elif y == 1:
        Draw3(x+2)
    elif y == 2:
        Draw3(x+3)

def Draw(x,y):
    if x == 0:
        Draw2(0,y)
    elif x == 1:
        Draw2(3,y)
    elif x == 2:
        Draw2(6,y)

def Display():
    print(Table)
    for x in range(0,3,1):
        for y in range(0,3,1):
            global show
            show = Table[x][y]
            if show:
                Draw(x,y)

def WinCheck():
    c = False
    global Playing
    if Table[0][0] and Table[0][1] and Table[0][2]:
        if Table[0][0] == Table[0][1] == Table[0][2] : c = True
    if Table[1][0] and Table[1][1] and Table[1][2]:
        if Table[1][0] == Table[1][1] == Table[1][2] : c = True
    if Table[2][0] and Table[2][1] and Table[2][2]:
        if Table[2][0] == Table[2][1] == Table[2][2] : c = True

    if Table[0][0] and Table[1][0] and Table[2][0]:
        if Table[0][0] == Table[1][0] == Table[2][0] : c = True
    if Table[0][1] and Table[1][1] and Table[2][1]:
        if Table[0][1] == Table[1][1] == Table[2][1] : c = True
    if Table[0][2] and Table[1][2] and Table[2][2]:
        if Table[0][2] == Table[1][2] == Table[2][2] : c = True

    if Table[0][0] and Table[1][1] and Table[2][2]:
        if Table[0][0] == Table[1][1] == Table[2][2] : c = True
    if Table[0][2] and Table[1][1] and Table[2][0]:
        if Table[0][2] == Table[1][1] == Table[2][0] : c = True
    
    if c:
        Playing = False
        if Player - 1:
            z = "O"
        else: 
            z = "X"
        print(z," win!")
        


#####################################################################Loop game
while Running:
    KeyCheck()
    pygame.display.update()

#####################################################################

