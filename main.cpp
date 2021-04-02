#include <iostream>
#include <random>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include "main.h"
using namespace std;

void printout(string paragraph){
    int x = 0;
    while (paragraph[x] != '\0'){
        cout << paragraph[x];
        usleep(10000);
        x++;
    }
}

int GenRand(){
    int x = rand() % 100 +1;
    return x;
}



int main(){


    //statarray[0]=STR
    //statarray[1]=CON
    //statarray[2]=DEX
    //statarray[3]=SIZ
    //statarray[4]=INT
    //statarray[5]=POW
    //statarray[6]=APP
    //statarray[7]=LUC
    //statarray[8]=HP
    //statarray[9]=SAN
    
    int statarray[10];
    stat_gen(statarray);
    string WhatToDo= "What do you want to do next?\n";
    string choice;


    //intro
    cout << endl;
    string Intro="In the mist, under the darkness, you see a figure in yellow, standing afar, staring at you.\nYour eyes scan through the figure, as your sight stopped on his face, you did not see anything,\nbut a chill strikes your spine, from the very bottom, up till the back of your head,\nit is the emotion of fear, the feeling of certain death, and the desire to run.\nAnd so did you, you started running, running into the abyss, as the darkness slowly engulfs you, swallowing you whole.\n";
    printout(Intro);
    cout << endl;

    // To store the current pos.
    //int LeftCell = 1;
    //int TortureRoom = 0;
    //int MiddleCell = 0;


    // Left cell event
    bool LC_Searched = 0;
    bool LC_BrokenWall = 0;
    bool LC_GetWire = 0;
    bool LC_OpenedDoor = 0;
    bool LC_ObservedWall = 0;
    bool LC_ObservedDoor = 0;

    // Middle cell event
    bool MC_Searched = 0;

    // Torture room event
    bool TR_Searched = 0;


    string LeftCellDes1 = "You wake up in a cell, packed with cushioned interior, a sturdy metal door blocks your path to freedom,\nas a tiny gap on the door gives you a glimpse of the outside, a plain concrete room.\nAt the meantime, you found all your personal items gone.\n";
    string LeftCellDes2 = "You woke up in this cell and there is no different, except the unlocked door.\n";
    string LeftCellDes3 = "You woke up in this cell and there is no different, except the broken wall and the unlocked door.\n";
    string LeftCellDes4 = "You woke up in this cell and there is no different, except the broken wall.\n";
    cout << endl;

    // Left cell
    LeftCell:{
        if (LC_Searched == 0){
            printout(LeftCellDes1);
        }
        else if (LC_Searched == 1 && LC_OpenedDoor == 1 && LC_BrokenWall == 0){
            printout(LeftCellDes2);
        }
        else if (LC_Searched == 1 && LC_OpenedDoor == 1 && LC_BrokenWall == 1){
            printout(LeftCellDes3);
        }
        else if (LC_Searched ==1 && LC_OpenedDoor == 0 && LC_BrokenWall == 1){
            printout(LeftCellDes4);
        }

        while (true){
            
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


            else if (LC_GetWire == 1 && LC_ObservedDoor == 0 && LC_BrokenWall == 0){
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
                    LC_BrokenWall = 1;
                    int HPRed = rand()% 3 + 1;
                    statarray[8] -= HPRed;
                    printout("As you forcefully smash your body into the wall, the wall shattered and crumbled,\nyou received ");
                    cout << HPRed << " ";
                    printout("damages, you still have ");
                    cout << statarray [8] << " HP,";
                     printout(" yet you fall intoanother cell.\n");
                    cout << endl;
                    goto MiddleCell;
                }
            }

            else if (LC_GetWire == 1 && LC_ObservedDoor == 1 && LC_BrokenWall == 0 && LC_OpenedDoor == 0){
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
                    cout << endl;
                }
                else if (choice == "C"){
                    if (GenRand() > statarray[7]){
                        printout("As your wire hooked and fixed onto the handle outside, you gently pull the wire,\nbut the wire ruptured the moment you pulled it.\nAs the wire ruptured, it seems that you need to find another way to escape.\n");
                        LC_GetWire = 0;
                        cout << endl;
                    }
                    else{
                        printout("You stretch your hands the very best you could, carefully hooking the twisted end of the wire onto the handle outside,\nas you feel the wire is fixed in its position, you slowly pull the wire in, the handle gradually lifted upward,\non the very urge of the wire from being ruptured, \"click\" the metal door opened\n");
                        LC_OpenedDoor =1;
                        cout << endl;
                    }
                }

                else if (choice == "D"){
                    LC_BrokenWall = 1;
                    int HPRed = rand()% 3 + 1;
                    statarray[8] -= HPRed;
                    printout("As you forcefully smash your body into the wall, the wall shattered and crumbled,\nyou received ");
                    cout << HPRed << " ";
                    printout("damages, you still have ");
                    cout << statarray [8] << " HP,";
                     printout(" yet you fall intoanother cell.\n");
                    cout << endl;
                    goto MiddleCell;
                }
            }

            else if (LC_Searched == 0 && LC_OpenedDoor == 1 && LC_BrokenWall == 0){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the Door.\nB. Observe the cushioned Walls.\nC. Leave the cell.\nD. Attack Cushion and try to break the wall.\n";
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
                    LC_Searched = 1;
                    cout << endl;
                    goto TortureRoom;
                }

                else if (choice == "D"){
                    LC_BrokenWall = 1;
                    int HPRed = rand()% 3 + 1;
                    statarray[8] -= HPRed;
                    printout("As you forcefully smash your body into the wall, the wall shattered and crumbled,\nyou received ");
                    cout << HPRed << " ";
                    printout("damages, you still have ");
                    cout << statarray [8] << " HP,";
                     printout(" yet you fall intoanother cell.\n");
                    cout << endl;
                    goto MiddleCell;
                }
            }
            else if (LC_Searched == 1 && LC_OpenedDoor == 1 && LC_BrokenWall == 0){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the Door.\nB. Observe the cushioned Walls.\nC. Go to the torture room.\nD. Attack Cushion and try to break the wall.\n";
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
                    printout("You leave the cell.\n");
                    LC_Searched = 1;
                    cout << endl;
                    goto TortureRoom;
                }

                else if (choice == "D"){
                    LC_BrokenWall = 1;
                    int HPRed = rand()% 3 + 1;
                    statarray[8] -= HPRed;
                    printout("As you forcefully smash your body into the wall, the wall shattered and crumbled,\nyou received ");
                    cout << HPRed << " ";
                    printout("damages, you still have ");
                    cout << statarray [8] << " HP,";
                     printout(" yet you fall intoanother cell.\n");
                    cout << endl;
                    goto MiddleCell;
                }
            }
            else if (LC_Searched == 0 && LC_GetWire == 0 && LC_ObservedWall == 1 && LC_ObservedDoor == 1 && LC_BrokenWall == 0 && LC_OpenedDoor == 0){
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
                    printout("Underneath the cushion,you found the concrete wall underneath to be fragile,\nhowever it would still cost a lot to brute force through the wall.\n");
                    LC_ObservedWall = 1;
                    cout << endl;
                }
                else if (choice == "C"){
                    LC_BrokenWall = 1;
                    int HPRed = rand()% 3 + 1;
                    statarray[8] -= HPRed;
                    printout("As you forcefully smash your body into the wall, the wall shattered and crumbled,\nyou received ");
                    cout << HPRed << " ";
                    printout("damages, you still have ");
                    cout << statarray [8] << " HP,";
                     printout(" yet you fall intoanother cell.\n");
                    cout << endl;
                    goto MiddleCell;
                }

            }
            else if(LC_Searched == 1 && TR_Searched == 1 && LC_BrokenWall == 1 && LC_OpenedDoor == 1){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the Door.\nB. Observe the cushioned Walls.\nC. Go to the torture room.\nD. Go to the middle cell.\n";
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
                    printout("You leave the cell and go to the torture room.\n");
                    goto TortureRoom;
                    cout << endl;
                }
                else if (choice == "D"){
                    printout("You leave the cell and go to the middle cell.\n");
                    goto MiddleCell;
                    cout << endl; 
                }
            }
            else if(LC_Searched == 1 && TR_Searched == 0 && LC_BrokenWall == 1 && LC_OpenedDoor == 1){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the Door.\nB. Observe the cushioned Walls.\nC. Go to the torture room.\nD. Go to the middle cell.\n";
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
                    printout("You leave the cell and go to the torture room.\n");
                    goto TortureRoom;
                    cout << endl;
                }
                else if (choice == "D"){
                    printout("You leave the cell and enter the cell nearby.\n");
                    goto MiddleCell;
                    cout << endl; 
                }
            }
            else if(LC_Searched == 1 && TR_Searched == 1 && LC_BrokenWall == 1 && LC_OpenedDoor == 0){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the Door.\nB. Observe the cushioned Walls.\nC. Go to the middle cell.\n";
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
                    printout("You leave the cell and go to the middle cell.\n");
                    goto TortureRoom;
                    cout << endl;
                }
            } 
            else if(LC_Searched == 1 && TR_Searched == 0 && LC_BrokenWall == 1 && LC_OpenedDoor == 0){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the Door.\nB. Observe the cushioned Walls.\nC. Go to the cell nearby.\n";
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
                    printout("You leave the cell and enter the cell nearby.\n");
                    goto MiddleCell;
                    cout << endl;
                }
            } 
            else if(LC_Searched == 1 && TR_Searched == 0 && LC_BrokenWall == 1 && LC_OpenedDoor == 1){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the Door.\nB. Observe the cushioned Walls.\nC. Go to the cell nearby.\nD. Leave the room through the door.";
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
                    printout("You leave the cell and enter the cell nearby.\n");
                    cout << endl;
                    goto MiddleCell;
                }
                else if (choice == "C"){
                    printout("You leave the cell.\n");
                    cout << endl;
                    goto TortureRoom;
                }
            } 
            else if(LC_Searched == 1 && TR_Searched == 1 && LC_BrokenWall == 1 && LC_OpenedDoor == 1){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the Door.\nB. Observe the cushioned Walls.\nC. Go to the cell nearby.\nD. Leave the room through the door.";
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
                    printout("You leave the cell and enter the middle cell.\n");
                    cout << endl;
                    goto MiddleCell;
                }
                else if (choice == "C"){
                    printout("You leave the cell and go to the torture room.\n");
                    cout << endl;
                    goto TortureRoom;
                }
            }

        }
    }
    




    TortureRoom:{

    }

    MiddleCell:{

    }
    

}
