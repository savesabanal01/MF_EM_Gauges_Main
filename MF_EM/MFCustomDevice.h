#pragma once

#include <Arduino.h>
#include "FFGauge/FFGauge.h"
#include "ITTGauge/ITTGauge.h"
#include "NPGauge/NPGauge.h"
#include "TRQGauge/TRQGauge.h"
#include "NGGauge/NGGauge.h"
#include "OTOPGauge/OTOPGauge.h"

// only one entry required if you have only one custom device
enum {
    FFGAUGE_DEVICE = 1,
    ITTGAUGE_DEVICE,
    NPGAUGE_DEVICE,
    TRQGAUGE_DEVICE,
    OTOPGAUGE_DEVICE,
    NGGAUGE_DEVICE
};
class MFCustomDevice
{
public:
    MFCustomDevice();
    void attach(uint16_t adrPin, uint16_t adrType, uint16_t adrConfig, bool configFromFlash = false);
    void detach();
    void update();
    void set(int16_t messageID, char *setPoint);

private:
    bool           getStringFromMem(uint16_t addreeprom, char *buffer, bool configFromFlash);
    bool           _initialized = false;
    FFGauge        *_myFFGaugedevice;
    ITTGauge       *_myITTGaugedevice;
    NPGauge        *_myNPGaugedevice;
    TRQGauge        *_myTRQGaugedevice;
    NGGauge         *_myNGGaugedevice;
    OTOPGauge       *_myOTOPGaugedevice;
    uint8_t        _pin1, _pin2, _pin3;
    uint8_t        _customType = 0;
};
