import subprocess
import re
import os
from os.path import join as ospj
from time import time

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

keys = list(inputs.keys())
keys.sort(reverse=True)

for k in keys:
    i = inputs[k]
    if k in outputs:
        o = outputs[k]

        t0 = time()
        p = subprocess.Popen(["./a.out", ospj(TCDIR, i), ospj(TCDIR, o)], stdout=subprocess.PIPE, stderr=subprocess.PIPE)

        # wait for process then measure the execution time.
        try:
            returncode = p.wait(30.0)
            t1 = time()
        except subprocess.TimeoutExpired as e:
            print(f"\033[91m----- Testcase failed on TC number {k}!! Timeout!! -----\033[0m\n")
            p.kill()
            continue

        if p.returncode != 0:
            print(f"\033[91m----- Testcase failed on TC number {k} in {(t1-t0)*1e+3:.3f}ms -----\033[0m\n")
            print("\033[95m--- STDERR:\033[0m")
            print(p.stderr.read().decode('utf-8'))
            print("\033[95m--- STDOUT:\033[0m")
            print(p.stdout.read().decode('utf-8'))
            break
        else:
            print(f"\033[92m----- Testcase passed on TC number {k} in {(t1-t0)*1e+3:.3f}ms -----\033[0m")
