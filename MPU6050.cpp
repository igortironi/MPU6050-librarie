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
#include "arduino.h"
#include "MPU6050.h"

#include <Wire.h>

MPU6050::MPU6050(){
}


void MPU6050::begin(){
    Wire.begin();

    Wire.beginTransmission(ADDR);
    Wire.write(PWR_MGMT_1);
    Wire.write(0);
    Wire.endTransmission(true);
}


void MPU6050::config_accel(int8_t data){
    if(data>=0 && data<=3){
        Wire.beginTransmission(ADDR);
        Wire.write(ACCEL_CONFIG);
        Wire.write(data<<3);
        Wire.endTransmission(true);

        switch (data){
        case 0:
            Accel_scale = 16384.0;
        break;
        case 1:
            Accel_scale = 8192.0;
        break;
        case 2:
            Accel_scale = 4096.0;
        break;
        case 3:
            Accel_scale = 2048.0;
        break;
    }
    }

}


void MPU6050::config_gyro(int8_t data){
    if(data>=0 && data<=3){
        Wire.beginTransmission(ADDR);
        Wire.write(GYRO_CONFIG);
        Wire.write(data<<3);
        Wire.endTransmission(true);


        switch (data){
        case 0:
            Gyro_scale = 131.0;
        break;
        case 1:
            Gyro_scale = 65.5;
        break;
        case 2:
            Gyro_scale = 32.8;
        break;
        case 3:
            Gyro_scale = 16.4;
        break;
    }
    }

}


void MPU6050::convert_value(int8_t state){
    Convert = state;
}


void MPU6050::config_filter(int8_t data){
    if(data>=0 && data<=6){
        Wire.beginTransmission(ADDR);
        Wire.write(CONFIG);
        Wire.write(data);
        Wire.endTransmission(true);
    }
}


float MPU6050::x_accel(){
    int result=0;
    Wire.beginTransmission(ADDR);
    Wire.write(ACCEL_XOUT_H);
    Wire.endTransmission(false);

    Wire.requestFrom(ADDR, 2, true);
    result = Wire.read()<<8|Wire.read();

    if(Convert) return (result / Accel_scale);
    else return result;
}

float MPU6050::y_accel(){
    int result=0;
    Wire.beginTransmission(ADDR);
    Wire.write(ACCEL_YOUT_H);
    Wire.endTransmission(false);

    Wire.requestFrom(ADDR, 2, true);
    result = Wire.read()<<8|Wire.read();

    if(Convert) return (result / Accel_scale);
    else return result;
}

float MPU6050::z_accel(){
    int result=0;
    Wire.beginTransmission(ADDR);
    Wire.write(ACCEL_ZOUT_H);
    Wire.endTransmission(false);

    Wire.requestFrom(ADDR, 2, true);
    result = Wire.read()<<8|Wire.read();

    if(Convert) return (result / Accel_scale);
    else return result;
}


float MPU6050::x_gyro(){
    int result=0;
    Wire.beginTransmission(ADDR);
    Wire.write(GYRO_XOUT_H);
    Wire.endTransmission(false);

    Wire.requestFrom(ADDR, 2, true);
    result = Wire.read()<<8|Wire.read();

    if(Convert) return (result / Gyro_scale);
    else return result;
}

float MPU6050::y_gyro(){
    int result=0;
    Wire.beginTransmission(ADDR);
    Wire.write(GYRO_YOUT_H);
    Wire.endTransmission(false);

    Wire.requestFrom(ADDR, 2, true);
    result = Wire.read()<<8|Wire.read();

    if(Convert) return (result / Gyro_scale);
    else return result;
}

float MPU6050::z_gyro(){
    int result=0;
    Wire.beginTransmission(ADDR);
    Wire.write(GYRO_ZOUT_H);
    Wire.endTransmission(false);

    Wire.requestFrom(ADDR, 2, true);
    result = Wire.read()<<8|Wire.read();

    if(Convert) return (result / Gyro_scale);
    else return result;
}

