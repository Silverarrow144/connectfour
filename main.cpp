#include "graphics.hpp"
#include "parentWindow.hpp"
#include "firstWindow.hpp"

using namespace genv;

int main()
{
    firstWindow * myWindow = new firstWindow(600,600);
    gout.open(myWindow->get_X(),myWindow->get_Y());
    myWindow->event_loop();
    delete myWindow;
    return 0;
}
