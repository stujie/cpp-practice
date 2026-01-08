/* 
Name: Stutie Banerjie
Date: 11/29/2025
Class: CSC 134-N801: C++ Programming
Assignment: Bank Simulation - Programming Exam Review 4s
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip> 
using namespace std;

// function prototypes
int getNumLoanApplications();
int generateCreditScore();
string generateScoreRating(int);
string generateStatus(int);
void analysis(int[], string[], string[], int);

// main function
int main()
{
	// seed time 
	srand(time(0));
	
	// variables
	int applications;
	
	// call getNumLoanApplications() function
	applications = getNumLoanApplications();
	
	// declare parallel arrays to hold credit scores and score ratings
	int creditScores[applications];		// array that holds the credit score for each loan application
	string scoreRatings[applications];	// array that holds the credit score rating for each loan application
	string loanStatuses[applications];	// array that holds the loan status for each loan application
	
	// use for loop to populate parallel credit score and score ratings arrays
	for (int i = 0; i < applications; i++)
	{
		creditScores[i] = generateCreditScore();	
		scoreRatings[i] = generateScoreRating(creditScores[i]);	
		loanStatuses[i] = generateStatus(creditScores[i]);
	}
	
	// call analysis() function to display all application stats & summary
	analysis(creditScores, scoreRatings, loanStatuses, applications);
}

/* 
	getNumLoanApplications() function
	allow the user to specify the number of loan applications to be evaludated in the simulation
	validation ensures integer input is between 50 and 2000
*/
getNumLoanApplications()
{
	// local variable holds # of loan applications to be simulated
	int applications;
	
	// get user input for application #
	cout << "Enter the number of Loan Applications to be evaluated (min 50 - max: 2000): ";
	cin >> applications;
	
	// validate the input of the number of loan applications
	while(applications < 50 or applications > 2000)
	{
		// display an error, then get another input
		cout << "\nERROR: INVALID NUMBER OF LOAN APPLICATIONS ENTERED. TRY AGAIN. \n\n";
		cout << "Enter the number of Loan Applications to be evaluated (min 50 - max: 2000): ";
		cin >> applications;
	}
	
	// return application amount
	return applications;
}


/* 
	generateCreditScore() function
	randomly generates a credit scores
	credit scores can be between 300 and 900
*/
int generateCreditScore()
{
	return 300 + rand() % 601;
}

/* 
	generateScoreRating() function
	based on generated credit score, generates a score rating
	score rating can be 1 of 5: poor, fair, good, very good, and exceptional
*/
string generateScoreRating(int score)
{
	if (score >= 300 and score <= 579)
		return "poor";
	else if (score >= 580 and score <= 669)
		return "fair";
	else if (score >= 670 and score <= 739)
		return "good";
	else if (score >= 740 and score <= 799)
		return "very good";
	else // (score >= 800 and score <= 900)
		return "exceptional";		
}

/* 
	generateStatus() function
	based on generated credit score, randomly generates a status for loan application
	status can be 1 of 2: approved or denied
*/
string generateStatus(int score)
{
	if(score >= 630)
		return "Approved";
	else // (score < 630)
		return "Declined";
}

/* 
	analysis() function
	display final summary of applications line by line 
	and a statistic summary at the bottom
*/
void analysis(int scores[], string ratings[], string statuses[], int applications)
{
	cout << endl;
	
	// local variables
	int approvedCount = 0, declinedCount = 0;
	int poorCount = 0, fairCount = 0, goodCount = 0, veryGoodCount = 0, exceptionalCount = 0;
	
	// loop to process the data from the arrays and display info about each loan application
	for(int i = 0; i < applications; i++)
	{
		// count approved & declined applications
		if (statuses[i] == "Approved")
		{
			approvedCount++;
		}
		else
		{
			declinedCount++;
		}
		
		// count applications by score ratings
		if (ratings[i] == "poor")
		{
			poorCount++;
		}
		else if (ratings[i] == "fair")
		{
			fairCount++;
		}
		else if (ratings[i] == "good")
		{
			goodCount++;
		}
		else if (ratings[i] == "very good")
		{
			veryGoodCount++;
		}
		else // if (ratings[i] == "exceptional")
		{
			exceptionalCount++;
		}
		
		// display individual application information line by line
		cout << "Application Status: " << statuses[i] << "\tCredit Score: " << scores[i]
			 << "\tScore Rating: " << ratings[i] << endl;
	}
	
	cout << endl;
	
	// display the stats
	cout << "Stats:";
	cout << "\n----------------------------\n";
	cout << "Total Applications:\t" << approvedCount + declinedCount << endl;
	cout << "\t Loans Approved: " << approvedCount << endl;
	cout << "\t Loans Declined: " << declinedCount;
	cout << "\n----------------------------\n";
	cout << "Total Scores By Rating:";
	cout << "\n\t # of Poor Scores (300 - 579): " << poorCount << endl;
	cout << "\t # of Fair Scores (580 - 669): " << fairCount << endl;
	cout << "\t # of Good Scores (670 - 739): " << goodCount << endl;
	cout << "\t # of Very Good Scores (740 - 799): " << veryGoodCount << endl;
	cout << "\t # of Exceptional Scores (800 - 900): " << exceptionalCount;	
} 

/* Personal Notes
> Timing: Finished 65 minutes early
> Review: 
*/
