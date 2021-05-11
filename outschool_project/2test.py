
import tkinter
import tkinter.scrolledtext
import threading
import time
import asyncio


def print2(txt):
    f.addmessage(txt)


def input(text):
    print2(text)
    f.clicked = False
    f.input_value = None
    while True:
        if f.clicked:
            if f.input_value is not None:
                if len(f.input_value) > 0:
                    break
    return f.input_value


class UnoFrame(tkinter.Frame):

    def __init__(self, r):
        tkinter.Frame.__init__(self, r)
        self.grid()

        # output box ----------------------------------------------------------
        self.text_area = tkinter.scrolledtext.ScrolledText(self,
                                                           width=60,
                                                           height=16,
                                                           font=("Times New Roman",
                                                                 15))

        # self.text_area.grid(column = 0, pady = 10, padx = 10)
        self.text_area.pack()

        self.text_area.insert(tkinter.INSERT, "")

        self.text_area.configure(state='disabled')

        # input box -----------------------------------------------------------
        self.input_box = tkinter.Entry(self)
        self.clicked = False
        self.confirm_button = tkinter.Button(
            self, text="Confirm", command=self.on_click)

        # self.input_box.grid(row = 1, pady = 10, padx = 5)
        # self.confirm_button.grid(column = 1, row = 1, padx = 5, pady = 10)
        self.input_box.pack(side=tkinter.LEFT)
        self.confirm_button.pack(side=tkinter.LEFT)
        self.input_value = None

    def on_click(self):
        self.clicked = True
        self.input_value = (self.inp())

    def addmessage(self, txt):
        self.text_area.configure(state='normal')
        self.text_area.insert(tkinter.INSERT, str(txt) + "\n")
        self.text_area.configure(state='disabled')

    def inp(self):
        t = self.input_box.get()
        self.input_box.delete(0, len(t))
        return t

# def udpate_print(inp):
#     print2(inp+"hohoho")


def main():
    while True:
        print2("try")
        time.sleep(1)
        # r.update()
        # text = str(input("one more"))
        # r.update()
        # if "coroutine" not in text:
        # print2(text + "hoho" + text)
        # if text == "quit":
        #     r.quit()
        #     exit(0)


class App(threading.Thread):

    def __init__(self):
        threading.Thread.__init__(self)
        self.start()

    def callback(self):
        self.root.quit()

    def run(self):
        self.root = tkinter.Tk()
        self.root.protocol("WM_DELETE_WINDOW", self.callback)
        # set widgets ~~~~~~~~~~~~~~~~~~~~~~~
        self.frame = UnoFrame(self.root)
        self.frame.pack()
        ###############################
        print("start main loop")
        self.root.mainloop()


if __name__ == "__main__":

    app = App()
    time.sleep(0.5)
    r = app.root
    f = app.frame
    main()
