# STM32

### 时钟系统
STM32 有4个独立时钟源:HSI、HSE、LSI、LSE。
①、HSI是高速内部时钟，RC振荡器，频率为8MHz，精度不高。
②、HSE是高速外部时钟，可接石英/陶瓷谐振器，或者接外部时钟源，频率范围为4MHz~16MHz。
③、LSI是低速内部时钟，RC振荡器，频率为40kHz，提供低功耗时钟。　 
④、LSE是低速外部时钟，接频率为32.768kHz的石英晶体。

其中LSI是作为IWDGCLK(独立看门狗)时钟源和RTC时钟源 而独立使用 

而HSI高速内部时钟 HSE高速外部时钟 PLL锁相环时钟  这三个经过分频或者倍频 作为系统时钟来使用

## 管脚功能


[UART & USART](../Electrical/Analog/Signal/SignalNote.md#uart)