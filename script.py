# pylint: disable=all
import os

def compileTask1():
    os.system("gcc -w LAB01-TASK01.c -o LAB01-TASK01.exe && LAB01-TASK01.exe")
    if os.path.exists("LAB01-TASK01.exe"):
        os.remove("LAB01-TASK01.exe")

def compileTask2():
    os.system("gcc -w LAB01-TASK02.c -o LAB01-TASK02.exe && LAB01-TASK02.exe")
    if os.path.exists("LAB01-TASK02.exe"):
        os.remove("LAB01-TASK02.exe")

def compileTask3():
    os.system("gcc -w LAB01-TASK03.c -o LAB01-TASK03.exe && LAB01-TASK03.exe")
    if os.path.exists("LAB01-TASK03.exe"):
        os.remove("LAB01-TASK03.exe")

def compileTask4():
    os.system("gcc -w LAB01-TASK04.c -o LAB01-TASK04.exe && LAB01-TASK04.exe")
    if os.path.exists("LAB01-TASK04.exe"):
        os.remove("LAB01-TASK04.exe")

def compileTask5():
    os.system("gcc -w LAB01-TASK05.c -o LAB01-TASK05.exe && LAB01-TASK05.exe")
    if os.path.exists("LAB01-TASK05.exe"):
        os.remove("LAB01-TASK05.exe")



# compileTask1()
# compileTask2()
# compileTask3()
# compileTask4()
compileTask5()
