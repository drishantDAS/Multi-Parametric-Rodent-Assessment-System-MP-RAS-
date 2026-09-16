# ESP32 Firmware

This directory contains the firmware for the ESP32-based weight distribution module of the MP-RAS system.

## Responsibilities

The ESP32 firmware is responsible for:

- Reading load-cell measurements through HX711.
- Processing and calibrating sensor readings.
- Monitoring the four paw-load channels.
- Displaying measurements on the SSD1306 OLED.
- Providing Wi-Fi-based communication.
- Transmitting measurement data to the software/backend system.

## Hardware Interface

### HX711

The HX711 is used as the load-cell signal amplifier and ADC interface.

Current development configuration:

- DOUT: GPIO 23
- SCK: GPIO 22

### OLED

SSD1306 128×64 OLED display:

- DC: GPIO 17
- CS: GPIO 16
- RESET: GPIO 5
- SCK: GPIO 19
- MOSI: GPIO 18

## Sensor Configuration

The weight platform uses four 100 g half-bridge 3-wire load cells associated with the four paw positions:

- FL — Front Left
- FR — Front Right
- HL — Hind Left
- HR — Hind Right

## Calibration

The firmware includes calibration parameters for converting raw HX711 readings into usable load measurements.

Calibration values must be verified experimentally before deployment.

## Communication

The ESP32 provides Wi-Fi connectivity for transmitting measurement data to the MP-RAS software/backend.

## Development Environment

- Arduino IDE
- ESP32 Arduino framework
- C/C++

## Status

**Development and integration in progress.**
