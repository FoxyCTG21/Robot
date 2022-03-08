#include <Arduino.h>
// Liberia de la app Dabble
#include <DabbleESP32.h>

//////////////////////////////// dabble bluethoot
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

//////////////////////////////// Pines del motor IZQUIERDA
#define IZQUIERDA_EN 12
#define IZQUIERDA_B1 13
#define IZQUIERDA_B2 2

//////////////////////////////// Pines del motor DERECHA
#define DERECHA_EN 4
#define DERECHA_A1 15
#define DERECHA_A2 14

////////////////////////////// Variables del PWM config
#define freq_i 30000
#define freq_d 30000
#define resolution_i 8
#define resolution_d 8
#define ledChannel_i 0
#define ledChannel_d 1

//////////////////////////// Variable le velocidad PWM
uint8_t dutyCycle = 150;

uint8_t movimiento = 0;

void setup()
{
    ///////////////////////////Definición de variables dabble
    Serial.begin(9600);          // Marcamos la velocidad de la transmisión serial
    Dabble.begin("MyFoxyRobot"); // Indicamos un nombre al dispositivo a encontrar

    /////////////////////////// Definición de pines
    pinMode(IZQUIERDA_EN, OUTPUT);
    pinMode(IZQUIERDA_B1, OUTPUT);
    pinMode(IZQUIERDA_B2, OUTPUT);
    pinMode(DERECHA_A1, OUTPUT);
    pinMode(DERECHA_A2, OUTPUT);

    //////////////////////////////// Definición de variables PWM
    ledcSetup(ledChannel_i, freq_i, resolution_i);
    ledcSetup(ledChannel_d, freq_d, resolution_d);

    ledcAttachPin(IZQUIERDA_EN, ledChannel_i);
    ledcAttachPin(DERECHA_EN, ledChannel_d);
}

void loop()
{
    /*
    this function is used to refresh data obtained
    from smartphone.Hence calling this function is
    mandatory in order to get data properly from your mobile.
    */
    Dabble.processInput();
    ledcWrite(ledChannel_i, dutyCycle);
    ledcWrite(ledChannel_d, dutyCycle);

    if (GamePad.isUpPressed())
    {
        Serial.println("Up");
        movimiento = 1;
    }
    else if (GamePad.isDownPressed())
    {
        Serial.println("Down");
        movimiento = 2;
    }
    else if (GamePad.isLeftPressed())
    {
        Serial.println("Left");
        movimiento = 3;
    }
    else if (GamePad.isRightPressed())
    {
        Serial.println("Right");
        movimiento = 4;
    }
    else
    {
        movimiento = 0;
    }

    if (GamePad.isSquarePressed())
    {
        dutyCycle = 50;
    }
    else if (GamePad.isCirclePressed())
    {
        dutyCycle = 150;
    }
    else if (GamePad.isCrossPressed())
    {
        dutyCycle = 200;
    }
    else if (GamePad.isTrianglePressed())
    {
        dutyCycle = 250;
    }

    switch (movimiento)
    {
    case 1:
        digitalWrite(IZQUIERDA_B1, HIGH);
        digitalWrite(IZQUIERDA_B2, LOW);
        digitalWrite(DERECHA_A1, LOW);
        digitalWrite(DERECHA_A2, HIGH);
        break;
    case 2:
        digitalWrite(IZQUIERDA_B1, LOW);
        digitalWrite(IZQUIERDA_B2, HIGH);
        digitalWrite(DERECHA_A1, HIGH);
        digitalWrite(DERECHA_A2, LOW);
        break;
    case 3:
        digitalWrite(IZQUIERDA_B1, LOW);
        digitalWrite(IZQUIERDA_B2, HIGH);
        digitalWrite(DERECHA_A1, LOW);
        digitalWrite(DERECHA_A2, HIGH);
        break;
    case 4:
        digitalWrite(IZQUIERDA_B1, HIGH);
        digitalWrite(IZQUIERDA_B2, LOW);
        digitalWrite(DERECHA_A1, HIGH);
        digitalWrite(DERECHA_A2, LOW);
        break;
    default:
        digitalWrite(IZQUIERDA_B1, LOW);
        digitalWrite(IZQUIERDA_B2, LOW);
        digitalWrite(DERECHA_A1, LOW);
        digitalWrite(DERECHA_A2, LOW);
        break;
    }
}
