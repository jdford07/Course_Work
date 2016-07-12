//Lab 2 - Currency Exchange Table
//John David Ford
//Date: 21 January 2016
//Section 2

#include <stdio.h>

int main()
{
	float fUser_Input = 0;
	
	//Dollar Variables-----------
	const float cfUSDAUD = 1.433;
	const float cfUSDGBP = 0.7038;
	const float cfUSDEUR = 0.9186;
	const float cfUSDINR = 67.93;
	const float cfUSDCAD = 1.432;
	const float cfUSDSGD = 1.435;
	//----------------------------
	const float cfAUDUSD = 0.6981;
	const float cfAUDGBP = 0.4911;
	const float cfAUDEUR = 0.6414;
	const float cfAUDINR = 47.39;
	const float cfAUDCAD = 0.9977;
	const float cfAUDSGD = 1.001;
	//----------------------------
	const float cfGBPUSD = 1.421;
	const float cfGBPAUD = 2.034;
	const float cfGBPEUR = 1.307;
	const float cfGBPINR = 96.50;
	const float cfGBPCAD = 2.030;
	const float cfGBPSGD = 2.038;
	//----------------------------
	const float cfEURUSD = 1.087;
	const float cfEURAUD = 1.556;
	const float cfEURGBP = 0.7654;
	const float cfEURINR = 73.83;
	const float cfEURCAD = 1.553;
	const float cfEURSGD = 1.559;
	//----------------------------
	const float cfINRUSD = 0.01473;
	const float cfINRAUD = 0.02107;
	const float cfINRGBP = 0.01036;
	const float cfINREUR = 0.01354;
	const float cfINRCAD = 0.02104;
	const float cfINRSGD = 0.02111;
	//----------------------------
	const float cfCADUSD = 0.7000;
	const float cfCADAUD = 1.001;
	const float cfCADGBP = 0.4924;
	const float cfCADEUR = 0.6433;
	const float cfCADINR = 47.54;
	const float cfCADSGD = 1.003;
	//---------------------------
	const float cfSGDUSD = 0.6973;
	const float cfSGDAUD = 0.9984;
	const float cfSGDGBP = 0.4905;
	const float cfSGDEUR = 0.6409;
	const float cfSGDINR = 47.36;
	const float cfSGDCAD = 0.9964;
	//Dollar Amount Ends---------
	
	// AUD = Australian, GBP = British, EUR = Euro, INR = India
	// CAD = Canadian, SGD = Singapore
	
	printf("Please enter $ amount.\n");
	scanf("%f", &fUser_Input);
	

	
//TABLE START
printf("      USD    AUD    GBP    EUR    INR    CAD    SGD  \n");
printf("USD  %.3f  %.3f  %.3f  %.3f  %.2f  %.3f  %.3f\n", fUser_Input, fUser_Input * cfUSDAUD, fUser_Input * cfUSDGBP, fUser_Input * cfUSDEUR, fUser_Input * cfUSDINR, fUser_Input * cfUSDCAD, fUser_Input * cfUSDSGD);
printf("AUD  %.3f  %.3f  %.3f  %.3f  %.2f  %.3f  %.3f\n", fUser_Input * cfAUDUSD, fUser_Input, fUser_Input * cfAUDGBP, fUser_Input * cfAUDEUR, fUser_Input * cfAUDINR, fUser_Input * cfAUDCAD, fUser_Input * cfAUDSGD);
printf("GBP  %.3f  %.3f  %.3f  %.3f  %.2f  %.3f  %.3f\n", fUser_Input * cfGBPUSD, fUser_Input * cfGBPAUD, fUser_Input, fUser_Input * cfGBPEUR, fUser_Input * cfGBPINR, fUser_Input * cfGBPCAD, fUser_Input * cfGBPSGD);
printf("EUR  %.3f  %.3f  %.3f  %.3f  %.2f  %.3f  %.3f\n", fUser_Input * cfEURUSD, fUser_Input * cfEURAUD, fUser_Input * cfEURGBP, fUser_Input, fUser_Input * cfEURINR, fUser_Input * cfEURCAD, fUser_Input * cfEURSGD);
printf("INR  %.3f  %.3f  %.3f  %.3f  %.2f   %.3f  %.3f\n", fUser_Input * cfINRUSD, fUser_Input * cfINRAUD, fUser_Input * cfINRGBP, fUser_Input * cfINREUR, fUser_Input, fUser_Input * cfINRCAD, fUser_Input * cfINRSGD);
printf("CAD  %.3f  %.3f  %.3f  %.3f  %.2f  %.3f  %.3f\n", fUser_Input * cfCADUSD, fUser_Input * cfCADAUD, fUser_Input * cfCADGBP, fUser_Input * cfCADEUR, fUser_Input * cfCADINR, fUser_Input, fUser_Input * cfCADSGD);
printf("SGD  %.3f  %.3f  %.3f  %.3f  %.2f  %.3f  %.3f\n", fUser_Input * cfSGDUSD, fUser_Input * cfSGDAUD, fUser_Input * cfSGDGBP, fUser_Input * cfSGDEUR, fUser_Input * cfSGDINR, fUser_Input * cfSGDCAD, fUser_Input);
//TABLE END
	
	//----- USD -> Other $'s
//	printf("USD -> USD is %.4f \n", fUser_Input);
//	printf("USD -> AUD is %.4f \n", fUser_Input * cfUSDAUD);
//	printf("USD -> GBP is %.4f \n", fUser_Input * cfUSDGBP);
//	printf("USD -> EUR is %.4f \n", fUser_Input * cfUSDEUR);
//	printf("USD -> INR is %.4f \n", fUser_Input * cfUSDINR);
//	printf("USD -> CAD is %.4f \n", fUser_Input * cfUSDCAD);
//	printf("USD -> SGD is %.4f \n", fUser_Input * cfUSDSGD);
	
	//----- AUD -> Other $'s
//	printf("AUD -> USD is %.4f \n", fUser_Input * cfAUDUSD);
//	printf("AUD -> AUD is %.4f \n", fUser_Input);
//	printf("AUD -> GBP is %.4f \n", fUser_Input * cfAUDGBP);
//	printf("AUD -> EUR is %.4f \n", fUser_Input * cfAUDEUR);
//	printf("AUD -> INR is %.4f \n", fUser_Input * cfAUDINR);
//	printf("AUD -> CAD is %.4f \n", fUser_Input * cfAUDCAD);
//	printf("AUD -> SGD is %.4f \n", fUser_Input * cfAUDSGD);
	
	//----- GBP -> Other $'s
//	printf("AUD -> USD is %.4f \n", fUser_Input * cfGBPUSD);
//	printf("AUD -> AUD is %.4f \n", fUser_Input * cfGBPAUD);
//	printf("AUD -> GBP is %.4f \n", fUser_Input);
//	printf("AUD -> EUR is %.4f \n", fUser_Input * cfGBPEUR);
//	printf("AUD -> INR is %.4f \n", fUser_Input * cfGBPINR);
//	printf("AUD -> CAD is %.4f \n", fUser_Input * cfGBPCAD);
//	printf("AUD -> SGD is %.4f \n", fUser_Input * cfGBPSGD);
	
	//----- EUR -> Other $'s
//	printf("AUD -> USD is %.4f \n", fUser_Input * cfEURUSD);
//	printf("AUD -> AUD is %.4f \n", fUser_Input * cfEURAUD);
//	printf("AUD -> GBP is %.4f \n", fUser_Input * cfEURGBP);
//	printf("AUD -> EUR is %.4f \n", fUser_Input);
//	printf("AUD -> INR is %.4f \n", fUser_Input * cfEURINR);
//	printf("AUD -> CAD is %.4f \n", fUser_Input * cfEURCAD);
//	printf("AUD -> SGD is %.4f \n", fUser_Input * cfEURSGD);
	
	//----- INR -> Other $'s
//	printf("AUD -> USD is %.4f \n", fUser_Input * cfINRUSD);
//	printf("AUD -> AUD is %.4f \n", fUser_Input * cfINRAUD);
//	printf("AUD -> GBP is %.4f \n", fUser_Input * cfINRGBP);
//	printf("AUD -> EUR is %.4f \n", fUser_Input * cfINREUR);
//	printf("AUD -> INR is %.4f \n", fUser_Input);
//	printf("AUD -> CAD is %.4f \n", fUser_Input * cfINRCAD);
//	printf("AUD -> SGD is %.4f \n", fUser_Input * cfINRSGD);
	
	//----- CAD -> Other $'s 
//	printf("AUD -> USD is %.4f \n", fUser_Input * cfCADUSD);
//	printf("AUD -> AUD is %.4f \n", fUser_Input * cfCADAUD);
//	printf("AUD -> GBP is %.4f \n", fUser_Input * cfCADGBP);
//	printf("AUD -> EUR is %.4f \n", fUser_Input * cfCADEUR);
//	printf("AUD -> INR is %.4f \n", fUser_Input * cfCADINR);
//	printf("AUD -> CAD is %.4f \n", fUser_Input);
//	printf("AUD -> SGD is %.4f \n", fUser_Input * cfCADSGD);
	
	//----- SGD -> Other $'s 
//	printf("AUD -> USD is %.4f \n", fUser_Input * cfSGDUSD);
//	printf("AUD -> AUD is %.4f \n", fUser_Input * cfSGDAUD);
//	printf("AUD -> GBP is %.4f \n", fUser_Input * cfSGDGBP);
//	printf("AUD -> EUR is %.4f \n", fUser_Input * cfSGDEUR);
//	printf("AUD -> INR is %.4f \n", fUser_Input * cfSGDINR);
//	printf("AUD -> CAD is %.4f \n", fUser_Input * cfSGDCAD);
//	printf("AUD -> SGD is %.4f \n", fUser_Input);
	
	return 0;
	
	
}
