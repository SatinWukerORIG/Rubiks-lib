#include<iostream>

using namespace std;

struct Cube{
    char cube[6][9] = {
        {'W','W','W','W','W','W','W','W','W'}, // white
        {'G','G','G','G','G','G','G','G','G'}, // green
        {'Y','Y','Y','Y','Y','Y','Y','Y','Y'}, // yellow
        {'B','B','B','B','B','B','B','B','B'}, // blue
        {'O','O','O','O','O','O','O','O','O'}, // orange
        {'R','R','R','R','R','R','R','R','R'}  // red
    };

    void printCube(){
        for(int i = 0; i < 6; i++){
            cout<<"\n------------------"<<endl;
            for(int j = 0; j < 9; j++){
                if(j % 3 == 0 && j != 0){
                    cout<<endl;
                }
                cout<<cube[i][j]<<" ";
            }
        }
    }

    void turnR(){
        /*
            R: [3, 6, 9]
            white -> green
            green -> yellow
            yellow -> blue
            blue -> white
        */
        int temp_white[3] = {cube[0][2], cube[0][5], cube[0][8]};

        for(int i = 0; i < 3; i++){
            cube[i][2] = cube[i + 1][2];
            cube[i][5] = cube[i + 1][5];
            cube[i][8] = cube[i + 1][8];
        }

        cube[3][2] = temp_white[0];
        cube[3][5] = temp_white[1];
        cube[3][8] = temp_white[2];

    };

    void turnRapos(){
        /*
            R': [3, 6, 9]
            white -> blue
            blue -> yellow
            yellow -> green
            green -> white
        */
        int temp_blue[3] = {cube[3][0], cube[3][3], cube[3][6]};
        for(int i = 3; i >= 1; i--){
            cube[i][2] = cube[i - 1][2];
            cube[i][5] = cube[i - 1][5];
            cube[i][8] = cube[i - 1][8];
        }

        cube[0][0] = temp_blue[0];
        cube[0][3] = temp_blue[1];
        cube[0][6] = temp_blue[2];

    };

    void turnL(){
        /*
            L: [1, 4, 7]
            while -> blue
            blue -> yellow
            yellow -> green
            green -> white
        */
        int temp_blue[3] = {cube[3][0], cube[3][3], cube[3][6]};
        for(int i = 3; i >= 1; i--){
            cube[i][0] = cube[i - 1][0];
            cube[i][3] = cube[i - 1][3];
            cube[i][6] = cube[i - 1][6];
        }

        cube[0][0] = temp_blue[0];
        cube[0][3] = temp_blue[1];
        cube[0][6] = temp_blue[2];
    }

    void turnLapos(){
        /*
            L': [1, 4, 7]
            white -> green
            green -> yellow
            yellow -> blue
            blue -> white
        */
        int temp_white[3] = {cube[0][0], cube[0][3], cube[0][6]};

        for(int i = 0; i < 3; i++){
            cube[i][0] = cube[i + 1][0];
            cube[i][3] = cube[i + 1][3];
            cube[i][6] = cube[i + 1][6];
        }

        cube[3][0] = temp_white[0];
        cube[3][3] = temp_white[1];
        cube[3][6] = temp_white[2];
    }

    void turnU(){
        /*
            U: [1][all]
            red -> green
            green -> orange
            orange -> blue
            blue -> red
        */
        int temp_green[3] = {cube[1][0], cube[1][1], cube[1][2]};
        /*SIDES*/
        // green -> red
        cube[1][0]=cube[5][0]; cube[1][1]=cube[5][1]; cube[1][2]=cube[5][2];
        // red -> blue
        cube[5][0]=cube[3][8]; cube[5][1]=cube[3][7]; cube[5][2]=cube[3][6];
        // blue -> orange
        cube[3][8]=cube[4][0]; cube[3][7]=cube[4][1]; cube[3][6]=cube[4][2];
        // orange -> green
        cube[4][0]=temp_green[0]; cube[4][1]=temp_green[1]; cube[4][2]=temp_green[2];

        char corner_1 = cube[0][2], side_1 = cube[0][1];
        /*swap CORNERS*/
        cube[0][2] = cube[0][0];
        cube[0][0] = cube[0][6];
        cube[0][6] = cube[0][8];
        cube[0][8] = corner_1;
        /*SIDE CUBES*/
        cube[0][1] = cube[0][3];
        cube[0][3] = cube[0][7];
        cube[0][7] = cube[0][5];
        cube[0][5] = side_1;
    }

    void turnUapos(){
        int temp_red[3] = {cube[5][0], cube[5][1], cube[5][2]};
        /*SIDES*/
        // red -> green
        cube[5][0]=cube[1][0]; cube[5][1]=cube[1][1]; cube[5][2]=cube[1][2];
        // green -> orange
        cube[1][0]=cube[4][0]; cube[1][1]=cube[4][1]; cube[1][2]=cube[4][2];
        // orange -> blue
        cube[4][0]=cube[3][8]; cube[4][1]=cube[3][7]; cube[4][2]=cube[3][6];

        // blue -> red
        cube[3][8]=temp_red[0]; cube[3][7]=temp_red[1]; cube[3][6]=temp_red[2];

        char corner_1 = cube[0][2], side_1 = cube[0][1];
        /*swap CORNERS*/
        cube[0][2] = cube[0][8];
        cube[0][8] = cube[0][6];
        cube[0][6] = cube[0][0];
        cube[0][0] = corner_1;
        /*SIDE CUBES*/
        cube[0][1] = cube[0][5];
        cube[0][5] = cube[0][7];
        cube[0][7] = cube[0][3];
        cube[0][3] = side_1;
    }

    void turnF(){

    }

    void turnFapos(){
        
    }
};


int main(){
    struct Cube Cub;

    Cub.turnR(); Cub.turnR();
    Cub.turnL(); Cub.turnL();
    Cub.turnU(); Cub.turnU();

    Cub.turnR(); Cub.turnR();
    Cub.turnL(); Cub.turnL();
    Cub.turnU(); Cub.turnU();
    
    Cub.turnR(); Cub.turnR();
    Cub.turnL(); Cub.turnL();
    Cub.turnU(); Cub.turnU();

    Cub.printCube();

    return 0;
}
