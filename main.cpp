#include <iostream>
#include <random>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include "main.h"
#include <fstream>
using namespace std;

struct player
{
  int position;
  int str;
  int con;
  int dex;
  int siz;
  int inte;
  int pow;
  int app;
  int luck;
  int hp;
  int san;

  bool LC_Searched;
  bool LC_BrokenWall;
  bool LC_GetWire;
  bool LC_OpenedDoor;
  bool LC_ObservedWall;
  bool LC_ObservedDoor;

  // Middle cell event
  bool MC_Searched;
  bool MC_FromLC;
  bool MC_FromTR;
  bool MC_ObservedCorpses;
  bool MC_ObservedDoor;
  bool MC_GetMetalKey;

  // Torture room event
  bool TR_Searched;
  bool TR_ObservedRCDoor;
  bool TR_ObservedPadlock;
  bool TR_ObservedMirror;
  bool TR_ObservedTortureIns;
  bool TR_ObservedDoor;
  bool TR_UnlockedDoor;
  bool TR_UnlockedRCDoor;


  // Second bedroom event
  bool SB_GetMagnetKey;

};

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


void savedata(player p)
{
  ofstream fout;
  fout.open("stats.txt");

  if (fout.fail())
  {
    cout<<"Error in file opening"<<endl;
    exit(1);
  }

  fout<<p.position<<endl
  <<p.str<<endl
  <<p.con<<endl
  <<p.dex<<endl
  <<p.siz<<endl
  <<p.inte<<endl
  <<p.pow<<endl
  <<p.app<<endl
  <<p.luck<<endl
  <<p.hp<<endl
  <<p.san<<endl
  <<p.LC_Searched<<endl
  <<p.LC_BrokenWall<<endl
  <<p.LC_GetWire<<endl
  <<p.LC_OpenedDoor<<endl
  <<p.LC_ObservedWall<<endl
  <<p.LC_ObservedDoor<<endl
  <<p.MC_Searched<<endl
  <<p.MC_FromLC<<endl
  <<p.MC_FromTR<<endl
  <<p.MC_ObservedCorpses<<endl
  <<p.MC_ObservedDoor<<endl
  <<p.MC_GetMetalKey<<endl
  <<p.TR_Searched<<endl
  <<p.TR_ObservedRCDoor<<endl
  <<p.TR_ObservedPadlock<<endl
  <<p.TR_ObservedMirror<<endl
  <<p.TR_ObservedTortureIns<<endl
  <<p.TR_ObservedDoor<<endl
  <<p.TR_UnlockedDoor<<endl
  <<p.TR_UnlockedRCDoor<<endl
  <<p.SB_GetMagnetKey<<endl;

  fout.close();


}


int main(){
    player p;

    int statarray[10];

    //intro
    string Intro="In the mist, under the darkness, you see a figure in yellow, standing afar, staring at you.\nYour eyes scan through the figure, as your sight stopped on his face, you did not see anything,\nbut a chill strikes your spine, from the very bottom, up till the back of your head,\nit is the emotion of fear, the feeling of certain death, and the desire to run.\nAnd so did you, you started running, running into the abyss, as the darkness slowly engulfs you, swallowing you whole.\n";



    string WhatToDo= "What do you want to do next?\n";
    string choice;

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







    //load the game if a save exists
    ifstream fin;
    fin.open("stats.txt");
    if (fin.good())
    {
      fin>>p.position
      >>p.str
      >>p.con
      >>p.dex
      >>p.siz
      >>p.inte
      >>p.pow
      >>p.app
      >>p.luck
      >>p.hp
      >>p.san
      >>p.LC_Searched
      >>p.LC_BrokenWall
      >>p.LC_GetWire
      >>p.LC_OpenedDoor
      >>p.LC_ObservedWall
      >>p.LC_ObservedDoor
      >>p.MC_Searched
      >>p.MC_FromLC
      >>p.MC_FromTR
      >>p.MC_ObservedCorpses
      >>p.MC_ObservedDoor
      >>p.MC_GetMetalKey
      >>p.TR_Searched
      >>p.TR_ObservedRCDoor
      >>p.TR_ObservedPadlock
      >>p.TR_ObservedMirror
      >>p.TR_ObservedTortureIns
      >>p.TR_ObservedDoor
      >>p.TR_UnlockedDoor
      >>p.TR_UnlockedRCDoor
      >>p.SB_GetMagnetKey;

      fin.close();

      if (p.position==1)
      {
        goto LeftCell;
      }
      else if (p.position==2)
      {
        goto MiddleCell;
      }
      else if (p.position==3)
      {
        goto TortureRoom;
      }
    }

    else if (fin.fail())
    {
      stat_gen(statarray);
    }






    p.str = statarray[0];
    p.con = statarray[1];
    p.dex = statarray[2];
    p.siz = statarray[3];
    p.inte = statarray[4];
    p.pow = statarray[5];
    p.app = statarray[6];
    p.luck = statarray[7];
    p.hp = statarray[8];
    p.san = statarray[9];









    // Left cell event
    p.LC_Searched = 0;
    p.LC_BrokenWall = 0;
    p.LC_GetWire = 0;
    p.LC_OpenedDoor = 0;
    p.LC_ObservedWall = 0;
    p.LC_ObservedDoor = 0;

    // Middle cell event
    p.MC_Searched = 0;
    p.MC_FromLC = 0;
    p.MC_FromTR = 0;
    p.MC_ObservedCorpses = 0;
    p.MC_ObservedDoor = 0;
    p.MC_GetMetalKey = 0;

    // Torture room event
    p.TR_Searched = 0;
    p.TR_ObservedRCDoor = 0;
    p.TR_ObservedPadlock = 0;
    p.TR_ObservedMirror = 0;
    p.TR_ObservedTortureIns = 0;
    p.TR_ObservedDoor = 0;
    p.TR_UnlockedDoor = 0;
    p.TR_UnlockedRCDoor = 0;


    // Second bedroom event
    p.SB_GetMagnetKey = 0;


    savedata(p);


    //intro
    cout << endl;
    printout(Intro);
    cout << endl;

    cout << endl;

    p.position=1;


    // Left cell
    LeftCell:{


        if (p.LC_Searched == 0){
            printout(LeftCellDes1);
        }
        else if (p.LC_Searched == 1 && p.LC_OpenedDoor == 1 && p.LC_BrokenWall == 0){
            printout(LeftCellDes2);
        }
        else if (p.LC_Searched == 1 && p.LC_OpenedDoor == 1 && p.LC_BrokenWall == 1){
            printout(LeftCellDes3);
        }
        else if (p.LC_Searched ==1 && p.LC_OpenedDoor == 0 && p.LC_BrokenWall == 1){
            printout(LeftCellDes4);
        }

        while (true){

            if (p.LC_ObservedWall == 0){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the Door.\nB. Observe the cushioned Walls.\n";
                printout(options);
                cout << endl;

                // action
                cin >> choice;
                if (choice == "A"){
                    printout("You carefully inspect the door, it is a sturdy and heavy door,\nthere’s also a tiny gap on the door that allows you to peek on the other side of the room, or vice versa.\nIt would be impossible to open this door by force, but you cannot see any sort of lock or handle,\nthis door must be operated from the other side.\n");
                    p.LC_ObservedDoor = 1;
                    cout << endl;
                }
                else if (choice == "B"){
                    printout("Underneath the cushion,you found the concrete wall underneath to be fragile,\nhowever it would still cost a lot to brute force through the wall, maybe you should attempt finding another way out first.\nAlso, you found a long piece of wire under the cushion.\n");
                    p.LC_ObservedWall = 1;
                    p.LC_GetWire = 1;
                    cout << endl;
                }
            }


            else if (p.LC_GetWire == 1 && p.LC_ObservedDoor == 0 && p.LC_BrokenWall == 0){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the Door.\nB. Observe the cushioned Walls.\nC. Attack Cushion and try to break the wall.\n";
                printout(options);
                cout << endl;

                // action
                cin >> choice;
                if (choice == "A"){
                    printout("You carefully inspect the door, it is a sturdy and heavy door,\nthere’s also a tiny gap on the door that allows you to peek on the other side of the room, or vice versa.\nIt would be impossible to open this door by force, but you cannot see any sort of lock or handle,\nthis door must be operated from the other side.\n");
                    p.LC_ObservedDoor = 1;
                    cout << endl;
                }
                else if (choice == "B"){
                    printout("Underneath the cushion,you found the concrete wall underneath to be fragile,\nhowever it would still cost a lot to brute force through the wall, maybe you should attempt finding another way out first.\n");
                    p.LC_ObservedWall = 1;
                    cout << endl;
                }

                else if (choice == "C"){
                    p.LC_BrokenWall = 1;
                    p.MC_FromLC = 1;
                    p.LC_Searched = 1;
                    int HPRed = rand()% 3 + 1;
                    p.hp -= HPRed;
                    printout("As you forcefully smash your body into the wall, the wall shattered and crumbled,\nyou received ");
                    cout << HPRed << " ";
                    printout("damages, you still have ");
                    cout << p.hp << " HP,";
                     printout(" yet you fall into another cell.\n");
                    cout << endl;
                    p.position=2;
                    savedata(p);
                    goto MiddleCell;
                }
            }

            else if (p.LC_GetWire == 1 && p.LC_ObservedDoor == 1 && p.LC_BrokenWall == 0 && p.LC_OpenedDoor == 0){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the Door.\nB. Observe the cushioned Walls.\nC. Try to open the door by the wire.\nD. Attack Cushion and try to break the wall.\n";
                printout(options);
                cout << endl;

                // action
                cin >> choice;
                if (choice == "A"){
                    printout("You carefully inspect the door, it is a sturdy and heavy door,\nthere’s also a tiny gap on the door that allows you to peek on the other side of the room, or vice versa.\nIt would be impossible to open this door by force, but you cannot see any sort of lock or handle,\nthis door must be operated from the other side.\n");
                    p.LC_ObservedDoor = 1;
                    cout << endl;
                }
                else if (choice == "B"){
                    printout("Underneath the cushion,you found the concrete wall underneath to be fragile,\nhowever it would still cost a lot to brute force through the wall, maybe you should attempt finding another way out first.\n");
                    p.LC_ObservedWall = 1;
                    cout << endl;
                }
                else if (choice == "C"){
                    if (GenRand() > p.luck){
                        printout("As your wire hooked and fixed onto the handle outside, you gently pull the wire,\nbut the wire ruptured the moment you pulled it.\nAs the wire ruptured, it seems that you need to find another way to escape.\n");
                        p.LC_GetWire = 0;
                        cout << endl;
                    }
                    else{
                        printout("You stretch your hands the very best you could, carefully hooking the twisted end of the wire onto the handle outside,\nas you feel the wire is fixed in its position, you slowly pull the wire in, the handle gradually lifted upward,\non the very urge of the wire from being ruptured, \"click\" the metal door opened\n");
                        p.LC_OpenedDoor =1;
                        cout << endl;
                    }
                }

                else if (choice == "D"){
                    p.LC_BrokenWall = 1;
                    p.LC_Searched = 1;
                    int HPRed = rand()% 3 + 1;
                    p.hp -= HPRed;
                    printout("As you forcefully smash your body into the wall, the wall shattered and crumbled,\nyou received ");
                    cout << HPRed << " ";
                    printout("damages, you still have ");
                    cout << p.hp << " HP,";
                     printout(" yet you fall intoanother cell.\n");
                    cout << endl;
                    p.position=2;
                    savedata(p);

                    goto MiddleCell;
                }
            }

            else if (p.LC_Searched == 0 && p.LC_OpenedDoor == 1 && p.LC_BrokenWall == 0){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the Door.\nB. Observe the cushioned Walls.\nC. Leave the cell.\nD. Attack Cushion and try to break the wall.\n";
                printout(options);
                cout << endl;

                // action
                cin >> choice;
                if (choice == "A"){
                    printout("You carefully inspect the door, it is a sturdy and heavy door,\nthere’s also a tiny gap on the door that allows you to peek on the other side of the room, or vice versa.\nIt would be impossible to open this door by force, but you cannot see any sort of lock or handle,\nthis door must be operated from the other side.\n");
                    p.LC_ObservedDoor = 1;
                    cout << endl;
                }
                else if (choice == "B"){
                    printout("Underneath the cushion,you found the concrete wall underneath to be fragile,\nhowever it would still cost a lot to brute force through the wall, maybe you should attempt finding another way out first.\n");
                    p.LC_ObservedWall = 1;
                    cout << endl;
                }
                else if (choice == "C"){
                    p.LC_Searched = 1;
                    cout << endl;
                    p.position=3;
                    savedata(p);
                    goto TortureRoom;
                }

                else if (choice == "D"){
                    p.LC_BrokenWall = 1;
                    p.MC_FromLC = 1;
                    p.LC_Searched = 1;
                    int HPRed = rand()% 3 + 1;
                    p.hp -= HPRed;
                    printout("As you forcefully smash your body into the wall, the wall shattered and crumbled,\nyou received ");
                    cout << HPRed << " ";
                    printout("damages, you still have ");
                    cout << p.hp << " HP,";
                     printout(" yet you fall intoanother cell.\n");
                    cout << endl;
                    p.position=2;
                    savedata(p);
                    goto MiddleCell;
                }
            }
            else if (p.LC_Searched == 1 && p.LC_OpenedDoor == 1 && p.LC_BrokenWall == 0){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the Door.\nB. Observe the cushioned Walls.\nC. Go to the torture room.\nD. Attack Cushion and try to break the wall.\n";
                printout(options);
                cout << endl;

                // action
                cin >> choice;
                if (choice == "A"){
                    printout("You carefully inspect the door, it is a sturdy and heavy door,\nthere’s also a tiny gap on the door that allows you to peek on the other side of the room, or vice versa.\nIt would be impossible to open this door by force, but you cannot see any sort of lock or handle,\nthis door must be operated from the other side.\n");
                    p.LC_ObservedDoor = 1;
                    cout << endl;
                }
                else if (choice == "B"){
                    printout("Underneath the cushion,you found the concrete wall underneath to be fragile,\nhowever it would still cost a lot to brute force through the wall, maybe you should attempt finding another way out first.\n");
                    p.LC_ObservedWall = 1;
                    cout << endl;
                }
                else if (choice == "C"){
                    printout("You leave the cell.\n");
                    p.LC_Searched = 1;
                    cout << endl;
                    p.position=3;
                    savedata(p);
                    goto TortureRoom;
                }

                else if (choice == "D"){
                    p.LC_BrokenWall = 1;
                    p.LC_Searched = 1;
                    p.MC_FromLC = 1;
                    int HPRed = rand()% 3 + 1;
                    p.hp -= HPRed;
                    printout("As you forcefully smash your body into the wall, the wall shattered and crumbled,\nyou received ");
                    cout << HPRed << " ";
                    printout("damages, you still have ");
                    cout << p.hp << " HP,";
                     printout(" yet you fall intoanother cell.\n");
                    cout << endl;
                    p.position=2;
                    savedata(p);
                    goto MiddleCell;
                }
            }
            else if (p.LC_Searched == 0 && p.LC_GetWire == 0 && p.LC_ObservedWall == 1 && p.LC_ObservedDoor == 1 && p.LC_BrokenWall == 0 && p.LC_OpenedDoor == 0){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the Door.\nB. Observe the cushioned Walls.\nC. Attack Cushion and try to break the wall.\n";
                printout(options);
                cout << endl;

                // action
                cin >> choice;
                if (choice == "A"){
                    printout("You carefully inspect the door, it is a sturdy and heavy door,\nthere’s also a tiny gap on the door that allows you to peek on the other side of the room, or vice versa.\nIt would be impossible to open this door by force, but you cannot see any sort of lock or handle,\nthis door must be operated from the other side.\n");
                    p.LC_ObservedDoor = 1;
                    cout << endl;
                }
                else if (choice == "B"){
                    printout("Underneath the cushion,you found the concrete wall underneath to be fragile,\nhowever it would still cost a lot to brute force through the wall.\n");
                    p.LC_ObservedWall = 1;
                    cout << endl;
                }
                else if (choice == "C"){
                    p.LC_BrokenWall = 1;
                    p.LC_Searched = 1;
                    p.MC_FromLC = 1;
                    int HPRed = rand()% 3 + 1;
                    p.hp -= HPRed;
                    printout("As you forcefully smash your body into the wall, the wall shattered and crumbled,\nyou received ");
                    cout << HPRed << " ";
                    printout("damages, you still have ");
                    cout << p.hp << " HP,";
                     printout(" yet you fall intoanother cell.\n");
                    cout << endl;
                    p.position=2;
                    savedata(p);
                    goto MiddleCell;
                }

            }
            else if(p.LC_Searched == 1 && p.TR_Searched == 1 && p.LC_BrokenWall == 1 && p.LC_OpenedDoor == 1){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the Door.\nB. Observe the cushioned Walls.\nC. Go to the torture room.\nD. Go to the middle cell.\n";
                printout(options);
                cout << endl;

                // action
                cin >> choice;
                if (choice == "A"){
                    printout("You carefully inspect the door, it is a sturdy and heavy door,\nthere’s also a tiny gap on the door that allows you to peek on the other side of the room, or vice versa.\nIt would be impossible to open this door by force, but you cannot see any sort of lock or handle,\nthis door must be operated from the other side.\n");
                    p.LC_ObservedDoor = 1;
                    cout << endl;
                }
                else if (choice == "B"){
                    printout("There is a hole on the wall due to your smash before.\n");
                    p.LC_ObservedWall = 1;
                    cout << endl;
                }
                else if (choice == "C"){
                    printout("You leave the cell and go to the torture room.\n");
                    p.position=3;
                    savedata(p);
                    goto TortureRoom;
                    cout << endl;
                }
                else if (choice == "D"){
                    printout("You leave the cell and go to the middle cell.\n");
                    p.position=2;
                    savedata(p);
                    goto MiddleCell;
                    cout << endl;
                }
            }
            else if(p.LC_Searched == 1 && p.TR_Searched == 0 && p.LC_BrokenWall == 1 && p.LC_OpenedDoor == 1){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the Door.\nB. Observe the cushioned Walls.\nC. Go to the torture room.\nD. Go to the middle cell.\n";
                printout(options);
                cout << endl;

                // action
                cin >> choice;
                if (choice == "A"){
                    printout("You carefully inspect the door, it is a sturdy and heavy door,\nthere’s also a tiny gap on the door that allows you to peek on the other side of the room, or vice versa.\nIt would be impossible to open this door by force, but you cannot see any sort of lock or handle,\nthis door must be operated from the other side.\n");
                    p.LC_ObservedDoor = 1;
                    cout << endl;
                }
                else if (choice == "B"){
                    printout("There is a hole on the wall due to your smash before.\n");
                    p.LC_ObservedWall = 1;
                    cout << endl;
                }
                else if (choice == "C"){
                    printout("You leave the cell and go to the torture room.\n");
                    cout << endl;
                    p.position=3;
                    savedata(p);
                    goto TortureRoom;

                }
                else if (choice == "D"){
                    printout("You leave the cell and enter the cell nearby.\n");
                    cout << endl;
                    p.position=2;
                    savedata(p);
                    goto MiddleCell;

                }
            }
            else if(p.LC_Searched == 1 && p.TR_Searched == 1 && p.LC_BrokenWall == 1 && p.LC_OpenedDoor == 0){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the Door.\nB. Observe the cushioned Walls.\nC. Go to the middle cell.\n";
                printout(options);
                cout << endl;

                // action
                cin >> choice;
                if (choice == "A"){
                    printout("You carefully inspect the door, it is a sturdy and heavy door,\nthere’s also a tiny gap on the door that allows you to peek on the other side of the room, or vice versa.\nIt would be impossible to open this door by force, but you cannot see any sort of lock or handle,\nthis door must be operated from the other side.\n");
                    p.LC_ObservedDoor = 1;
                    cout << endl;
                }
                else if (choice == "B"){
                    printout("There is a hole on the wall due to your smash before.\n");
                    p.LC_ObservedWall = 1;
                    cout << endl;
                }
                else if (choice == "C"){
                    printout("You leave the cell and go to the middle cell.\n");
                    cout << endl;
                    p.position=3;
                    savedata(p);
                    goto TortureRoom;

                }
            }
            else if(p.LC_Searched == 1 && p.TR_Searched == 0 && p.LC_BrokenWall == 1 && p.LC_OpenedDoor == 0){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the Door.\nB. Observe the cushioned Walls.\nC. Go to the cell nearby.\n";
                printout(options);
                cout << endl;

                // action
                cin >> choice;
                if (choice == "A"){
                    printout("You carefully inspect the door, it is a sturdy and heavy door,\nthere’s also a tiny gap on the door that allows you to peek on the other side of the room, or vice versa.\nIt would be impossible to open this door by force, but you cannot see any sort of lock or handle,\nthis door must be operated from the other side.\n");
                    p.LC_ObservedDoor = 1;
                    cout << endl;
                }
                else if (choice == "B"){
                    printout("There is a hole on the wall due to your smash before.\n");
                    p.LC_ObservedWall = 1;
                    cout << endl;
                }
                else if (choice == "C"){
                    printout("You leave the cell and enter the cell nearby.\n");
                    cout << endl;
                    p.position=2;
                    savedata(p);
                    goto MiddleCell;

                }
            }
            else if(p.LC_Searched == 1 && p.TR_Searched == 0 && p.LC_BrokenWall == 1 && p.LC_OpenedDoor == 1){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the Door.\nB. Observe the cushioned Walls.\nC. Go to the cell nearby.\nD. Leave the room through the door.";
                printout(options);
                cout << endl;

                // action
                cin >> choice;
                if (choice == "A"){
                    printout("You carefully inspect the door, it is a sturdy and heavy door,\nthere’s also a tiny gap on the door that allows you to peek on the other side of the room, or vice versa.\nIt would be impossible to open this door by force, but you cannot see any sort of lock or handle,\nthis door must be operated from the other side.\n");
                    p.LC_ObservedDoor = 1;
                    cout << endl;
                }
                else if (choice == "B"){
                    printout("There is a hole on the wall due to your smash before.\n");
                    p.LC_ObservedWall = 1;
                    cout << endl;
                }
                else if (choice == "C"){
                    printout("You leave the cell and enter the cell nearby.\n");
                    cout << endl;
                    p.position=2;
                    savedata(p);
                    goto MiddleCell;
                }
                else if (choice == "C"){
                    printout("You leave the cell.\n");
                    cout << endl;
                    p.position=3;
                    savedata(p);
                    goto TortureRoom;
                }
            }
            else if(p.LC_Searched == 1 && p.TR_Searched == 1 && p.LC_BrokenWall == 1 && p.LC_OpenedDoor == 1){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the Door.\nB. Observe the cushioned Walls.\nC. Go to the cell nearby.\nD. Leave the room through the door.";
                printout(options);
                cout << endl;

                // action
                cin >> choice;
                if (choice == "A"){
                    printout("You carefully inspect the door, it is a sturdy and heavy door,\nthere’s also a tiny gap on the door that allows you to peek on the other side of the room, or vice versa.\nIt would be impossible to open this door by force, but you cannot see any sort of lock or handle,\nthis door must be operated from the other side.\n");
                    p.LC_ObservedDoor = 1;
                    cout << endl;
                }
                else if (choice == "B"){
                    printout("There is a hole on the wall due to your smash before.\n");
                    cout << endl;
                }
                else if (choice == "C"){
                    printout("You leave the cell.\n");
                    cout << endl;
                    p.position=2;
                    savedata(p);
                    goto MiddleCell;
                }
                else if (choice == "C"){
                    printout("You leave the cell.\n");
                    cout << endl;
                    p.position=3;
                    savedata(p);
                    goto TortureRoom;
                }
            }

        }
    }





    TortureRoom:{
        if (p.TR_Searched == 0){
            p.TR_Searched = 1;
            int SanRed = random()%3 + 1;
            p.san -= SanRed;
            printout(TortureRoomDes1);
            printout("Because of seeing those instruments, you lost ");
            cout << SanRed;
            printout(" sanity, you have ");
            cout << p.san;
            printout(" sanity left.");
            cout << endl;
        }
        else{
            printout(TortureRoomDes2);
        }
        while (1){
            printout(WhatToDo);
            printout("A. Observe the torture instruments.\nB. Observe the Large Mirror.\n");
            if (p.TR_ObservedDoor == 0 && p.TR_UnlockedDoor == 0){
                printout("C. Observe the metal door.\n");
            }
            else if (p.TR_ObservedDoor == 1 && p.TR_UnlockedDoor == 0 && p.MC_GetMetalKey == 0){
                printout("C. Try to open the metal door.\n");
            }
            else if (p.TR_ObservedDoor == 1 && p.TR_UnlockedDoor == 0 && p.MC_GetMetalKey == 1){
                printout("C. Try to open the metal door with the metal key.\n");
            }
            else if (p.TR_UnlockedDoor == 1){
                printout("C. Leave the torture room.\n");
            }
            if(p.MC_ObservedDoor == 0){
                printout("D. Observe the door of the middle cell.\n");
            }
            else if (p.MC_ObservedDoor == 1){
                printout("D. Go into the middle cell.\n");
            }
            if (p.TR_ObservedRCDoor == 0){
                printout("E. Observe the door of the right cell.\n");
            }
            else if (p.TR_ObservedRCDoor == 1 && p.TR_ObservedPadlock == 0){
                printout("E. Observe the padlock on the door of the right cell.\n");
            }
            else if (p.TR_ObservedPadlock == 1 && p.MC_GetMetalKey == 1 && p.SB_GetMagnetKey == 0){
                printout("E. Try to open the door of the right cell by the metal key.\n");
            }
            else if (p.TR_ObservedPadlock ==1 && p.SB_GetMagnetKey == 1){
                printout("E. Try to open the door of the right cell by the magnet key.\n");
            }
            else{
                printout("E. Observe the door of the right cell.\n");
            }
            if (p.LC_OpenedDoor == 1){
                printout("F. Enter the left cell.\n");
            }
            else if (p.LC_OpenedDoor == 0){
                printout("F. Open the door of left cell.\n");
            }
            cout << endl;
            cin >> choice;
            if (choice == "A"){
                if (p.TR_ObservedTortureIns == 0){
                    p.TR_ObservedTortureIns = 1;
                    int SanRed = random()%3 + 1;
                    p.san -= SanRed;
                    printout("You closely inspected the instruments, you realize the cruelty of the instruments,\nyou lost ");
                    cout << SanRed;
                    printout(" sanity, you have ");
                    cout << p.san;
                    printout(" sanity left.");

                }
                else if (p.TR_ObservedTortureIns == 1){
                    printout("You closely inspected the instruments, there is nothing special.\n");

                }
            }
            else if(choice == "B"){
                if (p.TR_ObservedMirror == 0){
                    p.TR_ObservedMirror = 1;
                    p.san -= 1;
                    printout("You stared into the mirror, you see yourself, nothing special, nothing worthy. You felt worthless,\nyou lost 1 sanity, you have ");
                    cout << p.san;
                    printout(" sanity left.\n");
                }
                else if (p.TR_ObservedMirror == 1){
                    printout("You stared into the mirror, you see yourself, nothing special, nothing worthy.");
                }

            }
            else if (choice == "C"){
                if (p.TR_ObservedDoor == 0 && p.TR_UnlockedDoor == 0){
                    p.TR_ObservedDoor = 1;
                    printout("This is a metal door, it seems less bulky than the cell door, but it is still vain to open it by force.\n");
                }
                else if (p.TR_ObservedDoor == 1 && p.TR_UnlockedDoor == 0 && p.MC_GetMetalKey == 0){
                    printout("You attempted to open the door, but the door seemed to be locked.\n");
                }
                else if (p.TR_ObservedDoor == 1 && p.TR_UnlockedDoor == 0 && p.MC_GetMetalKey == 1){
                    p.TR_UnlockedDoor = 1;
                    printout("You inserted the key and turned it; the door opened with a \"click\".\n");
                }
                else if (p.TR_UnlockedDoor == 1){
                    p.TR_Searched = 1;
                    printout("You leave the torture room.\n");
                    cout << endl;
                    p.position=4;
                    savedata(p);
                    goto Storage;
                }

            }
            else if (choice == "D"){
                if(p.MC_ObservedDoor == 0){
                    p.MC_ObservedDoor = 1;
                    printout("As you pushed onto the door, the door slid open, someone must have forgot to lock the door.\n");
                }
                else if (p.MC_ObservedDoor == 1){
                    p.TR_Searched = 1;
                    p.MC_FromTR = 1;
                    printout("You enter the middle cell.\n");
                    cout << endl;
                    p.position=2;
                    savedata(p);
                    goto MiddleCell;
                }

            }
            else if (choice == "E"){
               if (p.TR_ObservedRCDoor == 0){
                    p.TR_ObservedRCDoor = 1;
                    printout("Different from the other two cells, a solid metal door bar, stretched to both side of the frame, was used to prevent to door from opening.\nYou see a padlock locking the metal bar onto the door.\nIt is merely impossible for any animals or human, that can fit into this cell, to physically break through this door\n");
                }
                else if (p.TR_ObservedRCDoor == 1 && p.TR_ObservedPadlock == 0){
                    p.TR_ObservedPadlock = 1;
                    printout("The padlock is cold to touch, a layer of reinforced metal enveloped the lock.\nMade of sturdy metal, the shackle is reinforced, partially covered in another layer of steel.\nOn the side of the padlock, it writes the word \"Squire\".\n");
                }
                else if (p.TR_ObservedPadlock == 1 && p.MC_GetMetalKey == 1 && p.SB_GetMagnetKey == 0){
                    printout("You insert the metal key you found in the middle cell and turned; However, it seem that this isn't the correct key.\n");
                }
                else if (p.TR_ObservedPadlock ==1 && p.SB_GetMagnetKey == 1){
                    p.TR_UnlockedRCDoor = 1;
                    printout("You insert the key you found in the main bedroom and turned; the padlock opened with ease.\n");
                }
            }
            else if (choice == "F"){
                if (p.LC_OpenedDoor == 1){
                    printout("You enter the left cell.\n");
                    cout << endl;
                    p.position=1;
                    savedata(p);
                    goto LeftCell;
                }
                else if (p.LC_OpenedDoor == 0){
                    p.LC_OpenedDoor = 1;
                    printout("You open the door of the left cell.\n");

                }

            }
            cout << endl;

        }



    }

    MiddleCell:{
        if (p.MC_Searched == 0 && p.MC_FromLC == 1){
            int SanRed = random()%4+1;
            printout (MiddleCellDes1);
            p.san -= SanRed;
            printout ("you lost ");
            cout << SanRed;
            printout (" sanity, you have ");
            cout << p.san;
            printout (" sanity left.\n");
            cout << endl;

        }

        if (p.MC_Searched == 0 && p.MC_FromTR == 1){
            int SanRed = random()%2+1;
            printout (MiddleCellDes2);
            p.san = p.san - SanRed - 1;
            printout ("you lost ");
            cout << SanRed;
            printout (" sanity, you have ");
            cout << p.san;
            printout (" sanity left.\n");
            cout << endl;
        }

        if (p.MC_Searched == 1){
            printout (MiddleCellDes3);
        }
        while (1){
            if (p.LC_BrokenWall == 1 && p.MC_ObservedDoor == 0){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the door.\nB. Observe the corpses.\nC. Go to the left cell.\n";
                printout(options);
                cout << endl;

                // action
                cin >> choice;
                if (choice == "A"){
                    printout("As you pushed onto the door, the door slid open, someone must have forgot to lock the door.\n");
                    p.MC_ObservedDoor = 1;
                    cout << endl;
                }
                else if (choice == "B"){
                    if (p.MC_ObservedCorpses == 0){
                        int x = random()%100+1;
                        if (x <= p.luck){
                            printout("As you carefully inspect the corpses, you find noticed a shining spot, upon close inspection, you found it to be a metal key.\n");
                            p.MC_ObservedCorpses = 1;
                            p.MC_GetMetalKey = 1;
                        }
                        else{
                            int SanRed = random ()%4+2;
                            p.san -= SanRed;
                            printout("As you carefully inspect the corpses, you noticed something odd, but you failed to find it, you still rummaged through the mashed remains,\nyou lost ");
                            cout << SanRed;
                            printout(" sanity, you have ");
                            cout << p.san;
                            printout(" sanity left, eventually, you found a key.\n");
                            p.MC_ObservedCorpses = 1;
                            p.MC_GetMetalKey = 1;
                            cout << endl;
                        }
                    }
                    else if (p.MC_ObservedCorpses == 1){
                        printout("You carefully inspect the corpses, however, you don't find anything special.\n");
                        cout << endl;
                    }

                }
                else if (choice == "C"){
                    printout("You leave the cell.\n");
                    p.MC_Searched = 1;
                    cout << endl;
                    p.position=1;
                    savedata(p);
                    goto LeftCell;
                }
            }
            else if (p.LC_BrokenWall == 0 && p.MC_ObservedDoor == 1){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the corpses.\nB. Left the cell through the door.\n";
                printout(options);
                cout << endl;

                // action
                cin >> choice;

                if (choice == "A"){
                    if (p.MC_ObservedCorpses == 0){
                        int x = random()%100+1;
                        if (x <= p.luck){
                            printout("As you carefully inspect the corpses, you find noticed a shining spot, upon close inspection, you found it to be a metal key.\n");
                            p.MC_ObservedCorpses = 1;
                            p.MC_GetMetalKey = 1;
                        }
                        else{
                            int SanRed = random ()%4+2;
                            p.san -= SanRed;
                            printout("As you carefully inspect the corpses, you noticed something odd, but you failed to find it, you still rummaged through the mashed remains,\nyou lost ");
                            cout << SanRed;
                            printout(" sanity, you have ");
                            cout << p.san;
                            printout(" sanity left, eventually, you found a key.\n");
                            p.MC_ObservedCorpses = 1;
                            p.MC_GetMetalKey = 1;
                            cout << endl;
                        }
                    }
                    else if (p.MC_ObservedCorpses == 1){
                        printout("You carefully inspect the corpses, however, you don't find anything special.\n");
                        cout << endl;
                    }

                }
                else if (choice == "B"){
                    printout("You leave the cell.\n");
                    p.MC_Searched = 1;
                    cout << endl;
                    p.position=3;
                    savedata(p);
                    goto TortureRoom;
                }
            }
            else if (p.LC_BrokenWall == 1 && p.MC_ObservedDoor == 1){
                // ask for action
                printout(WhatToDo);
                string options = "A. Observe the corpses.\nB. Left the cell through the door.\nC. Go to the left cell.\n";
                printout(options);
                cout << endl;

                // action
                cin >> choice;

                if (choice == "A"){
                    if (p.MC_ObservedCorpses == 0){
                        int x = random()%100+1;
                        if (x <= p.luck){
                            printout("As you carefully inspect the corpses, you find noticed a shining spot, upon close inspection, you found it to be a metal key.\n");
                            p.MC_ObservedCorpses = 1;
                            p.MC_GetMetalKey = 1;
                        }
                        else{
                            int SanRed = random ()%4+2;
                            p.san -= SanRed;
                            printout("As you carefully inspect the corpses, you noticed something odd, but you failed to find it, you still rummaged through the mashed remains,\nyou lost ");
                            cout << SanRed;
                            printout(" sanity, you have ");
                            cout << p.san;
                            printout(" sanity left, eventually, you found a key.\n");
                            p.MC_ObservedCorpses = 1;
                            p.MC_GetMetalKey = 1;
                            cout << endl;
                        }
                    }
                    else if (p.MC_ObservedCorpses == 1){
                        printout("You carefully inspect the corpses, however, you don't find anything special.\n");
                        cout << endl;
                    }

                }
                else if (choice == "B"){
                    printout("You leave the cell.\n");
                    p.MC_Searched = 1;
                    cout << endl;
                    p.position=3;
                    savedata(p);
                    goto TortureRoom;
                }
                else if (choice == "C"){
                    printout("You leave the cell.\n");
                    p.MC_Searched = 1;
                    cout << endl;
                    p.position=1;
                    savedata(p);
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
