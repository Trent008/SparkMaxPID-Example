#pragma once
#include "rev/CANSparkMax.h"

class NeoMotor {
private:
    rev::CANSparkMax* motor;

public:
    NeoMotor(int canID)
    {
        motor = new rev::CANSparkMax{canID, rev::CANSparkMax::MotorType::kBrushless};
    }

    void initialize()
    {
        motor->SetInverted(false);
        motor->GetPIDController().SetP(0.1);
        motor->GetPIDController().SetI(0);
        motor->GetPIDController().SetD(1);
        motor->GetPIDController().SetIZone(0);
        motor->GetPIDController().SetFF(0);
        motor->GetPIDController().SetOutputRange(-1, 1);
        motor->BurnFlash();
    }

    void SetAngle(double angle)
    {
        motor->GetPIDController().SetReference(angle / 360, rev::CANSparkMax::ControlType::kPosition);
    }
};