/*
	Implementation of all the functions defined in the radio.h file
*/

// Global variables
static uint8_t pintx = 1;
static uint8_t pinrx = 0;

// Function prototypes

void set_pins(uint8_t pin_rx, uint8_t pin_tx);
void setup(uint16_t speed);

void rf_begin();
void rf_end();

uint8_t send_data(uint8_t *buffer, uint8_t length);

uint8_t recv_data(uint8_t *buffer, uint8_t *length);

//Function definitions

void set_pins(uint8_t pin_rx, uint8_t pin_tx) {
  pintx = pin_tx;
  pinrx = pin_rx;
}

void setup(uint16_t speed) {

 

}

void rf_begin() {



}

void rf_end() {


}

uint8_t send_data(uint8_t *buffer, uint8_t length) {


}

uint8_t recv_data(uint8_t *buffer, uint8_t *length) {


}

