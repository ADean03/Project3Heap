#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include<fstream>
#include "maxHeap.h"
using namespace std;

int main() {
	string line;
	string next;
	int test = 0;

	//Video components
	string videoID = "";
	string trendingDate = "";
	string title = "";
	string channel = "";
	string categoryID = "";
	string publishTime = "";
	string tags = "";
	string views = "";
	string likes = "";
	string dislikes = "";
	string commentCount = "";
	string thumbnailLink = "";
	string commentsOn = "";
	string ratingsOn = "";
	string videoError = "";
	string description = "";

	//check for "at certian points (title description and channel) (only non english speaking)

	maxHeap heap;


	ifstream myFile;
	myFile.open("Databases/USvideos.csv");
	getline(myFile, line);
	
	//whatever i < n gets line # n+2 from csv file
	for (int i = 0; i < 0; i++) {
		getline(myFile, line);
	}

	//Reading data from file (English speaking only)
	while (getline(myFile, line)) {
		istringstream in(line);
		//deals with lines randomly not in correct format
		if (line[0] == '\\'){
			continue;
		}
		else if (line.size() < 12) {
			continue;
		}
		else if (line[11] != ',') {
			continue;
		}

		//Video ID (A)
		getline(in, next, ',');
		videoID = next;

		//Trending Date (B)
		getline(in, next, ',');
		trendingDate = next;

		//Title (C)
		getline(in, next, '"');
		getline(in, next, '"');
		title = next;

		//Channel (D)
		getline(in, next, '"');
		getline(in, next, '"');
		channel = next;
		
		//Category ID (E)
		getline(in, next, ',');
		getline(in, next, ',');
		categoryID = next;

		//Publish Time (F)
		getline(in, next, ',');
		publishTime = next;

		//Tags (G)
		getline(in, next, ',');
		tags = next;

		//Views (H)
		getline(in, next, ',');
		views = next;

		//Likes (I)
		getline(in, next, ',');
		likes = next;

		//dislikes (J)
		getline(in, next, ',');
		dislikes = next;

		//Comment Count (K)
		getline(in, next, ',');
		commentCount = next;

		//Thumbnail link (L)
		getline(in, next, ',');
		thumbnailLink = next;

		//Comments On (M)
		getline(in, next, ',');
		commentsOn = next;

		//Ratings on (n)
		getline(in, next, ',');
		ratingsOn = next;

		//Video error (O)
		getline(in, next, ',');
		videoError = next;

		//Description (P)
		getline(in, next);
		description = next;

		//cout << "a " << videoID << endl;
		//cout << "b " << trendingDate << endl;
		//cout << "c " << title << endl;
		//cout << "d " << channel << endl;
		//cout << "e " << categoryID << endl;
		//cout << "f " << publishTime << endl;
		//cout << "g " << tags << endl;
		//cout << "h " << views << endl;
		//cout << "i " << likes << endl;
		//cout << "j " << dislikes << endl;
		//cout << "l " << thumbnailLink << endl;
		//cout << "m " << commentsOn << endl;
		//cout << "n " << ratingsOn << endl;
		//cout << "o " << videoError << endl;
		//cout << "p " << description << endl;

		heap.insert(title, channel, trendingDate, views, likes, dislikes);

		test++;
	}
	
	myFile.close();

	heap.kthLargest(100);
	heap.kthLargest(3);

	//heap.printVideos();

	test = 0; 

	return 0;
}