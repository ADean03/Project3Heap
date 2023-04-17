#pragma once
#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

struct video {
	string title;
	string channel;
	string date;
	int views;
	int likes;
	int dislikes;


	video(string vidName, string channelName, string trendDate, string viewC, string numLikes, string numDislikes) : title(vidName), channel(channelName), date(trendDate), views(stoi(viewC)), likes(stoi(numLikes)), dislikes(stoi(numDislikes)) {}
};

class maxHeap {

public:
	maxHeap();
	void insert(string title, string channel, string date, string views, string likes, string dislikes);
	void remove();

	void printVideos();
	void kthLargest(int k);

private:
	vector<video> heap;



};

maxHeap::maxHeap() {
	
}

void maxHeap::insert(string title, string channel, string date, string views, string likes, string dislikes) {
	heap.push_back(video(title, channel, date, views, likes, dislikes));
	int child = heap.size() - 1;
	int parent = (child - 1) / 2;

	while (parent >= 0 && heap.at(parent).views <= heap.at(child).views) {
		if (child == 0) {
			break;
		}
		//If same views only swaps if child has more likes than the parent
		if ((heap.at(parent).views == heap.at(child).views) && (heap.at(parent).likes > heap.at(child).likes)) {
			break;
		}
		string tempS;
		int tempI;

		//swap title
		tempS = heap.at(parent).title;
		heap.at(parent).title = heap.at(child).title;
		heap.at(child).title = tempS;

		//swap chanel
		tempS = heap.at(parent).channel;
		heap.at(parent).channel = heap.at(child).channel;
		heap.at(child).channel = tempS;

		//swap date
		tempS = heap.at(parent).date;
		heap.at(parent).date = heap.at(child).date;
		heap.at(child).date = tempS;

		//swap views
		tempI = heap.at(parent).views;
		heap.at(parent).views = heap.at(child).views;
		heap.at(child).views = tempI;

		//swap likes
		tempI = heap.at(parent).likes;
		heap.at(parent).likes = heap.at(child).likes;
		heap.at(child).likes = tempI;

		//swap dislikes
		tempI = heap.at(parent).dislikes;
		heap.at(parent).dislikes = heap.at(child).dislikes;
		heap.at(child).dislikes = tempI;

		//swaps parent and kid index
		child = parent;
		parent = (child - 1) / 2;
	}
}

void maxHeap::remove() {
	if (heap.size() != 0) {
		int parent = 0;
		int child = heap.size() - 1;

		string tempS;
		int tempI;

		//swap title
		tempS = heap.at(parent).title;
		heap.at(parent).title = heap.at(child).title;
		heap.at(child).title = tempS;

		//swap chanel
		tempS = heap.at(parent).channel;
		heap.at(parent).channel = heap.at(child).channel;
		heap.at(child).channel = tempS;

		//swap date
		tempS = heap.at(parent).date;
		heap.at(parent).date = heap.at(child).date;
		heap.at(child).date = tempS;

		//swap views
		tempI = heap.at(parent).views;
		heap.at(parent).views = heap.at(child).views;
		heap.at(child).views = tempI;

		//swap likes
		tempI = heap.at(parent).likes;
		heap.at(parent).likes = heap.at(child).likes;
		heap.at(child).likes = tempI;

		//swap dislikes
		tempI = heap.at(parent).dislikes;
		heap.at(parent).dislikes = heap.at(child).dislikes;
		heap.at(child).dislikes = tempI;

		heap.pop_back();

		int greatest = parent;
		while (parent < heap.size()) {
			int leftI = parent * 2 + 1;
			int rightI = parent * 2 + 2;
			//case 1 both children exist
			if ((leftI < heap.size()) && (rightI < heap.size())) {
				//finding greatest
				if (heap.at(leftI).views > heap.at(parent).views) {
					greatest = leftI;
				}
				if (heap.at(rightI).views > heap.at(greatest).views) {
					greatest = rightI;
				}
				//checks to continue
				if (greatest == parent) {
					break;
				}
				//swaps
				else {

					//swap title
					tempS = heap.at(parent).title;
					heap.at(parent).title = heap.at(greatest).title;
					heap.at(greatest).title = tempS;

					//swap chanel
					tempS = heap.at(parent).channel;
					heap.at(parent).channel = heap.at(greatest).channel;
					heap.at(greatest).channel = tempS;

					//swap date
					tempS = heap.at(parent).date;
					heap.at(parent).date = heap.at(greatest).date;
					heap.at(greatest).date = tempS;

					//swap views
					tempI = heap.at(parent).views;
					heap.at(parent).views = heap.at(greatest).views;
					heap.at(greatest).views = tempI;

					//swap likes
					tempI = heap.at(parent).likes;
					heap.at(parent).likes = heap.at(greatest).likes;
					heap.at(greatest).likes = tempI;

					//swap dislikes
					tempI = heap.at(parent).dislikes;
					heap.at(parent).dislikes = heap.at(greatest).dislikes;
					heap.at(greatest).dislikes = tempI;

					parent = greatest;
				}
			}
			//case 2 only left
			else if (leftI < heap.size()) {
				if (heap.at(parent).views > heap.at(leftI).views) {
					break;
				}
				else {
					child = leftI;

					//swap title
					tempS = heap.at(parent).title;
					heap.at(parent).title = heap.at(child).title;
					heap.at(child).title = tempS;

					//swap chanel
					tempS = heap.at(parent).channel;
					heap.at(parent).channel = heap.at(child).channel;
					heap.at(child).channel = tempS;

					//swap date
					tempS = heap.at(parent).date;
					heap.at(parent).date = heap.at(child).date;
					heap.at(child).date = tempS;

					//swap views
					tempI = heap.at(parent).views;
					heap.at(parent).views = heap.at(child).views;
					heap.at(child).views = tempI;

					//swap likes
					tempI = heap.at(parent).likes;
					heap.at(parent).likes = heap.at(child).likes;
					heap.at(child).likes = tempI;

					//swap dislikes
					tempI = heap.at(parent).dislikes;
					heap.at(parent).dislikes = heap.at(child).dislikes;
					heap.at(child).dislikes = tempI;

					parent = leftI;
				}
			}
			//case 3 right only
			else if (rightI < heap.size()) {
				if (heap.at(parent).views > heap.at(rightI).views) {
					break;
				}
				else {
					child = rightI;

					//swap title
					tempS = heap.at(parent).title;
					heap.at(parent).title = heap.at(child).title;
					heap.at(child).title = tempS;

					//swap chanel
					tempS = heap.at(parent).channel;
					heap.at(parent).channel = heap.at(child).channel;
					heap.at(child).channel = tempS;

					//swap date
					tempS = heap.at(parent).date;
					heap.at(parent).date = heap.at(child).date;
					heap.at(child).date = tempS;

					//swap views
					tempI = heap.at(parent).views;
					heap.at(parent).views = heap.at(child).views;
					heap.at(child).views = tempI;

					//swap likes
					tempI = heap.at(parent).likes;
					heap.at(parent).likes = heap.at(child).likes;
					heap.at(child).likes = tempI;

					//swap dislikes
					tempI = heap.at(parent).dislikes;
					heap.at(parent).dislikes = heap.at(child).dislikes;
					heap.at(child).dislikes = tempI;

					parent = rightI;
				}
			}
			//case 4 no kids
			else {
			break;
			}
		}

	}
}

void maxHeap::printVideos() {
	for (int i = 0; i < heap.size(); i++) {
		cout << "The title is: " << heap.at(i).title << endl;
		cout << "The channel is: " << heap.at(i).channel << endl;
		cout << "The date is: " << heap.at(i).date << endl;
		cout << "The views are: " << heap.at(i).views << endl;
		cout << "The likes are: " << heap.at(i).likes << endl;
		cout << "The dislikes are: " << heap.at(i).dislikes << endl;
		cout << " " << endl;

	}
}

void maxHeap::kthLargest(int k) {
	vector<video> temp;

	for (int i = 1; i < k; i++) {
		if (k > heap.size()) {
			break;
		}
		temp.push_back(heap.at(i));
		remove();
	}
	cout << k << "th largest" << endl;
	cout << "The title is: " << heap.at(0).title << endl;
	cout << "The channel is: " << heap.at(0).channel << endl;
	cout << "The date is: " << heap.at(0).date << endl;
	cout << "The views are: " << heap.at(0).views << endl;
	cout << "The likes are: " << heap.at(0).likes << endl;
	cout << "The dislikes are: " << heap.at(0).dislikes << endl;

	for (int i = 0; i < temp.size(); i++) {
		insert(temp.at(i).title, temp.at(i).channel, temp.at(i).date, to_string(temp.at(i).views), to_string(temp.at(i).likes), to_string(temp.at(i).dislikes));
		temp.erase(temp.begin() + i);
	}

}