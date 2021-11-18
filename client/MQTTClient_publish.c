/*******************************************************************************
 * Copyright (c) 2012, 2020 IBM Corp.
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the Eclipse Public License v2.0
 * and Eclipse Distribution License v1.0 which accompany this distribution. 
 *
 * The Eclipse Public License is available at 
 *   https://www.eclipse.org/legal/epl-2.0/
 * and the Eclipse Distribution License is available at 
 *   http://www.eclipse.org/org/documents/edl-v10.php.
 *
 * Contributors:
 *    Ian Craggs - initial contribution
 *******************************************************************************/
//sudo cc MQTTClient_subscribe.c -o MQTTSUB -lpaho-mqtt3c
//voor i²c zorg dat deze aanstaat. sudo raspi-config => 3. Interface options => anable i²c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "MQTTClient.h"
//i²c
//sudo apt-get install wiringpi
#include <wiringPiI2C.h>
#define DEVICE_ID 0x48

//define for mqtt 
//#define ADDRESS     "tcp://rpi-yb:1883"
#define ADDRESS     "tcp://broker.emqx.io:1883"
#define CLIENTID    "ExampleClientPub"
//#define TOPIC       "temperatuur"
#define TOPIC       "feestbeestdink"
//#define PAYLOAD     "message from paho"
#define QOS         1
#define TIMEOUT     10000L 

void delay(int number_of_miliseconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000*number_of_miliseconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

int main(int argc, char* argv[])
{
    char buffer[10];

    // Setup I2C communication
    int fd = wiringPiI2CSetup(DEVICE_ID);
    if (fd == -1) {
       printf("Failed to init I2C communication.\n");
        return -1;
    }
    printf("I2C communication successfully setup.\n");
    // Switch device to measurement mode
    wiringPiI2CWriteReg8(fd, 0x00, 0b00000001);

    //setup mqtt client
    MQTTClient client;
    MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
    MQTTClient_message pubmsg = MQTTClient_message_initializer;
    MQTTClient_deliveryToken token;
    int rc;
    //create mqtt client
    if ((rc = MQTTClient_create(&client, ADDRESS, CLIENTID,
        MQTTCLIENT_PERSISTENCE_NONE, NULL)) != MQTTCLIENT_SUCCESS)
    {
         printf("Failed to create client, return code %d\n", rc);
         exit(EXIT_FAILURE);
    }
    //try to connect to client
    conn_opts.keepAliveInterval = 20;
    conn_opts.cleansession = 1;
    if ((rc = MQTTClient_connect(client, &conn_opts)) != MQTTCLIENT_SUCCESS)
    {
        printf("Failed to connect, return code %d\n", rc);
        exit(EXIT_FAILURE);
    }

    while (1)
    {
        int temp = wiringPiI2CReadReg8(fd, 0x48); 
        sprintf(buffer, "%d", temp);
        printf("temp: %s \r\n",buffer);
        pubmsg.payload = buffer;
        pubmsg.payloadlen = (int)strlen(buffer);
        pubmsg.qos = QOS;
        pubmsg.retained = 0;
        if ((rc = MQTTClient_publishMessage(client, TOPIC, &pubmsg, &token)) != MQTTCLIENT_SUCCESS)
        {
            printf("Failed to publish message, return code %d\n", rc);
            exit(EXIT_FAILURE);
        }
         rc = MQTTClient_waitForCompletion(client, token, TIMEOUT);
         delay(1000);
    }
    /*
    if ((rc = MQTTClient_disconnect(client, 10000)) != MQTTCLIENT_SUCCESS)
    	printf("Failed to disconnect, return code %d\n", rc);
    MQTTClient_destroy(&client);
    return rc; 
    */
}
