#pragma once
#include "rev/CANSparkMax.h"

class NeoMotor {
private:
    // pointer variable for the SparkMax because we don't know it's CAN ID
    rev::CANSparkMax motor{11, rev::CANSparkMax::MotorType::kBrushless};
    rev::SparkPIDController pidController = motor.GetPIDController();

public:

    // method to run in RobotInit()
    void initialize()
    {
        // "->" is used instead of the "." operator because "motor" is a pointer
        motor.SetInverted(false);
        // set PID constants
        pidController.SetP(0.1);
        pidController.SetI(0);
        pidController.SetD(1);
        pidController.SetIZone(0);
        pidController.SetFF(0);
        // set output range
        pidController.SetOutputRange(-1, 1);
        motor.BurnFlash();
    }

    // set the rotor position relative to it's starting position
    void SetAngle(double angle)
    {
        pidController.SetReference(angle / 360, rev::CANSparkMax::ControlType::kPosition);
    }
};