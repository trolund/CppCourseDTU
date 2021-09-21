#include <iostream>
#include <vector>
#include <math.h>

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

void init(tile **playground, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
            playground[i][j].x = j;
            playground[i][j].y = i;
            playground[i][j].isWall = (j==0 || i==(n-1) || (i==0 && j!=3) || j==(m-1));
            if (playground[i][j].isWall) {
                playground[i][j].type = stone;
            }
            else {
                playground[i][j].type = wood;
            }
        }
    }
}

void printState(tile **playground, player* p, int n, int m){
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++){
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

bool stepOk(tile **playground, int x, int y){
    if(playground[y][x].isWall){
        return false;
    }
    return true;
}

int main() {
    player* p = new player;

    int n = 0;
    int m = 0;

    string input;
    for (int i = 0; i < 2; i++) {
        getline(cin, input);

        if(i == 0){
            string delimiter = " ";
            n = stoi(input.substr(0, input.find(delimiter)));
            m = stoi(input.substr(input.find(delimiter), input.size()));
        }
    }

    p->x = m/2;
    p->y = n/2;

    tile **playground = new tile*[n];

    for (int i = 0; i < m; i++) {
        playground[i] = new tile[m];
    }

    init(playground, n, m);

    for (int i = 0; i < input.size(); i++) {
        printState(playground, p, n, m);

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