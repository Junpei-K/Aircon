extern "C" {
#include "user_interface.h"
}

enum sleep_type {
        NONE_SLEEP_T    = 0,
        LIGHT_SLEEP_T,
        MODEM_SLEEP_T
};

bool wifi_set_sleep_type(enum sleep_type type);

void setup() {
  // put your setup code here, to run once:
   wifi_set_sleep_type(LIGHT_SLEEP_T);
}

void loop() {
  // put your main code here, to run repeatedly:

}
