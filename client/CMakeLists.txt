cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(opdracht3-client)

add_executable(opdracht3-client MQTTClient_publish.c)

target_link_libraries(opdracht3-client paho-mqtt3c wiringPi)
