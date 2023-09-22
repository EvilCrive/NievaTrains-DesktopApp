import os
import shutil
for i in os.listdir() :
    if (i in [".qmake.stash", "debug", "release"]) or (i[0:8]=="Makefile") or (i[-4:] == ".pro"):
        try:
            if os.path.isdir(i) :
                shutil.rmtree(i)
            else :
                os.remove(i)
        except OSError as e:
            print(f"Error: {e}. Failed to remove the file '{i}'.")