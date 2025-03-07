/*
 * myMakeLED.c - Modified version of makeLED.c
 * 
 * This program controls an LED using command-line arguments.
 * If an invalid command is given, the LED flashes (1 sec ON, 1 sec OFF).
 * 
 * Usage:
 *   sudo ./myMakeLED on   -> Turns LED ON
 *   sudo ./myMakeLED off  -> Turns LED OFF
 *   sudo ./myMakeLED blink -> Blinks LED
 *   sudo ./myMakeLED invalid_command -> Flashes LED at 1-second intervals
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define LED_PATH "/sys/class/leds/beaglebone:green:usr0"

void writeLED(char *filename, char *value) {
    char fullPath[100];
    sprintf(fullPath, "%s/%s", LED_PATH, filename);
    FILE *fp = fopen(fullPath, "w");
    if (fp == NULL) {
        printf("Error: Cannot open %s\n", fullPath);
        exit(1);
    }
    fprintf(fp, "%s", value);
    fclose(fp);
}

void flashLED() {
    printf("Invalid command! Flashing LED...\n");
    while (1) {
        writeLED("trigger", "timer");
        writeLED("delay_on", "1000");
        writeLED("delay_off", "1000");
        sleep(2);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: sudo ./myMakeLED <on|off|blink>\n");
        return 1;
    }

    if (strcmp(argv[1], "on") == 0) {
        writeLED("trigger", "none");
        writeLED("brightness", "1");
    } else if (strcmp(argv[1], "off") == 0) {
        writeLED("trigger", "none");
        writeLED("brightness", "0");
    } else if (strcmp(argv[1], "blink") == 0) {
        writeLED("trigger", "timer");
        writeLED("delay_on", "500");
        writeLED("delay_off", "500");
    } else {
        flashLED();  // Handle invalid commands
    }

    return 0;
}
