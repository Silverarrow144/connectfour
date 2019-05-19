#ifndef PARENTWINDOW_HPP
#define PARENTWINDOW_HPP

#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>


class parentWindow
{
    public:
        parentWindow(int X, int Y);
        void event_loop();
        void clearit();
        int get_X(){return _X;};
        int get_Y(){return _Y;};
    protected:
        int _X, _Y;
        std::vector<Widget*>* w;

        int bc_r=0;
        int bc_g=150;
        int bc_b=0;

        bool isQuit=false;
    private:
};

#endif // PARENTWINDOW_HPP
