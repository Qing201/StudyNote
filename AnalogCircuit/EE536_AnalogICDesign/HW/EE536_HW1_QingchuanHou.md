EE536 HW1
Qingchuan Hou
10/29/2022

\



1. *Why are the dimensions of an antenna usually related to the wavelength of the signal a receiver is trying to detect? What is the length of an antenna at 2.4GHz and 5.0GHz? Describe the length of an Antenna relative to the wavelength. (5 pts)*

When the length of the antenna is 1/4 related to the wavelength, the movement of charges in the antenna can resonate with the signal. The transmission and reception conversion efficiency of the antenna is the highest.

$ \lambda = c/f_c$ (c is the speed of light, $c = 3\times 10^8 m/s$)

$\lambda(2.4GHz) = 3\times 10^8 / (2.4 \times 10^9)  = 0.125 m$
$l_{ant} = 0.125m/4 =31.25 mm$

$\lambda(5GHz) = 3\times 10^8 / (5 \times 10^9)  = 0.06 m$
$l_{ant} = 0.06m/4 =15 mm$

The wavelength of the signal is $\lambda$, then the length of the antenna is 1/4 of the wavelength.

2. *What factors influence the minimum detectable signal in a receiver? (5 pts)*

To receive the minimum detectable signal, we need to let the noise be minimum compared to the signal we want to find the signal. The factors to reduce the noise influence:
- Use minimum bandwidth.
- Minimum temperature
- Signal-Noise Ratio
- Noise Factor(NF)

3. *For receivers used in mobile communication, what environmental factors will influence receive signal quality? Ie. what physical effects, outside the receiver, will influence the radios performance? (5pts)*
- Distance and direction of signal tower
- Transmission Power
- Network Congestion
- Weather and Geography Environment
- Antenna efficiency and gain
- Temperature (Noise)

4. *Assuming isotropic radiation from a radio transmitting 10Watts, what would be the power of a signal at the input of a receiver 100meters away? 1km away? Assume the antenna efficiency is 100%. (5pts)*

   Assume the frequency of the signal is $f$ and the wavelength of the signal is  $ \lambda = c/f$

   The power ratio between transmitted power and received power is
   $$
   \frac{P_r}{P_t} = [\frac{\sqrt{G_l}\lambda}{4\pi d}]^2
   $$
   For isotropic radiation, $G_l$ = 1. Therefore,
   $$
   P_r = P_t  [\frac{\lambda}{4\pi d}]^2
   $$
   When d = 100 m,
   $$
   P_r = 10  [\frac{\lambda}{4\pi *100}]^2 = \frac{\lambda}{1.6*10^4\pi}
   $$
   When d = 1km,
   $$
   P_r = 10  [\frac{\lambda}{4\pi *1000}]^2 = \frac{\lambda}{1.6*10^6\pi}
   $$
   

5. *You are to design a Power Amplifier (PA) for the new 4th Generation Wireless Standard, WiMAX, which uses a multi-carrier system. The maximum desired carriers at the input are 0dBm, while the maximum desired carriers at the PA output need to be +30dBm. In addition, to guarantee that you don’t interfere with other “adjacent” and “alternate” channel users, your absolute intermodulation must not be greater than -10dBm at the output. The situation is illustrated below. What input and output IP$_3$ does this PA need? What output HD$_3$ do you need? (10 points)*

The gain for this PA is $A_s = A_{adj}$ is 30dbm = $31.62mV_p$.
The desired output should be 40dbm greater than adjacent and alternate channel, then in the output:
$$
20log|a_1 A_{sig}| - 40dbm = 20log|\frac{3}{4}a_3 A_{adj}^3|
$$

$$
|\frac{a_1}{a_3}| = |\frac{3000}{4} A^2|
$$

$$
IIP_3 = \sqrt{\frac{4}{3}|\frac{a_1}{a_3}|} = 31.62V_p \approx 90dBm
$$

$$
IM_3 = \frac{3}{4}\frac{a_3}{a_1}A^2 = 0dbm
$$





