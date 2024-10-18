#pragma once

#include "esphome/core/component.h"
#include "esphome/components/light/light_output.h"
#include "esphome/core/log.h"
#include <functional>

namespace esphome {
namespace custom_light {

class CustomLightOutput : public Component, public LightOutput {
 public:
  CustomLightOutput(std::function<void(float)> write_state_func) : write_state_func_(write_state_func) {}

  void write_state(float state) override {
    ESP_LOGD("custom_light", "Setting brightness to: %.2f", state);
    this->write_state_func_(state);
  }

 private:
  std::function<void(float)> write_state_func_;
};


}  // namespace custom_light
}  // namespace esphome
