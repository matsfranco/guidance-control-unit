# guidance-control-unit
Firmware of a guidance control unit for a two-wheel robot.
The current version reads a multi-channel radio controller which sends PPM signal and sends to a Motor Control Unit by Serial Port

## Channel and Axis Mapping

### Mode 2

Channel | Axis | Code | Pin
--- | --- | --- | ---
CH1 | Right X | RX | 2
CH2 | Right Y | RY | 3
CH3 | Left Y | LY | 4
