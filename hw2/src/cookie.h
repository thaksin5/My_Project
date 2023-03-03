#ifndef COOKIE
#define COOKIE
#include <string>

int check_x(bool** grid){
    int check = 1;
    for(int i=1; i<=9; i++){
        for(int j=9; j>=0; j--){
            if(grid[j][i] == true){
                check = 0; break;
            }
        }
        if(check==1){ return i-1;} // dont have true element 
        check = 1;
    }
    return 9;
}

int check_y(bool** grid){
    int check = 1;
    for(int i=8; i>=0; i--){
        for(int j=0; j<=9; j++){
            if(grid[i][j]==true){ 
                check=0; break;
            }
        }
        if(check==1){ return i+1;}
        check=1;
    }
    return 0;
}

void placeTop(bool** grid){
    int x = check_x(grid);
    int y = check_y(grid);

    if(y==0){
        throw std::string("out of range"); return;
    }
    grid[y-1][x] = true;
}

void placeRight(bool** grid){
    int x = check_x(grid);
    int y = check_y(grid);

    if(x==9){
        throw std::string("out of range"); return;
    }
    grid[y][x+1] = true;
}

int calcRow(bool** grid, int row){
    if(!(row>=0 && row<=9)){
        throw std::string("out of range");
    }
    int count = 0;
    for(int i = 0; i < 10; i++) {
        if(grid[row][i] == true) {
            count++;
        }
    }
    return count;
}

int calcColumn(bool** grid, int column){
    if(!(column>=0 && column<=9)){
        throw std::string("out of range");
    }
    int count = 0;
    for(int i = 0; i < 10; i++) {
        if(grid[i][column] == true) {
            count++;
        }
    }
    return count;
}

#endif
