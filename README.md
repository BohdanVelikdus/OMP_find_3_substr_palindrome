This is an implementation of algorithm, which finds if we can divide origin string into three substring, which are palindrome. 
In ```main``` branch, I used an OpenMP library, which can parallelize loop in function. I added some directives, which made my code parallelize.
Due to OpenMP use Fork-Join philosophy, it's easy to optimize code with a lot of loops.
In ```sequ``` brach, I just used the sequential algorithm to solve the problem
### To Start(For Unix systems)

1. Copy the code directly from file, or copy repository 
2. Check if on your PC is installed OpenMP
3. Build a project(example for g++): ```g++ -fopenmp main.cpp -o main```
4. Execute: ```./main```

In the output you see the time(microSeconds) ellapsed from start of the computation.
