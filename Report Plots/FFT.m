clc;
clear;

%% Load data
y_data = load('output4HzSineWave.mat');
e_data = load('error4HzSineWave.mat');

% Extract signals
t_y = y_data.output.Time(:);
position = y_data.output.Data(:);

t_e = e_data.error.Time(:);
error = e_data.error.Data(:);

L = length(error);
Fs = 4000;
Y = fft(error);
P2 = abs(Y/L);
P1 = P2(1:L/2+1);
P1(2:end-1) = 2*P1(2:end-1);
f = Fs*(0:(L/2))/L;

% Identify the dominant frequency component
[~, dominantIndex] = max(P1(2:end));
dominantIndex = dominantIndex + 1;
dominantFrequency = f(dominantIndex);

figure
semilogx(f,P1,"LineWidth",3)
title("Single-Sided Amplitude Spectrum of X(t)")
xlabel("f (Hz)")
ylabel("Amplitude")
grid on

peak_text = sprintf('Dominant Frequency = %.2f [Hz]\n', dominantFrequency);

% Position textbox in northeast corner
text(0.98, 0.98, peak_text, ...
    'Units','normalized', ...
    'FontSize',10, ...
    'FontWeight','bold', ...
    'BackgroundColor','white', ...
    'EdgeColor',[0.7 0.7 0.7], ...
    'HorizontalAlignment','right', ...
    'VerticalAlignment','top');
