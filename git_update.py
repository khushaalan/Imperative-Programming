import os

def gitUpdate():
    os.system("git status")
    os.system("git add -A")
    os.system("git commit -m 'update'")
    os.system("git push origin main")
    os.system("git status")

gitUpdate()