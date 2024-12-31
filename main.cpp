#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>

using namespace sf;
using namespace std;

const int rows = 10;
const int columns = 10;

int main()
{
    int num = 0, x = 510, y = 7, x_cor = 4, y_cor = 4, key = 0, enter = 0, x_cor1 = 4, y_cor1 = 4, temp = 0, points = 0, movescounter = 15, SaveLoad = 0;
    int init_score = 0;
    int a[rows][columns];
    srand(time(NULL));

    //Initializing grid
    sf::RectangleShape grid[rows][columns];

    //Open window
    sf::RenderWindow window(VideoMode(1280, 600), "Candy Crush Sage", Style::Fullscreen);

    window.setFramerateLimit(60);

    //Background
    sf::RectangleShape background;
    sf::Texture backgroundtex;
    backgroundtex.loadFromFile("grid.png");
    background.setTexture(&backgroundtex);
    background.setSize(Vector2f(1920.0, 1080.0));

    //Text boxes
    RectangleShape rec1(Vector2f(130.f, 30.f));
    rec1.setPosition(Vector2f(100.f, 200.f));
    rec1.setFillColor(Color::Transparent);
    rec1.setOutlineColor(Color::Magenta);
    rec1.setOutlineThickness(5);

    RectangleShape rec2(Vector2f(165.f, 30.f));
    rec2.setPosition(Vector2f(100.f, 250.f));
    rec2.setFillColor(Color::Transparent);
    rec2.setOutlineColor(Color::Magenta);
    rec2.setOutlineThickness(5);

    RectangleShape rec3(Vector2f(125.f, 30.f));
    rec3.setPosition(Vector2f(100.f, 300.f));
    rec3.setFillColor(Color::Transparent);
    rec3.setOutlineColor(Color::Magenta);
    rec3.setOutlineThickness(5);

    RectangleShape rec4(Vector2f(125.f, 40.f));
    rec4.setPosition(Vector2f(75.f, 500.f));
    rec4.setFillColor(Color::Transparent);
    rec4.setOutlineColor(Color::Magenta);
    rec4.setOutlineThickness(5);

    RectangleShape rec5(Vector2f(125.f, 40.f));
    rec5.setPosition(Vector2f(275.f, 500.f));
    rec5.setFillColor(Color::Transparent);
    rec5.setOutlineColor(Color::Magenta);
    rec5.setOutlineThickness(5);

    RectangleShape win(Vector2f(626.f, 417.f));
    win.setOutlineColor(Color::Magenta);
    win.setOutlineThickness(25);

    RectangleShape lose(Vector2f(626.f, 417.f));
    lose.setOutlineColor(Color::Magenta);
    lose.setOutlineThickness(25);

    //Loading textures
    Texture wintex;
    wintex.loadFromFile("win.png", IntRect(0, 0, 1280, 600));
    win.setTexture(&wintex);
    win.setPosition(Vector2f(300.f, 100.f));
    Texture losetex;
    losetex.loadFromFile("lose.png", IntRect(0, 0, 1280, 600));
    lose.setTexture(&losetex);
    lose.setPosition(Vector2f(300.f, 100.f));

    //Setting font
    Font font;
    font.loadFromFile("font.ttf");

    //Text to be displayed
    Text title;
    title.setFont(font);
    title.setString("You are playing Candy Crush");
    title.setCharacterSize(24);
    title.setPosition(Vector2f(10.f, 10.f));
    title.setFillColor(Color::Black);

    Text target;
    target.setFont(font);
    target.setString("Goal : ");
    target.setCharacterSize(24);
    target.setPosition(Vector2f(100.f, 200.f));
    target.setFillColor(Color::Black);

    Text moves;
    moves.setFont(font);
    moves.setString("Moves left : ");
    moves.setCharacterSize(24);
    moves.setPosition(Vector2f(100.f, 250.f));
    moves.setFillColor(Color::Black);

    Text score;
    score.setFont(font);
    score.setString("Points : ");
    score.setCharacterSize(24);
    score.setPosition(Vector2f(100.f, 300.f));
    score.setFillColor(Color::Black);

    Text tpoint;
    tpoint.setFont(font);
    tpoint.setString("200");
    tpoint.setCharacterSize(24);
    tpoint.setPosition(Vector2f(185.f, 200.f));
    tpoint.setFillColor(Color::Red);

    Text save;
    save.setFont(font);
    save.setString("SAVE");
    save.setCharacterSize(24);
    save.setPosition(Vector2f(100.f, 510.f));
    save.setFillColor(Color::Black);

    Text load;
    load.setFont(font);
    load.setString("LOAD");
    load.setCharacterSize(24);
    load.setPosition(Vector2f(300.f, 510.f));
    load.setFillColor(Color::Black);

    Text quit;
    quit.setFont(font);
    quit.setString("PRESS ESC TO QUIT");
    quit.setCharacterSize(15);
    quit.setPosition(Vector2f(10.f, 580.f));
    quit.setFillColor(Color::Black);

    //Generating random numbers
    for (int i = 0; i < columns; ++i) 
    {

        for (int j = 0; j < rows; ++j) 
        {
            num = ((rand() % 5) + 1);
            a[i][j] = num;
        }
    }

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            //Exit when escape is pressed
            if ((event.type == Event::Closed) || (Keyboard::isKeyPressed(Keyboard::Escape)))
                window.close();

        }

        //Keyboard input
        if (key <= 8) 
        {
            ++key;
        }

        if ((Keyboard::isKeyPressed(Keyboard::Up)) && (y_cor != 0) && (key >= 8)) 
        {
            y_cor = y_cor - 1;
            key = 0;
        }
        else  if ((Keyboard::isKeyPressed(Keyboard::Down)) && (y_cor != 8) && (key >= 8)) 
        {
            y_cor = y_cor + 1;
            key = 0;
        }
        else  if ((Keyboard::isKeyPressed(Keyboard::Right)) && (x_cor != 8) && (key >= 8)) 
        {
            x_cor = x_cor + 1;
            key = 0;
        }
        else  if ((Keyboard::isKeyPressed(Keyboard::Left)) && (x_cor != 0) && (key >= 8)) 
        {
            x_cor = x_cor - 1;
            key = 0;
        }

        if (((Keyboard::isKeyPressed(Keyboard::Left)) && (x_cor == 0)) && (key >= 8)) 
        {
            if (SaveLoad != 2)
            {
                SaveLoad++;
            }
            key = 0;
        }

        if ((Keyboard::isKeyPressed(Keyboard::Right)) && (key >= 8)) 
        {
            SaveLoad--;
            key = 0;
        }

        if ((Keyboard::isKeyPressed(Keyboard::Enter)) && (key >= 8)) 
        {
            enter++;
            key = 0;
        }

        //Changing color of outline
        if (SaveLoad == 1) 
        {
            rec5.setOutlineColor(Color::White);
            rec4.setOutlineColor(Color::Magenta);
        }
        else if (SaveLoad == 2) 
        {
            rec4.setOutlineColor(Color::White);
            rec5.setOutlineColor(Color::Magenta);
        }
        else 
        {
            rec5.setOutlineColor(Color::Magenta);
            rec4.setOutlineColor(Color::Magenta);
        }

        //Coordinates of the first selection
        if (enter == 1) 
        {
            x_cor1 = x_cor;
            y_cor1 = y_cor;
            enter++;
        }

        //Checking if same candies exist
        for (int i = 0; i < (columns - 1); i++) 
        {
            for (int j = 0; j < (rows - 1); j++) 
            {
                if (((a[i][j] == a[i - 1][j]) && (a[i][j] == a[i + 1][j]))) 
                {
                    for (int k = 0; k <= (i + 1); k++) 
                    {
                        num = ((rand() % 5) + 1);
                        a[k][j] = num;
                    }

                    points = points + 20;
                    if (init_score < 51) 
                    {
                        init_score++;
                    }
                }
                else if ((a[i][j] == a[i][j - 1]) && (a[i][j] == a[i][j + 1])) 
                {

                    for (int k = 0; k <= i; k++) 
                    {
                        num = ((rand() % 5) + 1);
                        a[k][j - 1] = num;
                    }
                    for (int k = 0; k <= i; k++)
                    {
                        num = ((rand() % 5) + 1);
                        a[k][j + 1] = num;
                    }
                    for (int k = 0; k <= i; k++) 
                    {
                        num = ((rand() % 5) + 1);
                        a[k][j] = num;

                    }

                    points = points + 10;
                    if (init_score < 51) 
                    {
                        init_score++;
                    }


                }
            }
        }
        if (init_score < 50) 
        {
            points = 0;
        }
    
        //Displaying moves and points
        init_score++;
        Text point;
        stringstream str;
        str << points;
        point.setString(str.str().c_str());
        point.setFont(font);
        point.setString(str.str());
        point.setCharacterSize(24);
        point.setPosition(Vector2f(185.f, 300.f));
        point.setFillColor(Color::Red);

        Text tries;
        stringstream str1;
        str1 << movescounter;
        tries.setString(str1.str().c_str());
        tries.setFont(font);
        tries.setString(str1.str());
        tries.setCharacterSize(24);
        tries.setPosition(Vector2f(235.f, 250.f));
        tries.setFillColor(Color::Red);

        //Displaying on window
        window.clear();
        window.draw(background);
        window.draw(rec1);
        window.draw(rec2);
        window.draw(rec3);
        window.draw(rec4);
        window.draw(rec5);
        window.draw(title);
        window.draw(target);
        window.draw(score);
        window.draw(moves);
        window.draw(point);
        window.draw(tpoint);
        window.draw(tries);
        window.draw(save);
        window.draw(load);
        window.draw(quit);

        //Grid printing
        x = 510;
        y = 5;
        sf::Vector2f cellSize(25.f, 25.f);
        for (int i = 0; i < (columns - 1); ++i) 
        {
            x = 510;
            for (int j = 0; j < (rows - 1); ++j) 
            {

                if (a[i][j] == 1) 
                {
                    grid[i][j].setSize(cellSize);
                    grid[i][j].setFillColor(Color::Blue);
                    grid[i][j].setOutlineThickness(5.f);
                    if (((i == y_cor) && (j == x_cor) && (enter != 2)) && (SaveLoad == 0)) {
                        grid[i][j].setOutlineColor(Color::Yellow);

                    }
                    else if (((i == y_cor) && (j == x_cor) && (enter == 2)) && (SaveLoad == 0)) {
                        grid[i][j].setOutlineColor(Color::Red);

                    }

                    else if ((SaveLoad == 1) && (SaveLoad == 2))
                        grid[i][j].setOutlineColor(Color::White);
                    else
                        grid[i][j].setOutlineColor(Color::White);
                        grid[i][j].setPosition(x, y);
                        window.draw(grid[i][j]);
                }
                else if (a[i][j] == 2) 
                {
                    grid[i][j].setSize(cellSize);
                    grid[i][j].setFillColor(Color(232, 97, 0));
                    grid[i][j].setOutlineThickness(5.f);
                    if (((i == y_cor) && (j == x_cor) && (enter != 2)) && (SaveLoad == 0)) {
                        grid[i][j].setOutlineColor(Color::Yellow);

                    }
                    else if (((i == y_cor) && (j == x_cor) && (enter == 2)) && (SaveLoad == 0)) {
                        grid[i][j].setOutlineColor(Color::Red);

                    }

                    else if ((SaveLoad == 1) && (SaveLoad == 2))
                        grid[i][j].setOutlineColor(Color::White);
                    else
                        grid[i][j].setOutlineColor(Color::White);

                    grid[i][j].setPosition(x, y);
                    window.draw(grid[i][j]);
                }
                else if (a[i][j] == 3) 
                {
                    grid[i][j].setSize(cellSize);
                    grid[i][j].setFillColor(Color::Red);
                    grid[i][j].setOutlineThickness(5.f);
                    if (((i == y_cor) && (j == x_cor) && (enter != 2)) && (SaveLoad == 0)) {
                        grid[i][j].setOutlineColor(Color::Yellow);

                    }
                    else if (((i == y_cor) && (j == x_cor) && (enter == 2)) && (SaveLoad == 0)) {
                        grid[i][j].setOutlineColor(Color::Red);

                    }

                    else if ((SaveLoad == 1) && (SaveLoad == 2))
                        grid[i][j].setOutlineColor(Color::White);
                    else
                        grid[i][j].setOutlineColor(Color::White);

                    grid[i][j].setPosition(x, y);
                    window.draw(grid[i][j]);
                }
                else if (a[i][j] == 4) 
                {
                    grid[i][j].setSize(cellSize);
                    grid[i][j].setFillColor(Color::Green);
                    grid[i][j].setOutlineThickness(5.f);

                    if (((i == y_cor) && (j == x_cor) && (enter != 2)) && (SaveLoad == 0)) 
                    {
                        grid[i][j].setOutlineColor(Color::Yellow);

                    }
                    else if (((i == y_cor) && (j == x_cor) && (enter == 2)) && (SaveLoad == 0)) 
                    {
                        grid[i][j].setOutlineColor(Color::Red);

                    }

                    else if ((SaveLoad == 1) && (SaveLoad == 2))
                        grid[i][j].setOutlineColor(Color::White);
                    else
                        grid[i][j].setOutlineColor(Color::White);

                    grid[i][j].setPosition(x, y);
                    window.draw(grid[i][j]);
                }
                else if (a[i][j] == 5) 
                {
                    grid[i][j].setSize(cellSize);
                    grid[i][j].setFillColor(Color::Yellow);
                    grid[i][j].setOutlineThickness(5.f);
                    if (((i == y_cor) && (j == x_cor) && (enter != 2)) && (SaveLoad == 0)) {
                        grid[i][j].setOutlineColor(Color::Yellow);

                    }
                    else if (((i == y_cor) && (j == x_cor) && (enter == 2)) && (SaveLoad == 0)) {
                        grid[i][j].setOutlineColor(Color::Red);

                    }

                    else if ((SaveLoad == 1) && (SaveLoad == 2))
                        grid[i][j].setOutlineColor(Color::White);
                    else
                        grid[i][j].setOutlineColor(Color::White);

                    grid[i][j].setPosition(x, y);
                    window.draw(grid[i][j]);
                }
                x = x + 75;
            }
            y = y + 70;

            //Swapping candies
            //Decrementing moves
            if ((enter == 3) && (((((y_cor1 + 1 == y_cor) || (y_cor1 - 1) == y_cor)) && (x_cor1 == x_cor)) || ((((x_cor1 + 1 == x_cor) || (x_cor1 - 1) == x_cor)) && (y_cor1 == y_cor)))) {
                temp = a[y_cor][x_cor];
                a[y_cor][x_cor] = a[y_cor1][x_cor1];
                a[y_cor1][x_cor1] = temp;
                enter = 0;
                movescounter--;

            }
            else if (enter 
                == 3) 
            {
                enter = 0;
            }
        }

        //If points go above or equal to 200, player wins
        if (points >= 200) 
        {
            window.draw(win);
        }

        //If points are less than 200, the player loses
        if ((movescounter == 0) && (points < 200)) 
        {
            window.draw(lose);
        }


        window.display();

        //Saving data
        if ((SaveLoad == 2) && (enter == 2)) 
        {
            ofstream fout;
            fout.open("SaveLoad.txt");
            fout << points << endl;
            fout << movescounter << endl;

            for (int i = 0; i < columns; i++)
                for (int j = 0; j < rows; j++) 
                {
                    fout << a[i][j] << "  ";
                    if (j == 9) {
                        fout << endl;
                    }
                }

            SaveLoad = 0;
            enter = 0;

        }

        //Reloading data
        if ((SaveLoad == 1) && (enter == 2)) 
        {
            ifstream fin;
            fin.open("candy.txt");
            fin >> points;
            fin >> movescounter;

            for (int i = 0; i < columns; i++)
            {
                for (int j = 0; j < rows; j++)
                    fin >> a[i][j];
            }

            SaveLoad = 0;
            enter = 0;

        }
    }

    return 0;
}