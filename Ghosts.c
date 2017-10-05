#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void print(int n, int time){
    for(int i = 0; i <= time; i++){
        for(int j = 0; j < (int)sqrt(n); j++){
            if(i%2==0){
                for(int k = 0; k < (int)sqrt(n); k++){ printf("   ▄▄▄     "); }
                printf("\n");
                for(int k = 0; k < (int)sqrt(n); k++){ printf("  ▀█▀██  ▄ "); }
                printf("\n");
                for(int k = 0; k < (int)sqrt(n); k++){ printf("▀▄██████▀  "); }
                printf("\n");
                for(int k = 0; k < (int)sqrt(n); k++){ printf("   ▀█████  "); }
                printf("\n");
                for(int k = 0; k < (int)sqrt(n); k++){ printf("      ▀▀▀▀▄"); }
                printf("\n");
            }else{ 
                for(int k = 0; k < (int)sqrt(n); k++){ printf("     ▄▄▄   "); }
                printf("\n");
                for(int k = 0; k < (int)sqrt(n); k++){ printf(" ▄  ██▀█▀  "); }
                printf("\n");
                for(int k = 0; k < (int)sqrt(n); k++){ printf("  ▀██████▄▀"); }
                printf("\n");
                for(int k = 0; k < (int)sqrt(n); k++){ printf("  █████▀   "); }
                printf("\n");
                for(int k = 0; k < (int)sqrt(n); k++){ printf("▄▀▀▀▀      "); }
                printf("\n");
            }
        }
        //waits and then erases previous ghosts
        sleep(1);
        for(int k=0;k<(int)sqrt(n)*5;k++){
            write(1,"\33[2K\r",5);
            write(1,"\33[1A",4);
        }
    }
}

int main(int argc, char *argv[]){
    if(argc == 2){
        int n = strtol(argv[1], NULL, 10); 
        print(n,60);
    }else if(argc == 3){
        int n = strtol(argv[1], NULL, 10);
        int time = strtol(argv[2], NULL, 10);
        print(n, time);
    }else{
        print(1,60);
    }
    //get rid of stray characters that wont go away for 
    //a reason that im too lazy to figure out right now >_<
    //write(1,"\33[2K\r",5);
    //write(1,"\33[1A",4);
}