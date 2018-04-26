#include "mbed.h"
#include "ultrasonic.h"
#include "C12832.h"

DigitalOut led(LED1);
C12832 lcd(p5, p7, p6, p8, p11);

 void dist(int distance)
{
    lcd.cls();
    lcd.locate(0,3);
    //lcd.printf("test");
    lcd.printf("Distance changed to %dmm\r\n", distance);
    if (distance < 100) //closest
    {
        led = 1;
        wait(0.2);
        led = 0;
        wait(0.2);
    }
    else if (distance > 100 && distance < 500) //medium
    {
        led = 1;
        wait(0.4);
        led = 0;
        wait(0.4);    
    }
    else
    {
        led = 1;
        wait(0.2);
    }
}

ultrasonic mu(p9, p21, .1, 1, &dist);

int main()
{
    mu.startUpdates();//start mesuring the distance
    while(1)
    {
        //Do something else here
        mu.checkDistance();
    }
}
