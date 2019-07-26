#ifndef SCREEN1_VIEW_HPP
#define SCREEN1_VIEW_HPP

#include <gui_generated/screen1_screen/Screen1ViewBase.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>

#include "stm32f7xx.h"
#include "stm32f7xx_hal.h"

class Screen1View : public Screen1ViewBase
{
public:
    Screen1View();
    virtual ~Screen1View() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
    virtual void handleTickEvent();
    
    virtual void volumesliderfunction(int value);
    virtual void powertogglefunction();
    virtual void searchbuttonfunction();
    virtual void playtogglefunction();
    virtual void previousbuttonfunction();
    virtual void nextbuttonfunction();
    UART_HandleTypeDef huart6;
    uint8_t SYSTEM_GetSysRdy[7] = {0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFD};
    uint8_t CMD_ACK[7] = {0xFE, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFD};
    uint8_t STREAM_AutoSearch[9] = {0xFE, 0x01, 0x03, 0x00, 0x00, 0x02, 0x00, 0x40, 0xFD};
    uint8_t STREAM_GetTotalProgram[6] = {0xFE, 0x01, 0x16, 0x00, 0x00, 0xFD};
    uint8_t STREAM_GetTotalProgramResponse[11] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    uint8_t STREAM_GetTotalProgramCheck[11] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
    uint8_t STREAM_Play[12] = {0xFE, 0x01, 0x00, 0x00, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFD};
    uint8_t STREAM_GetPlayStatus[7] = {0xFE, 0x01, 0x05, 0x00, 0x00, 0x00, 0xFD};
    uint8_t STREAM_GetPlayStatusResponse[8] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};


protected:
    int16_t hour;
    int16_t minute;
    int16_t tickCount;
    int16_t addStart;
    int16_t addEnd;
};

#endif // SCREEN1_VIEW_HPP
