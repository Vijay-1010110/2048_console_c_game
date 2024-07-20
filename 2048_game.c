#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>


void detectArrowKeyPress(int arr[4][4]);
void display(int arr[4][4]);
void clearScreen();
void generateRandomNumber(int arr[4][4]);
void rightShift(int arr[4][4]);
void leftShift(int arr[4][4]);
void upShift(int arr[4][4]);
void downShift(int arr[4][4]);


int main(){

    int arr[4][4] = {0};
    printf("\n");
    generateRandomNumber(arr);
    generateRandomNumber(arr);
    display(arr);
    printf("2048 Game\n");
    detectArrowKeyPress(arr);
    return 0;
}


void display(int arr[4][4]){
    //clear screen first
    clearScreen();
    for(int i = 0 ; i < 4 ; i++){
        for(int j = 0 ; j < 4 ; j++){
            if(arr[i][j] == 0)
            printf("%5c ",'-');
            else
            printf("%5d ",arr[i][j]);
        }
        printf("\n\n");
    }
}

void generateRandomNumber(int arr[4][4]){
   
    srand(time(NULL));
    int random = rand()%10+1;
    int value = random > 2 ? 2 : 4 ;
    int i,j ;
    int found = 0;
    for(i = 3 ; i >= 0 ; i--){
        for(j = 3 ; j >= 0 ; j--){
            if(arr[i][j] == 0){
                found = 1;
                break;
            }
        }  
    }

      if(!found){
        printf("\nGame Over!...");
        exit(-1);
      } 
    
    for(; 1 ; ){
        int ri = rand()%4;
        int rj = rand()%4;
      //  printf("ri %d rj %d \n",ri,rj);
        if(arr[ri][rj] ==  0){
            arr[ri][rj] = value;
            break;
        }

    }
}


// Function to clear the screen
void clearScreen() {
    #ifdef _WIN32
    system("cls"); // For Windows
    #else
    system("clear"); // For Unix-based systems (Linux, macOS)
    #endif
}

//detect Arror key is pressed
void detectArrowKeyPress(int arr[4][4]) {
    while (1) {
        if (_kbhit()) {
            int key = _getch();
            if (key == 0xE0) {
                int arrowKey = _getch();
                switch (arrowKey) {
                    case 75: // Left arrow
                        leftShift(arr);
                        break;
                    case 77: // Right arrow
                        rightShift(arr);
                        break;
                    case 72: // Up arrow
                        upShift(arr);
                        break;
                    case 80: // Down arrow
                        downShift(arr);
                        break;
                }
            }
        }
    }
}

//rightShift
void rightShift(int arr[4][4]){
    int i=0,j=0;
   
  for(i = 0; i < 4; i++) {
        int temp =0;
        int k = 3; // Initialize k to the rightmost column
        for(j = 3; j >= 0; j--) {
            if (arr[i][j] != 0) {
                arr[i][k] = arr[i][j];

                if(temp == arr[i][k]){
                    arr[i][k+1]=arr[i][k]+temp;
                    arr[i][k] = 0 ;
                    temp = arr[i][k+1];
                    if (k != j) {
                    arr[i][j] = 0;
                }
                    continue;
                }
                temp = arr[i][k];
                k--;         
            }
        }
    }
    generateRandomNumber(arr);
    display(arr);
}

//leftShift
void leftShift(int arr[4][4]){
    int i=0,j=0;   
  for(i = 0; i < 4; i++) {
        int temp =0;
        int k = 0; // Initialize k to the rightmost column
        for(j = 0; j < 4; j++) {
            if (arr[i][j] != 0) {
                arr[i][k] = arr[i][j];

                if(temp == arr[i][k]){
                    arr[i][k-1]=arr[i][k]+temp;
                    arr[i][k] = 0 ;
                    temp = arr[i][k+1];
                    if (k != j) {
                    arr[i][j] = 0;
                }
                    continue;
                }
                temp = arr[i][k];
                k++;         
            }
        }
    }
    generateRandomNumber(arr);
    display(arr);
}

//up shift
void upShift(int arr[4][4]) {
    int i, j;
    for (j = 0; j < 4; j++) {
        int temp = 0;
        int k = 0; // Initialize k to the top row
        for (i = 0; i < 4; i++) {
            if (arr[i][j] != 0) {
                arr[k][j] = arr[i][j];
                if (temp == arr[k][j]) {
                    arr[k - 1][j] = arr[k][j] + temp;
                    arr[k][j] = 0;
                    temp = arr[k - 1][j];
                    if (k != i) {
                        arr[i][j] = 0;
                    }
                    continue;
                }
                temp = arr[k][j];
                k++;
            }
        }
    }
    generateRandomNumber(arr);
    display(arr);
}

//down shift
void downShift(int arr[4][4]) {
    int i, j;
    for (j = 0; j < 4; j++) {
        int temp = 0;
        int k = 3; // Initialize k to the bottom row
        for (i = 3; i >= 0; i--) {
            if (arr[i][j] != 0) {
                arr[k][j] = arr[i][j];
                if (temp == arr[k][j]) {
                    arr[k + 1][j] = arr[k][j] + temp;
                    arr[k][j] = 0;
                    temp = arr[k + 1][j];
                    if (k != i) {
                        arr[i][j] = 0;
                    }
                    continue;
                }
                temp = arr[k][j];
                k--;
            }
        }
    }
    generateRandomNumber(arr);
    display(arr);
}



