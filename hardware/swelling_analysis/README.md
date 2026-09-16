# Paw Swelling Analysis Module

The paw swelling analysis module uses camera-based imaging to capture and quantify changes in rodent paw size during experimental assessment.

## Hardware

- Raspberry Pi
- Raspberry Pi Camera Module
- IMX219 camera sensor
- Camera mounting system
- Controlled illumination

## Image Acquisition

The camera captures images of the paw at defined experimental intervals.

Current camera configuration may include:

- Camera sensor: IMX219
- Full-resolution capture: 3280 × 2464
- Processing resolution: 1920 × 1080 or application-specific cropped images

## Analysis Pipeline

```text
Rodent Paw
    ↓
Pi Camera
    ↓
Image Acquisition
    ↓
Image Pre-processing
    ↓
Paw Region Detection
    ↓
Swelling Measurement
    ↓
Parameter Extraction
    ↓
Database / Results
