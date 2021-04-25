#include <iostream>
#include "main.h"
#include <random>
#include <string>
using namespace std;

//generate the stats and store the 8 stats into an int array

void stat_gen(int arr[10])
{
  printout("Welcome to Call of Cthulhu (CoC)!!!\nNow, you need to create your own investigator.\nYou can distribute the attribute point to different characteristics which will affect your playing style.\n");
  printout("Your total attribute points will be determined by eight 3D6 die roll, and that number multiplied by 5.\n");
  int totalpoint=0;
  int temp=0;
  int temptotal=0;

  int counter=1;
  srand((unsigned)time(NULL)) ;
  while (counter<=8)
  {
    temptotal=0;

    printout("Die roll ");
    cout<<counter<<": ";
    printout("You rolled ");
    temp = rand()%6+1;
    temptotal += temp;
    cout<<temp<<" + ";


    temp = rand()%6+1;
    temptotal += temp;
    cout<<temp<<" + ";

    temp = rand()%6+1;
    temptotal += temp;
    cout<<temp<<" = "<<temptotal<<endl;

    totalpoint+=temptotal;
    counter++;
  }

  printout("Your total attribute points is ");
  cout << totalpoint;
  totalpoint *= 5;
  printout(" * 5 = ");
  cout<<totalpoint<<endl<<endl;

  int pointleft=totalpoint;
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
  printout("Use the command \"reset\" if you wish to reset all attribute points.\n\n");

  bool finished=false;
  string input;
  int value;

  while (finished==false)
  {
    //check if character creation is finished
    if (pointleft==0)
    {
      if (str>=15&&str<=90&&con>=15&&con<=90&&dex>=15&&dex<=90&&siz>=15&&siz<=90&&inte>=15&&inte<=90&&pow>=15&&pow<=90&&app>=15&&app<=90&&luck>=15&&luck<=90) 
      {
        printout("\nYour current stats :\n");
        printout("STR (strength)     :");
        cout<<str<<endl;
        printout("CON (constitution) :");
        cout<<con<<endl;
        printout("POW (willpower)    :");
        cout<<pow<<endl;
        printout("DEX (Dexterity)    :");
        cout<<dex<<endl;
        printout("APP (appearance)   :");
        cout<<app<<endl;
        printout("SIZ (size)         :");
        cout<<siz<<endl;
        printout("INT (intelligence) :");
        cout<<inte<<endl;
        printout("LUC (luck)         :");
        cout<<luck<<endl<<endl;
        printout("HP  (Hit Points)   :");
        cout<<hp<<endl;
        printout("SAN (Sanity)       :");
        cout<<san<<endl;
        printout("You have distributed all your attribute points.\n");
        printout("use command \"confirm\" to finish character creation or use command \"reset\" to reset.\n**Once you confirmed, you cannot change the characteristics until the end of the game or the death of your investigator.**\n");
        
        cin>>input;
        if (input=="confirm")
        {
          finished=true;
          arr[0]=str;
          arr[1]=con;
          arr[2]=pow;
          arr[3]=dex;
          arr[4]=app;
          arr[5]=siz;
          arr[6]=inte;
          arr[7]=luck;
          arr[8]=hp;
          arr[9]=san;
          break;
        }
        else if(input=="reset")
        {
          pointleft=totalpoint;
          str=0;
          con=0;
          pow=0;
          dex=0;
          app=0;
          siz=0;
          inte=0;
          luck=0;
          hp=0;
          san=0;

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
        printout("Some attributes are not in range between 15 and 90, points distribution has been reset, please distribute your points again.\n");
        pointleft=totalpoint;
        str=0;
        con=0;
        pow=0;
        dex=0;
        app=0;
        siz=0;
        inte=0;
        luck=0;
        hp=0;
        san=0;
        
      }
    }
    printout("\nYour current stats :\n");
    printout("STR (strength)     :");
    cout<<str<<endl;
    printout("CON (constitution) :");
    cout<<con<<endl;
    printout("POW (willpower)    :");
    cout<<pow<<endl;
    printout("DEX (Dexterity)    :");
    cout<<dex<<endl;
    printout("APP (appearance)   :");
    cout<<app<<endl;
    printout("SIZ (size)         :");
    cout<<siz<<endl;
    printout("INT (intelligence) :");
    cout<<inte<<endl;
    printout("LUC (luck)         :");
    cout<<luck<<endl<<endl;
    printout("HP  (Hit Points)   :");
    cout<<hp<<endl;
    printout("SAN (Sanity)       :");
    cout<<san<<endl;
    printout("Points left: ");
    cout<<pointleft<<endl;

//user will input command like "STR 50" to distribute points.
    cin>>input;
    if (input=="STR"){
      cin>>value;
      //deal with invalid inputs
      if (cin.fail() ||value<0)
      {
        printout("Invalid input, please try again.\n");
        cin.clear();
        cin.ignore(10000,'\n');
      }
      else if (value<=pointleft)
      {
        str+=value;
        pointleft-=value;
      }
      else
      {
        printout("You do not have enough points, perhaps you want to reset with the \"reset\" command?\n");
      }
    }

    else if (input=="CON"){
      cin>>value;
      if (cin.fail() || value<0)
      {
        printout("Invalid input, please try again.\n");
        cin.clear();
        cin.ignore(10000,'\n');
      }
      else if (value<=pointleft)
      {
        con+=value;
        hp=(con+siz)/10;
        pointleft-=value;
      }
      else
      {
        printout("You do not have enough points, perhaps you want to reset with the \"reset\" command?\n");
      }
    }

    else if (input=="DEX"){
      cin>>value;
      if (cin.fail() || value<0)
      {
        printout("Invalid input, please try again.\n");
        cin.clear();
        cin.ignore(10000,'\n');
      }
      else if (value<=pointleft)
      {
        dex+=value;
        pointleft-=value;
      }
      else
      {
        printout("You do not have enough points, perhaps you want to reset with the \"reset\" command?\n");
      }
    }

    else if (input=="SIZ"){
      cin>>value;
      if (cin.fail() || value<0)
      {
        printout("Invalid input, please try again.\n");
        cin.clear();
        cin.ignore(10000,'\n');
      }
      else if (value<=pointleft)
      {
        siz+=value;
        hp=(con+siz)/10;
        pointleft-=value;
      }
      else
      {
        printout("You do not have enough points, perhaps you want to reset with the \"reset\" command?\n");
      }
    }

    else if (input=="INT"){
      cin>>value;
      if (cin.fail() || value<0)
      {
        printout("Invalid input, please try again.\n");
        cin.clear();
        cin.ignore(10000,'\n');
      }
      else if (value<=pointleft)
      {
        inte+=value;
        pointleft-=value;
      }
      else
      {
        printout("You do not have enough points, perhaps you want to reset with the \"reset\" command?\n");
      }
    }

    else if (input=="POW"){
      cin>>value;
      if (cin.fail() || value<0)
      {
        printout("Invalid input, please try again.\n");
        cin.clear();
        cin.ignore(10000,'\n');
      }
      else if (value<=pointleft)
      {
        pow+=value;
        san=pow;
        pointleft-=value;
      }
      else
      {
        printout("You do not have enough points, perhaps you want to reset with the \"reset\" command?\n");
      }
    }

    else if (input=="APP"){
      cin>>value;
      if (cin.fail() || value<0)
      {
        printout("Invalid input, please try again.\n");
        cin.clear();
        cin.ignore(10000,'\n');
      }
      else if (value<=pointleft)
      {
        app+=value;
        pointleft-=value;
      }
      else
      {
        printout("You do not have enough points, perhaps you want to reset with the \"reset\" command?\n");
      }
    }

    else if (input=="LUC"){
      cin>>value;
      if (cin.fail() || value<0)
      {
        printout("Invalid input, please try again.\n");
        cin.clear();
        cin.ignore(10000,'\n');
      }
      else if (value<=pointleft)
      {
        luck+=value;
        pointleft-=value;
      }
      else
      {
        printout("You do not have enough points, perhaps you want to reset with the \"reset\" command?\n");
      }
    }

    else if (input=="reset")
    {
      pointleft=totalpoint;
      str=0;
      con=0;
      pow=0;
      dex=0;
      app=0;
      siz=0;
      inte=0;
      luck=0;
      hp=0;
      san=0;
    }
    
    else
    {
      printout("Invalid input, please try again.\n");
      cin.clear();
      cin.ignore(10000,'\n');
    }

  }
}
