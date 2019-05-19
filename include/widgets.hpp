#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"

class Widget {
protected:
    int _x, _y, _sx, _sy;
    //int _menuID;
public:
    Widget(int x, int y, int sx, int sy);
    virtual bool is_selected(int mouse_x, int mouse_y);
    virtual void draw() = 0;
    virtual void handle(genv::event ev) = 0;
    virtual std::string myInfo() = 0;
    bool in_focus=false;
    virtual void lostFocus() = 0;
    virtual ~Widget();
};
#endif // WIDGETS_HPP_INCLUDED
