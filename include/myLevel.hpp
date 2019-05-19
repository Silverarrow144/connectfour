#ifndef MYLEVEL_HPP
#define MYLEVEL_HPP

#include "widgets.hpp"
#include "graphics.hpp"


class myLevel : public Widget
{
    public:
        myLevel(int x, int y);
        void draw() override;
        void handle(genv::event ev) override;
        std::string myInfo() override;
        void lostFocus() override;
        void setMyColor(int r, int g, int b);
    protected:
        int _level[6][7]={};
        int lc_r=0;
        int lc_g=0;
        int lc_b=240;
        int column=0;
        int lastZero;

    private:
};

#endif // MYLEVEL_HPP
