// Copyright Refringence
// Built with Refringence IDE — https://refringence.com
#ifndef CONFIG_H
#define CONFIG_H

// Platform: ESP32 (Arduino framework) - simulated via printf for tests
// Pin mappings (placeholders for documentation; not used in simulation)
#define UART_TX_PIN 17
#define UART_RX_PIN 16
#define SPI_MOSI_PIN 23
#define SPI_MISO_PIN 19
#define SPI_SCK_PIN  18
#define SPI_FLASH_CS_PIN 5
#define SPI_SRAM_CS_PIN  15

// WiFi credentials and HTTP target (used by simulated drivers)
#define WIFI_SSID "TestSSID"
#define WIFI_PASS "TestPASS"
#define HTTP_HOST "example.com"
#define HTTP_PATH "/"
#define HTTP_PORT 80

// General settings
#define INIT_OK_MSG "System initialized"
#define WIFI_CONNECTED_MSG "WiFi connected"
#define WIFI_DISCONNECTED_MSG "WiFi disconnected"
#define HTTP_GET_OK_MSG "HTTP GET success"
#define HEARTBEAT_MSG "Heartbeat"

// Memory manager settings
#define MEM_POOL_BLOCK_SIZE 128
#define MEM_POOL_BLOCK_COUNT 8

#endif // CONFIG_H
