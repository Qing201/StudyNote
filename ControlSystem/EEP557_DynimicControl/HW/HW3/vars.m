%% Variables
R = 1;
x_i = 1e-2;
g = 5*1e-4;
N = 100;
A = 4*1e-4;
mu_0 = 4*pi*1e-7;
m = 0.05;
K_s = 100;

fd_m = 1e-4;
fd_f = 1;

x_op = 3*1e-3;

i_op = sqrt(2*K_s*(x_i-x_op)*(x_op+g)^2/(N^2*mu_0*A));
e_op = i_op*R;
v_op = 0;



%% Simulation with different x_op and fd_f

x_ops = [1*1e-3, 3*1e-3, 6*1e-3, 9*1e-3];
figNum = 0;

for x_opNum = 1:4
    x_op = x_ops(x_opNum);
    i_op = sqrt(2*K_s*(x_i-x_op)*(x_op+g)^2/(N^2*mu_0*A));
    e_op = i_op*R;

        
    for fd_f = 1:10
    
        % Simulink Simulation
        simOut = sim('HW3_sim.slx','SimulationMode','normal',...
                    'SaveState','off', 'StopTime','1000',...
                    'SaveOutput','on','OutputSaveName','xout',...
                    'SaveFormat', 'Dataset');
        outputs = simOut.xout;
        
        x = (outputs.get('x').Values);
        
        % Plots
        if (fd_f == 1 || fd_f == 6)     % Plot 1-5 and 6-10 separately
            figNum = figNum+1;
        end
        
        figure(figNum)
    
        if (fd_f > 5) 
            subplot(5,1,fd_f-5);
        else
            subplot(5,1,fd_f);
        end
    
        plot(x)
        title(['x_op:', num2str(x_op*1e+3), 'mm  f:' num2str(fd_f), 'Hz'])    
    end
   
end


