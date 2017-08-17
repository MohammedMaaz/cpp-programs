#ifndef STYLING_H_INCLUDED
#define STYLING_H_INCLUDED

#include<SFML/Graphics.hpp>
#include<string>

class Button : public sf::Transformable
{
public:


    //public data-members
    //NOTE: Convention for data-members followed is that there first alphabet is capitalized
    std::string ReturnValue;
    bool IsClicked = false;



    void setDimensions(float X1, float Y1, float X2, float Y2)
    {
        x1=X1; y1=Y1; x2=X2; y2=Y2;

        //Drawing the button
        Box.setSize(sf::Vector2f(x2-x1,y2-y1));
        Box.setPosition(x1,y1);
    }


    void syncWithWindow(sf::RenderWindow* userWindow)
    {
        win = userWindow;
    }


    void setColor(short r, short g, short b, short a=255)
    {
        Clr = sf::Color(r,g,b,a);

        Box.setFillColor(Clr);
    }


    void setTextFont(sf::Font &userFont)
    {
        font = userFont;
        text.setFont(font);
    }


    void writeText(sf::String str)
    {
        text.setString(str);
        textX = x1 + ( (x2-x1)-text.getLocalBounds().width )/2;
        textY = y1 + ( (y2-y1)-text.getLocalBounds().height )/2;
        text.setPosition(textX,textY);
        boxStr = str;
    }


    void setTextOffset(float x, float y)
    {
        textX = textX + x;
        textY = textY + y;
        text.setPosition(textX,textY);
    }


    void setTextColor(short r, short g, short b, short a=255)
    {
        textClr = sf::Color(r,g,b,a);
        text.setFillColor(textClr);
    }


    void setOutline(short r, short g, short b, short a=255, float width=1)
    {
        outlineClr = sf::Color(r,g,b,a);
        outlineWidth = width;

        Box.setOutlineColor(outlineClr);
        Box.setOutlineThickness(outlineWidth);
    }


    bool isHovered()
    {
        if(win==nullptr)
            return false;

        sf::Vector2i mousePos = sf::Mouse::getPosition(*win);

        if(mousePos.x>=x1 && mousePos.x<=x2 && mousePos.y>=y1 && mousePos.y<=y2)
            return true;
        else
            return false;
    }


    void setHoverDimensions(float X1, float Y1, float X2, float Y2)
    {
        hoverDimensionsTrigger = true;
        hoverX1=X1; hoverY1=Y1; hoverX2=X2; hoverY2=Y2;
    }


    void setHoverTextColor(short r, short g, short b, short a=255)
    {
        hoverTextClr = sf::Color(r,g,b,a);
        hoverTextClrTrigger = true;
    }


    void setHoverColor(short r, short g, short b, short a=255, float time = 0)
    {
        hoverClr = sf::Color(r,g,b,a);
        hoverClrTrigger = true;

        if(time<=0)
        {
            rT = Clr.a;
            startRTime = Clr.a;
            startHTime = hoverClr.a;
            hT = hoverClr.a;
        }
        else
            transitionTime = time;
    }


    void writeHoverText(sf::String str)
    {
        text.setString(str);
        hoverTextX = hoverX1 + ( (hoverX2-hoverX1)-text.getLocalBounds().width )/2;
        hoverTextY = hoverY1 + ( (hoverY2-hoverY1)-text.getLocalBounds().height )/2;
        hoverBoxStrTrigger = true;
        hoverBoxStr = str;
    }


    void setHoverTextOffset(float x, float y)
    {
        hoverTextX = hoverTextX + x;
        hoverTextY = hoverTextY + y;
    }


    void setHoverOutline(short r, short g, short b, short a=255, float width=1)
    {
        hoverOutlineClr = sf::Color(r,g,b,a);
        hoverOutlineWidth = width;
        hoverOutlineTrigger = true;
    }


    void trackClick(sf::Event& event)
    {
        if ( isClickable && ((this->isHovered() && event.type == sf::Event::MouseButtonPressed && event.mouseButton.button==sf::Mouse::Left) || (sf::Keyboard::isKeyPressed(clickKey))) )
        {
            realClick = true;
            IsClicked = true;
            sound.play();
        }
        else if( isClickable && ((this->isHovered() && event.type == sf::Event::MouseButtonReleased && event.mouseButton.button==sf::Mouse::Left) || (event.key.code==clickKey)) )
            realClick = false;
    }


    void setClickable(bool val)
    {
        isClickable = val;
    }


    void setClickColor(short r, short g, short b, short a=255)
    {
        clickClr = sf::Color(r,g,b,a);
        clickClrTrigger = true;
    }


    void setClickSound(sf::SoundBuffer &buffer)
    {
        soundBuffer = buffer;
        sound.setBuffer(buffer);
    }


    void setClickDimensions(float X1, float Y1, float X2, float Y2)
    {
        clickX1 = X1; clickX2 = X2; clickY1 = Y1; clickY2 = Y2;
        clickDeimensionsTrigger = true;
    }


    void Draw()
    {

        if(hoverDimensionsTrigger)
        {
            this->setDimensions(x1,y1,x2,y2);

            if( this->isHovered())
            {
                Box.setSize(sf::Vector2f(hoverX2-hoverX1,hoverY2-hoverY1));
                Box.setPosition(hoverX1,hoverY1);
            }
        }

        if(hoverBoxStrTrigger)
        {
            text.setString(boxStr);
            text.setPosition(textX,textY);

            if(this->isHovered())
            {
                text.setString(hoverBoxStr);
                text.setPosition(hoverTextX,hoverTextY);
            }
        }

        if(hoverTextClrTrigger)
        {
            this->setTextColor(textClr.r,textClr.g,textClr.b,textClr.a);

            if( this->isHovered() )
                text.setFillColor(hoverTextClr);
        }

        if(hoverOutlineTrigger)
        {
            this->setOutline(outlineClr.r,outlineClr.g,outlineClr.b,outlineClr.a,outlineWidth);

            if( this->isHovered() )
            {
                Box.setOutlineColor(hoverOutlineClr);
                Box.setOutlineThickness(hoverOutlineWidth);
            }
        }

        if(hoverClrTrigger)
        {
            if(this->isHovered())
            {
                rT=startRTime;
                Box.setFillColor(sf::Color(hoverClr.r,hoverClr.g,hoverClr.b,hT));
                if(hT<hoverClr.a)
                    hT+=transitionTime;
            }
            else
            {
                hT=startHTime;
                Box.setFillColor(sf::Color(Clr.r,Clr.g,Clr.b,rT));
                if(rT<hoverClr.a)
                    rT+=transitionTime;
            }
        }

        if(clickDeimensionsTrigger)
        {
            if(!hoverDimensionsTrigger)
                this->setDimensions(x1,y1,x2,y2);

            if(realClick)
            {
                Box.setSize(sf::Vector2f(clickX2-clickX1,clickY2-clickY1));
                Box.setPosition(clickX1,clickY1);
            }
        }

        if(clickClrTrigger)
        {
            if(!hoverClrTrigger)
                Box.setFillColor(Clr);
            if(realClick)
                Box.setFillColor(clickClr);
        }

        win->draw(Box);
        win->draw(text);
        IsClicked = false;
    }





private:

    sf::RenderWindow* win;
    sf::Font font;
    sf::SoundBuffer soundBuffer;
    sf::Sound sound;

    float x1,y1,x2,y2,  hoverX1,hoverY1,hoverX2,hoverY2,    clickX1,clickX2,clickY1,clickY2;
    float textX, textY, hoverTextX,hoverTextY;
    sf::String boxStr, hoverBoxStr;
    sf::Color Clr, hoverClr, clickClr;
    sf::Color textClr, hoverTextClr;
    sf::Color outlineClr, hoverOutlineClr;
    float outlineWidth, hoverOutlineWidth;
    float transitionTime, hT = 30, rT = 30, startRTime=30, startHTime = 30;
    sf::Keyboard::Key clickKey = sf::Keyboard::Return;

    bool hoverDimensionsTrigger = false;
    bool hoverClrTrigger = false;
    bool hoverBoxStrTrigger = false;
    bool hoverTextClrTrigger = false;
    bool hoverOutlineTrigger = false;
    bool clickClrTrigger = false;
    bool isClickable = true;
    bool realClick = false;
    bool clickDeimensionsTrigger = false;






protected:

    // To access the shape and text properties by the inherited/Daughter class
    sf::RectangleShape Box; //to access the shape properties
    sf::Text text; //to access the text such as obj.text.sfmlProp etc.

};

#endif // STYLING_H_INCLUDED
