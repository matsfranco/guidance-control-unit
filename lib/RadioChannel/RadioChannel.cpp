#include "Arduino.h"
#include "RadioChannel.h"
#define FAIL_SAFE_LIMIT 50000

RadioChannel::RadioChannel(int inputPin) {
    _inputPin = inputPin;
    pinMode(_inputPin, INPUT);
}

void RadioChannel::setInputValues(int min, int max, int nullZone) {
    _minInput = min;
    _maxInput = max;
    _nullZone = nullZone;
}

void RadioChannel::setOutputValues(int min, int max) {

    _minOutput = min;
    _maxOutput = max;
}

unsigned long RadioChannel::getInput() {
    _measure = (pulseIn (_inputPin, HIGH, 100000))/10;
    if(_measure > _maxInput || _measure < _minInput) { 
        _measure = FAIL_SAFE_LIMIT;
    }
    return _measure;
}

long RadioChannel::calculateOutput() {
    if(_measure < FAIL_SAFE_LIMIT) {
        _output = map(_measure, _minInput, _maxInput, _minOutput, _maxOutput);
    } else {
        _output = 0;
    }    
    return _output;
}

long RadioChannel::getOutput() {
    return _output;
}

long RadioChannel::process() {
    getInput();
    return calculateOutput();
}

String RadioChannel::getChannelData() {
    return "";
}