#include "modules.hpp"

#include "constants.h"
#include "pinConfig.h"

GPIO led(LED_BUILTIN);
GPIO tcrtL(TCRT_L), tcrtR(TCRT_R);

CCD ccd(CCD_CLK, CCD_SI, CCD_AO);

Motor motorL(MOTOR_L_PWM, MOTOR_L_DIR);
Motor motorR(MOTOR_R_PWM, MOTOR_R_DIR);

BaseDriver baseDriver(motorL, motorR);

PID pid(PID_P, PID_I, PID_D, PID_LIMIT);
