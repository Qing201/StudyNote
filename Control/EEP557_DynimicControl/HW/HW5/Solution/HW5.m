% Homework #5
Rp = 1;                         % motor resistance [ohms]
Lp = 1e-3;                      % motor inductance [H]
Jp = 1e-5;                      % motor inertia [kg-m^2]
bp = 1e-5;                      % motor viscous damping [Nm/(rad/s)]
Kt = 0.2;                       % motor torque constant [Nm/A]
Ke = Kt;                        % motor back EMF constant [V/(rad/s)]
Kth = Kt;                       % estimated value of motor torque constant
Keh = Ke;                       % estimated value of motor back EMF constant
Ktheta = 0.006/(2*pi);          % actuator ballscrew pitch [m/rad]
L = 1;                          % distance between actuators [m]

z_s_mag = 0.010;                % surface position command magnitude [m]
z_s_freq = 10;                  % surface position command frequency [Hz]
theta_s_mag = 10*pi/180;        % surface position command magnitude [rad]
theta_s_freq = 10;              % surface position command frequency [Hz]

%% gains

% (s+t1)(s+t2)(s+t3) = s^3 + (t1+t2+t3)s^2 + (t1t2+t1t3+t2t3)s + t1t2t3

% translational axis CE
% s^3 + (Ktheta^2*bz+2*bp)/(2*Jp)s^2 + (Ktheta^2*Ksz)/(2*Jp)s + (Ktheta^2*Kisz)/(2*Jp)

t1z = 2*pi*0.2;                 % translational integrated position loop BW [rad/sec]
t2z = 2*pi*2;                   % translational position loop BW [rad/sec]
t3z = 2*pi*20;                  % translational velocity loop BW [rad/sec]

t1theta = 2*pi*0.05;            % rotational integrated position loop BW [rad/sec]
t2theta = 2*pi*0.5;             % rotational position loop BW [rad/sec]
t3theta = 2*pi*5;               % rotational velocity loop BW [rad/sec]

bz = (2*Jp*(t1z+t2z+t3z)-2*bp)/Ktheta^2;   % translational active damping [N/(m/s)]
Ksz = 2*Jp*(t1z*t2z+t1z*t3z+t2z*t3z)/Ktheta^2;   % translational active stiffness [N/m]
Kisz = 2*Jp*(t1z*t2z*t3z)/Ktheta^2;        % translational active integrated stiffness [N/(m-s)]

btheta = (L^2*Jp*(t1theta+t2theta+t3theta)-L^2*bp)/(2*Ktheta^2);   % rotational active damping [N/(m/s)]
Kstheta = L^2*Jp*(t1theta*t2theta+t1theta*t3theta+t2theta*t3theta)/(2*Ktheta^2);   % rotational active stiffness [N/m]
Kistheta = L^2*Jp*(t1theta*t2theta*t3theta)/(2*Ktheta^2);        % rotational active integrated stiffness [N/(m-s)]

velocity_command_enable = 0;    % enable velocity command [1 - enabled; 0 - disabled]
