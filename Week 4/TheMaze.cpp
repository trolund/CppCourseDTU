#include <iostream>
#include <vector>
#include <math.h>

#define NROWS 12
#define NCOLS 16

using namespace std;

typedef enum { wood, stone } material;

struct tile{
    int x,y;
    bool isWall;
    material type;
};

struct player {
    int x, y;
};

void init(tile playground[NROWS][NCOLS]) {
    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++){
            playground[i][j].x = j;
            playground[i][j].y = i;
            playground[i][j].isWall = (j==0 || i==(NROWS-1) || (i==0 && j!=3) || j==(NCOLS-1));
            if (playground[i][j].isWall) {
                playground[i][j].type = stone;
            }
            else {
                playground[i][j].type = wood;
            }
        }
    }
}

void printState(tile playground[NROWS][NCOLS], player* p){
    for (int i = 0; i < NROWS; i++) {
        for (int j = 0; j < NCOLS; j++){
            tile current = playground[i][j];

            if(p->y == i && p->x == j){
                cout << "O";
            }else if(current.isWall){
                cout << "*";
            }else {
                cout << " ";
            }
        }
        cout << "\n";
    }
}

bool stepOk(tile playground[NROWS][NCOLS], int x, int y){
    if(playground[y][x].isWall){
        return false;
    }
    return true;
}

int main() {
    player* p = new player;

    p->x = 5;
    p->y = 5;

    tile playground[NROWS][NCOLS];
    init(playground);

    string input;
    getline(cin, input);

    for (int i = 0; i < input.size(); i++) {
        printState(playground, p);

        char command = input[i];

        if(command == 'q'){
            break;
        }else if(command == 'r' && stepOk(playground, p->x+1, p->y)){
            p->x += 1;
        }else if(command == 'l' && stepOk(playground, p->x-1, p->y)){
            p->x -= 1;
        }else if(command == 'u' && stepOk(playground, p->x, p->y-1)){
            p->y -= 1;
        }else if(command == 'd' && stepOk(playground, p->x, p->y+1)){
            p->y += 1;
        }
    }

    return 0;
}





