% syms i x e f_d e N mu_0 A x g R m x_i K_s v Lx_d

R = 1;
x_i = 1e-2;
g = 5*1e-4;
N = 100;
A = 4*1e-4;
mu_0 = 4*pi*1e-7;
m = 0.05;
K_s = 100;

x = 1e-3;

i = sqrt(2*K_s*(x_i-x)*(x+g)^2/(N^2*mu_0*A));
e = i*R;
v = 0;


fd_m = 1e-4;
fd_f = 10;
