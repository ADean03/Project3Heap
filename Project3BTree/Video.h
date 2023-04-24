#ifndef VIDEO_H
#define VIDEO_H

#include <string>
using namespace std;

class Video 
{
 public:
    string title;
    int views;

    Video(string title, int views) 
    {
        this->title = title;
        this->views = views;
    }

    ~Video() {}
};

#endif
