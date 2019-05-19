#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "widgets.hpp"
#include "graphics.hpp"


class button : public Widget
{
    public:
        button(int x, int y, int sx, int sy);
        void draw() override;
        void handle(genv::event ev) override;
        virtual void action() =0;
        bool is_selected(int mouse_x, int mouse_y) override;
    protected:

    private:
};

#endif // BUTTON_HPP
