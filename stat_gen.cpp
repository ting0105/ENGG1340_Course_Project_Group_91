#include <iostream>
#include "main.h"
#include <random>
#include <string>

#include <unistd.h>
using namespace std;

//Generate player stats and store the 8 stats into an int array
//Player can distribute their attribute points freely or let the program distribute remaining points for them randomly

//The program take a int array of size 10 as input

//The program will output a int array with size 10, which
//str = statarray[0];
//con = statarray[1];
//dex = statarray[2];
//siz = statarray[3];
//inte = statarray[4];
//pow = statarray[5];
//app = statarray[6];
//luck = statarray[7];
//hp = statarray[8];
//san = statarray[9];

void printout(string paragraph){
    int x = 0;
    while (paragraph[x] != '\0'){
        cout << paragraph[x++];
        cout.flush();
        usleep(20000); // 10000
    }
}

void stat_gen(int arr[10])
{
  printout("Welcome to Call of Cthulhu (CoC)!!!\nNow, you need to create your own investigator.\nYou can distribute the attribute point to different characteristics which will affect your playing style.\n");
  printout("Your total attribute points will be determined by eight 3D6 die roll, and that number multiplied by 5.\n");
  int totalpoint=0;
  int temp=0;
  int temptotal=0;
  int random_temp;

  int counter=1;
  srand((unsigned)time(NULL)) ;
  while (counter<=8)
  {
    //Determine the total points player have by dice roll
    temptotal=0;

    printout("Die roll ");
    cout << counter << ": ";
    printout("You rolled ");
    temp = rand() % 6 + 1;
    temptotal += temp;
    cout << temp << " + ";


    temp = rand() % 6 + 1;
    temptotal += temp;
    cout << temp << " + ";

    temp = rand() % 6 + 1;
    temptotal += temp;
    cout << temp << " = " << temptotal << endl;

    totalpoint += temptotal;
    counter++;
  }

  printout("Your total attribute points is ");
  cout << totalpoint;
  totalpoint *= 5;
  printout(" * 5 = ");
  cout << totalpoint << endl << endl;

  int pointleft = totalpoint;
  int str=0;
  int con=0;
  int pow=0;
  int dex=0;
  int app=0;
  int siz=0;
  int inte=0;
  int luck=0;
  int hp=0;
  int san=0;


  printout("Now you can distribute your points.\n");
  printout("You can use command [attribute name] [value] to distribute your points.\n");
  printout("For example, the command \"STR 50\" will add 50 points to STR (strength)\n");
  printout("You may put minimum 15 points and maximum 90 points in each attribute except HP and SAN.\n");
  printout("It is because the value of HP is depended on SIZ and CON, while SAN is depended on POW.\n");
  printout("HP = (SIZ + CON) / 10 and SAN = POW\n");
  printout("Use the command \"reset\" if you wish to reset all attribute points.\n");
  printout("Use the command \"random\" if you wish to distribute the remaining points randomly\n");

  bool finished = false;
  string input;
  int value;

  while (finished == false)
  {
    //check if character creation is finished
    if (pointleft == 0)
    {
      if (str >= 15 && str <= 90 && con >= 15 && con <= 90 && dex >= 15 && dex <= 90 && siz >= 15 && siz <= 90
        && inte >= 15 && inte <= 90 && pow >= 15 && pow <= 90 && app >= 15 && app <= 90 && luck >= 15 && luck <= 90)
      {
        printout("\nYour current stats :\n");
        printout("STR (strength)     :");
        cout << str << endl;
        printout("CON (constitution) :");
        cout<< con << endl;
        printout("POW (willpower)    :");
        cout << pow << endl;
        printout("DEX (Dexterity)    :");
        cout << dex << endl;
        printout("APP (appearance)   :");
        cout << app << endl;
        printout("SIZ (size)         :");
        cout << siz << endl;
        printout("INT (intelligence) :");
        cout << inte << endl;
        printout("LUC (luck)         :");
        cout << luck << endl << endl;
        printout("HP  (Hit Points)   :");
        cout << hp << endl;
        printout("SAN (Sanity)       :");
        cout << san << endl;
        printout("You have distributed all your attribute points.\n");
        printout("use command \"confirm\" to finish character creation or use command \"reset\" to reset.\n**Once you confirmed, you cannot change the characteristics until the end of the game or the death of your investigator.**\n");

        cin >> input;

        if (input == "confirm")
        {
          finished = true;
          arr[0] = str;
          arr[1] = con;
          arr[2] = pow;
          arr[3] = dex;
          arr[4] = app;
          arr[5] = siz;
          arr[6] = inte;
          arr[7] = luck;
          arr[8] = hp;
          arr[9] = san;
          break;
        }
        else if(input == "reset")
        {
          pointleft = totalpoint;
          str = 0;
          con = 0;
          pow = 0;
          dex = 0;
          app = 0;
          siz = 0;
          inte = 0;
          luck = 0;
          hp = 0;
          san = 0;
        }
        else
        {
          printout("invalid input, please try again.\n");
          cin.clear();
          cin.ignore(10000,'\n');
          continue;
        }

      }
      else
      {
        printout("Some attributes are not in range between 15 and 90, point distribution has been reset, please distribute your points again.\n");
        pointleft=totalpoint;
        str = 0;
        con = 0;
        pow = 0;
        dex = 0;
        app = 0;
        siz = 0;
        inte = 0;
        luck = 0;
        hp = 0;
        san = 0;
      }
    }
    printout("\nYour current stats :\n");
    printout("STR (strength)     :");
    cout << str << endl;
    printout("CON (constitution) :");
    cout << con << endl;
    printout("POW (willpower)    :");
    cout << pow << endl;
    printout("DEX (Dexterity)    :");
    cout << dex << endl;
    printout("APP (appearance)   :");
    cout << app << endl;
    printout("SIZ (size)         :");
    cout << siz << endl;
    printout("INT (intelligence) :");
    cout << inte << endl;
    printout("LUC (luck)         :");
    cout << luck << endl << endl;
    printout("HP  (Hit Points)   :");
    cout << hp << endl;
    printout("SAN (Sanity)       :");
    cout << san << endl;
    printout("Points left: ");
    cout << pointleft << endl;

//user will input command like "STR 50" to distribute points.
    cin >> input;
    if (input == "STR"){
      cin >> value;
      //deal with invalid inputs
      if (cin.fail() || value<0)
      {
        printout("Invalid input, please try again.\n");
        cin.clear();
        cin.ignore(10000,'\n');
      }
      else if (value <= pointleft)
      {
        str += value;
        pointleft -= value;
      }
      else
      {
        printout("You do not have enough points, perhaps you want to reset with the \"reset\" command?\n");
      }
    }

    else if (input == "CON"){
      cin >> value;
      if (cin.fail() || value < 0)
      {
        printout("Invalid input, please try again.\n");
        cin.clear();
        cin.ignore(10000,'\n');
      }
      else if (value <= pointleft)
      {
        con += value;
        hp = (con + siz) / 10;
        pointleft -= value;
      }
      else
      {
        printout("You do not have enough points, perhaps you want to reset with the \"reset\" command?\n");
      }
    }

    else if (input == "DEX"){
      cin >> value;
      if (cin.fail() || value < 0)
      {
        printout("Invalid input, please try again.\n");
        cin.clear();
        cin.ignore(10000,'\n');
      }
      else if (value <= pointleft)
      {
        dex += value;
        pointleft -= value;
      }
      else
      {
        printout("You do not have enough points, perhaps you want to reset with the \"reset\" command?\n");
      }
    }

    else if (input == "SIZ"){
      cin >> value;
      if (cin.fail() || value < 0)
      {
        printout("Invalid input, please try again.\n");
        cin.clear();
        cin.ignore(10000,'\n');
      }
      else if (value <= pointleft)
      {
        siz += value;
        hp = (con + siz) / 10;
        pointleft -= value;
      }
      else
      {
        printout("You do not have enough points, perhaps you want to reset with the \"reset\" command?\n");
      }
    }

    else if (input == "INT"){
      cin >> value;
      if (cin.fail() || value < 0)
      {
        printout("Invalid input, please try again.\n");
        cin.clear();
        cin.ignore(10000,'\n');
      }
      else if (value <= pointleft)
      {
        inte += value;
        pointleft -= value;
      }
      else
      {
        printout("You do not have enough points, perhaps you want to reset with the \"reset\" command?\n");
      }
    }

    else if (input == "POW"){
      cin >> value;
      if (cin.fail() || value < 0)
      {
        printout("Invalid input, please try again.\n");
        cin.clear();
        cin.ignore(10000,'\n');
      }
      else if (value <= pointleft)
      {
        pow += value;
        san = pow;
        pointleft -= value;
      }
      else
      {
        printout("You do not have enough points, perhaps you want to reset with the \"reset\" command?\n");
      }
    }

    else if (input == "APP"){
      cin >> value;
      if (cin.fail() || value < 0)
      {
        printout("Invalid input, please try again.\n");
        cin.clear();
        cin.ignore(10000,'\n');
      }
      else if (value <= pointleft)
      {
        app += value;
        pointleft -= value;
      }
      else
      {
        printout("You do not have enough points, perhaps you want to reset with the \"reset\" command?\n");
      }
    }

    else if (input == "LUC"){
      cin >> value;
      if (cin.fail() || value < 0)
      {
        printout("Invalid input, please try again.\n");
        cin.clear();
        cin.ignore(10000,'\n');
      }
      else if (value <= pointleft)
      {
        luck += value;
        pointleft -= value;
      }
      else
      {
        printout("You do not have enough points, perhaps you want to reset with the \"reset\" command?\n");
      }
    }

    else if (input == "reset")
    {
      pointleft = totalpoint;
      str = 0;
      con = 0;
      pow = 0;
      dex = 0;
      app = 0;
      siz = 0;
      inte = 0;
      luck = 0;
      hp = 0;
      san = 0;
    }
    else if (input == "random")
    {
      //make sure all attribute is more than 15
      for (int i = 0;i < 8;i++)
      {
        if (i == 0)
        {
          if (str < 15)
          {
            random_temp = 15 - str;
            str += random_temp;
            pointleft -= random_temp;
          }
        }
        if (i == 1)
        {
          if (con < 15)
          {
            random_temp = 15 - con;
            con += random_temp;
            hp = (con + siz) / 10;
            pointleft -= random_temp;
          }
        }
        if (i == 2)
        {
          if (pow < 15)
          {
            random_temp = 15 - pow;
            pow += random_temp;
            san = pow;
            pointleft -= random_temp;
          }
        }
        if (i == 3)
        {
          if (dex < 15)
          {
            random_temp = 15 - dex;
            dex += random_temp;
            pointleft -= random_temp;
          }
        }
        if (i == 4)
        {
          if (app < 15)
          {
            random_temp = 15 - app;
            app += random_temp;
            pointleft -= random_temp;
          }
        }
        if (i == 5)
        {
          if (siz < 15)
          {
            random_temp = 15 - siz;
            siz += random_temp;
            hp = (con + siz) / 10;
            pointleft -= random_temp;
          }
        }
        if (i == 6)
        {
          if (inte < 15)
          {
            random_temp = 15 - inte;
            inte += random_temp;
            pointleft -= random_temp;
          }
        }
        if (i == 7)
        {
          if (luck < 15)
          {
            random_temp = 15 - luck;
            luck += random_temp;
            pointleft -= random_temp;
          }
        }

        //If player cannot fulfill the minimum requirement of 15 point for all attributes, reset for them
        if (pointleft < 0)
        {
          printout("You do not have enough points to fulfill the minimum requirement of 15 point for all attributes, point distribution has been reset, please distribute your points again.\n");
          pointleft = totalpoint;
          str = 0;
          con = 0;
          pow = 0;
          dex = 0;
          app = 0;
          siz = 0;
          inte = 0;
          luck = 0;
          hp = 0;
          san = 0;
        }
      }
      int which_stat_to_add; //used for determining which stat to add randomly

      while (pointleft != 0)
      {
        which_stat_to_add = rand() % 8;

        if (which_stat_to_add == 0)
        {
          //make sure attribute point don't exceed the 90 limit or more than the points left
          if (pointleft <= (90 - str))
          {
            random_temp = rand() % pointleft + 1;
            str += random_temp;
            pointleft -= random_temp;
          }
          else
          {
            random_temp = rand() % (91 - str);
            str += random_temp;
            pointleft -= random_temp;
          }
        }
        else if (which_stat_to_add == 1)
        {
          //make sure attribute point don't exceed the 90 limit or more than the points left
          if (pointleft <= (90 - con))
          {
            random_temp = rand() % pointleft + 1;
            con += random_temp;
            hp = (con + siz) / 10;
            pointleft -= random_temp;
          }
          else
          {
            random_temp = rand() % (91 - con);
            con += random_temp;
            hp = (con + siz) / 10;
            pointleft -= random_temp;
          }
        }
        else if (which_stat_to_add == 2)
        {
          //make sure attribute point don't exceed the 90 limit or more than the points left
          if (pointleft <= (90 - pow))
          {
            random_temp = rand() % pointleft + 1;
            pow += random_temp;
            san = pow;
            pointleft -= random_temp;
          }
          else
          {
            random_temp = rand() % (91 - pow);
            pow += random_temp;
            san = pow;
            pointleft -= random_temp;
          }
        }
        else if (which_stat_to_add == 3)
        {
          //make sure attribute point don't exceed the 90 limit or more than the points left
          if (pointleft <= (90 - dex))
          {
            random_temp = rand() % pointleft + 1;
            dex += random_temp;
            pointleft -= random_temp;
          }
          else
          {
            random_temp = rand() % (91 - dex);
            dex += random_temp;
            pointleft -= random_temp;
          }
        }
        else if (which_stat_to_add == 4)
        {
          //make sure attribute point don't exceed the 90 limit or more than the points left
          if (pointleft <= (90 - app))
          {
            random_temp = rand() % pointleft + 1;
            app += random_temp;
            pointleft -= random_temp;
          }
          else
          {
            random_temp = rand() % (91 - app );
            app += random_temp;
            pointleft -= random_temp;
          }
        }
        else if (which_stat_to_add == 5)
        {
          //make sure attribute point don't exceed the 90 limit or more than the points left
          if (pointleft <= (90 - siz))
          {
            random_temp = rand() % pointleft + 1;
            siz += random_temp;
            hp = (con + siz) / 10;
            pointleft -= random_temp;
          }
          else
          {
            random_temp = rand() % (91 - siz);
            siz += random_temp;
            hp = (con + siz) / 10;
            pointleft -= random_temp;
          }
        }
        else if (which_stat_to_add == 6)
        {
          //make sure attribute point don't exceed the 90 limit or more than the points left
          if (pointleft <= (90 - inte))
          {
            random_temp = rand() % pointleft + 1;
            inte += random_temp;
            pointleft -= random_temp;
          }
          else
          {
            random_temp = rand() % (91 - inte);
            inte += random_temp;
            pointleft -= random_temp;
          }
        }
        else if (which_stat_to_add == 7)
        {
          //make sure attribute point don't exceed the 90 limit or more than the points left
          if (pointleft <= (90 - luck))
          {
            random_temp = rand() % pointleft + 1;
            luck += random_temp;
            pointleft -= random_temp;
          }
          else
          {
            random_temp = rand() % (91 - luck);
            luck += random_temp;
            pointleft -= random_temp;
          }
        }
      }
    }
    else
    {
      printout("Invalid input, please try again.\n");
      cin.clear();
      cin.ignore(10000,'\n');
    }

    if (str > 90 || con > 90 || pow > 90 || dex > 90 || app > 90
    || siz > 90 ||  inte > 90 || luck > 90)
    {
      printout("Some of the attribute exceed 90, all attribute should be in range of 15 and 90.\n");
      printout("Points have been reset for you, please try again.\n");
      pointleft = totalpoint;
      str = 0;
      con = 0;
      pow = 0;
      dex = 0;
      app = 0;
      siz = 0;
      inte = 0;
      luck = 0;
      hp = 0;
      san = 0;
    }


  }
}




int main()
{
  int statarray[10];
  stat_gen(statarray);
  return 0;
}
