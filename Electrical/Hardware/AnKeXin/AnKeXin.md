- [53](#53)
  - [继电器电路](#继电器电路)
    - [下拉电阻](#下拉电阻)
    - [二极管并联继电器 （续流二极管）](#二极管并联继电器-续流二极管)
    - [串联电容](#串联电容)
  - [485通讯](#485通讯)
    - [TVS管](#tvs管)
    - [数字隔离器](#数字隔离器)
      - [电源隔离](#电源隔离)
  - [ABUS](#abus)
    - [线性稳压器](#线性稳压器)
  - [电源管理](#电源管理)

# 53

## 继电器电路 
### 下拉电阻
防止mos G极悬空，保护
### 二极管并联继电器 （续流二极管）
续流二极管通常和储能元件一起使用，其作用是防止电路中电压电流的突变，为反向电动势提供耗电通路
[参考](https://zhuanlan.zhihu.com/p/72959795)
### 串联电容
![](src/img/继电器前置电路.png)
电容的作用是使用电容的特性来控制点动时间。（也可以以软件的方式实现）

## 485通讯



### TVS管
Transient Voltage Suppressor
[知乎](https://zhuanlan.zhihu.com/p/366516831)

tvs管是吸收浪涌功率用的，能在极短时间内承受反向电压冲击，使两极间的电压钳位于一个特定电压上，避免后面的电路受到冲击，过压保护

### 数字隔离器

CEU8721N1 磁耦隔离

EL3H7-G 光隔离

#### 电源隔离
VPS8504 微功率隔离电源专用芯片
[CSDN](https://blog.csdn.net/TEL15622383762/article/details/128159688)


## ABUS

ULN2803


上输入，下输出


### 线性稳压器

LDO（low dropout regulator，低压差线性稳压器）



## 电源管理
