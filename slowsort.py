from tkinter import *
from tkinter import ttk
import random
from slow import slowsort


window = Tk()
window.title("War never changes, neither does this array")
window.maxsize(1000, 700)
window.config(bg = '#FFFFFF')


data = []

def drawData(data, colorArray):
    canvas.delete("all")
    canvas_width = 800
    canvas_height = 400
    x_width = canvas_width / (len(data) + 1)
    offset = 4
    spacing = 2
    normalizedData = [i / max(data) for i in data]

    for i, height in enumerate(normalizedData):
        x0 = i * x_width + offset + spacing
        y0 = canvas_height - height * 390
        x1 = (i + 1) * x_width + offset
        y1 = canvas_height
        canvas.create_rectangle(x0, y0, x1, y1, fill='#0F5BED')

    window.update()

def generate():
    global data
    data = []
    for i in range(0, 100):
        random_value = random.randint(0, 1)
        data.append(random_value)

    drawData(data, ['#0F5BED' for x in range(len(data))])
    window.update()

def sort():
    global data
    slowsort(data, 0, (len(data) - 1), drawData)


UI_frame = Frame(window, width= 900, height=300, bg='#FFFFFF')
UI_frame.grid(row=0, column=0, padx=10, pady=5)

b1 = Button(UI_frame, text="Sort", command=sort, bg='#C4C5BF')
b1.grid(row=2, column=1, padx=5, pady=5)


b3 = Button(UI_frame, text="Generate Array", command=generate, bg='#C4C5BF')
b3.grid(row=2, column=0, padx=5, pady=5)

canvas = Canvas(window, width=800, height=400, bg='#FFFFFF')
canvas.grid(row=1, column=0, padx=10, pady=5)

window.mainloop()

