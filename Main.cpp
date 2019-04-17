// Gregory Miller
// Section 2
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <iomanip>

using namespace std;

struct person {
    char name[20];
    float balance;
};


int numberOfRecords(int);
person *readData(int);
void printmenu();
void display(person *arr, int);
void findRichest(person *arr, int);
void getDepositInfo(person *arr, int, char *custName, double *amount, int *cmpValue);
void deposit(person *arr, int, char *custName, double);
void newCopy(string, person *arr, int);

int main() {

      int choice;
      int i = 0;
      int N = numberOfRecords(i);
      person *arr = readData(N);
      char custName[19];
      double amount = 0;
      int cmpValue = -1;
      do
      {
          printmenu();
          cin >> choice;
          switch(choice)
          {
              case 1:
                  display(arr, N);
                  break;

              case 2:
                  cin.ignore();
                  getDepositInfo(arr, N, custName, &amount, &cmpValue);
                  if (cmpValue == -1) { break;}
                  deposit(arr, N, custName, amount);
                  break;

              case 3:
                  findRichest(arr, N);
                  break;

              case 4:
                  newCopy("data.txt", arr, N);
                  cout << "File Updated..." << endl;
                  break;

              case 5:
                  newCopy("data.txt", arr, N);
                  break;

              default:
                  cout << "Invalid entry" << endl;
                  break;
          }
          cout << endl;
     } while(choice != 5);
        arr = NULL;
        delete []arr;
        return 0;
}
  void printmenu() {
      cout << "Please enter a choice:" << endl;
      cout << "1. Display records"<< endl;
      cout << "2. Deposit funds"<< endl;
      cout << "3. Find Highest Balance" << endl;
      cout << "4. Update records" << endl;
      cout << "5. Exit the program" << endl;
  }

int numberOfRecords(int i){
    ifstream myData;
    myData.open("data.txt");
    string line;
    while(myData){
        getline(myData, line);
        i++;
    }
    i--;
    myData.close();
    return i;

}

person *readData(int N){
  string firstName;
  string lastName;
  person *P = new person[N];
  ifstream dataIn;
  dataIn.open("data.txt");
  int i = 0;
  while(dataIn >> firstName >> lastName >> P[i].balance){
    // dataIn >> firstName >> lastName >> P[i].balance;
    strcpy(P[i].name, (firstName + " " + lastName).c_str());
    i++;
  }
  dataIn.close();

  return P;
}

void getDepositInfo(person *arr, int N, char *custName, double *amount, int *cmpValue) {
    cout << "Enter Name: ";
    cin.getline(custName, 19);
    for(int i = 0; i < N; i++){
        if(strcmp(custName, arr[i].name) == 0) { *cmpValue = 0; break;}
    }
    if(*cmpValue == -1) { cout << "The name you entered does not match our records, please try again! "; return;}
    cout << "Amount: ";
    double depositAmount = 0;
    cin >> depositAmount;
    *amount = depositAmount;

}
void display(person *arr, int N){
    cout << "Name                Balance" << endl;
    cout << "---------------------------" << endl;
    for(int i = 0; i < N; i++){
        cout << setw(20) << left << arr[i].name << left << fixed << setprecision(2) << arr[i].balance << endl;
    }
}

void findRichest(person *arr, int N){
    int temp = 0;
    for(int i = 0; i < N; i++){
        if(arr[temp].balance < arr[i].balance) { temp = i;}
    }
    cout << "Highest balance: " << arr[temp].name << endl;
}

void deposit(person *arr, int N, char *custName, double amount){
    int temp = 0;
    for(int i = 0; i < N; i++){
        if(strcmp(custName, arr[i].name) == 0) {temp = i; break;}
    }
    arr[temp].balance += amount;
    cout << "New balance: " << arr[temp].balance << endl;
}

void newCopy(string file, person *arr, int N){
    ofstream data;
    data.open(file);
    for(int i = 0; i < N; i++){
        data << arr[i].name << " " << fixed << setprecision(2) << arr[i].balance << endl;
    }
    data.close();
}
