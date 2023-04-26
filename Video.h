#ifndef VIDEO_H
#define VIDEO_H

#include <string>
using namespace std;

class Video
{
public:
    string title;
    int views;
    string channel;
    string date;
    string likes;
    string dislikes;

    Video(string title, int views, string channel, string date, string likes, string dislikes)
    {
        this->title = title;
        this->views = views;
        this->channel = channel;
        this->date = date;
        this->likes = likes;
        this->dislikes = dislikes;
    }

    ~Video() {}
};

#endif