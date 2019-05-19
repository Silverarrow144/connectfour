#ifndef TEXTWINDOW_HPP
#define TEXTWINDOW_HPP

#include "widgets.hpp"
#include "graphics.hpp"
#include <string>
#include <iostream>

class textWindow : public Widget
{
    public:
        textWindow(int x, int y, int sx, int sy, std::string fileName);
        void draw() override;
        void handle(genv::event ev) override;
        std::string myInfo() override;
        bool is_selected(int mouse_x, int mouse_y) override;
        void lostFocus() override;

    protected:
        std::string _oneLine;
        std::string _fileName;
        genv::canvas myCanvas;

        bool is_right=false;
        bool is_left=false;
        bool is_up=false;
        bool is_down=false;

        int _stampx=0;
        int _stampy=0;
        int margo=10;
        int longestLine=0;
        int lineCount=0;

    private:
};

#endif // TEXTWINDOW_HPP
