#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include "Player.h"
#include "Food.h"
#include "Game.h"
#include "Intro.h"
#include "Button.h"
#include "PlayButton.h"
#include "MainMenu.h"
#include "Shop.h"
#include "data.h"

using namespace std;    
using namespace sf;

int main()
{
    RenderWindow window(VideoMode(1000, 800), "Tomczyszyn Eater v1.0 BETA TEST 1");
    window.setFramerateLimit(60);
    srand(time(nullptr));

    Texture bg_text;
    bg_text.loadFromFile("Assets/Textures/bg.png");
    Sprite bg{ bg_text };

    Player player{ "Assets/Textures/player.png" };
    time_t start{};

    Event event;
    Intro* intro = new Intro{window};
    MainMenu* menu = new MainMenu{&window};

    Game game{player, &window};
    Shop shop(&window, player, bg);
    bool intro_deleted{ false };
    bool menu_deleted{ false };
    bool game_started{ false };
    int menuState{ -1 };

    // Once we open the game, we load data from file
    // IFSTREAM
    ifstream binFile("Assets/Data/data.dat", ios::in | ios::binary);
    dataToSave dataTS;
    binFile.read((char*)&dataTS, sizeof(dataTS));

    game.balance() = dataTS.money; // Load money

    bool* sk = new bool[8];
    bool* bsk = new bool[4];
    for (int i = 0; i < 8; i++)
    {
        if (dataTS.skins[i] == 'o') sk[i] = true;
        else sk[i] = false;
    }
    for (int i = 0; i < 4; i++)
    {
        if (dataTS.bg_skins[i] == 'o') bsk[i] = true;
        else bsk[i] = false;
    }
    // Load the rest
    shop.loadSkins(sk, dataTS.current_skin); // Load skins
    shop.loadBgSkins(bsk, dataTS.current_bgskin); // Load bg skins
    delete[] sk; delete[] bsk;
    // close the file
    binFile.close();

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == Event::EventType::Closed) // Before closing save data to file
            {
                ofstream binFile("Assets/Data/data.dat", ios::in | ios::binary);
                dataTS.money = game.balance();
                dataTS.current_skin = shop.getPointer();
                dataTS.current_bgskin = shop.getBgPointer();

                bool* sk;
                sk = shop.isBought();
                char sk_char[8];
                for (int i = 0; i < 8; i++)
                {
                    if (sk[i] == true) sk_char[i] = 'o';
                    else if (sk[i] == false) sk_char[i] = 'n';
                }
                for (int i = 0; i < 8; i++)
                {
                    dataTS.skins[i] = sk_char[i];
                }
                bool* bsk;
                char bsk_char[4];
                bsk = shop.isBgBought();
                for (int i = 0; i < 4; i++)
                {
                    if (bsk[i] == true) bsk_char[i] = 'o';
                    else if (bsk[i] == false) bsk_char[i] = 'n';
                }
                for (int i = 0; i < 4; i++)
                {
                    dataTS.bg_skins[i] = bsk_char[i];
                }
                // Write
                binFile.write((char*)&dataTS, sizeof(dataTS));

                delete sk; delete bsk;
                // Close
                binFile.close();
                window.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::Space) && game.gameRunning() == false)
            {
                start = time(nullptr);
                game.runGame();
            }            
            else if (Keyboard::isKeyPressed(Keyboard::Escape) && game.gameRunning() == false)
            {
                menuState = 0;
            }
        }
        window.clear();

        if (game.gameRunning() == true && menuState == 1) // Main Game
        {
            if (game_started == false)
            {
                start = time(nullptr);
                game_started = true;
            }
            if (intro_deleted == false)
            {
                delete intro;
                intro_deleted = true;
            }            
            if (menu_deleted == false)
            {
                delete menu;
                menu_deleted = true;
            }
            window.draw(bg);
            game.drawMoney();
            player.update();
            window.draw(player.getSprite());

            game.update();
            game.draw();
            if (double(time(nullptr) - start) == 2)
            {
                start = time(nullptr);
                int liczba = rand() % 6 + 1;
                string file_name{ "Assets/Textures/food" + to_string(liczba) + ".png" };
                Food* newFood = new Food{file_name};
                game.spawn(newFood);
            }
            game.catched();
            game.fell();
        }
        else if (menuState == 0) // Menu
        {
            if (menu_deleted == true)  menu = new MainMenu{ &window };
            menu->draw();

            menu->update(menuState, shop, game, dataTS);

            menu_deleted = false;
        }
        else if (menuState == -1) // Intro
        {
            start = time(nullptr);
            intro->play();
            if (intro->intro_started() == true) menuState = 0;
        } 
        else if (menuState == 2) // Shop
        {
            shop.draw();
            shop.backIfClicked(menuState);
            shop.checkIfBought(game.balance());
            
            game.drawMoney();
        }
        else
        {
            game.drawDeathScreen();
        }
        window.display();
    }
}