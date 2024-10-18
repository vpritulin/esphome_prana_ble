#include "esphome/core/component.h"
#include "esphome/core/log.h"  // Правильное подключение для логирования
#include "esphome/components/output/float_output.h"
#include "esphome/components/prana_ble/prana_ble_hub.h"

class CustomPranaBrightnessOutput : public esphome::Component, public esphome::output::FloatOutput {
 public:
  CustomPranaBrightnessOutput(esphome::prana_ble::PranaBLEHub *hub) : hub_(hub) {}

  void write_state(float state) override {
    int brightness_value = static_cast<int>(state * 5) + 1;
    ESP_LOGD("custom_brightness", "Setting brightness to: %d", brightness_value); 
    hub_->set_brightness(brightness_value);
  }

 protected:
  esphome::prana_ble::PranaBLEHub *hub_;
};
