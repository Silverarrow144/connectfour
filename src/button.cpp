#include "button.hpp"
#include "graphics.hpp"
using namespace genv;

button::button(int x, int y, int sx, int sy) : Widget(x,y,sx,sy)
{

}

void button::draw()
{
    gout << color(100,100,100) << move_to(_x,_y) << box(_sx,_sy);
    gout << color(200,200,200) << move_to(_x+4,_y+4) << box(_sx-8,_sy-8);
}

void button::handle(event ev)
{
    if(ev.type==ev_mouse && ev.button==btn_left && is_selected(ev.pos_x,ev.pos_y))
    {
        action();
    }
}

bool button::is_selected(int mouse_x, int mouse_y)
{
    return mouse_x>_x && mouse_x<_x+_sx && mouse_y>_y && mouse_y<_y+_sy;
}


