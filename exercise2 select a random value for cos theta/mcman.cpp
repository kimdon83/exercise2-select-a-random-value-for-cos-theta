#include "mcman.h"
#include "define.h"

Cmcmanager::Cmcmanager(){
	Num_history = 100;
	loc_aver[0] = 0; loc_aver[1] = 0;
	rad_aver = 0;
	cos = 0;	cosMean = 0;	cosVar = 0; cosFSD = 0;
	cosSum = 0; cosSqu = 0;
}
Cmcmanager::~Cmcmanager(){
}

int Cmcmanager::readINPUT(void){
	cout << "------------------------------------------------------------------" << endl;
	cout << "|       Exercise #2. Select a random value for cos theta        |" << endl;
	cout << "------------------------------------------------------------------" << endl;

	cout << "      input the number of history " << endl;
	cin >> Num_history;
	
	return 0;
}
int Cmcmanager::mcrun(void){
	for (j = 0; j < Num_history; j++){
		do{
			for (i = 0; i < 2; i++){
				loc[i] = 2 * RN.gnRN() - 1; // theta : (0,pi*2)
				//loc[i] = RN.gnRN();       // theta : (0,pi/2)   
			}
			rad = loc[0] * loc[0] + loc[1] * loc[1] ;
		} while (rad > 1);
		rad = sqrt(rad);
		cos = loc[0] / rad;
		cosSum += cos;
		cosSqu += cos*cos;
		
	}
	cosMean = cosSum / Num_history;
	cosVar = (-cosMean*cosMean + (cosSqu) / Num_history) / (Num_history-1);

	cout << "Mean of cosine : " << cosMean << endl;
	cout << "Sample Variance of cosine : " << cosVar << endl;
	cout << "FSD of cosine : " << sqrt(cosVar) / cosMean << endl;

	return 0;
}
