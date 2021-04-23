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
  bool MC_SanRed;
  bool MC_FromLC;
  bool MC_FromTR;
  bool MC_ObservedCorpses;
  bool MC_ObservedDoor;
  bool MC_GetMetalKey;

  // Torture room event
  bool TR_Searched;
  bool TR_SanRed;
  bool TR_ObservedRCDoor;
  bool TR_ObservedPadlock;
  bool TR_ObservedMirror;
  bool TR_ObservedTortureIns;
  bool TR_ObservedDoor;
  bool TR_UnlockedDoor;
  bool TR_UnlockedRCDoor;

  // Storage event
  bool Sto_Searched;
  bool Sto_ObservedBag;
  bool Sto_SearchedBag;
  bool Sto_ObservedTable;
  bool Sto_ObservedStew;
  bool Sto_EatStew;
  bool Sto_RealizeStew;
  bool Sto_ObservedStairway;

  // Entrance event
  bool Ent_Searched;
  bool Ent_ObservedDoor;

  // Living Room event
  bool LR_Searched;
  bool LR_SanRed;
  bool LR_ObservedCabinet;
  bool LR_SearchedUpperCabinet;
  bool LR_SearchedLowerCabinet;
  bool LR_GetCoal;
  bool LR_GetFirstAidKit;
  bool LR_ObservedDiningTable;
  bool LR_GetNote;
  bool LR_ConsumeDishes;
  bool LR_SearchedBody;
  bool LR_GetCopperKey;
  bool LR_ObservedFireplace;
  bool LR_CleanedFireplace;
  bool LR_SetFire;

  // Kitchen event
  bool Kit_Searched;
  bool Kit_ObservedStove;
  bool Kit_ObservedPot;
  bool Kit_GetKnife;
  bool Kit_ObservedFridge;
  bool Kit_ObservedSink;
  bool Kit_ObservedCupboard;
  bool Kit_GetChemicals;

  // Second floor event
  bool SF_Searched;
  bool SF_FromFF;
  bool SF_FromRm;
  bool SF_PickUpThePhone;
  bool SF_CallHelp;

  // Main bedroom event
  bool MB_Searched;
  bool MB_ObservedCloset;
  bool MB_ObservedBed;
  bool MB_ObservedNightStand;
  bool MB_GetCozyCoat;
  bool MB_GetDiary;
  bool MB_AddSan;
    


  // Second bedroom event
  bool SB_Sarched;
  bool SB_ObservedCloset;
  bool SB_SanRed;
  bool SB_ObservedBed;
  bool SB_AddSan;
  bool SB_ObservedNightStand;
  bool SB_OpenedDrawer;
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
  <<p.MC_SanRed<<endl
  <<p.MC_FromLC<<endl
  <<p.MC_FromTR<<endl
  <<p.MC_ObservedCorpses<<endl
  <<p.MC_ObservedDoor<<endl
  <<p.MC_GetMetalKey<<endl
  <<p.TR_Searched<<endl
  <<p.TR_SanRed<<endl
  <<p.TR_ObservedRCDoor<<endl
  <<p.TR_ObservedPadlock<<endl
  <<p.TR_ObservedMirror<<endl
  <<p.TR_ObservedTortureIns<<endl
  <<p.TR_ObservedDoor<<endl
  <<p.TR_UnlockedDoor<<endl
  <<p.TR_UnlockedRCDoor<<endl
  <<p.Sto_Searched<<endl
  <<p.Sto_ObservedBag<<endl
  <<p.Sto_SearchedBag<<endl
  <<p.Sto_ObservedTable<<endl
  <<p.Sto_ObservedStew<<endl
  <<p.Sto_EatStew<<endl
  <<p.Sto_RealizeStew<<endl
  <<p.Sto_ObservedStairway<<endl
  <<p.Ent_Searched<<endl
  <<p.Ent_ObservedDoor<<endl
  <<p.LR_Searched<<endl
  <<p.LR_SanRed<<endl
  <<p.LR_ObservedCabinet<<endl
  <<p.LR_SearchedUpperCabinet<<endl
  <<p.LR_SearchedLowerCabinet<<endl
  <<p.LR_GetCoal<<endl
  <<p.LR_GetFirstAidKit<<endl
  <<p.LR_ObservedDiningTable<<endl
  <<p.LR_GetNote<<endl
  <<p.LR_ConsumeDishes<<endl
  <<p.LR_SearchedBody<<endl
  <<p.LR_GetCopperKey<<endl
  <<p.LR_ObservedFireplace<<endl
  <<p.LR_CleanedFireplace<<endl
  <<p.LR_SetFire<<endl
  <<p.Kit_Searched<<endl
  <<p.Kit_ObservedStove<<endl
  <<p.Kit_ObservedPot<<endl
  <<p.Kit_GetKnife<<endl
  <<p.Kit_ObservedFridge<<endl
  <<p.Kit_ObservedSink<<endl
  <<p.Kit_ObservedCupboard<<endl
  <<p.Kit_GetChemicals<<endl
  <<p.SF_Searched<<endl
  <<p.SF_FromFF<<endl
  <<p.SF_FromRm<<endl
  <<p.SF_PickUpThePhone<<endl
  <<p.SF_CallHelp<<endl
  <<p.MB_Searched<<endl
  <<p.MB_ObservedCloset<<endl
  <<p.MB_ObservedBed<<endl
  <<p.MB_ObservedNightStand<<endl
  <<p.MB_GetCozyCoat<<endl
  <<p.MB_GetDiary<<endl
  <<p.MB_AddSan<<endl
  <<p.SB_Sarched<<endl
  <<p.SB_ObservedCloset<<endl
  <<p.SB_SanRed<<endl
  <<p.SB_ObservedBed<<endl
  <<p.SB_AddSan<<endl
  <<p.SB_ObservedNightStand<<endl
  <<p.SB_OpenedDrawer<<endl
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
    string TortureRoomDes1 = "As you break free from the cell, you noticed you are in a plain room\nwith white concrete walls, with no windows, a couple of torture instruments was set in the middle of room,\nsome of them have stains and some remains on them.\nThere’s also a large mirror on the other side of the room.\nYou look behind you, there are a total of 3 cells,\nthe left one, where you woke up, the middle one and the right one. While you see another door at the other end of the room.\n";
    string TortureRoomDes2 = "You enter the torture room and there is no different,\na couple of torture instruments was set in the middle of room, some of them have stains and some remains on them.\nThere are three cells in the room\nThere’s also a large mirror on the other side of the room.\n";

    // Storage description
    string StorageDes1 = "You finally escaped from the torture room, what waiting for you is another concealed area which looks like a storage room.\nIn this new room, you see a pile of bags of different types, color and size; a table with pots on it.\nOn the other side of the room, there is also a stairway leading upward.\n";
    string StorageDes2 = "You are now in the storage room, there is a pile of bags of different types, color and size; a table with pots on it.\nOn the other side of the room, there is also a stairway leading upward.\n";

    // Entrance description
    string EntranceDes = "At the entrance of the house, you see a stairway leadind down to the store room, a staircase leading up to the second floor of the house,\na door that seems to lead to the outside, a doorway to the living room.\n";

    // Living Room description
    string LivingRoomDes = "When entering the living room, a horrific scene came into your eyes, next to a dining table,\nseveral dead bodies, both males and females, was sitting on chairs.\nApart from the dining table, you also see several furniture in the living room, a cabinet, a fireplace.\n";

    // Kitchen description
    string KitchenDes = "In the kitchen you found a stove, a fridge, a sink and a cupboard.\n";

    // Second floor description
    string SecondFloorDes1 = "Stepping onto the second floor, you found nothing special, just a couple of rooms and a telephone next to the stairs,\njudging on the signs on the doors, you can tell these rooms are\nmain bedroom, second bedroom, study, restroom.\n";
    string SecondFloorDes2 = "You left the room and you are now at the corridor of the second floor.\nThere is a telephone, main bedroom, second bedroom, study, restroom.\n";
    string SecondFloorDes3 = "Stepping on the second floor, you are now at the corridor of the second floor.\n There is a telephone, main bedroom, second bedroom, study, restroom.\n";

    // Main bedroom description
    string MainBedroomDes = "You entered the main bedroom, in this bedroom you found a closet, a bed, and a nightstand beside it.\n";

    // Second bedroom description
    string SecondBedroomDes = "You entered the second bedroom, in this bedroom you found a closet, a bed, and a nightstand beside it.\n";

    


    // start, ask for new game or load game
    Start:{

    }

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
      >>p.MC_SanRed
      >>p.MC_FromLC
      >>p.MC_FromTR
      >>p.MC_ObservedCorpses
      >>p.MC_ObservedDoor
      >>p.MC_GetMetalKey
      >>p.TR_Searched
      >>p.TR_SanRed
      >>p.TR_ObservedRCDoor
      >>p.TR_ObservedPadlock
      >>p.TR_ObservedMirror
      >>p.TR_ObservedTortureIns
      >>p.TR_ObservedDoor
      >>p.TR_UnlockedDoor
      >>p.TR_UnlockedRCDoor
      >>p.Sto_Searched
      >>p.Sto_ObservedBag
      >>p.Sto_SearchedBag
      >>p.Sto_ObservedTable
      >>p.Sto_ObservedStew
      >>p.Sto_EatStew
      >>p.Sto_RealizeStew
      >>p.Sto_ObservedStairway
      >>p.Ent_Searched
      >>p.Ent_ObservedDoor
      >>p.LR_Searched
      >>p.LR_SanRed
      >>p.LR_ObservedCabinet
      >>p.LR_SearchedUpperCabinet
      >>p.LR_SearchedLowerCabinet
      >>p.LR_GetCoal
      >>p.LR_GetFirstAidKit
      >>p.LR_ObservedDiningTable
      >>p.LR_GetNote
      >>p.LR_ConsumeDishes
      >>p.LR_SearchedBody
      >>p.LR_GetCopperKey
      >>p.LR_ObservedFireplace
      >>p.LR_CleanedFireplace
      >>p.LR_SetFire
      >>p.Kit_Searched
      >>p.Kit_ObservedStove
      >>p.Kit_ObservedPot
      >>p.Kit_GetKnife
      >>p.Kit_ObservedFridge
      >>p.Kit_ObservedSink
      >>p.Kit_ObservedCupboard
      >>p.Kit_GetChemicals
      >>p.SF_Searched
      >>p.SF_FromFF
      >>p.SF_FromRm
      >>p.SF_PickUpThePhone
      >>p.SF_CallHelp
      >>p.MB_Searched
      >>p.MB_ObservedCloset
      >>p.MB_ObservedBed
      >>p.MB_ObservedNightStand
      >>p.MB_GetCozyCoat
      >>p.MB_GetDiary
      >>p.MB_AddSan
      >>p.SB_Sarched
      >>p.SB_ObservedCloset
      >>p.SB_SanRed
      >>p.SB_ObservedBed
      >>p.SB_AddSan
      >>p.SB_ObservedNightStand
      >>p.SB_OpenedDrawer
      >>p.SB_GetMagnetKey;

      fin.close();

      if (p.position == 1){
        goto LeftCell;
      }
      else if (p.position == 2){
        goto MiddleCell;
      }
      else if (p.position == 3){
        goto TortureRoom;
      }
      else if (p.position == 4){
        goto Storage;
      }
      else if (p.position == 5){
          goto Entrance;
      }
      else if (p.position == 6){
          goto LivingRoom;
      }
      else if (p.position == 7){
          goto Kitchen;
      }
      else if (p.position == 8){
          goto SecondFloor;
      }
      else if (p.position == 9){
          goto MainBedroom;
      }
      else if (p.position == 10){
          goto SecondBedroom;
      }
      else if (p.position == 11){
          goto Study;
      }
      else if (p.position == 12){
          goto Restroom;
      }
      else if (p.position == 13){
          goto RightCell;
      }
    }

    else if (fin.fail())
    {
       //stat_gen(statarray);
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
    p.MC_SanRed = 0;
    p.MC_FromLC = 0;
    p.MC_FromTR = 0;
    p.MC_ObservedCorpses = 0;
    p.MC_ObservedDoor = 0;
    p.MC_GetMetalKey = 0;

    // Torture room event
    p.TR_Searched = 0;
    p.TR_SanRed = 0;
    p.TR_ObservedRCDoor = 0;
    p.TR_ObservedPadlock = 0;
    p.TR_ObservedMirror = 0;
    p.TR_ObservedTortureIns = 0;
    p.TR_ObservedDoor = 0;
    p.TR_UnlockedDoor = 0;
    p.TR_UnlockedRCDoor = 0;
    

    // Storage event
    p.Sto_Searched = 0;
    p.Sto_ObservedBag = 0;
    p.Sto_SearchedBag = 0;
    p.Sto_ObservedTable = 0;
    p.Sto_ObservedStew = 0;
    p.Sto_EatStew = 0;
    p.Sto_RealizeStew = 0;
    p.Sto_ObservedStairway = 0;

    // Entrance event
    p.Ent_Searched = 0;
    p.Ent_ObservedDoor = 0;

    // Living Room event
    p.LR_Searched = 0;
    p.LR_SanRed = 0;
    p.LR_ObservedCabinet = 0;
    p.LR_SearchedUpperCabinet = 0;
    p.LR_SearchedLowerCabinet = 0;
    p.LR_GetCoal = 0;
    p.LR_GetFirstAidKit = 0;
    p.LR_ObservedDiningTable = 0;
    p.LR_GetNote = 0;
    p.LR_ConsumeDishes = 0;
    p.LR_SearchedBody = 0;
    p.LR_GetCopperKey = 0;
    p.LR_ObservedFireplace = 0;
    p.LR_CleanedFireplace = 0;
    p.LR_SetFire = 0;

    // Kitchen event
    p.Kit_Searched = 0;
    p.Kit_ObservedStove = 0;
    p.Kit_ObservedPot = 0;
    p.Kit_GetKnife = 0;
    p.Kit_ObservedFridge = 0;
    p.Kit_ObservedSink = 0;
    p.Kit_ObservedCupboard = 0;
    p.Kit_GetChemicals = 0;

    //Second floor event
    p.SF_Searched = 0;
    p.SF_FromFF = 0;
    p.SF_FromRm = 0;

    // Main bedroom event
    p.MB_Searched = 0;
    p.MB_ObservedCloset = 0;
    p.MB_ObservedBed = 0;
    p.MB_ObservedNightStand = 0;
    p.MB_GetCozyCoat = 0;
    p.MB_GetDiary = 0;
    p.MB_AddSan = 0;

    // Second bedroom event
    p.SB_Sarched = 0;
    p.SB_ObservedCloset = 0;
    p.SB_SanRed = 0;
    p.SB_ObservedBed = 0;
    p.SB_AddSan = 0;
    p.SB_ObservedNightStand = 0;
    p.SB_OpenedDrawer = 0;
    p.SB_GetMagnetKey = 0;


    savedata(p);


    //intro
    cout << endl;
    printout(Intro);
    cout << endl;

    cout << endl;

    p.position=1;


    // 1
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

        while (1){
            // ask for action
            printout(WhatToDo);
            if (p.LC_ObservedDoor == 0){
                printout("A. Observe the door.\n");
            }
            
            else if (p.LC_ObservedDoor == 1 && p.LC_GetWire == 1 && p.LC_OpenedDoor == 0){
                printout("A. Try to open the door with the wire.\n");
            }

            else if(p.TR_Searched == 0 && p.LC_OpenedDoor == 1){
                printout("A. Leave the cell through the door.\n");
            }
            else if(p.TR_Searched == 1 && p.LC_OpenedDoor == 1){
                printout("A. Go to torture room.\n");
            }
            else{
                printout("A. Observe the door.\n");
            }
            if (p.LC_ObservedWall == 0){
                printout("B. Observe the wall.\n");
            }
            else if (p.LC_ObservedWall == 1 && p.LC_BrokenWall == 0){
                printout("B. Attack the cushion and try to break the wall.\n");
            }
            else if (p.LC_BrokenWall == 1 && p.TR_Searched == 0){
                printout("B. Go to the cell nearby.\n");
            }
            else if (p.LC_BrokenWall == 1 && p.TR_Searched == 1){
                printout("B. Go to the middle cell.\n");
            }
            cout << endl;

            // action
            cin >> choice;
            if (choice == "A"){
                if (p.LC_ObservedDoor == 0){
                    p.LC_ObservedDoor = 1;
                    printout("You carefully inspect the door, it is a sturdy and heavy door,\nthere’s also a tiny gap on the door that allows you to peek on the other side of the room, or vice versa.\nIt would be impossible to open this door by force, but you cannot see any sort of lock or handle,\nthis door must be operated from the other side.\n");
                
                }
                else if (p.LC_ObservedDoor == 1 && p.LC_GetWire == 1 && p.LC_OpenedDoor == 0){
                    if (GenRand() > p.luck){
                        printout("As your wire hooked and fixed onto the handle outside, you gently pull the wire,\nbut the wire ruptured the moment you pulled it.\nAs the wire ruptured, it seems that you need to find another way to escape.\n");
                        
                        p.LC_GetWire = 0;
                        cout << endl;
                    }
                    else{
                        printout("You stretched your hands the very best you could, carefully hooking the twisted end of the wire onto the handle outside,\nas you feel the wire is fixed in its position, you slowly pulled the wire in, the handle gradually lifted upward,\non the very urge of the wire from being ruptured, \"click\" the metal door opened\n");
                        p.LC_OpenedDoor =1;
                        cout << endl;
                    }
                }
                else if(p.TR_Searched == 0 && p.LC_OpenedDoor == 1){
                    p.LC_Searched = 1;
                    p.position=3;
                    savedata(p);
                    printout("You left the cell through the door.\n");
                    cout << endl;
                    goto TortureRoom;
                    
                }
                else if(p.TR_Searched == 1 && p.LC_OpenedDoor == 1){
                    p.LC_Searched = 1;                   
                    p.position=3;
                    savedata(p);
                    printout("You left the cell and went to the torture room.\n");
                    cout << endl;
                    goto TortureRoom;
                }   
                else{
                    p.LC_ObservedDoor = 1;
                    printout("You carefully inspect the door, it is a sturdy and heavy door,\nthere’s also a tiny gap on the door that allows you to peek on the other side of the room, or vice versa.\nIt would be impossible to open this door by force, but you cannot see any sort of lock or handle,\nthis door must be operated from the other side.\n");
                }
            }
            else if (choice == "B"){
                if (p.LC_ObservedWall == 0){
                    p.LC_ObservedWall = 1;
                    p.LC_GetWire = 1;
                    printout("Underneath the cushion,you found the concrete wall underneath to be fragile,\nhowever it would still cost a lot to brute force through the wall, maybe you should attempt finding another way out first.\nAlso, you found a long piece of wire under the cushion.\n");
                }
                else if (p.LC_ObservedWall == 1 && p.LC_BrokenWall == 0){
                    p.LC_BrokenWall = 1;
                    p.MC_FromLC = 1;
                    p.LC_Searched = 1;
                    int HPRed = rand()% 3 + 1;
                    p.hp -= HPRed;
                    printout("As you forcefully smash your body into the wall, the wall shattered and crumbled, yet you falled into another cell.\nyou received ");
                    cout << HPRed;
                    printout(" damages, you still have ");
                    cout << p.hp;
                     printout(" HP.\n");
                    cout << endl;
                    p.position=2;
                    savedata(p);
                    goto MiddleCell;
                }
                
                else if (p.LC_BrokenWall == 1 && p.TR_Searched == 0){
                    printout("You left the cell and went to the cell nearby.\n");
                    p.position=2;
                    savedata(p);
                    cout << endl;
                    goto MiddleCell;
                    
                }
                else if (p.LC_BrokenWall == 1 && p.TR_Searched == 1){
                    printout("You left the cell and went to the middle cell.\n");
                    p.position=2;
                    savedata(p);
                    cout << endl;
                    goto MiddleCell;
                    
                } 
            }
            cout << endl;
        }
    }
    
    // 2
    MiddleCell:{
        if (p.MC_FromLC == 1 && p.MC_SanRed == 0){
            p.MC_SanRed = 1;
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

        else if (p.MC_FromTR == 1 && p.MC_SanRed == 0){
            p.MC_SanRed = 1;
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

        else if (p.MC_SanRed == 1){
            printout (MiddleCellDes3);
        }
        savedata(p);

        while (1){
                // ask for action
                printout(WhatToDo); 
                printout("A. Observe the corpses.\n");
                if (p.MC_ObservedDoor == 0){
                    printout("B. Observe the Door.\n");
                }
                else if (p.TR_Searched == 0 && p.MC_ObservedDoor == 1){
                    printout("B. Leave the cell through the door.\n");
                }
                else if (p.TR_Searched == 1 && p.MC_ObservedDoor == 1){
                    printout("B. Go to the torture room.\n");
                }
                if (p.LC_BrokenWall == 1 && p.TR_Searched == 0){
                    printout("C. Go to the cell nearby.\n");
                }
                else if (p.LC_BrokenWall == 1 && p.TR_Searched == 1){
                    printout("C. Go to the left cell.\n");
                }
                cout << endl;

                // action
                cin >> choice;
                if(choice == "A"){
                    if (p.MC_ObservedCorpses == 0){
                        int x = random()%100+1;
                        if (x <= p.luck){
                            p.MC_ObservedCorpses = 1;
                            p.MC_GetMetalKey = 1;
                            printout("As you carefully inspected the corpses, you find noticed a shining spot, upon close inspection, you found it to be a metal key.\n");
                        }
                        else{
                            p.MC_ObservedCorpses = 1;
                            p.MC_GetMetalKey = 1;
                            int SanRed = random ()%4+2;
                            p.san -= SanRed;
                            printout("As you carefully inspected the corpses, you noticed something odd, but you failed to find it, you still rummaged through the mashed remains,\nyou lost ");
                            cout << SanRed;
                            printout(" sanity, you have ");
                            cout << p.san;
                            printout(" sanity left, eventually, you found a metal key.\n");
                        }  
                    }
                    else if (p.MC_ObservedCorpses == 1){
                        printout("You carefully inspected the corpses, however, you didn't find anything special.\n");
                        cout << endl;
                    }
                }
                else if (choice == "B"){
                    if (p.MC_ObservedDoor == 0){
                        p.MC_ObservedDoor = 1;
                        printout("As you pushed onto the door, the door slid open, someone must have forgot to lock the door.\n");
                    }
                    else if (p.TR_Searched == 0 && p.MC_ObservedDoor == 1){
                        printout("You left the cell.\n");
                        p.MC_Searched = 1;
                        p.position = 3;
                        cout << endl;
                        savedata(p);
                        goto TortureRoom;
                    }
                    else if (p.TR_Searched == 1 && p.MC_ObservedDoor == 1){
                        printout("You left the cell and went to the torture room.\n");
                        p.MC_Searched = 1;
                        p.position = 3;
                        cout << endl;
                        savedata(p);
                        goto TortureRoom;
                    }
                }
                else if (choice == "C"){
                    if (p.LC_BrokenWall == 1 && p.TR_Searched == 0){
                        printout("You left the cell.\n");
                        p.MC_Searched = 1;
                        p.position = 1;
                        cout << endl;
                        savedata(p);
                        goto LeftCell;
                    }
                    else if (p.LC_BrokenWall == 1 && p.TR_Searched == 1){
                        printout("You left the cell and went to the left cell.\n");
                        p.MC_Searched = 1;
                        cout << endl;
                        p.position=1;
                        savedata(p);
                        goto LeftCell;
                        
                    }
                }
                cout << endl;

            }   
        }

    // 3
    TortureRoom:{
        if (p.TR_Searched == 0 && p.TR_SanRed == 0){
            p.TR_SanRed = 1;
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
        savedata(p);
        while (1){
            // ask for action
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
            else if (p.TR_UnlockedDoor == 1 && p.Sto_Searched == 0){
                printout("C. Leave the torture room through the metal door.\n");
            }
            else if (p.TR_UnlockedDoor == 1 && p.Sto_Searched == 1){
                printout("C. Go to storage room.\n");
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
            
            // action
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
                    printout("You insert the metal key you found in the middle cell and turned; However, it seems that this isn't the correct key.\n");
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

    // 4
    Storage:{
        if (p.Sto_Searched == 0){
            printout(StorageDes1);
        }
        else{
            printout(StorageDes2);
        }
        while (1){
            // Ask for action.
            printout(WhatToDo);
            if (p.Sto_ObservedBag == 0){
                printout("A. Observe the bags.\n");
            }
            else if (p.Sto_ObservedBag == 1){
                printout("A. Search the bags.\n");
            }
            if (p.Sto_ObservedTable == 0){
               printout("B. Observe the table.\n");
            }
            else if (p.Sto_ObservedTable == 1 && p.Sto_ObservedStew == 0){
                printout("B. Observe the mysterious stew.\n");
            }
            else if (p.Sto_ObservedStew == 1){
                printout("B. Eat the stew.\n");
            }
            if(p.Sto_ObservedStairway == 0){
                printout("C. Observer the stairway.\n");
            }
            else if (p.Sto_ObservedStairway == 1){
                printout("C. Leave the room through the stairway.\n");
            }
            if(p.TR_UnlockedDoor == 1){
                printout("D. Go to the torture room.\n");
                cout << endl;
            }
            cout << endl;

            // action.
            cin >> choice;
            if (choice  == "A"){
                if (p.Sto_ObservedBag == 0){
                    p.Sto_ObservedBag = 1;
                    printout("This is a pile of bags, perhaps you can find your lost belongings in here?\n");
                    if (GenRand() < p.inte){
                        p.san -= 1;
                        printout("Also, You realize the number of people that was kidnapped here and possibly murdered,\nyou lost 1 sanity, you have ");
                        cout << p.san;
                        printout(" sanity left.\n");
                    }
                }
                else if (p.Sto_ObservedBag == 1 && p.Sto_SearchedBag == 0){
                    p.Sto_SearchedBag = 1;
                    printout("Unluckly, you found that all the bags are empty, it seems that your belongings were thrown away.\n");
                }
                else if (p.Sto_ObservedBag == 1 && p.Sto_SearchedBag == 1){
                    printout("You searched the bags before and you found that all the bags are empty.\n");
                }
            }
            else if (choice == "B"){
                if (p.Sto_ObservedTable == 0){
                    p.Sto_ObservedTable = 1;
                    printout("On the table there is a few pots lying on it. There’s mysterious stew in them.\n");
                }
                else if (p.Sto_ObservedTable == 1 && p.Sto_ObservedStew == 0){
                    p.Sto_ObservedStew = 1;
                    printout("The mysterious stew are blood red in colour, it doesn't look good.\n");
                    if (GenRand() < p.inte){
                        p.Sto_RealizeStew = 1;
                        int SanRed = 2 * (random()%2+1);
                        p.san -= SanRed;
                        printout("Suddently, You realize the mysterious stew are made of human parts, you lost ");
                        cout << SanRed;
                        printout(" sanity,you have ");
                        cout << p.san;
                        printout(" sanity left.\n");
                    }
                }
                else if (p.Sto_ObservedStew == 1 && p.Sto_EatStew == 0){
                    p.Sto_EatStew = 1;
                    p.san --;
                    printout("You found this stew tastes particularly awful,\nyou lost 1 sanity, you have ");
                    cout << p.san;
                    printout(" sanity left.\n");
                    if (p.Sto_RealizeStew == 0){
                        p.Sto_RealizeStew = 1;
                        int SanRed = 2 * (random()%2+1);
                        p.san -= SanRed;
                        printout("Suddently, You realize the mysterious stew are made of human parts, you lost ");
                        cout << SanRed;
                        printout(" sanity,you have ");
                        cout << p.san;
                        printout(" sanity left.\n"); 
                    }
                }
                else if (p.Sto_ObservedStew == 1 && p.Sto_EatStew == 1){
                    printout("You found this stew tastes particularly awful.\n");
                }
            }
            else if (choice == "C"){
                if(p.Sto_ObservedStairway == 0){
                    p.Sto_ObservedStairway = 1;
                    printout("This stairway leads upstairs. This seems to be the only way out.\n");
                }
                else if (p.Sto_ObservedStairway == 1){
                    p.Sto_Searched = 1;
                    p.position = 5;
                    printout("You left the room through the stairway.\n");
                    cout << endl;
                    savedata(p);
                    cout << endl;
                    goto Entrance;
                }
            }
            else if (choice == "D"){
                if(p.TR_UnlockedDoor == 1){
                    p.Sto_Searched = 1;
                    p.position = 3;
                    printout("You left the room.\n");
                    savedata(p);
                    cout << endl;
                    goto TortureRoom;
                }
            }
            cout << endl;
        }
    }

    // 5
    Entrance:{
        printout(EntranceDes);
        
        while (1){
            // ask for action
            printout(WhatToDo);
            printout("A. Observe the door.\n");
            printout("B. Move to the second floor.\n");
            printout("C. Go to the living room.\n");
            printout("D. Go to the storage room.\n");
            cout << endl;

            // action
            cin >> choice;
            if (choice == "A"){
                if (p.Ent_ObservedDoor == 0){
                    p.Ent_ObservedDoor = 1;
                    p.san = p.san - 2;
                    printout("Through the peephole, you found that outside the door is only endless mist and eternal darkness,\nas you gaze into the abyss, the abyss gaze back,\nyou lost 2 sanity, you have ");
                    cout << p.san;
                    printout(" sanity left.\n");
                }
                else if(p.Ent_ObservedDoor == 1){
                    printout("Because of fear, you are afraid to look through the peephole again.\n");
                }
            }
            else if (choice == "B"){
                p.Ent_Searched = 1;
                p.position = 8;
                p.SF_FromFF = 1;
                printout("You left the entrance and reached second floor.\n");
                savedata(p);
                cout << endl;
                goto SecondFloor;
                
            }
            else if (choice == "C"){
                p.Ent_Searched = 1;
                p.position = 6;
                printout("You left the entrance and entered the living room.\n");
                savedata(p);
                cout << endl;
                goto LivingRoom;
            }
            else if (choice == "D"){
                p.Ent_Searched = 1;
                p.position = 4;
                printout("You left the entrance and entered the storage room.\n");
                savedata(p);
                cout << endl;
                goto Storage;
            }
            cout << endl;
        }
    }

    // 6
    LivingRoom:{
        printout(LivingRoomDes);
        if (p.LR_SanRed == 0){
            p.LR_SanRed = 1;
            int SanRed = (random()%2+1)*2;
            p.san -= SanRed;
            printout("Because of seeing the dead bodies, you lost ");
            cout << SanRed;
            printout(" sanity, You have ");
            cout << p.san;
            printout(" sanity left.\n"); 
        }
        savedata(p);

        while(1){
            // ask for action
            printout(WhatToDo);
            if(p.LR_ObservedCabinet == 0){
                printout("A. Observe the cabinet.\n");
            }
            else if (p.LR_ObservedCabinet == 1){
                printout("A1. Search the upper compartment.\nA2. Search the lower compartment.\n");
            }
            if (p.LR_ObservedDiningTable == 0){
                printout("B. Observe the dining table.\n");
            }
            else if (p.LR_ObservedDiningTable == 1){
                printout("B. Consume the dishes.\n");
            }
            printout("C. Observe the dead bodies.\n");
            if (p.LR_ObservedFireplace == 0){
                printout("D. Observe the fireplace.\n");
            }
            else if (p.LR_ObservedFireplace == 1 && p.LR_CleanedFireplace == 0){
                printout("D. Clean the fireplace.\n");
            }
            else if (p.LR_CleanedFireplace == 1 && p.LR_GetCoal == 1){
                printout("D. Set Fire in fireplace.\n");
            }


            else{
                printout("D. Observe the fireplace.\n");
            }
            printout("E. Go to kitchen.\n");
            printout("F. Go to Entrance.\n");
            cout << endl;

            // ACTION
            cin >> choice;
            if (choice == "A"){
                if (p.LR_ObservedCabinet == 0){
                    p.LR_ObservedCabinet = 1;
                    printout("The display cabinet is divided into two compartments,\nthe upper one with a glass door, filled with display dishes, the lower one with a wooden door.\n");
                }
            }
            else if ( choice == "A1"){
                if (p.LR_ObservedCabinet == 1 && p.LR_SearchedUpperCabinet == 0){
                    p.LR_SearchedUpperCabinet = 1;
                    printout("You rummaged through the cabinet, but you cannot find anything besides the dishes.\n");
                }
                else if (p.LR_SearchedUpperCabinet == 1){
                    printout("You searched it before and you didn't find anything useful.\n");
                }
            }
            else if ( choice == "A2"){
                if(p.LR_ObservedCabinet == 1 && p.LR_GetCopperKey == 0 && p.MC_GetMetalKey == 1){
                    printout("You attempted to open the door of the compartment, but it seemed to be locked.\nIt is obvious that the metal key you found in the middle cell isn't the correct key.\n");
                }
                else if(p.LR_ObservedCabinet == 1 && p.LR_GetCopperKey == 0 && p.MC_GetMetalKey == 0){
                    printout("You attempted to open the door of the compartment, but it seemed to be locked.\n");
                }
                else if (p.LR_ObservedCabinet == 1 && p.LR_GetCopperKey == 1){
                    p.LR_SearchedLowerCabinet = 1;
                    p.LR_GetCoal = 1;
                    p.LR_GetFirstAidKit = 1;
                    printout("You opened the door with ease with the copper key, inside you found several bags of coal, and a first aid kit.\n");
                }
            }
            else if (choice == "B"){
                if (p.LR_ObservedDiningTable == 0){
                    p.LR_ObservedDiningTable = 1;
                    p.LR_GetNote = 1;
                    printout("As you closely inspect the table, you found various kind of dishes are set on the table.\nThere also appears to be a note on the table.\n");
                }
                else if(p.LR_ObservedDiningTable == 1){
                    if(p.LR_ConsumeDishes == 0){
                        p.LR_ConsumeDishes = 1;
                        p.san --;
                        printout("The moment you tasted the foods, you vomited, there’s no way these are edible by humans,\nyou lost 1 sanity, you have ");
                        cout << p.san;
                        printout(" sanity left.\n");
                    }
                    else if(p.LR_ConsumeDishes = 1){
                        printout("You tasted the foods before and you don't want to try it again.\n");
                    }
                }
            }
            else if (choice == "C"){
                if (p.LR_SearchedBody == 0 && p.LR_GetCopperKey == 0){
                    p.LR_GetCopperKey = 1;
                    p.LR_SearchedBody = 1;
                    printout("You carefully inspected the bodies,on a body, you found a copper key.\n");
                }
                else if (p.LR_SearchedBody == 1){
                    printout("You carefully inspected the bodies again, but you didn't find anything special.\n");
                    if (GenRand()>p.luck){
                        p.san --;
                        printout("when you were inspecting one of the bodies, you felt that she was looking at you, this make you feel terrified.\nYou lost 1 sanity, you have ");
                        cout<< p.san;
                        printout(" sanity left.\n");
                    }
                }
            }
            else if (choice == "D"){
                if (p.LR_ObservedFireplace == 0){
                    p.LR_ObservedFireplace = 1;
                    printout ("The fireplace is filled with ashes and remains of coals. It would take a bit of effort to clear it but wouldn’t be too long.\n");
                }
                else if (p.LR_ObservedFireplace == 1 && p.LR_CleanedFireplace == 0){
                    p.LR_CleanedFireplace = 1;
                    printout ("The fireplace was cleaned and it is able to set fire in it now.\n");
                }
                else if (p.LR_CleanedFireplace == 1 && p.LR_GetCoal == 0 && p.LR_SetFire == 0){
                    printout("You cleaned the fireplace, if you have coal, you can set fire.\n");
                }
                else if (p.LR_GetCoal == 1 && p.LR_CleanedFireplace == 1){
                    p.LR_SetFire = 1;
                    p.LR_GetCoal = 0;
                    p.san++;
                    printout("After you set the fire in the fireplace, warmth surrounds you, you felt much better than what you were,\nyou gained 1 sanity, you have ");
                    cout<<p.san;
                    printout(" sanity left.\n");
                }
                else if (p.LR_GetCoal == 0 && p.LR_SetFire == 1){
                    printout("You looked at the fire in the fireplace, you felt warm.\n");
                }
            }
            else if (choice == "E"){
                p.LR_Searched = 1;
                p.position = 7;
                savedata(p);
                printout("You entered the kitchen.\n");
                cout << endl;
                goto Kitchen;
            }
            else if (choice == "F"){
                p.LR_Searched = 1;
                p.position = 5;
                savedata(p);
                printout("You entered the entrance.\n");
                cout << endl;
                goto Entrance;
            }
            cout << endl;
        }
    }
    
    // 7
    Kitchen:{
        printout(KitchenDes);

        while(1){
            // ask for action
            printout(WhatToDo);
            if (p.Kit_ObservedStove == 0){
                printout("A. Observe the stove.\n");
            }
            else if (p.Kit_ObservedStove == 1){
                printout("A1. Observe the pot.\nA2. Take a knife.\n");
            }
            printout("B. Observe the fridge.\n");
            printout("C. Observe the sink.\n");
            if (p.Kit_ObservedCupboard == 0){
                printout("D. Observe the cupboard.\n");
            }
            else if(p.Kit_ObservedCupboard == 1 && p.Kit_GetChemicals == 0){
                printout("D. Take the box of mysterious chemicals.\n");
            }
            else if(p.Kit_GetChemicals == 1 && p.Kit_ObservedCupboard == 1 ){
                printout("D. Observe the cupboard.\n");
            }
            printout("E. Go to living room.\n");
            cout << endl;

            // action
            cin >> choice;
            if (choice == "A"){
                if ( p.Kit_ObservedStove == 0){
                    p.Kit_ObservedStove = 1;
                    printout("On the stove there’s a frying pan, a pot with lid on and a few other cooking instruments.\nAlso, there are some knifes, they seems good to be a weapon.\n");
                }
            }
            else if (choice == "A1"){
                if (p.Kit_ObservedStove == 1){
                    if(p.Kit_ObservedPot == 0){
                        p.Kit_ObservedPot = 1;
                        printout("You opened the pot, only to discover human remains and flesh within. You lost 1 sanity, you have ");
                        cout << p.san;
                        printout(" sanity left.\n");
                    }
                    else if (p.Kit_ObservedPot == 1){
                        printout("You checked it before, it contains human remains and flesh.\n");
                    }
                    
                }
            }
            else if (choice == "A2"){
                if (p.Kit_ObservedStove == 1){
                    if (p.Kit_GetKnife == 0){
                        p.Kit_GetKnife = 1;
                        printout ("You took a knife as a weapon.\n");
                    }
                    else if(p.Kit_GetKnife = 1){
                        printout ("You already have one, you don't need two.\n");
                    } 
                }
            }
            else if (choice == "B"){
                if (p.Kit_ObservedFridge == 0){
                    p.Kit_ObservedFridge = 1;
                    p.san--;
                    printout("In the fridge, you can only find frozen human remains and a few soft drinks… You lost 1 sanity, you have ");
                    cout << p.san;
                    printout(" sanity left.\n");
                }
                else if(p.Kit_ObservedFridge == 1){
                    printout("You searched it before, there are some frozen human remains and a few soft drinks inside.\n");
                }
            }
            else if (choice == "C"){
                p.Kit_ObservedSink = 1;
                printout("In the sink there’s a few dishes that are unfinished, also you couldn’t turn on the tap.\n");
            }
            else if (choice == "D"){
                if (p.Kit_ObservedCupboard == 0){
                    p.Kit_ObservedCupboard = 1;
                    printout("In the cupboard, you found a few box of cereals and a storage box of mircotubes, inside the tubes are greenish fluid,\non the side of the boxes there’s a skull & crossbones symbol, on the cover of the box a small label wrote “αCaMKII Inducer”,\nit would not be wise to take a sip out of these tubes.\n");
                }
                else if (p.Kit_GetChemicals == 0 && p.Kit_ObservedCupboard == 1){
                    p.Kit_GetChemicals = 1;
                    printout("You took the box of mysterious chemicals.\n");
                }
                else{
                    printout("You found a box of mysterious chemicals here and there is a few box of cereals.\n");
                }
            }
            else if (choice == "E"){
                p.Kit_Searched = 1;
                p.position = 6;
                savedata(p);
                printout("You left the kitchen and went back to the living room.\n");
                cout << endl;
                goto LivingRoom;
            }
            cout << endl;

        }

    }

    // 8
    SecondFloor:{
        if (p.SF_Searched == 0 && p.SF_FromFF == 1){
            p.SF_FromFF = 0;
            printout(SecondFloorDes1);
        }
        else if (p.SF_FromRm == 1 && p.SF_Searched == 1){
            p.SF_FromRm = 0;
            printout(SecondFloorDes2);
        }
        else if (p.SF_FromFF == 1 && p.SF_Searched == 1){
            p.SF_FromFF = 0;
            printout(SecondFloorDes3);
        }
        while(1){
            // ask for action
            printout(WhatToDo);
            if (p.SF_PickUpThePhone == 0 ){
                printout("A. Pick up the telephone.\n");
            }
            if(p.SF_PickUpThePhone == 1){
                printout("A1. Dial a number.\n");
            }
            if(p.SF_PickUpThePhone == 1){
                printout("A2. Put down the telephone.\n");
            }
            printout("B. Enter the main bedroom.\n");
            printout("C. Enter the second bedroom.\n");
            printout("D. Enter the study.\n");
            printout("E. Enter the restroom.\n");
            cout <<  endl;

            cin >> choice;
            if (choice == "A"){
                if (p.SF_PickUpThePhone == 0){
                    p.SF_PickUpThePhone = 1;
                    printout("You picked up the phone, as expected, there’s no response…\n");
                }
                
            }
            else if(choice == "A1"){
                if (p.SF_CallHelp == 0 && p.SF_PickUpThePhone == 1){
                    p.SF_CallHelp = 1;
                    printout("You dialed a number and hope the other side would pick up, but nobody came…\n");
                }
                else if (p.SF_CallHelp == 1 && p.SF_PickUpThePhone == 1){
                    printout("You dialed a number again, but nobody came…\n");
                }
            }
            else if(choice == "A2"){
                if (p.SF_PickUpThePhone == 1){
                    p.SF_PickUpThePhone = 0;
                    printout("You put down the telephone.\n");
                }
            }
            else if (choice == "B"){
                if (p.SF_PickUpThePhone == 1){
                    p.SF_PickUpThePhone = 0;
                    p.SF_Searched = 1;
                    p.position = 9;
                    savedata(p);
                    printout("You put down the telephone and entered the main bedroom.\n");
                    cout << endl;
                }
                else if (p.SF_PickUpThePhone == 0){
                    p.SF_Searched = 1;
                    p.position = 9;
                    savedata(p);
                    printout("You entered the main bed room.\n");
                    cout << endl;
                }
                goto MainBedroom;

            }
            else if (choice == "C"){
                if (p.SF_PickUpThePhone == 1){
                    p.SF_PickUpThePhone = 0;
                    p.SF_Searched = 1;
                    p.position = 10;
                    savedata(p);
                    printout("You put down the telephone and entered the second bedroom.\n");
                    cout << endl;
                }
                else if (p.SF_PickUpThePhone == 0){
                    p.SF_Searched = 1;
                    p.position = 10;
                    savedata(p);
                    printout("You entered the seconc bedroom.\n");
                    cout << endl;
                }
                goto SecondBedroom;

            }
            else if (choice == "D"){
                if (p.SF_PickUpThePhone == 1){
                    p.SF_PickUpThePhone = 0;
                    p.SF_Searched = 1;
                    p.position = 11;
                    savedata(p);
                    printout("You put down the telephone and entered the study.\n");
                    cout << endl;
                }
                else if (p.SF_PickUpThePhone == 0){
                    p.SF_Searched = 1;
                    p.position = 11;
                    savedata(p);
                    printout("You entered the study.\n");
                    cout << endl;
                }
                goto Study;

            }
            else if (choice == "E"){
                if (p.SF_PickUpThePhone == 1){
                    p.SF_PickUpThePhone = 0;
                    p.SF_Searched = 1;
                    p.position = 12;
                    savedata(p);
                    printout("You put down the telephone and entered the restroom.\n");
                    cout << endl;
                }
                else if (p.SF_PickUpThePhone == 0){
                    p.SF_Searched = 1;
                    p.position = 12;
                    savedata(p);
                    printout("You entered the restroom.\n");
                    cout << endl;
                }
                goto Restroom;
            }
            cout << endl;     
        }
    }

    // 9
    MainBedroom:{
        printout(MainBedroomDes);
        while(1){
            printout(WhatToDo);
            printout("A. Observe the closet.\n");
            printout("B. Observe the bed.\n");
            printout("C. Observe the nightstand.\n");
            printout("D. Left the main bedroom.\n");
            cout << endl;

            cin >>  choice;
            if (choice == "A"){
                if (p.MB_ObservedCloset == 0){
                    p.MB_ObservedCloset = 1;
                    p.MB_GetCozyCoat = 1;
                    printout("In the closet there are a few smelly clothes, you found a brand-new cozy coat as well.\n");
                }
                else if(p.MB_ObservedCloset == 1){
                    printout("You found a brand-new cozy coat here before, there are a few smelly clothes left.\n");
                }
            }
            else if(choice == "B"){
                if (p.MB_ObservedBed == 0){
                    p.MB_ObservedBed = 1;
                    printout("The bed does not have any mattress, it’s just a plank of wood.\n");
                }
                else if(p.MB_ObservedBed == 1){
                    printout("You observed the bed before, it’s just a plank of wood.\n");
                }
            }
            else if(choice == "C"){
                if(p.MB_ObservedNightStand == 0){
                    p.MB_ObservedNightStand = 1;
                    p.MB_GetDiary = 1;
                    printout("On the nightstand, you found a diary.\n");
                }
                else if(p.MB_ObservedNightStand == 1){
                    printout("You found a diary here before and it's empty now.\n");
                }

            }
            else if(choice == "D"){
                p.MB_Searched = 1;
                p.position = 8;
                p.SF_FromRm = 1;
                savedata(p);
                printout("You left the main bedroom.\n");
                cout << endl;
                goto SecondFloor;
            }
            cout << endl;
        }

    }

    // 10
    SecondBedroom:{
        printout(SecondBedroomDes);
        while(1){
            printout(WhatToDo);
            printout("A. Observe the closet.\n");
            if (p.SB_ObservedBed == 0){
                printout("B. Observe the bed.\n");
            }
            else if(p.SB_ObservedBed == 1){
                printout("B. Lie on the bed.\n");
            }
            if (p.SB_ObservedNightStand == 0){
                printout("C. Observe the nightstand.\n");
            }
            else if (p.SB_ObservedNightStand == 1){
                printout("C. Observe the drawer.\n");
            }

            cout << endl;
            cin << choice;
            if (choice == "A"){
                if (p.SB_ObservedCloset == 0){
                    p.SB_ObservedCloset = 1;
                    p.SB_SanRed = 1;
                    p.san --;
                    printout("Opening the closet, a few pieces of human body fell out, you lost 1 sanity, you have ");
                    cout << san;
                    printout(" sanity left.\n");
                }
                else if (p.SB_SanRed == 1 && p.SB_ObservedCloset == 1){
                    printout("A few pieces of human body fell on the ground and there is nothing in the closet now.\n");
                }
            }
            else if (choice == "B"){
                if (p.SB_ObservedBed == 0){
                    p.SB_ObservedBed = 1;
                    printout("The bed has a mattress on it.\n");
                }
                else if (p.SB_ObservedBed == 1 && p.SB_AddSan == 0){
                    p.SB_AddSan = 1;
                    p.san ++;
                    printout("Lying on the bed, you felt relieved from the stress. You gained 1 sanity, you have ");
                    cout << p.san;
                    printout(" sanity left.\n");
                }
                else if (p.SB_ObservedBed == 1 && p.SB_AddSan == 1){
                    printout ("After a short break, you realised that you should left this house as soon as possible.\n");
                }
            }

            }
        }

    }

    // 11
    Study:{

    }

    // 12
    Restroom:{

    }

    // 13
    RightCell:{

    }

    Dead:{

    }
    END:{
        printout("As you woke up, the first thing you saw is a plain yet unfamiliar ceiling. \n\"Where am I?\", you thought to yourself, but your brain could hardly gather enough memory to construct an answer.\nAs you stood up, you found yourself in a clean yet seemingly familiar house, a strange yet pleasant aroma filled up the house.\nYou looked to the center of the room, copious and various dishes was set on a dining table,\nsomehow a sudden feeling of disgust rushes up into your mind when you saw the chairs that scattered around the table.\nYou look to the sides of the room, at the extremity of the room, you found a door, that resembles a front door in your memory.\nAs you approach the door, a faint light shines from underneath the door.\nTrembling, you pushed the door opened.\nYour tried to keep your eyes opened, as the brightening light engulfed you.");
    }

}
