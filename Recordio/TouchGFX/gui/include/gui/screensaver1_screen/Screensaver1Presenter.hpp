#ifndef SCREENSAVER1_PRESENTER_HPP
#define SCREENSAVER1_PRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class Screensaver1View;

class Screensaver1Presenter : public Presenter, public ModelListener
{
public:
    Screensaver1Presenter(Screensaver1View& v);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~Screensaver1Presenter() {};
    
    void saveHour(int16_t hour)
    {
        model->saveHour(hour);
    }

    void saveMinute(int16_t minute)
    {
        model->saveMinute(minute);
    }

    int16_t getHour()
    {
        return model->getHour();
    }

    int16_t getMinute()
    {
        return model->getMinute();
    }

private:
    Screensaver1Presenter();

    Screensaver1View& view;
};


#endif // SCREENSAVER1_PRESENTER_HPP
