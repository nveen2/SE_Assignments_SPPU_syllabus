#include <iostream>
#include<algorithm>
#include<cmath>
#include<fstream>
using namespace std;

string searcher;
int linearProbe(string[], int, int);
int main()
{
  string choice ;
  cout<<"To start type \t check"<<endl;
  cin >> choice;
  int tablesize = 53;
start:
  string table[tablesize];
  int s = 0;
  int sz = 0;
  int collisions = 0;
  int location = 0;
  ifstream f;
  int count = 0;
  double fac = 0;
  string currWord;
  f.open("words.txt");
  while (f >> currWord)
  {
    for (int i = 0; i < currWord.length(); i++)
    {
      s += int(currWord[i]) * (i);
    }
    if (table[s % tablesize].length() > 0)
    {
      collisions += 1;
      if (choice == "check")
      {
        location = linearProbe(table, s % tablesize, tablesize);
      }
    }
    else
    {
      location = s % tablesize;
    }
    table[location] = currWord;
    count++;
    fac = static_cast<double>(count) / static_cast<double>(tablesize);
    if (fac > 0.5)
    {
      tablesize = tablesize * 2;
      f.close();
      goto start;
    }
    s = 0;
  }
  int n1 = 0;
  cout << "NO of time keep using speel checker" << endl;
  cin >> n1;
  while (n1 >= 0)
  {
    sz = 0;
    cout << "Enter a Word to search:" << endl;
    getline(cin, searcher);

    for (int i = 0; i < searcher.length(); i++)
    {
      sz += int(searcher[i]) * (i);
    }

    if (table[sz % tablesize] == searcher)
    {
      cout << "Your Word is in the table" << endl;
      cout << "The Spelling for the word you entered is correct" << endl;
      cout << endl;
    }
    else
    {
      int y = sz;
      int qaz = 1;

      if (choice == "check2")
      {

        while (qaz != 20)
        {
          y = sz + pow(qaz, 2);
          if (table[y % tablesize] == searcher)
          {
            cout << "Found the word, it is spelled correctly but suffered a collision" << endl;
            goto next;
          }
          else
          {
            qaz++;
          }
        }
        cout << "Your word is either not in the table or spelled incorrectly" << endl;

      next:

        n1--;
      }

      if (choice == "check")
      {
        int y = sz;
        int qaz = 1;

        while (table[y % tablesize].length() > 0)
        {
          y++;
          if (table[y % tablesize] == searcher)
          {
            cout << "Found the word, it is spelled correctly but suffered a collision" << endl;
            goto next1;
          }
        }

        cout << "Your word is either not in the table or spelled incorrectly" << endl;

      next1:

        n1--;
      }
    }
  }
}

int linearProbe(string table[], int i, int n)
{

  while (table[i].length() > 0)
  {
    i++;
    if (i > n)
    {
      i = i % n;
    }
  }
  return (i % n);
}