/*
 *  离散正弦变换DST
 *  nSampleLength	采样长度
 *  fInputData		采样数据数列
 *  fTransformData	正弦波分量幅度值
*/
#define PI 3.14159265358979323846
int i,j;
float fArgument;
for(i=0;i<nSampleLength;i++)
{
	fTransformData[i]=0;
	for(j=0;j<nSampleLength;j++)
	{
		fArgument[i]=i*PI*j/nSampleLength;
		fTransformData[i]+=fInputData[j]*sin(fArgument);	//使用cos()则为离散余弦变换DCT
	}
}

/*
 *  离散傅里叶变换DFT
 *  nSampleLength	采样长度
 *  fInputData		采样数据数列
 *  fTransformData	正弦波分量幅度值
*/
#define PI 3.14159265358979323846
int i,j;
float fArgument;
float fSign=-1;
for(i=0;i<nSampleLength/2;i++)
{
	fSinTransformData[i]=0;
	fCosTransformData[i]=0;
	for(j=0;j<nSampleLength;j++)
	{
		fArgument[i]=2*PI*i*j/nSampleLength;
		fSinTransformData[i]+=fInputData[j]*sin(fArgument)*fSign;	
		fCosTransformData[i]+=fInputData[j]*cos(fArgument);	
	}
	//正弦信号的频率HZ
	fFrequency[i]=nSampleRate*i*nSampleLength;
	//正弦信号的幅度dB
	fMagnitude[i]=(2/nSampleLength)*sqrt(pow(fSinTransformData[i],2)+pow(fCosTransformData[i],2));
	fMagnitude[i]=20.f*log10(fMagnitude[i]);
	//正弦信号的相位°
	fPhase[i]=180.f*atan2(fSinTransformData[j],fCosTransformData[j])/PI;
}

