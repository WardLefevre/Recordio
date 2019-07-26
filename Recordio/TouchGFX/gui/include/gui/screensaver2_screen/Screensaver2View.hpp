#ifndef SCREENSAVER2_VIEW_HPP
#define SCREENSAVER2_VIEW_HPP

#include <gui_generated/screensaver2_screen/Screensaver2ViewBase.hpp>
#include <gui/screensaver2_screen/Screensaver2Presenter.hpp>

class Screensaver2View : public Screensaver2ViewBase
{
public:
    Screensaver2View();
    virtual ~Screensaver2View() {}
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

#endif // SCREENSAVER2_VIEW_HPP
