- [Basic Components](#basic-components)
  - [Resistor](#resistor)
  - [Capacitor](#capacitor)
    - [Application](#application)
  - [Inductor](#inductor)
  - [](#)
- [RLC Circuit](#rlc-circuit)
  - [Basic RLC](#basic-rlc)
    - [Resonate](#resonate)
  - [Frequency Filter](#frequency-filter)
    - [Low-Pass and High-Pass Filter](#low-pass-and-high-pass-filter)
    - [Band Pass and Band Stop Filter](#band-pass-and-band-stop-filter)
- [Bipolar Junction Transistors (BJT)](#bipolar-junction-transistors-bjt)
  - [PNP and NPN](#pnp-and-npn)
  - [Amplifier](#amplifier)
- [MOS](#mos)
- [电子原件](#电子原件)
  - [隔离](#隔离)
    - [隔离电源模块](#隔离电源模块)
    - [数字隔离器](#数字隔离器)
  - [TVS管](#tvs管)
  - [线性稳压器](#线性稳压器)
    - [PSRR(Power Supply Ripple Rejection)](#psrrpower-supply-ripple-rejection)

**Analog Circuit**

## Basic Components

### Resistor

### Capacitor

#### Application
[电容在电路中的27种经典应用(知乎)](https://zhuanlan.zhihu.com/p/82664931)
[VCC与GND之间的电容](https://zhuanlan.zhihu.com/p/550387466)

### Inductor





###

## RLC Circuit

### Basic RLC
[Series RLC](https://www.electronics-tutorials.ws/accircuits/series-circuit.html)
![](src/img/RLC_Resistance.png)

#### Resonate
The resonate frequency of CL circuit is:
$$f_0 = \frac{1}{2\pi \sqrt{L C}}$$

When resonate:
1. the series LC circuit will have infinity impedance,consider as **open circuit** (the current in LC loop is back-forth)
2. the parallel LC circuit will have 0 impedance, consider as **short circuit**
### Frequency Filter

#### Low-Pass and High-Pass Filter
Reluctance Frequency: $f_r = \frac{1}{2\pi \sqrt{RC}} = \sqrt{f_Hf_L}$

Inductor(L): Pass Low level frequency
Conductor(C): Pass High level frequency

![](src/img/FrequencyFilter.png)

#### Band Pass and Band Stop Filter

![](src/img/BandFrequencyFilter.png)

## Bipolar Junction Transistors (BJT)

### PNP and NPN
![](src/img/BJT.png)
base, collector, emitter

The arrow is current direction for emitter

![](src/img/BJTRegion.png)

Cutoff: $V_{BE} < 0.6, \ V_{CE} = V_{CC}, \ I_C = 0 $
Active: $V_{BE} \ge 0.6, \ 0 < V_{CE} < V_{CC}, \ I_C > 0 $
Saturation: $V_{BE} > 0.6, \ V_{CE} = 0 $

### Amplifier


## MOS

current mirror

amplifying transconductance


## 电子原件

### 隔离

#### 隔离电源模块


#### 数字隔离器
在电气隔离器状态下实现数字信号传递

**光耦隔离**
optical coupler 

**容耦隔离**

**磁耦隔离**
磁耦是芯片级变压器隔离技术


### TVS管
Transient Voltage Suppressor
[知乎](https://zhuanlan.zhihu.com/p/366516831)

tvs管是吸收浪涌功率用的，能在极短时间内承受反向电压冲击，使两极间的电压钳位于一个特定电压上，避免后面的电路受到冲击，过压保护



### 线性稳压器

LDO（low dropout regulator，低压差线性稳压器）

#### PSRR(Power Supply Ripple Rejection)