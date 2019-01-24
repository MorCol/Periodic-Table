 // Periodic Table Project

#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include <vector>
using namespace std;

struct Element{
  int Atomic_Number;
  string Name;
  string Symbol;
  int Group;
  int Period;
  char Block;
  float Atomic_Mass;
  float Melting_Point;
  float Boiling_Point;
  float Density;
  int Year_Discovered;
  float Ionisation_Energy;
};

void Main_Menu(){

  int i;

  cout << "Welcome to the Modern Periodic Table" << endl;
  cout << "Would you like to:" << endl;
  cout << "1. Search" << endl;
  cout << "2. Exit" << endl;
  cin >> i;

  while((i!=1) && (i!=2)){
    cout << "ERROR: Invalid Selection" << endl;
    cout << "Please retry: ";
    cin >> i;
    cout << endl;
  }

  if(i == 1){
    cout << "Enterring Search" << endl;
  }

  else if(i == 2){
    exit(0);
  }

}

void Display_Element(vector<Element>& Number, int i){

  i--;
  cout << "Name: " << Number.at(i).Name << endl;
  cout << "Atomic Number: " << Number.at(i).Atomic_Number << endl;
  cout << "Symbol: " << Number.at(i).Symbol << endl;
  cout << "Atomic Mass: " << Number.at(i).Atomic_Mass << endl;
  cout << "Melting Point: " << Number.at(i).Melting_Point << endl;
  cout << "Boiling Point: " << Number.at(i).Boiling_Point << endl;
  cout << "Year Discovered: ";
  if(Number.at(i).Year_Discovered == 0){
    cout << "Since Antiquity" << endl;}
  else{
    cout << Number.at(i).Year_Discovered << endl;}
  cout << "First Ionisation Energy: " << Number.at(i).Ionisation_Energy << endl;
  cout << "Group: " << Number.at(i).Group << endl;
  cout << "Period: " << Number.at(i).Period << endl;
  cout << "Block: " << Number.at(i).Block << endl;

}

void Import_data(vector<Element>& Number){

  Element Atomic;
  ifstream Element_Data("Data_Tables.txt");

  if(Element_Data.is_open()){

    int i = 0;
    while(Element_Data){

      Element_Data >> Atomic.Atomic_Number;
      Element_Data >> Atomic.Group;
      Element_Data >> Atomic.Period;
      Element_Data >> Atomic.Block;
      Element_Data >> Atomic.Symbol;
      Element_Data >> Atomic.Name;
      Element_Data >> Atomic.Atomic_Mass;
      Element_Data >> Atomic.Melting_Point;
      Element_Data >> Atomic.Boiling_Point;
      Element_Data >> Atomic.Density;
      Element_Data >> Atomic.Year_Discovered;
      Element_Data >> Atomic.Ionisation_Energy;
      Number.push_back(Atomic);
    }

    Element_Data.close();
  }
  else{
    cout << "File is NOT Open" << endl;
  }

}

int Search_Function(vector<Element>& Number){

  int i;
  int m;
  string input;
  int chosen_element;
  cout << "Would you like to search by:" << endl;
  cout << "1. Atomic Number" << endl;
  cout << "2. Atomic Mass" << endl;
  cout << "3. Name" << endl;
  cout << "4. Symbol" << endl;
  cout << "5. Group" << endl;
  cout << "6. Period" << endl;
  cout << "0. Return to Main Menu" << endl;

  cin >> i;
  if(i == 0){
    return 0;
  }

  if(i == 1){
    cout << "Please enter Atomic Number: ";
    cin >> chosen_element;
  }

  if(i == 2){
    cout << "Please enter Atomic Mass: ";
    cin >> m;
    int l = 0;
    vector<int> Approximate_Mass;
    while(l==0){

      for(int j=0; j<Number.size(); j++){
        int n;
        n = Number.at(j).Atomic_Mass;
        if(n == m){
          l++;
          cout << l << ". " << Number.at(j).Name << endl;
          Approximate_Mass.push_back(Number.at(j).Atomic_Number);
        }
      }

      if(l==0){
        cout << "No Elements with that approximate Mass found!" << endl;
        cout << "Please Reinput mass: ";
        cin >> m;
      }

    if(l==1){
      l--;
      chosen_element = Approximate_Mass.at(l);
      return chosen_element;
    }

    cout << "0. Return to Main Menu" << endl;
    cout << "Please select Element: ";
    cin >> m;

    m--;
    chosen_element = Approximate_Mass.at(m);
    return chosen_element;
  }
}

  if(i == 3){
    cout << "Please enter the Element's Name: ";
    cin >> input;

    int l = 0;

    while(l==0){
      for(int j = 0; j<Number.size(); j++){
        if(Number.at(j).Name == input){
        chosen_element = Number.at(j).Atomic_Number;
        l++;
        }
      }
      if(l==0){
        cout << "Element not found!" << endl;
        cout << "Please Check Spelling!" << endl;
        cin >> input;
      }
    }

    return chosen_element;
  }

  if(i == 4){
    cout << "Please enter the Element's Symbol: ";
    cin >> input;

    int l = 0;

    while(l==0){
      for(int j = 0; j<Number.size(); j++){
        if(Number.at(j).Symbol == input){
        chosen_element = Number.at(j).Atomic_Number;
        l++;
        }
      }
      if(l==0){
        cout << "Element not found!" << endl;
        cout << "Please Check Typing!" << endl;
        cin >> input;
      }
    }

    return chosen_element;
  }

  if(i == 5){
    cout << "Please enter group number: ";
    cin >> m;
    int l = 0;
    vector<int> Group_Elements;
    Group_Elements.clear();

    for(int j=0; j<Number.size(); j++){

      if(Number.at(j).Group == m){
        l++;
        cout << l << ". " << Number.at(j).Name << endl;
        Group_Elements.push_back(Number.at(j).Atomic_Number);
      }
    }

    cout << "0. Return to Main Menu" << endl;
    cout << "Please select Element: ";
    cin >> m;

    if(m == 0){
      return 0;
    }

    m--;
    chosen_element = Group_Elements.at(m);

    return chosen_element;
  }

  if(i == 6){
    cout << "Please enter period number: ";
    cin >> m;
    int l = 0;
    vector<int> Period_Elements;
    Period_Elements.clear();
    for(int j=0; j<Number.size(); j++){

      if(Number.at(j).Period == m){
        l++;
        cout << l << ". " << Number.at(j).Name << endl;
        Period_Elements.push_back(Number.at(j).Atomic_Number);
      }
    }

    cout << "0. Return to Main Menu" << endl;
    cout << "Please select Element: ";
    cin >> m;

    if(m == 0){
      return 0;
    }

    m--;
    chosen_element = Period_Elements.at(m);

    return chosen_element;
  }


}

int main(){

/*
  int Atomic_Number;
  string Name;
  string Symbol;
  int Group;
  int Period; */
  int chosen_element = 0;
  //Main_Menu();
  vector<Element> Number;
  Number.clear();

  Import_data(Number);

/*
    while(Element_Data >> Atomic_Number >> Name >> Symbol >> Group >> Period){
      cout << Atomic_Number << " " << Name << " " << Symbol << " " << Group << " " << Period << endl;
    }
*/

/*
      cout << Atomic.Atomic_Number << " " << Atomic.Name << endl;
      cout << Number.size() << endl;
      i = Number.size();
      cout << Number.at(--i).Name <<endl; */


  //int chosen_element;
  //cout << Number.size() << endl;
  //chosen_element = Search_Function(Number);
  while(chosen_element == 0){
    Main_Menu();
    chosen_element = Search_Function(Number);
  }
  Display_Element(Number, chosen_element);
}
