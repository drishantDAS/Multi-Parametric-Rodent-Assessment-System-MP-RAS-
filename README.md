# Multi-Parametric Rodent Assessment System (MP-RAS)

## Overview

The **Multi-Parametric Rodent Assessment System (MP-RAS)** is an integrated hardware and software platform designed for objective assessment of rodent inflammation, pain-related responses, weight distribution, gait, and paw swelling.

The system combines embedded sensing, computer vision, image processing, and automated data analysis to reduce manual variability and improve the repeatability of experimental measurements.

## Objectives

- Measure left/right and front/hind paw weight distribution.
- Analyze rodent gait using camera-based computer vision.
- Quantify paw swelling from images.
- Integrate multiple experimental parameters into a single assessment platform.
- Reduce manual measurement and observation time.
- Provide digitally recorded and reproducible experimental data.

## System Parameters

MP-RAS focuses on three primary assessment parameters:

### 1. Weight Distribution

A horizontal pronograde corridor contains four isolated paw plates corresponding to:

- Front Left (FL)
- Front Right (FR)
- Hind Left (HL)
- Hind Right (HR)

Each paw plate is associated with a load-cell sensing arrangement for measuring weight distribution.

### 2. Gait Analysis

A Raspberry Pi-based camera system captures the rodent from a bottom-view perspective.

Computer vision and machine-learning based analysis are used to detect and analyze paw movement and gait characteristics.

### 3. Paw Swelling Analysis

A Raspberry Pi camera system captures images of the paw for swelling assessment.

Image processing is used to obtain measurable information from the captured paw images, supporting objective comparison during experimental observations.

## Hardware

### Weight Distribution Module

- ESP32
- 4 × 100 g half-bridge load cells
- HX711 load-cell amplifier
- SSD1306 128×64 OLED display
- Wi-Fi communication
- Four isolated paw plates

### Imaging Module

- Raspberry Pi 4
- Raspberry Pi Camera Module / IMX219
- Camera-based image acquisition
- Computer vision processing

## Software & Technologies

- Embedded C/C++
- Arduino IDE
- ESP32
- Raspberry Pi
- Python
- Computer Vision
- Machine Learning
- YOLO-based gait analysis
- Flask
- PostgreSQL
- Wi-Fi communication

## Weight Platform

The weight-distribution platform uses a horizontal pronograde corridor.

Approximate platform dimensions:

- Base: **130 × 70 mm**
- Corridor: **120 × 38 × 50 mm**
- Paw plates: **25 × 25 mm**
- Lateral gap: **8 mm**
- Front-to-rear gap: **15 mm**

The four paw plates are mechanically isolated to enable individual measurement of the four paws.

## Data Processing

The system acquires sensor and image data from the experimental setup and processes the measurements digitally.

The architecture is designed to support:

1. Data acquisition
2. Signal processing
3. Image acquisition
4. Computer vision analysis
5. Parameter extraction
6. Data storage
7. Experimental comparison

## Project Architecture

```text
                    MP-RAS
                       |
        +--------------+--------------+
        |              |              |
   Weight Module   Gait Module   Swelling Module
        |              |              |
      ESP32       Raspberry Pi     Raspberry Pi
        |              |              |
      HX711        Pi Camera       Pi Camera
        |              |              |
   Load Cells    Gait Analysis   Image Analysis
        |              |              |
        +--------------+--------------+
                       |
                 Data Processing
                       |
                 Data Storage
                       |
              Experimental Analysis
