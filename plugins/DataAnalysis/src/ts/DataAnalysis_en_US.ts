<?xml version="1.0" encoding="utf-8"?>
<!DOCTYPE TS>
<TS version="2.1" language="en_US" sourcelanguage="en_US">
<context>
    <name>DataAnalysisActions</name>
    <message>
        <location filename="DataAnalysisActions.cpp" line="20"/>
        <source>Spectrum</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="DataAnalysisActions.cpp" line="67"/>
        <source>DAAppActionsInterface::recordAction get null action</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="DataAnalysisActions.cpp" line="72"/>
        <source>DAAppActionsInterface::recordAction(QAction objname=%1) receive same object name, and the previous record will be overwritten</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>DataAnalysisUI</name>
    <message>
        <location filename="DataAnalysisUI.cpp" line="28"/>
        <source>Data Analysis</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="DataAnalysisUI.cpp" line="29"/>
        <source>Signal Process</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="DataAnalysisUI.cpp" line="40"/>
        <source>loss &quot;da-ribbon-category-data&quot; category page</source>
        <translation type="unfinished"></translation>
    </message>
</context>
<context>
    <name>DialogSpectrumSetting</name>
    <message>
        <location filename="Dialogs/DialogSpectrumSetting.ui" line="14"/>
        <location filename="Dialogs/DialogSpectrumSetting.ui" line="48"/>
        <source>Spectrum Setting</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="Dialogs/DialogSpectrumSetting.ui" line="27"/>
        <source>select series</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="Dialogs/DialogSpectrumSetting.ui" line="37"/>
        <source>data preview</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="Dialogs/DialogSpectrumSetting.ui" line="54"/>
        <source>The length of FFT is equal to the length of data</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="Dialogs/DialogSpectrumSetting.ui" line="67"/>
        <source>amplitude processing method</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="Dialogs/DialogSpectrumSetting.ui" line="74"/>
        <source>Amplitude</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="Dialogs/DialogSpectrumSetting.ui" line="100"/>
        <source>customize</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="Dialogs/DialogSpectrumSetting.ui" line="112"/>
        <source>fft size</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="Dialogs/DialogSpectrumSetting.ui" line="119"/>
        <source>1.Cropping or Zero-Padding Input:
When the FFT length is shorter than the input waveform length, cropping the input can reduce the amount of data the FFT needs to process, thereby improving computational speed. However, doing so may lose some information in the waveform.
When the FFT length is longer than the input waveform length, zero-padding is used to increase the number of data points. This usually doesn&apos;t increase spectral resolution (because no actual signal information is added), but it can make the spectrum appear smoother and may help identify peaks more clearly during graphical presentation.

2.Controlling Frequency Resolution:
FFT converts signals from the time domain to the frequency domain, resulting in a series of complex numbers representing different frequency components. The modulus of these complex numbers indicates the amplitude of that frequency component, while the argument represents the phase.
The FFT length (i.e., the number of points n) determines the number of frequency components. A longer FFT will produce more frequency components, providing finer frequency resolution. However, it&apos;s important to note that increasing the FFT length doesn&apos;t necessarily increase the accuracy or information content of the spectrum; it just distributes the existing spectral information across more points.

3.Performance Optimization:
Many FFT libraries (such as FFTW, KissFFT, etc.) are optimized for FFTs of specific lengths, especially when the length is a power of 2. In these cases, the FFT algorithm can utilize divide-and-conquer strategies (such as the Cooley-Tukey FFT algorithm) to compute the transformation more efficiently.

4.Avoiding Spectral Leakage:
If the signal contains periodic components (such as sine waves), and the FFT length happens to be an integer multiple of that period, the FFT result will produce a sharp peak at that frequency, while values at other frequencies will be close to zero. This helps to identify and measure periodic components in the signal more accurately.
If the FFT length is not an integer multiple of the signal period, it can lead to spectral leakage, where the signal&apos;s energy leaks into other frequencies, making spectral analysis difficult. Choosing an appropriate FFT length (especially one that matches the signal period) can reduce this leakage.

5.Saving Computational Resources:
In some application scenarios, very high frequency resolution may not be required. In these cases, using a shorter FFT can save computation time and resources while still providing sufficient information to meet the needs.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="Dialogs/DialogSpectrumSetting.ui" line="183"/>
        <source>Decibel(dB)</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="Dialogs/DialogSpectrumSetting.ui" line="193"/>
        <source>The length of FFT is a next power of 2</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="Dialogs/DialogSpectrumSetting.ui" line="203"/>
        <source>sampling rate</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="Dialogs/DialogSpectrumSetting.ui" line="223"/>
        <source>Specifies how to detrend,detrending mainly affects the DC component (0 frequency) of the signal.</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="Dialogs/DialogSpectrumSetting.ui" line="226"/>
        <source>detrend</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="Dialogs/DialogSpectrumSetting.ui" line="233"/>
        <source>constant</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="Dialogs/DialogSpectrumSetting.ui" line="243"/>
        <source>linear</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="Dialogs/DialogSpectrumSetting.cpp" line="101"/>
        <location filename="Dialogs/DialogSpectrumSetting.cpp" line="109"/>
        <source>warning</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="Dialogs/DialogSpectrumSetting.cpp" line="102"/>
        <source>You need to select a waveform data for spectrum analysis</source>
        <translation type="unfinished"></translation>
    </message>
    <message>
        <location filename="Dialogs/DialogSpectrumSetting.cpp" line="110"/>
        <source>The sampling rate cannot be 0</source>
        <translation type="unfinished"></translation>
    </message>
</context>
</TS>