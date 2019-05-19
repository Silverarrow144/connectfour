#include "numberBox.hpp"
#include <string>

using namespace genv;

numberBox::numberBox(int x, int y, int sx, int sy, int myMax, int myMin) : Widget(x,y,sx,sy)
{
    _myMax=myMax;
    _myMin=myMin;
}

std::string numberBox::myInfo()
{
    std::string _s;
    _s=std::to_string(_numb);
    return _s;
}

bool numberBox::is_selected(int mouse_x, int mouse_y)
{
    return mouse_x>_x && mouse_x<_x+_sx && mouse_y>_y && mouse_y<_y+_sy;
}

void numberBox::handle(genv::event ev)
{
    ///Fel
    if(  ev.pos_x>(_x+_sx-24) && ev.pos_x<(_x+_sx-6) && ev.pos_y>(_y+5) && ev.pos_y<(_y+_sy/2-1) && ev.type==ev_mouse && ev.button==btn_left)
    {
        c2=200;
        if(_numb<_myMax)
           {
               _numb++;
           }
    }
    else
    {
        c2=150;
    }
    ///Le
    if(  ev.pos_x>(_x+_sx-24) && ev.pos_x<(_x+_sx-6) && ev.pos_y>(_y+_sy-_sy/2+1) && ev.pos_y<(   _y+_sy-6) && ev.type==ev_mouse && ev.button==btn_left )
    {
        c3=200;
        if(_numb>_myMin)
        {_numb--;}
    }
    else
    {
        c3=150;
    }

    if(in_focus && ev.type==ev_key)
    {
        if(_numb<_myMax && ev.keycode==key_up)
        {
            _numb++;
        }
        if(_numb>_myMin && ev.keycode==key_down)
        {
            _numb--;
        }

        if(_numb>_myMin+9 && ev.keycode==key_pgdn)
        {
            _numb-=10;
        }
        if(_numb<_myMax-10 && ev.keycode==key_pgup)
        {
            _numb+=10;
        }
    }
}

void numberBox::draw()
{
    int cl=0;
    if(in_focus)
    {
        cl=255;
    }
    else
    {
        cl=150;
    }
    gout << move_to(_x,_y) << color(150,cl,150) << box(_sx,_sy);
    gout << move_to(_x+4,_y+4) << color(250,250,250) << box(_sx-8,_sy-8);
    ///Szám
    gout << move_to(_x+_sx-40-gout.twidth(std::to_string(_numb)),_y+25) << color(0,0,0) << text(std::to_string(_numb));
    ///Gombok
    gout << move_to(_x+_sx-6,_y+5) << color(150,c2,150) << box_to(_x+_sx-24,_y+_sy/2-1);///Fel
    gout << move_to(_x+_sx-6,_y+_sy-6) << color(150,c3,150) << box_to(_x+_sx-24,_y+_sy-_sy/2+1);///Le
    ///Nyilak
    gout << move_to(_x+_sx-22,_y+18) << color(0,0,0) << line(8,-8) << line(8,8);///Fel
    gout << move_to(_x+_sx-22,_y+_sy-18) << color(0,0,0) << line(8,8) << line(8,-8);///Le
}

void numberBox::lostFocus(){}
