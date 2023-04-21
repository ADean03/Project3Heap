#include <SFML/Graphics.hpp>
#include <sstream>
#include <iostream>
#include <vector>
#include <sstream>
#include <iomanip>
#include<fstream>
#include "maxHeap.h"
using namespace std;


int main()
{
    ////////////////
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
    myFile.open("../USvideos.csv"); //////////had to change to work on local machine change back later
    
    
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

  


    















    /// <summary>
    /// ////////////////
    /// </summary>
    /// <returns></returns>
    sf::RenderWindow window(sf::VideoMode(900, 700), "Project 3");
    
    sf::String playerInput;
    sf::Texture t;
    t.loadFromFile("../backgroundimageprogram.jpg");
    sf::Vector2f targetSize(900.0f, 800.0f);
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
    sf::Sprite button3;
    button3.setTexture(buttonSprite);
    // sf::RectangleShape button(sf::Vector2f(150, 30));
    button3.setPosition(30, 220);
    button3.setColor(sf::Color::Red);
    button3.setScale(0.75, 0.75);
    sf::Font font;
    sf::Text playerText("", font, 24);
   // sf::Font font;
    if (!font.loadFromFile("../Roboto-Light.ttf")) {
       return EXIT_FAILURE;
    }

    sf::Text HeapText;
    HeapText.setFont(font);
    HeapText.setString("Heap Tree:");
    HeapText.setCharacterSize(36);
    HeapText.setPosition(35, 50);
    HeapText.setFillColor(sf::Color::White);
    HeapText.setStyle(sf::Text::Bold);

    sf::Text BTText;
    BTText.setFont(font);
    BTText.setString("B Tree:");
    BTText.setCharacterSize(36);
    BTText.setPosition(600, 50);
    BTText.setFillColor(sf::Color::White);
    BTText.setStyle(sf::Text::Bold);

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
    sf::Text printText;
    printText.setFont(font);
    printText.setString("Print Videos");
    printText.setCharacterSize(24);
    printText.setPosition(35, 180);
    printText.setFillColor(sf::Color::White);
    printText.setStyle(sf::Text::Bold);
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
    kthText.setPosition(35, 220);
    thText.setPosition(50, 225
    );
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
    button4.setPosition(595, 100);
    button4.setColor(sf::Color::Red);
    button4.setScale(0.75, 0.75);
    //
  //  button.setFillColor(sf::Color::Red);

    sf::Sprite button5;
    button5.setTexture(buttonSprite);
    // sf::RectangleShape button(sf::Vector2f(150, 30));
    button5.setPosition(595, 140);
    button5.setColor(sf::Color::Red);
    button5.setScale(0.75, 0.75);
    //

    sf::Sprite button6;
    button6.setTexture(buttonSprite);
    // sf::RectangleShape button(sf::Vector2f(150, 30));
    button6.setPosition(595, 180);
    button6.setColor(sf::Color::Red);
    button6.setScale(0.75, 0.75);

    //
    sf::Sprite button7;
    button7.setTexture(buttonSprite);
    // sf::RectangleShape button(sf::Vector2f(150, 30));
    button7.setPosition(595, 220);
    button7.setColor(sf::Color::Red);
    button7.setScale(0.75, 0.75);
  //  sf::Font font;
    //sf::Text playerText("", font, 24);
    // sf::Font font;
    if (!font.loadFromFile("../Roboto-Light.ttf")) {
        return EXIT_FAILURE;
    }
    //buttonText is insert
    sf::Text BTreeIn;
    BTreeIn.setFont(font);
    BTreeIn.setString("Insert");
    BTreeIn.setCharacterSize(24);
    BTreeIn.setPosition(600, 100);
    BTreeIn.setFillColor(sf::Color::White);
    BTreeIn.setStyle(sf::Text::Bold);
    //
    //removeText is insert
    sf::Text BTreeRe;
    BTreeRe.setFont(font);
    BTreeRe.setString("Remove");
    BTreeRe.setCharacterSize(24);
    BTreeRe.setPosition(600, 140);
    BTreeRe.setFillColor(sf::Color::White);
    BTreeRe.setStyle(sf::Text::Bold);
    //
    //printText is insert
    sf::Text BTreePrint;
    BTreePrint.setFont(font);
    BTreePrint.setString("Print Videos");
    BTreePrint.setCharacterSize(24);
    BTreePrint.setPosition(600, 180);
    BTreePrint.setFillColor(sf::Color::White);
    BTreePrint.setStyle(sf::Text::Bold);
    //
    //kthText is insert
    sf::Text BTreekthText;
    sf::Text BTreethText;
    BTreekthText.setFont(font);
    BTreethText.setFont(font);
    BTreekthText.setString("K  Largest");
    BTreethText.setString("th");
    BTreekthText.setCharacterSize(24);
    BTreethText.setCharacterSize(10);
    BTreekthText.setPosition(600, 220);
    BTreethText.setPosition(615, 225);
    BTreekthText.setFillColor(sf::Color::White);
    BTreethText.setFillColor(sf::Color::White);
    BTreekthText.setStyle(sf::Text::Bold);
    BTreethText.setStyle(sf::Text::Bold);







    ///////////////

      sf::CircleShape shape(100.f);
      shape.setFillColor(sf::Color::Green);
      // ...
  //    std::stringstream ss;
 //     ss << 12;
  //    sf::Text.setString(ss.str());

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
                      spriteButton.setColor(sf::Color::White);
                  }
              }
              if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                  sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                  sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                  if (button1.getGlobalBounds().contains(mousePosF)) {
                      //button is clicked, do something 
                      //remove function actions
                      button1.setColor(sf::Color::White);
                  }
              }if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                  sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                  sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                  if (button2.getGlobalBounds().contains(mousePosF)) {
                      //button is clicked, do something 
                      //print function actions
                      button2.setColor(sf::Color::White);
                  }
              }if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                  sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                  sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                  if (button3.getGlobalBounds().contains(mousePosF)) {
                      //button is clicked, do something 
                      //kth largest fucntion actions
                      button3.setColor(sf::Color::White);
                  }
                  if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                      sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                      sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                      if (button4.getGlobalBounds().contains(mousePosF)) {
                          //button is clicked, do something 
                          //insert function actions
                          button4.setColor(sf::Color::White);
                      }
                  }
                  if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                      sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                      sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                      if (button5.getGlobalBounds().contains(mousePosF)) {
                          //button is clicked, do something 
                          //remove function actions
                          button5.setColor(sf::Color::White);
                      }
                  }if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                      sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                      sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                      if (button6.getGlobalBounds().contains(mousePosF)) {
                          //button is clicked, do something 
                          //print function actions
                          button6.setColor(sf::Color::White);
                      }
                  }if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                      sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                      sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                      if (button7.getGlobalBounds().contains(mousePosF)) {
                          //button is clicked, do something 
                          //kth largest fucntion actions
                          button7.setColor(sf::Color::White);
                      }
                  }
              }if (event.type == sf::Event::TextEntered)
              {
                  playerInput += event.text.unicode;
                  playerText.setString(playerInput);
              }
          }
        

          window.clear();
          window.draw(background);
          window.draw(spriteButton);
          window.draw(button1);
          window.draw(button2);
          window.draw(button3);
          window.draw(button4);
          window.draw(button5);
          window.draw(button6);
          window.draw(button7);
          
          window.draw(HeapText);
          window.draw(BTText);
          window.draw(buttonText);
          window.draw(removeText);
          window.draw(printText);
          window.draw(kthText);
          window.draw(BTreeIn);
          window.draw(BTreeRe);
          window.draw(BTreePrint);
          window.draw(BTreekthText);
          window.draw(BTreethText);
          window.draw(playerText);
          window.display();
      }
            return 0;
        }
   