# Dynamics Of Controlled Systems

```diff
+ Week 1 Class 1, Wed, Oct/3/2022
```
 

![](src/img/2022-10-09-18-33-58.png) 

Mason's method?

HW: Simulink symbolic


```diff
+ Week 2 Class 2, Mon, Oct/10/2022,
```

### Operating Point Analysis

#### Taylor Series Approximation

![](src/img/OperatingPointSys.png)



$$\Delta \mathcal{F}(x) = \mathcal{F}(x) - \mathcal{F}(x_{op}) \cong \Delta x \cdot\mathcal{F'}(x_{op}) \qquad x = x_{op}+\Delta x$$

Neglects higher order terms, because the 1st derivative term can give a good proximation on $\Delta \mathcal{F}$

Example: Cos(x)

![](src/img/OperatingPointSysCosEx.png)

Multi-variable Operating System:
![](src/img/MultiVarOpSys.png)

#### Car Model:

![](src/img/CarModelNonlinearModel.png) \
![](src/img/CarModelSysEq.png) 

Operating:

![](src/img/CarModelOperatingSys.png)

![](src/img/CarModelOperatingSysEq.png) \
![](src/img/CarModelOperatingSysBlock.png) \
![](src/img/CarModelOpSysSolve.png)


-3db

$x(t) = sin(2 \pi f_0 t) --> y(t) = 0.707sin(2 \pi f_0 t)$

-3db $\approx$ 0.5  &emsp; 0.707 $\approx$ 1/ $\sqrt{2}$



