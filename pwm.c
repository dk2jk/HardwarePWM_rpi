#include <stdio.h>
#include <unistd.h>

#include <pigpio.h>
#include <pigpiod_if2.h>

#define PIN0 18
#define PIN1 19

int main(void)
{
    int pi;
    int pin0freq,pin0duty;
    int pin1freq,pin1duty;
    double rate0,rate1;

    pi = pigpio_start(0,0);

    set_mode(pi,PIN0,PI_OUTPUT);
    set_mode(pi,PIN1,PI_OUTPUT);

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

    rate0 = (pin0duty / 1000000) * 100;
    rate1 = (pin1duty / 1000000) * 100;

    printf("GPIO18::freq=%dHz:duty=%d:%lf%\n",pin0freq,pin0duty,rate0);
    printf("GPIO19::freq=%dHz:duty=%d:%lf%\n",pin1freq,pin1duty,rate1);

    printf("--Outputting--\n");

    hardware_PWM(pi,PIN0,pin0freq,pin0duty);
    hardware_PWM(pi,PIN1,pin1freq,pin1duty);

    sleep(10);

    printf("\n--END--\n");
    set_mode(pi,PIN0,PI_INPUT);
    set_mode(pi,PIN1,PI_INPUT);

    pigpio_stop(pi);

    return 0;
}
