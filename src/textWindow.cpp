#include "textWindow.hpp"
#include "graphics.hpp"
#include <iostream>
#include <fstream>

using namespace genv;
using namespace std;

textWindow::textWindow(int x, int y, int sx, int sy, std::string fileName) : Widget(x,y,sx,sy)
{
    _fileName=fileName;

    std::ifstream myFile;
    myFile.open(_fileName);
    if(myFile.is_open())
    {
        while ( getline (myFile,_oneLine) )
        {
            if(gout.twidth(_oneLine)>longestLine)
            {
                longestLine=gout.twidth(_oneLine);
            }
            lineCount++;
        }
        myFile.close();
    }
    myFile.open(_fileName);
    myCanvas.open(margo+margo+longestLine,margo+(lineCount+1)*(3+gout.cascent()));
    myCanvas << color(255,255,255) << move_to(0,0) << box(margo+margo+longestLine,margo+(lineCount+1)*(3+gout.cascent()));
    lineCount=0;
    if(myFile.is_open())
    {
        while ( getline (myFile,_oneLine) )
        {
            myCanvas << color(0,0,0) << move_to(margo,margo+(lineCount+1)*(3+gout.cascent())) << text(_oneLine);
            lineCount++;
        }
        myFile.close();
    }
}

void textWindow::draw()
{
    int c_1=0;
    int c_2=0;
    if(in_focus)
    {
        c_1=255;
        c_2=150;
    }
    else
    {
        c_1=150;
        c_2=100;
    }
    gout << color(c_1,150,150) << move_to(_x,_y) << box(_sx,_sy);
    gout << move_to(_x+4,_y+4) << color(250,250,250) << box(_sx-8,_sy-8);
    gout << move_to(_x+4,_y+4) << color(c_2,100,100) << box(_sx-8,30);
    gout << move_to(_x+8,_y+8+gout.cascent()) << color(255,255,255) << text(_fileName);

    ///Ablak
    gout << stamp(myCanvas,min(_stampx,(margo+margo+longestLine-_sx)),min(_stampy,margo+(lineCount+1)*(3+gout.cascent())),_sx-8,_sy-38,_x+4,_y+30);
}

void textWindow::handle(event ev)
{
    if(ev.type==ev_key)
    {
        ///Lenyomás közben lépked

        ///Right
        if(ev.keycode==key_right)
        {
            is_right=true;
        }
        else if(ev.keycode==-key_right)
        {
            is_right=false;
        }

        ///Left
        if(ev.keycode==key_left)
        {
            is_left=true;
        }
        else if(ev.keycode==-key_left)
        {
            is_left=false;
        }

        ///Down
        if(ev.keycode==key_down)
        {
            is_down=true;
        }
        else if(ev.keycode==-key_down)
        {
            is_down=false;
        }

        ///Up
        if(ev.keycode==key_up)
        {
            is_up=true;
        }
        else if(ev.keycode==-key_up)
        {
            is_up=false;
        }
    }

    if(ev.type==ev_timer)
    {
        ///Right
        if(is_right && _stampx<(margo+margo+longestLine-_sx))
        {
            _stampx+=2;
        }

        ///Left
        if(is_left && _stampx>0)
        {
            _stampx-=2;
        }

        ///Down
        if(is_down && _stampy<(margo+(lineCount+1)*(3+gout.cascent())-_sy+30))
        {
            _stampy+=2;
        }

        ///Up
        if(is_up && _stampy>0)
        {
            _stampy-=2;
        }
    }
}

void textWindow::lostFocus() {}

std::string textWindow::myInfo()
{
    return "";
}

bool textWindow::is_selected(int mouse_x, int mouse_y)
{
    return mouse_x>_x && mouse_x<_x+_sx && mouse_y>_y && mouse_y<_y+_sy;
}
