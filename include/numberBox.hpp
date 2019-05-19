#ifndef NUMBERBOX_HPP
#define NUMBERBOX_HPP

#include "graphics.hpp"
#include "widgets.hpp"


class numberBox : public Widget
{
    public:
        numberBox(int x, int y, int sx, int sy, int myMax, int myMin);
        void draw() override;
        void handle(genv::event ev) override;
        std::string myInfo() override;
        bool is_selected(int mouse_x, int mouse_y) override;
        void lostFocus() override;

    protected:
        int _numb=0;
        int _myMax;
        int _myMin;
        int c2=150;
        int c3=150;
    private:
};

#endif // NUMBERBOX_HPP
