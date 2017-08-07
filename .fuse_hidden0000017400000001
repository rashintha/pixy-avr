#include <avr/io.h>
#include <util/delay.h>
#include "usart.h"
#include "spi.h"
#include "pixy.h"

int32_t servoX = 500L, servoY = 500L;
void updateServos(uint16_t x, uint16_t y);

int32_t x_p_gain = 350;
int32_t x_d_gain = 600;
int32_t y_p_gain = 500;
int32_t y_d_gain = 700;
int32_t x_prev_err = 0x80000000L;
int32_t y_prev_err = 0x80000000L;

int main(void){

  usartInit();
  spiInit();
  pixyInit();

  setServos(servoX, servoY);

  while(1){
    static int i = 0;
    int j;
    uint16_t blocks;
    char buf[32]; 
    
    // grab blocks!
    blocks = getBlocks(1000);
    
    // If there are detect blocks, print them!
    if (blocks){

      updateServos(g_blocks[0].x, g_blocks[0].y);

      i++;
      
      // print after every 50 frames
      if (i%50==0)
      {
        sprintf(buf, "Detected %d:\n", blocks);
        serialPrint(buf);
        for (j=0; j<blocks; j++)
        {
          sprintf(buf, "  block %d: ", j);
          serialPrint(buf);
          print(g_blocks[j]);
        }
      }
    } 
  }

  return 0;
}

void updateServos(uint16_t x, uint16_t y){
  //char buf[33];

  //Servo controlling using Propotional & Derivative Control (PD Control)

  //Pan Axis (X)
  int32_t x_error = PIXY_CAM_CENTER_X - x;
  long int x_vel;
  

  if (x_prev_err != 0x80000000)
  { 
    x_vel = (x_error*x_p_gain + (x_error - x_prev_err)*x_d_gain)>>10;
    servoX += x_vel;
    if (servoX > PIXY_SERVO_MAX_POS) 
      servoX = PIXY_SERVO_MAX_POS; 
    else if (servoX < PIXY_SERVO_MIN_POS) 
      servoX = PIXY_SERVO_MIN_POS;
  }
  x_prev_err = x_error;

  //Tilt Axis (Y)
  int32_t y_error = y - PIXY_CAM_CENTER_Y;
  long int y_vel;

  if (y_prev_err != 0x80000000)
  { 
    y_vel = (y_error*y_p_gain + (y_error - y_prev_err)*y_d_gain)>>10;
    servoY += y_vel;
    if (servoY > PIXY_SERVO_MAX_POS) 
      servoY = PIXY_SERVO_MAX_POS; 
    else if (servoY < PIXY_SERVO_MIN_POS) 
      servoY = PIXY_SERVO_MIN_POS;
  }
  y_prev_err = y_error;

  //sprintf(buf, "%ld %ld\n", servoX, servoY);
  //serialPrint(buf);

  setServos(servoX, servoY);
}