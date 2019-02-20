CPSC301 - Assignment 1

1. Create the following “data.txt”  file. Each record consists of customer's name and their balance:
 
Maria  Brown  2100.90
Jeffrey  Jackson  200.20
Bernard  Smith  223.10
Matthew  Davenport  1630.20
Kimberly Macias  19100.90
Amber  Daniels  2400.40

The records in the file will be like the text above. You will store them in the struct provided below:

struct  PERSON {
    char  Name[20];
    float Balance; }; 

i. We don’t know exactly how many records are in the file. You will have to go through the file a first time and count the number of records (N).

ii . Once you have this information, you can create an array that is large enough to hold all of the records in the file PERSON P[N];

iii. Remember that c_strings or character arrays must be null terminated, so you will either need to set every element to ‘/0’ before writing the name, or make sure you put one after you have written the name.

iv. Display all records in array a. Use calling statement: Display(a, N);
Your output should look like the following:
                	Name           	  Balance
         -----------------------------------------------
Maria  Brown  2100.90
Jeffrey  Jackson  200.20 
Bernard  Smith  223.10
Matthew  Davenport  1630.20
Kimberly Macias  19100.90
Amber  Daniels  2400.40
 
v. Display the name of customer with maximum balance. Call function FindRichest(a, N);
   	Output:  	
The customer with maximum balance is Kimberly Macias
vi. Allow a customer to deposit money in his/her account. Call function :
 Deposit(CustName, a, N); where CustName is the name of the customer who wants to deposit money
    	Output: 
Enter your full name to deposit money: Maria  Brown
        	            Maria Brown, how much would you like to deposit?  100
Now your new balance is 2200.90
 
Vii. Copy array a in the same file. Use calling statement NewCopy(“data.txt”, a, N);
(turn in a copy of the file with the new updated records)
