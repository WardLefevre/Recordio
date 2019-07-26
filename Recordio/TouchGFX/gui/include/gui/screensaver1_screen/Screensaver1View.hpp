#ifndef SCREENSAVER1_VIEW_HPP
#define SCREENSAVER1_VIEW_HPP

#include <gui_generated/screensaver1_screen/Screensaver1ViewBase.hpp>
#include <gui/screensaver1_screen/Screensaver1Presenter.hpp>

class Screensaver1View : public Screensaver1ViewBase
{
public:
    Screensaver1View();
    virtual ~Screensaver1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
    
protected:
    int16_t hour;
    int16_t minute;
    int16_t tickCount;
    int16_t addStart;
    int16_t addEnd;
};

#endif // SCREENSAVER1_VIEW_HPP
