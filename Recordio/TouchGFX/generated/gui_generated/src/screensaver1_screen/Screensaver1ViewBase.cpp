/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screensaver1_screen/Screensaver1ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Screensaver1ViewBase::Screensaver1ViewBase() :
    flexButtonCallback(this, &Screensaver1ViewBase::flexButtonCallbackHandler),
    interaction2EndedCallback(this, &Screensaver1ViewBase::interaction2EndedCallbackHandler)
{
    box1.setPosition(0, 0, 480, 272);
    box1.setColor(touchgfx::Color::getColorFrom24BitRGB(0, 0, 0));

    flexButton.setBoxWithBorderPosition(0, 0, 480, 272);
    flexButton.setBorderSize(5);
    flexButton.setBoxWithBorderColors(touchgfx::Color::getColorFrom24BitRGB(0, 102, 153), touchgfx::Color::getColorFrom24BitRGB(0, 153, 204), touchgfx::Color::getColorFrom24BitRGB(0, 51, 102), touchgfx::Color::getColorFrom24BitRGB(51, 102, 153));
    flexButton.setPosition(0, 0, 480, 272);
    flexButton.setAlpha(0);
    flexButton.setAction(flexButtonCallback);

    textClock.setXY(193, -12);
    textClock.setColor(touchgfx::Color::getColorFrom24BitRGB(255, 255, 255));
    textClock.setLinespacing(0);
    Unicode::snprintf(textClockBuffer1, TEXTCLOCKBUFFER1_SIZE, "%s", TypedText(T_SINGLEUSEID17).getText());
    textClock.setWildcard1(textClockBuffer1);
    Unicode::snprintf(textClockBuffer2, TEXTCLOCKBUFFER2_SIZE, "%s", TypedText(T_SINGLEUSEID18).getText());
    textClock.setWildcard2(textClockBuffer2);
    textClock.resizeToCurrentText();
    textClock.setTypedText(TypedText(T_SINGLEUSEID5));

    add(box1);
    add(flexButton);
    add(textClock);
}

void Screensaver1ViewBase::setupScreen()
{

}

//Called when the screen is done with transition/load
void Screensaver1ViewBase::afterTransition()
{
    //Interaction2
    //When screen is entered move textClock
    //Move textClock to x:193, y:230 with LinearIn easing in 5000 ms (300 Ticks)
    textClock.clearMoveAnimationEndedAction();
    textClock.startMoveAnimation(193, 230, 300, EasingEquations::linearEaseIn, EasingEquations::linearEaseIn);
    textClock.setMoveAnimationEndedAction(interaction2EndedCallback);
}

void Screensaver1ViewBase::interaction2EndedCallbackHandler(const touchgfx::MoveAnimator<touchgfx::TextAreaWithTwoWildcards>& comp)
{
    //Interaction3
    //When Interaction2 completed change screen to Screensaver2
    //Go to Screensaver2 with no screen transition
    application().gotoScreensaver2ScreenNoTransition();
}

void Screensaver1ViewBase::flexButtonCallbackHandler(const touchgfx::AbstractButtonContainer& src)
{
    if (&src == &flexButton)
    {
        //Interaction1
        //When flexButton clicked change screen to Screen1
        //Go to Screen1 with no screen transition
        application().gotoScreen1ScreenNoTransition();
    }
}