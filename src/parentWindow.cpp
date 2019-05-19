#include "parentWindow.hpp"
#include <fstream>

using namespace genv;
using namespace std;

parentWindow::parentWindow(int X, int Y)
{
    _X=X;
    _Y=Y;
}

/*parentWindow::~parentWindow()
{
    for(Widget *widg: *w)
    {
        delete widg;
    }
}*/

void parentWindow::clearit()
{
    gout << move_to(0,0) << color(bc_r,bc_g,bc_b) << box(_X,_Y);
}

void parentWindow::event_loop()
{
    event ev;
    gin.timer(40);
    int focus = -1;
    while(gin >> ev && ev.keycode!=key_escape && !isQuit)
    {
        clearit();


        for(Widget *widg: *w)
        {
            widg->draw();
        }
        gout << refresh;

        if (ev.type == ev_mouse && ev.button==btn_left)
        {
            for (size_t i=0; i<w->size(); i++)
            {
                if (w->at(i)->is_selected(ev.pos_x, ev.pos_y))
                {
                    focus = i;
                    for(size_t j=0; j<w->size(); j++)
                    {
                        w->at(j)->in_focus=false;
                    }
                    w->at(i)->in_focus=true;
                }
                else
                {
                    focus=-1;
                    w->at(i)->in_focus=false;
                    w->at(i)->lostFocus();
                    for(size_t j=0; j<w->size(); j++)
                    {
                        if(w->at(j)->in_focus)
                        {
                            focus=j;
                        }
                    }
                }
            }
            //w->at(focus)->handle(ev);
        }
        if (focus!=-1)
        {
            w->at(focus)->handle(ev);
        }
        /*if(ev.type==ev_key && ev.keycode==key_space)
        {
            ofstream myfile;
            myfile.open ("results.txt");
            for(int i=0; i<w->size(); i++)
            {
                myfile << w->at(i)->myInfo() << ' ';
            }
            myfile.close();
        }*/

    }
}
