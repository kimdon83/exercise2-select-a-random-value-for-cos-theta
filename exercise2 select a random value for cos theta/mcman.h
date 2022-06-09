#ifndef _MCMAN_H_KDH_
#define _MCMAN_H_KDH_

#include "define.h"

class Cmcmanager{
private:
	int i,j,k;
	double loc[2];
	rng RN;
	
	double rad;
	int Num_history;
	double loc_aver[2], rad_aver;//average of location vector and radius
	double cosSum, cosSqu;
	double cos,cosMean, cosVar, cosFSD; 

public:

	Cmcmanager();
	~Cmcmanager();

	int readINPUT(void);
	int mcrun(void);
};
#endif