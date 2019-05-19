#include "myLevel.hpp"
//#include "graphics.hpp"
#include <iostream>

using namespace genv;

myLevel::myLevel(int x, int y) : Widget(x,y,7*60,6*60)
{
    //ctor
}

void myLevel::draw()
{
    gout << move_to(_x,_y) << color(lc_r,lc_g,lc_b) << box(_sx,_sy);

    int r=25;

    int cx=_x+30;
    int cy=_y+30;

    for(int i=5;i>-1;i--)
    {
        if(_level[i][column]==0)
        {
            lastZero=i;
            break;
        }
    }
    for(int i=0; i<7; i++)
    {
        cy=_y+30;
        for(int j=0; j<6; j++)
        {
            if(lastZero==j && i==column)
            {
                gout << color(100,0,0);
            }
            else
            {
                gout << color(0,0,0);
            }
            ///Kör
            for(int y=cy-r; y<cy+r; y++)
            {
                for(int x=cx-r; x<cx+r; x++)
                {
                    if(  ( (x-cx)*(x-cx)+(y-cy)*(y-cy) ) <r*r)
                    {
                        gout << move_to(x,y) << dot;
                    }
                }
            }
            cy+=60;
        }
        cx+=60;
    }
}

void myLevel::handle(genv::event ev)
{
    if(ev.type==ev_mouse)
    {
        for(int i=0; i<7; i++)
        {
            if(ev.pos_x>_x+i*60 && ev.pos_x<_x+60+i*60 && ev.pos_y>_y && ev.pos_y<_sy)
            {
                column=i;
                std::cout << column << std::endl;
            }
        }
    }
}

std::string myLevel::myInfo()
{
    return "";
}

void myLevel::lostFocus()
{

}



void myLevel::setMyColor(int r, int g, int b)
{
    lc_r=r;
    lc_g=g;
    lc_b=b;
}
