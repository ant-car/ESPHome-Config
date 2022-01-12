#ifndef SB1_UART_H_
#define SB1_UART_H_

#include "esphome.h"
using namespace esphome;

class TuyaSwitchMcu : public Component, public uart::UARTDevice {
  protected:
    int lolInt;

  public:
    TuyaSwitchMcu(uart::UARTComponent *parent) : uart::UARTDevice(parent) {}

    void setup() override {
    }

    /* 
     * State machine; generally follows the same message sequence as
     * has been observed to flow between the stock Tuya firmware and
     * the SB1 chip via the UART bus.
     */
    void loop() override {
      String line = readString();
      int i = parseInt();
      while (available()) {
        char c = read();
        Serial.print(c);
      }
      delay(1000);
    }
};

#endif // SB1_UART_H_