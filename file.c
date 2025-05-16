#include <stdint.h>

uint16_t shift_value_based_on_input(uint16_t value, uint8_t user_input) {
    uint8_t shift_amount;
    
    /* Complex logic to determine shift amount based on user input */
    if (user_input > 100) {
        shift_amount = 8;
    } else if (user_input > 50) {
        shift_amount = 12;
    } else if (user_input > 25) {
        shift_amount = 14;
    } else {
        shift_amount = 16;  /* This value is problematic - exceeds bit width */
    }
    
    /* MISRA Rule 12.2 violation when shift_amount is 16 */
    /* For uint16_t, valid shift values are 0-15 only */
    return value << shift_amount;
}