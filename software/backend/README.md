# MP-RAS Backend

This directory contains the backend components responsible for communication, data processing, and storage for the MP-RAS system.

## Purpose

The backend provides an interface between the experimental hardware/software modules and the database.

## Technology

- Python
- Flask
- PostgreSQL
- REST API
- CORS

## Architecture

```text
ESP32 / Raspberry Pi
        ↓
    Wi-Fi / Network
        ↓
      Flask
        ↓
     REST API
        ↓
   PostgreSQL
        ↓
 Experimental Data
