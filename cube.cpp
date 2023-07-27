#include <iostream>
#include "cube.h"

void Cube::_swap_surfaces(int face){
    char corner_1 = cube[face][2], side_1 = cube[face][1];
    /*swap CORNERS*/
    cube[face][2] = cube[face][0];
    cube[face][0] = cube[face][6];
    cube[face][6] = cube[face][8];
    cube[face][8] = corner_1;
    /*SIDE CUBES*/
    cube[face][1] = cube[face][3];
    cube[face][3] = cube[face][7];
    cube[face][7] = cube[face][5];
    cube[face][5] = side_1;
}
void Cube::_swap_surfaces_c(int face){
    char corner_1 = cube[face][2], side_1 = cube[face][1];
    /*swap CORNERS*/
    cube[face][2] = cube[face][8];
    cube[face][8] = cube[face][6];
    cube[face][6] = cube[face][0];
    cube[face][0] = corner_1;
    /*SIDE CUBES*/
    cube[face][1] = cube[face][5];
    cube[face][5] = cube[face][7];
    cube[face][7] = cube[face][3];
    cube[face][3] = side_1;
}
void Cube::ascii(){
    for(int i = 0; i < 6; i++){
        std::cout<<"\n------------------"<<std::endl;
        for(int j = 0; j < 9; j++){
            if(j % 3 == 0 && j != 0){
                std::cout<<std::endl;
            }
            std::cout<<cube[i][j]<<" ";
        }
    }
    std::cout << '\n';
}


void Cube::make_move(int m){
    switch (m) { //r l u f b d
        case 0: { //r
            char temp_white[3] = {cube[0][2], cube[0][5], cube[0][8]};

            for(int i = 0; i < 3; i++){
                cube[i][2] = cube[i + 1][2];
                cube[i][5] = cube[i + 1][5];
                cube[i][8] = cube[i + 1][8];
            }

            cube[3][2] = temp_white[0];
            cube[3][5] = temp_white[1];
            cube[3][8] = temp_white[2];

            _swap_surfaces(5);
            break;
        }
        case 1: { //r'
            char temp_blue[3] = {cube[3][2], cube[3][5], cube[3][8]};
            for(int i = 3; i >= 1; i--){
                cube[i][2] = cube[i - 1][2];
                cube[i][5] = cube[i - 1][5];
                cube[i][8] = cube[i - 1][8];
            }

            cube[0][2] = temp_blue[0];
            cube[0][5] = temp_blue[1];
            cube[0][8] = temp_blue[2];

            _swap_surfaces_c(5);
            break;
        }
        case 2: { //l
            char temp_blue[3] = {cube[3][0], cube[3][3], cube[3][6]};
            for(int i = 3; i >= 1; i--){
                cube[i][0] = cube[i - 1][0];
                cube[i][3] = cube[i - 1][3];
                cube[i][6] = cube[i - 1][6];
            }

            cube[0][0] = temp_blue[0];
            cube[0][3] = temp_blue[1];
            cube[0][6] = temp_blue[2];

            _swap_surfaces(4);
            break;
        }
        case 3: { //l'
            char temp_white[3] = {cube[0][0], cube[0][3], cube[0][6]};
            for(int i = 0; i < 3; i++){
                cube[i][0] = cube[i + 1][0];
                cube[i][3] = cube[i + 1][3];
                cube[i][6] = cube[i + 1][6];
            }

            cube[3][0] = temp_white[0];
            cube[3][3] = temp_white[1];
            cube[3][6] = temp_white[2];

            _swap_surfaces_c(4);
            break;
        }
        case 4: { //u
            char temp_green[3] = {cube[1][0], cube[1][1], cube[1][2]};
            /*SIDES*/
            // green -> red
            cube[1][0]=cube[5][0]; cube[1][1]=cube[5][1]; cube[1][2]=cube[5][2];
            // red -> blue
            cube[5][0]=cube[3][8]; cube[5][1]=cube[3][7]; cube[5][2]=cube[3][6];
            // blue -> orange
            cube[3][8]=cube[4][0]; cube[3][7]=cube[4][1]; cube[3][6]=cube[4][2];
            // orange -> green
            cube[4][0]=temp_green[0]; cube[4][1]=temp_green[1]; cube[4][2]=temp_green[2];

            _swap_surfaces(0);
            break;
        }
        case 5: { //u'
            char temp_red[3] = {cube[5][0], cube[5][1], cube[5][2]};
            /*SIDES*/
            // red -> green
            cube[5][0]=cube[1][0]; cube[5][1]=cube[1][1]; cube[5][2]=cube[1][2];
            // green -> orange
            cube[1][0]=cube[4][0]; cube[1][1]=cube[4][1]; cube[1][2]=cube[4][2];
            // orange -> blue
            cube[4][0]=cube[3][8]; cube[4][1]=cube[3][7]; cube[4][2]=cube[3][6];

            // blue -> red
            cube[3][8]=temp_red[0]; cube[3][7]=temp_red[1]; cube[3][6]=temp_red[2];

            _swap_surfaces_c(0);
            break;
        }
        case 6: { //f
            char temp_white[3] = {cube[0][6], cube[0][7], cube[0][8]};

            cube[0][6] = cube[4][8];
            cube[0][7] = cube[4][5];
            cube[0][8] = cube[4][2];

            cube[4][2] = cube[2][0];
            cube[4][5] = cube[2][1];
            cube[4][8] = cube[2][2];

            cube[2][0] = cube[5][6];
            cube[2][1] = cube[5][3];
            cube[2][2] = cube[5][0];

            cube[5][0] = temp_white[0];
            cube[5][3] = temp_white[1];
            cube[5][6] = temp_white[2];

            _swap_surfaces(1);
            break;
        }
        case 7: {//f_
            char temp_white[3] = {cube[0][6], cube[0][7], cube[0][8]};

            cube[0][6] = cube[5][0];
            cube[0][7] = cube[5][3];
            cube[0][8] = cube[5][6];

            cube[5][0] = cube[2][2];
            cube[5][3] = cube[2][1];
            cube[5][6] = cube[2][0];

            cube[2][0] = cube[4][2];
            cube[2][1] = cube[4][5];
            cube[2][2] = cube[4][8];

            cube[4][2] = temp_white[2];
            cube[4][5] = temp_white[1];
            cube[4][8] = temp_white[0];

            _swap_surfaces_c(1);
            break;
        }
        case 8: { //b
            char temp_white[3] = {cube[0][0], cube[0][1], cube[0][2]};

            cube[0][0] = cube[5][2];
            cube[0][1] = cube[5][5];
            cube[0][2] = cube[5][8];

            cube[5][2] = cube[2][8];
            cube[5][5] = cube[2][7];
            cube[5][8] = cube[2][6];

            cube[2][6] = cube[4][0];
            cube[2][7] = cube[4][3];
            cube[2][8] = cube[4][6];

            cube[4][0] = temp_white[2];
            cube[4][3] = temp_white[1];
            cube[4][6] = temp_white[0];

            _swap_surfaces(3);
            break;
        }
        case 9: { //b'
            char temp_white[3] = {cube[0][0], cube[0][1], cube[0][2]};

            cube[0][0] = cube[4][0];
            cube[0][1] = cube[4][3];
            cube[0][2] = cube[4][6];

            cube[4][0] = cube[2][6];
            cube[4][3] = cube[2][7];
            cube[4][6] = cube[2][8];

            cube[2][6] = cube[5][8];
            cube[2][7] = cube[5][7];
            cube[2][8] = cube[5][6];

            cube[5][2] = temp_white[0];
            cube[5][5] = temp_white[1];
            cube[5][8] = temp_white[2];

            _swap_surfaces_c(3);
            break;
        };
        case 10: {
            char temp_red[3] = {cube[5][6], cube[5][7], cube[5][8]};
            /*SIDES*/
            // red -> green
            cube[5][6]=cube[1][6]; cube[5][7]=cube[1][7]; cube[5][8]=cube[1][8];
            // green -> orange
            cube[1][6]=cube[4][6]; cube[1][7]=cube[4][7]; cube[1][8]=cube[4][8];
            // orange -> blue
            cube[4][6]=cube[3][2]; cube[4][7]=cube[3][1]; cube[4][8]=cube[3][0];

            // blue -> red
            cube[3][2]=temp_red[0]; cube[3][1]=temp_red[1]; cube[3][0]=temp_red[2];

            _swap_surfaces(2);
            break;
        }
        case 11: {
            char temp_green[3] = {cube[1][6], cube[1][7], cube[1][8]};
            /*SIDES*/
            // green -> red
            cube[1][6]=cube[5][6]; cube[1][7]=cube[5][7]; cube[1][8]=cube[5][8];
            // red -> blue
            cube[5][6]=cube[3][2]; cube[5][7]=cube[3][1]; cube[5][8]=cube[3][0];
            // blue -> orange
            cube[3][0]=cube[4][8]; cube[3][1]=cube[4][7]; cube[3][2]=cube[4][6];
            // orange -> green
            cube[4][6]=temp_green[0]; cube[4][7]=temp_green[1]; cube[4][8]=temp_green[2];
            _swap_surfaces_c(2);
            break;
        }
    }
}