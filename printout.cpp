#include <iostream>
#include "main.h"
#include <unistd.h>
#include <string>
using namespace std;

void printout(string paragraph){
    int x = 0;
    while (paragraph[x] != '\0'){
        cout << paragraph[x++];
        cout.flush();
        usleep(20000); // 10000
    }
} 
