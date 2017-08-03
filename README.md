# AVR Library for PIXY Camera

This is a AVR library for PIXY camera. Currently the library is made for Atmega328P MCU. Change relevent registers when you're using it for another MCU. USART or SPI communication methods could be used to communicate with the PIXY in this library.


## Getting Started

You need to install avrdude in your PC in order to upload this code to the MCU. Download everything and goto the file directory.

```
make all & make program
```

Now use above code to compile and upload the code. Remember to connect PIXY cam to the MCU with either USART or SPI.


## Authors

* **Rashintha Maduneth** - *Porting the library to AVR*

See also the list of [contributors](https://github.com/pixy-avr/contributors) who participated in this project.


## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details


## Acknowledgments

* PIXY Porting guide
* Arduino PIXY Library
