#include "firstWindow.hpp"

#include "graphics.hpp"

#include <vector>
#include <string>
#include <iostream>
#include <fstream>

using namespace std;
using namespace genv;

firstWindow::firstWindow(int X, int Y) : parentWindow(X,Y)
{
    _X=X;
    _Y=Y;

    int centerX=_X/2-80;
    w=&menuWidgets;

    ///Main menu
    player2 = new functorButton(this,centerX,100,160,40,"Human VS Human",[this]()
    {
        this->theGame();
    });
    opti = new functorButton(this,centerX,200,160,40,"Opciok",[this]()
    {
        this->theOptions();
    });
    cSoon = new textbox(centerX+180,180,"");
    player1 = new functorButton(this,centerX,150,160,40,"Human VS Computer",[this](){this->writeText();});

    exitButton = new functorButton(this,centerX,280,160,40,"Exit",[this](){this->isQuit=true;});




    ///Options
    goBack = new functorButton(this,0,0,80,30,"Back",[this]()
    {
        this->theMainMenu();
    });



    ///Game
    nextPlayer= new textbox(200,500,"Next player: ");
    level = new myLevel(60,60);

    menuWidgets.push_back(player2);
    menuWidgets.push_back(opti);
    menuWidgets.push_back(player1);
    menuWidgets.push_back(cSoon);
    menuWidgets.push_back(exitButton);

    gameWidgets.push_back(nextPlayer);
    gameWidgets.push_back(goBack);
    gameWidgets.push_back(level);

    //optiWidgets.push_back(nextPlayer);
    optiWidgets.push_back(goBack);


    vector<string> lista {"Zöld", "Piros", "Sárga", "Kék", "Szürke", "Fekete"};
    vector<string> listb {"Halványzöld", "Pink", "Narancs", "Halványkék"};
    backgroundColor = new selectBox(100,100,150,40,4,lista);
    levelColor = new selectBox(300,100,150,40,4,listb);
    accept = new functorButton(this,500,100,80,40,"Alkalmaz",[this]() {this->setBgColors();this->setLevelColors();});

    optiWidgets.push_back(backgroundColor);
    optiWidgets.push_back(levelColor);
    optiWidgets.push_back(accept);

    //cout << menuWidgets.size();
    //cout << optionsWidgets.size();
    //cout << gameWidgets.size();
}

firstWindow::~firstWindow()
{
    /*for(Widget *widg: menuWidgets)
    {
        delete widg;
    }
    for(Widget *widg: optiWidgets)
    {
        delete widg;
    }
    for(Widget *widg: gameWidgets)
    {
        delete widg;
    }*/
    for (int i=0;i<menuWidgets.size();i++)
    {
        if(menuWidgets[i]){
        delete menuWidgets[i];
        }
    }
    for (int i=0;i<optiWidgets.size();i++)
    {
        if(optiWidgets[i]){
        delete optiWidgets[i];
        }
    }
    for (int i=0;i<gameWidgets.size();i++)
    {
        if(gameWidgets[i]){
        delete gameWidgets[i];
        }
    }
}

void firstWindow::setBgColors()
{
    if(backgroundColor->myInfo()=="Zöld"){
        this->bc_r=0;
        this->bc_g=150;
        this->bc_b=0;
    }
    else if(backgroundColor->myInfo()=="Piros"){
        this->bc_r=150;
        this->bc_g=0;
        this->bc_b=0;
    }
    else if(backgroundColor->myInfo()=="Sárga"){
        this->bc_r=150;
        this->bc_g=150;
        this->bc_b=0;
    }
    else if(backgroundColor->myInfo()=="Kék"){
        this->bc_r=0;
        this->bc_g=0;
        this->bc_b=150;
    }
    else if(backgroundColor->myInfo()=="Szürke"){
        this->bc_r=130;
        this->bc_g=130;
        this->bc_b=130;
    }
    else if(backgroundColor->myInfo()=="Fekete"){
        this->bc_r=0;
        this->bc_g=0;
        this->bc_b=0;
    }
}

void firstWindow::writeText()
{
    cSoon->setText("Coming Soon!");
}

void firstWindow::setLevelColors()
{
    if(levelColor->myInfo()=="Halványzöld")
    {
        level->setMyColor(179,255,204);

    }
    else if(levelColor->myInfo()=="Pink")
    {
        level->setMyColor(255,179,217);

    }
    else if(levelColor->myInfo()=="Narancs")
    {
        level->setMyColor(255,153,0);

    }
    else if(levelColor->myInfo()=="Halványkék")
    {
        level->setMyColor(0,191,255);

    }
}
