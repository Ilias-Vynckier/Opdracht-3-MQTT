# Embedded Systems 2 opdracht 3.

  Read temperature of TC74 zith the client and send  the value over MQTT. The Server receives the value over MQTT and places it in a database.

## First install paho mqtt librqry + examples

    mkdir MQTTClients
    cd MQTTClients
    sudo git clone https://github.com/janderholm/paho.mqtt.c.git
    cd paho.mqtt.c
    sudo apt-get install libssl-dev
    sudo make
    sudo make install

## Client

  Enable i2c
    
    sudo raspi-config
    5. Interfacing options
    P5 I2C ENABLE/DISABLE

  Install library for i2c
  
    sudo apt-get install wiringpi
   
  Build file and execute
  
    cd build
    sudo make
    sudo ./opdracht3-client
    
## Sever
