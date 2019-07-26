#include <gui/screen1_screen/Screen1View.hpp>

#include "stm32f7xx.h"
#include "stm32f7xx_hal.h"
#include "string.h"

Screen1View::Screen1View()
{

}

void Screen1View::setupScreen()
{
    Screen1ViewBase::setupScreen();
    
    hour = presenter->getHour();
    minute = presenter->getMinute();
    
}

void Screen1View::tearDownScreen()
{
    presenter->saveHour(hour);
    presenter->saveMinute(minute);

    Screen1ViewBase::tearDownScreen();
}

void Screen1View::volumesliderfunction(int value)
{
    uint8_t STREAM_SetVolume[8] = {0xFE, 0x01, 0x0C, 0x00, 0x00, 0x01, uint8_t(value), 0xFD};
    HAL_UART_Transmit(&huart6, STREAM_SetVolume, sizeof(STREAM_SetVolume), HAL_MAX_DELAY);
}

void Screen1View::searchbuttonfunction(){
  HAL_UART_Transmit(&huart6, STREAM_AutoSearch, sizeof(STREAM_AutoSearch), HAL_MAX_DELAY);
}

void Screen1View::powertogglefunction(){
  uint8_t Check[7];
  while (strcmp((const char *)CMD_ACK, (const char *)Check) != 0){
    HAL_Delay(800);
    HAL_UART_Transmit(&huart6, SYSTEM_GetSysRdy, sizeof(SYSTEM_GetSysRdy), HAL_MAX_DELAY);
    HAL_UART_Receive(&huart6, Check, sizeof(Check), HAL_MAX_DELAY);
  }
}

void Screen1View::playtogglefunction(){
    
    while (strcmp((const char *)STREAM_GetTotalProgramResponse, (const char *)STREAM_GetTotalProgramCheck) == 0){
      HAL_UART_Transmit(&huart6, STREAM_GetTotalProgram, sizeof(STREAM_GetTotalProgram), HAL_MAX_DELAY);
      HAL_UART_Receive(&huart6, STREAM_GetTotalProgramResponse, sizeof(STREAM_GetTotalProgramResponse), HAL_MAX_DELAY);
    }
    HAL_UART_Transmit(&huart6, STREAM_Play, sizeof(STREAM_Play), HAL_MAX_DELAY);
    while (strcmp((const char *)STREAM_GetPlayStatus, (const char *)STREAM_GetPlayStatusResponse) == 0){
      HAL_UART_Transmit(&huart6, STREAM_GetPlayStatus, sizeof(STREAM_GetPlayStatus), HAL_MAX_DELAY);
      HAL_UART_Receive(&huart6, STREAM_GetPlayStatusResponse, sizeof(STREAM_GetPlayStatusResponse), HAL_MAX_DELAY);
    }
    
}

void Screen1View::previousbuttonfunction(){
  STREAM_Play[11]--;
  HAL_UART_Transmit(&huart6, STREAM_Play, sizeof(STREAM_Play), HAL_MAX_DELAY);
}
    
void Screen1View::nextbuttonfunction(){
  STREAM_Play[11]++;
  HAL_UART_Transmit(&huart6, STREAM_Play, sizeof(STREAM_Play), HAL_MAX_DELAY);
}
    

void Screen1View::handleTickEvent()
{
    if (tickCount == 60)
    {
        minute++;
        hour = (hour + (minute / 60)) % 24;
        minute %= 60;

        tickCount = 0;
    }

    if (1){
      tickCount++;
    }
}