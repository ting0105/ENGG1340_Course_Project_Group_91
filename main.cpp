#include <iostream>
#include <random>
#include <string>
#include <windows.h>
using namespace std;

void printout(string paragraph){
    int x = 0;
    while (paragraph[x] != '\0'){
        cout << paragraph[x];
        Sleep(0);
        x++;
    }
}

void EnterLeftCell(int BrokenWall){
    //if (BrokenWall == 0){

    }




void EnterMiddleCell(){



}



int main(){
    string WhatToDo= "What do you want to do next?\n";


    //intro
    string Intro="In the mist, under the darkness, you see a figure in yellow, standing afar, staring at you.\nYour eyes scan through the figure, as your sight stopped on his face, you did not see anything,\nbut a chill strikes your spine, from the very bottom, up till the back of your head,\nit is the emotion of fear, the feeling of certain death, and the desire to run.\nAnd so did you, you started running, running into the abyss, as the darkness slowly engulfs you, swallowing you whole.\n";
    printout(Intro);
    cout << endl;

    // To store the current pos.
    int LeftCell = 1;
    int TortureRoom = 0;
    int MiddleCell = 0;


    // Left cell
    int LC_BrokenWall = 0;
    int LC_GetWire = 0;
    int LC_OpenedDoor = 0;
    int LC_ObservedWall = 0;
    int LC_ObservedDoor = 0;
    string LeftCellDes="You wake up in a cell, packed with cushioned interior, a sturdy metal door blocks your path to freedom,\nas a tiny gap on the door gives you a glimpse of the outside, a plain concrete room.\nAt the meantime, you found all your personal items gone.\n";
    printout(LeftCellDes);
    cout << endl;


    string choice;
    while (true){
        while (LeftCell == 1){
            if (LC_ObservedWall == 0){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the Door.\nB. Observe the cushioned Walls.\n";
                printout(options);
                cout << endl;

                // action
                cin >> choice;
                if (choice == "A"){
                    printout("You carefully inspect the door, it is a sturdy and heavy door,\nthere’s also a tiny gap on the door that allows you to peek on the other side of the room, or vice versa.\nIt would be impossible to open this door by force, but you cannot see any sort of lock or handle,\nthis door must be operated from the other side.\n");
                    LC_ObservedDoor = 1;
                    cout << endl;
                }
                else if (choice == "B"){
                    printout("Underneath the cushion,you found the concrete wall underneath to be fragile,\nhowever it would still cost a lot to brute force through the wall, maybe you should attempt finding another way out first.\nAlso, you found a long piece of wire under the cushion.\n");
                    LC_ObservedWall = 1;
                    LC_GetWire = 1;
                    cout << endl;
                }
            }


            if (LC_GetWire == 1 && LC_ObservedDoor == 0 && LC_BrokenWall == 0){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the Door.\nB. Observe the cushioned Walls.\nC. Attack Cushion and try to break the wall.\n";
                printout(options);
                cout << endl;

                // action
                cin >> choice;
                if (choice == "A"){
                    printout("You carefully inspect the door, it is a sturdy and heavy door,\nthere’s also a tiny gap on the door that allows you to peek on the other side of the room, or vice versa.\nIt would be impossible to open this door by force, but you cannot see any sort of lock or handle,\nthis door must be operated from the other side.\n");
                    LC_ObservedDoor = 1;
                    cout << endl;
                }
                else if (choice == "B"){
                    printout("Underneath the cushion,you found the concrete wall underneath to be fragile,\nhowever it would still cost a lot to brute force through the wall, maybe you should attempt finding another way out first.\n");
                    LC_ObservedWall = 1;
                    cout << endl;
                }

                else if (choice == "C"){
                    printout(" ");
                    LC_BrokenWall = 1;
                    LeftCell = 0;
                    MiddleCell = 1;
                    cout << endl;
                }
            }

            if (LC_GetWire == 1 && LC_ObservedDoor == 1 && LC_BrokenWall == 0 && LC_OpenedDoor == 0){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the Door.\nB. Observe the cushioned Walls.\nC. Try to open the door by the wire.\nD. Attack Cushion and try to break the wall.\n";
                printout(options);
                cout << endl;

                // action
                cin >> choice;
                if (choice == "A"){
                    printout("You carefully inspect the door, it is a sturdy and heavy door,\nthere’s also a tiny gap on the door that allows you to peek on the other side of the room, or vice versa.\nIt would be impossible to open this door by force, but you cannot see any sort of lock or handle,\nthis door must be operated from the other side.\n");
                    LC_ObservedDoor = 1;
                    cout << endl;
                }
                else if (choice == "B"){
                    printout("Underneath the cushion,you found the concrete wall underneath to be fragile,\nhowever it would still cost a lot to brute force through the wall, maybe you should attempt finding another way out first.\n");
                    LC_ObservedWall = 1;
                    LC_GetWire = 1;
                    cout << endl;
                }
                else if (choice == "C"){
                    printout(" ");
                    LC_OpenedDoor =1;
                    cout << endl;
                }

                else if (choice == "D"){
                    printout("");
                    LC_BrokenWall = 1;
                    cout << endl;
                }
            }

            if (LC_OpenedDoor == 1 && LC_BrokenWall == 0){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the Door.\nB. Observe the cushioned Walls.\nC. Get out the room.\nD. Attack Cushion and try to break the wall.\n";
                printout(options);
                cout << endl;

                // action
                cin >> choice;
                if (choice == "A"){
                    printout("You carefully inspect the door, it is a sturdy and heavy door,\nthere’s also a tiny gap on the door that allows you to peek on the other side of the room, or vice versa.\nIt would be impossible to open this door by force, but you cannot see any sort of lock or handle,\nthis door must be operated from the other side.\n");
                    LC_ObservedDoor = 1;
                    cout << endl;
                }
                else if (choice == "B"){
                    printout("Underneath the cushion,you found the concrete wall underneath to be fragile,\nhowever it would still cost a lot to brute force through the wall, maybe you should attempt finding another way out first.\n");
                    LC_ObservedWall = 1;
                    LC_GetWire = 1;
                    cout << endl;
                }
                else if (choice == "C"){
                    printout("");
                    LeftCell = 0;
                    TortureRoom = 1;
                    cout << endl;
                }

                else if (choice == "D"){
                    printout("");
                    LC_BrokenWall = 1;
                    LeftCell = 0;
                    MiddleCell = 1;
                    cout << endl;
                }
            }

        }

    }

}
  

