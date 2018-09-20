#include <iostream>
#include "Header.h" 
using namespace std;
#include <string>



int main ()
{	
	CourseDetails Student[1000] ;
    float n, TotalGP = 0.0 , TotalUnit = 0.0 ;
	float YourGP;
	
	cout << "This is a GP Calculator. \n \n Enter your number of courses, excude all GST courses." << endl;
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
	}

	YourGP = CalculateGP ( TotalGP , TotalUnit ) ;

	system ("cls") ;

	PrintResult ( Student ,  YourGP , n, TotalGP , TotalUnit );

	cout << " \n \n You just calculated your Semester GPA. Do you wish to calculate your Cummulative GPA? " <<endl; 
	cout << "Type in y for yes and n for no " << endl ;

	char decision ;
	cin >> decision ;

	system("cls"); 

	if(decision == 'Y' || decision == 'y')
	{
		cout << "Okay then, \nDo you know your most recent Cummulative Grade Points and Cummulative Units as at last semester? " << endl;
		cout << "Type in y for yes and n for no " ;

		char decision2 ;
		cin >> decision2 ;

		if(decision2 == 'Y' || decision2 == 'y')
			{
				CGPA1 ( TotalGP ,  TotalUnit , YourGP) ;

			}
		else
			{  
				system ("cls") ;
				cout << "Sigh, you have to calculate the total grade points and unit for every semester excluding the one for this semester" << endl;

				float FTGP , FTU ;
				float *FTotalGP_ptr = &FTGP ;
				float *FTotalUnit_ptr= &FTU ;
				
				CGPA2 ( FTotalGP_ptr,  FTotalUnit_ptr) ;

				float CGPA = (*FTotalGP_ptr + TotalGP) / (*FTotalUnit_ptr + TotalUnit) ;

				cout << " \nTotal Grade Points" << *FTotalGP_ptr ;
				cout << " \nTotal Amount of Units " << *FTotalUnit_ptr << endl;

				cout << "Your CGPA is - " << CGPA << endl ;

			}

				system ("pause") ;
				return 0;
	} 
	else
	{   
		cout << "You didn't say Yes. Byeee! \n \t \t \t END. " << endl;
		system ("pause") ;
	    return 0;
	}
	
}