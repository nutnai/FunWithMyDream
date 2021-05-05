from googletrans import Translator
import pyautogui
from PIL import Image
from pytesseract import pytesseract
from time import sleep
from pyscreenshot import grab
import pygame
import mouse

pytesseract.tesseract_cmd = r'D:\Python\program_ad-on\Tesseract-OCR\tesseract.exe'
translator = Translator()
pygame.display.init()
pygame.display.set_mode((200,200))

def _lineNotify(payload,file=None):
    import requests
    url = "https://notify-api.line.me/api/notify"
    token = 'ck9roZLBmnmoFTcGc9bQgs6yenpCbiP8zbGmIcGzZgg'
    headers = {'Authorization':'Bearer '+token}
    return requests.post(url, headers=headers , data = payload, files=file)

def lineNotify(message):
    payload = {'message':message}
    return _lineNotify(payload)

def input():
    a1 = pyautogui.position().x
    a2 = pyautogui.position().y
    sleep(0.2)
    while True:
        b1 = pyautogui.position().x
        b2 = pyautogui.position().y
        if mouse.is_pressed(button='middle'):
            break
    temp1 = a1
    temp2 = a2
    if b2-a2<0 and b1-a1<0:
        a1 = b1
        a2 = b2
        b1 = temp1
        b2 = temp2
    elif b2-a2>0 and b1-a1<0:
        a1 = b1
        b1 = temp1
    elif b2-a2<0 and b1-a1>0:
        a2 = b2
        b2 = temp2

    grab(bbox=(a1,a2,b1,b2)).save('screen.png')
    screen = Image.open('screen.png')
    """
    display = pygame.display.set_mode(screen.size)
    showimage = pygame.image.load('screen.png')
    display.blit(showimage, (0, 0))
    pygame.display.update()
    """
    vocab = pytesseract.image_to_string(screen)
    sent = '\n' + vocab + "\n" + translator.translate(vocab,dest='th').text
    lineNotify(sent)

key = 'ctrl'
while True:
    if mouse.is_pressed(button='middle'):
        input()
    for event in pygame.event.get():
        if event.type == pygame.QUIT: exit()
