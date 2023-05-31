# pylint: disable=all
import os,sys


def compileTask1():
    os.system("gcc -Wall -Wextra LAB01-TASK01.c -o LAB01-TASK01.exe && LAB01-TASK01.exe")
    if os.path.exists("LAB01-TASK01.exe"):
        os.remove("LAB01-TASK01.exe")

def compileTask2():
    os.system("gcc -Wall -Wextra LAB01-TASK02.c -o LAB01-TASK02.exe && LAB01-TASK02.exe")
    if os.path.exists("LAB01-TASK02.exe"):
        os.remove("LAB01-TASK02.exe")

def compileTask3():
    os.system("gcc -Wall -Wextra LAB01-TASK03.c -o LAB01-TASK03.exe && LAB01-TASK03.exe")
    if os.path.exists("LAB01-TASK03.exe"):
        os.remove("LAB01-TASK03.exe")

def compileTask4():
    os.system("gcc -Wall -Wextra LAB01-TASK04.c -o LAB01-TASK04.exe && LAB01-TASK04.exe")
    if os.path.exists("LAB01-TASK04.exe"):
        os.remove("LAB01-TASK04.exe")

def compileTask5():
    os.system("gcc -Wall -Wextra LAB01-TASK05.c -o LAB01-TASK05.exe && LAB01-TASK05.exe")
    if os.path.exists("LAB01-TASK05.exe"):
        os.remove("LAB01-TASK05.exe")

## Imperative-Programming Repo (Khushaalan)
def gitUpdate():
    os.system("git status")
    os.system("git add -A")
    os.system("git commit -m 'update'")
    os.system("git push origin main")
    os.system("git status")


def main(args=None):
    args = args or sys.argv[1:]

    if args:
        if args[0] == '--1':
            compileTask1()
        elif args[0] == '--2':
            compileTask2()
        elif args[0] == '--3':
            compileTask3()
        elif args[0] == '--4':
            compileTask4()
        elif args[0] == '--5':
            compileTask5()
        elif args[0] == '--git':
            gitUpdate()
        else:
            print("Usage: python MAKEFILE.py [--1 | --2 | --3 | --4 | --5]")
            return
    else:
        print("Usage: python MAKEFILE.py [--1 | --2 | --3 | --4 | --5]")
        return


main()
