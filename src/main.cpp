/* example1.c */

#include <stdio.h>
#include <math.h>

#include "emd.h"

float dist(feature_t* F1, feature_t* F2)
{
	int dX = F1->x - F2->x;
	int dY = F1->y - F2->y;
  return sqrt(dX*dX + dY*dY);
}

main()
{
  feature_t f1[4] = { {100,40}, {211,20}, {32,190}, {2,100} };
	feature_t f2[3] = { {0,0}, {50,100}, {255,255} };
  float w1[4] = { 1, 1, 1, 1};
  float w2[3] = { 1, 1, 1};
  signature_t s1 = { 4, f1, w1};
	signature_t s2 = { 3, f2, w2};
  float e;

	flow_t flows[6];
	int num_flows;
  e = emd(&s1, &s2, dist, flows, &num_flows);

  printf("emd=%f\n", e);
	printf("flows = %d\n", num_flows);
	for(int i=0;i<num_flows;++i){
		printf("s%d -> t%d, amount=%f\n", flows[i].from, flows[i].to, flows[i].amount);
	}
}