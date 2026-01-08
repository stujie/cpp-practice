/* 
Name: Stutie Banerjie
Date: 11/26/2025
Class: CSC 134-N801: C++ Programming
Assignment: Service Desk - Programming Exam Review 3
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip> 
using namespace std;

// function prototypes
int mainMenuChoice();							// prototype for mainMenuChoice() function
string generatePriority();						// prototype for generatePriority() function
int generateServiceTime();						// prototype for generateServiceTime() function
void serviceDeskStats(string[], int[], int);	// prototype for serviceDeskStats() function

// main function
int main()
{
	// use srand to seed random numbers
	srand(time(0));
	
	// constant
	const int NUM_OF_REQUESTS = 100;
	
	// variables
	int menuChoice;		// variable holds the menu choice 
	
	// requests menu input till user chooses to exit
	do
	{
		// call function to determine menu choice
		menuChoice = mainMenuChoice();
		
		if(menuChoice == 1)
		{
			string priorities[NUM_OF_REQUESTS];		// array to hold the priority level for each service request
			int serviceTimes[NUM_OF_REQUESTS];		// array to hold the service request times of each service request
			
			// populate arrays for each service request
			for (int i = 0; i < NUM_OF_REQUESTS; i++)
			{
				// call function to generate priority of service request
				priorities[i] = generatePriority();	
				// call function to generate service time of service request
				serviceTimes[i] = generateServiceTime();
			}
			
			// call the serviceDeskStats() function
			serviceDeskStats(priorities, serviceTimes, NUM_OF_REQUESTS);
		}
		else
		{
			cout << endl << endl << "Program will Exit.";
		}
		
	} while(menuChoice == 1);
	
}

/* 
	mainMenuChoice () funciton
	display menu and obtain user's decision on whether to run simulation or exit
	validate 
*/
int mainMenuChoice()
{
	int choice;		// local variable to hold the user's menu choice
	
	// get the user's menu choice
	cout << "******Welcome to the Service Desk Simulator ******" << endl;
	cout << "Choose from one of the following options:" << endl
		 << setw(45) << "1. Process 100 Service Desk Requests" << endl
		 << setw(16) << "2. Exit" << endl
	   	 << "Enter your choice (1 or 2): ";
	cin >> choice;
	
	// validate the input of the user choice decision
	while (choice < 1 or choice > 2)
	{
		// display an error and get another input
		cout << endl << endl << "ERROR: INVALID MENU CHOICE" << endl << endl;
		cout << "Choose from one of the following options:" << endl
		 << setw(45) << "1. Process 100 Service Desk Requests" << endl
		 << setw(16) << "2. Exit" << endl
	   	 << "Enter your choice (1 or 2): ";
		cin >> choice;
	}
	
	// return the user's menu choice
	return choice;	 
}

/* 
	generatePriority() function
	generates a priority level for each service request
	priority levels can be 1 of 3 options: high, medium, or low
*/
string generatePriority()
{
	int priority; 			// local variable to hold generated priority level of service request
	string priorityLevel;	// local variable to hold generated priority level of service request as a string
	
	// generate random priority level
	priority = 1 + rand() % 3; 
	
	// conditional to assign string value to integer representing priority level
	if (priority == 1)
		priorityLevel = "high";
	else if (priority == 2)
		priorityLevel = "medium";
	else
		priorityLevel = "low";
		
	// return priority level as a string
	return priorityLevel;
}

/* 
	generateServiceTime() function
	generates a service time for each service request
	service times can be 5-8 minutes long
*/
int generateServiceTime()
{
	int time;	// local variable to hold generated service time of service request
	
	// generate random service time between 5 and 8 minutes
	time = 5 + rand() % 4;
	
	// return service time
	return time;
}

/*
	serviceDeskStats() function
	function displays a list of all of the service requests in the simulation
	also displays total amount of requests within each priority level 
	along with the average service time within each priority level
*/
void serviceDeskStats(string priorities[], int times[], int numOfRequests)
{
	// local variables
	int highPriority = 0, mediumPriority = 0, lowPriority = 0;			// local variables counts total requests in each priority level
	int highTotalTime = 0, mediumTotalTime = 0, lowTotalTime = 0;		// local variables adds up total time spent on all requests under each priority level
	double highAvgTime = 0.0, mediumAvgTime = 0.0, lowAvgTime = 0.0;	// local variables that hold calculated avg time spent on requests under each priority level
	
	// display summary title & column headers
	cout << endl << endl << setw(29) << "-Service Line Stats-" << endl << endl;
	cout << setw(9) << "Request #" << setw(24) << right << "Priority" << setw(19) << "Service Time" << endl;
	
	// loop that counts total request in each priority 
	// also calculates total time of requests in each priority category
	// also displays information for each service desk request
	for ( int i = 0; i < numOfRequests; i++)
	{
		if (priorities[i] == "high")
		{
			highPriority++;
			highTotalTime += times[i];
		}
		else if (priorities[i] == "medium")
		{
			mediumPriority++;
			mediumTotalTime += times[i];
		}
		else // priorities[i] == "low"
		{
			lowPriority++;
			lowTotalTime += times[i];
		}
		
		// displays information for each service request
		// information includes service request #, priority level, and service time taken
		cout << setw(17) << "Service Request #" << setw(7) << left << (i + 1) 
			 << setw(6) << left << priorities[i] 
			 << setw(11) << right << times[i] << " minutes" << endl;
	}
	
	// calculate time averages for each priority level
	highAvgTime = (double) highTotalTime / (double) highPriority;
	mediumAvgTime = (double) mediumTotalTime / (double) mediumPriority;
	lowAvgTime = (double) lowTotalTime / (double) lowPriority;
	
	// display stat summary
	// includes total requests per priority level and avg service time of each priority level
	cout << setprecision(2) << showpoint << fixed;
	cout << endl << "Stats:" << endl;
	cout << setw(43) << "Total # of High Priority Requests: " << highPriority << endl;
	cout << setw(60) << "Average service time of the High Priority Requests: " << highAvgTime << " minutes" << endl << endl;
	cout << setw(45) << "Total # of Medium Priority Requests: " << mediumPriority << endl;
	cout << setw(62) << "Average service time of the Medium Priority Requests: " << mediumAvgTime << " minutes" << endl << endl;
	cout << setw(42) << "Total # of Low Priority Requests: " << lowPriority << endl;
	cout << setw(59) << "Average service time of the Low Priority Requests: " << lowAvgTime << " minutes" << endl << endl;
}

/* Personal Notes
> Timing: Finished 15 min early
> Review: Randomly Generated Integers, do-while loops
*/
