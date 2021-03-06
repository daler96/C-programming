// Name: Daler Rahimjonov
// ID: 150140906
// BIL105E HW2

#include<stdio.h>

unsigned long long int choose,seed,num_samples,square,temp,n,product,number;
float p1,p2,p3,p4,p5,counter1=0,counter2=0,counter3=0,counter4=0,counter5=0; // p1-p5 are percentage variables

void lsd_rng(long seed){ // uses rightmost digits of a product to generate random numbers
	
		int i=0;
		
		for(i=0;i<num_samples;++i){ // iterates until i reaches num_samples
		
		product=seed*73; // LSD-PRNG algorithm
		number=product%100000; // takes five rightmost digits of a number
	
		
		if( ((number%500)+1)>=1 && ((number%500)+1)<=100 )
		counter1++; // increases counter1 if generated number in the 1st range
		
		else if ( ((number%500)+1)>=101 && ((number%500)+1)<=200 )
		counter2++; // increases counter2 if generated number in the 2nd range
		
		else if ( ((number%500)+1)>=201 && ((number%500)+1)<=300 )
		counter3++; // increases counter3 if generated number in the 3rd range
		
		else if ( ((number%500)+1)>=301 && ((number%500)+1)<=400 )
		counter4++; // increases counter4 if generated number in the 4th range
		
		else if ( ((number%500)+1)>=401 && ((number%500)+1)<=500 )
		counter5++; // increases counter5 if generated number in the 5th range
		
		seed=number; // seed becomes number to run loop one more time
		
		}
		
	printf("\n%llu random numbers were generated by using LSD-PRNG:\n\n",num_samples);
	print_histogram(); // prints histogram according to generated numbers
	
	
}

void mid_rng(long seed){ // uses 5 digits in the middle of a square to generate random numbers
	
		
		
	
		square=seed*seed; // MID-PRNG algorithm
		
		for(n=0;n<num_samples;++n){ // iterates until i reaches num_samples
		if(square>999999999) { // if square of a seed is 10 digits number, then... 
		
		temp = square/1000; // we divide it by 1000
		seed = temp%100000; // and take 5 digits in the middle using mod
	
		if( ((seed%500)+1)>=1 && ((seed%500)+1)<=100 )
		counter1++; // increases counter1 if generated number in the 1st range
		
		else if ( ((seed%500)+1)>=101 && ((seed%500)+1)<=200 )
		counter2++; // increases counter2 if generated number in the 2nd range
		
		else if ( ((seed%500)+1)>=201 && ((seed%500)+1)<=300 )
		counter3++; // increases counter3 if generated number in the 3rd range
		
		else if ( ((seed%500)+1)>=301 && ((seed%500)+1)<=400 )
		counter4++; // increases counter4 if generated number in the 4th range
		
		else if ( ((seed%500)+1)>=401 && ((seed%500)+1)<=500 )
		counter5++; // increases counter5 if generated number in the 5th range
		
		square=seed*seed; // square equalizes to seed*seed to iterate loop again and again
		}
		
		else if(square<=999999999) { // if square of a seed is 9 digits number, then...
		
		temp = square/100; // we divide it by 100
		seed = temp%100000; // and take 5 digits in the middle using mod
	
		if( ((seed%500)+1)>=1 && ((seed%500)+1)<=100 )
		counter1++; // increases counter1 if generated number in the 1st range
		
		else if ( ((seed%500)+1)>=101 && ((seed%500)+1)<=200 )
		counter2++; // increases counter2 if generated number in the 2nd range
		
		else if ( ((seed%500)+1)>=201 && ((seed%500)+1)<=300 )
		counter3++; // increases counter3 if generated number in the 3rd range
		
		else if ( ((seed%500)+1)>=301 && ((seed%500)+1)<=400 )
		counter4++; // increases counter4 if generated number in the 4th range
		
		else if ( ((seed%500)+1)>=401 && ((seed%500)+1)<=500 )
		counter5++; // increases counter5 if generated number in the 5th range
		
		square=seed*seed; // square equalizes to seed*seed to iterate loop again and again
		}	
		}
	printf("\n%llu random numbers were generated by using MID-PRNG:\n\n",num_samples);
	print_histogram(); // prints histogram according to generated numbers
	
}

int take_samples()

{
	
	printf("Which PRNG algorithm?\n\n");
	printf("1.MID-PRNG\n\n");
	printf("2.LSD-PRNG\n\n");
	scanf("%llu",&choose); // user chooses whether to use MID-PRNG or LSD-PRNG
	
	if (choose==1) // if user chooses MID-PRNG ...
	{
		printf("\nEnter the seed\n\n");
		scanf("%llu",&seed);
		printf("\nEnter number of samples\n\n");
		scanf("%llu",&num_samples);
		mid_rng(seed);	// it takes seed, num_samples values and calls mid_rng(seed) function
			
	}
	
	else if (choose==2)  // if user chooses LSD-PRNG ...
	{
		int last_digit;
		printf("\nEnter the seed\n\n");
		scanf("%llu",&seed);
		last_digit=seed%10;
		while (last_digit==5 || seed%2==0) // checks whether seed is even or ends with 5
		{
		
		printf("\nInvalid seed, Enter another seed\n\n");
		scanf("%llu",&seed);
		last_digit=seed%10;	
		}
		printf("\nEnter number of samples\n\n");
		scanf("%llu",&num_samples);
		lsd_rng(seed); // it takes seed, num_samples values and calls lsd_rng(seed) function

	}
	

	
}

print_histogram(){
	
int i;

p1 = (counter1/num_samples)*100;
 printf("  1..100: ");
 for(i=0;i<p1;++i) // prints starts according to p1 value
 printf("*");
 printf("(%0.f %%)\n\n",p1);
	
p2 = (counter2/num_samples)*100;
 printf("101..200: ");
 for(i=0;i<p2;++i) // prints starts according to p2 value
 printf("*");
 printf("(%0.f %%)\n\n",p2);
 
p3 = (counter3/num_samples)*100;
 printf("201..300: ");
 for(i=0;i<p3;++i) // prints starts according to p3 value
 printf("*");
 printf("(%0.f %%)\n\n",p3);
 
p4 = (counter4/num_samples)*100;
 printf("301..400: ");
 for(i=0;i<p4;++i) // prints starts according to p4 value
 printf("*");
 printf("(%0.f %%)\n\n",p4);

p5 = (counter5/num_samples)*100;
 printf("401..500: ");
 for(i=0;i<p5;++i) // prints starts according to p5 value
 printf("*");
 printf("(%0.f %%)\n\n",p5);
	
}

int main()
{
	
take_samples(); // calls take_samples() function

return 0;

} // end of the program

