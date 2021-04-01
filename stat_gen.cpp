#include <iostream>
#include "main.h"
#include <random>
using namespace std;

//generate the stats and store the 7 stats into an int array

void stat_gen(int arr[7])
{
  cout<<"Your total attribute points will be determined by seven 3D6 die roll, and that number multiplied by 5."<<endl;
  int totalpoint=0;
  int temp=0;
  int temptotal=0;

  int counter=1;
  srand((unsigned)time(NULL)) ;
  while (counter<=7)
  {
    temptotal=0;

    cout<<"Die roll "<<counter<<": ";
    cout<<"You rolled ";
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

  cout<<"Your total attribute points is "<<totalpoint;
  totalpoint *= 5;
  cout<<" * 5 = "<<totalpoint<<endl<<endl;

  int pointleft=totalpoint;
  int str=0;
  int con=0;
  int pow=0;
  int dex=0;
  int app=0;
  int siz=0;
  int inte=0;

  cout<<"Now you can distribute your points."<<endl;
  cout<<"You can use command [attribute name] [value] to distribute your points."<<endl;
  cout<<"For example, the command \"STR 50\" will add 50 points to STR (strength)"<<endl;
  cout<<"You may put minimum 15 points and maximum 90 points in each attribute."<<endl;
  cout<<"Use the command \"reset\" if you wish to reset all attribute points."<<endl<<endl;

  bool finished=false;
  string input;
  int value;

  while (finished==false)
  {
    //check if character creation is finished
    if (pointleft==0)
    {
      if (str>=15&&str<=90&&con>=15&&con<=90&&dex>=15&&dex<=90&&siz>=15&&siz<=90&&inte>=15&&inte<=90&&pow>=15&&pow<=90&&app>=15&&app<=90)
      {
        cout<<"You have distributed all your attribute points."<<endl;
        cout<<"use command \"confirm\" to finish character creation or use command \"reset\" to reset."<<endl;
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

        }
        else
        {
          cout<<"invalid input, please try again."<<endl;
          cin.clear();
          cin.ignore(10000,'\n');
          continue;
        }

      }
      else
      {
        cout<<"Some attributes are not in range between 15 and 90, points distribution has been reset, please distribute your points again."<<endl;
        pointleft=totalpoint;
        str=0;
        con=0;
        pow=0;
        dex=0;
        app=0;
        siz=0;
        inte=0;
      }
    }
    cout<<"Your current stats: "<<endl;
    cout<<"STR (strength):     "<<str<<endl;
    cout<<"CON (constitution): "<<con<<endl;
    cout<<"POW (power):        "<<pow<<endl;
    cout<<"DEX (Dexterity):    "<<dex<<endl;
    cout<<"APP (appearance):   "<<app<<endl;
    cout<<"SIZ (size):         "<<siz<<endl;
    cout<<"INT (intelligence): "<<inte<<endl;
    cout<<"Points left: "<<pointleft<<endl;

//user will input command like "STR 50" to distribute points.
    cin>>input;
    if (input=="STR"){
      cin>>value;
      //deal with invalid inputs
      if (cin.fail() ||value<0)
      {
        cout<<"Invalid input, please try again."<<endl;
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
        cout<<"You do not have enough points, perhaps you want to reset with the \"reset\" command?"<<endl;
      }
    }

    else if (input=="CON"){
      cin>>value;
      if (cin.fail() || value<0)
      {
        cout<<"Invalid input, please try again."<<endl;
        cin.clear();
        cin.ignore(10000,'\n');
      }
      else if (value<=pointleft)
      {
        con+=value;
        pointleft-=value;
      }
      else
      {
        cout<<"You do not have enough points, perhaps you want to reset with the \"reset\" command?"<<endl;
      }
    }

    else if (input=="DEX"){
      cin>>value;
      if (cin.fail() || value<0)
      {
        cout<<"Invalid input, please try again."<<endl;
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
        cout<<"You do not have enough points, perhaps you want to reset with the \"reset\" command?"<<endl;
      }
    }

    else if (input=="SIZ"){
      cin>>value;
      if (cin.fail() || value<0)
      {
        cout<<"Invalid input, please try again."<<endl;
        cin.clear();
        cin.ignore(10000,'\n');
      }
      else if (value<=pointleft)
      {
        siz+=value;
        pointleft-=value;
      }
      else
      {
        cout<<"You do not have enough points, perhaps you want to reset with the \"reset\" command?"<<endl;
      }
    }

    else if (input=="INT"){
      cin>>value;
      if (cin.fail() || value<0)
      {
        cout<<"Invalid input, please try again."<<endl;
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
        cout<<"You do not have enough points, perhaps you want to reset with the \"reset\" command?"<<endl;
      }
    }

    else if (input=="POW"){
      cin>>value;
      if (cin.fail() || value<0)
      {
        cout<<"Invalid input, please try again."<<endl;
        cin.clear();
        cin.ignore(10000,'\n');
      }
      else if (value<=pointleft)
      {
        pow+=value;
        pointleft-=value;
      }
      else
      {
        cout<<"You do not have enough points, perhaps you want to reset with the \"reset\" command?"<<endl;
      }
    }

    else if (input=="APP"){
      cin>>value;
      if (cin.fail() || value<0)
      {
        cout<<"Invalid input, please try again."<<endl;
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
        cout<<"You do not have enough points, perhaps you want to reset with the \"reset\" command?"<<endl;
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
    }
    
    else
    {
      cout<<"Invalid input, please try again."<<endl;
      cin.clear();
      cin.ignore(10000,'\n');
    }

  }
}
