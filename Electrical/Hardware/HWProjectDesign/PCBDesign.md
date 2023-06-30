## PCB 标识

触点：
NO: Normally Open
NC: Normally Close

原理图原件：
NC：No Connection

## PCB 过孔 (Via)

信号过孔 0.3mm 0.6mm 一般盖油，选择直连

电源过孔可以大一点

## PCB 接口

EN：使能信号接口 （芯片输出给电路）
AD：检测信号接口 （电路输入给 MCU 检测状态）

EMC(Electro Magnetic Compatibility)——电磁兼容

[DataSheet](https://www.alldatasheet.com)

[如何将立创元器件封装库导入 AD 使用（CSDN）](https://blog.csdn.net/m0_50364091/article/details/120053730)

## 封装

[九种常见的元器件封装技术（知乎）](https://zhuanlan.zhihu.com/p/103470579)

## EMI 电磁干扰

(Electromagnetic Interference)

## 模块设计

### 电源

#### BUCK

BUck 电路内部其实是环路，需要将 3 个地尽量靠近连在一起

反馈信号靠近

## Check List

ESD（Electro-Static discharge）静电放电

EMI EMC

### 设计注意

模拟信号避开干扰

PWM，Buck 电路这种震荡电路都是高干扰源，高阻抗地区也是高干扰源，例如 mos 的栅极，因为电阻高，细微的电流变化会造成很大的电压变化。

电源控制芯片反馈电路尽量避免与输出电路接触

模拟信号尽量就近处理，处理后在输送给 mcu

打电流地方加粗，需要不只是大电压地方

滤波电筒要靠近芯片区域，顺序不能颠倒

附铜后检查是否有小的类似天线

尽量区域内布线，能走单面走单面，可以保留地面大面积的地

一些芯片（电源芯片）中间需要接地

避免锐角

Bck 电路内部其实是环路，需要将 3 个地尽量靠近连在一起

反馈信号靠近

