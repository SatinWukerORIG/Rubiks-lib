#include<iostream>
#include<chrono>
#include "cube.h"





// 180 turns, center slicing, double layer turns, orientation changes, and move history are not implemented YET.

unsigned long long perft(Cube cube,int depth){
    if (depth<=0){return 1ULL;}
    unsigned long long nodes=0;
    for (int m=0;m<12;m++){
        cube.make_move(m);
        nodes+=perft(cube,depth-1);
        cube.make_move(cube.reverse_moves[m]);
    }
    return nodes;
}

int main(){
    Cube cube;

    int nodes=0;
    const auto t0=std::chrono::high_resolution_clock::now();
    nodes=perft(cube,8);
    const auto t1=std::chrono::high_resolution_clock::now();
    const auto dt=std::chrono::duration_cast<std::chrono::milliseconds>(t1-t0);
    std::cout<<"\n"<<dt.count()<<" "<<nodes<<" "<<nodes/(dt.count()+1)<<std::endl;

    cube.ascii();
    return 0;
}