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
void fillPerson(person P[], int);
void display(person P[], int);
void findRichest(person P[], int);
void deposit(char custName[], person P[], int);
void newCopy(string file, person P[], int);

int main() {
    int n = 0;
    int numAccounts = numberOfRecords(n);
    person P[numAccounts];
    fillPerson(P, numAccounts);
    display(P, numAccounts);
    findRichest(P, numAccounts);
    char custName[20];  // we need to make a char array so we can pass to our function
    cout << "Enter your full name to deposit money: ";
    cin.getline(custName, 20);  // we want to make sure that the name they enter can fit into our char name[20]
    deposit(custName, P, numAccounts);
    newCopy("data.txt", P, numAccounts);
    
    return 0;
}

int numberOfRecords(int n){ // find the ammount of people are in the file
    ifstream myData;
    myData.open("data.txt");
    string line;
    while(myData){  // while we can get data from the file
        getline(myData, line);  // take a line
        n++;    // increase counter
    }
    n--;
    myData.close();
    return n;
    
}

void fillPerson(person P[], int numAccounts){       // take in data from the file and fill the struct array
    string firstName = "";
    string lastName = "";
    int i = 0;  // initialize counter
    ifstream myData;
    myData.open("data.txt");    // open file
    while(myData){
        myData >> firstName >> lastName >> P[i].balance;    // take in data from array since firstName and lastName is a string and not a c-string
        // we can direclty put in the last variable into struct array in savings
        strcpy(P[i].name, (firstName + " " + lastName).c_str());    // combine firstName and lastName into a c-string and copy that into our char name array
        i++;    // we need to use counter to iterate and fill char name array
    }
    myData.close(); // close file
}

void display(person P[], int numAccounts){  // display the struct array
    cout << "Name                Balance" << endl;
    cout << "---------------------------" << endl;
    for(int i = 0; i < numAccounts; i++){   // loop through the struct array and cout each ones name and savings
        cout << setw(20) << left << P[i].name << left << fixed << setprecision(2) << P[i].balance << endl;
    }
}

void findRichest(person P[], int numAccounts){  // finds the richest person and displays who they are
    int temp = 0;   // temp variable so we can take index of greater valued
    for(int i = 0; i < numAccounts; i++){   // loop through everyones savings and if we find a greater savings make temp that index's number
        if(P[temp].balance < P[i].balance) { temp = i;}
    }
    cout << "The customer with maximum balance is " << P[temp].name << endl;    // cout the richest person
}

void deposit(char custName[], person P[], int numAccounts){ // pick the person you want to deposit and increase their savings by that ammount
    int cmpValue = -1;   // since strcmp returns -1 or 1 if the strings are not equal and returns 0 if they are we want the base case to be false(-1/1)
    int temp = 0;
    // i used to have cmpValue = 1 but if index 1 of P then we would get a bug and would cout the name entered does not match always
    for(int i = 0; i < numAccounts; i++){   // loop through the struct array
        if(strcmp(custName, P[i].name) == 0) { cmpValue = 0; temp = i; break;}    // if when we compare the name given to the names in the struct array and there is a match (strcmp returns 0) so if it returns 0 then we want to change our cmpValue so below code doesnt go off and set a temp variable to the index we find the name in
    }
    if(cmpValue == -1) { cout << "The name you entered does not match our records"; return;} // if we didnt find a match
    cout << P[temp].name << ", how much would you like to deposit? ";
    float depositAmount = 0;
    cin >> depositAmount;
    P[temp].balance += depositAmount;   // increase the persons savings by ammount they input
    cout << "Your new balance is " << P[temp].balance << endl;
}

void newCopy(string file, person P[], int numAccounts){ // make a new copy of the file with updated savings
    ofstream data;
    data.open(file);
    for(int i = 0; i < numAccounts; i++){   // loop through struct and input new data
        data << P[i].name << " " << fixed << setprecision(2) << P[i].balance << endl;
    }
    data.close();
}
