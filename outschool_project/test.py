import random
from unoframe import UnoFrame
import tkinter
from time import sleep
import asynctkinter as at

at.patch_unbind()
# from multiprocessing.pool import ThreadPool

# pool=ThreadPool(processes=2)
# import asyncio

# loop=asyncio.get_event_loop()

def print2(txt):
    f.addmessage(txt)

# def input(txt):
#     f.addmessage(txt)
#     f.clicked = False
#     r.after(100,)
#     r.update()
#     while True:
#         if f.clicked:
#             break
#     return f.inp()

async def wait_input():
    while True:
        # await asyncio.sleep(0.1)
        if f.clicked:
            if f.input_value is not None:
                break
    return f.input_value

async def input(text):
    print2(text)
    f.clicked = False
    f.input_value=None
    # with concurrent.futures.ThreadPoolExecutor() as executor:
    #     future = executor.submit(wait_input)
    #     return_value = future.result()
    # async_result=pool.apply_async(wait_input)
    # return_value= await async_result.get()
    return_value = await wait_input()
    return return_value
    # while True:
    #     await asyncio.sleep(0.1)
    #     if f.clicked:
    #         if f.input_value is not None:
    #             break
    # return f.input_value

class UnoFrame(tkinter.Frame):
    def __init__(self, r):
        tkinter.Frame.__init__(self, r)
        self.grid()

        # output box -----------------------------------------------------------
        self.text_area = tkinter.scrolledtext.ScrolledText(self,
                            width = 60, 
                            height = 16, 
                            font = ("Times New Roman",
                                    15))
  
        # self.text_area.grid(column = 0, pady = 10, padx = 10)
        self.text_area.pack()
        
        self.text_area.insert(tkinter.INSERT, "")
        
        self.text_area.configure(state ='disabled')

        # input box ------------------------------------------------------------
        self.input_box = tkinter.Entry(self)
        self.clicked = False
        self.confirm_button = tkinter.Button(self, text = "Confirm", command = self.on_click)
        
        # self.input_box.grid(row = 1, pady = 10, padx = 5)
        # self.confirm_button.grid(column = 1, row = 1, padx = 5, pady = 10)
        self.input_box.pack(side = tkinter.LEFT)
        self.confirm_button.pack(side = tkinter.LEFT)
        self.input_value=None

    def on_click(self):
        self.clicked = True
        self.input_value=(self.inp())

    def addmessage(self, txt):
        self.text_area.configure(state ='normal')
        self.text_area.insert(tkinter.INSERT, str(txt)+"\n")
        self.text_area.configure(state ='disabled')

    def inp(self):
        t = self.input_box.get()
        self.input_box.delete(0, len(t))
        return t

def udpate_print(inp):
    print2(inp+"hohoho")

async def main():
    while True:
        print2("try")
        # sleep(1)
        r.update()
        text=str(await input("one more"))
        # r.update()
        if "coroutine" not in text:
            print2(text+"hoho"+text)
        if text=="quit":
            exit(0)
    # r.after(1000,main)

# def main1():
#     asyncio.run(main())

if __name__ == "__main__":
    # Main game loop -------------------------------------------------------------------------------
    r = tkinter.Tk()
    f = UnoFrame(r)
    f.pack()
    at.start(main())
    # r.after(100, lambda: loop.run_until_complete(main()))
        # play_uno(2)
    r.mainloop()
    