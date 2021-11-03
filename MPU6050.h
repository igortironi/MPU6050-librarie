/*  MPU6050.cpp - Class file for the MPU6050 Triple Axis Gyroscope & Accelerometer Arduino Library.

    BY by Igor Tironi.
    23/04/2018.
    Version 1.0

        This program is free software: you can redistribute it and/or modify
    it under the terms of the version 3 GNU General Public License as
    published by the Free Software Foundation.

        This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
*/
#ifndef MPU6050_h
#define MPU6050_h

#include "arduino.h"

#define PWR_MGMT_1 0x6B
#define GYRO_CONFIG 0x1B
#define ACCEL_CONFIG 0x1C
#define CONFIG 0x1A
#define ADDR 0x68
#define ACCEL_XOUT_H 0x3B
#define ACCEL_YOUT_H 0x3D
#define ACCEL_ZOUT_H 0x3F
#define GYRO_XOUT_H 0x43
#define GYRO_YOUT_H 0x45
#define GYRO_ZOUT_H 0x47

class MPU6050{
public:
    MPU6050();
    void begin();
    void config_accel(int8_t data);
    void config_gyro(int8_t data);
    void config_filter(int8_t data);
    void convert_value(int8_t state);
    float x_accel();
    float y_accel();
    float z_accel();
    float x_gyro();
    float y_gyro();
    float z_gyro();
private:
    float Gyro_scale = 131.0;
    float Accel_scale = 16384.0;
    int8_t Convert = 0;
};


#endif // MPU6050
