#ifndef TEXTBOX_HPP
#define TEXTBOX_HPP
#include <string>
#include "graphics.hpp"
#include "widgets.hpp"

class textbox : public Widget {
    public:
        textbox(int x, int y, std::string tx);
        void draw() override;
        void handle(genv::event ev) override;
        std::string myInfo() override;
        bool is_selected(int mouse_x, int mouse_y) override;
        void lostFocus() override;
        void setText(std::string s){_tx=s;}
    protected:
        std::string _tx;
    private:
};

#endif // TEXTBOX_HPP
