- [MCU 组成](#mcu-组成)
  - [CPU](#cpu)
  - [总线](#总线)
  - [储存器](#储存器)
    - [非易失性储存器](#非易失性储存器)
    - [易失性储存器](#易失性储存器)
    - [FSMC](#fsmc)
    - [AHB 到 APB 的桥（片上外设）](#ahb-到-apb-的桥片上外设)
  - [时钟系统](#时钟系统)
    - [定时器](#定时器)
    - [看门狗（WatchDog）](#看门狗watchdog)
    - [RTC](#rtc)
  - [模拟模块](#模拟模块)
    - [ADC](#adc)
    - [比较器（COMP）](#比较器comp)
  - [总线](#总线-1)
- [Function](#function)
  - [GPIO](#gpio)
  - [中断](#中断)
    - [EXTI (Extern Interrupt)](#exti-extern-interrupt)
  - [USART](#usart)
- [I2C](#i2c)
- [Project](#project)
- [Check List](#check-list)

## MCU 组成

### CPU

### 总线

ICode 总线

DCode 总线 (Data): 读取数据

System 总线：访问外设寄存器

DMA (Direct Memory Access) 总线：传输数据

因为数据可以被 DCode 总线和 DMA 总线访问，所以为了避免访问冲突，在取数的时候需要经过一个总线矩阵来仲裁，决定哪个总线取数。

### 储存器

#### 非易失性储存器

掉点后数据不会丢失
Flash Memory

System Memory: ROM，MCU 出厂后不可以更改，一般内置 bootloader，帮助串口下载

> ROM: 只读存储器（Read-Only Memory）

#### 易失性储存器

掉电后数据丢失
RAM

SRAM（Static Random Access Memory）静态随机存储器

> [SRAM 科普](https://zhuanlan.zhihu.com/p/392836594)

#### FSMC

#### AHB 到 APB 的桥（片上外设）

片上外设区分为 3 条总线，根据不同的外设速度，不同总线挂载着不同的外设，APB1 挂载低速外设，APB2 和 AHB 挂载高速外设。

### 时钟系统

HSI (Inside)

HSE (External)

STM32 有 4 个独立时钟源:HSI、HSE、LSI、LSE。

①HSI 是高速内部时钟，RC 振荡器，频率为 8MHz。  
②HSE 是高速外部时钟，可接石英/陶瓷谐振器，或者接外部时钟源，频率范围为 4MHz~16MHz。
③LSI 是低速内部时钟，RC 振荡器，频率为 40kHz。
④LSE 是低速外部时钟，接频率为 32.768kHz 的石英晶体。
⑤PLL 为锁相环倍频输出，其时钟输入源可选择为 HSI/2、HSE 或者 HSE/2。倍频可选择为 2~16 倍，但是其输出频率最大不得超过 72MHz。

其中 LSI 是作为 IWDGCLK(独立看门狗)时钟源和 RTC 时钟源 而独立使用

而 HSI 高速内部时钟 HSE 高速外部时钟 PLL 锁相环时钟 这三个经过分频或者倍频 作为系统时钟来使用

> 对于 SYSCLK、HCLK、PCLK2、PCLK1 这 4 个时钟的配置一般是：PCLK2=HCLK=SYSCLK=PLLCLK=72MHz，PCLK1=HCLK/2=36MHz。(STM32 库开发实战指南)

#### 定时器

| 定时器种类             | 位数 | 计数器模式          | 产生 DMA 请求 | 捕获/比较通道 | 互补输出                                     | 特殊应用场景 |
| ---------------------- | ---- | ------------------- | ------------- | ------------- | -------------------------------------------- | ------------ |
| 高级定时器(TIM1,TIM8)  | 16   | 向上，向下，向上/下 | 4             | 有            | 带死区控制盒鱉急刹车，可威用手 PWM 电机控制  |
| 通用定时器(TIM2~TIM5)  | 16   | 向上，向下，向上/下 | 4             | 无            | 通用．定时计数，PWM 输出．输入拥获，输出比较 |
| 基本定时器(TIM6, TIM7) | 16   | 向上，向下，向上/下 | 0             | 无            |

#### 看门狗（WatchDog）

原理：定时器计时，超出时间产生复位信号

IWDG: 独立看门狗
WWDG: 窗口看门狗

|          |            IWDG             |           WWDG            |
| :------: | :-------------------------: | :-----------------------: |
| 独立时钟 | 有独立时钟，40KHZ RC 振荡器 | 无独立时钟，使用 CPU 时钟 |
|   中断   |             有              |            无             |
| 控制方法 |         硬件或软件          |           软件            |
| 时钟长度 |          只有下限           |       有下限和上限        |
|          |          12 位递减          |         7 位递减          |

独立看门狗(IWDG)是独立于系统之外，因为有独立时钟，所以不受系统影响的系统故障探测器。主要用于监视硬件错误。

窗口看门狗(WWDG)是系统内部的故障探测器，时钟与系统相同。如果系统时钟不走了，这个狗也就失去作用了。主要用于监视软件错误。

#### RTC

### 模拟模块

#### ADC

#### 比较器（COMP）

电压比较，输出数字信号大于$V_{ref}$或小于$V_{ref}$

### 总线

## Function

### GPIO

输出方式： 输出(推挽或开漏)、输入(带或不带上拉或下拉)

| 程序中标识            | 模式         | -               | -                         |
| --------------------- | ------------ | --------------- | ------------------------- |
| GPIO_Mode_Out_PP      | 推挽输出     | Push-Pull       | General purpose output    |
| GPIO_Mode_Out_OD      | 开漏输出     | Open-Drain      |                           |
| GPIO_Mode_AF_PP       | 复用推挽输出 | Push-Pull       | Alternate Function output |
| GPIO_Mode_AF_OD       | 复用开漏输出 | Open-Drain      |                           |
| GPIO_Mode_AIN         | 模拟输入     | Analog          | Input                     |
| GPIO_Mode_IN_FLOATING | 浮空输入     | Input floating  |                           |
| GPIO_Mode_IPD         | 下拉输入     | Input pull-down |                           |
| GPIO_Mode_IPU         | 上拉输入     | input pull-up   |                           |

### 中断

使用 NVIC 统一管理中断，每个中断通道都拥有 16 个可编程的优先等级，可对优先级进行分组，进一步设置抢占优先级和响应优先级

抢占优先级：可以暂停CPU现有的操作。
响应优先级：决定CPU执行完现有任务后执行其他任务的顺序（排队插队）

- NVIC的中断优先级由优先级寄存器的4位 （0-15） 决定，这4位可以进行切分，分为高n位的抢占优先级和低4-n位的响应优先级
- 抢占优先级高的可以中断能套，响应优先级高的可以优先排队，抢占优先级和响应优先级均相同的按中断号排队

#### EXTI (Extern Interrupt)
GPIO电源中断

### USART

[USART Note](../../Electrical/Hardware/DataTransfer/DataTransferNote.md#usart)

USART 发送数据时，使用发送数据寄存器（TDR）传入发送移位寄存器，数位位移进行发送给 TX 引脚
![](src/img/USART_BlockDiagram_STM32.png)
图中上半部分为数据传输部分，下半部分为控制部分

USART 输入采样时，需要控制其采样时处于每个 bit 信号发送的中间位置。在接收数据刚开始时 MCU 会使用 16 倍的采样速率进行判断采样的中间点。


## I2C
[USART Note](../../Electrical/Hardware/DataTransfer/DataTransferNote.md#i2c-inter－integrated-circuit)
## Project

![](src/img/STM32库文件关系.png)

## Check List
