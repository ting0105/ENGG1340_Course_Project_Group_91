#include <iostream>
#include <random>
#include "main.h"
using namespace std;

//The function is to handle combat between player and enemy

//The function take 7 inputs
//*monsterHP, *monsterDEX, *monsterSTR are int pointers and they mean HP, DEX, STR of monster respectively
//playerHP is the HP of player which is passed by reference so it can directly modify player's HP
//playerDEX, playerSTR, playerSIZ are DEX, STR, DEX of player respectively
//kit_getknife is a bool that show if player got the knife weapon, if player has the knife weapon, the player deal more damage

//The function will return 0 if player died, return 1 if player won


//Monster's stats are stored using pointers because the data will be deleted to free up memory after battle in main
bool combat(int * monsterHP, int * monsterDEX, int * monsterSTR, int &playerHP, int playerDEX, int playerSTR, int playerSIZ, bool kit_getknife){
  bool ended = 0;
  string choice;
  int damage;
  int damage_bonus = 0;
  int temp;
  bool decision_maker;

  //if enemy HP is below wounded_checker, a message will be displayed when enemy take damage
  int wounded_checker = *monsterHP / 2;

  //determine damage bonus
  if (playerSIZ + playerSTR <= 64){
    damage_bonus = -1;
  }
  else if (playerSIZ + playerSTR <= 84){
    damage_bonus = -0;
  }
  else if (playerSIZ + playerSTR <= 124){
    damage_bonus = 1;
  }
  else if (playerSIZ + playerSTR <= 164){
    damage_bonus = rand() % 4 + 1;
  }
  else{
    damage_bonus = rand() % 6 + 1;
  }

  //use time as random seed
  srand((unsigned)time(NULL));

  //Player goes first if he has higher DEX than monster
  if (playerDEX >= *monsterDEX){
    while (true){
      //clear choice
      choice = "0";
      printout("What do you want to do next?\n");
      printout("A. Attack\n");

      while (choice != "A"){
        cin >> choice;
        if (choice != "A"){
          printout("Invalid input. Please try again\n");
        }
      }

      if (choice == "A"){
        if (kit_getknife == 1){
          damage = rand() % 8 + 1 + damage_bonus;
        }
        else if (kit_getknife == 0){
          damage = rand()% 3 + 1 + damage_bonus;
        }

        decision_maker = rand() % 2; //return 0 or 1
        //monster take dodge or counter attack action randomly
        //0 means dodge and 1 means counter attack
        if (decision_maker == 0){
          if (*monsterDEX >= rand() % 100 + 1){
            printout("The enemy dodged your attack and received no damage!\n");
          }
          else{
            *monsterHP -= damage;
            printout("You attacked the enemy and the enemy took ");
            cout << damage;
            printout(" damage!\n");

            if (*monsterHP < wounded_checker){
              printout("The enemy seems wounded.\n");
            }

            //Check if the player / monster is dead
            if (playerHP <= 0){
              return 0;
            }
            if (*monsterHP <= 0){
              return 1;
            }
          }
        }
        else if (decision_maker == 1){

          if (((*monsterDEX) + (*monsterSTR)) / 2 >= rand() % 100 + 1){
            *monsterHP -= damage / 2;
            temp = rand() % 6 + 1 + 4;
            playerHP -= temp;
            printout("The enemy attacked back and you both took damage!\n");
            printout("The enemy took ");
            cout << damage / 2;
            printout(" damage.\n");
            printout("You took ");
            cout << temp;
            printout(" damage\n");
            printout("You have ");
            cout << playerHP;
            printout(" HP left.\n");

            if (*monsterHP < wounded_checker){
              printout("The enemy seems wounded.\n");
            }
            if (playerHP <= 0){
              return 0;
            }
            if (*monsterHP <= 0){
              return 1;
            }
          }
          else{
            *monsterHP -= damage;
            printout("You attacked the enemy and the enemy took ");
            cout << damage;
            printout(" damage!\n");

            if (*monsterHP < wounded_checker){
              printout("The enemy seems wounded.\n");
            }

            //Check if the player / monster is dead
            if (playerHP<=0){
              return 0;
            }
            if (*monsterHP<=0){
              return 1;
            }
          }
        }


      }

      //clear choice
      choice = "0";

      printout("The enemy attacks you!\n");
      printout("What do you want to do in response?\n");
      printout("A. Dodge\n");
      printout("B. Counter attack\n");

      while (choice != "A" && choice != "B"){
        cin >> choice;
        if (choice != "A" && choice != "B"){
          printout("Invalid input. Please try again\n");
        }
      }

      if (choice == "A"){
        if(playerDEX >= rand() % 100 + 1){
          printout("You dodged the attack successfully\n");
        }
        else{
          temp = rand() % 6 + 1 + 4;
          playerHP -= temp;
          printout("You failed to dodge the attack.\n");
          printout("You took ");
          cout << temp;
          printout(" damage.\n");
          printout("You have ");
          cout << playerHP;
          printout(" HP left.\n");

          if (playerHP <= 0){
            return 0;
          }
          if (*monsterHP <= 0){
            return 1;
          }
        }
      }
      else if (choice == "B"){
        //determine damage by player
        if (kit_getknife == 1){
          damage = rand() % 8 + 1 + damage_bonus;
        }
        else if (kit_getknife == 0){
          damage = rand()% 3 + 1 + damage_bonus;
        }

        if((playerSTR + playerDEX) / 2 >= rand() % 100 + 1){
          *monsterHP -= damage;
          temp = rand() % 6 + 1 + 4;
          playerHP -= temp / 2;

          printout("You counter attacked but the enemy's attack still landed on you.\n");
          printout("The enemy took ");
          cout << damage;
          printout(" damage.\n");
          printout("You took ");
          cout << temp / 2;
          printout(" damage.\n");
          printout("You have ");
          cout << playerHP;
          printout(" HP left.\n");

          if (*monsterHP < wounded_checker){
            printout("The enemy seems wounded.\n");
          }
          //Check if the player / monster is dead
          if (playerHP <= 0){
            return 0;
          }
          if (*monsterHP <= 0){
            return 1;
          }

        }
        else{
          temp = rand() % 6 + 1 + 4 + 2;
          playerHP -= temp;

          printout("You failed to counter attack and exposed your weak spot to the enemy.\n");
          printout("You took ");
          cout << temp;
          printout(" damage.\n");
          printout("You have ");
          cout << playerHP;
          printout(" HP left.\n");

          //Check if the player / monster is dead
          if (playerHP <= 0){
            return 0;
          }
          if (*monsterHP <= 0){
            return 1;
          }
        }
      }
    }
  }
  else if (playerDEX < *monsterDEX){
    while (true){
      //clear choice
      choice = "0";

      printout("The enemy attacks you!\n");
      printout("What do you want to do in response?\n");
      printout("A. Dodge\n");
      printout("B. Counter attack\n");

      while (choice != "A" || choice != "B"){
        cin >> choice;
        if (choice != "A" || choice != "B"){
          printout("Invalid input. Please try again\n");
        }
      }

      if (choice == "A"){
        if(playerDEX >= rand() % 100 + 1){
          printout("You dodged the attack successfully\n");
        }
        else{
          temp = rand() % 6 + 1 + 4;
          playerHP -= temp;

          printout("You failed to dodge the attack.\n");
          printout("You took ");
          cout << temp;
          printout(" damage.\n");
          printout("You have ");
          cout<<playerHP;
          printout(" HP left.\n");

          if (playerHP <= 0){
            return 0;
          }
          if (monsterHP <= 0){
            return 1;
          }
        }
      }
      else if (choice == "B"){
        //determine damage by player
        if (kit_getknife == 1){
          damage = rand()% 8 + 1 + damage_bonus;
        }
        else if (kit_getknife == 0){
          damage = rand() % 3 + 1 + damage_bonus;
        }

        if((playerSTR + playerDEX) / 2 >= rand() % 100 + 1){
          *monsterHP -= damage;
          temp = rand() % 6 + 1 + 4;
          playerHP -= temp / 2;

          printout("You counter attacked but the enemy's attack still landed on you.\n");
          printout("The enemy took ");
          cout << damage;
          printout(" damage.\n");
          printout("You took ");
          cout << temp / 2;
          printout(" damage.\n");
          printout("You have ");
          cout << playerHP;
          printout(" HP left.\n");

          if (*monsterHP < wounded_checker){
            printout("The enemy seems wounded.\n");
          }
          //Check if the player / monster is dead
          if (playerHP <= 0){
            return 0;
          }
          if (*monsterHP <= 0){
            return 1;
          }

        }
        else{
          temp = rand() % 6 + 1 + 4 + 2;
          playerHP -= temp;
          printout("You failed to counter attack and exposed your weak spot to the enemy.\n");
          printout("You took ");
          cout << temp;
          printout(" damage.\n");
          printout("You have ");
          cout << playerHP;
          printout(" HP left.\n");

          //Check if the player / monster is dead
          if (playerHP <= 0){
            return 0;
          }
          if (*monsterHP <= 0){
            return 1;
          }
        }

      }


      //clear choice
      choice = "0";
      printout("What do you want to do next?\n");
      printout("A. Attack\n");

      while (choice != "A"){
        cin >> choice;
        if (choice != "A"){
          printout("Invalid input. Please try again\n");
        }
      }

      if (choice == "A"){
        if (kit_getknife == 1){
          damage = rand() % 8 + 1 + damage_bonus;
        }
        else if (kit_getknife == 0){
          damage = rand() % 3 + 1 + damage_bonus;
        }

        decision_maker = rand() % 2;
        //monster take dodge or counter attack action randomly
        if (decision_maker == 0){
          if (*monsterDEX >= rand() % 100 + 1){
            printout("The enemy dodged your attack and received no damage!\n");
          }
          else{
            *monsterHP -= damage;
            printout("You attacked the enemy and the enemy took ");
            cout << damage;
            printout(" damage!\n");

            //Check if the player / monster is dead
            if (playerHP <= 0){
              return 0;
            }
            if (*monsterHP <= 0){
              return 1;
            }
          }
        }
        else if (decision_maker == 1){
          if ((*monsterDEX + *monsterSTR) / 2 >= rand() % 100 + 1){
            *monsterHP -= damage / 2;
            temp = rand() % 6 + 1 + 4;
            playerHP -= temp;

            printout("The enemy attacked back and you both took damage!\n");
            printout("The enemy took ");
            cout << damage / 2;
            printout(" damage.\n");
            printout("You took ");
            cout << temp;
            printout(" damage\n");
            printout("You have ");
            cout << playerHP;
            printout(" HP left.\n");

            if (*monsterHP < wounded_checker){
              printout("The enemy seems wounded.\n");
            }

            if (playerHP <= 0){
              return 0;
            }
            if (*monsterHP <= 0){
              return 1;
            }
          }
          else{
            *monsterHP -= damage;
            printout("You attacked the enemy and the enemy took ");
            cout << damage;
            printout(" damage!\n");

            if (*monsterHP < wounded_checker){
              printout("The enemy seems wounded.\n");
            }

            //Check if the player / monster is dead
            if (playerHP <= 0){
              return 0;
            }
            if (*monsterHP <= 0){
              return 1;
            }
          }
        }
      }
    }
  }
}
