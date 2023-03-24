#pragma once

#ifndef WEATHER_DHT_LIB_HPP
#define WEATHER_DHT_LIB_HPP

#include <Arduino.h>
#include <DHT.h>



class WeatherDhtLib
{
    private:
        DHT* dhtSensor = nullptr;
    public:
        WeatherDhtLib(uint8_t dhtPin, uint8_t sensorType);
        ~WeatherDhtLib();
        float getTempC();
        float getTempF();
        float getHumudity();
};

#endif // !WEATHER_DHT_LIB_HPP