#include "textbox.hpp"
#include "graphics.hpp"
#include <string>

using namespace genv;

textbox::textbox(int x, int y, std::string tx): Widget(x,y,gout.twidth(tx)+5,30), _tx(tx)
{
}

std::string textbox::myInfo(){return _tx;}

bool textbox::is_selected(int, int) {return false;}

void textbox::handle(event) {}

void textbox::draw()
{
    gout << move_to(_x,_y) << color(255,255,255) << text(_tx);
}

void textbox::lostFocus(){}
