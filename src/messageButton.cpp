#include "messageButton.hpp"
#include "graphics.hpp"

using namespace genv;

messageButton::messageButton(int x, int y, int sx, int sy) : button(x,y,sx,sy)
{

}

void messageButton::action()
{

}

fvptrButton::fvptrButton(firstWindow *w, int x, int y, int sx, int sy, void(*fvptr)(firstWindow *)) : button(x,y,sx,sy), myParent(w), fv(fvptr) {}

void fvptrButton::action()
{
    fv(myParent);
}

functorButton::functorButton(firstWindow *w, int x, int y, int sx, int sy, std::string label, std::function<void()>myFuggveny) : button(x,y,sx,sy), myParent(w), _myFuggveny(myFuggveny)
{
    _label=label;
}

std::string messageButton::myInfo(){return "";}

std::string fvptrButton::myInfo(){return "";}

std::string functorButton::myInfo(){return "";}

void functorButton::lostFocus(){}

void fvptrButton::lostFocus(){}

void messageButton::lostFocus(){}

void functorButton::action()
{
    _myFuggveny();
}

void functorButton::draw()
{
    gout << color(100,100,100) << move_to(_x,_y) << box(_sx,_sy);
    gout << color(200,200,200) << move_to(_x+4,_y+4) << box(_sx-8,_sy-8);
    gout << color(0,0,100) << move_to(_x+6,_y+_sy-6) << text(_label);
}
