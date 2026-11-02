clc;
clear;
close all;

%% Load data
y_data = load('outputEverything.mat');
e_data = load('errorEverything.mat');

% Extract signals
t_y = y_data.output.Time(:);
position = y_data.output.Data(:);

t_e = e_data.error.Time(:);
error = e_data.error.Data(:);

%% Constant velocity interval
t_start = 0.22;
t_end = 5.41;

idx_y = (t_y >= t_start) & (t_y <= t_end);
idx_e = (t_e >= t_start) & (t_e <= t_end);

t_const_vel = t_y(idx_y);
y_const_vel = position(idx_y);

t_error_const = t_e(idx_e);
e_const_vel = error(idx_e);

%% Calculate performance metrics
RMS_error = rms(e_const_vel);
max_abs_error = max(abs(e_const_vel));

total_displacement = sum(abs(diff(y_const_vel)));
net_displacement = abs(y_const_vel(end) - y_const_vel(1));

fprintf('RMS tracking error: %.5f mrad\n', RMS_error*1000);
fprintf('Maximum absolute error: %.5f mrad\n', max_abs_error*1000);
fprintf('Total displacement: %.3f rad\n', total_displacement);
fprintf('Net displacement: %.3f rad\n', net_displacement);

%% Find maximum and minimum tracking errors
[max_error, idx_max] = max(e_const_vel);
[min_error, idx_min] = min(e_const_vel);

t_max = t_error_const(idx_max);
t_min = t_error_const(idx_min);

fprintf('Maximum error: %.5f mrad at %.3f s\n', ...
    max_error*1000, t_max);
fprintf('Minimum error: %.5f mrad at %.3f s\n', ...
    min_error*1000, t_min);

%% Figure 1: Complete measurement
figure('Color','w','Position',[150 150 1100 450]);

% Position
yyaxis left
h1 = plot(t_y, position, ...
    'Color','#0072BD','LineWidth',1.2);
ylabel('Position [rad]');
hold on;

% Highlight selected constant velocity interval
yl = ylim;

h_region = patch( ...
    [t_start t_end t_end t_start], ...
    [yl(1) yl(1) yl(2) yl(2)], ...
    [0.5 0.5 0.5], ...
    'FaceAlpha',0.15, ...
    'EdgeColor','none', ...
    'HandleVisibility','off');

uistack(h_region,'bottom');

% Tracking error
yyaxis right
h2 = plot(t_e, error*1000, ...
    'Color','#D95319','LineWidth',1.1);
ylabel('Tracking Error [mrad]');

% Formatting
xlabel('Time [s]');
title('Position 2nd Mass and Positioning Error');
legend([h1 h2], {'Position','Error'}, ...
    'Location','best');

grid on;
box on;
xlim([t_y(1) t_y(end)]);

ax = gca;
ax.YAxis(1).Color = '#0072BD';
ax.YAxis(2).Color = '#D95319';
ax.FontSize = 11;
ax.LineWidth = 1;

%% Figure 2: Constant velocity interval
figure('Color','w','Position',[200 200 1100 450]);

% Position
yyaxis left
h1 = plot(t_const_vel, y_const_vel, ...
    'Color','#0072BD','LineWidth',1.5);
ylabel('Position [rad]');

% Tracking error
yyaxis right
h2 = plot(t_error_const, e_const_vel*1000, ...
    'Color','#D95319','LineWidth',1.2);
hold on;

% Mark maximum error
h3 = plot(t_max, max_error*1000, 'ro', ...
    'MarkerSize',8, ...
    'MarkerFaceColor','r', ...
    'LineWidth',1.2);

% Mark minimum error
h4 = plot(t_min, min_error*1000, 'ko', ...
    'MarkerSize',8, ...
    'MarkerFaceColor','k', ...
    'LineWidth',1.2);

% Add peak value labels
text(t_max, max_error*1000, ...
    sprintf('  Max: %.3f mrad', max_error*1000), ...
    'FontSize',10, ...
    'FontWeight','bold', ...
    'Color','r', ...
    'VerticalAlignment','bottom');

text(t_min, min_error*1000, ...
    sprintf('  Min: %.3f mrad', min_error*1000), ...
    'FontSize',10, ...
    'FontWeight','bold', ...
    'Color','k', ...
    'VerticalAlignment','top');

ylabel('Tracking Error [mrad]');

% Formatting
xlabel('Time [s]');
title('Position 2nd Mass and Positioning Error During Constant Velocity');

legend([h1 h2 h3 h4], ...
    {'Position','Error','Maximum Error','Minimum Error'}, ...
    'Location','southeast');

grid on;
box on;
xlim([t_start t_end]);

ax = gca;
ax.YAxis(1).Color = '#0072BD';
ax.YAxis(2).Color = '#D95319';
ax.FontSize = 11;
ax.LineWidth = 1;

%% Performance annotation
RMS_text = sprintf([ ...
    'RMS Tracking Error = %.2f mrad\n' ...
    'Maximum Absolute Error = %.2f mrad\n' ...
    'Angular Displacement = %.4f rad'], ...
    RMS_error*1000, max_abs_error*1000, net_displacement);

% Position textbox in northeast corner
text(0.98, 0.98, RMS_text, ...
    'Units','normalized', ...
    'FontSize',10, ...
    'FontWeight','bold', ...
    'BackgroundColor','white', ...
    'EdgeColor',[0.7 0.7 0.7], ...
    'HorizontalAlignment','right', ...
    'VerticalAlignment','top');

exportgraphics(gcf, 'Everything.png', 'Resolution', 300);
exportgraphics(gcf, 'Everything_Error.png', 'Resolution', 300);