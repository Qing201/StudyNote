- [adv](#adv)

## Week 1

Supervised Learning: give the object name

Unsupervised Learning: don't give the object name, Machine don't know what it is, only know if there have two objects are different.

### data 
1. Take care of Noise
2. Missing Values
3. Normalize attribute:
   > 面积大，bedroom小，为了使平等，normalize所有data使其拥有相同的权重，例如把所有data normalize 到=1到1

   > Mean Normalization:
   X = (X – column_mean) / (column_max – column_min)
   (For Linear model, usually do mean normalization for all contribute)

Normal Equation:
![Normal_Equation](Image/normal-equation.jpg)
### K-fold Cross Validation

### Objective (Loss) Function
![Loss](Image/Loss_equation.png)
### Linear Regression
#### Lasso: 
![Lasso](Image/Lasso.png)
Benefits: Removes un-important features

#### Ridge: 
![Ridge](Image/Ridge.png)

 $||w||_2^2 = w_1^2 + w_2^2$

Benefits: No larger weights

#### Elastic Net:


Loss fuction

numerical value

categorical value

```diff
+ Class 2.2
```

Stochastic gradient descent

# Classfication

## Linear Separability

Linear Separability: logistic regretion; SVM

> Non-linear Separability: Deep Learnig; Random Forest

### Logistic Regretion

Sigmoid Function (logistic function)

```diff
- 所有ML问题的根本就是让你的模型中的Loss尽可能的small。越小就越贴近于真实值。 所有的Loss function 都是covers function. covers function的简单解释是有可以趋向的最小值。例如 y=x^2 的形状 （covers function是自己的理解，不一定正确）。所以Loss可以趋向于一个值。 
convconv Make the loss as small as it can
```

```diff
+ Class 3.1
```

