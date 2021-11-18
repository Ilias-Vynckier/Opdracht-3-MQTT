# Embedded Systems 2 opdracht 3.

## first install paho mqtt librqry + examples

    mkdir MQTTClients
    cd MQTTClients
    sudo git clone https://github.com/janderholm/paho.mqtt.c.git
    cd paho.mqtt.c
    sudo apt-get install libssl-dev
    sudo makesudo make install

## Client

  Install library for i2c
  
    sudo apt-get install wiringpi
   
  Build file and execute
  
    cd build
    sudo make
    sudo ./opdracht3-client
    
## Sever
