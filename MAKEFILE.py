# pylint: disable=all

"""
##################################################################################################################################################
# This is a MAKEFILE for LAB01. 
# I have turned on all the warnings for the GCC compiler ( -Wall -Wextra )
# Usage: python MAKEFILE.py [ --1 | --2 | --3 | --4 | --5 | --git ]
# If you are running this on Linux, you need to amened the code and change the '.exe' to '.out' because Linux couldn't run executable files.


#   To compile and run LAB01-TASK01.c use the following command:  
    python MAKEFILE.py --1
#   To compile and run LAB01-TASK02.c use the following command:  
    python MAKEFILE.py --2
#   To compile and run LAB01-TASK03.c use the following command:  
    python MAKEFILE.py --3
#   To compile and run LAB01-TASK04.c use the following command:  
    python MAKEFILE.py --4
#   To compile and run LAB01-TASK05.c use the following command:  
    python MAKEFILE.py --5

######################################################################################################################################################
"""

import os,sys
WARNING = "-Wall -Wextra"
COMMAND =""

def compileTask1():
    COMMAND = "gcc "+ WARNING + " LAB01-TASK01.c -o LAB01-TASK01.exe && LAB01-TASK01.exe"
    os.system(COMMAND)
    if os.path.exists("LAB01-TASK01.exe"):
        os.remove("LAB01-TASK01.exe")

def compileTask2():
    COMMAND = "gcc "+ WARNING + " LAB01-TASK02.c -o LAB01-TASK02.exe && LAB01-TASK02.exe"
    os.system(COMMAND)
    if os.path.exists("LAB01-TASK02.exe"):
        os.remove("LAB01-TASK02.exe")

def compileTask3():
    COMMAND = "gcc "+ WARNING + " LAB01-TASK03.c -o LAB01-TASK03.exe && LAB01-TASK03.exe"
    os.system(COMMAND)
    if os.path.exists("LAB01-TASK03.exe"):
        os.remove("LAB01-TASK03.exe")

def compileTask4():
    COMMAND = "gcc "+ WARNING + " LAB01-TASK04.c -o LAB01-TASK04.exe && LAB01-TASK04.exe"
    os.system(COMMAND)
    if os.path.exists("LAB01-TASK04.exe"):
        os.remove("LAB01-TASK04.exe")

def compileTask5():
    COMMAND = "gcc "+ WARNING + " LAB01-TASK05.c -o LAB01-TASK05.exe && LAB01-TASK05.exe"
    os.system(COMMAND)
    if os.path.exists("LAB01-TASK05.exe"):
        os.remove("LAB01-TASK05.exe")

## https://github.com/khushaalan/Imperative-Programming.git
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
            print("Usage: python MAKEFILE.py [ --1 | --2 | --3 | --4 | --5 | --git ]")
            print("Example: python MAKEFILE.py --1")
            return
    else:
        print("Usage: python MAKEFILE.py [ --1 | --2 | --3 | --4 | --5 | --git ]")
        print("Example: python MAKEFILE.py --1")
        return


main()
