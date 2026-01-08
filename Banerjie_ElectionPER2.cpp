/* 
Name: Stutie Banerjie
Date: 11/26/2025
Class: CSC 134-N801: C++ Programming
Assignment: Election - Programming Exam Review 2
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip> 
using namespace std;

// function prototypes
int getNumCandidates();
long getNumVoters();
void displayStats(long[], double[], int);
void calcWinner(long[], int);

// int main()
int main()
{
	srand(time(0)); 	// use srand to seed random numbers
	
	// variables
	int candidates; 	// the number of candidates to be entered by the user
	int voters;			// the number of voters to be entered by the user
	
	candidates = getNumCandidates();	// get the input of the number of candidates
	voters = getNumVoters();			// get the input of the number of voters
	
	// arrays to hold voting statistics
	long candidateVotes[candidates];		// hold the votes for each candidate
	double votePercentages[candidates];		// hold the percentages of votes each candidate receives
	
	// initialize candidateVotes[] = 0
	for (int i = 0; i < candidates; i++)
	{
		candidateVotes[i] = 0;
	}
	
	// use a for loop to populate candidate votes array
	// simulate voting - randomize which candidate receives each voter's vote
	for(int i = 0; i < voters; i++)
	{
		int c = rand() % candidates;	// randomly choose which candidate receives vote
		
		candidateVotes[c] += 1; 		// increment candidates votes by 1		
	}
	
	// use a for loop to populate the percentage array
	// candidate percentages = candidate votes / total votes
	for (int i = 0; i < candidates; i++)
	{
		// calculate each percentage of voters
		votePercentages[i] = (double)candidateVotes[i]/(double)voters;
	}
	
	// once the arrays are populated, call function to display the stats
	displayStats(candidateVotes, votePercentages, candidates);
	
	// display the election winner
	calcWinner(candidateVotes, candidates);
}

/*
	getNumCandidates function
	The user must first specify the number of candidates that will be running in the 
	simulated election.
	Validate the user input of the number of candidates so that the number is between 
	2 and 5.
*/
int getNumCandidates()
{
	int candidates;		// local variable that will hold the number of candidates
	
	// get the input of the number of candidates from the user
	cout << "How many candidates are running? <Min: 2 Max: 5>: ";
	cin >> candidates;
	
	// validate the input of the number of candidates
	while(candidates < 2 or candidates > 5)
	{
		// display an error, then get another input of candidates
		cout << endl << "ERROR: Must enter between 2 and 5 candidates." << endl;
		cout << "How many candidates are running? <Min: 2 Max: 5>: ";
		cin >> candidates;
	}
	
	// return the validated number of candidates
	return candidates;
}

/*
	getNumVoters function
	The user must then specify the number of voters who will cast votes in the
	simulated election.
	Validate the user input of the number of voters so that the number is between
	1 and 300,000,000.
*/
long getNumVoters()
{
	int voters;			// local variable that will hold the number of voters
	
	// get the input of the number of voters from the user
	cout << endl << "How many voters are voting? <Min: 1 Max: 300000000>: ";
	cin >> voters;
	
	// validate the input of the number of voters
	while(voters < 1 or voters > 300000000)
	{
		// display an error, then get another input of candidates
		cout << endl << "ERROR: Must enter between 1 and 300000000 voters." << endl;
		cout << "How many voters are voting? <Min: 1 Max: 300000000>: ";
		cin >> voters;		
	}
	
	// return the validated number of voters
	return voters;	
}

/*
	displayStats function
	displays the stats for each video on separate lines
*/
void displayStats(long votes[], double percentages[], int candidates)
{
	// display the column headers
	cout << endl << endl << setw(10) << "Candidate" << setw(16) << "Votes" <<  setw(16) << "% of Votes" << endl;
	
	// for each candidate - display the candidate's votes & percentage of votes
	for (int i = 0; i < candidates; i++)
	{
		cout << setw(11) << "Candidate #" << (i+1) << setw(15) << votes[i] << setw(15) << percentages[i] << endl;
	}
}

/*
	calcWinner function
	displays the candidate who is the winner of the election with the most votes
*/
void calcWinner(long votes[], int candidates)
{
	int maxVotes = votes[0] ; 		// initialize the max votes to the first candidate's votes
	int winner = 1;					// initialize winner to the first candidate
	
	// loop through the rest of the votes array and find the candidate with the most votes
	for (int i = 1; i < candidates; i++)
	{
		// check to see if the current value in the array is greater than the 
		// current highest value in the array
		if(votes[i]>maxVotes)
		{
			maxVotes = votes[i];	// if the current value is greater than the current max
							// that value becomes the new maximum value in the array
			winner = i+1;	// updated the index where that new maximum value was found
		}
	}
	
	cout << endl << endl << "Election Winner" << endl;
	cout << setw(11) << "Candidate #" << winner << setw(15) << maxVotes << " votes";
}

/* Personal Notes
> Timing: Finished 25 min early
> Review: Randomly Generated Integers
*/


