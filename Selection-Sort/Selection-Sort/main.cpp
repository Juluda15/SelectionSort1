#include <stdio.h>
#include <ctime>
#include <time.h>
#include <string>
#include <vector>
#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"

void TryLoadFont(sf::Font& font, std::string path);
void selectionsort(int n, int arr[]);
//Swap funtion//
void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 600), "Selection-Sort");
    sf::Event e;
    //Font//
    sf::Font font;
    TryLoadFont(font, "8bitfont.ttf");
    //Line between original and sorted//
    sf::RectangleShape line;
    const float heightline = 10.00f;
    const float widthline = 1000.00f;
    line = sf::RectangleShape(sf::Vector2f(widthline, heightline));
    line.setPosition(0, 300.01);
    line.setFillColor(sf::Color::Red);
    //Original Array//
    sf::Text text1("Original Array: ", font, 22);
    text1.setFillColor(sf::Color::Red);
    text1.setPosition(sf::Vector2f(0, 5)); 
    //Sorted Array//
    sf::Text text2("Sorted Array: ", font, 22);
    text2.setFillColor(sf::Color::Red);
    text2.setPosition(sf::Vector2f(0, 316));
    //Make the orginal and sorted arrays//
    srand(time(0));
    int orgarr[25];
    for (int i = 0; i < 25; i++)
    {
        orgarr[i] = rand() % 25 + 1;
    }
    //Create rectangles for original//
    sf::RectangleShape orectangles[25];
    const float columnwidth = 1000.00f / 25.00f;
    const float columnheight = 250;
    for (int i = 0; i < 25; i++)
    {
        float height = orgarr[i] / 25.00f * columnheight;
        orectangles[i] = sf::RectangleShape(sf::Vector2f(columnwidth, -height));
        orectangles[i].setPosition(i * columnwidth, 300);
        orectangles[i].setFillColor(sf::Color::White);
    }
    int sortarr[25];
    for (int i = 0; i < 25; i++)
    {
        sortarr[i] = orgarr[i];
    }
    //Sort//
    selectionsort(25, sortarr);
    //Print the numbers on screen//
    std::string originalArray;
    for (int i = 0; i < 25; i++)
    {
        originalArray += std::to_string(orgarr[i]) + " ";
    }
    std::string sortedArray;
    for (int i = 0; i < 25; i++)
    {
        sortedArray += std::to_string(sortarr[i]) + " ";
    }
    //Window is open//
    while (window.isOpen())
    {
        while (window.pollEvent(e))
        {
            if (e.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        // After all of the events
        // --------- clear the screen ----------
        window.clear(sf::Color::Black);

        // --------- draw on the screen ---------
        window.draw(text1);
        window.draw(text2);
        for(int i = 0; i < 25; i++)
        {
            window.draw(orectangles[i]);
        }
        window.draw(line);

        // --------- display on the screen --------
        window.display();

    }



}
void TryLoadFont(sf::Font& font, std::string path)
{
    if (!font.loadFromFile(path))
    {
        std::cerr << "Failed to load font: " << path << std::endl;
        exit(EXIT_FAILURE);
    }
}

void selectionsort(int n, int arr[])
{
    int i, a, minindex;
    for (i = 0; i < n - 1; i++)
    {
        minindex = i;
        for (a = i + 1; a < n; a++)
        {
            if (arr[a] < arr[minindex])
            {
                minindex = a;
            }
        }
        if (minindex != i)
        {
            swap(&arr[minindex], &arr[i]);
        }
    }
}

