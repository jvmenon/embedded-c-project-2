# ESP32 Mixed System Architecture (Simulated C Skeleton)

This project provides a modular C implementation skeleton for a mixed system architecture targeting ESP32 (Arduino framework) with:
- Battery + Power Regulator (simulated)
- Application Processor (logic block)
- External RAM (SPI SRAM, simulated)
- Non-volatile Storage (AT25 SPI Flash, simulated)
- Wireless Module (ESP8266/ESP-01 over UART using AT commands, simulated)
- Cooperative Scheduler (no RTOS)
- Device Drivers, Memory Manager, Communication Stack (HTTP GET demo)

All hardware interactions are simulated via printf to enable deterministic testing without actual hardware.

## Files
- `include/config.h` - Pins, credentials, constants, messages
- `src/main.c` - Entry point orchestrating initialization, WiFi connection, HTTP GET, and heartbeat task
- `drivers/wifi.c/.h` - ESP8266 AT command driver over UART (simulated)
- `drivers/communication_stack.c/.h` - Minimal HTTP GET using WiFi TCP primitives
- `drivers/memory_manager.c/.h` - Fixed-block memory pool for DMA/buffers
- `drivers/rtos_scheduler.c/.h` - Cooperative scheduler (round-robin, periodic tasks)
- `drivers/ram_entity.c/.h` - External SRAM (SPI) simulated read/write
- `drivers/application_processor.c/.h` - Stub logic block init
- `drivers/device_drivers.c/.h` - Aggregated initialization including flash JEDEC ID read (simulated)
- `tests.json` - Stdout-based tests that verify key outputs

## How to Run
1. Run the code in this environment (no PlatformIO needed): it uses standard C and printf.
2. The test harness will check for these outputs in stdout:
   - `System initialized`
   - `Device drivers initialized`
   - `WiFi connected`
   - `HTTP GET success`
   - `Heartbeat`

## Expected Output (excerpt)
```
System initialized
Power regulator: 3.3V rail enabled
Battery monitor: VBAT OK
Memory manager initialized: 8 blocks of 128 bytes
Application Processor initialized
External SRAM initialized (simulated SPI)
Flash (AT25): JEDEC ID read -> 0x1F 0x66 0x01 (simulated)
WiFi driver init (ESP8266 AT over UART)
Device drivers initialized
AT+CWJAP="TestSSID","TestPASS" -> CONNECT
WiFi connected
Communication stack initialized
AT+CIPSTART="TCP","example.com",80 -> CONNECT
AT+CIPSEND=... -> SEND OK
TX: GET / HTTP/1.1
Host: example.com
Connection: close

RX: HTTP/1.1 200 OK
...
HTTP GET success
WiFi disconnected
Heartbeat
Heartbeat
Heartbeat
```

## Design Notes
- The structure maps to the architecture:
  - Battery/Regulator simulated by initialization prints
  - Application Processor is a logical init unit
  - RAM entity uses a backing array to simulate SPI SRAM
  - Flash is stubbed with a simulated JEDEC ID
  - WiFi uses an ESP8266 AT-style flow for connect/TCP/HTTP
  - Communication stack provides a simple HTTP helper
  - Scheduler triggers a heartbeat task periodically
- Porting to real ESP32 Arduino:
  - Replace printf with Serial.println, implement UART with HardwareSerial for ESP8266 AT
  - Use SPI library for Flash/SRAM (specify chip selects in config.h)
  - Consider lwIP on ESP32 directly if not using external ESP8266
  - Add proper parsing, timeouts, and error handling


---
© Refringence — Built with Refringence IDE: https://refringence.com