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
        usleep(0); // 10000
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
    int str = statarray[0];
    int con = statarray[1];
    int dex = statarray[2];
    int siz = statarray[3];
    int inte = statarray[4];
    int pow = statarray[5];
    int app = statarray[6];
    int luck = statarray[7];
    int hp = statarray[8];
    int san = statarray[9];



    //stat_gen(statarray);
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
    bool MC_FromLC = 0;
    bool MC_FromTR = 0;
    bool MC_ObservedCorpses = 0;
    bool MC_ObservedDoor = 0;
    bool MC_GetMetalKey = 0;

    // Torture room event
    bool TR_Searched = 0;
    bool TR_ObservedRCDoor = 0;
    bool TR_ObservedPadlock = 0;
    bool TR_ObservedMirror = 0;
    bool TR_ObservedTortureIns = 0;
    bool TR_ObservedDoor = 0;
    bool TR_UnlockedDoor = 0;
    bool TR_UnlockedRCDoor = 0;


    // Second bedroom event
    bool SB_GetMagnetKey = 0;



    // LC description
    string LeftCellDes1 = "You wake up in a cell, packed with cushioned interior, a sturdy metal door blocks your path to freedom,\nas a tiny gap on the door gives you a glimpse of the outside, a plain concrete room.\nAt the meantime, you found all your personal items gone.\n";
    string LeftCellDes2 = "You woke up in this cell and there is no different, except the unlocked door.\n";
    string LeftCellDes3 = "You woke up in this cell and there is no different, except the broken wall and the unlocked door.\n";
    string LeftCellDes4 = "You woke up in this cell and there is no different, except the broken wall.\n";

    // MC description
    string MiddleCellDes1 = "As you fell into the middle cell along with the crumbling concretes, you fell into a puddle of sticky and smelly liquids.\nAs you get up, you found yourself covered in flesh and blood,\n";
    string MiddleCellDes2 = "As you lift the handle and pull on the door, a strong scent rushes into your nose, you lost 1 sanity. As the content fully disclosed,\nyou found the cell to be filled up with flesh, blood, and human remains,\n";
    string MiddleCellDes3 = "You enter the middle cell and there is no different, it is still full of flesh, blood, and human remains.\n";

    // TR description
    string TortureRoomDes1 = "As you break free from the cell, you noticed you are in a plain room\nwith white concrete walls, with no windows, a couple of torture instruments was set in the middle of room,\nsome of them have stains and some remains on them.\nThere’s also a large mirror  on the other side of the room.\nYou look behind you, there are a total of 3 cells,\nthe left one, where you woke up, the middle one and the right one. While you see another door at the other end of the room.";
    string TortureRoomDes2 = "You enter the torture room and there is no different,\na couple of torture instruments was set in the middle of room, some of them have stains and some remains on them.\nThere are three cells in the room\nThere’s also a large mirror on the other side of the room.\n";
    
    
    
    
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
                    MC_FromLC = 1;
                    LC_Searched = 1;
                    int HPRed = rand()% 3 + 1;
                    hp -= HPRed;
                    printout("As you forcefully smash your body into the wall, the wall shattered and crumbled,\nyou received ");
                    cout << HPRed << " ";
                    printout("damages, you still have ");
                    cout << hp << " HP,";
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
                    if (GenRand() > luck){
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
                    LC_Searched = 1;
                    int HPRed = rand()% 3 + 1;
                    hp -= HPRed;
                    printout("As you forcefully smash your body into the wall, the wall shattered and crumbled,\nyou received ");
                    cout << HPRed << " ";
                    printout("damages, you still have ");
                    cout << hp << " HP,";
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
                    MC_FromLC = 1;
                    LC_Searched = 1;
                    int HPRed = rand()% 3 + 1;
                    hp -= HPRed;
                    printout("As you forcefully smash your body into the wall, the wall shattered and crumbled,\nyou received ");
                    cout << HPRed << " ";
                    printout("damages, you still have ");
                    cout << hp << " HP,";
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
                    LC_Searched = 1;
                    MC_FromLC = 1;
                    int HPRed = rand()% 3 + 1;
                    hp -= HPRed;
                    printout("As you forcefully smash your body into the wall, the wall shattered and crumbled,\nyou received ");
                    cout << HPRed << " ";
                    printout("damages, you still have ");
                    cout << hp << " HP,";
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
                    LC_Searched = 1;
                    MC_FromLC = 1;
                    int HPRed = rand()% 3 + 1;
                    hp -= HPRed;
                    printout("As you forcefully smash your body into the wall, the wall shattered and crumbled,\nyou received ");
                    cout << HPRed << " ";
                    printout("damages, you still have ");
                    cout << hp << " HP,";
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
                    printout("There is a hole on the wall due to your smash before.\n");
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
                    printout("There is a hole on the wall due to your smash before.\n");
                    LC_ObservedWall = 1;
                    cout << endl;
                }
                else if (choice == "C"){
                    printout("You leave the cell and go to the torture room.\n");
                    cout << endl;
                    goto TortureRoom;
                    
                }
                else if (choice == "D"){
                    printout("You leave the cell and enter the cell nearby.\n");
                    cout << endl; 
                    goto MiddleCell;
                    
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
                    printout("There is a hole on the wall due to your smash before.\n");
                    LC_ObservedWall = 1;
                    cout << endl;
                }
                else if (choice == "C"){
                    printout("You leave the cell and go to the middle cell.\n");
                    cout << endl;
                    goto TortureRoom;
                    
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
                    printout("There is a hole on the wall due to your smash before.\n");
                    LC_ObservedWall = 1;
                    cout << endl;
                }
                else if (choice == "C"){
                    printout("You leave the cell and enter the cell nearby.\n");
                    cout << endl;
                    goto MiddleCell;
                    
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
                    printout("There is a hole on the wall due to your smash before.\n");
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
                    printout("There is a hole on the wall due to your smash before.\n");
                    cout << endl;
                }
                else if (choice == "C"){
                    printout("You leave the cell.\n");
                    cout << endl;
                    goto MiddleCell;
                }
                else if (choice == "C"){
                    printout("You leave the cell.\n");
                    cout << endl;
                    goto TortureRoom;
                }
            }

        }
    }
    




    TortureRoom:{
        if (TR_Searched == 0){
            int SanRed = random()%3 + 1;
            san -= SanRed;
            printout(TortureRoomDes1);
            printout("Because of seeing those instruments, you lost ");
            cout << SanRed;
            printout(" sanity, you have ");
            cout << san;
            printout(" sanity left.");
            cout << endl;
        }
        else{
            printout(TortureRoomDes2);
        }
        while (1){
            printout(WhatToDo);
            printout("A. Observe the torture instruments.\nB. Observe the Large Mirror.\n");
            if (TR_ObservedDoor == 0 && TR_UnlockedDoor == 0){
                printout("C. Observe the metal door.\n");
            }
            else if (TR_ObservedDoor == 1 && TR_UnlockedDoor == 0 && MC_GetMetalKey == 0){
                printout("C. Try to open the metal door.\n");
            }
            else if (TR_ObservedDoor == 1 && TR_UnlockedDoor == 0 && MC_GetMetalKey == 1){
                printout("C. Try to open the metal door with the metal key.\n");
            }
            else if (TR_UnlockedDoor == 1){
                printout("C. Leave the torture room.\n");
            }
            if(MC_ObservedDoor == 0){
                printout("D. Observe the door of the middle cell.\n");
            }
            else if (MC_ObservedDoor == 1){
                printout("D. Go into the middle cell.\n");
            }
            if (TR_ObservedRCDoor == 0){
                printout("E. Observer the door of the right cell.\n");
            }
            else if (TR_ObservedRCDoor == 1 && TR_ObservedPadlock == 0){
                printout("E. Observe the padlock on the door of the right cell.\n");
            }
            else if (TR_ObservedPadlock == 1 && MC_GetMetalKey == 1 && SB_GetMagnetKey == 0){
                printout("E. Try to open the door of the right cell by the metal key.\n");
            }
            else if (TR_ObservedPadlock ==1 && SB_GetMagnetKey == 1){
                printout("E. Try to open the door of the right cell by the magnet key.\n");
            }
            else{
                printout("E. Observer the door of the right cell.\n");
            }
            if (LC_OpenedDoor == 1){
                printout("F. Enter the left cell.\n");
            }
            else if (LC_OpenedDoor == 0){
                printout("F. Open the door of left cell.\n");
            }
            cout << endl;
            cin >> choice;
            if (choice == "A"){
                if (TR_ObservedTortureIns == 0){
                    TR_ObservedTortureIns = 1;
                    int SanRed = random()%3 + 1;
                    san -= SanRed;
                    printout("You closely inspected the instruments, you realize the cruelty of the instruments,\nyou lost ");
                    cout << SanRed;
                    printout(" sanity, you have ");
                    cout << san;
                    printout(" sanity left.");
                    
                }
                else if (TR_ObservedTortureIns == 1){
                    printout("You closely inspected the instruments, there is nothing special.\n");
                    
                }
            }
            else if(choice == "B"){
                if (TR_ObservedMirror == 0){
                    TR_ObservedMirror = 1;
                    san -= 1;
                    printout("You stared into the mirror, you see yourself, nothing special, nothing worthy. You felt worthless,\nyou lost 1 sanity, you have ");
                    cout << san;
                    printout(" sanity left.\n");
                }
                else if (TR_ObservedMirror == 1){
                    printout("You stared into the mirror, you see yourself, nothing special, nothing worthy.");
                }

            }
            else if (choice == "C"){
                if (TR_ObservedDoor == 0 && TR_UnlockedDoor == 0){
                    TR_ObservedDoor = 1;
                    printout("This is a metal door, it seems less bulky than the cell door, but it is still vain to open it by force.\n");
                }
                else if (TR_ObservedDoor == 1 && TR_UnlockedDoor == 0 && MC_GetMetalKey == 0){
                    printout("You attempted to open the door, but the door seemed to be locked.\n");
                }
                else if (TR_ObservedDoor == 1 && TR_UnlockedDoor == 0 && MC_GetMetalKey == 1){
                    TR_UnlockedDoor = 1;
                    printout("You inserted the key and turned it; the door opened with a \"click\".\n");
                }
                else if (TR_UnlockedDoor == 1){
                    TR_Searched = 1;
                    printout("You leave the torture room.\n");
                    cout << endl;
                    goto Storage;
                }

            }
            else if (choice == "D"){
                if(MC_ObservedDoor == 0){
                    MC_ObservedDoor = 1;
                    printout("As you pushed onto the door, the door slid open, someone must have forgot to lock the door.\n");
                }
                else if (MC_ObservedDoor == 1){
                    TR_Searched = 1;
                    MC_FromTR = 1;
                    printout("You enter the middle cell.\n");
                    cout << endl;
                    goto MiddleCell;
                }

            }
            else if (choice == "E"){
               if (TR_ObservedRCDoor == 0){
                    TR_ObservedRCDoor = 1;
                    printout("Different from the other two cells, a solid metal door bar, stretched to both side of the frame, was used to prevent to door from opening.\nYou see a padlock locking the metal bar onto the door.\nIt is merely impossible for any animals or human, that can fit into this cell, to physically break through this door\n");
                }
                else if (TR_ObservedRCDoor == 1 && TR_ObservedPadlock == 0){
                    TR_ObservedPadlock = 1;
                    printout("The padlock is cold to touch, a layer of reinforced metal enveloped the lock.\nMade of sturdy metal, the shackle is reinforced, partially covered in another layer of steel.\nOn the side of the padlock, it writes the word \"Squire\".\n");
                }
                else if (TR_ObservedPadlock == 1 && MC_GetMetalKey == 1 && SB_GetMagnetKey == 0){
                    printout("You insert the metal key you found in the middle cell and turned; However, it seem that this isn't the correct key.\n");
                }
                else if (TR_ObservedPadlock ==1 && SB_GetMagnetKey == 1){
                    TR_UnlockedRCDoor = 1;
                    printout("You insert the key you found in the main bedroom and turned; the padlock opened with ease.\n"); 
                }
            }
            else if (choice == "F"){
                if (LC_OpenedDoor == 1){
                    printout("You enter the left cell.\n");
                    cout << endl;
                    goto LeftCell;
                }
                else if (LC_OpenedDoor == 0){
                    LC_OpenedDoor = 1;
                    printout("You open the door of the left cell.\n");
                
                }
                
            }
            cout << endl;

            
        }

        

    }

    MiddleCell:{
        if (MC_Searched == 0 && MC_FromLC == 1){
            int SanRed = random()%4+1;
            printout (MiddleCellDes1);
            san -= SanRed;
            printout ("you lost ");
            cout << SanRed;
            printout (" sanity, you have ");
            cout << san;
            printout (" sanity left.\n");
            cout << endl;

        }

        if (MC_Searched == 0 && MC_FromTR == 1){
            int SanRed = random()%2+1;
            printout (MiddleCellDes2);
            san = san - SanRed - 1;
            printout ("you lost ");
            cout << SanRed;
            printout (" sanity, you have ");
            cout << san;
            printout (" sanity left.\n");
            cout << endl;
        }

        if (MC_Searched == 1){
            printout (MiddleCellDes3);
        }
        while (1){
            if (LC_BrokenWall == 1 && MC_ObservedDoor == 0){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the door.\nB. Observe the corpses.\nC. Go to the left cell.\n";
                printout(options);
                cout << endl;

                // action
                cin >> choice;
                if (choice == "A"){
                    printout("As you pushed onto the door, the door slid open, someone must have forgot to lock the door.\n");
                    MC_ObservedDoor = 1;
                    cout << endl;
                }
                else if (choice == "B"){
                    if (MC_ObservedCorpses == 0){
                        int x = random()%100+1;
                        if (x <= luck){
                            printout("As you carefully inspect the corpses, you find noticed a shining spot, upon close inspection, you found it to be a metal key.\n");
                            MC_ObservedCorpses = 1;
                            MC_GetMetalKey = 1;
                        }
                        else{
                            int SanRed = random ()%4+2;
                            san -= SanRed;
                            printout("As you carefully inspect the corpses, you noticed something odd, but you failed to find it, you still rummaged through the mashed remains,\nyou lost ");
                            cout << SanRed;
                            printout(" sanity, you have ");
                            cout << san;
                            printout(" sanity left, eventually, you found a key.\n");
                            MC_ObservedCorpses = 1;
                            MC_GetMetalKey = 1;
                            cout << endl;
                        }    
                    }
                    else if (MC_ObservedCorpses == 1){
                        printout("You carefully inspect the corpses, however, you don't find anything special.\n");
                        cout << endl;
                    }

                }
                else if (choice == "C"){
                    printout("You leave the cell.\n");
                    MC_Searched = 1;
                    cout << endl;
                    goto LeftCell;
                }
            }
            else if (LC_BrokenWall == 0 && MC_ObservedDoor == 1){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the corpses.\nB. Left the cell through the door.\n";
                printout(options);
                cout << endl;

                // action
                cin >> choice;
                
                if (choice == "A"){
                    if (MC_ObservedCorpses == 0){
                        int x = random()%100+1;
                        if (x <= luck){
                            printout("As you carefully inspect the corpses, you find noticed a shining spot, upon close inspection, you found it to be a metal key.\n");
                            MC_ObservedCorpses = 1;
                            MC_GetMetalKey = 1;
                        }
                        else{
                            int SanRed = random ()%4+2;
                            san -= SanRed;
                            printout("As you carefully inspect the corpses, you noticed something odd, but you failed to find it, you still rummaged through the mashed remains,\nyou lost ");
                            cout << SanRed;
                            printout(" sanity, you have ");
                            cout << san;
                            printout(" sanity left, eventually, you found a key.\n");
                            MC_ObservedCorpses = 1;
                            MC_GetMetalKey = 1;
                            cout << endl;
                        }    
                    }
                    else if (MC_ObservedCorpses == 1){
                        printout("You carefully inspect the corpses, however, you don't find anything special.\n");
                        cout << endl;
                    }

                }
                else if (choice == "B"){
                    printout("You leave the cell.\n");
                    MC_Searched = 1;
                    cout << endl;
                    goto TortureRoom;
                }
            }
            else if (LC_BrokenWall == 1 && MC_ObservedDoor == 1){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the corpses.\nB. Left the cell through the door.\nC. Go to the left cell.\n";
                printout(options);
                cout << endl;

                // action
                cin >> choice;
                
                if (choice == "A"){
                    if (MC_ObservedCorpses == 0){
                        int x = random()%100+1;
                        if (x <= luck){
                            printout("As you carefully inspect the corpses, you find noticed a shining spot, upon close inspection, you found it to be a metal key.\n");
                            MC_ObservedCorpses = 1;
                            MC_GetMetalKey = 1;
                        }
                        else{
                            int SanRed = random ()%4+2;
                            san -= SanRed;
                            printout("As you carefully inspect the corpses, you noticed something odd, but you failed to find it, you still rummaged through the mashed remains,\nyou lost ");
                            cout << SanRed;
                            printout(" sanity, you have ");
                            cout << san;
                            printout(" sanity left, eventually, you found a key.\n");
                            MC_ObservedCorpses = 1;
                            MC_GetMetalKey = 1;
                            cout << endl;
                        }    
                    }
                    else if (MC_ObservedCorpses == 1){
                        printout("You carefully inspect the corpses, however, you don't find anything special.\n");
                        cout << endl;
                    }

                }
                else if (choice == "B"){
                    printout("You leave the cell.\n");
                    MC_Searched = 1;
                    cout << endl;
                    goto TortureRoom;
                }
                else if (choice == "C"){
                    printout("You leave the cell.\n");
                    MC_Searched = 1;
                    cout << endl;
                    goto LeftCell;
                }
            }
        }

    }
    END:{

    }
    Storage:{

    }

}
