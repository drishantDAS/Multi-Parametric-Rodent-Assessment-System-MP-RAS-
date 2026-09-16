# Gait Analysis Module

The gait analysis module uses camera-based imaging to capture and analyze rodent paw movement during locomotion.

## Hardware

- Raspberry Pi 4
- Raspberry Pi Camera Module
- IMX219 camera sensor
- Camera mounting system
- Illumination system as required

## Image Acquisition

The camera is positioned to obtain a suitable view of the rodent's movement through the experimental corridor.

Typical acquisition configuration:

- Resolution: 640 × 480
- Frame rate: up to 30 FPS
- Image format: RGB

## Analysis

The captured video/images are processed to identify paw movement and extract gait-related parameters.

The development workflow includes:

1. Image acquisition
2. Pre-processing
3. Paw detection
4. Paw position tracking
5. Gait parameter extraction
6. Data storage
7. Experimental analysis

A YOLO-based model is used in the current development workflow for gait-related detection.

## Processing Pipeline

```text
Rodent Movement
       ↓
Pi Camera
       ↓
Raspberry Pi 4
       ↓
Image / Video Processing
       ↓
Paw Detection
       ↓
Gait Analysis
       ↓
Parameter Extraction
       ↓
Data Storage
