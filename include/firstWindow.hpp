#ifndef FIRSTWINDOW_HPP
#define FIRSTWINDOW_HPP

#include "parentWindow.hpp"
#include "widgets.hpp"

#include "numberBox.hpp"
#include "selectBox.hpp"
#include "textWindow.hpp"
#include "messageButton.hpp"
#include "textbox.hpp"

#include "myLevel.hpp"

#include <iostream>

using namespace std;

class messageButton;
class functorButton;
class fvptrButton;

class firstWindow : public parentWindow
{
    public:
        firstWindow(int X, int Y);
        void theMainMenu(){w=&menuWidgets;};
        void theGame(){w=&gameWidgets;};
        void theOptions(){w=&optiWidgets;};
        void writeText();
        virtual ~firstWindow();
        void setBgColors();

    protected:
        ///Mainmenu
        std::vector<Widget*> menuWidgets;
        std::vector<Widget*> gameWidgets;
        std::vector<Widget*> optiWidgets;

        functorButton * player2;
        functorButton * opti;
        functorButton * player1;
        functorButton * exitButton;

        textbox * cSoon;

        ///Options
        selectBox * backgroundColor;
        selectBox * levelColor;
        functorButton * goBack;
        functorButton * accept;

        ///Level
        //canvas, körrajzolás vagy képbol .kep
        textbox * nextPlayer;
        myLevel * level;

            ///Hatter

        //int palya[6][7]={};
};

#endif // FIRSTWINDOW_HPP
