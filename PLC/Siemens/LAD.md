# LAD (梯形图)

- [LAD (梯形图)](#lad-梯形图)
  - [程序](#程序)
    - [输入](#输入)
    - [沿指令](#沿指令)
      - [P\_TRIG and N\_TRIG](#p_trig-and-n_trig)
    - [定时器和计数器](#定时器和计数器)
      - [S\_ODT接通延时S5定时器](#s_odt接通延时s5定时器)
  - [比较指令和移动指令](#比较指令和移动指令)
    - [Example](#example)
      - [B站教程](#b站教程)


## 程序

[快速西门子 PLC 入门（适合零基础）- 知乎](https://zhuanlan.zhihu.com/p/154615808)

I: input
Q:
| 名称 | 符号 |
| -------------------- | --- |
| 输入继电器         | I   |
| 输出继电器           | Q   |
| 通用辅助继电器       | M   |
| 特殊继电器           | SM  |
| 变量存储器           | V   |
| 局部变量存储器       | L   |
| 顺序控制继电器       | S   |
| 定时器               | T   |
| 计数器               | C   |
| 模拟量输入映像寄存器 | AI  |
| 模拟量输出映像寄存器 | AQ  |
| 高速计数器           | HC  |
| 累加器               | AC  |


### 输入
常开按钮：按下接通，松开断开

上升沿按钮：（P）按下后会导通一瞬间

下降沿按钮：（N）松开后接通一瞬间 

### 沿指令

#### P_TRIG and N_TRIG
P上升沿扫描，N下降沿扫描，扫描到沿信号后发送一次跳变信号

### 定时器和计数器

定时器：根据时间倒计时
计数器：记录（按键）次数

#### S_ODT接通延时S5定时器
[S5Time定时器](https://www.ad.siemens.com.cn/productportal/Prods/published/Prog/Prog_3.1/Prog_3.1.html)


## 比较指令和移动指令

移动指令：按下按钮附值
比较指令：比较器

### Example

#### B站教程
[二进制奇偶数操作](https://www.bilibili.com/video/BV1qF411X7ZY?p=15&vd_source=a5064f97cca6d561d6f9195f615bd7a0)

P22 [按键画面切换](https://www.bilibili.com/video/BV1qF411X7ZY?p=22&vd_source=a5064f97cca6d561d6f9195f615bd7a0)