#pragma once

using namespace std;
#include <string>

enum Grade {F, E, D, C, B, A} ;

struct CourseDetails 
{
  string CName;
  float CScore;
  int CUnit;
  Grade CGrade;
  int CGP;
} ;



void GetDetails ( CourseDetails [] , int ); 
float ScoreConverter ( CourseDetails [] , int  ) ;
float GP ( CourseDetails [] , int , int  ) ;
float CalculateGP (float, float) ; 
void PrintResult ( CourseDetails [] , float, int , float, float) ; 
void CGPA1 (float , float , float) ;
void CGPA2 (float *, float *) ;