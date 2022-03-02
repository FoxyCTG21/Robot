#include <Arduino.h>
// Liberia de la app Dabble
#include <DabbleESP32.h>

//////////////////////////////// dabble bluethoot
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE

//////////////////////////////// Pines del motor IZQUIERDA
#define IZQUIERDA_EN 12
#define IZQUIERDA_A1 15
#define IZ1UIERDA_A2 14

//////////////////////////////// Pines del motor DERECHA
#define DERECHA_EN 16
#define DERECHA_A1 13
#define DERECHA_A2 2

/////////////////////////////// Pin de Standby
#define STBY 4

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);          // Marcamos la velocidad de la transmisión serial
    Dabble.begin("MyFoxyRobot"); // Indicamos un nombre al dispositivo a encontrar
}

void loop()
{
    Dabble.processInput(); // this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
    Serial.print("KeyPressed: ");
    if (GamePad.isUpPressed())
    {
        Serial.print("Up");
    }

    if (GamePad.isDownPressed())
    {
        Serial.print("Down");
    }

    if (GamePad.isLeftPressed())
    {
        Serial.print("Left");
    }

    if (GamePad.isRightPressed())
    {
        Serial.print("Right");
    }

    if (GamePad.isSquarePressed())
    {
        Serial.print("Square");
    }

    if (GamePad.isCirclePressed())
    {
        Serial.print("Circle");
    }

    if (GamePad.isCrossPressed())
    {
        Serial.print("Cross");
    }

    if (GamePad.isTrianglePressed())
    {
        Serial.print("Triangle");
    }

    if (GamePad.isStartPressed())
    {
        Serial.print("Start");
    }

    if (GamePad.isSelectPressed())
    {
        Serial.print("Select");
    }
    Serial.print('\t');

    int a = GamePad.getAngle();
    Serial.print("Angle: ");
    Serial.print(a);
    Serial.print('\t');
    int b = GamePad.getRadius();
    Serial.print("Radius: ");
    Serial.print(b);
    Serial.print('\t');
    float c = GamePad.getXaxisData();
    Serial.print("x_axis: ");
    Serial.print(c);
    Serial.print('\t');
    float d = GamePad.getYaxisData();
    Serial.print("y_axis: ");
    Serial.println(d);
    Serial.println();
}
