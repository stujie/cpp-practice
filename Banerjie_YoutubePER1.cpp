/* 
Name: Stutie Banerjie
Date: 11/26/2025
Class: CSC 134-N801: C++ Programming
Assignment: Youtube Videos - Programming Exam Review 1
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip> 
using namespace std;

// function prototypes
int getNumVideos();

long long generateViews();
long long generateLikes(long long views);
double calculateLikePct(long long views, long long likes);

void displayStats(int videos, long long views[], long long likes[], double percentages[]);

void maxViews(int videos, long long views[]);
void minViews(int videos, long long views[]);
void maxLikes(int videos, long long likes[]);
void minLikes(int videos, long long likes[]);

// main function
int main()
{
	// seed random numbers at time(0) to ensure different values can be generated
	srand(time(0));
	
	// declare variables
	int numOfVideos;  
	
	// decide # of videos
	numOfVideos = getNumVideos();
	
	// initialize  arrays
	long long views[numOfVideos];
	long long likes[numOfVideos];
	double likePercentages[numOfVideos];
	
	// format output to show two decimal places using setprecision()
	cout << setprecision(2) << showpoint << fixed;
	
	// populate arrays - randomly generate views, likes, percentages
	for (int vid = 0; vid <= numOfVideos-1; vid++)
	{
		views[vid] = generateViews();
		likes[vid] = generateLikes(views[vid]);
		likePercentages[vid] = calculateLikePct(views[vid], likes[vid]);
	}
	
	// display stats of each video
	displayStats(numOfVideos, views, likes, likePercentages);
	
	// video with most view
	maxViews(numOfVideos, views);
	// video with least views
	minViews(numOfVideos, views);
	// video with most likes
	maxLikes(numOfVideos, likes);
	// video with least likes
	minLikes(numOfVideos, likes);
}

// function 1 - getNumVideos: validates user input & return amount of videos selected from Youtube
int getNumVideos()
{
	int numOfVid; 
	
	cout << "Enter the amount of videos that will be selected from Youtube <min:1 - max: 9>: ";
	cin >> numOfVid;
	
	while (numOfVid < 1 || numOfVid > 9)
	{
		// validate input
		cout << "\nERROR: ENTER BETWEEN 1 AND 9 VIDEOS\n";
		cout << "Enter the amount of videos that will be selected from Youtube <min:1 - max: 9>: ";
		cin >> numOfVid;
	}
	
	return numOfVid;
}

// function 2 - generateViews: randomly generated views count
long long generateViews()
{
	long views; // generated view count
	
	// views  between 1 - 100,000,000,000
	views = 1 + rand() % 100000000000;
	
	return views;
}

// function 3 - generateLikes based on view count
long long generateLikes(long long views)
{
	long likes; // generated like
	
	// likes between 1 - view count
	likes = 1 + rand() % views;
	
	return likes;
}

// function 4 - generate percentage based on views & likes
double calculateLikePct(long long views, long long likes)
{
	double percentage;
	
	// percentage = likes/views
	percentage = (double(likes)/views)*100;
	
	return percentage;
}

// function 5 - display video stats
void displayStats(int videos, long long views[], long long likes[], double percentages[])
{	
	// header
	cout << endl << endl;
	cout << setw(3) << " " << "Video # " << setw(15) << right << "Views" << setw(15) << "Likes" << setw(15) << "Like %" << endl;
	
	// display per video
	for (int vid = 0; vid <= videos-1; vid++)
	{
		cout << setw(3) << " " << "Video #" <<  vid+1 << setw(15) << right << views[vid] << setw(15) << likes[vid] << setw(15) << percentages[vid]<< endl;
	}
	
	// spacing
	cout << endl << endl;
}

// function 6 - video with max views
void maxViews(int videos, long long views[])
{
	int maxVid = 1;
	long long max = views[0];
	
	// determine highest view count
	for (int vid = 1; vid <= videos-1; vid++)
	{
		if(views[vid] > max)
		{
			maxVid = vid+1;
			max = views[vid];
		}
	}
	
	// display
	cout << "Most Viewed Video" << endl;
	cout << setw(3) << " " << "Video #" <<  maxVid << setw(15) << right << max << " views" << endl << endl;
	
	
}

// function 7 - video with min views
void minViews(int videos, long long views[])
{
	int minVid = 1;
	long long min = views[0];
	
	// determine lowest view count
	for (int vid = 1; vid <= videos-1; vid++)
	{
		if(views[vid] < min)
		{
			minVid = vid+1;
			min = views[vid];
		}
	}
	
	// display
	cout << "Least Viewed Video" << endl;
	cout << setw(3) << " " << "Video #" <<  minVid << setw(15) << right << min << " views" << endl << endl;
}

// function 8 - video with max likes
void maxLikes(int videos, long long likes[])
{
	int maxVid = 1;
	long long max = likes[0];
	
	// determine highest like count
	for (int vid = 1; vid <= videos-1; vid++)
	{
		if(likes[vid] > max)
		{
			maxVid = vid+1;
			max = likes[vid];
		}
	}
	
	// display
	cout << "Most Liked Video" << endl;
	cout << setw(3) << " " << "Video #" <<  maxVid << setw(15) << right << max << " likes" << endl << endl;
}

// function 9 - video with min Likes
void minLikes(int videos, long long likes[])
{
	int minVid = 1;
	long long min = likes[0];
	
	// determine highest like count
	for (int vid = 1; vid <= videos-1; vid++)
	{
		if(likes[vid] < min)
		{
			minVid = vid+1;
			min = likes[vid];
		}
	}
	
	// display
	cout << "Least Liked Video" << endl;
	cout << setw(3) << " " << "Video #" <<  minVid << setw(15) << right << min << " likes" << endl;
}

/* Personal Notes
> Timing: Went 8 min over time
> Review: Randomly Generated Integers, Modular Programming(parameters/arguments)
*/
