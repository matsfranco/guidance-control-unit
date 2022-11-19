#ifndef RadioChannel_h
#define RadioChannel_h
#include "Arduino.h"

class RadioChannel {
    public:
        RadioChannel(int pin);
        void setInputValues(int min, int max, int nullZone);
        void setOutputValues(int min, int max);
        unsigned long getInput();
        long calculateOutput();
        long getOutput();
        String getChannelData();
        long process();
    private:
        int _inputPin; 
        int _minInput;
        int _maxInput; 
        int _minOutput;
        int _maxOutput;
        int _middleInput;
        int _nullZone;
        unsigned long _measure;
        long _output;
};

#endif