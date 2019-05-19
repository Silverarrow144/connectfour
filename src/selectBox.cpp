#include "selectBox.hpp"
#include "graphics.hpp"
#include <vector>
#include <iostream>

using namespace genv;

selectBox::selectBox(int x, int y, int sx, int sy, int dropDownLength, std::vector<std::string> myList) : Widget(x,y,sx,sy)
{
    _list=myList;
    _dropDownLength=dropDownLength;
}

bool selectBox::is_selected(int mouse_x, int mouse_y)
{
    if(_dropDown)
    {
        return mouse_x>_x && mouse_x<_x+_sx && mouse_y>_y && mouse_y<_y+_sy+40*_dropDownLength;
    }
    else
    {
        return mouse_x>_x && mouse_x<_x+_sx && mouse_y>_y && mouse_y<_y+_sy;
    }
}

std::string selectBox::myInfo()
{
    std::string _s;
    _s=_list[_toWrite];
    return _s;
}

void selectBox::handle(event ev)
{
    if  (ev.type==ev_mouse)
    {
        if(ev.button==btn_wheelup && _firstToDraw>0)
        {
            _firstToDraw--;
        }
        if(ev.button==btn_wheeldown && _firstToDraw<_list.size()-_dropDownLength)
        {
            _firstToDraw++;
        }

        if(ev.button==btn_left)
        {
            if((ev.pos_x>_x+_sx-24) && (ev.pos_x<_x+_sx-6) && (ev.pos_y>_y+5) && (ev.pos_y<_y+_sy-6))
            {
                c2=255;
            }
            if (_dropDown && ( (ev.pos_x<_x+_sx-8  &&  ev.pos_x>_x+4 && ev.pos_y>_y+_sy && ev.pos_y<_y+_sy+40*_dropDownLength) ) )
            {
                _dropDown=false;
                if(ev.pos_x<_x+_sx-8  &&  ev.pos_x>_x+4 && ev.pos_y>_y+_sy && ev.pos_y<_y+_sy+40*_dropDownLength)
                {
                    _toWrite=_highlight+_firstToDraw;
                }
            }
            if(  (ev.pos_x>_x+_sx-24) && (ev.pos_x<_x+_sx-6) && (ev.pos_y>_y+5) && (ev.pos_y<_y+_sy-6))
            {
                _dropDown=!_dropDown;
            }

        }

        if(ev.button==-btn_left)
        {
            c2=150;
        }
    }

    if(_dropDown)
    {
        for(int i=0; i<_dropDownLength; i++)
        {
            if(  ev.pos_x<_x+_sx-8  &&  ev.pos_x>_x+4   &&   ev.pos_y<_y+4+_sy+40+40*i   &&   ev.pos_y>_y+4+_sy+40*i    )
            {
                _highlight=i;
            }
        }
    }
}

void selectBox::draw()
{
    if(in_focus)
    {
        c1=255;
        ///Lenyilo
        if(_dropDown)
        {
            gout << move_to(_x,_y+_sy) << color(150,150,c1) << box(_sx,40*_dropDownLength);
            gout << move_to(_x+4,_y+4+_sy) << color(250,250,250) << box(_sx-8,40*_dropDownLength-8);
            gout << move_to(_x+4,_y+4+_sy+40*_highlight) << color(0,0,0);
            if(_highlight+1<_dropDownLength)
            {
                gout << box(_sx-8,40);
            }
            else
            {
                gout << box(_sx-8,32);
            }
            ///Leszöveg
            for(int i=0; i<_dropDownLength; i++)
            {
                gout << move_to(_x+8,_y+18+_sy+i*40) << color(0,0,0) << text(_list[i+_firstToDraw]);
            }
            gout << move_to(_x+8,_y+18+_sy+_highlight*40) << color(255,255,255) << text(_list[_highlight+_firstToDraw]);
        }
    }
    else
    {
        c1=150;
    }
    gout << move_to(_x,_y) << color(150,150,c1) << box(_sx,_sy);
    gout << move_to(_x+4,_y+4) << color(250,250,250) << box(_sx-8,_sy-8);

    ///Gomb
    gout << move_to(_x+_sx-6,_y+5) << color(150,150,c2) << box_to(_x+_sx-24,_y+_sy-6);
    gout << move_to(_x+_sx-22,_y+_sy-28) << color(0,0,0) << line(8,8) << line(8,-8);

    ///Lista
    gout << move_to(_x+20,_y+25) << color(0,0,0) << text(_list[_toWrite]);
}

void selectBox::lostFocus()
{
    _dropDown=false;
}
