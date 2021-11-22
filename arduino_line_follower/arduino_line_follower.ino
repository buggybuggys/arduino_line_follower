#include "Main.hpp"
#include "flags.hpp"
#include "isr.hpp"
#include "modules.hpp"

void hostCommunication();

void setup() {
    flags::init();
    // led.setMode(OUTPUT);
    // beep.setMode(OUTPUT);
    tcrtArray.init();
    tcrtL.setMode(INPUT), tcrtR.setMode(INPUT);

    motorL.init();
    motorR.init();

    isrStart();
    SerialIO::begin(115200);
}

void loop() {
    flags::tcrt.update();

    // testTCRT();
    if (flags::startPID) pidCtrl(false);

    while (SerialIO::available()) hostCommunication();
}

void serialEvent() {
    // while (SerialIO::available()) hostCommunication();
}