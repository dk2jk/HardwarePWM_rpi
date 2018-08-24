# HardwarePWM_rpi

Raspberry Pi2以降でハードウェアPWMを出力します。

pigpioを使用するため
$sudo apt-get install python-pigpio

でpigpioをダウンロードした後、

$sudo pigpiod
を実行して下さい

$python pwm.py
で起動します。

18番ピンと19番ピンに周波数とduty比を設定したら10秒間pwm波が出力されます。
