#include <stdio.h>
#include <ctime>
#include <time.h>
#include <string>
#include <vector>
#include <iostream>
#include <string>
#include "SFML/Graphics.hpp"
// TODO: Fix issue with gap_end not resizing correctly
void TryLoadFont(sf::Font& font, std::string path);
void selectionsort(int n, int arr[]);
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
    ///////////Font & Text///////////////////////
    sf::Font font;
    TryLoadFont(font, "8bitfont.ttf");
    sf::Text text1("", font, 22);
    text1.setFillColor(sf::Color::Red);
    text1.setPosition(sf::Vector2f(450, 295));
    ///////Swap minimum with current////////////
    srand(time(0));
    int arr[25];
    for (int i = 0; i < 25; i++)
    {
        arr[i] = rand() % 25 + 1;
    }
    std::cout << "Original Array: ";
    for (int i = 0; i < 25; i++)
    {
        std::cout << arr[i] << " " << std::endl;
    }
    selectionsort(arr[], 25);
    std::cout << "Sorted array: ";
    for (int i = 0; i < 25; i++) {
        std::cout << arr[i] << " " << std::endl;
    }

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
        int minindex = i;
        for (a = i + 1; a < n; a++)
        {
            if (arr[a] < arr[minindex])
            {
                arr[minindex] = arr[a];
            }
        }
        if (minindex != i)
        {
            swap(&arr[minindex], &arr[a]);
        }
    }
}
