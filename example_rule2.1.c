#include <stdio.h>

void process_data(int sensor_value) {
    int system_state = get_system_state();  // External function call
    int temperature = read_temperature();   // External function call
    
    if (system_state == 0x5A3C) {
        /* This condition can only be true when specific hardware is connected */
        if (temperature > 100 && sensor_value < -50) {
            /* This combination of conditions is physically impossible 
               (high temperature and extremely low sensor reading) */
            printf("Critical error: Inconsistent readings detected\n");
            emergency_shutdown();  // MISRA violation: unreachable code
        }
    }
}

int get_system_state(void) {
    /* Implementation that interacts with hardware */
    return 0;  // Simplified for example
}

int read_temperature(void) {
    /* Implementation that reads from temperature sensor */
    return 25;  // Simplified for example
}

void emergency_shutdown(void) {
    /* Implementation of emergency shutdown procedure */
}