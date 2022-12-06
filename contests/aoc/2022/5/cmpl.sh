g++ -std=c++14 -O2 -Wall -g -DDEBUG $1.cpp -o $1.out

# ./$1.out < test.txt
./$1.out < input.txt