#include <iostream>
using namespace std;
#include <string>
#include "Header.h"
#include <iomanip>




void GetDetails ( CourseDetails Student[] , int i )
{
       cout << "Course name? " ;
		cin >> Student[i-1].CName ;

	    cout << "Score? " ;
		cin >> Student[i-1].CScore ;

		cout << "Number of Units? " ;
		cin >> Student[i-1].CUnit  ;
		cout << endl ;
}

float ScoreConverter (CourseDetails Student[1000] , int i) 

{	
	int score = Student[i-1].CScore ;
	char grade;

	if( score < 40)
	{ return 0 ;} 

	else if( score >= 40 && score < 45 )
	{ return 1 ;} 

	else if( score >= 45 && score < 50 )
	{ return 2 ;} 

	else if( score >= 50  && score < 60 )
	{ return 3 ;}

	else if( score >= 60  && score < 70 )
	{ return 4 ;}

	else if( score >= 70  && score <= 100 )
	{ return 5 ;}
}


float GP ( CourseDetails Student [], int i, int Converted ) 
{
	int GradePoint = Student[i-1].CUnit * Converted ;

	return GradePoint;
}



float CalculateGP ( float TGP ,float TU)
{
	float Final = (TGP / TU) ;
	return Final;
}

void PrintResult ( CourseDetails Student [] , float YourGP ,int n ,float TGP , float TU )
{
	for (int i=1 ; i <=n ; i++ )
	{
		
		cout << Student[i-1].CName << endl;
		cout << " \t \t Grade - " ;
		switch (Student[i-1].CGrade) 
		{ 
		case 0 : { cout << "F" << endl; } 
				 break ;
		case 1 : { cout << "E" << endl; } 
				 break ;
		case 2 : { cout << "D" << endl; } 
				 break ;
		case 3 : { cout << "C" << endl; } 
				 break;
		case 4 : { cout << "B" << endl; } 
				 break ;
		case 5 : { cout << "A" << endl; } 
				 break ;
		}

	}

	cout << "\nTotal Grade Points - " << TGP << endl;
	cout << "Total Units - " << TU << endl << endl;
	cout << "Your GP is " << setprecision(3) << YourGP << endl;
}

void CGPA1 (float TotalGP , float TotalUnit , float YourGP)
{
	
				float NewTGP, NewTU , sum1, sum2 , CGPA;

				cout << " \nPrevious Total Grade Points? " ;
				cin >> NewTGP ;
				cout << "Previous Total Units? " ;
				cin >> NewTU ;

				sum1 = NewTGP + TotalGP;
				sum2 = NewTU + TotalUnit;

				CGPA = CalculateGP ( sum1 , sum2 );

				cout << " \n \n Semester GPA - " << YourGP << endl;
				cout << "CGPA - " << CGPA << endl;
}

void CGPA2 (float *FTotalGP_ptr, float *FTotalUnit_ptr)
{
	int semesters;
	
		int n;
		CourseDetails Student[1000] ;
		float YourGP;
		float FTotalGP = 0.0 , FTotalUnit = 0.0;

	cout << "How many semesters have you done?" << endl;
	cin >> semesters; 

	for (int j=1 ; j <= semesters ; j++ )
	{	
		float TotalGP = 0.0 , TotalUnit = 0.0 ;
		
		FTotalGP_ptr = &FTotalGP ;
		FTotalUnit_ptr = &FTotalUnit ;
		
		cout << "\n For semester " << j ;
		cout << " enter your number of courses. Exclude all GST courses." << endl;
		cin >> n;



		for ( int i=1 ; i <= n ; i++ )
		{ 
			cout << " \t COURSE " << i << endl ;

			GetDetails ( Student , i ) ;

			int Converted = ScoreConverter (Student , i );
		
			Student[i-1].CGrade = (Grade) Converted ;
		
			Student[i-1].CGP = GP ( Student, i, Converted ) ; 
		 
			TotalGP = TotalGP + Student[i-1].CGP ; 
		
			TotalUnit = TotalUnit + Student[i-1].CUnit ;

			FTotalGP = FTotalGP + TotalGP;
		
			FTotalUnit = FTotalUnit + TotalUnit;
		}
			
	  
	YourGP = CalculateGP ( TotalGP , TotalUnit ) ;

	cout << "Your GP that semester was " << YourGP << endl;

	

    }

	 
}