#include <gui/screensaver2_screen/Screensaver2View.hpp>

Screensaver2View::Screensaver2View()
{

}

void Screensaver2View::setupScreen()
{
    Screensaver2ViewBase::setupScreen();
    
    hour = presenter->getHour();
    minute = presenter->getMinute();

    Unicode::snprintf(textClockBuffer1, TEXTCLOCKBUFFER1_SIZE, "%02d", hour);
    Unicode::snprintf(textClockBuffer2, TEXTCLOCKBUFFER2_SIZE, "%02d", minute);
}

void Screensaver2View::tearDownScreen()
{
    //Screensaver2ViewBase::tearDownScreen();
    
    presenter->saveHour(hour);
    presenter->saveMinute(minute);

    //Screensaver1View::tearDownScreen();
    Screensaver2ViewBase::tearDownScreen();
}

void Screensaver2View::handleTickEvent()
{
    if (tickCount == 60)
    {
        minute++;
        hour = (hour + (minute / 60)) % 24;
        minute %= 60;

        Unicode::snprintf(textClockBuffer1, TEXTCLOCKBUFFER1_SIZE, "%02d", hour);
        Unicode::snprintf(textClockBuffer2, TEXTCLOCKBUFFER2_SIZE, "%02d", minute);

        textClock.invalidate();

        tickCount = 0;
    }

    if (1){
      tickCount++;
    }
    /*if (!textClock.isMoveAnimationRunning())
    {
        tickCount++;
        if (circle.getArcStart() + 340 == circle.getArcEnd())
        {
            addStart = 2;
            addEnd = 1;
        }
        else if (circle.getArcStart() + 20 == circle.getArcEnd())
        {
            addStart = 1;
            addEnd = 2;
        }
        circle.invalidate();
        circle.setArc(circle.getArcStart() + addStart, circle.getArcEnd() + addEnd);
        circle.invalidate();
    }*/
}
