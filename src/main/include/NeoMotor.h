#pragma once
#include "rev/CANSparkMax.h"

class NeoMotor {
private:
    // pointer variable for the SparkMax because we don't know it's CAN ID
    rev::CANSparkMax* motor;

public:
    NeoMotor(int canID)
    {
        // create a SparkMax object given it's CAN ID
        motor = new rev::CANSparkMax{canID, rev::CANSparkMax::MotorType::kBrushless};
    }

    // method to run in RobotInit()
    void initialize()
    {
        // "->" is used instead of the "." operator because "motor" is a pointer
        motor->SetInverted(false);
        // set PID constants
        motor->GetPIDController().SetP(0.1);
        motor->GetPIDController().SetI(0);
        motor->GetPIDController().SetD(1);
        motor->GetPIDController().SetIZone(0);
        motor->GetPIDController().SetFF(0);
        // set output range
        motor->GetPIDController().SetOutputRange(-1, 1);
        motor->BurnFlash();
    }

    // set the rotor position relative to it's starting position
    void SetAngle(double angle)
    {
        motor->GetPIDController().SetReference(angle / 360, rev::CANSparkMax::ControlType::kPosition);
    }
};