#ifndef ROBOTMAP_H
#define ROBOTMAP_H


/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// #define LEFTMOTOR 1
// #define RIGHTMOTOR 2

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// #define RANGE_FINDER_PORT 1
// #define RANGE_FINDER_MODULE 1
#define LEFT_VICTOR 1
#define RIGHT_VICTOR 2
#define ARM_SERVO 3
#define JOYSTICK_1 1
#define JOYSTICK_2 2
#define IR_CHANNEL 4
// DIGITAL IO Port numbers on the Digital Sidecar
#define ABSOLUTEENCODER_CHIPSELECT	4
#define ABSOLUTEENCODER_CLOCK	3
#define ABSOLUTEENCODER_MISO	2
// one data line: master in - slave out (master provide the clock)
#define ABSOLUTEENCODER_DATA	2
// The Absolute Encoder wire colors map to the above pins
// first color from the encoder. second color is the gender change connector.
#define ABSOLUTEENCODER_GREYGREEN	4
#define ABSOLUTEENCODER_YELLOWYELLOW	3
#define ABSOLUTEENCODER_ORANGEBLUE	2
#endif
