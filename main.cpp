#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include<fstream>
#include "maxHeap.h"
#include <algorithm>
#include "BTree.h"
#include "Video.h"
//#include "Textbox.h"
using namespace std;


int main()
{
    ////////////////
    string line;
    string next;
    int test = 0;
    int counter = 0;
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
    vector<Video> videos;

    ifstream myFile;
    
    myFile.open("Databases/USvideos.csv"); //
    if (myFile.is_open()) {
    //    cout << "open!";
    }
    
    getline(myFile, line);

    //whatever i < n gets line # n+2 from csv file
    for (int i = 0; i < 0; i++) {
        getline(myFile, line);
    }
   
    //Reading data from file (English speaking only)
    while (getline(myFile, line)) {
        istringstream in(line);
        //deals with lines randomly not in correct format
        if (line[0] == '\\') {
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

        
                    videos.push_back(Video(title, stoi(views), channel, trendingDate, likes, dislikes));
                    heap.insert(title, channel, trendingDate, views, likes, dislikes);
                    
           
        
        test++;
    }

    myFile.close();

    

    //heap.printVideos();

    test = 0;

    BTree bTree(3); // create a new BTree with minimum degree 3

    for (auto& video : videos) {
        bTree.insert(video); // insert video into BTree
    }

    bTree.traverse(); // print the contents of the BTree


    ////////////////////////


    /// <summary>
    /// ////////////////
    /// </summary>
    /// <returns></returns>
    sf::RenderWindow window(sf::VideoMode(1200, 700), "Project 3");
    string playerInput;
    sf::Texture t;
    t.loadFromFile("../highressmokelarge.jpg");
    sf::Vector2f targetSize(1200.0f, 700.0f);
    sf::Sprite background;
    background.setTexture(t);
    background.setScale(
        targetSize.x / background.getLocalBounds().width,
        targetSize.y / background.getLocalBounds().height);
    
    
    //
    sf::Texture buttonSprite;
    buttonSprite.loadFromFile("../buttonSpritev3.png");
    sf::Sprite spriteButton;
    spriteButton.setTexture(buttonSprite);
   // sf::RectangleShape button(sf::Vector2f(150, 30));
    spriteButton.setPosition(30, 100);
    spriteButton.setColor(sf::Color::Red);
    spriteButton.setScale(0.75, 0.75);
    //
  //  button.setFillColor(sf::Color::Red);
    

    sf::Sprite button1;
    button1.setTexture(buttonSprite);
    // sf::RectangleShape button(sf::Vector2f(150, 30));
    button1.setPosition(30, 140);
    button1.setColor(sf::Color::Red);
    button1.setScale(0.75, 0.75);
    //
    
    sf::Sprite button2;
    button2.setTexture(buttonSprite);
    // sf::RectangleShape button(sf::Vector2f(150, 30));
    button2.setPosition(30, 180);
    button2.setColor(sf::Color::Red);
    button2.setScale(0.75, 0.75);
    
    //

    sf::Font font;
    sf::Text playerText("", font, 24);
    playerText.setStyle(sf::Text::Bold);
   
    sf::Text playerText2("", font, 24);
    playerText2.setStyle(sf::Text::Bold);
   // sf::Font font;
    if (!font.loadFromFile("../Roboto-Light.ttf")) {
       return EXIT_FAILURE;
    }

    sf::Font font2;
    if (!font2.loadFromFile("../Roboto-Bold.ttf")) {
        return EXIT_FAILURE;
    }
    sf::Text HeapText;
    HeapText.setFont(font2);
    HeapText.setString("Max Heap:");
    HeapText.setCharacterSize(30);
    HeapText.setPosition(35, 50);
    HeapText.setFillColor(sf::Color::White);
    HeapText.setStyle(sf::Text::Underlined);

    sf::Text BTText;
    BTText.setFont(font2);
    BTText.setString("B Tree:");
    BTText.setCharacterSize(30);
    BTText.setPosition(35, 250);
    BTText.setFillColor(sf::Color::White);
    BTText.setStyle(sf::Text::Underlined);

    //buttonText is insert
    sf::Text buttonText;
    buttonText.setFont(font);
    buttonText.setString("Insert");
    buttonText.setCharacterSize(24);
    buttonText.setPosition(35, 100);
    buttonText.setFillColor(sf::Color::White);
    buttonText.setStyle(sf::Text::Bold);
    //
    //removeText is insert
    sf::Text removeText;
    removeText.setFont(font);
    removeText.setString("Remove");
    removeText.setCharacterSize(24);
    removeText.setPosition(35, 140);
    removeText.setFillColor(sf::Color::White);
    removeText.setStyle(sf::Text::Bold);
    //
    //printText is insert

    //
    //kthText is insert
    sf::Text kthText;
    sf::Text thText;
    kthText.setFont(font);
    thText.setFont(font);
    kthText.setString("K  Largest");
    thText.setString("th");
    kthText.setCharacterSize(24);
    thText.setCharacterSize(10);
    kthText.setPosition(35, 180);
    thText.setPosition(50, 185);
    kthText.setFillColor(sf::Color::White);
    thText.setFillColor(sf::Color::White);
    kthText.setStyle(sf::Text::Bold);
    thText.setStyle(sf::Text::Bold);
    //
    /////////////////////
    //BTREE
    sf::Sprite button4;
    button4.setTexture(buttonSprite);
    // sf::RectangleShape button(sf::Vector2f(150, 30));
    button4.setPosition(30, 300);
    button4.setColor(sf::Color::Red);
    button4.setScale(0.75, 0.75);
    //
  //  button.setFillColor(sf::Color::Red);

    sf::Sprite button5;
    button5.setTexture(buttonSprite);
    // sf::RectangleShape button(sf::Vector2f(150, 30));
    button5.setPosition(30, 340);
    button5.setColor(sf::Color::Red);
    button5.setScale(0.75, 0.75);
    //

    sf::Sprite button6;
    button6.setTexture(buttonSprite);
    // sf::RectangleShape button(sf::Vector2f(150, 30));
    button6.setPosition(30, 380);
    button6.setColor(sf::Color::Red);
    button6.setScale(0.75, 0.75);

  
    //buttonText is insert
    sf::Text BTreeIn;
    BTreeIn.setFont(font);
    BTreeIn.setString("Insert");
    BTreeIn.setCharacterSize(24);
    BTreeIn.setPosition(35, 300);
    BTreeIn.setFillColor(sf::Color::White);
    BTreeIn.setStyle(sf::Text::Bold);
    //
    //removeText is insert
    sf::Text BTreeRe;
    BTreeRe.setFont(font);
    BTreeRe.setString("Search");
    BTreeRe.setCharacterSize(24);
    BTreeRe.setPosition(35, 340);
    BTreeRe.setFillColor(sf::Color::White);
    BTreeRe.setStyle(sf::Text::Bold);
    //
    //printText is insert
   /* sf::Text BTreePrint;
    BTreePrint.setFont(font);
    BTreePrint.setString("Print Videos");
    BTreePrint.setCharacterSize(24);
    BTreePrint.setPosition(35, 380);
    BTreePrint.setFillColor(sf::Color::White);
    BTreePrint.setStyle(sf::Text::Bold);*/
    //
    //kthText is insert
    sf::Text BTreekthText;
    sf::Text BTreethText;
    BTreekthText.setFont(font);
    BTreethText.setFont(font);
    BTreekthText.setString("K  Smallest");
    BTreethText.setString("th");
    BTreekthText.setCharacterSize(24);
    BTreethText.setCharacterSize(10);
    BTreekthText.setPosition(35, 380);
    BTreethText.setPosition(50, 385);
    BTreekthText.setFillColor(sf::Color::White);
    BTreethText.setFillColor(sf::Color::White);
    BTreekthText.setStyle(sf::Text::Bold);
    BTreethText.setStyle(sf::Text::Bold);



    std::vector<sf::Text> textOutput;

    sf::Text inputPrompt;
    inputPrompt.setFont(font);
    inputPrompt.setString("Enter video: ");
    inputPrompt.setCharacterSize(24);
    inputPrompt.setPosition(190, 100);
    inputPrompt.setFillColor(sf::Color::White);
    inputPrompt.setStyle(sf::Text::Bold);

    std::vector<sf::Text> textOutput2;

    sf::Text inputPrompt2;
    inputPrompt2.setFont(font);
    inputPrompt2.setString("Enter k: ");
    inputPrompt2.setCharacterSize(24);
    inputPrompt2.setPosition(190, 180);
    inputPrompt2.setFillColor(sf::Color::White);
    inputPrompt2.setStyle(sf::Text::Bold);

    std::vector<sf::Text> textOutput3;

    sf::Text inputPrompt3;
    inputPrompt3.setFont(font);
    inputPrompt3.setString("Enter video: ");
    inputPrompt3.setCharacterSize(24);
    inputPrompt3.setPosition(190, 300);
    inputPrompt3.setFillColor(sf::Color::White);
    inputPrompt3.setStyle(sf::Text::Bold);

    std::vector<sf::Text> textOutput4;

    sf::Text inputPrompt4;
    inputPrompt4.setFont(font);
    inputPrompt4.setString("Enter k: ");
    inputPrompt4.setCharacterSize(24);
    inputPrompt4.setPosition(190, 380);
    inputPrompt4.setFillColor(sf::Color::White);
    inputPrompt4.setStyle(sf::Text::Bold);

    std::vector<sf::Text> textOutput5;

    sf::Text inputPrompt5;
    inputPrompt5.setFont(font);
    inputPrompt5.setString("Search: ");
    inputPrompt5.setCharacterSize(24);
    inputPrompt5.setPosition(190, 340);
    inputPrompt5.setFillColor(sf::Color::White);
    inputPrompt5.setStyle(sf::Text::Bold);

    sf::Text outPutHTreeK;
    outPutHTreeK.setFont(font);
    outPutHTreeK.setString("");
    outPutHTreeK.setCharacterSize(24);
    outPutHTreeK.setPosition(400, 50);
    outPutHTreeK.setFillColor(sf::Color::White);
    outPutHTreeK.setStyle(sf::Text::Bold);

    sf::Text outPutBTK;
    outPutHTreeK.setFont(font);
    outPutHTreeK.setString("");
    outPutHTreeK.setCharacterSize(24);
    outPutHTreeK.setPosition(400, 50);
    outPutHTreeK.setFillColor(sf::Color::White);
    outPutHTreeK.setStyle(sf::Text::Bold);

    sf::Text success;
    success.setFont(font);
    success.setString("");
    success.setCharacterSize(24);
    success.setPosition(400, 10);
    success.setFillColor(sf::Color::Transparent);
    success.setStyle(sf::Text::Bold);



    ///////////////
    string tempKHeap;
      sf::CircleShape shape(100.f);
      shape.setFillColor(sf::Color::Green);
      // ...
  //    std::stringstream ss;
 //     ss << 12;
  //    sf::Text.setString(ss.str());
      int countSpriteButt = 0;
      int countButt1 = 0;
      int countButt2 = 0;
      int countButt4 = 0;
      int countButt5 = 0;
      int countButt6 = 0;
      string kthHeap = "0";
      string kthBT = "0";
      int removeCountMaxHeap = 0;
      int removeCountBT = 0;
      string maxHeaptitle;
      string maxHeapchannel;
      string maxHeapdate;
      string maxHeapviews; 
      string maxHeaplikes;
      string maxHeapdislikes;
      string temp;
      

      string BTreetitle;
      string BTreechannel;
      string BTreedate;
      string BTreeviews;
      string BTreelikes;
      string BTreedislikes;
      string temp2;
      string searchFunc;
      int searchFuncTimes = 0;

      int timesKPrint = 0;

      while (window.isOpen())
      {
          
          sf::Event event;
          while (window.pollEvent(event))
          {
              if (event.type == sf::Event::Closed) {
                  window.close();
              }
              
              else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                  sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                  sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                  if (spriteButton.getGlobalBounds().contains(mousePosF)) {
                      //button is clicked, do something 
                      //insert function actions
                      if (countSpriteButt % 2 == 0) {
                          countSpriteButt++;
                          spriteButton.setColor(sf::Color::White);
                          //textOutput.push_back(inputPrompt);
                          ///
                          temp = ("");
                          std::cout << "Enter Title: ";
                          std::cin >> maxHeaptitle;
                          std::cout << "Enter Channel: ";
                          std::cin >> maxHeapchannel;
                          std::cout << "Enter Date: ";
                          std::cin >> maxHeapdate;
                          std::cout << "Enter Views: ";
                          std::cin >> maxHeapviews;
                          std::cout << "Enter Likes: ";
                          std::cin >> maxHeaplikes;
                          std::cout << "Enter Dislikes: ";
                          std::cin >> maxHeapdislikes;
                          std::cout << endl;
                          int tester2 = 0;
                          playerText.setString("");
                          temp.append("Title: ");
                          temp.append(maxHeaptitle);
                          temp.append("\n");
                          temp.append("Channel: ");
                          temp.append(maxHeapchannel);
                          temp.append("\n");
                          temp.append("Date: ");
                          temp.append(maxHeapdate);
                          temp.append("\n");
                          temp.append("Views: ");
                          temp.append(maxHeapviews);
                          temp.append("\n");
                          temp.append("Likes: ");
                          temp.append(maxHeaplikes);
                          temp.append("\n");
                          temp.append("Dislikes: ");
                          temp.append(maxHeapdislikes);
                          temp.append("\n");
                          int testerTop = 0;
                          for (int i = 0; i < maxHeapviews.length(); i++) {
                              if (isalpha(maxHeapviews.at(i))) {
                                  testerTop++;
                              }
                          }
                          for (int i = 0; i < maxHeaplikes.length(); i++) {
                              if (isalpha(maxHeaplikes.at(i))) {
                                  testerTop++;
                              }
                          }
                          for (int i = 0; i < maxHeapdislikes.length(); i++) {
                              if (isalpha(maxHeapdislikes.at(i))) {
                                  testerTop++;
                              }
                          }
                          if (testerTop == 0) {
                              heap.insert(maxHeaptitle, maxHeapchannel, maxHeapdate, maxHeapviews, maxHeaplikes, maxHeapdislikes);
                              //  tempKheap =;
                              playerText.setPosition(400, 100);
                              playerText.setFillColor(sf::Color::White);
                              playerInput += event.text.unicode;
                              playerText.setString((temp));
                              //outPutHTreeK.setString(heap.kthLargest(stoi(kthHeap)));
                              textOutput.push_back(inputPrompt);

                              success.setString("Successful");
                              success.setFillColor(sf::Color::White);
                              success.setPosition(400, 10);
                          }
                          else {
                              success.setString("Unsuccessful");
                              playerText.setString("");
                              success.setFillColor(sf::Color::White);
                              success.setPosition(400, 10);
                          }

                          ///
                      }
                      else {
                          success.setFillColor(sf::Color::Transparent);
                          playerText.setFillColor(sf::Color::Transparent);
                          countSpriteButt++;
                          playerText.setString("");
                          spriteButton.setColor(sf::Color::Red);
                          if (!empty(textOutput)) {
                              textOutput.pop_back();
                          }
                      }
                  }
              }
              if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                  sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                  sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                  if (button1.getGlobalBounds().contains(mousePosF)) {
                      //button is clicked, do something 
                      //remove function actions
                      if (countButt1 % 2 == 0) {
                          countButt1++;
                          button1.setColor(sf::Color::White);
                          heap.remove();

                          success.setString("Successful");
                          success.setFillColor(sf::Color::White);
                          success.setPosition(400, 10);
                          playerText.setPosition(400, 100);
                          playerText.setFillColor(sf::Color::White);
                          removeCountMaxHeap++;
                          string removeCountText = to_string(removeCountMaxHeap);
                          removeCountText.append(" Videos Removed");
                          playerText.setString(removeCountText);
                      }
                      else {
                          countButt1++;
                          button1.setColor(sf::Color::Red);
                          success.setFillColor(sf::Color::Transparent);
                          playerText.setFillColor(sf::Color::Transparent);
                      }
                  }
              }if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                  sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                  sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                  if (button2.getGlobalBounds().contains(mousePosF)) {
                      //button is clicked, do something 
                      //kth function actions
                      if (countButt2 % 2 == 0) {
                          countButt2++;
                          button2.setColor(sf::Color::White);

                          std::cout << "Enter k: ";
                          std::cin >> kthHeap;
                          std::cout << endl;
                          int tester = 0;
                          for (int i = 0; i < kthHeap.length(); i++) {
                              if (isalpha(kthHeap.at(i))) {
                                  tester = 1;
                              }
                          }
                          if (tester == 0) {
                              //  tempKheap =;
                              playerText.setPosition(280, 180);
                              playerText.setFillColor(sf::Color::White);
                              playerInput += event.text.unicode;
                              playerText.setString((kthHeap));
                              outPutHTreeK.setString(heap.kthLargest(stoi(kthHeap)));
                              textOutput2.push_back(inputPrompt2);

                              success.setString("Successful");
                              success.setFillColor(sf::Color::White);
                              success.setPosition(400, 10);
                          }
                          else {
                              success.setString("Unsuccessful");
                              success.setFillColor(sf::Color::White);
                              success.setPosition(400, 10);
                          }
                          kthHeap = "0";
                      }
                      else {
                          playerText.setFillColor(sf::Color::Transparent);
                          success.setFillColor(sf::Color::Transparent);
                          countButt2++;
                          button2.setColor(sf::Color::Red);
                          if (!textOutput2.empty()) {
                              textOutput2.pop_back();
                          }
                          outPutHTreeK.setString("");
                      }
                  }
              }

              if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                  sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                  sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                  if (button4.getGlobalBounds().contains(mousePosF)) {
                      //button is clicked, do something 
                      //insert function actions

                      if (countButt4 % 2 == 0) {
                          countButt4++;
                          inputPrompt3.setFillColor(sf::Color::White);

                          button4.setColor(sf::Color::White);
                          textOutput3.push_back(inputPrompt3);
                          temp = ("");
                          std::cout << "Enter Title: ";
                          std::cin >> BTreetitle;
                          std::cout << "Enter Channel: ";
                          std::cin >> BTreechannel;
                          std::cout << "Enter Date: ";
                          std::cin >> BTreedate;
                          std::cout << "Enter Views: ";
                          std::cin >> BTreeviews;
                          std::cout << "Enter Likes: ";
                          std::cin >> BTreelikes;
                          std::cout << "Enter Dislikes: ";
                          std::cin >> BTreedislikes;
                          std::cout << endl;
                          int tester3 = 0;
                          playerText.setString("");
                          temp.append("Title: ");
                          temp.append(BTreetitle);
                          temp.append("\n");
                          temp.append("Channel: ");
                          temp.append(BTreechannel);
                          temp.append("\n");
                          temp.append("Date: ");
                          temp.append(BTreedate);
                          temp.append("\n");
                          temp.append("Views: ");
                          temp.append(BTreeviews);
                          temp.append("\n");
                          temp.append("Likes: ");
                          temp.append(BTreelikes);
                          temp.append("\n");
                          temp.append("Dislikes: ");
                          temp.append(BTreedislikes);
                          temp.append("\n");
                          int testerTop2 = 0;
                          for (int i = 0; i < BTreeviews.length(); i++) {
                              if (isalpha(BTreeviews.at(i))) {
                                  testerTop2++;
                              }
                          }
                          for (int i = 0; i < BTreelikes.length(); i++) {
                              if (isalpha(BTreelikes.at(i))) {
                                  testerTop2++;
                              }
                          }
                          for (int i = 0; i < BTreedislikes.length(); i++) {
                              if (isalpha(BTreedislikes.at(i))) {
                                  testerTop2++;
                              }
                          }
                          if (testerTop2 == 0) {
                              videos.push_back(Video(BTreetitle, stoi(BTreeviews), BTreechannel, BTreedate, BTreelikes, BTreedislikes));
                              //  tempKheap =;
                              playerText.setPosition(400, 100);
                              playerText.setFillColor(sf::Color::White);
                              playerInput += event.text.unicode;
                              playerText.setString((temp));
                              //outPutHTreeK.setString(heap.kthLargest(stoi(kthHeap)));
                              textOutput3.push_back(inputPrompt3);

                              success.setString("Successful");
                              success.setFillColor(sf::Color::White);
                              success.setPosition(400, 10);
                          }
                          else {
                              success.setString("Unsuccessful");
                              success.setFillColor(sf::Color::White);
                              success.setPosition(400, 10);
                          }
                      }
                      else {
                          countButt4++;
                          button4.setColor(sf::Color::Red);
                          playerText.setString("");
                          success.setFillColor(sf::Color::Transparent);
                          textOutput3.pop_back();
                          inputPrompt3.setFillColor(sf::Color::Transparent);
                      }
                  }
              }
              if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                  sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                  sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                  if (button5.getGlobalBounds().contains(mousePosF)) {
                      //button is clicked, do something 
                      //remove function actions
                      if (countButt5 % 2 == 0) {
                          temp = ("");
                          countButt5++;
                          button5.setColor(sf::Color::White);
                          textOutput5.push_back(inputPrompt5);
                          playerText.setString("");
                          std::cout << "Search: ";
                          std::cin >> searchFunc;
                          playerText2.setPosition(280, 340);
                          playerText2.setFillColor(sf::Color::White);
                          playerInput += event.text.unicode;
                          playerText2.setString(searchFunc);
                          
                          for (int i = 0; i < videos.size(); i++) {
                              size_t found = videos.at(i).title.find(searchFunc);
                              if (found != string::npos) {
                               //   cout << videos.at(i).title;
                                  size_t found2 = temp.find(videos.at(i).title);
                                  if (found2 == string::npos) {
                                      temp.append(videos.at(i).title);
                                      temp.append("\n");
                                  }
                                  
                              }
                          }
                          playerText.setPosition(400, 100);
                          playerText.setFillColor(sf::Color::White);
                          playerText.setString(temp);

                      }
                      else {
                          playerText2.setString("");
                          playerText.setString("");
                          countButt5++;
                          button5.setColor(sf::Color::Red);
                          success.setFillColor(sf::Color::Transparent);
                          playerText.setFillColor(sf::Color::Transparent);
                          textOutput5.pop_back();
                      }
                  }
              }if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                  sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                  sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                  if (button6.getGlobalBounds().contains(mousePosF)) {
                      //button is clicked, do something 
                      //kth function actions
                      if (countButt6 % 2 == 0) {
                          countButt6++;
                          button6.setColor(sf::Color::White);
                          
                          ///
                          timesKPrint = 0;
                          std::cout << "Enter k: ";
                          std::cin >> kthBT;
                          std::cout << endl;
                          int tester4 = 0;
                          for (int i = 0; i < kthBT.length(); i++) {
                              if (isalpha(kthBT.at(i))) {
                                  tester4 = 1;
                              }
                          }
                          if (tester4 == 0) {
                              //  tempKheap =;
                              playerText.setPosition(280, 380);
                              playerText.setFillColor(sf::Color::White);
                              playerInput += event.text.unicode;
                              playerText.setString((kthBT));
                          //    outPutBTK.setString(bTree.kthLargest(stoi(kthBT)));
                              for (int i = 0; i < videos.size(); i++) {
                                  if (i == stoi(kthBT) && timesKPrint == 0) {
                                      cout << videos.at(i).title;
                                      timesKPrint++;
                                      playerText.setString("");
                                      temp = ("");
                                      temp.append("Title: ");
                                      temp.append(videos.at(i).title);
                                      temp.append("\n");
                                      temp.append("Channel: ");
                                      temp.append(videos.at(i).channel);
                                      temp.append("\n");
                                      temp.append("Date: ");
                                      temp.append(videos.at(i).date);
                                      temp.append("\n");
                                      temp.append("Views: ");
                                      temp.append(to_string(videos.at(i).views));
                                      temp.append("\n");
                                      temp.append("Likes: ");
                                      temp.append(videos.at(i).likes);
                                      temp.append("\n");
                                      temp.append("Dislikes: ");
                                      temp.append(videos.at(i).dislikes);
                                      temp.append("\n");
                                  }
                              
                              }
                              textOutput4.push_back(inputPrompt4);
                              playerText.setPosition(400, 100);
                              playerText.setFillColor(sf::Color::White);
                              playerInput += event.text.unicode;
                              playerText.setString((temp));
                              success.setString("Successful");
                              success.setFillColor(sf::Color::White);
                              success.setPosition(400, 10);
                          }
                          else {
                              success.setString("Unsuccessful");
                              success.setFillColor(sf::Color::White);
                              success.setPosition(400, 10);
                          }
                          kthBT = "0";
                          //inputPrompt.setFillColor(sf::Color::White);
                          //textOutput4.push_back(inputPrompt4);
                      }
                      else {
                          countButt6++;
                          button6.setColor(sf::Color::Red);
                          playerText.setFillColor(sf::Color::Transparent);
                          //textOutput4.pop_back();
                          success.setFillColor(sf::Color::Transparent);
                         // if (!textOutput4.empty()) {
                              textOutput4.pop_back();
                        //  }
                          outPutBTK.setString("");
                      }
                  }
              }

          }
        

          window.clear();
          window.draw(background);
          window.draw(spriteButton);
          window.draw(button1);
          window.draw(button2);
          window.draw(button4);
          window.draw(button5);
          window.draw(button6);
          window.draw(HeapText);
          window.draw(BTText);
          window.draw(buttonText);
          window.draw(removeText);
          window.draw(kthText);
          window.draw(thText);
          window.draw(BTreeIn);
          window.draw(BTreeRe);
          window.draw(BTreekthText);
          window.draw(BTreethText);

          for (auto it = textOutput.begin(); it != textOutput.end(); it++)
          {
              window.draw(*it);
          }

          for (auto it = textOutput2.begin(); it != textOutput2.end(); it++)
          {
              window.draw(*it);
          }
          for (auto it = textOutput3.begin(); it != textOutput3.end(); it++)
          {
              window.draw(*it);
          }
          for (auto it = textOutput4.begin(); it != textOutput4.end(); it++)
          {
              window.draw(*it);
          }
          for (auto it = textOutput5.begin(); it != textOutput5.end(); it++)
          {
              window.draw(*it);
          }
          window.draw(outPutHTreeK);
          window.draw(outPutBTK);

          window.draw(playerText);
          window.draw(playerText2);
          window.draw(success);
          window.display();
      }
            return 0;
        }
   