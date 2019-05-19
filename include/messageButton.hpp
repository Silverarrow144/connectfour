#ifndef MESSAGEBUTTON_HPP
#define MESSAGEBUTTON_HPP

#include "button.hpp"
#include "firstWindow.hpp"
#include <functional>

class firstWindow;

class messageButton : public button
{
    public:
        messageButton(int x, int y, int sx, int sy);
        void action() override;
        std::string myInfo() override;
        void lostFocus() override;
    protected:

    private:
};

class fvptrButton: public button
{
    firstWindow *myParent;
    void (*fv)(firstWindow*);
public:
    fvptrButton(firstWindow *w, int x, int y, int sx, int sy, void (*fvptr)(firstWindow *));
    void action() override;
    std::string myInfo() override;
    void lostFocus() override;
};

class functorButton : public button
{
    firstWindow *myParent;
    std::function<void()> _myFuggveny;

    std::string _label;
public:
    functorButton(firstWindow *w, int x, int y, int sx, int sy, std::string label, std::function<void()>myFuggveny);
    std::string myInfo() override;
    void action() override;
    void lostFocus() override;
    void draw() override;
};

#endif // MESSAGEBUTTON_HPP
