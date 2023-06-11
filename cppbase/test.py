import subprocess
import re
import os
from os.path import join as ospj

TCDIR = "testcases"

inputs = dict()
outputs = dict()

flist = [f for f in os.listdir("testcases") if f.endswith(".txt")]
for f in flist:
    if re.match("input[0-9]+\.txt", f) is not None:
        n = re.search("(?<=input)[0-9]+(?=\.txt)", f).group()
        inputs[n] = f
    if re.match("output[0-9]+\.txt", f) is not None:
        n = re.search("(?<=output)[0-9]+(?=\.txt)", f).group()
        outputs[n] = f

# first compile the main function.
p = subprocess.run(["g++", "-g", "-std=c++20", "main.cpp"])
if p.returncode != 0:
    print("\n\033[91mCompile error!!\033[0m\n")
    exit(1)

for k, i in inputs.items():
    if k in outputs:
        o = outputs[k]
        p = subprocess.Popen(["./a.out", ospj(TCDIR, i), ospj(TCDIR, o)], stdout=subprocess.PIPE, stderr=subprocess.PIPE)
        if p.returncode != 0:
            print(f"\033[91m----- Testcase failed on TC number {k}!! -----\033[0m\n")
            print("\033[95m--- STDERR:\033[0m")
            print(p.stderr.read().decode('utf-8'))
            print("\033[95m--- STDOUT:\033[0m")
            print(p.stdout.read().decode('utf-8'))
            break
