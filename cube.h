#ifndef MISC_CUBE_H
#define MISC_CUBE_H
#include <iostream>
#include <cstdint>
#include <vector>
class Cube{
private:
public:
    char cube[6][9] = {
            {'W','W','W','W','W','W','W','W','W'}, // white
            {'G','G','G','G','G','G','G','G','G'}, // green
            {'Y','Y','Y','Y','Y','Y','Y','Y','Y'}, // yellow
            {'B','B','B','B','B','B','B','B','B'}, // blue
            {'O','O','O','O','O','O','O','O','O'}, // orange
            {'R','R','R','R','R','R','R','R','R'}  // red
    };
    const int reverse_moves[12]={1,0,3,2,5,4,7,6,9,8,11,10};

    void _swap_surfaces(int face);
    void _swap_surfaces_c(int face);
    void ascii();
    void make_move(int m);

};




#endif //MISC_CUBE_H
