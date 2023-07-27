# Rubiks
A Rubik's Cube representation written in C++

180 turns, center slicing, double layer turns, orientation changes, and move history are not implemented YET.

What is implemented:
-cube 


____Getting Started____:
```c++
#include<iostream>
#include "cube.h"

unsigned long long perft(Cube cube,int depth){
    if (depth<=0){return 1ULL;}
    unsigned long long nodes=0;
    for (int m=0;m<12;m++){ 
        cube.make_move(m);
        nodes+=perft(cube,depth-1);
        cube.make_move(cube.reverse_moves[m]);   //undo_move  - cheap fix, double the speed over a move_history implementation :D
    }
    return nodes;
}

int main(){
    Cube cube;
    std::cout<<perft(cube,8);
    cube.ascii();
    return 0;
}
```







# Build & Run
## Windows
1. `cd src`
2. `build` or `g++ rubiks.cpp -o rubiks.exe -O3`

7431ms | 429981696nodes | 57855nodes per ms


## MacOS/Linux
```shell
make all
./rubiks
```
