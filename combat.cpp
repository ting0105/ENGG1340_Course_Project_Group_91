#include <iostream>
#include <random>
#include "main.h"
using namespace std;

//Monster's stats are stored using pointers because the data will be deleted to free up memory after battle
//Return 0 if player died, return 1 if player won
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
      cout << "What do you want to do next?" << endl
      << "A. Attack" << endl;

      while (choice != "A"){
        cin >> choice;
        if (choice != "A"){
          cout << "Invalid input. Please try again" << endl;
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
            cout << "The enemy dodged your attack and received no damage!" << endl;
          }
          else{
            *monsterHP -= damage;
            cout << "You attacked the enemy and the enemy took " << damage << " damage!" << endl;
            if (*monsterHP < wounded_checker){
              cout << "The enemy seems wounded." << endl;
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
            cout << "The enemy attacked back and you both took damage!" << endl
            << "The enemy took " << damage / 2 << " damage." << endl
            << "You took " << temp << " damage" << endl
            << "You have " << playerHP << " HP left." << endl;
            if (*monsterHP < wounded_checker){
              cout << "The enemy seems wounded." << endl;
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
            cout << "You attacked the enemy and the enemy took " << damage << " damage!" << endl;
            if (*monsterHP < wounded_checker){
              cout<<"The enemy seems wounded."<<endl;
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
      choice="0";

      cout<<"The enemy attacks you!"<<endl
      <<"What do you want to do in response?"<<endl
      <<"A. Dodge"<<endl
      <<"B. Counter attack"<<endl;

      while (choice!="A"&&choice!="B"){
        cin>>choice;
        if (choice!="A"&&choice!="B"){
          cout<<"Invalid input. Please try again"<<endl;
        }
      }

      if (choice=="A"){
        if(playerDEX>=rand()%100+1){
          cout<<"You dodged the attack successfully"<<endl;
        }
        else{
          temp=rand()%6+1+4;
          playerHP-=temp;
          cout<<"You failed to dodge the attack."<<endl
          <<"You took "<<temp<<" damage."<<endl
          <<"You have "<<playerHP<<" HP left."<<endl;
          if (playerHP<=0){
            return 0;
          }
          if (*monsterHP<=0){
            return 1;
          }
        }
      }
      else if (choice=="B"){
        //determine damage by player
        if (kit_getknife==1){
          damage = rand()%8 + 1 + damage_bonus;
        }
        else if (kit_getknife==0){
          damage = rand()% 3 + 1 + damage_bonus;
        }

        if((playerSTR+playerDEX)/2>=rand()%100 +1){
          *monsterHP-=damage;
          temp=rand()%6+1+4;
          playerHP-=temp/2;
          cout<<"You counter attacked but the enemy's attack still landed on you."<<endl
          <<"The enemy took "<<damage<<" damage."<<endl
          <<"You took "<<temp/2<<" damage."<<endl
          <<"You have "<<playerHP<<" HP left."<<endl;

          if (*monsterHP<wounded_checker){
            cout<<"The enemy seems wounded."<<endl;
          }
          //Check if the player / monster is dead
          if (playerHP<=0){
            return 0;
          }
          if (*monsterHP<=0){
            return 1;
          }

        }
        else{
          temp=rand()%6+1+4+2;
          playerHP-=temp;
          cout<<"You failed to counter attack and exposed your weak spot to the enemy."<<endl
          <<"You took "<<temp<<" damage."<<endl
          <<"You have "<<playerHP<<" HP left."<<endl;
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
  }
  else if (playerDEX<*monsterDEX){
    while (true){
      //clear choice
      choice="0";

      cout<<"The enemy attacks you!"<<endl
      <<"What do you want to do in response?"<<endl
      <<"A. Dodge"<<endl
      <<"B. Counter attack"<<endl;

      while (choice!="A"||choice!="B"){
        cin>>choice;
        if (choice!="A"||choice!="B"){
          cout<<"Invalid input. Please try again"<<endl;
        }
      }

      if (choice=="A"){
        if(playerDEX>=rand()%100+1){
          cout<<"You dodged the attack successfully"<<endl;
        }
        else{
          temp=rand()%6+1+4;
          playerHP-=temp;
          cout<<"You failed to dodge the attack."<<endl
          <<"You took "<<temp<<" damage."<<endl
          <<"You have "<<playerHP<<" HP left."<<endl;
          if (playerHP<=0){
            return 0;
          }
          if (monsterHP<=0){
            return 1;
          }
        }
      }
      else if (choice=="B"){
        //determine damage by player
        if (kit_getknife==1){
          damage = rand()%8 + 1 + damage_bonus;
        }
        else if (kit_getknife==0){
          damage = rand()% 3 + 1 + damage_bonus;
        }

        if((playerSTR+playerDEX)/2>=rand()%100 +1){
          *monsterHP-=damage;
          temp=rand()%6+1+4;
          playerHP-=temp/2;
          cout<<"You counter attacked but the enemy's attack still landed on you."<<endl
          <<"The enemy took "<<damage<<" damage."<<endl
          <<"You took "<<temp/2<<" damage."<<endl
          <<"You have "<<playerHP<<" HP left."<<endl;

          if (*monsterHP<wounded_checker){
            cout<<"The enemy seems wounded."<<endl;
          }
          //Check if the player / monster is dead
          if (playerHP<=0){
            return 0;
          }
          if (*monsterHP<=0){
            return 1;
          }

        }
        else{
          temp=rand()%6+1+4+2;
          playerHP-=temp;
          cout<<"You failed to counter attack and exposed your weak spot to the enemy."<<endl
          <<"You took "<<temp<<" damage."<<endl
          <<"You have "<<playerHP<<" HP left."<<endl;
          //Check if the player / monster is dead
          if (playerHP<=0){
            return 0;
          }
          if (*monsterHP<=0){
            return 1;
          }
        }

      }


      //clear choice
      choice="0";
      cout<<"What do you want to do next?"<<endl
      <<"A. Attack";
      while (choice!="A"){
        cin>>choice;
        if (choice!="A"){
          cout<<"Invalid input. Please try again"<<endl;
        }
      }

      if (choice=="A"){
        if (kit_getknife==1){
          damage = rand()%8 + 1 + damage_bonus;
        }
        else if (kit_getknife==0){
          damage = rand()% 3 + 1 + damage_bonus;
        }

        decision_maker=rand()%2;
        //monster take dodge or counter attack action randomly
        if (decision_maker==0){
          if (*monsterDEX >= rand()%100+1){
            cout<<"The enemy dodged your attack and received no damage!"<<endl;
          }
          else{
            *monsterHP-=damage;
            cout<<"You attacked the enemy and the enemy took "<<damage<<" damage!"<<endl;

            //Check if the player / monster is dead
            if (playerHP<=0){
              return 0;
            }
            if (*monsterHP<=0){
              return 1;
            }
          }
        }
        else if (decision_maker==1){
          if ((*monsterDEX+*monsterSTR)/2 >= rand()%100+1){
            *monsterHP-=damage/2;
            temp=rand()%6+1+4;
            playerHP-=temp;
            cout<<"The enemy attacked back and you both took damage!"<<endl
            <<"The enemy took "<<damage/2<<" damage."<<endl
            <<"You took "<<temp<<" damage"<<endl
            <<"You have "<<playerHP<<" HP left."<<endl;

            if (*monsterHP<wounded_checker){
              cout<<"The enemy seems wounded."<<endl;
            }

            if (playerHP<=0){
              return 0;
            }
            if (*monsterHP<=0){
              return 1;
            }
          }
          else{
            *monsterHP-=damage;
            cout<<"You attacked the enemy and the enemy took "<<damage<<" damage!"<<endl;

            if (*monsterHP<wounded_checker){
              cout<<"The enemy seems wounded."<<endl;
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
    }
  }
}
