import tkinter as tk
from tkinter import messagebox, ttk
import math
import time

class KochApp:
    def __init__(self, root):
        self.root = root
        self.root.title("Flocon de Koch")

        # Couleurs disponibles
        self.colors = ["blue", "red", "green", "black", "purple", "orange"]
        
        # Création de la zone supérieure (contrôles)
        self.controls_frame = tk.Frame(root)
        self.controls_frame.pack(pady=5)

        tk.Label(self.controls_frame, text="Order:").grid(row=0, column=0)
        self.order_var = tk.IntVar(value=3)
        self.order_entry = tk.Entry(self.controls_frame, textvariable=self.order_var, width=5)
        self.order_entry.grid(row=0, column=1)

        self.keep_history = tk.BooleanVar()
        self.history_check = tk.Checkbutton(self.controls_frame, text="Keep History", variable=self.keep_history)
        self.history_check.grid(row=0, column=2)

        tk.Label(self.controls_frame, text="Color:").grid(row=0, column=3)
        self.color_var = tk.StringVar(value="blue")
        self.color_menu = ttk.Combobox(self.controls_frame, textvariable=self.color_var, values=self.colors, width=7)
        self.color_menu.grid(row=0, column=4)

        tk.Label(self.controls_frame, text="Speed:").grid(row=0, column=5)
        self.speed_var = tk.DoubleVar(value=1)
        self.speed_slider = tk.Scale(self.controls_frame, from_=0.1, to=6, resolution=0.1, orient=tk.HORIZONTAL, variable=self.speed_var)
        self.speed_slider.grid(row=0, column=6)

        # Zone de dessin (milieu)
        self.canvas = tk.Canvas(root, width=600, height=500, bg="white")
        self.canvas.pack()

        # Zone inférieure (boutons)
        self.buttons_frame = tk.Frame(root)
        self.buttons_frame.pack(pady=5)

        self.btn_exec = tk.Button(self.buttons_frame, text="Exécuter", command=self.draw_koch)
        self.btn_exec.pack(side=tk.LEFT, padx=5)

        self.btn_clear = tk.Button(self.buttons_frame, text="Effacer", command=self.clear_canvas)
        self.btn_clear.pack(side=tk.LEFT, padx=5)

        self.btn_apropos = tk.Button(self.buttons_frame, text="À propos", command=self.show_info)
        self.btn_apropos.pack(side=tk.LEFT, padx=5)

        self.btn_exit = tk.Button(self.buttons_frame, text="Quitter", command=self.quit_app)
        self.btn_exit.pack(side=tk.LEFT, padx=5)

    def draw_koch_segment(self, x1, y1, x2, y2, order):

        if order == 0:
            self.canvas.create_line(x1, y1, x2, y2, fill=self.color_var.get())
            self.canvas.update()
            time.sleep(0.1 / self.speed_var.get())  # Ajuster la vitesse d'affichage
        else:
            dx = (x2 - x1) / 3
            dy = (y2 - y1) / 3

            xA, yA = x1 + dx, y1 + dy
            xB, yB = x1 + 2 * dx, y1 + 2 * dy

            xC = (xA + xB) / 2 - (math.sqrt(3) * (yB - yA)) / 2
            yC = (yA + yB) / 2 + (math.sqrt(3) * (xB - xA)) / 2

            self.draw_koch_segment(x1, y1, xA, yA, order - 1)
            self.draw_koch_segment(xA, yA, xC, yC, order - 1)
            self.draw_koch_segment(xC, yC, xB, yB, order - 1)
            self.draw_koch_segment(xB, yB, x2, y2, order - 1)

    def draw_koch(self):

        if not self.keep_history.get():
            self.clear_canvas()

        order = self.order_var.get()
        width, height = 500, 500
        x1, y1 = 100, 400
        x2, y2 = 400, 400
        x3, y3 = (x1 + x2) / 2, y1 - math.sqrt(3) * (x2 - x1) / 2

        self.draw_koch_segment(x1, y1, x2, y2, order)
        self.draw_koch_segment(x2, y2, x3, y3, order)
        self.draw_koch_segment(x3, y3, x1, y1, order)

    def clear_canvas(self):
        
        self.canvas.delete("all")

    def show_info(self):

        messagebox.showinfo("À propos", "Auteur: Mohammed IALLOUCHEN\nAffiliation: Polytechdijon\nVersion: 1.0\nAnnée: 2024-2025")

    def quit_app(self):

        if messagebox.askokcancel("Quitter", "Voulez-vous vraiment quitter ?"):
            self.root.quit()

if __name__ == "__main__":
    root = tk.Tk()
    app = KochApp(root)
    root.mainloop()
