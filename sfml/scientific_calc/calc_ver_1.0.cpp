#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "headers/buffer.h"
#include "headers/styling.h"
#include <iostream> //for Debugging and testing
using namespace std;

int main()
{
    sf::RenderWindow win(sf::VideoMode(600,600),"Scientific Calculator");
    win.setVerticalSyncEnabled(true);

    sf::Font font;
    loadFile("fonts/OpenSans-Regular.ttf",font);

    sf::SoundBuffer buffer;
    loadFile("audios/Click2-Sebastian-759472264.wav",buffer);

    Button b1;
    b1.setDimensions(200,100,300,200);
    b1.syncWithWindow(&win);
    b1.setTextFont(font);
    b1.writeText("Test");
    b1.setTextOffset(-1.6,-7);
    b1.setColor(18,18,18);
    //b1.setHoverDimensions(200,110,400,300);
    b1.setHoverTextColor(4,199,4);
    b1.setTextColor(4,199,4);
    b1.setHoverOutline(4,199,4,255,1);
    b1.setOutline(4,199,4,255,1);
    b1.setHoverColor(59,55,59,255,0.5);
    b1.setClickable(false);
    b1.setClickColor(29,29,29);
    b1.setClickSound(buffer);
    b1.setClickDimensions(201.6,101.6,298.4,198.4);
    b1.ReturnValue = "clicked";


    //Program Loop
    while(win.isOpen())
    {
        sf::Event event;

        while(win.pollEvent(event))
        {
            if(event.type==sf::Event::Closed)
                win.close();

            b1.trackClick(event);
        }

        if(b1.IsClicked)
            cout << b1.ReturnValue << endl;

        win.clear(sf::Color(40,40,40));
        b1.Draw();
        win.display();
    }

    return 0;

}
