cmake_minimum_required(VERSION 2.8 FATAL_ERROR)
project(client)

add_executable(client MQTTClient_publish.c)

target_link_libraries(client paho-mqtt3c wiringPi)
