import tkinter
import tkinter.scrolledtext

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
        self.confirm_button = tkinter.Button(self, text = "Confirm", command = self.clicked)
        
        # self.input_box.grid(row = 1, pady = 10, padx = 5)
        # self.confirm_button.grid(column = 1, row = 1, padx = 5, pady = 10)
        self.input_box.pack(side = tkinter.LEFT)
        self.confirm_button.pack(side = tkinter.LEFT)

    def clicked(self):
        self.clicked = True

    def addmessage(self, txt):
        self.text_area.configure(state ='normal')
        self.text_area.insert(tkinter.INSERT, str(txt)+"\n")
        self.text_area.configure(state ='disabled')

    def inp(self):
        t = self.input_box.get()
        self.input_box.delete(0, len(t))
        return t



if __name__ == "__main__":
    r = tkinter.Tk()
    f = UnoFrame(r)
    f.addmessage("afjekuhskjfbksjefksjbefkjfbskjebf")
    f.addmessage("akjsdhkasjdhk")
    f.mainloop()