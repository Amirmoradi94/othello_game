#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//---------------------------------------------------Define Map------------------------------------------------------------------------
char** define_map(){ 
    char** map;
    map = new char*[17];
    for (int h = 0; h < 17; h++)
    {
        map[h] = new char[17];
        for (int w = 0; w < 17; w++)
        {
            map[h][w] = ' ';
        }
    }
    
    map[7][9] = 'B';
    map[7][7] = 'W';
    map[9][7] = 'B';
    map[9][9] = 'W';
    for (int i=0; i<=14; i+=2){
        map[0][i] = '-';
    }
    
    map[0][1] = '1';
    map[0][3] = '2';
    map[0][5] = '3';
    map[0][7] = '4';
    map[0][9] = '5';
    map[0][11] = '6';
    map[0][13] = '7';
    map[0][15] = '8';
    
    map[1][0] = '1';
    map[3][0] = '2';
    map[5][0] = '3';
    map[7][0] = '4';
    map[9][0] = '5';
    map[11][0] = '6';
    map[13][0] = '7';
    map[15][0] = '8';
    
    for (int i=0; i<=16; i+=1){
        map[16][i] = '-';
    }
    
    for (int i=0; i<=14; i+=2){
        map[0][16] = '-';
        
        map[16][16] = '-';
        
        map[i][0] = '-';
        map[16][0] = '-';
        
        map[i][16] = '-';
        map[i+1][16] = '|';
    }
    
    for (int j=2; j<=14; j+=2){
        for (int i=1; i<=15; i+=1){
            map[j][i] = '-';
        }
    }
    
    for (int i=2; i<=14; i+=2){
        for (int j=1; j<=15; j+=2){
            map[j][i] = '|';
        }
    }
    return map;
}

//---------------------------------------------------Show Map------------------------------------------------------------------------
void show_map(char** map){
    
    for (int i=0; i<17; i++){
        cout << "                                              ";
        for (int j=0; j<17; j++){
            if(j==16){
                cout << map[i][16];
                printf("\n");
            }
            else{
                cout << map[i][j];
            }
        }
    }
}

//-------------------------------------------------Update Map--------------------------------------------------------------------------
void update_map(char** map, int row, int column, int flag){
    if (flag == 1){   // Black
        map[2*row-1][2*column-1] = 'B';
    }
    else if (flag == 0){
        map[2*row-1][2*column-1] = 'W';
    }
}

//-------------------------------------------------Move Black--------------------------------------------------------------------------
void move_black(char** map){
    for (int i=1; i<=8; i++){
        for (int j=1; j<=8; j++){
            if (map[2*i-1][2*j-1] == 'B'){  // Finding First Black stone
                for (int z=1; z<=8; z++){
                    for (int w=1; w<=8; w++){
                        if (map[2*z-1][2*w-1] == 'B'){  // Finding Second Black Stone 
                            double dis = sqrt(pow(i - z, 2) + pow(j - w, 2));
                            //-----------------------------------------------------------------------------------------------------------------
                            if (w == j){   // They are in same Column 
                                if (z>i){  // Second Black Stone is Lower in Table
                                    int white_number = 0;
                                    for (int k=i; k<z; k++){   // Loop between First and Second Black Stones in same Column.
                                        if (map[2*k-1][2*j-1] == 'W'){  // Counting the White Stones between two Black Stones.
                                            white_number+=1;
                                        }
                                    }
                                    if (dis-1 == white_number && dis != 1){  // if total number of white stones equals to dis-1 then we have white stones between two blacks
                                        for (int k=i+1; k<z; k++){
                                            map[2*k-1][2*j-1] = 'B';
                                            
                                        }
                                    }
                                    
                                }
                                else if (i>z){  // First Black Stone is Lower in Table
                                    int white_number = 0;
                                    for (int k=z+1; k<i; k++){   // Loop between First and Second Black Stones in same Column.
                                        if (map[2*k-1][2*j-1] == 'W'){  // Counting the White Stones between two Black Stones.
                                            white_number+=1;
                                        }
                                    }
                                    if (dis-1 == white_number && dis != 1){  // if total number of white stones equals to dis-1 then we have white stones between two blacks
                                        for (int k=z+1; k<i; k++){
                                            map[2*k-1][2*j-1] = 'B';
                                        }
                                    }
                                    
                                }
                            }
                            //----------------------------------------------------------------------------------------------------------------
                            else if (i == z){   // They are in same Row
                                if (w>j){  // Second Black Stone is right in Table
                                    int white_number = 0;
                                    for (int k=j; k<w; k++){   // Loop between First and Second Black Stones in same Column.
                                        if (map[2*i-1][2*k-1] == 'W'){  // Counting the White Stones between two Black Stones.
                                            white_number+=1;
                                        }
                                    }
                                    if (dis-1 == white_number && dis != 1){  // if total number of white stones equals to dis-1 then we have white stones between two blacks
                                        for (int k=j+1; k<w; k++){
                                            map[2*i-1][2*k-1] = 'B';
                                        }
                                    }
                                    
                                }
                                else if (j>w){  // First Black Stone is Lower in Table
                                    int white_number = 0;
                                    for (int k=w; k<j; k++){   // Loop between First and Second Black Stones in same Column.
                                        if (map[2*i-1][2*k-1] == 'W'){  // Counting the White Stones between two Black Stones.
                                            white_number+=1;
                                        }
                                    }
                                    if (dis-1 == white_number && dis != 1){  // if total number of white stones equals to dis-1 then we have white stones between two blacks
                                        for (int k=w+1; k<j; k++){
                                            map[2*i-1][2*k-1] = 'B';
                                        }
                                    }
                                    
                                }
                            }
                            //--------------------------------------------------------------------------------------------------------------------------
                            else if (dis == sqrt(8) || dis == sqrt(18) || dis == sqrt(32) || dis == sqrt(50) || dis == sqrt(72) || dis == sqrt(98)){   // They are in Orthogonal mode
                                //--------------------------------------------//
                                if (i<z && j<w){
                                    int white_number = 0;
                                    int block_number = 0;
                                    int row = i;
                                    int col = j;
                                    while (row <z){
                                        block_number+=1;
                                        if(map[2*row-1][2*col-1] == 'W'){
                                            white_number+=1;
                                        }
                                        row+=1;
                                        col+=1;
                                    }
                                    row = i+1;
                                    col = j+1;
                                    if (block_number-1 == white_number && block_number != 1){
                                        while (row <z){
                                            map[2*row-1][2*col-1] = 'B';
                                            row+=1;
                                            col+=1;
                                        }
                                    }
                                    
                                }
                                //--------------------------------------------//
                                else if (i<z && j>w){
                                    int white_number = 0;
                                    int block_number = 0;
                                    int row = i;
                                    int col = j;
                                    while (row <z){
                                        block_number+=1;
                                        if(map[2*row-1][2*col-1] == 'W'){
                                            white_number+=1;
                                        }
                                        row+=1;
                                        col-=1;
                                    }
                                    row = i+1;
                                    col = j-1;
                                    if (block_number-1 == white_number && block_number != 1){
                                        while (row <z){
                                            map[2*row-1][2*col-1] = 'B';
                                            row+=1;
                                            col-=1;
                                        }
                                    }
                                    
                                }
                                //--------------------------------------------//
                                else if (i>z && j<w){
                                    int white_number = 0;
                                    int block_number = 0;
                                    int row = i;
                                    int col = j;
                                    while (row >z){
                                        block_number+=1;
                                        if(map[2*row-1][2*col-1] == 'W'){
                                            white_number+=1;
                                        }
                                        row-=1;
                                        col+=1;
                                    }
                                    row = i-1;
                                    col = j+1;
                                    if (block_number-1 == white_number && block_number != 1){
                                        while (row >z){
                                            map[2*row-1][2*col-1] = 'B';
                                            row-=1;
                                            col+=1;
                                        }
                                    }
                                    
                                }
                                //--------------------------------------------//
                                else if (i>z && j>w){
                                    int white_number = 0;
                                    int block_number = 0;
                                    int row = i;
                                    int col = j;
                                    while (row >z){
                                        block_number+=1;
                                        if(map[2*row-1][2*col-1] == 'W'){
                                            white_number+=1;
                                        }
                                        row-=1;
                                        col-=1;
                                    }
                                    row = i-1;
                                    col = j-1;
                                    if (block_number-1 == white_number && block_number != 1){
                                        while (row >z){
                                            map[2*row-1][2*col-1] = 'B';
                                            row-=1;
                                            col-=1;
                                        }
                                    }
                                    
                                }
                            }
                            
                        }
                    }
                }
            }
        }
    }
}

//-------------------------------------------------Move White--------------------------------------------------------------------------
void move_white(char** map){
    for (int i=1; i<=8; i++){
        for (int j=1; j<=8; j++){
            if (map[2*i-1][2*j-1] == 'W'){  // Finding First White stone
                for (int z=1; z<=8; z++){
                    for (int w=1; w<=8; w++){
                        if (map[2*z-1][2*w-1] == 'W'){  // Finding Second White Stone 
                            double dis = sqrt(pow(i - z, 2) + pow(j - w, 2));
                            //-----------------------------------------------------------------------------------------------------------------
                            if (w == j){   // They are in same Column 
                                if (z>i){  // Second White Stone is Lower in Table
                                    int black_number = 0;
                                    for (int k=i; k<z; k++){   // Loop between First and Second Black Stones in same Column.
                                        if (map[2*k-1][2*j-1] == 'B'){  // Counting the White Stones between two Black Stones.
                                            black_number+=1;
                                        }
                                    }
                                    if (dis-1 == black_number && dis != 1){  // if total number of black stones equals to dis-1 then we have Black stones between two Whites
                                        for (int k=i+1; k<z; k++){
                                            map[2*k-1][2*j-1] = 'W';
                                            
                                        }
                                    }
                                    
                                }
                                else if (i>z){  // First White Stone is Lower in Table
                                    int black_number = 0;
                                    for (int k=z+1; k<i; k++){   // Loop between First and Second white Stones in same Column.
                                        if (map[2*k-1][2*j-1] == 'B'){  // Counting the black Stones between two white Stones.
                                            black_number+=1;
                                        }
                                    }
                                    if (dis-1 == black_number && dis != 1){  // if total number of black stones equals to dis-1 then we have white stones between two blacks
                                        for (int k=z+1; k<i; k++){
                                            map[2*k-1][2*j-1] = 'W';
                                        }
                                    }
                                    
                                }
                            }
                            //----------------------------------------------------------------------------------------------------------------
                            else if (i == z){   // They are in same Row
                                if (w>j){  // Second Black Stone is Lower in Table
                                    int black_number = 0;
                                    for (int k=j; k<w; k++){   // Loop between First and Second Black Stones in same Column.
                                        if (map[2*i-1][2*k-1] == 'B'){  // Counting the White Stones between two Black Stones.
                                            black_number+=1;
                                        }
                                    }
                                    if (dis-1 == black_number && dis != 1){  // if total number of black stones equals to dis-1 then we have black stones between two blacks
                                        for (int k=j+1; k<w; k++){
                                            map[2*i-1][2*k-1] = 'W';
                                        }
                                    }
                                    
                                }
                                else if (j>w){  // First Black Stone is Lower in Table
                                    int black_number = 0;
                                    for (int k=w; k<j; k++){   // Loop between First and Second white Stones in same Column.
                                        if (map[2*i-1][2*k-1] == 'B'){  // Counting the black Stones between two Black Stones.
                                            black_number+=1;
                                        }
                                    }
                                    if (dis-1 == black_number && dis != 1){  // if total number of Black stones equals to dis-1 then we have white stones between two blacks
                                        for (int k=w+1; k<j; k++){
                                            map[2*i-1][2*k-1] = 'W';
                                        }
                                    }
                                    
                                }
                            }
                            //--------------------------------------------------------------------------------------------------------------------------
                            else if (dis == sqrt(8) || dis == sqrt(18) || dis == sqrt(32) || dis == sqrt(50) || dis == sqrt(72) || dis == sqrt(98)){   // They are in Orthogonal mode
                                //--------------------------------------------//
                                if (i<z && j<w){
                                    int black_number = 0;
                                    int block_number = 0;
                                    int row = i;
                                    int col = j;
                                    while (row <z){
                                        block_number+=1;
                                        if(map[2*row-1][2*col-1] == 'B'){
                                            black_number+=1;
                                        }
                                        row+=1;
                                        col+=1;
                                    }
                                    row = i+1;
                                    col = j+1;
                                    if (block_number-1 == black_number){
                                        while (row <z){
                                            map[2*row-1][2*col-1] = 'W';
                                            row+=1;
                                            col+=1;
                                        }
                                    }
                                    
                                }
                                //--------------------------------------------//
                                else if (i<z && j>w){
                                    int black_number = 0;
                                    int block_number = 0;
                                    int row = i;
                                    int col = j;
                                    while (row <z){
                                        block_number+=1;
                                        if(map[2*row-1][2*col-1] == 'B'){
                                            black_number+=1;
                                        }
                                        row+=1;
                                        col-=1;
                                    }
                                    row = i+1;
                                    col = j-1;
                                    if (block_number-1 == black_number){
                                        while (row <z){
                                            map[2*row-1][2*col-1] = 'W';
                                            row+=1;
                                            col-=1;
                                        }
                                    }
                                    
                                }
                                //--------------------------------------------//
                                else if (i>z && j<w){
                                    int black_number = 0;
                                    int block_number = 0;
                                    int row = i;
                                    int col = j;
                                    while (row >z){
                                        block_number+=1;
                                        if(map[2*row-1][2*col-1] == 'B'){
                                            black_number+=1;
                                        }
                                        row-=1;
                                        col+=1;
                                    }
                                    row = i-1;
                                    col = j+1;
                                    if (block_number-1 == black_number){
                                        while (row >z){
                                            map[2*row-1][2*col-1] = 'W';
                                            row-=1;
                                            col+=1;
                                        }
                                    }
                                    
                                }
                                //--------------------------------------------//
                                else if (i>z && j>w){
                                    int black_number = 0;
                                    int block_number = 0;
                                    int row = i;
                                    int col = j;
                                    while (row >z){
                                        block_number+=1;
                                        if(map[2*row-1][2*col-1] == 'B'){
                                            black_number+=1;
                                        }
                                        row-=1;
                                        col-=1;
                                    }
                                    row = i-1;
                                    col = j-1;
                                    if (block_number-1 == black_number){
                                        while (row >z){
                                            map[2*row-1][2*col-1] = 'W';
                                            row-=1;
                                            col-=1;
                                        }
                                    }
                                    
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

//----------------------------------------------Black and White Counter Stones-----------------------------------------------------------------------------
bool black_white_counter(char** map){
    int b_c = 0;
    int w_c = 0;
    bool flag = false;
    for (int i=1; i<=8; i++){
        for (int j=1; j<=8; j++){
            if (map[2*i-1][2*j-1] == 'B'){
                b_c+=1;
            }
            else if (map[2*i-1][2*j-1] == 'W'){
                w_c+=1;
            }
        }
    }
    cout << "Black's Stones: " << b_c << endl;
    cout << "White's Stones: " << w_c << endl;
    
    if (b_c == 0){
        flag = true;
        cout<< "--------------------" << endl;
        cout<< "--------------------" << endl;
        cout << "White is Winner!" << endl;
        cout << "White Final Scores is: " << w_c << endl;
        cout<< "--------------------" << endl;
        cout<< "--------------------" << endl;
    }
    else if (w_c == 0){
        flag = true;
        cout<< "--------------------" << endl;
        cout<< "--------------------" << endl;
        cout << "Black is Winner!" << endl;
        cout << "Black Final Scores is: " << b_c << endl;
        cout<< "--------------------" << endl;
        cout<< "--------------------" << endl;
    }
    else if (w_c + b_c == 64){
        if (w_c > b_c){
            flag = true;
            cout<< "--------------------" << endl;
            cout<< "--------------------" << endl;
            cout << "White is Winner!" << endl;
            cout << "White Final Scores is: " << w_c << endl;
            cout<< "--------------------" << endl;
            cout<< "--------------------" << endl;
        }
        else if(w_c < b_c){
            flag = true;
            cout<< "--------------------" << endl;
            cout<< "--------------------" << endl;
            cout << "Black is Winner!" << endl;
            cout << "Black Final Scores is: " << b_c << endl;
            cout<< "--------------------" << endl;
            cout<< "--------------------" << endl;
        }
    }
    return flag;
}

//-----------------------------------------------Available Movement----------------------------------------------------------------------------
bool available_movement_black(char** map){
    bool my_flag = true;
    for (int i=1; i<=8; i++){
        for (int j=1; j<=8; j++){
            for (int z=1; z<=8; z++){
                for (int w=1; w<=8; w++){
                    if (map[2*z-1][2*w-1] == 'B'){  // Finding Second White Stone 
                        double dis = sqrt(pow(i - z, 2) + pow(j - w, 2));
                        //-----------------------------------------------------------------------------------------------------------------
                        if (w == j){   // They are in same Column 
                            if (z>i){  // Second White Stone is Lower in Table
                                int white_number = 0;
                                for (int k=i; k<z; k++){   // Loop between First and Second Black Stones in same Column.
                                    if (map[2*k-1][2*j-1] == 'W'){  // Counting the White Stones between two Black Stones.
                                        white_number+=1;
                                    }
                                }
                                //cout << "black num: " << black_number<< endl;
                                if (dis-1 == white_number && dis-1 != 0 && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W' && white_number !=0){  // if total number of black stones equals to dis-1 then we have Black stones between two Whites
                                    cout << "Optional Row for Black: " << i <<endl;
                                    cout << "Optional Column for Black: " << j <<endl;
                                    cout<< "------------------------------" << endl;
                                    my_flag = false;
                                }
                                
                            }
                            else if (i>z){  // First White Stone is Lower in Table
                                int white_number = 0;
                                for (int k=z+1; k<i; k++){   // Loop between First and Second white Stones in same Column.
                                    if (map[2*k-1][2*j-1] == 'W'){  // Counting the black Stones between two white Stones.
                                        white_number+=1;
                                    }
                                }
                                if (dis-1 == white_number && dis-1 != 0 && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W' && white_number !=0){  // if total number of black stones equals to dis-1 then we have white stones between two blacks
                                    cout << "Optional Row for Black: " << i <<endl;
                                    cout << "Optional Column for Black: " << j <<endl;
                                    cout<< "------------------------------" << endl;
                                    my_flag = false;
                                }
                                
                            }
                        }
                        //----------------------------------------------------------------------------------------------------------------
                        else if (i == z){   // They are in same Row
                            if (w>j){  // Second Black Stone is Lower in Table
                                int white_number = 0;
                                for (int k=j; k<w; k++){   // Loop between First and Second Black Stones in same Column.
                                    if (map[2*i-1][2*k-1] == 'W'){  // Counting the White Stones between two Black Stones.
                                        white_number+=1;
                                    }
                                }
                                if (dis-1 == white_number && dis-1 != 0 && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W' && white_number !=0){  // if total number of black stones equals to dis-1 then we have black stones between two blacks
                                    cout << "Optional Row for Black: " << i <<endl;
                                    cout << "Optional Column for Black: " << j <<endl;
                                    cout<< "------------------------------" << endl;
                                    my_flag = false;
                                    
                                }
                                
                            }
                            else if (j>w){  // First Black Stone is Lower in Table
                                int white_number = 0;
                                for (int k=w; k<j; k++){   // Loop between First and Second white Stones in same Column.
                                    if (map[2*i-1][2*k-1] == 'W'){  // Counting the black Stones between two Black Stones.
                                        white_number+=1;
                                    }
                                }
                                if (dis-1 == white_number && dis-1 != 0 && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W' && white_number !=0){  // if total number of Black stones equals to dis-1 then we have white stones between two blacks
                                    cout << "Optional Row for Black: " << i <<endl;
                                    cout << "Optional Column for Black: " << j <<endl;
                                    cout<< "------------------------------" << endl;
                                    my_flag = false;
                                }
                                
                            }
                        }
                        //--------------------------------------------------------------------------------------------------------------------------
                        else if (dis == sqrt(8) || dis == sqrt(18) || dis == sqrt(32) || dis == sqrt(50) || dis == sqrt(72) || dis == sqrt(98)){   // They are in Orthogonal mode
                            //--------------------------------------------//
                            if (i<z && j<w){
                                int white_number = 0;
                                int block_number = 0;
                                int row = i;
                                int col = j;
                                while (row <z){
                                    block_number+=1;
                                    if(map[2*row-1][2*col-1] == 'W'){
                                        white_number+=1;
                                    }
                                    row+=1;
                                    col+=1;
                                }
                                row = i+1;
                                col = j+1;
                                if (block_number-1 == white_number && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W' && white_number !=0){
                                    cout << "Optional Row for Black: " << i <<endl;
                                    cout << "Optional Column for Black: " << j <<endl;
                                    cout<< "------------------------------" << endl;
                                    my_flag = false;
                                }
                            }
                            //--------------------------------------------//
                            else if (i<z && j>w){
                                int white_number = 0;
                                int block_number = 0;
                                int row = i;
                                int col = j;
                                while (row <z){
                                    block_number+=1;
                                    if(map[2*row-1][2*col-1] == 'W'){
                                        white_number+=1;
                                    }
                                    row+=1;
                                    col-=1;
                                }
                                row = i+1;
                                col = j-1;
                                if (block_number-1 == white_number && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W' && white_number !=0){
                                    cout << "Optional Row for Black: " << i <<endl;
                                    cout << "Optional Column for Black: " << j <<endl;
                                    cout<< "------------------------------" << endl;
                                    my_flag = false;
                                }
                                
                            }
                            //--------------------------------------------//
                            else if (i>z && j<w){
                                int white_number = 0;
                                int block_number = 0;
                                int row = i;
                                int col = j;
                                while (row >z){
                                    block_number+=1;
                                    if(map[2*row-1][2*col-1] == 'W'){
                                        white_number+=1;
                                    }
                                    row-=1;
                                    col+=1;
                                }
                                row = i-1;
                                col = j+1;
                                if (block_number-1 == white_number && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W' && white_number !=0){
                                    cout << "Optional Row for Black: " << i <<endl;
                                    cout << "Optional Column for Black: " << j <<endl;
                                    cout<< "------------------------------" << endl;
                                    my_flag = false;
                                }
                                
                            }
                            //--------------------------------------------//
                            else if (i>z && j>w){
                                int white_number = 0;
                                int block_number = 0;
                                int row = i;
                                int col = j;
                                while (row >z){
                                    block_number+=1;
                                    if(map[2*row-1][2*col-1] == 'W'){
                                        white_number+=1;
                                    }
                                    row-=1;
                                    col-=1;
                                }
                                row = i-1;
                                col = j-1;
                                if (block_number-1 == white_number && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W' && white_number !=0){
                                    cout << "Optional Row for Black: " << i <<endl;
                                    cout << "Optional Column for Black: " << j <<endl;
                                    cout<< "------------------------------" << endl;
                                    my_flag = false;
                                }
                                
                            }
                        }
                    }
                }
            }
        }
    }
    return my_flag;
}

//-----------------------------------------------Available Movement----------------------------------------------------------------------------
bool available_movement_white(char** map){
    bool my_flag = true;
    for (int i=1; i<=8; i++){
        for (int j=1; j<=8; j++){
            for (int z=1; z<=8; z++){
                for (int w=1; w<=8; w++){
                    if (map[2*z-1][2*w-1] == 'W'){  // Finding Second White Stone 
                        double dis = sqrt(pow(i - z, 2) + pow(j - w, 2));
                        //-----------------------------------------------------------------------------------------------------------------
                        if (w == j){   // They are in same Column 
                            if (z>i){  // Second White Stone is Lower in Table
                                int black_number = 0;
                                for (int k=i; k<z; k++){   // Loop between First and Second Black Stones in same Column.
                                    if (map[2*k-1][2*j-1] == 'B'){  // Counting the White Stones between two Black Stones.
                                        black_number+=1;
                                    }
                                }
                                //cout << "black num: " << black_number<< endl;
                                if (dis-1 == black_number && dis-1 != 0 && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W' && black_number !=0){  // if total number of black stones equals to dis-1 then we have Black stones between two Whites
                                    cout << "Optional Row for White: " << i <<endl;
                                    cout << "Optional Column for White: " << j <<endl;
                                    cout<< "------------------------------" << endl;
                                    my_flag = false;
                                }
                                
                            }
                            else if (i>z){  // First White Stone is Lower in Table
                                int black_number = 0;
                                for (int k=z+1; k<i; k++){   // Loop between First and Second white Stones in same Column.
                                    if (map[2*k-1][2*j-1] == 'B'){  // Counting the black Stones between two white Stones.
                                        black_number+=1;
                                    }
                                }
                                if (dis-1 == black_number && dis-1 != 0 && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W' && black_number !=0){  // if total number of black stones equals to dis-1 then we have white stones between two blacks
                                    cout << "Optional Row for White: " << i <<endl;
                                    cout << "Optional Column for White: " << j <<endl;
                                    cout<< "------------------------------" << endl;
                                    my_flag = false;
                                }
                                
                                
                            }
                        }
                        //----------------------------------------------------------------------------------------------------------------
                        else if (i == z){   // They are in same Row
                            if (w>j){  // Second Black Stone is Lower in Table
                                int black_number = 0;
                                for (int k=j; k<w; k++){   // Loop between First and Second Black Stones in same Column.
                                    if (map[2*i-1][2*k-1] == 'B'){  // Counting the White Stones between two Black Stones.
                                        black_number+=1;
                                    }
                                }
                                if (dis-1 == black_number && dis-1 != 0 && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W' && black_number !=0){  // if total number of black stones equals to dis-1 then we have black stones between two blacks
                                    cout << "Optional Row for White: " << i <<endl;
                                    cout << "Optional Column for White: " << j <<endl;
                                    cout<< "------------------------------" << endl;
                                    my_flag = false;
                                    
                                }
                                
                            }
                            else if (j>w){  // First Black Stone is Lower in Table
                                int black_number = 0;
                                for (int k=w; k<j; k++){   // Loop between First and Second white Stones in same Column.
                                    if (map[2*i-1][2*k-1] == 'B'){  // Counting the black Stones between two Black Stones.
                                        black_number+=1;
                                    }
                                }
                                if (dis-1 == black_number && dis-1 != 0 && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W' && black_number !=0){  // if total number of Black stones equals to dis-1 then we have white stones between two blacks
                                    cout << "Optional Row for White: " << i <<endl;
                                    cout << "Optional Column for White: " << j <<endl;
                                    cout<< "------------------------------" << endl;
                                    my_flag = false;
                                }
                                
                            }
                        }
                        //--------------------------------------------------------------------------------------------------------------------------
                        else if (dis == sqrt(8) || dis == sqrt(18) || dis == sqrt(32) || dis == sqrt(50) || dis == sqrt(72) || dis == sqrt(98)){   // They are in Orthogonal mode
                            //--------------------------------------------//
                            if (i<z && j<w){
                                int black_number = 0;
                                int block_number = 0;
                                int row = i;
                                int col = j;
                                while (row <z){
                                    block_number+=1;
                                    if(map[2*row-1][2*col-1] == 'B'){
                                        black_number+=1;
                                    }
                                    row+=1;
                                    col+=1;
                                }
                                row = i+1;
                                col = j+1;
                                if (block_number-1 == black_number && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W' && black_number !=0){
                                    cout << "Optional Row for White: " << i <<endl;
                                    cout << "Optional Column for White: " << j <<endl;
                                    cout<< "------------------------------" << endl;
                                    my_flag = false;
                                }
                                
                            }
                            //--------------------------------------------//
                            else if (i<z && j>w){
                                int black_number = 0;
                                int block_number = 0;
                                int row = i;
                                int col = j;
                                while (row <z){
                                    block_number+=1;
                                    if(map[2*row-1][2*col-1] == 'B'){
                                        black_number+=1;
                                    }
                                    row+=1;
                                    col-=1;
                                }
                                row = i+1;
                                col = j-1;
                                if (block_number-1 == black_number && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W' && black_number !=0){
                                    cout << "Optional Row for White: " << i <<endl;
                                    cout << "Optional Column for White: " << j <<endl;
                                    cout<< "------------------------------" << endl;
                                    my_flag = false;
                                }
                            }
                                
                            //--------------------------------------------//
                            else if (i>z && j<w){
                                int black_number = 0;
                                int block_number = 0;
                                int row = i;
                                int col = j;
                                while (row >z){
                                    block_number+=1;
                                    if(map[2*row-1][2*col-1] == 'B'){
                                        black_number+=1;
                                    }
                                    row-=1;
                                    col+=1;
                                }
                                row = i-1;
                                col = j+1;
                                if (block_number-1 == black_number && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W' && black_number !=0){
                                    cout << "Optional Row for White: " << i <<endl;
                                    cout << "Optional Column for White: " << j <<endl;
                                    cout<< "------------------------------" << endl;
                                    my_flag = false;
                                }
                                
                            }
                            //--------------------------------------------//
                            else if (i>z && j>w){
                                int black_number = 0;
                                int block_number = 0;
                                int row = i;
                                int col = j;
                                while (row >z){
                                    block_number+=1;
                                    if(map[2*row-1][2*col-1] == 'B'){
                                        black_number+=1;
                                    }
                                    row-=1;
                                    col-=1;
                                }
                                row = i-1;
                                col = j-1;
                                if (block_number-1 == black_number && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W' && black_number !=0){
                                    cout << "Optional Row for White: " << i <<endl;
                                    cout << "Optional Column for White: " << j <<endl;
                                    cout<< "------------------------------" << endl;
                                    my_flag = false;
                                }
                                
                            }
                        }
                    }
                }
            }
        }
    }
    return my_flag;
}

//-----------------------------------------------Correction Movement Black----------------------------------------------------------------------------
bool correction_movement_black(char** map, int black_row, int black_column){
    bool my_flag = true;
    for (int i=1; i<=8; i++){
        for (int j=1; j<=8; j++){
            for (int z=1; z<=8; z++){
                for (int w=1; w<=8; w++){
                    if (map[2*z-1][2*w-1] == 'B'){  // Finding Second White Stone 
                        double dis = sqrt(pow(i - z, 2) + pow(j - w, 2));
                        //-----------------------------------------------------------------------------------------------------------------
                        if (w == j){   // They are in same Column 
                            if (z>i){  // Second White Stone is Lower in Table
                                int black_number = 0;
                                for (int k=i; k<z; k++){   // Loop between First and Second Black Stones in same Column.
                                    if (map[2*k-1][2*j-1] == 'W'){  // Counting the White Stones between two Black Stones.
                                        black_number+=1;
                                    }
                                }
                                //cout << "black num: " << black_number<< endl;
                                if (dis-1 == black_number && dis-1 != 0 && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W'){  // if total number of black stones equals to dis-1 then we have Black stones between two Whites
                                    if (i == black_row && j == black_column){
                                        map[2*black_row-1][2*black_column-1] = 'B';
                                        my_flag = false;
                                    }
                                }
                            }
                            else if (i>z){  // First White Stone is Lower in Table
                                int black_number = 0;
                                for (int k=z+1; k<i; k++){   // Loop between First and Second white Stones in same Column.
                                    if (map[2*k-1][2*j-1] == 'W'){  // Counting the black Stones between two white Stones.
                                        black_number+=1;
                                    }
                                }
                                if (dis-1 == black_number && dis-1 != 0 && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W'){  // if total number of black stones equals to dis-1 then we have white stones between two blacks
                                    if (i == black_row && j == black_column){
                                        map[2*black_row-1][2*black_column-1] = 'B';
                                        my_flag = false;
                                    }
                                }
                            }
                        }
                        //----------------------------------------------------------------------------------------------------------------
                        else if (i == z){   // They are in same Row
                            if (w>j){  // Second Black Stone is Lower in Table
                                int black_number = 0;
                                for (int k=j; k<w; k++){   // Loop between First and Second Black Stones in same Column.
                                    if (map[2*i-1][2*k-1] == 'W'){  // Counting the White Stones between two Black Stones.
                                        black_number+=1;
                                    }
                                }
                                if (dis-1 == black_number && dis-1 != 0 && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W'){  // if total number of black stones equals to dis-1 then we have black stones between two blacks
                                    if (i == black_row && j == black_column){
                                        map[2*black_row-1][2*black_column-1] = 'B';
                                        my_flag = false;
                                    }
                                    
                                }
                            }
                            else if (j>w){  // First Black Stone is Lower in Table
                                int black_number = 0;
                                for (int k=w; k<j; k++){   // Loop between First and Second white Stones in same Column.
                                    if (map[2*i-1][2*k-1] == 'W'){  // Counting the black Stones between two Black Stones.
                                        black_number+=1;
                                    }
                                }
                                if (dis-1 == black_number && dis-1 != 0 && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W'){  // if total number of Black stones equals to dis-1 then we have white stones between two blacks
                                    if (i == black_row && j == black_column){
                                        map[2*black_row-1][2*black_column-1] = 'B';
                                        my_flag = false;
                                    }
                                }
                            }
                        }
                        //--------------------------------------------------------------------------------------------------------------------------
                        else if (dis == sqrt(8) || dis == sqrt(18) || dis == sqrt(32) || dis == sqrt(50) || dis == sqrt(72) || dis == sqrt(98)){   // They are in Orthogonal mode
                            //--------------------------------------------//
                            if (i<z && j<w){
                                int black_number = 0;
                                int block_number = 0;
                                int row = i;
                                int col = j;
                                while (row <z){
                                    block_number+=1;
                                    if(map[2*row-1][2*col-1] == 'W'){
                                        black_number+=1;
                                    }
                                    row+=1;
                                    col+=1;
                                }
                                row = i+1;
                                col = j+1;
                                if (block_number-1 == black_number && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W'){
                                    if (i == black_row && j == black_column){
                                        map[2*black_row-1][2*black_column-1] = 'B';
                                        my_flag = false;
                                    }
                                }
                            }
                            //--------------------------------------------//
                            else if (i<z && j>w){
                                int black_number = 0;
                                int block_number = 0;
                                int row = i;
                                int col = j;
                                while (row <z){
                                    block_number+=1;
                                    if(map[2*row-1][2*col-1] == 'W'){
                                        black_number+=1;
                                    }
                                    row+=1;
                                    col-=1;
                                }
                                row = i+1;
                                col = j-1;
                                if (block_number-1 == black_number && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W'){
                                    if (i == black_row && j == black_column){
                                        map[2*black_row-1][2*black_column-1] = 'B';
                                        my_flag = false;
                                    }
                                }
                            }
                            //--------------------------------------------//
                            else if (i>z && j<w){
                                int black_number = 0;
                                int block_number = 0;
                                int row = i;
                                int col = j;
                                while (row >z){
                                    block_number+=1;
                                    if(map[2*row-1][2*col-1] == 'W'){
                                        black_number+=1;
                                    }
                                    row-=1;
                                    col+=1;
                                }
                                row = i-1;
                                col = j+1;
                                if (block_number-1 == black_number && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W'){
                                    if (i == black_row && j == black_column){
                                        map[2*black_row-1][2*black_column-1] = 'B';
                                        my_flag = false;
                                    }
                                }
                            }
                            //--------------------------------------------//
                            else if (i>z && j>w){
                                int black_number = 0;
                                int block_number = 0;
                                int row = i;
                                int col = j;
                                while (row >z){
                                    block_number+=1;
                                    if(map[2*row-1][2*col-1] == 'W'){
                                        black_number+=1;
                                    }
                                    row-=1;
                                    col-=1;
                                }
                                row = i-1;
                                col = j-1;
                                if (block_number-1 == black_number && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W'){
                                    if (i == black_row && j == black_column){
                                        map[2*black_row-1][2*black_column-1] = 'B';
                                        my_flag = false;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return my_flag;
}

//-----------------------------------------------Correction Movement White----------------------------------------------------------------------------
bool correction_movement_white(char** map, int white_row, int white_column){
    bool my_flag = true;
    for (int i=1; i<=8; i++){
        for (int j=1; j<=8; j++){
            for (int z=1; z<=8; z++){
                for (int w=1; w<=8; w++){
                    if (map[2*z-1][2*w-1] == 'W'){  // Finding Second White Stone 
                        double dis = sqrt(pow(i - z, 2) + pow(j - w, 2));
                        //-----------------------------------------------------------------------------------------------------------------
                        if (w == j){   // They are in same Column 
                            if (z>i){  // Second White Stone is Lower in Table
                                int black_number = 0;
                                for (int k=i; k<z; k++){   // Loop between First and Second Black Stones in same Column.
                                    if (map[2*k-1][2*j-1] == 'B'){  // Counting the White Stones between two Black Stones.
                                        black_number+=1;
                                    }
                                }
                                //cout << "black num: " << black_number<< endl;
                                if (dis-1 == black_number && dis-1 != 0 && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W'){  // if total number of black stones equals to dis-1 then we have Black stones between two Whites
                                    if (i == white_row && j == white_column){
                                        map[2*white_row-1][2*white_column-1] = 'W';
                                        my_flag = false;
                                    }
                                }
                            }
                            else if (i>z){  // First White Stone is Lower in Table
                                int black_number = 0;
                                for (int k=z+1; k<i; k++){   // Loop between First and Second white Stones in same Column.
                                    if (map[2*k-1][2*j-1] == 'B'){  // Counting the black Stones between two white Stones.
                                        black_number+=1;
                                    }
                                }
                                if (dis-1 == black_number && dis-1 != 0 && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W'){  // if total number of black stones equals to dis-1 then we have white stones between two blacks
                                    if (i == white_row && j == white_column){
                                        map[2*white_row-1][2*white_column-1] = 'W';
                                        my_flag = false;
                                    }
                                }
                            }
                        }
                        //----------------------------------------------------------------------------------------------------------------
                        else if (i == z){   // They are in same Row
                            if (w>j){  // Second Black Stone is Lower in Table
                                int black_number = 0;
                                for (int k=j; k<w; k++){   // Loop between First and Second Black Stones in same Column.
                                    if (map[2*i-1][2*k-1] == 'B'){  // Counting the White Stones between two Black Stones.
                                        black_number+=1;
                                    }
                                }
                                if (dis-1 == black_number && dis-1 != 0 && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W'){  // if total number of black stones equals to dis-1 then we have black stones between two blacks
                                    if (i == white_row && j == white_column){
                                        map[2*white_row-1][2*white_column-1] = 'W';
                                        my_flag = false;
                                    }
                                    
                                }
                            }
                            else if (j>w){  // First Black Stone is Lower in Table
                                int black_number = 0;
                                for (int k=w; k<j; k++){   // Loop between First and Second white Stones in same Column.
                                    if (map[2*i-1][2*k-1] == 'B'){  // Counting the black Stones between two Black Stones.
                                        black_number+=1;
                                    }
                                }
                                if (dis-1 == black_number && dis-1 != 0 && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W'){  // if total number of Black stones equals to dis-1 then we have white stones between two blacks
                                    if (i == white_row && j == white_column){
                                        map[2*white_row-1][2*white_column-1] = 'W';
                                        my_flag = false;
                                    }
                                }
                            }
                        }
                        //--------------------------------------------------------------------------------------------------------------------------
                        else if (dis == sqrt(8) || dis == sqrt(18) || dis == sqrt(32) || dis == sqrt(50) || dis == sqrt(72) || dis == sqrt(98)){   // They are in Orthogonal mode
                            //--------------------------------------------//
                            if (i<z && j<w){
                                int black_number = 0;
                                int block_number = 0;
                                int row = i;
                                int col = j;
                                while (row <z){
                                    block_number+=1;
                                    if(map[2*row-1][2*col-1] == 'B'){
                                        black_number+=1;
                                    }
                                    row+=1;
                                    col+=1;
                                }
                                row = i+1;
                                col = j+1;
                                if (block_number-1 == black_number && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W'){
                                    if (i == white_row && j == white_column){
                                        map[2*white_row-1][2*white_column-1] = 'W';
                                        my_flag = false;
                                    }
                                }
                            }
                            //--------------------------------------------//
                            else if (i<z && j>w){
                                int black_number = 0;
                                int block_number = 0;
                                int row = i;
                                int col = j;
                                while (row <z){
                                    block_number+=1;
                                    if(map[2*row-1][2*col-1] == 'B'){
                                        black_number+=1;
                                    }
                                    row+=1;
                                    col-=1;
                                }
                                row = i+1;
                                col = j-1;
                                if (block_number-1 == black_number && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W'){
                                    if (i == white_row && j == white_column){
                                        map[2*white_row-1][2*white_column-1] = 'W';
                                        my_flag = false;
                                    }
                                }
                            }
                            //--------------------------------------------//
                            else if (i>z && j<w){
                                int black_number = 0;
                                int block_number = 0;
                                int row = i;
                                int col = j;
                                while (row >z){
                                    block_number+=1;
                                    if(map[2*row-1][2*col-1] == 'B'){
                                        black_number+=1;
                                    }
                                    row-=1;
                                    col+=1;
                                }
                                row = i-1;
                                col = j+1;
                                if (block_number-1 == black_number && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W'){
                                    if (i == white_row && j == white_column){
                                        map[2*white_row-1][2*white_column-1] = 'W';
                                        my_flag = false;
                                    }
                                }
                            }
                            //--------------------------------------------//
                            else if (i>z && j>w){
                                int black_number = 0;
                                int block_number = 0;
                                int row = i;
                                int col = j;
                                while (row >z){
                                    block_number+=1;
                                    if(map[2*row-1][2*col-1] == 'B'){
                                        black_number+=1;
                                    }
                                    row-=1;
                                    col-=1;
                                }
                                row = i-1;
                                col = j-1;
                                if (block_number-1 == black_number && map[2*i-1][2*j-1] != 'B' && map[2*i-1][2*j-1] != 'W'){
                                    if (i == white_row && j == white_column){
                                        map[2*white_row-1][2*white_column-1] = 'W';
                                        my_flag = false;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return my_flag;
}


//-----------------------------------------------Main----------------------------------------------------------------------------
int main(int argc, char **argv) {
    
    int turn = 1;  // ODD for Black and Even for White
    char** game_map = define_map();
    show_map(game_map);
    bool no_move_black = false;
    bool no_move_white = false;
    bool finished_game = false;
    bool yes_no_black = false;
    bool yes_no_white = false;
    
    while(finished_game != true){
        if(turn%2 == 0){         // White Turn
            int white_row;
            int white_column;
            no_move_white = available_movement_white(game_map);
            
            if (no_move_white == false){
            
                cout<< "------------" << endl;
                cout<< "White Turn!" << endl;
                cout<< "------------" << endl;
                //----------------------------
                cout << "Input Row: ";
                //cout<< "------------" << endl;
                cin >> white_row;
                //----------------------------
                cout << "Input Column: ";
                cin >> white_column;
                cout<< "------------" << endl;
                
                if (game_map[2*white_row-1][2*white_column-1] != 'B' && game_map[2*white_row-1][2*white_column-1] != 'W'){
                    //flag_black_white = 0; 
                    //update_map(game_map, white_row, white_column, flag_black_white);
                    yes_no_white = correction_movement_white(game_map, white_row, white_column);
                    if (yes_no_white == false){
                        move_white(game_map);
                    }
                    cout<< "------------" << endl;
                    finished_game = black_white_counter(game_map);
                    show_map(game_map);
                    turn+=1;
                }
                else if (game_map[2*white_row-1][2*white_column-1] == 'B' || game_map[2*white_row-1][2*white_column-1] == 'W'){
                    cout << "Invalid Input! Please Import Correct Row ans Column!" << endl;
                }
            }
            else{
                turn+=1;
            }
        }
        
        else if(turn%2 != 0){    // Black Turn
            int black_row;
            int black_column;
            no_move_black = available_movement_black(game_map);
            
            if(no_move_black == false){
                cout<< "------------" << endl;
                cout<< "Black Turn!" << endl;
                cout<< "------------" << endl;
                //----------------------------
                cout << "Input Row: ";
                cin >> black_row;
                //----------------------------
                cout << "Input Column: ";
                cin >> black_column;
                
                if (game_map[2*black_row-1][2*black_column-1] != 'B' && game_map[2*black_row-1][2*black_column-1] != 'W'){
                    yes_no_black = correction_movement_black(game_map, black_row, black_column);
                    if (yes_no_black == false){
                        move_black(game_map);
                    }
                    cout<< "------------" << endl;
                    finished_game = black_white_counter(game_map);
                    show_map(game_map);
                    turn+=1;
                }
                else if (game_map[2*black_row-1][2*black_column-1] == 'B' || game_map[2*black_row-1][2*black_column-1] == 'W'){
                    cout << "Invalid Input! Please Import Correct Row ans Column!" << endl;
                }
            }
            else{
                turn+=1;
            }
        }
        if (no_move_black == true && no_move_white == true){
            finished_game = true;
            int b_c = 0;
            int w_c = 0;
            for (int i=1; i<=8; i++){
                for (int j=1; j<=8; j++){
                    if (game_map[2*i-1][2*j-1] == 'B'){
                        b_c+=1;
                    }
                    else if (game_map[2*i-1][2*j-1] == 'W'){
                        w_c+=1;
                    }
                }
            }
            if (b_c > w_c){
                cout<< "--------------------" << endl;
                cout<< "--------------------" << endl;
                cout << "Black is Winner!" << endl;
                cout << "Black Final Scores is: " << b_c << endl;
                cout<< "--------------------" << endl;
                cout<< "--------------------" << endl;
            }
            else if (w_c > b_c){
                cout<< "--------------------" << endl;
                cout<< "--------------------" << endl;
                cout << "White is Winner!" << endl;
                cout << "White Final Score is: " << w_c << endl;
                cout<< "--------------------" << endl;
                cout<< "--------------------" << endl;
            }
            else{
                cout<< "--------------------" << endl;
                cout<< "--------------------" << endl;
                cout << "Equal !!!" << endl;
                cout << "White Final Score is: " << w_c << endl;
                cout << "Black Final Score is: " << b_c << endl;
                cout<< "--------------------" << endl;
                cout<< "--------------------" << endl;
                
            }
        }
    }
    return 0;
}


 