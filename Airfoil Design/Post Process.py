import os
from tkinter import Tk, filedialog, simpledialog, messagebox
from tkinter import Button, Label, Entry, StringVar
from tkinter import Toplevel

# Function to select a file
def select_file():
    file_path = filedialog.askopenfilename(title="Select a File")
    if file_path:
        file_path_var.set(file_path)

# Function to edit the file content
def edit_file():
    file_path = file_path_var.get()
    if not file_path:
        messagebox.showerror("Error", "No file selected!")
        return
    with open(file_path, 'r') as file:
        content = file.read()
    
    # Simple text-based editor (editable in dialog)
    new_content = simpledialog.askstring("Edit Content", "Edit the file content below:", initialvalue=content)
    if new_content is not None:
        with open(file_path, 'w') as file:
            file.write(new_content)
        messagebox.showinfo("Success", "File content updated!")

# Function to convert file type
def convert_file():
    file_path = file_path_var.get()
    if not file_path:
        messagebox.showerror("Error", "No file selected!")
        return
    
    # Get new file type from user
    new_extension = simpledialog.askstring("Convert File", "Enter new file extension (e.g., .txt, .md):")
    if not new_extension:
        return
    
    new_file_path = os.path.splitext(file_path)[0] + new_extension
    os.rename(file_path, new_file_path)
    file_path_var.set(new_file_path)
    messagebox.showinfo("Success", f"File converted to {new_extension}!")

# Set up the GUI
root = Tk()
root.title("File Editor & Converter")

# Variables
file_path_var = StringVar()

# GUI Widgets
Label(root, text="Selected File:").grid(row=0, column=0, padx=10, pady=10, sticky="e")
Entry(root, textvariable=file_path_var, width=50).grid(row=0, column=1, padx=10, pady=10)

Button(root, text="Browse", command=select_file).grid(row=0, column=2, padx=10, pady=10)
Button(root, text="Edit File", command=edit_file).grid(row=1, column=1, padx=10, pady=10)
Button(root, text="Convert File", command=convert_file).grid(row=2, column=1, padx=10, pady=10)

# Start the main loop
root.mainloop()
