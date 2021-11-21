#include "modules.hpp"

#include "constants.h"
#include "pinConfig.h"

GPIO led(LED_BUILTIN);
GPIO beep(A3);
GPIO tcrtL(TCRT_L), tcrtR(TCRT_R);

// CCD ccd(CCD_CLK, CCD_SI, CCD_AO, CCD_SEP, CCD_THRESHOLD_LOW, CCD_THRESHOLD_HIGH);

// Motor motorL(MOTOR_L_PWM, MOTOR_L_DIR, MOTOR_L_INV);
// Motor motorR(MOTOR_R_PWM, MOTOR_R_DIR, MOTOR_R_INV);

Motor motorL(MOTOR_L_E, MOTOR_L_A, MOTOR_L_B);
Motor motorR(MOTOR_R_E, MOTOR_R_A, MOTOR_R_B);

BaseDriver baseDriver(motorL, motorR);

PID pid(PID_P, PID_I, PID_D, PID_LIMIT);

TCRTArray tcrtArray((const uint8_t[]){TCRT_ARRAY}, TCRT_NUM, TCRT_THRESH_LOW, TCRT_THRESH_HIGH);
