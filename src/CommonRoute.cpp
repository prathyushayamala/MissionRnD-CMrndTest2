/*
There are two friends Hack and Code . They have decided to go on a world tour which consists of only Islands.
There are a total of 26 Islands in the world ,where Each Island has a name from A ,B ,C ,D ... till Z .
[Each Island name is restricted to only 1 Letter]

Hack and Code seperately made their travel lists ,where they specify List of Islands they want to visit 
in a particular order .
Ex : If Hack's List is "CADBZ" , He wants to go first to C island ,next A island and B and so on ,and finally
reach Z island .

Now Hack and Code had shared their lists , and they observed that their lists are not at all similar .
No one wants to compromise on their Travel List and Order,and each wants other person to accept their List .
After a through discussion,They finally decided that they will Find the Common route in the List which covers
Maxium Islands and make that their Tour .

Cost of Visting each Island will be equal to the position in the Alphabats Series that Island Name is( Letter ) .
Cost of Visiting A island is 1 ,H is 8 , Z is 26 and so on .
Can you help Hack and Code to find the Common Route ,so that their dispute is solved .

Inputs :
Two Strings of Capital Letters ,where each Letter denotes an Island .They can visit each Island any 
number of times.
Output :
Return a Common Route String which covers maxiumum Islands 

Example 1 : 
Input : HackList="CADBZAYZY" CodeList="BZAYACAFRDBZ" 
Output: Return "BZAY" and modify the Cost variable to  54 [2+26+1+25]
Explanation : 
They both can start at B ,Go to Z ,and go to A,Finally reach Y .This Route covers 4 islands ,where
all other routes like CA ,DBZ , ZAY ,etc covers less than 4 islands .

Note : If there are Two Maximum routes which cover Equal number of Islands , Return the Route which Costs 
less . IF the Costs are also equal ,Return the Route ,whose FirstIsland is Alphabetically Before 
[Assume two routes with same cost ,will always have first island a different one].

Final Route Islands should be in Both Hack and Codes list and in same order ,If Final route is ACB 
There must be a route in both Lists which is ACB . [AZZCB , ADCDB dont qualify ,Order should be continous]
Return NULL for Invalid Inputs or No Common Route[Cost will be 0].

Example 2 : Input : "CABTYUZZZ" , "ZZZTYUCAB" , Output : "CAB" and cost should be 6 (Least Cost ) 
Example 3 : Input : "HHHZAADTD" , "ZAAHHHDTDRR" , Output : "DTD" (DTD , HHH ,ZAA has same cost of 28 ,but the
First Island in DTD ie 'D' occurs alphabatically before 'H' and 'Z')

*/

#include <stdlib.h>
#include <stdlib.h>
#include <stdio.h>

char* largest_common_route(char** res,int size){
	int i=0, j=0, temp=0, *cost,*len,k=0,temp_cost=0;
	cost = (int*)malloc(size*sizeof(int));
	len = (int*)malloc(size*sizeof(int));
	while (res[i] != '\0'){
		j = 0;
		while (res[i][j] != '\0'){
			j++;
		}
		len[i] = j;
		if (j > temp){
			temp = j;
		}
		i++;
	}
	for (k = 0; k <= i; k++){
		if (temp == len[k]){
			for (j = 0; j < len[k]; j++){
				temp_cost = temp_cost + res[k][j]-'A'-1;
			}
			if (temp_cost > cost[k]){
				cost[k] = temp_cost;
			}
		}
	}
	temp = cost[0];
	j = 0;
	int index;
	for (k = 0; k < i; k++){
		if (temp>cost[k]){
			temp = cost[k];
			index = k;
			j = 0;
		}
		if (temp == cost[k]){
			j++;
		}
	}
	if (j == 0){
		return res[index];
	}
	else{
		if (temp == 0){
			return NULL;
		}
		else{
			i = 0;
			while (temp == cost[i]){
				i++;
			}
			j = i;
			while (temp == cost[j]){
				j--;
			}
			if (res[i][0] > res[j][0]){
				return res[i];
			}
			else{
				return res[j];
			}
		}
	}
}

char * find_common_route(char * hacklist, char *codelist, int *cost){
	int i, j, len1 = 0, len2 = 0, temp = *cost, k, p = 0, l1, l2;
	char **res;
	if ((hacklist != NULL) && (codelist != NULL)){
		if (*cost <= 0){
			return NULL;
		}
		else{
			while (hacklist[len1] != '\0'){
				len1++;
			}
			while (codelist[len2] != '\0'){
				len2++;
			}
			if (len1 >= len2){
				res = (char**)malloc(len2*sizeof(char));
				for (i = 0; i < len2; i++){
					res[i] = (char*)malloc(len2*sizeof(char));
				}
			}
			else{
				res = (char**)malloc(len1*sizeof(char));
				for (i = 0; i < len1; i++){
					res[i] = (char*)malloc(len1*sizeof(char));
				}
			}
			for (i = 0; i < len1; i++){
				for (j = 0; j < len2; j++){
					if (hacklist[i] == codelist[j]){
						k = 0;
						l1 = i, l2 = j;
						while (hacklist[l1] == codelist[l2]){
							res[p][k] = hacklist[l1];
							k++;
							l1++;
							l2++;
						}
						res[p][k] = '\0';
						p++;
					}
				}
			}
			res[p] = '\0';
			return largest_common_route(res, p);
		}
	}
		else{
		return NULL;
	}
}

