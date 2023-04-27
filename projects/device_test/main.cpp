
#include "ThinkGearReceiver.h"
#include <boost/asio.hpp>
#include <iostream>
#define BUFSIZE 512

int main()
{
    libThinkGear::ThinkGearReceiver tgReceiver;
    std::string portName;
    int baudRate;
    //tg.test();
    std::cout << "Before continue connect Neurosky device to Bluetooth as Serial Port Protocol\n";
    std::cout << "Press Ctrl+C to exit\n";
    
    std::cout << "\nInput serial port name: ";
    std::cin >> portName;
    std::cout << "\nInput baudrate [1200]: ";
    std::cin >> baudRate;
    if (!baudRate) baudRate = 1200;
    
    boost::asio::io_service io_service;
    boost::asio::serial_port device(io_service, portName);
    device.set_option(boost::asio::serial_port_base::baud_rate(baudRate));
    
    while( true ) {
        unsigned char data[BUFSIZE];
        int size = device.read_some(boost::asio::buffer(data, BUFSIZE));
        for (int i=0; i<size; i++) {
            tgReceiver.readByte(data[i]);
        }
    }
    return 0;
     
}
