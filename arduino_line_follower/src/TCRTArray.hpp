#ifndef _TCRT_ARRAY_HPP
#define _TCRT_ARRAY_HPP

#include <Arduino.h>

class TCRTArray {
    const int8_t N;
    uint8_t* pins = nullptr;
    int16_t* data = nullptr;
    const int16_t low, high;
    bool _valid = false;
    int32_t _res;
    void collectDigital();
    void collectAnalog();

 public:
    TCRTArray(const uint8_t* pins, int8_t N, int16_t threshLow, int16_t threshHigh);
    ~TCRTArray();
    void init();

    void collect();
    int16_t operator[](int i) const { return data[i]; }
    int8_t size() const { return N; }
    void send() const;

    void calc();
    bool valid() const { return _valid; }
    int32_t res() const { return _res; }
};

#endif  // _TCRT_ARRAY_HPP