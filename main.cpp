#include <iostream>                             // for standard input/output
using namespace std;                            // using the standard namespace

#include <SFML/Graphics.hpp>                    // include the SFML Graphics Library
using namespace sf;                             // using the sf namespace

#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cmath>

#include "Gameboard.h"
#include "Functions.h"

const int NUM_ROWS = 4;
const int NUM_COLS = 4;
const int NUM_COLORS = 12;

int main() {

    srand(time(0));
    rand();

    ifstream leaderboard("leaderboard.txt");
    if ( leaderboard.fail() ) {
        cerr << "Error opening leaderboard file";
        return -1;
    }

    // reads in the leaderboard file
    vector<int> highScores;
    vector<string> userNames;
    string userName;
    int highScore;
    while (!leaderboard.eof()) {
        leaderboard >> userName;
        leaderboard >> highScore;
        userNames.push_back(userName);
        highScores.push_back(highScore);
    }
    leaderboard.close();

    int bestScore = highScores.at(determineBestScore(highScores));

    Color tile_colors[NUM_COLORS];
    tile_colors[0] = Color(255, 255, 255);
    for (int i = 1; i < NUM_COLORS; i++) {      // initializes tile colors
        tile_colors[i] = Color((255 - (i * 20)), (255 - (i * 50)), 255, 255);
    }

    Gameboard gb; // initializes the gameboard gb using default constructor

    RenderWindow window( VideoMode(850, 550), "Fives!" );

    Font defaultFont;
    if (!defaultFont.loadFromFile("data/arial.ttf")) {
        cerr << "Could not open the font file (.ttf)" << endl;
        return -1;
    }

    while( window.isOpen() ) {
        while (!gb.isGameOver()) { // runs the game

            window.clear( Color::White );           // clear the contents of the old frame

            RectangleShape gameboard;
            gameboard.setPosition(Vector2f(350, 50));
            gameboard.setFillColor(Color(200, 200, 200));
            gameboard.setSize(Vector2f(450, 450));
            window.draw(gameboard);

            for (int r = 0; r < NUM_ROWS; r++){
                for (int c = 0; c < NUM_COLS; c++) {
                    RectangleShape tile;
                    int tileVal = gb.getBoard().at(r).at(c).getCurrentVal();
                    int fivePow = pow(tileVal, 1.0/5);

                    Text val;
                    val.setFont(defaultFont);
                    val.setString(to_string(tileVal));
                    val.setCharacterSize(20);
                    val.setFillColor(Color::White);
                    val.setPosition(Vector2f(370 + (c * 110), 70 + (r * 110)));

                    tile.setSize(Vector2f(100, 100));
                    tile.setPosition(Vector2f(360 + (c * 110), 60 + (r * 110)));
                    tile.setFillColor(tile_colors[fivePow]); // sets the tile fill color to a shade of blue based off of its power of five
                    window.draw(tile);
                    window.draw(val);
                }
            }

            Text title, score, highScoreVal, highScorePlayer, scoreHeader, highScoreHeader;
            title.setFont(defaultFont);
            score.setFont(defaultFont);
            highScoreVal.setFont(defaultFont);
            highScorePlayer.setFont(defaultFont);
            scoreHeader.setFont(defaultFont);
            highScoreHeader.setFont(defaultFont);

            title.setString("Fives!");
            title.setPosition(Vector2f(50, 50));
            title.setCharacterSize(100);
            title.setFillColor(Color::Blue);

            score.setString(to_string(gb.getScore()));
            score.setPosition(Vector2f(50, 220));
            score.setCharacterSize(50);
            score.setFillColor(Color::Red);

            highScoreVal.setString(to_string(bestScore));
            highScoreVal.setPosition(Vector2f(50, 340));
            highScoreVal.setCharacterSize(50);
            highScoreVal.setFillColor(Color::Black);

            scoreHeader.setString("Score:");
            scoreHeader.setPosition(Vector2f(50, 160));
            scoreHeader.setCharacterSize(50);
            scoreHeader.setFillColor(Color::Red);

            highScoreHeader.setString("High Score:");
            highScoreHeader.setPosition(Vector2f(50, 280));
            highScoreHeader.setCharacterSize(50);
            highScoreHeader.setFillColor(Color::Black);

            window.draw(title);
            window.draw(score);
            window.draw(highScoreVal);
            window.draw(scoreHeader);
            window.draw(highScoreHeader);

            window.display();                      // display the window

            //****************************************
            // HANDLE EVENTS BELOW HERE
            //****************************************
            Event event;
            while( window.pollEvent(event) ) {      // ask the window if any events occurred
                if( event.type == Event::Closed ) { // if event type is a closed event
                    // i.e. they clicked the X on the window
                    window.close();                 // then close our window
                    break;
                } else if (event.type == Event::KeyPressed) {
                    // moves can only occur if one is availble or the gameboard isn't full
                    if (Keyboard::isKeyPressed(Keyboard::W)) {
                        if (gb.canMoveVert() || gb.countZeroes() != 0) {
                            gb.moveUp();
                            gb.newTile();
                        }
                    } else if (Keyboard::isKeyPressed(Keyboard::A)) {
                        if (gb.canMoveLeft() || gb.countZeroes() != 0) {
                            gb.moveLeft();
                            gb.newTile();
                        }
                    } else if (Keyboard::isKeyPressed(Keyboard::S)) {
                        if (gb.canMoveVert() || gb.countZeroes() != 0) {
                            gb.moveDown();
                            gb.newTile();
                        }
                    } else if (Keyboard::isKeyPressed(Keyboard::D)) {
                        if (gb.canMoveRight() || gb.countZeroes() != 0) {
                            gb.moveRight();
                            gb.newTile();
                        }
                    }
                }
            }
        }

        // print this once the game is over

        window.clear( Color::White );           // clear the contents of the old frame

        RectangleShape gameboard;
        gameboard.setPosition(Vector2f(350, 50));
        gameboard.setFillColor(Color(200, 200, 200));
        gameboard.setSize(Vector2f(450, 450));
        window.draw(gameboard);

        for (int r = 0; r < NUM_ROWS; r++){
            for (int c = 0; c < NUM_COLS; c++) {
                RectangleShape tile;
                int tileVal = gb.getBoard().at(r).at(c).getCurrentVal();
                int fivePow = pow(tileVal, 1.0/5);

                Text val;
                val.setFont(defaultFont);
                val.setString(to_string(tileVal));
                val.setCharacterSize(20);
                val.setFillColor(Color::White);
                val.setPosition(Vector2f(370 + (c * 110), 70 + (r * 110)));

                tile.setSize(Vector2f(100, 100));
                tile.setPosition(Vector2f(360 + (c * 110), 60 + (r * 110)));
                tile.setFillColor(tile_colors[fivePow]); // sets the tile fill color to the list of colors
                window.draw(tile);
                window.draw(val);
            }
        }

        Text title, score, highScoreVal, gameOver, scoreHeader, highScoreHeader;
        title.setFont(defaultFont);
        score.setFont(defaultFont);
        highScoreVal.setFont(defaultFont);
        scoreHeader.setFont(defaultFont);
        highScoreHeader.setFont(defaultFont);

        title.setString("GAME OVER!!");
        title.setPosition(Vector2f(50, 50));
        title.setCharacterSize(100);
        title.setFillColor(Color::Red);

        score.setString(to_string(gb.getScore()));
        score.setPosition(Vector2f(50, 220));
        score.setCharacterSize(50);
        score.setFillColor(Color::Red);

        highScoreVal.setString(to_string(bestScore));
        highScoreVal.setPosition(Vector2f(50, 340));
        highScoreVal.setCharacterSize(50);
        highScoreVal.setFillColor(Color::Black);

        scoreHeader.setString("Score:");
        scoreHeader.setPosition(Vector2f(50, 160));
        scoreHeader.setCharacterSize(50);
        scoreHeader.setFillColor(Color::Red);

        highScoreHeader.setString("High Score:");
        highScoreHeader.setPosition(Vector2f(50, 280));
        highScoreHeader.setCharacterSize(50);
        highScoreHeader.setFillColor(Color::Black);

        window.draw(title);
        window.draw(score);
        window.draw(highScoreVal);
        window.draw(scoreHeader);
        window.draw(highScoreHeader);

        window.display();

        Event event;
        while( window.pollEvent(event) ) {      // ask the window if any events occurred
            if (event.type == Event::Closed) { // if event type is a closed event
                // i.e. they clicked the X on the window
                window.close();
            }
        }
    }

    cout << "What is your username for the leaderboard?" << endl;
    string currentUserName;
    getline(cin, currentUserName);

    ofstream fout("leaderboard.txt", ios_base::app);
    if ( fout.fail() ) {
        cerr << "Error opening leaderboard file";
        return -1;
    }

    fout << currentUserName << ' ' << gb.getScore() << endl;        // appends the final score to file
    fout.close();


    return EXIT_SUCCESS;                        // report our program exited successfully
}