/* 
 *   
 *  Project:          IoT Energy Meter with C/C++, Java/Spring, TypeScript/Angular and Dart/Flutter;
 *  About:            End-to-end implementation of a LoRaWAN network for monitoring electrical quantities;
 *  Version:          1.0;
 *  Backend Mote:     ATmega328P/ESP32/ESP8266/ESP8285/STM32;
 *  Radios:           RFM95w and LoRaWAN EndDevice Radioenge Module: RD49C;
 *  Sensors:          Peacefair PZEM-004T 3.0 Version TTL-RTU kWh Meter;
 *  Backend API:      Java with Framework: Spring Boot;
 *  LoRaWAN Stack:    MCCI Arduino LoRaWAN Library (LMiC: LoRaWAN-MAC-in-C) version 3.0.99;
 *  Activation mode:  Activation by Personalization (ABP) or Over-the-Air Activation (OTAA);
 *  Author:           Adail dos Santos Silva
 *  E-mail:           adail101@hotmail.com
 *  WhatsApp:         +55 89 9 9433-7661
 *  
 *  WARNINGS:
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of
 *  this software and associated documentation files (the “Software”), to deal in
 *  the Software without restriction, including without limitation the rights to
 *  use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 *  the Software, and to permit persons to whom the Software is furnished to do so,
 *  subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software.
 *  
 *  THE SOFTWARE IS PROVIDED “AS IS”, WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 *  FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 *  COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 *  IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 *  CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *  
 */

/********************************************************************
 _____              __ _                       _   _             
/  __ \            / _(_)                     | | (_)            
| /  \/ ___  _ __ | |_ _  __ _ _   _ _ __ __ _| |_ _  ___  _ __  
| |    / _ \| '_ \|  _| |/ _` | | | | '__/ _` | __| |/ _ \| '_ \ 
| \__/\ (_) | | | | | | | (_| | |_| | | | (_| | |_| | (_) | | | |
 \____/\___/|_| |_|_| |_|\__, |\__,_|_|  \__,_|\__|_|\___/|_| |_|
                          __/ |                                  
                         |___/                                   
********************************************************************/

/* 
 *  C menu code
 *  Start where it has headers, declaration of global variables and etc.
 */
/* Variables */
typedef enum items
{
    Item1 = 1,
    Item2
} Items;

typedef enum screens
{
    Screen0_Menu,
    Screen1,
    Screen2
} Screens;

bool    button_down;
bool    button_up;
bool    selection_button;
uint8_t LED1;
uint8_t LED2;
uint8_t _target_screen = Screen0_Menu;

/*****************************
 _____           _      
/  __ \         | |     
| /  \/ ___   __| | ___ 
| |    / _ \ / _` |/ _ \
| \__/\ (_) | (_| |  __/
 \____/\___/ \__,_|\___|
*****************************/

/* Functions */
/*
 *  Program options menu
 */
void menu(uint8_t *_target_screen)
{
    /* State your local variables here */
    items   _menu;
    uint8_t _return                 = 0;
    uint8_t _menu_position          = Item1;
    uint8_t _previous_menu_position = Item2;
    
    while (_return == 0)
    {
        /* Write here your code of what will happen on the menu, be it animations, beep when you press a key and etc. */
        if (_previous_menu_position != _menu_position)
        {
            switch (_menu_position)
            {
            case Item1:
            {
                /*  
                 *  Write here the code that will draw your menu in C when the first item is selected.
                 *  It can be like the GIF, an arrow on the side indicating, change the color of the text.  
                 */
                break;
            }
            case Item2:
            {
                /*  
                 *   Write here the code that will draw your menu in C when the second item is selected.
                 *   It can be like the GIF, an arrow on the side indicating, change the color of the text.
                 */
                break;
            }
            default:
                break; /* Error */
            }
            _previous_menu_position = _menu_position;
        }
        /* Code responsible for reading buttons, encoder, etc. to change the position selected in the menu. */
        if (button_down == 1 && _menu_position != Item2)
            _menu_position++;
        else if (button_up == 1 && _menu_position != Item1)
            _menu_position--;
        /* If pressed the button to select the highlighted item in the menu, exit the menu. */
        if (selection_button == 1)
            _return = 1;
    }
    *_target_screen = _menu_position;
}

/*
 *  Screen1, selected in the menu by "Item1"
 */
void screen1(uint8_t *_target_screen)
{
    /* State your local variables here */
    uint8_t _return = 0;
    
    while (_return == 0)
    {
        /* Write here your code of what will happen on this screen, how to show or receive data, turn on an LED, etc.. */
        LED1 = 1;
        /* Here is the return / exit condition of the screen. It can be a button pressed, an interruption, a command from the terminal. */
        if (selection_button == 1)
            _return = 1;
    }
    /* When leaving this screen, you return to the menu. You can change this on this line. */
    *_target_screen = Screen0_Menu;
}

/*
 *  Screen2, selected in the menu by "Item1" or 2?
 */
void screen2(uint8_t *_target_screen)
{
    /* State your local variables here */
    uint8_t _return = 0;
    
    while (_return == 0)
    {
        /* Write here your code of what will happen on this screen, how to show or receive data, turn on an LED, etc. */
        LED2 = 1;
        /* Here is the return / exit condition of the screen. It can be a button pressed, an interruption, a command from the terminal. */
        if (selection_button == 1)
            _return = 1;
    }
    /* When leaving this screen, you return to the menu. You can change this on this line. */
    *_target_screen = Screen0_Menu;
}

/*****************************
 _____      _               
/  ___|    | |              
\ `--.  ___| |_ _   _ _ __  
 `--. \/ _ \ __| | | | '_ \ 
/\__/ /  __/ |_| |_| | |_) |
\____/ \___|\__|\__,_| .__/ 
                     | |    
                     |_|    
******************************/

void setup()
{
    
}

/*****************************
 _                       
| |                      
| |     ___   ___  _ __  
| |    / _ \ / _ \| '_ \ 
| |___| (_) | (_) | |_) |
\_____/\___/ \___/| .__/ 
                  | |    
                  |_|    
*****************************/

void loop()
{
    /*
     *  This is your program loop. For those who program Arduino, this while is their loop() function
     *  Insert what you want here, as long as it does not block the operation of the switch below
     *  This switch is responsible for making your program go from one screen to another.
     */
    switch (_target_screen)
    {
        case Screen0_Menu:
        {
            menu(&_target_screen);
            break;
        }
        case Screen1:
        {
            screen1(&_target_screen);
            break;
        }
        case Screen2:
        {
            screen2(&_target_screen);
            break;
        }
    }
}
