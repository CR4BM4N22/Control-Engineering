%% Load Measurement Data

fig = openfig('Con_3point_4k_120sec_error_LP300.fig','invisible');
%% Find plotted lines
ax = findobj(fig, 'Type', 'Axes');
stairsObj = findobj(ax, 'Type', 'Stair');

FRF.eTime = stairsObj(1).XData(:);
FRF.e = stairsObj(1).YData(:);

FRF.uTime = stairsObj(2).XData(:);
FRF.u = stairsObj(2).YData(:);

FRF.dTime = stairsObj(3).XData(:);
FRF.d = stairsObj(3).YData(:);

%% Measurement Constants
fs = 4000;                               %% Insert actual sampling freq! 
Ts = 1/fs;
L = length(FRF.u);
%% PSD/CPSD Constants

NrWin = 80;
nfft = L/NrWin;                                      %% Window length [# samples]
noverlap = .5*nfft;                                   %% Nr of overlapped samples [# samples]

[PSD.Sud, hz] = cpsd(FRF.u, FRF.d,hann(nfft),noverlap,nfft,fs);
PSD.Sdd = pwelch(FRF.d,hann(nfft),noverlap,nfft,fs);

PSD.coherence_du = mscohere(FRF.d,FRF.u,hann(nfft),noverlap,nfft,fs);
% Plot coherence
figure;
semilogx(hz, PSD.coherence_du);
title('Coherence between d and u')
grid on;
xlabel('Frequency [Hz]', Interpreter='latex')
ylabel('Coherence', Interpreter='latex')
ylim([0 1.2])
xlim([10 300])

S = PSD.Sud./PSD.Sdd;

% plot S
S_mag = 20*log10(abs(S));
S_ph = angle(S) * (180/pi);
figure;
subplot(2,1,1)
semilogx(hz,S_mag);
title("FRF Sensitivity")
grid on;
xlabel("Frequency [Hz]",Interpreter="latex")
ylabel('Magnitude [dB]',Interpreter="latex")
xlim([10 300])
subplot(2,1,2)
semilogx(hz,S_ph)
xlabel("Frequency [Hz]",Interpreter="latex")
ylabel('Angle [deg]',Interpreter="latex")
xlim([10 300])

freqRes = fs/nfft;


%% Transfer Function Estimation

H = 1./S-1;

H_mag = 20*log10(abs(H));
H_ph = angle(H) * (180/pi);
figure;
subplot(2,1,1)
semilogx(hz,H_mag);
title("FRF Open Loop")
grid on;
xlabel("Frequency [Hz]",Interpreter="latex")
ylabel('Magnitude [dB]',Interpreter="latex")
xlim([10 300])
subplot(2,1,2)
semilogx(hz,H_ph)
xlabel("Frequency [Hz]",Interpreter="latex")
ylabel('Angle [deg]',Interpreter="latex")
xlim([10 300])