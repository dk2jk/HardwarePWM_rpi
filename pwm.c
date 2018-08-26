#include <stdio.h>
#include <unistd.h>

#include <pigpio.h>
<<<<<<< HEAD
#include <pigpiod_if2.h>
=======
>>>>>>> 4d332827346fcc8cd513e336c46652c8a51e846c

#define PIN0 18
#define PIN1 19

int main(void)
{
<<<<<<< HEAD
    int pi;
=======
>>>>>>> 4d332827346fcc8cd513e336c46652c8a51e846c
    int pin0freq,pin0duty;
    int pin1freq,pin1duty;
    double rate0,rate1;

<<<<<<< HEAD
    pi = pigpio_start(0,0);

    set_mode(pi,PIN0,PI_OUTPUT);
    set_mode(pi,PIN1,PI_OUTPUT);
=======
    if(gpioInitialise() < 0){
        printf("ERROR\n");
        return 1;
    }

    gpioSetMode(PIN0,PI_OUTPUT);
    gpioSetMode(PIN1,PI_OUTPUT);
>>>>>>> 4d332827346fcc8cd513e336c46652c8a51e846c

    printf("Hardware PWM for Raspberry Pi by c\n");

    printf("Please set the frequency of GPIO18.[0-125000000]\n");
    printf(">> ");
    scanf("%d",&pin0freq);

    printf("Please set the duty of GPIO18.[0-1000000]\n");
    printf(">> ");
    scanf("%d",&pin0duty);

    printf("Please set the frequency of GPIO19.[0-125000000]\n");
    printf(">> ");
    scanf("%d",&pin1freq);

    printf("Please set the duty of GPIO19.[0-125000000]\n");
    printf(">> ");
    scanf("%d",&pin1duty);

<<<<<<< HEAD
    rate0 = (double)pin0duty / 1000000 * 100;
    rate1 = (double)pin1duty / 1000000 * 100;
=======
    rate0 = (pin0duty / 1000000) * 100;
    rate1 = (pin1duty / 1000000) * 100;
>>>>>>> 4d332827346fcc8cd513e336c46652c8a51e846c

    printf("GPIO18::freq=%dHz:duty=%d:%lf%\n",pin0freq,pin0duty,rate0);
    printf("GPIO19::freq=%dHz:duty=%d:%lf%\n",pin1freq,pin1duty,rate1);

<<<<<<< HEAD
    printf("--Outputting--\n");

    hardware_PWM(pi,PIN0,pin0freq,pin0duty);
    hardware_PWM(pi,PIN1,pin1freq,pin1duty);
=======
    printf("--Outputting--");

    gpioHardwarePWM(PIN0,pin0freq,pin0duty);
    gpioHardwarePWM(PIN1,pin1freq,pin1duty);
>>>>>>> 4d332827346fcc8cd513e336c46652c8a51e846c

    sleep(10);

    printf("\n--END--\n");
<<<<<<< HEAD
    set_mode(pi,PIN0,PI_INPUT);
    set_mode(pi,PIN1,PI_INPUT);

    pigpio_stop(pi);
=======
    gpioSetMode(PIN0,PI_INPUT);
    gpioSetMode(PIN1,PI_INPUT);

    gpioTerminate();
>>>>>>> 4d332827346fcc8cd513e336c46652c8a51e846c

    return 0;
}
