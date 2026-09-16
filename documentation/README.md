# Documentation

This directory contains technical and research documentation for the MP-RAS project.

## Contents

The documentation may include:

- System architecture
- Hardware design
- Circuit diagrams
- Sensor wiring and pinouts
- Mechanical design
- Calibration procedures
- Camera configuration
- Software architecture
- Database structure
- Experimental methodology
- Testing procedures
- Results and analysis
- Project reports

## System Architecture

MP-RAS consists of three primary measurement modules:

```text
                 MP-RAS
                    |
       +------------+------------+
       |            |            |
     Weight       Gait       Swelling
   Distribution  Analysis     Analysis
       |            |            |
      ESP32      Raspberry Pi  Raspberry Pi
       |            |            |
    Load Cells    Camera       Camera
       |            |            |
       +------------+------------+
                    |
              Data Processing
                    |
               Backend/API
                    |
                Database
