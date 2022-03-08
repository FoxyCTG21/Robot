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