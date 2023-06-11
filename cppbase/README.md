# Basic test environment for coding test with cpp

# MacOS
```
g++ --version
```
Then the example output of the above command is like below.
```
Apple clang version 14.0.0 (clang-1400.0.29.102)
Target: x86_64-apple-darwin22.1.0
Thread model: posix
InstalledDir: /Library/Developer/CommandLineTools/usr/bin
```
Create the bits dir at the path like below, and then edit stdc++.h
```
sudo mkdir -p /Library/Developer/CommandLineTools/usr/include/bits
sudo vi /Library/Developer/CommandLineTools/usr/include/bits/stdc++.h
```
Then copy and paste https://gist.github.com/frankchen0130/9ac562b55fa7e03689bca30d0e52b0e5

# Run Test
```
g++ -g -std=c++20 main.cpp && ./a.out testcases/input00.txt testcases/output00.txt
```

# Environment for each problem solving
```
git checkout -b "solve/lc/count-of-integers"
```
After solving the problem, then delete the branch.
```
git checkout main
git branch -D "solve/lc/count-of-integers"
```

# Run all testcases
```
python test.py
```
main function should be return nonzero value if the gt doesn't match the output.
