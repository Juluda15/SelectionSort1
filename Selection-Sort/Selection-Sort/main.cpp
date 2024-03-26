#include <stdio.h>
#include <ctime>
#include <time.h>
#include <string>
#include <vector>
#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"

void TryLoadFont(sf::Font& font, std::string path);
void selectionsortSP(int n, int arr[], int step);
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
    //Make the orginal array//
    srand(time(0));
    int orgarr[25];
    for (int i = 0; i < 25; i++)
    {
        orgarr[i] = rand() % 25 + 1;
    }
    //Create rectangles for original//
    sf::RectangleShape orectangles[25];
    const float ocolumnwidth = 1000.00f / 25.00f;
    const float ocolumnheight = 250;
    for (int i = 0; i < 25; i++)
    {
        float height1 = orgarr[i] / 25.00f * ocolumnheight;
        orectangles[i] = sf::RectangleShape(sf::Vector2f(ocolumnwidth, -height1));
        orectangles[i].setPosition(i * ocolumnwidth, 300);
        orectangles[i].setFillColor(sf::Color::White);
    }
    //Make the sorted array//
    int sortarr[25];
    for (int i = 0; i < 25; i++)
    {
        sortarr[i] = orgarr[i];
    }
    int step = 0;
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
        window.draw(line);
        for(int i = 0; i < 25; i++)
        {
            window.draw(orectangles[i]);
        }
        //Make the sort visible//
        if (step < 24)
        {
            selectionsortSP(25, sortarr, step);
            step++;
            sf::sleep(sf::milliseconds(200));
        }
        //Create rectangles for sorted//
        sf::RectangleShape srectangles[25];
        const float scolumnwidth = 1000.00f / 25.00f;
        const float scolumnheight = 250.00f;
        for (int i = 0; i < 25; i++)
        {
            float height2 = sortarr[i] / 25.00f * scolumnheight;
            srectangles[i] = sf::RectangleShape(sf::Vector2f(scolumnwidth, -height2));
            srectangles[i].setPosition(i * scolumnwidth, 600);
            srectangles[i].setFillColor(sf::Color::White);
            window.draw(srectangles[i]);
        }
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

void selectionsortSP(int n, int arr[], int step)
{
    int a, minindex;
    minindex = step;
    for (a = step + 1; a < n; a++)
    {
        if (arr[a] < arr[minindex])
        {
            minindex = a;
        }
    }
    if (minindex != step)
    {
        swap(&arr[minindex], &arr[step]);
    }
}

