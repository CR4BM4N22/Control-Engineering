clc;
% Load Measurement Data
fig = openfig('NoCon_Openloop_4k_30s_lp300.fig');
%% Find plotted lines
ax = findobj(fig, 'Type', 'Axes');
stairsObj = findobj(ax, 'Type', 'Stair');

FRF.yTime = stairsObj(1).XData(:);
FRF.y = stairsObj(1).YData(:);

%FRF.uTime = stairsObj(2).XData(:);
%FRF.u = stairsObj(2).YData(:);

FRF.uTime = stairsObj(3).XData(:);
FRF.u = stairsObj(3).YData(:);

%% Measurement Constants
fs = 4000;                               %% Insert actual sampling freq! 
Ts = 1/fs;
L = length(FRF.u);

% Estimate Sensitivity S(f)
%% PSD/CPSD Constants
nfft = 1000;  
noverlap = .5*nfft;                                   %% Nr of overlapped samples [# samples]
                                  %% Window length [# samples]

[PSD.Syu, hz] = cpsd(FRF.y, FRF.u,hann(nfft),noverlap,nfft,fs);
w = hz .*(2*pi); 
PSD.Suu = pwelch(FRF.u,hann(nfft),noverlap,nfft,fs);

PSD.coherence_yu = mscohere(FRF.y,FRF.u,hann(nfft),noverlap,nfft,fs);
% Plot coherence
% figure;
% semilogx(hz, PSD.coherence_yu);
% title('Coherence between y and u')
% grid on;
% xlabel('Frequency [Hz]', Interpreter='latex')
% ylabel('Coherence', Interpreter='latex')
% ylim([0 1.2])

% S = (PSD.Syu)./(PSD.Suu);
% 
% % plot S
% S_mag = 20*log10(abs(S));
% S_ph = angle(S) * (180/pi);
% figure;
% subplot(2,1,1)
% semilogx(hz,S_mag);
% title("FRF Sensitivity")
% grid on;
% xlabel("Frequency [Hz]",Interpreter="latex")
% ylabel('Magnitude [dB]',Interpreter="latex")
% subplot(2,1,2)
% semilogx(hz,S_ph)
% xlabel("Frequency [Hz]",Interpreter="latex")
% ylabel('Angle [deg]',Interpreter="latex")

freqRes = fs/nfft;

%Transfer Function Estimation
H = PSD.Syu ./ PSD.Suu;

H_mag = 20*log10(abs(H));
H_ph = angle(H) * (180/pi);
figure(2);
subplot(3,1,1)
semilogx(hz,H_mag);
title("FRF Open Loop")
grid on;
xlabel("Frequency [Hz]",Interpreter="latex")
ylabel('Magnitude [dB]',Interpreter="latex")
subplot(2,1,2)
semilogx(hz,H_ph)
xlabel("Frequency [Hz]",Interpreter="latex")
ylabel('Angle [deg]',Interpreter="latex")
semilogx(hz, PSD.coherence_yu);
title('Coherence between y and u')
grid on;
xlabel('Frequency [Hz]', Interpreter='latex')
ylabel('Coherence', Interpreter='latex')
ylim([0 1.2])
