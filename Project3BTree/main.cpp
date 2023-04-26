#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include "BTree.h"
#include "Video.h"
using namespace std;

///////////////////////////////////////////////////////////////

int main() {

    vector<Video> videos;

    // Read videos from csv file
    ifstream myFile;
    myFile.open("Databases/USvideos.csv");
    string line;
    getline(myFile, line); // Skip header line

    while (getline(myFile, line)) {
        istringstream in(line);
        string videoID, trendingDate, title, channel, categoryID, publishTime, tags, thumbnailLink, commentsOn, ratingsOn, videoError, description;
        int views, likes, dislikes, commentCount;

        // parse line
        getline(in, videoID, ',');
        getline(in, trendingDate, ',');
        getline(in, title, ',');
        getline(in, channel, ',');
        getline(in, categoryID, ',');
        getline(in, publishTime, ',');
        getline(in, tags, ',');
        in >> views >> likes >> dislikes >> commentCount;
        getline(in, thumbnailLink, ',');
        getline(in, commentsOn, ',');
        getline(in, ratingsOn, ',');
        getline(in, videoError, ',');
        getline(in, description);

        // Only add videos that are in English
        if (videoError.empty() && title.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890!@#$%^&*()_+[]\\{}|;':\",./<>?`~-=_") == string::npos &&
            channel.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890!@#$%^&*()_+[]\\{}|;':\",./<>?`~-=_") == string::npos &&
            description.find_first_not_of("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ01234567890!@#$%^&*()_+[]\\{}|;':\",./<>?`~-=_") == string::npos) {

            videos.push_back(Video(title, views));
        }
    }

    myFile.close();

    BTree bTree(3); // create a new BTree with minimum degree 3

    for (auto &video : videos) {
        bTree.insert(video); // insert video into BTree
    }

    //bTree.traverse(); // print the contents of the BTree

    vector<Video> largest = bTree.findklargest(3);
    for (int i = 0; i < largest.size(); i++) {
        cout << largest[i].title << " - " << largest[i].views << endl;
    }
    return 0;
}
