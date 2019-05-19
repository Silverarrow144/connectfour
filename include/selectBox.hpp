#ifndef SELECTBOX_HPP
#define SELECTBOX_HPP

#include "graphics.hpp"
#include "widgets.hpp"
#include <vector>


class selectBox : public Widget
{
    public:
        selectBox(int x, int y, int sx, int sy, int dropDownLength, std::vector<std::string> myList);
        void draw() override;
        void handle(genv::event ev) override;
        std::string myInfo() override;
        bool is_selected(int mouse_x, int mouse_y) override;
        void lostFocus() override;

    protected:
        std::vector<std::string>_list;
        int _dropDownLength;
        int _highlight=0;
        int _toWrite=0;
        int _firstToDraw=0;
        bool _dropDown=false;
        int c1=150;
        int c2=150;
    private:
};

#endif // SELECTBOX_HPP
