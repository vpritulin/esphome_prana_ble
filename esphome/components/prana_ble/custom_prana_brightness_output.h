#include "esphome.h"

class CustomPranaBrightnessOutput : public Component, public FloatOutput {
 public:
  void write_state(float state) override {
    // Convert the input value (0.0 - 1.0) to the range from 1 to 6
    int brightness_value = (int)(state * 5) + 1;
    id(prana)->set_brightness(brightness_value);
  }
};