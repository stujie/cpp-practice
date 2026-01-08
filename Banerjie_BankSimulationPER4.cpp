/* 
Name: Stutie Banerjie
Date: 11/29/2025
Class: CSC 134-N801: C++ Programming
Assignment: Bank Simulation - Programming Exam Review 4
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip> 
using namespace std;

// function prototypes
int getNumAccounts();						// prototype for getNumAccounts() function
string generateTransactionType();			// prototype for generateTransactionType() function
long generateTransactionAmount();			// prototype for genereateTransactionAmount() function
void displayStats(string[], long[], int);	// prototype for displayStats() function

// main function
int main()
{
	// use srand to seed random numbers
	srand(time(0));
	
	// variables
	int numAccounts;
	
	// call getNumAccounts() function to specify # of bank accounts to be evaluated
	numAccounts = getNumAccounts();
	
	// array declarations
	string transactionTypes[numAccounts];		// array to hold the transaction type for each account
	long transactionAmounts[numAccounts];		// array to hold the transaction amount for each account
	
	// loop to populate arrays
	// for each bank account, randomly generate a transaction type and transaction amount
	for(int i = 0; i < numAccounts; i++)
	{
		transactionTypes[i] = generateTransactionType();
		transactionAmounts[i] = generateTransactionAmount();
	}
	
	// call the displayStats() function
	displayStats(transactionTypes, transactionAmounts, numAccounts);
}

/*
	getNumAccounts() function
	allows the user to specify the # of bank accounts to be evaluates in simulation
	validation assures integer is between 5 and 100
*/
int getNumAccounts()
{
	int numberOfAccounts; 	// local variable to hold # of accounts to be evaluated
	
	// prompt user to enter account #
	cout << "Enter the number of accounts to be evaluated (min 5 - max: 100): ";
	cin >> numberOfAccounts;
	
	// validate the user input
	while(numberOfAccounts < 5 or numberOfAccounts > 100)
	{
		// display and error and get another input value
		cout << endl <<  "ERROR: INVALID NUMBER OF ACCOUNTS ENTERED. TRY AGAIN." << endl << endl;
		cout << "Enter the number of accounts to be evaluated (min 5 - max: 100): ";
		cin >> numberOfAccounts;
	}
	
	// return # of accounts to be evaluated
	return numberOfAccounts;	
}


/* 
	generateTransactionType() function
	generates a random transaction type for each bank account
	2 transaction types: deposit or withdrawal
*/
string generateTransactionType()
{
	int transactionType = 1 + rand() % 2;	// local variable to hold which transaction type is generated
	
	if (transactionType == 1)
		return "deposit";
	else // (transactionType == 2)
		return "withdrawal";
}


/* 
	generateTransactionAmount() function
	generates a trandom transaction amount for each bank account
	amounts range from $5 to $10,000
*/
long generateTransactionAmount()
{
	return (5 + rand() % 9996);	
}

/* 
	displayStats() function
	function displays transaction number, type, and amount for each bank account 
	in the simulation
	shows stats that display total amount, counters, and avg amounts for all transactions,
	deposit transactions, and withdrawal transactions
*/
void displayStats(string transactionTypes[], long transactionAmounts[], int numAccounts)
{
	// local variables
	int withdrawalCounter = 0, depositCounter = 0, totalCounter = 0;
	double totalWithdrawalAmount = 0.0, totalDepositAmount = 0.0, totalAmount = 0.0;
	double avgWithdrawalAmount = 0.0, avgDepositAmount = 0.0, avgTotalAmount = 0.0;
	
	cout << endl; 
	
	for (int i = 0; i < numAccounts; i++)
	{
		// count the number of transactions and calculate the sum of money transacted 
		// in each transaction type
		if (transactionTypes[i] == "deposit")
		{
			depositCounter++;
			totalDepositAmount += transactionAmounts[i];
		}
		else // (transactionTypes[i] == "withdrawal")
		{
			withdrawalCounter++;
			totalWithdrawalAmount += transactionAmounts[i];
		}
		
		// display stats for simulated bank account evaluations
		cout << "Transaction #" << setw(3) << left << i << " Type: " << setw(10) << left
			 << transactionTypes[i] << setw(17) << right << "Amount: $" 
			 << left << transactionAmounts[i] << endl;
	}
	
	// calculate total transaction
	totalCounter = withdrawalCounter + depositCounter; 
	
	// calculate total amount transaction
	totalAmount = totalWithdrawalAmount + totalDepositAmount; 
	
	// calculate average deposit, withdrawal, and total amounts
	avgDepositAmount = totalDepositAmount / (double) depositCounter;
	avgWithdrawalAmount = totalWithdrawalAmount / (double) withdrawalCounter;
	avgTotalAmount = totalAmount / (double) totalCounter;
	
	// set point precision
	cout << setprecision(2) << showpoint << fixed;
	
	cout << endl;
	
	// display summary statistics
	cout << endl << "Stats:" << endl;
	cout << "Total Transactions: " << totalCounter << endl;
	cout << "Total Deposits: " << depositCounter << endl;
	cout << "Total Withdrawals: " << withdrawalCounter << endl << endl;
	
	cout << "Avg Amount Per Deposit: $" << avgDepositAmount << endl;
	cout << "Avg Amount Per Withdrawal: $" << avgWithdrawalAmount << endl;
	cout << "Avg Amount Per Transaction: $" << avgTotalAmount << endl << endl;
	
	cout << "Total Amount of Deposits: $" << totalDepositAmount << endl;
	cout << "Total Amonut of Withdrawals: $" << totalWithdrawalAmount << endl;
	cout << "Total Amount Transacted: $" << totalAmount;
}

/* Personal Notes
> Timing: Finished 55 minutes early
> Review: setw() formatting vs tabs
*/
