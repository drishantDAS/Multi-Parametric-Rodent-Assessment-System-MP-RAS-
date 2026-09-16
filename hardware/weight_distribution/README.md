# Weight Distribution Module

The weight distribution module measures the individual load applied by the four paws of a rodent during an experimental assessment.

## Measurement Parameters

The system identifies four paw positions:

- Front Left (FL)
- Front Right (FR)
- Hind Left (HL)
- Hind Right (HR)

## Hardware

- ESP32
- 4 × 100 g half-bridge 3-wire load cells
- HX711 load-cell amplifier
- SSD1306 128×64 OLED display
- Wi-Fi communication

## Mechanical Platform

- Base: 130 × 70 mm
- Corridor: 120 × 38 × 50 mm
- Paw plate: 25 × 25 mm
- Lateral gap: 8 mm
- Front-to-rear gap: 15 mm

The four paw plates are mechanically isolated to allow individual load measurements.

## Data Flow

```text
Rodent Paw
    ↓
Load Cell
    ↓
HX711
    ↓
ESP32
    ↓
Weight Calculation
    ↓
OLED / Wi-Fi
    ↓
Data Storage & Analysis
