#include "myLevel.hpp"
//#include "graphics.hpp"

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

    gout << color(0,0,0);
    for(int i=0; i<7; i++)
    {
        cy=_y+30;
        for(int j=0; j<6; j++)
        {

            for(int y=cy-r; y<cy+r; y++)
            {
                for(int x=cx-r; x<cx+r; x++)
                {
                    if(  ( (x-cx)*(x-cx)+(y-cy)*(y-cy) ) <r*r)
                    {
                        //std::cout<<"0";
                        gout << move_to(x,y) << dot;
                    }
                }
            }
            cy+=60;
        }
        cx+=60;
    }

    /*for(int y=cy-r; y<cy+r; y++)
    {
        for(int x=cx-r; x<cx+r; x++)
        {
            if(  ( (x-cx)*(x-cx)+(y-cy)*(y-cy) ) <r*r)
            {
                //std::cout<<"0";
                gout << move_to(x,y) << dot;
            }
        }
    }*/
}

void myLevel::handle(genv::event ev)
{

}

std::string myLevel::myInfo()
{
    return "";
}

void myLevel::lostFocus()
{

}

/*void myLevel::setLvlColors()
{
    if(levelColor->myInfo()=="Halványzöld")
    {
        lc_r=179;
        lc_g=255;
        lc_b=204;
    }
    else if(levelColor->myInfo()=="Pink")
    {
        lc_r=255;
        lc_g=179;
        lc_b=217;
    }
    else if(levelColor->myInfo()=="Narancs")
    {
        lc_r=255;
        lc_g=153;
        lc_b=0;
    }
    else if(levelColor->myInfo()=="Halványkék")
    {
        lc_r=0;
        lc_g=191;
        lc_b=255;
    }
}*/
