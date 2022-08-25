// 26.8.2022... I have added lots of comments that were lacking, still needs lots of work...



#include <REG52.H>
#include <intrins.h>
#define uchar unsigned char
#define uint unsigned int



// This is an array that stores data for a 8x8 LED display.

uchar display[8][8];

/*rank:A,1,2,3,4,I,心,U*/
//This line of code defines a variable called table_cha as an unsigned character.
uchar code table_cha[8][8]={0x51,0x51,0x51,0x4a,0x4a,0x4a,0x44,0x44,0x18,0x1c,0x18,0x18,0x18,0x18,0x18,0x3c,0x3c,0x66,0x66,0x30,0x18,0xc,0x6,0xf6,0x3c,0x66,0x60,0x38,0x60,0x60,0x66,0x3c,0x30,0x38,0x3c,0x3e,0x36,0x7e,0x30,0x30,0x3c,0x3c,0x18,0x18,0x18,0x18,0x3c,0x3c,0x66,0xff,0xff,0xff,0x7e,0x3c,0x18,0x18,0x66,0x66,0x66,0x66,0x66,0x66,0x7e,0x3c};




/*the "ideasoft"*/

uchar code table_id[40]={0x81,0xff,0x81,0x00,0xff,0x81,0x81,0x7e,0x00,0xff,0x89,0x89,0x00,0xf8,0x27,0x27,0xf8,0x00,0x8f,0x89,0x89,0xf9,0x00,0xff,0x81,0x81,0xff,0x00,0xff,0x09,0x09,0x09,0x01,0x0,0x01,0x01,0xff,0x01,0x01,0x00};

/*railway*/

uchar code dat[128]={0x0,0x20,0x40,0x60,0x80,0xa0,0xc0,0xe0,0xe4,0xe8,0xec,0xf0,0xf4,0xf8,0xfc,0xdc,0xbc,0x9c,0x7c,0x5c,0x3c,0x1c,0x18,0x14,0x10,0xc,0x8,0x4,0x25,0x45,0x65,0x85,0xa5,0xc5,0xc9,0xcd,0xd1,0xd5,0xd9,0xb9,0x99,0x79,0x59,0x39,0x35,0x31,0x2d,0x29,0x4a,0x6a,0x8a,0xaa,0xae,0xb2,0xb6,0x96,0x76,0x56,0x52,0x4e,0x6f,0x8f,0x93,0x73,0x6f,0x8f,0x93,0x73,0x4a,0x6a,0x8a,0xaa,0xae,0xb2,0xb6,0x96,0x76,0x56,0x52,0x4e,0x25,0x45,0x65,0x85,0xa5,0xc5,0xc9,0xcd,0xd1,0xd5,0xd9,0xb9,0x99,0x79,0x59,0x39,0x35,0x31,0x2d,0x29,0x0,0x20,0x40,0x60,0x80,0xa0,0xc0,0xe0,0xe4,0xe8,0xec,0xf0,0xf4,0xf8,0xfc,0xdc,0xbc,0x9c,0x7c,0x5c,0x3c,0x1c,0x18,0x14,0x10,0xc,0x8,0x4};

/*railway 2*/

uchar code dat2[28]={0x0,0x20,0x40,0x60,0x80,0xa0,0xc0,0xe0,0xe4,0xe8,0xec,0xf0,0xf4,0xf8,0xfc,0xdc,0xbc,0x9c,0x7c,0x5c,0x3c,0x1c,0x18,0x14,0x10,0xc,0x8,0x4};

/*railway 3*/

uchar code dat3[24]={0x00,0x01,0x02,0x03,0x04,0x05,0x06,0x16,0x26,0x36,0x46,0x56,0x66,0x65,0x64,0x63,0x62,0x61,0x60,0x50,0x40,0x30,0x20,0x10};

/*3p char*/

uchar code table_3p[3][8]={0xff,0x89,0xf5,0x93,0x93,0xf5,0x89,0xff,0x0e,0x1f,0x3f,0x7e,0x7e,0x3f,0x1f,0x0e,0x18,0x3c,0x7e,0xff,0x18,0x18,0x18,0x18};

//initializtion
// That is to initialize the program .
// It is write to set the timer in c52 mcu.
// So the program can renovate the led_3d_cube in fixed time use the interrupt function.

void sinter()

{

         IE=0x82;

         TCON=0x01;

         TH0=0xc0;

         TL0=0;

         TR0=1;

}


//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
// The delay5us() function delays for approximately 5 microseconds. 
// This function is called by delay(), which takes a parameter specifying the number of milliseconds to delay. 
// delay() calls delay5us() the appropriate number of times to produce the specified delay.


void delay5us(void)   //误差 -0.026765046296us STC 1T 22.1184Mhz
{
    unsigned char a,b;
    for(b=7;b>0;b--)
        for(a=2;a>0;a--);
}

void delay(uint i)

{                                                                                                     

         while (i--){
		 delay5us();}//12t的mcu 注释这个延时即可
}
//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;





//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
// The code is checking if a certain bit in a number is 1 or 0. 
// The num variable is the number being checked, and the b variable is the bit position being checked. 
// The code uses a bitwise AND operation to check if the bit is 1 or not. 
// If the result is not 0, then the bit is 1. Otherwise, the bit is 0.


/*To judge the num bit*/

uchar judgebit(uchar num,uchar b)

{

         char n;

         num=num&(1<<b);

         if (num)

         n=1;

         else

         n=0;

         return n;

}

//;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
//This code is finding the absolute value of 'a'. 
//'a' is divided by 10 and the quotient is assigned to 'b'. 
//The remainder of 'a' divided by 10 is assigned back to 'a'. 
//If 'a' is greater than or equal to 5, 'b' is incremented by 1. 
//The final value of 'b' is returned.


/*To figure out the round number*/

uchar abs(uchar a)

{

         uchar b;

         b=a/10;

         a=a-b*10;

         if (a>=5)

         b++;

         return b;

}


;///////////////////////////////////////////////////////
// This code line defines a function that calculates the absolute value of a number. 
// If the number is negative, the function makes it positive before returning it.
	
/*To figure out the absolute value*/

uchar abss(char a)

{

         if (a<0)

         a=-a;

         return a;

}



;//////////////////////////////////////////////////////
// This code is a function that swaps the values of two variables if the first variable is greater than the second variable.
/*The function can comparat the character.

And remove the big one to the back.*/

void max(uchar *a,uchar *b)

{

   uchar t;

   if ((*a)>(*b))

   {

                   t=(*a);

                   (*a)=(*b);

                   (*b)=t;   

   }

}

////////////////////////////////////////////////////////////////////

/*The function is to figure out the max number and return it.*/
//This is a function that returns the maximum of three values.

uchar maxt(uchar a,uchar b,uchar c)

{

         if (a<b)

         a=b;

         if (a<c)

         a=c;

         return a;

}


// This code is creating a function called clear that takes in a character input called le. 
//The function then sets up two variables, i and j, that will be used as counters. 
//There is then a nested for loop that will run 8 times. 
//The first for loop will run through each row of the display array 
//and the second for loop will run through each column of the display array. 
//The nested for loop will set each element of the display array equal to the input character le.

void clear(char le)

{

         uchar i,j;

         for (j=0;j<8;j++)

         {

                   for (i=0;i<8;i++)

                   display[j][i]=le;

         }

}




// This is a function that creates a trailing effect. 
//The outer for loop iterates from 6 to -3. 
//The first if statement within the for loop says that if i is greater than or equal to 0, 
//then the program will execute the next for loop. 
//This for loop iterates through the columns of the display array 
//and sets the value of each element in the column to the element in the column to the right of it. 
//The second if statement within the for loop says that if i is less than 4, 
//then the program will execute the next for loop. 
//This for loop iterates through the columns of the display array and sets the value of each element in the column to 0. 
//This trailing effect is achieved by iterating through the columns of the array and shifting the values to the right by one each time.

void trailler(uint speed)

{

         char i,j;

         for (i=6;i>=-3;i--)

         {

                   if (i>=0)

                   {

                            for (j=0;j<8;j++)

                            display[j][i]=display[j][i+1];

                   }

                   if (i<4)

                   {

                            for (j=0;j<8;j++)

                            display[j][i+4]=0;

                   }

                   delay(speed);

         }

}
//This is a function that sets a single LED at the coordinates (x, y, z) to the state "le". 
//"le" is short for "level", with 1 meaning on and 0 meaning off. 
//The function works by creating a bitmask with a 1 in the position of the LED to be set. 
//It then ANDs or ORs this mask with the current value of the byte in the display array corresponding to the LED's position. 
//This changes the state of only the one LED.
	
	
void point(uchar x,uchar y,uchar z,uchar le)

{

         uchar ch1,ch0;

         ch1=1<<x;

         ch0=~ch1;

         if (le) 

         display[z][y]=display[z][y]|ch1;

         else 

         display[z][y]=display[z][y]&ch0;

}



//This code is defining a function to print a character on the screen. 
//The function takes in two parameters, the character to be printed (cha), 
//and the y-coordinate on the screen where the character should be printed. 
//The code then loops through each column of pixels in the character, 
//and sets the corresponding pixels in the display array to the corresponding pixels in the table_cha array.
	

void type(uchar cha,uchar y)

{        

         uchar xx;

         for (xx=0;xx<8;xx++)

         {

         display[xx][y]=table_cha[cha][xx];

         }

}

/*The first variable is the distance from the midpoint.
The second is the layer.
the third is the flash speed of the time between each two point.
The forth is the enable io,it controls weather draw or claen.*/

//This is a function definition for a function called "cirp." 
//The function takes in three parameters - "cpp" (a character), "dir" (a unsigned character), and "le" (a unsigned character).
//Inside the function, there is an if statement that checks if "cpp" is less than 128 and greater than or equal to 0. 
//If that is true, the code inside the if statement will run.
//The code inside the if statement initializes a variable called "cp." 
//If the "dir" parameter is true, "cp" will be set to 127 minus "cpp." If "dir" is false, "cp" will be set equal to "cpp."
//The code then initializes three variables - "a," "b," and "c." 
//"a" is set equal to the result of shifting "dat[cp]" right 5 bits and ANDing it with 0x07. 
//"b" is set equal to the result of shifting "dat[cp]" right 2 bits and ANDing it with 0x07. 
//"c" is set equal to the result of ANDing "dat[cp]" with 0x03.
//If "cpp" is greater than 63, "c" is set equal to 7 minus "c."
//Finally, the function calls the "point" function, passing in the four parameters "a," "b," "c," and "le."




void cirp(char cpp,uchar dir,uchar le)

{

         uchar a,b,c,cp;

         if ((cpp<128)&(cpp>=0))

         {

                   if (dir)

                   cp=127-cpp;

                   else 

                   cp=cpp; 

                   a=(dat[cp]>>5)&0x07;

                   b=(dat[cp]>>2)&0x07;

                   c=dat[cp]&0x03;

                   if (cpp>63)

                   c=7-c;

                   point (a,b,c,le);

         }

}


//This code is for drawing a line from point (x1, y1, z1) to point (x2, y2, z2) with a given length 'le'. 
//First, it finds the longest side of the line, then calculates how much to increment each coordinate 
//by for each point on the line using the proportion of the longest side. 
//Finally, it draws the line point by point using a for loop.

void line(uchar x1,uchar y1,uchar z1,uchar x2,uchar y2,uchar z2,uchar le)

{

         char t,a,b,c,a1,b1,c1,i;

         a1=x2-x1;

         b1=y2-y1;

         c1=z2-z1;

         t=maxt(abss(a1),abss(b1),abss(c1));

         a=x1*10;

         b=y1*10;

         c=z1*10;

         a1=a1*10/t;

         b1=b1*10/t;

         c1=c1*10/t;

         for (i=0;i<t;i++)

         {

                   point(abs(a),abs(b),abs(c),le);

                   a+=a1;

                   b+=b1;

                   c+=c1;

         }

         point(x2,y2,z2,le);

}


//This code is for a 3D cube. 
//The first three lines { uchar i,j,t=0; max(&x1,&x2); max(&y1,&y2); max(&z1,&z2); } set up the variables for the code. 
//The next line for (i=x1;i<=x2;i++) t|=1<<i; sets up a for loop that will run from x1 to x2, and will set t equal to 1 shifted left by i each time. 
//The next line if (!le) t=~t; will flip all the bits in t if le is not equal to 1. 
//The next line if (fill) { sets up an if statement that will run the code inside the curly braces if fill is equal to 1. 
//The next three lines { for (i=z1;i<=z2;i++) { for (j=y1;j<=y2;j++) display[j][i]|=t; } } will set up a for loop that will run from z1 to z2, 
//and will set the value of display[j][i] equal to t ORed with the current value of display[j][i]. 
//The code inside the curly braces { } will then run again, this time from y1 to y2. 
//If fill is not equal to 1, the code inside the else statement will run. 
//The next four lines 
//{ display[y1][z1]|=t; display[y2][z1]|=t; display[y1][z2]|=t; display[y2][z2]|=t; } 
//will set the value of display[y1][z1], display[y2][z1], display[y1][z2], and display[y2][z2] all equal to t ORed with the current value of each. 
//The next line t=(0x01<<x1)|(0x01<<x2); sets t equal to 1 shifted left by x1 ORed with 1 shifted left by x2. 
//The next line if (!le) t=~t; will flip all the bits in t if le is not equal to 1. 
//The next line if (le) { sets up an if statement that will run the code inside the curly braces if le is equal to 1. 
//The next three lines 
//{ for (j=z1;j<=z2;j+=(z2-z1)) { for (i=y1;i<=y2;i++) display[i][j]|=t; } for (j=y1;j<=y2;j+=(y2-y1)) { for (i=z1;i<=z2;i++) display[j][i]|=t; } } 
//will set up a for loop that will run from z1 to z2, and will set the value of display[i][j] equal to t ORed with the current value of display[i][j]. 
//The code inside the curly braces { } will then run again, this time from y1 to y2. 
//The code inside the curly braces { } will then run again, this time from z1 to z2. 
//The code inside the curly braces { } will then run again, this time from y1 to y2. 
//If le is not equal to 1, the code inside the else statement will run. 
//The next three lines 
//{ for (j=z1;j<=z2;j+=(z2-z1)) { for (i=y1;i<=y2;i++) { display[i][j]&=t; } } for (j=y1;j<=y2;j+=(y2-y1)) { for (i=z1;i<=z2;i++) { display[j][i]&=t; } } } 
//will set up a for loop that will run from z1 to z2, and will set the value of display[i][j] equal to t ANDed with the current value of display[i][j]. 
//The code inside the curly braces { } will then run again, this time from y1 to y2. 
//The code inside the curly braces { } will then run again, this time from z1 to z2. 
//The code inside the curly braces { } will then run again, this time from y1 to y2.


void box(uchar x1,uchar y1,uchar z1,uchar x2,uchar y2,uchar z2,uchar fill,uchar le)

{

         uchar i,j,t=0;

         max(&x1,&x2);

         max(&y1,&y2);

         max(&z1,&z2);

         for (i=x1;i<=x2;i++)

                   t|=1<<i;

         if (!le)

                   t=~t;

         if (fill)

         {

                   if (le)

                   {

                            for (i=z1;i<=z2;i++)

                            {

                                     for (j=y1;j<=y2;j++)

                                               display[j][i]|=t;

                            }

                   }

                   else

                   {

                            for (i=z1;i<=z2;i++)

                            {

                                     for (j=y1;j<=y2;j++)

                                               display[j][i]&=t;

                            }

                   }

         }

         else

         {

                   if (le)

                   {

                            display[y1][z1]|=t;

                            display[y2][z1]|=t;

                            display[y1][z2]|=t;

                            display[y2][z2]|=t;

                   }

                   else

                   {

                           display[y1][z1]&=t;

                            display[y2][z1]&=t;

                            display[y1][z2]&=t;

                            display[y2][z2]&=t;

                   }

                   t=(0x01<<x1)|(0x01<<x2);

                   if (!le)

                            t=~t;

                   if (le)

                   {

                            for (j=z1;j<=z2;j+=(z2-z1))

                            {

                                     for (i=y1;i<=y2;i++)

                                               display[i][j]|=t;

                            }

                            for (j=y1;j<=y2;j+=(y2-y1))

                            {

                                     for (i=z1;i<=z2;i++)

                                               display[j][i]|=t;

                            }

                   }

                   else

                   {

                            for (j=z1;j<=z2;j+=(z2-z1))

                            {

                                     for (i=y1;i<=y2;i++)

                                     {

                                     display[i][j]&=t;

                                     }

                            }

                            for (j=y1;j<=y2;j+=(y2-y1))

                            {

                                     for (i=z1;i<=z2;i++)

                                     {

                                     display[j][i]&=t;

                                     }

                            }

                   }

         }

}


//The first line creates a variable called "i" of type unsigned char.
//The second line calls the function "max" with two parameters, "z1" and "z2".
//The third line checks if the value of the variable "fill" is true. 
//If it is, the code executes the for loop on the fourth line. 
//This loop will continue executing until the value of "i" is greater than "z2". will run from the value of 'z1' up to and including the value of 'z2'. 
//Each time the loop runs, the 'line' function will be called with the coordinates of the two points and the value of 'i'.
//Inside the for loop, the fifth line calls the function "line" with seven parameters. 
//The first four parameters are the coordinates of the start and end points of the line. 
//The fifth and sixth parameters are the values of "i" and "le" respectively. The seventh parameter is the value of "z2".
//If the value of "fill" is not true, the code will execute the 'line' function four times,  on the sixth and seventh lines will execute.  once for each side of the cube. 
//These lines call the "line" function with the same parameters as before, except that the seventh parameter is the value of "z1" instead of "z2".


void box_apeak_xy(uchar x1,uchar y1,uchar z1,uchar x2,uchar y2,uchar z2,uchar fill,uchar le)

{

         uchar i;

         max(&z1,&z2);

         if (fill)

         {

                   for (i=z1;i<=z2;i++)

                   {

                            line (x1,y1,i,x2,y2,i,le);

                   } 

         } 

         else

         {

                   line (x1,y1,z1,x2,y2,z1,le);

                   line (x1,y1,z2,x2,y2,z2,le);

                   line (x2,y2,z1,x2,y2,z2,le);

                   line (x1,y1,z1,x1,y1,z2,le);

         }

}
//The poke function takes in three parameters - n, x and y. n is a number between 0 and 255, x and y are coordinates between 0 and 7.
//The function loops through the 8 bits of n, and sets the pixel at (x,y,i) to the value of the i-th bit of n.


void poke(uchar n,uchar x,uchar y)

{

         uchar i;

         for (i=0;i<8;i++)

         {

          point(x,y,i,judgebit(n,i));

         }

}



//The function boxtola takes two arguments, i and n, and does not return a value.
//If the value of i is between 0 and 7, the code sets the value of the byte at memory address n to 7-i.
//If the value of i is between 8 and 16, the code sets the value of the byte at memory address n to i-8.
//If the value of i is between 16 and 24, the code sets the value of the byte at memory address n to i-16.

void boxtola(char i,uchar n)

{

         if ((i>=0)&(i<8))

         {

                   poke(n,0,7-i);

         }

         if ((i>=8)&(i<16))

         {

                   poke(n,i-8,0);

         }

         if ((i>=16)&(i<24))

         {

                   poke(n,7,i-16);

         }

 

}

// The rolldisplay() function displays a scrolling message on the screen, with each character in the message appearing in turn. 
//The speed parameter determines how fast the message scrolls.
//The function first sets up a loop that will run for a total of 40 characters. 
//Within this loop, another loop is used to display each character in the message in turn.
//The first loop runs from 23 to -40, decrementing by 1 each time. 
//The second loop runs from 0 to 40, incrementing by 1 each time.
//For each iteration of the first loop, the second loop will display the character at the corresponding position in the message. 
//For example, on the first iteration of the first loop, 
//    the second loop will display characters 0-39 from the message. 
//    On the second iteration, it will display characters 1-40, and so on.
//Once all the characters have been displayed, the function delays for a time determined by the speed parameter, before starting again from the beginning.

void rolldisplay(uint speed)

{

         uchar j;

         char i,a;

         for (i=23;i>-40;i--)

         {

                   for (j=0;j<40;j++)

                   {

                            a=i+j;

                            if ((a>=0)&(a<24))

                            boxtola(a,table_id[j]);

                   }

                   delay(speed);

         }

}



///////////////////
//This is a function that creates an animation of a dot rolling around the edge of a cube. 
// The function takes in two parameters, n and speed. N determines which face of the cube the dot starts on, and speed determines how fast the dot should move. 
//The function uses a switch statement to determine which face of the cube to start on. 
//Then, there is a for loop that goes from i=0 to i<7. 
//Inside the for loop, the display array is updated to create the animation of the dot rolling around the edge of the cube. 
//Finally, the delay function is used to control the speed of the animation.


void roll_apeak_yz(uchar n,uint speed)

{

         uchar i;

         switch(n)

         {

                   case 1:

                            for (i=0;i<7;i++)

                            {

                                     display[i][7]=0;

                                     display[7][6-i]=255;

                                     delay(speed);

                            };

                            break;

                   case 2:

                            for (i=0;i<7;i++)

                            {

                                     display[7][7-i]=0;

                                     display[6-i][0]=255;

                                     delay(speed);

                            };

                            break;

                   case 3:

                            for (i=0;i<7;i++)

                            {

                                     display[7-i][0]=0;

                                     display[0][i+1]=255;

                                     delay(speed);

                            };

                            break;

                   case 0:

                            for (i=0;i<7;i++)

                            {

                                     display[0][i]=0;

                                     display[i+1][7]=255;

                                     delay(speed);

                            };

         }

}


//////////////
//This is a function that will roll an "apeak" across the LED matrix
//n is the number of the apeak (there are four apeaks, numbered 0-3)
//speed is the speed at which the apeak will roll
//The function starts by creating a loop that will run 7 times
//Inside the loop, the first LED in the apeak's column is turned on, and the last LED in the previous apeak's column is turned off
//Then, the loop delays for the speed that was inputted before repeating
//After the loop has finished running, the function will end
//
//This is a function that rolls a peak around the xy axis. 
//n is the starting point, with 0 being the top left, 
//1 being the top right, 2 being the bottom right, and 3 being the bottom left. 
//speed is the delay between each step. 
//The function works by first drawing a line in the direction it is supposed to go, 
//then drawing a line at the end of the peak, then delaying for however long is specified. 
//It repeats this process 7 times.


void roll_apeak_xy(uchar n,uint speed)

{

         uchar i;

         switch(n)

         {

                   case 1:

                            for (i=0;i<7;i++)

                            {

                                     line(0,i,0,0,i,7,0);

                                     line(i+1,7,0,i+1,7,7,1);

                                     delay(speed);

                            };

                            break;

                   case 2:

                            for (i=0;i<7;i++)

                            {

                                     line(i,7,0,i,7,7,0);

                                     line(7,6-i,0,7,6-i,7,1);

                                     delay(speed);

                            };

                            break;

                   case 3:

                            for (i=0;i<7;i++)

                            {

                                     line(7,7-i,0,7,7-i,7,0);

                                     line(6-i,0,0,6-i,0,7,1);

                                     delay(speed);

                            };

                            break;

                   case 0:

                            for (i=0;i<7;i++)

                            {

                                     line(7-i,0,0,7-i,0,7,0);

                                     line(0,i+1,0,0,i+1,7,1);

                                     delay(speed);

                            };

         }

}


////////////////
//This code is a function that creates an animation of a box rolling across the screen. 
//The function takes in two parameters, n and speed. 
//n corresponds to which direction the box will roll. 
//A value of 
//1 indicates the box will roll from left to right, 
//2 indicates the box will roll from top to bottom, 
//3 indicates the box will roll from right to left, 
//and 0 indicates the box will roll from bottom to top. 
//The speed parameter determines how fast the box will roll across the screen. 
//Inside the function, there is a for loop that iterates 8 times. 
//On each iteration of the loop, the box is moved one pixel in the direction specified by the n parameter. 
//The box is then redrawn in its new position. A delay is inserted between each iteration of the loop to control the speed of the animation.
//
//This function is used to roll a 3D box on a given xy plane. 
//The function takes in two parameters - 
//n - which is the plane on which the box has to be rolled (can be 1, 2, 3 or 0)
//speed - which is the speed at which the box has to be rolled
//Depending on the value of the 'n' parameter, the box is rolled on a different plane. 
//For example, if 'n' is 1, the box is rolled on the xy plane with the z axis pointing downwards. 
//Similarly, if 'n' is 2, the box is rolled on the xy plane with the z axis pointing to the left. 
//If 'n' is 3, the box is rolled on the xy plane with the z axis pointing upwards and if 'n' is 0, 
//the box is rolled on the xy plane with the z axis pointing to the right. 
//The box is rolled by first drawing it at a particular position and then clearing that position and drawing it at the next position. 
//This is repeated until the box has been rolled to the desired position.


void roll_3_xy(uchar n,uint speed)

{

         uchar i;

         switch(n)

         {

                   case 1:

                            for (i=0;i<8;i++)

                            {

                                     box_apeak_xy (0,i,0,7,7-i,7,1,1);

                                     delay(speed);

                                     if (i<7)

                                     box_apeak_xy (3,3,0,0,i,7,1,0);

                            };

                            break;

                   case 2:

                            for (i=0;i<8;i++)

                            {

                                      box_apeak_xy (7-i,0,0,i,7,7,1,1);

                                     delay(speed);

                                     if (i<7)

                                     box_apeak_xy (3,4,0,i,7,7,1,0);

                            };

                            break;

                   case 3:

                            for (i=0;i<8;i++)

                            {

                                     box_apeak_xy (0,i,0,7,7-i,7,1,1);

                                     delay(speed);

                                     if (i<7)

                                     box_apeak_xy (4,4,0,7,7-i,7,1,0);

                            };

                            break;

                   case 0:

                            for (i=0;i<8;i++)

                            {

                                     box_apeak_xy (7-i,0,0,i,7,7,1,1);

                                     delay(speed);

                                     if (i<7)

                                     box_apeak_xy (4,3,0,7-i,0,7,1,0);

                            };

         }

}
/////////////////////////
//This is a function that shifts all the pixels in an 8x8 display by one pixel to the right. 
//The function takes in two parameters: z, which is the row of the display that is being shifted, 
//and speed, which is the delay between each pixel shifting. 
//The function first shifts all the pixels in the row by one pixel to the right, then delays for the specified time before shifting the next row.
//This is a function that shifts all the bits in an array over by one to the right. 
//The function takes in two parameters, z which is the array to shift and speed which is the amount of time to delay between each shift. 
//The function first loops through each row in the array. For each row, it loops through each column and shifts the bits over by one. 
//After shifting all the bits, the function delays for the amount of time specified by the speed parameter. 
//The outer for loop iterates over the 8 rows in the display, and the inner for loop iterates over the 8 columns. 
//For each row and column, the code shifts the value in display[z][i] one pixel to the right.


void trans(uchar z,uint speed)

{

         uchar i,j;

         for (j=0;j<8;j++)

         {

                   for (i=0;i<8;i++)

                   {

                            display[z][i]>>=1;

                   }

                   delay(speed);

         }

}
///////////////////////////
//This function is responsible for outputting a character to the screen, one line at a time. 
//The character is defined by the variable "c", and the speed is defined by the variable "speed". 
//The first for loop is responsible for outputting the character one line at a time. 
//The second for loop is responsible for actually outputting the character to the screen. 
//The third for loop delays the output by the amount specified by the "speed" variable.
//The character is passed in as the "c" parameter, and the speed is passed in as the "speed" parameter. 
//The function loops through each column in the character, outputting the column to the display. 
//The speed parameter controls the delay between outputting each column.

void tranoutchar(uchar c,uint speed)

{

         uchar i,j,k,a,i2=0;

         for (i=0;i<8;i++)

         {

                   if (i<7)

                   box_apeak_xy (i+1,0,0,i+1,7,7,1,1);

                   box_apeak_xy (i2,0,0,i2,7,7,1,0);

                   a=0;

                   i2=i+1;

                   for (j=0;j<=i;j++)

                   {

                            a=a|(1<<j);

                   }

                   for (k=0;k<8;k++)

                   {

                            display[k][3]|=table_cha[c][k]&a;

                            display[k][4]|=table_cha[c][k]&a;

                   }

                   delay(speed);

         }

}
//////////////////////////////
//This is a function that shifts all of the values in the display array to the left by one.

void transss()

{

         uchar i,j;

         for (i=0;i<8;i++)

         {

                   for (j=0;j<8;j++)

                   display[i][j]<<=1;

         }

}

 

/*From now on,the function below is to display the flash.*/

//////////////////////
//This function is called flash_1().
//The first line clears the screen.
//The second line types "1" on the screen.
//The third line delays for 60,000 milliseconds.
//The fourth line types "2" on the screen.
//The fifth line delays for 60,000 milliseconds.
//The sixth line types "3" on the screen.
//The seventh line delays for 60,000 milliseconds.
//The eighth line types "4" on the screen.
//The ninth line delays for 60,000 milliseconds.
//The tenth line delays for 60,000 milliseconds.
//The eleventh line clears the screen.
//The twelfth line rolls the display.
//The thirteenth line types "0" on the screen.
//The fourteenth line delays for 60,000 milliseconds.
//The fifteenth line calls the trailler() function.
//The sixteenth line delays for 60,000 milliseconds.


void flash_1()

{
         clear(0);
         type(1,0);
         delay(60000);
         type(2,0);
         delay(60000);
         type(3,0);
         delay(60000);
         type(4,0);
         delay(60000);
         delay(60000);
         clear(0);
         rolldisplay(30000);
         type(0,7);
         delay(60000);
         trailler(6000);
         delay(60000);
}
///////////
//This code is for a function called flash_2. 
//The first for loop runs from 129 to 1, and for each number in that range, 
//   it turns on the LED at position i-2, then delays for 8 seconds. 
//   Then, it turns off the LED at position i-1. 
//After the first for loop has finished running, there is a delay of 8 seconds. 
//The second for loop runs from 0 to 136. 
//  For each number in that range, it turns on the LED at position i, 
//  delays for 8 seconds, then turns off the LED at position i-8. 
//After the second for loop has finished running, there is a delay of 8 seconds. 
//The third for loop is the same as the first, except that it only runs from 129 to 1. 
//After the third for loop has finished running, there is a delay of 8 seconds. 
//The fourth for loop is the same as the second, except that it only runs from 0 to 128. 
//After the fourth for loop has finished running, there is a delay of 60 seconds.



////////////////////////////
//This is a function that flashes two lights on and off. 
//The first for loop runs from 129 to 1, decrementing by 1 each time. 
//It turns on the light at position i-2 and then delays for 8 seconds. 
//It then turns off the light at position i-1. 
//After the for loop has finished running, there is another delay of 8 seconds. 
//The second for loop runs from 0 to 136, incrementing by 1 each time. 
//It turns on the light at position i and then delays for 8 seconds. 
//It then turns off the light at position i-8. 
//After the second for loop has finished running, there is another delay of 8 seconds. 
//The third for loop is the same as the first, but it does not turn off any lights. 
//After the third for loop has finished running, there is another delay of 8 seconds. 
//The fourth for loop is the same as the second, but it does not turn on any lights. 
//After the fourth for loop has finished running, there is a final delay of 60 seconds.


void flash_2()
{
         uchar i;
         for (i=129;i>0;i--)
         {
                   cirp(i-2,0,1);
                   delay(8000);
                   cirp(i-1,0,0);
         }
         delay(8000);     
         for (i=0;i<136;i++)
         {
                   cirp(i,1,1);
                   delay(8000);
                   cirp(i-8,1,0);
         }
         delay(8000);
                  for (i=129;i>0;i--)
         {
                   cirp(i-2,0,1);
                   delay(8000);
         }
         delay(8000);
                   for (i=0;i<128;i++)
         {
                   cirp(i-8,1,0);
                   delay(8000);
         }
         delay(60000);  
}
//////////////////////////////////////////////
//This function is called flash_3(). 
//It contains a for loop that will run 8 times. 
//Each time the loop runs, it will create a box on the screen that is 7 units wide and 7 units tall. 
//The box will be located at position (0,i) on the screen. 
//The function will then pause for 20,000 milliseconds before either deleting the box or moving on to the next iteration of the loop.

void flash_3()

{

         char i;

         for (i=0;i<8;i++)

         {

                   box_apeak_xy(0,i,0,7,i,7,1,1);

                   delay(20000);

                   if (i<7)

                   box_apeak_xy(0,i,0,7,i,7,1,0);

         }

         for (i=7;i>=0;i--)

         {

                   box_apeak_xy(0,i,0,7,i,7,1,1);

                   delay(20000);

                   if (i>0)

                   box_apeak_xy(0,i,0,7,i,7,1,0);

         }

         for (i=0;i<8;i++)

         {

                   box_apeak_xy(0,i,0,7,i,7,1,1);

                   delay(20000);

                   if (i<7)

                   box_apeak_xy(0,i,0,7,i,7,1,0);

         }

}
/////////////////////////////////////////////
//This is a function that creates a "flash" effect with 8 lines. 
//The first for loop sets the value of j to 7, and as long as j is less than 15, the value of j is incremented by 1. The value of an[j-7] is set to j. 
//The second for loop sets the value of i to 0, and as long as i is less than or equal to 16, the value of i is incremented by 1. 
//The third for loop sets the value of j to 0, and as long as j is less than 8, the value of j is incremented by 1. 
//   If the value of an[j] is less than 8 and greater than or equal to 0, 
//   then a line is drawn from point (0, an[j]) to point (j, 7) with a color corresponding to the value of an[j]. 
//The fourth for loop does the same thing as the third for loop, 
//   except it draws a line from point (0, an[j]+1) to point (j, 7) with a color corresponding to the value of an[j]+1. 
//The fifth for loop sets the value of j to 0, and as long as j is less than 8, the value of j is incremented by 1. 
//    If the value of an[j] is greater than 0, then the value of an[j] is decremented by 1. 
//A delay is created, and then the process repeats with the sixth for loop. 
//The sixth for loop sets the value of j to 0, and as long as j is less than 8, 
//the value of j is incremented by 1. The value of an[j] is set to 1-j. 
//The seventh for loop does the same thing as the third for loop, 
// except it draws a line from point (0, an[j]) to point (j, 7) with a color corresponding to the value of an[j]. 
//The eighth for loop does the same thing as the fourth for loop, 
// except it draws a line from point (0, an[j]-1) to point (j, 7) with a color corresponding to the value of an[j]-1. 
//The ninth for loop sets the value of j to 0, and as long as j is less than 8, 
// the value of j is incremented by 1. If the value of an[j] is less than 7, then the value of an[j] is incremented by 1. 
//A delay is created, and then the process repeats.


void flash_4()
{
         char i,j,an[8];
         for (j=7;j<15;j++)
                   an[j-7]=j;
         for (i=0;i<=16;i++)
         {
                   for (j=0;j<8;j++)
                   {
                            if ((an[j]<8)&(an[j]>=0))
                            line(0,an[j],j,7,an[j],j,1);
                   }
                   for (j=0;j<8;j++)
                   {
                            if (((an[j]+1)<8)&(an[j]>=0))
                            line(0,an[j]+1,j,7,an[j]+1,j,0);
                   }
                   for (j=0;j<8;j++)
                   {
                            if (an[j]>0)
                            an[j]--;
                   }
                   delay(15000);
         }
         for (j=0;j<8;j++)
                   an[j]=1-j;
         for (i=0;i<=16;i++)
         {
                   for (j=0;j<8;j++)
                   {
                            if ((an[j]<8)&(an[j]>=0))
                            line(0,an[j],j,7,an[j],j,1);
                   }
                   for (j=0;j<8;j++)
                   {
                            if (((an[j]-1)<7)&(an[j]>0))
                            line(0,an[j]-1,j,7,an[j]-1,j,0);
                   }
                   for (j=0;j<8;j++)
                   {
                            if (an[j]<7)
                            an[j]++;
                   }
                   delay(15000);
         }
}
//////////////////////////////////////////////////
// This code is creating a flashing light effect using boxes. 
//The first for loop is creating the boxes and the second for loop is making the boxes flash.

//The code defines a function called "flash_5." 
//The function includes a "for" loop that iterates four times. 
//Each time the loop runs, it defines two variables, "i" and "j," and sets their values to 8 and 7, respectively. 
//The loop then runs a series of commands that result in a flashing light effect. 
//Finally, the function ends with a delay of 15000 milliseconds.


void flash_5()
{
         uint a=15000;//a=delay
         char i=8,j,an[4];

//1
         for (j=7;j<11;j++)
                   an[j-7]=j;
         while(i--)
         {
                   for (j=0;j<4;j++)
                   {
                            if (an[j]<8)
                            box_apeak_xy(j,an[j],j,7-j,an[j],7-j,0,1);
                            if (an[j]<7)
                            box_apeak_xy(j,an[j]+1,j,7-j,an[j]+1,7-j,0,0);
                   }
                   for (j=0;j<4;j++)
                   {
                            if (an[j]>3)
                            an[j]--;
                   }
                   delay(a);
         }

	
//2
//
//1. The code sets the value of i to 3.
//2. It then enters a for loop that will run 4 times. 
//3. The code sets the value of an[j] to 5-j.
//4. It then enters a while loop that will run 3 times. 
//5. The code enters another for loop that will also run 4 times. 
//6. If the value of an[j] is less than 4, the code will run the box_apeak_xy function. 
//7. If the value of an[j] is less than 3, the code will run the box_apeak_xy function again. 
//8. The code then exits the for loop.
//9. The code enters another for loop that will run 4 times. 
//10. If the value of an[j] is greater than 0, the code will decrement the value of an[j]. 
//11. The code then exits the for loop.
//12. The code then exits the while loop.	
	
	
         i=3;
         for (j=0;j<4;j++)
         an[j]=5-j;
         while(i--)
         {
                   for (j=1;j<4;j++)
                   {
                            if (an[j]<4)
                            box_apeak_xy(j,an[j],j,7-j,an[j],7-j,0,1);
                            if (an[j]<3)
                            box_apeak_xy(j,an[j]+1,j,7-j,an[j]+1,7-j,0,0);
                   }
                   for (j=0;j<4;j++)
                   {
                            if (an[j]>0)
                            an[j]--;
                   }
                   delay(a);
         }

	
	
//3
//The next line declares a variable called "i" and assigns it the value 3.
//The next line is a for loop. It will execute the code inside the braces 3 times. The variable "j" is declared and initialized to 1. The code inside the braces will be executed. Then, the variable "j" will be incremented by 1. This will continue until the value of "j" is greater than 4.
//The next line is a while loop. It will execute the code inside the braces while the variable "i" is greater than 0.
//The next line is another for loop. It will execute the code inside the braces 3 times. The variable "j" is declared and initialized to 1. The code inside the braces will be executed. Then, the variable "j" will be incremented by 1. This will continue until the value of "j" is greater than 4.
//The next line is an if statement. It will execute the code inside the braces if the variable "an[j]" is greater than or equal to 0.
//The next line is another if statement. It will execute the code inside the braces if the variable "an[j]" is greater than 0.
//The next line is a for loop. It will execute the code inside the braces 3 times. The variable "j" is declared and initialized to 1. The code inside the braces will be executed. Then, the variable "j" will be incremented by 1. This will continue until the value of "j" is greater than 4.
//The next line is an if statement. It will execute the code inside the braces if the variable "an[j]" is less than 3.
//The next line will increment the variable "an[j]" by 1.
//The next line will delay the execution of the code by "a" milliseconds.
	
	i=3;
         for (j=1;j<4;j++)
         an[j]=4-j;
         while(i--)
         {
                   for (j=1;j<4;j++)
                   {
                            if (an[j]>=0)
                            box_apeak_xy(j,an[j],j,7-j,an[j],7-j,0,1);
                            if (an[j]>0)
                            box_apeak_xy(j,an[j]-1,j,7-j,an[j]-1,7-j,0,0);
                   }
                   for (j=1;j<4;j++)
                   {
                            if (an[j]<3)
                            an[j]++;
                   }
                   delay(a);
         }

//4
//i is initialized to 3.
//For loop iterates from j=0 to j<4. 
//an[j] is assigned j+1.
//While loop iterates until i becomes 0. 
//For loop iterates from j=1 to j<4.
//If an[j] is greater than 3, box_apeak_xy function is called with arguments (j, an[j], j, 7-j, an[j], 7-j, 0, 1).
//If an[j] is greater than 3, box_apeak_xy function is called with arguments (j, an[j]-1, j, 7-j, an[j]-1, 7-j, 0, 0).
//For loop iterates from j=0 to j<4. 
//an[j] is incremented by 1.
//delay(a) function is called.
	
	
	i=3;
         for (j=0;j<4;j++)
         an[j]=j+1;
         while(i--)
         {
                   for (j=1;j<4;j++)
                   {
                            if (an[j]>3)
                            box_apeak_xy(j,an[j],j,7-j,an[j],7-j,0,1);
                            if (an[j]>3)
                            box_apeak_xy(j,an[j]-1,j,7-j,an[j]-1,7-j,0,0);
                   }
                   for (j=0;j<4;j++)
                            an[j]++;
                   delay(a);
         }

	
	
	
//5
 
//i is set to 3, and then a for loop runs from 3 to 6, setting each value of an to j. 
//Then, there is a while loop that runs until i is no longer positive. 
//Inside of the while loop, there is another for loop that runs from 1 to 4. 
//This for loop prints out the asterisks in the diamond pattern. 
//After the for loop, there is another for loop that runs from 0 to 4. 
//If the value of an at the current index is greater than 3, the value is decremented by 1. 
//Then, delay is called with the parameter a.	
  
	i=3;
         for (j=3;j<6;j++)
                   an[j-2]=j;
         while(i--)
         {
                   for (j=1;j<4;j++)
                   {
                            box_apeak_xy(j,an[j],j,7-j,an[j],7-j,0,1);
                            box_apeak_xy(j,an[j]+1,j,7-j,an[j]+1,7-j,0,0);
                   }
                   for (j=0;j<4;j++)
                   {
                            if (an[j]>3)
                            an[j]--;
                   }
                   delay(a);
         }

//6
//i=3 means that the loop will iterate 3 times
//j<4 means that the inner loop will iterate 4 times
//an[j]=5-j means that the value of an will be 5-j
//while(i--) means that the loop will continue while i is not equal to 0
//for (j=1;j<4;j++) means that the inner loop will iterate 4 times
//if (an[j]<4) means that if the value of an is less than 4, it will execute the next line
//box_apeak_xy(j,an[j],j,7-j,an[j],7-j,0,1); means that it will create a box with the given parameters
//if (an[j]<3) means that if the value of an is less than 3, it will execute the next line
//box_apeak_xy(j,an[j]+1,j,7-j,an[j]+1,7-j,0,0); means that it will create a box with the given parameters
//for (j=0;j<4;j++) means that the inner loop will iterate 4 times
//if (an[j]>0) means that if the value of an is greater than 0, it will execute the next line
//an[j]--; means that the value of an will be decremented by 1
//delay(a); means that it will wait for 'a' milliseconds before executing the next line
  
	
	 i=3;
         for (j=0;j<4;j++)
         an[j]=5-j;
         while(i--)
         {
                   for (j=1;j<4;j++)
                   {
                            if (an[j]<4)
                            box_apeak_xy(j,an[j],j,7-j,an[j],7-j,0,1);
                            if (an[j]<3)
                            box_apeak_xy(j,an[j]+1,j,7-j,an[j]+1,7-j,0,0);
                   }
                   for (j=0;j<4;j++)
                   {
                            if (an[j]>0)
                            an[j]--;
                   }
                   delay(a);
         }

//7
//The code creates a for loop that iterates 4 times. 
//For each iteration, the value of j is set to 0. The code then sets the value of an[j] to 3-j. The value of an[0] is set to 2. 
//The code then enters a while loop that runs as long as the value of i is greater than 0. 
//The code inside the while loop creates a for loop that iterates 3 times. 
//For each iteration, the code checks if the value of an[j] is greater than or equal to 0. 
//If it is, the code calls the box_apeak_xy() function with the arguments j, an[j], j, 7-j, an[j], 7-j, 0, 1. 
//The code then calls the box_apeak_xy() function again with the arguments j, an[j]+1, j, 7-j, an[j]+1, 7-j, 0, 0. 
//After the for loop has finished iterating, the code sets the value of j to 0. 
//The code then sets the value of an[j] to 3-j. The value of an[0] is set to 2. 
//The code then calls the delay() function with the argument a. 
//The code then decrements the value of i by 1 and the while loop repeats.

	i=3;
         for (j=0;j<4;j++)
         an[j]=3-j;
         an[0]=2;
         while(i--)
         {
                   for (j=0;j<3;j++)
                   {
                            if (an[j]>=0)
                                     box_apeak_xy(j,an[j],j,7-j,an[j],7-j,0,1);
                            if (an[j]>=0)
                                     box_apeak_xy(j,an[j]+1,j,7-j,an[j]+1,7-j,0,0);
                   }
                   for (j=0;j<4;j++)
                   {
                            if (j<5-i)
                            an[j]--;
                   }
                   delay(a);
         }

//8
// It defines a for loop that iterates four times. 
//Within the for loop, the code defines a variable named "an" as an array of four elements. 
//The code then defines a while loop that iterates ten times. 
//Within the while loop, the code defines a nested for loop that iterates four times. 
//The nested for loop contains code that draws a box on the screen. 
//The code then increments the value of the "an" array by one. 
//The code then delays for a period of time before repeating the while loop.
//
//there is a for loop that sets the value of j to 0. 
//J is less than 4, so the loop will continue until the value of j is 4. 
//The value of i is 10. The loop will continue until the value of i is 0. 
//The value of an is set to j-2. 
//If the value of an is greater than or equal to 0, the box will be displayed. 
//If the value of an is greater than or equal to 0, the box will be displayed in the next line. 
//The value of an is incremented by 1. If the value of an is less than 7, the loop will continue. 
//The value of an is incremented by 1. The delay is set to a.
	
	
	i=10;
         for (j=0;j<4;j++)
                   an[j]=j-2;
         while(i--)
         {
                   for (j=0;j<4;j++)
                   {
                            if (an[j]>=0)
                            box_apeak_xy(j,an[j],j,7-j,an[j],7-j,0,1);
                            if (an[j]>=0)
                            box_apeak_xy(j,an[j]-1,j,7-j,an[j]-1,7-j,0,0);
                   }
                   for (j=0;j<4;j++)
                   {
                            if (an[j]<7)
                            an[j]++;
                   }
                   delay(a);
         }
 }
/////////////////////////////////////////////////////////////////////////
//The function flash_6() uses a for loop to roll the apeks on the y and z axes. 
//It also uses a for loop to flash the apeks on the x axis.
//This function is part of a larger program that flashes an LED in a certain pattern. 
//This particular function makes the LED appear to roll up a peak. 
//First, the roll_apeak_yz function is called three times. 
//This function turns the LED on and off to create the illusion of movement. 
//Next, the for loop is executed three times. 
//This loop goes through each row of the LED and turns on the appropriate pixels to create the peak. 
//Finally, the trans function is called to create a delay between each peak.


void flash_6()
{
      uchar i,j,k,z;
      roll_apeak_yz(1,10000);
      roll_apeak_yz(2,10000);
      roll_apeak_yz(3,10000);
      roll_apeak_yz(0,10000);
      roll_apeak_yz(1,10000);
      roll_apeak_yz(2,10000);
      roll_apeak_yz(3,10000);
      for (i=0;i<3;i++)
               {
                         for (j=0;j<8;j++)
                         {
                                  for (k=0;k<8;k++)
                                  {
                                           if ((table_3p[i][j]>>k)&1)
                                           {
                                                     for (z=1;z<8;z++)
                                                              {
                                                                       point (j,7-k,z,1);
                                                                       if (z-1)
                                                                       point (j,7-k,z-1,0);
                                                                       delay(5000);
                                                              }
                                           }
                                  }
                         }
                         trans(7,15000);
               }
}


//////////////////////////////////
//The function flash_7 is a series of commands that cause a series of actions to happen in sequence. These actions are:
//1. The roll_apeak_yz function is called four times, once for each of the four possible values of i (0, 1, 2, and 3). 
//This function causes a "peak" to appear in the middle of the display, moving from left to right.
//2. The roll_apeak_xy function is called four times, once for each of the four possible values of i (0, 1, 2, and 3). 
//This function causes a "peak" to appear in the middle of the display, moving from top to bottom.
//3. A for loop is executed, causing the box_apeak_xy function to be called eight times. 
//This function draws a box on the display, with the top left corner at coordinates (0,0), the bottom right corner at coordinates (7,7), 
//and with the box moving from left to right.
//4. A delay of 30,000 milliseconds (30 seconds) is executed.
//5. The roll_3_xy function is called four times, once for each of the four possible values of i (0, 1, 2, and 3). 
//This function causes the display to "roll" from left to right, with each column of pixels moving one pixel to the right.
//6. A delay of 30,000 milliseconds (30 seconds) is executed.
//7. A for loop is executed, causing the box_apeak_xy function to be called eight times. 
//This function draws a box on the display, with the top left corner at coordinates (7,0), the bottom right corner at coordinates (0,7), 
//and with the box moving from right to left.


void flash_7()
{
      uchar i;
      uint a=3000;
      roll_apeak_yz(0,10000);
      roll_apeak_yz(1,10000);
      roll_apeak_yz(2,10000);
      roll_apeak_yz(3,10000);
      roll_apeak_yz(0,10000);
      roll_apeak_yz(1,10000);
      roll_apeak_yz(2,10000);
      roll_apeak_yz(3,10000);
      roll_apeak_yz(0,10000);
      roll_apeak_yz(1,10000);
      roll_apeak_yz(2,10000);
      roll_apeak_xy(0,10000);
      roll_apeak_xy(1,10000);
      roll_apeak_xy(2,10000);
      roll_apeak_xy(3,10000);
      roll_apeak_xy(0,10000);
      roll_apeak_xy(1,10000);
      roll_apeak_xy(2,10000);
      roll_apeak_xy(3,10000);
      for (i=0;i<8;i++)
      {
               box_apeak_xy (0,i,0,7-i,i,7,1,1);
               delay(a);
      }
      delay(30000);
      roll_3_xy(0,a);
      delay(30000);
      roll_3_xy(1,a);
      delay(30000);
      roll_3_xy(2,a);
      delay(30000);
      roll_3_xy(3,a);
      delay(30000);
      roll_3_xy(0,a);
      delay(30000);
      roll_3_xy(1,a);
      delay(30000);
      roll_3_xy(2,a);
      delay(30000);
      roll_3_xy(3,a);
      for (i=7;i>0;i--)
      {
               box_apeak_xy(i,0,0,i,7,7,1,0);
               delay(a);
      }
}


////////////////////////////////////////////////////////////
//The function flash_8() will output the characters 5, 6, and 7 to the screen, 
//each character separated by a delay of 60,000 milliseconds.


void flash_8()
{
      uchar i;
      for (i=5;i<8;i++)
      {
               tranoutchar(i,10000);
               delay(60000);
               delay(60000);
      }
}



///////////////////////////////////////////////////////////
//This function displays a series of animations on the LED matrix. 
//First, a series of boxes are displayed on the matrix, each box appearing in a different location. 
//Then, the boxes roll across the matrix. Next, a series of lines are drawn on the matrix. 
//Finally, a series of boxes are displayed, filling up the matrix. and then disappearing. how it works in detail:
//The function starts by displaying a series of boxes on the matrix. 
//For each box, the function first calculates the x and y coordinates of the top left and bottom right corners of the box. 
//It then calls the box_apeak_xy() function to draw the box. 
//The box_apeak_xy() function takes four arguments: 
//the x and y coordinates of the top left corner of the box, 
//the x and y coordinates of the bottom right corner of the box, 
//and a boolean value indicating whether the box should be filled in or not.
//After all the boxes have been drawn, the function calls the roll_apeak_xy() function to roll the boxes across the matrix. 
//The roll_apeak_xy() function takes two arguments: the number of pixels to roll the boxes, and the delay in between each pixel.
//Next, the function draws a series of lines on the matrix. 
//For each line, the function first calculates the x and y coordinates of the start and end points of the line. 
//It then calls the line() function to draw the line. 
//The line() function takes four arguments: 
//the x and y coordinates of the start point of the line, 
//the x and y coordinates of the end point of the line, 
//and a boolean value indicating whether the line should be filled in or not.
//Finally, the function displays a series of boxes on the matrix, 
//filling up the entire matrix. 
//For each box, the function again calculates the x and y coordinates of the top left and bottom right corners of the box. 
//It then calls the box_apeak_xy() function to draw the box. 
//This time, however, the function also passes a third argument to the box_apeak_xy() function: the delay in between each pixel.
//After all the boxes have been drawn, the function calls the delay() function to pause for a moment before starting the next animation.

void flash_9()
{
      char i;
      uchar j,an[8],x,y,t,x1,y1;
      for (i=0;i<8;i++)
      {
               box_apeak_xy (i,0,0,i,7,7,1,1);
               if (i)
               box_apeak_xy (i-1,0,0,i-1,7,7,1,0);
               delay(10000);
      }
      roll_apeak_xy(3,10000);
      roll_apeak_xy(0,10000);
      roll_apeak_xy(1,10000);
      for (i=0;i<7;i++)
      {
               line(6-i,6-i,0,6-i,6-i,7,1);
               line(i,7,0,i,7,7,0);
               delay(10000);
      }
      for (i=0;i<8;i++)
               an[i]=14;
      for (i=0;i<85;i++)
      {
               clear(0);
               for (j=0;j<8;j++)
               {
                         t=an[j]%28;
                         x=dat2[t]>>5;
                         y=(dat2[t]>>2)&0x07;
                         t=(an[j]-14)%28;
                         x1=dat2[t]>>5;
                         y1=(dat2[t]>>2)&0x07;
                         line(x,y,j,x1,y1,j,1);
               }
               for (j=0;j<8;j++)
               {
               if ((i>j)&(j>i-71))
               an[j]++;
               } 
               delay(5000);
      }
      for (i=0;i<85;i++)
      {
               clear(0);
               for (j=0;j<8;j++)
               {
                         t=an[j]%28;
                         x=dat2[t]>>5;
                         y=(dat2[t]>>2)&0x07;
                         t=(an[j]-14)%28;
                         x1=dat2[t]>>5;
                         y1=(dat2[t]>>2)&0x07;
                         line(x,y,j,x1,y1,j,1);
               }
               for (j=0;j<8;j++)
               {
               if ((i>j)&(j>i-71))
               an[j]--;
               } 
               delay(5000);
      }
      for (i=0;i<29;i++)
      {
               clear(0);
               t=an[0]%28;
               x=dat2[t]>>5;
               y=(dat2[t]>>2)&0x07;
               t=(an[0]-14)%28;
               x1=dat2[t]>>5;
               y1=(dat2[t]>>2)&0x07;
               box_apeak_xy(x,y,0,x1,y1,7,0,1);
               box_apeak_xy(x,y,1,x1,y1,6,0,1);
               an[0]++; 
               delay(5000);
      }
      for (i=0;i<16;i++)
      {
               clear(0);
               t=an[0]%28;
               x=dat2[t]>>5;
               y=(dat2[t]>>2)&0x07;
               t=(an[0]-14)%28;
               x1=dat2[t]>>5;
               y1=(dat2[t]>>2)&0x07;
               box_apeak_xy(x,y,0,x1,y1,7,1,1);
               an[0]--; 
               delay(5000);
      }
      for (i=0;i<8;i++)
      {
               line(i,i,0,0,0,i,0);
               delay(5000);
      }
      for (i=1;i<7;i++)
      {
               line(i,i,7,7,7,i,0);
               delay(5000);
      }
      for (i=1;i<8;i++)
      {
               clear(0);
               box(7,7,7,7-i,7-i,7-i,0,1);
               delay(10000);
      }
      for (i=1;i<7;i++)
      {
               clear(0);
               box(0,0,0,7-i,7-i,7-i,0,1);
               delay(10000);
      }
      for (i=1;i<8;i++)
      {
               clear(0);
               box(0,0,0,i,i,i,0,1);
               delay(10000);
      }
      for (i=1;i<7;i++)
      {
               clear(0);
               box(7,0,0,i,7-i,7-i,0,1);
               delay(10000);
      }
      for (i=1;i<8;i++)
      {
               box(7,0,0,7-i,i,i,1,1);
               delay(10000);
      }
      for (i=1;i<7;i++)
      {
               clear(0);
               box(0,7,7,7-i,i,i,1,1);
               delay(10000);
      }
}
///////////////////////////////////////////////////////////////////////
//This code creates a flashing animation consisting of a series of filled in squares. 
//The first for loop creates the initial square pattern. 
//The next four for loops create the animation of the squares moving around the screen. 
//The last for loop reverses the animation.
//
//This function creates a simple animation of four objects moving around the screen. 
//The objects are created using the "box" function, which draws a rectangle of a given size and color. 
//The objects start in the middle of the screen and move outward in a spiral pattern.
//They then move back inward in the same pattern and finally disappear off the screen. and the screen is cleared.how the function works:
//The function first creates an array of four objects, each with a different starting position. 
//The objects are then drawn on the screen in their starting positions.
//The function then enters a loop, in which the objects are moved one pixel at a time in a spiral pattern. 
//After each movement, the function pauses for a short time. This delay is what creates the animation effect.
//Once the objects have reached the edge of the screen, the function reverses the direction of the spiral pattern 
//and the objects move back toward the center of the screen. 
//When the objects reach the center, the function ends and the screen is cleared.any more specific details:
//The function uses the "box" function to draw the objects. 
//The "box" function takes four parameters: the x and y coordinates of the top left corner of the box, 
//the width and height of the box. 
//The function also uses the "delay" function, which pauses the program for a given number of milliseconds.and that's it!
//This function creates a simple animation of four objects moving around the screen. 
//The objects are created using the "box" function, which draws a rectangle of a given size and color. 
//The objects start in the middle of the screen and move outward in a spiral pattern. 
//They then move back inward in the same pattern and finally disappear off the screen.more specifically, the function works as follows:
//The function first creates an array of four objects, each with a different starting position. 
//The objects are then drawn on the screen in their starting positions.
//The function then enters a loop, in which the objects are moved one pixel at a time in a spiral pattern. 
//After each movement, the function pauses for a short time. This delay is what creates the animation effect.
//Once the objects have reached the edge of the screen, the function reverses the direction of the spiral pattern 
//and the objects move back toward the center of the screen. When the objects reach the center, the function ends and the screen is cleared.

void flash_10()
{
 

	
	
	uchar i,j,an[4],x,y,t; // these are all variables that will be used within the function 
      for (i=1;i<7;i++)		//this for loop is used to draw a box that starts from the top left corner and gets bigger as it goes down and to the right
      {
               
               clear(0); //this clears the screen 
	      
   

	      
               box(0,6,6,1,7,7,1,1);  //this draws a box in the top left corner 
               box(i,6,6-i,i+1,7,7-i,1,1); //this draws a box that starts from the top left corner and gets bigger as it goes down and to the right 
               box(i,6,6,i+1,7,7,1,1); //this draws a box in the top left corner that is the same size as the previous box 
               box(0,6,6-i,1,7,7-i,1,1);//this draws a box in the top left corner that is the same size as the previous box 
               box(0,6-i,6,1,7-i,7,1,1);//this draws a box in the top left corner that is the same size as the previous box 
               box(i,6-i,6-i,i+1,7-i,7-i,1,1);//this draws a box in the top left corner that is the same size as the previous box 
               box(i,6-i,6,i+1,7-i,7,1,1);//this draws a box in the top left corner that is the same size as the previous box 
               box(0,6-i,6-i,1,7-i,7-i,1,1);//this draws a box in the top left corner that is the same size as the previous box 
               delay(30000);//this delays the next line of code from running for 30,000 milliseconds
      }
      for (i=0;i<4;i++)//this for loop is used to set the value of the 'an' array 
      {
               an[i]=6*i;//this sets the value of the 'an' array to 6 times the index 
      }
      for (i=0;i<35;i++)//this for loop is used to draw a series of boxes that start in the top left corner and travel down the screen 
      {
               clear(0);//this clears the screen 
	      
  
 
	      
	      
	      
	      
               for(j=0;j<4;j++) //this for loop is used to draw the boxes 
               {
                         t=an[j]%24; //this sets the value of 't' to the value of 'an' at index 'j' modulo 24 
                         x=dat3[t]>>4; //this sets the value of 'x' to the value of 'dat3' at index 't' shifted 4 bits to the right 
                         y=dat3[t]&0x0f;//this sets the value of 'y' to the value of 'dat3' at index 't' ANDed with 0x0f 
                         box(x,y,0,x+1,y+1,1,1,1);//this draws a box at coordinates 'x, y' that is 1x1 
                         box(x,y,6,x+1,y+1,7,1,1);//this draws a box at coordinates 'x, y' that is 1x1 
               }
               for (j=0;j<4;j++)  ;//this for loop is used to increment the value of 'an'
               an[j]++; //this increments the value of 'an' at index 'j'
               delay(10000); //this delays the next line of code from running for 10,000 milliseconds
      }
      for (i=0;i<35;i++) ; 	//this for loop is used to draw a series of boxes 
				//that start in the top left corner and travel down the screen in the reverse order from the previous for loop 
      {
               clear(0);
	      
	      
//
	      
               for(j=0;j<4;j++);//this for loop is used to draw the boxes 
               {
                         t=an[j]%24;//this sets the value of 't' to the value of 'an' at index 'j' modulo 24 
                         x=dat3[t]>>4;//this sets the value of 'x' to the value of 'dat3' at index 't' shifted 4 bits to the right 
                         y=dat3[t]&0x0f;//this sets the value of 'y' to the value of 'dat3' at index 't' ANDed with 0x0f 
                         box(x,y,0,x+1,y+1,1,1,1);//this draws a box at coordinates 'x, y' that is 1x1 
                         box(x,y,6,x+1,y+1,7,1,1);//this draws a box at coordinates 'x, y' that is 1x1 
               }
               for (j=0;j<4;j++)  //this for loop is used to decrement the value of 'an' 
               an[j]--; //this decrements the value of 'an' at index 'j' 
               delay(10000);// this delays the next line of code from running for 10,000 milliseconds 
	      
	      
	      
//
      }
      for (i=0;i<35;i++);//this for loop is used to draw a series of boxes that start in the top left corner and travel across the screen 
      {
               clear(0);//this clears the screen 
               for(j=0;j<4;j++);//this for loop is used to draw the boxes 
               {
                         t=an[j]%24;//this sets the value of 't' to the value of 'an' at index 'j' modulo 24 
                         x=dat3[t]>>4;//this sets the value of 'x' to the value of 'dat3' at index 't' shifted 4 bits to the right 
                         y=dat3[t]&0x0f;//this sets the value of 'y' to the value of 'dat3' at index 't' ANDed with 0x0f 
                         box(x,0,y,x+1,1,y+1,1,1);//this draws a box at coordinates 'x, y' that is 1x
                         box(x,6,y,x+1,7,y+1,1,1);//this draws a box at coordinates 'x, y' that is 1x1 
               }
               for (j=0;j<4;j++)//this for loop is used to increment the value of 'an' 
               an[j]++; //this increments the value of 'an' at index 'j' 
               delay(10000);//this delays the next line of code from running for 10,000 milliseconds 
	      
//
	      
	      
      }
      for (i=0;i<36;i++)	// this for loop is used to draw a series of boxes that start in the top left corner 
	     			//and travel across the screen in the reverse order from the previous for loop 
      {
               clear(0);//this clears the screen 
               for(j=0;j<4;j++)//this for loop is used to draw the boxes 
               {
                         t=an[j]%24;//this sets the value of 't' to the value of 'an' at index 'j' modulo 24 
                         x=dat3[t]>>4;//this sets the value of 'x' to the value of 'dat3' at index 't' shifted 4 bits to the right 
                         y=dat3[t]&0x0f;//this sets the value of 'y' to the value of 'dat3' at index 't' ANDed with 0x0f 
                         box(x,0,y,x+1,1,y+1,1,1);//this draws a box at coordinates 'x, y' that is 1x1 
                         box(x,6,y,x+1,7,y+1,1,1);//this draws a box at coordinates 'x, y' that is 1x1 
               }
               for (j=0;j<4;j++)//this for loop is used to decrement the value of 'an' 
               an[j]--; //this decrements the value of 'an' at index 'j' 
               delay(10000);//this delays the next line of code from running for 10,000 milliseconds     
	      
	      
//This is a for loop that is counting down from 6 to 0. 

//This is a for loop that creates a decreasing box size. It starts at the largest size and decreases by one unit until it reaches the smallest size. 
//For each number in the loop, it will clear the screen and draw a new box. 
//The new box will be shifted over by the number of the loop. 
//So the first box will be shifted over by 1, the second box will be shifted over by 2, and so on.	 
//      
      }
      for (i=6;i>0;i--)
      {
               
               clear(0);			//clears the screen. 
               box(0,6,6,1,7,7,1,1);		//creates a box with the coordinates (0,6), (6,6), (6,7), and (7,7). 
               box(i,6,6-i,i+1,7,7-i,1,1);	//creates a box with the coordinates (i,6), (6-i,6), (6-i,7-i), and (7-i,7-i). 
               box(i,6,6,i+1,7,7,1,1);		//creates a box with the coordinates (i,6), (6,6), (6,7), and (7,7). 
               box(0,6,6-i,1,7,7-i,1,1);	//creates a box with the coordinates (0,6), (6-i,6), (6-i,7-i), and (7-i,7-i). 
               box(0,6-i,6,1,7-i,7,1,1);	//creates a box with the coordinates (0,6-i), (6,6-i), (6,7), and (7,7). 
               box(i,6-i,6-i,i+1,7-i,7-i,1,1);	//creates a box with the coordinates (i,6-i), (6-i,6-i), (6-i,7-i), and (7-i,7-i). 
               box(i,6-i,6,i+1,7-i,7,1,1);	//creates a box with the coordinates (i,6-i), (6,6-i), (6,7), and (7,7). 
               box(0,6-i,6-i,1,7-i,7-i,1,1);	//creates a box with the coordinates (0,6-i), (6-i,6-i), (6-i,7-i), and (7-i,7-i). 
               delay(30000);			//delays the next action by 30000 milliseconds.	
      }
}


///////////////////////////////////////////////////////
 
//

The sixth line 

The seventh line 

The eighth line 

The ninth line calls the delay() function and passes in 10000.

The tenth line is an else statement.

The eleventh line 

The twelfth line calls the line() function and passes in 7 parameters.

The thirteenth line calls the transss() function.

The fourteenth line calls the delay() function and passes in 10000.

The fifteenth line is a for loop that iterates 8 times.

The sixteenth line checks if the value of j is greater than 3.

The seventeenth line assigns the value of 4 to t.

The eighteenth line is an else statement.

The nineteenth line assigns the value of j to t.

The twentieth line is a for loop that iterates 24 times.

The twenty-first line assigns the value of dat3 at index i shifted right 4 bits to x.

The twenty-second line assigns the value of dat3 at index i AND'ed with 0x0f to y.

The twenty-third line calls the box_apeak_xy() function and passes in 8 parameters.

The twenty-fourth line calls the transss() function.

The twenty-fifth line calls the delay() function and passes in 10000.

The twenty-sixth line is a for loop that iterates 8 times.

The twenty-seventh line checks if the value of j is greater than 3.

The twenty-eighth line assigns the value of 4 to t.

The twenty-ninth line is an else statement.

The thirtieth line assigns the value of j to t.

The thirty-first line is a for loop that iterates 24 times.

The thirty-second line assigns the value of dat3 at index i shifted right 4 bits to x.

The thirty-third line assigns the value of dat3 at index i AND'ed with 0x0f to y.

The thirty-fourth line calls the point() function and passes in 4 parameters.

The thirty-fifth line calls the transss() function.

The thirty-sixth line calls the delay() function and passes in 10000.


void flash_11()
{
      uchar i,j,t,x,y; 						//declares a variable called i, j, t, x and y as unsigned chars.
      uchar code daa[13]={0,1,2,0x23,5,6,7,6,5,0x23,2,1,0};	//declares an array called daa with 13 elements.
      for (j=0;j<5;j++)						//for loop that iterates 5 times.
      {
               for (i=0;i<13;i++)				//for loop that iterates 13 times.
               {
                         if (daa[i]>>4)				//checks if the value of daa at index i is greater than 4.
                         {
                                  t=daa[i]&0x0f;		//assigns the value of daa at index i and AND's it with 0x0f.
                                  line (0,0,t+1,0,7,t+1,1);	//calls the line() function and passes in 7 parameters.
                         }
                         else 
                                  t=daa[i];			//
                         line (0,0,t,0,7,t,1);			//
                         transss();				// calls the transss() function.
                         delay(10000);				//
               }
      }
	//  The first 'for' loop is designed to iterate through each value of j from 1 to 8. 
	//the second 'for' loop is designed to iterate through each value of i from 0 to 24, adding j to i each time. 
	// The 'if' statement is designed to change the value of t to 4 after j becomes greater than 3. 
	//The 'x' variable is designed to store the value of dat3[i] shifted 4 bits to the right. 
	//The 'y' variable is designed to store the value of dat3[i] with its rightmost 4 bits masked off. 
	//The 'box_apeak_xy' function is designed to draw a box with the top left corner at (0,x,y), 
	//the bottom right corner at (0,x+1,y+1), and with a line width of 1. 
	//The 'transss' function is designed to apply a transparency effect to the box. 
	//The 'delay' function is designed to pause the program for 10,000 milliseconds.
	
      for (j=1;j<8;j++)
      {
               if (j>3)
                         t=4;
               else
                         t=j;
               for (i=0;i<24;i+=j)				 
               {
                         x=dat3[i]>>4;
                         y=dat3[i]&0x0f;
                         box_apeak_xy(0,x,y,0,x+1,y+1,1,1);
                         transss();
                         delay(10000);
               }
      }
	
	
	//The outer for loop is iterating through the numbers 1-7 
	// The inner for loop is iterating through the numbers 0-23
	// The variable t is set to either j or 4 depending on the value of j
	// The variable x is set to dat3 at position i shifted 4 bits to the right
	// The variable y is set to dat3 at position i with a bitwise and operation with 0x0f
	// The point is then plotted at position 0,x,y with a color of 1 
	// transss is then called which likely translates the point that was just plotted 
	// A delay of 10,000 is then called
	
      for (j=1;j<8;j++)
      {
               if (j>3)
                         t=4;
               else
                         t=j;
               for (i=0;i<24;i+=j)
               {
                         x=dat3[i]>>4;
                         y=dat3[i]&0x0f;
                         point (0,x,y,1);
                         transss();
                         delay(10000);
               }
      }
}
/////////////////////////////////////////////////////////////////////
void main()
{
	
       sinter();
	while(1){
       // clear(0);
         /*play list*/
         //flash_1();
         clear(0);
         flash_2();
         flash_3();
         flash_4();
         flash_4();
         flash_5();
      flash_5();
      flash_6();
      flash_7();
      flash_8();
      flash_9();
      flash_10();
      clear (0);
      flash_11();
      flash_9();
      flash_5();
      flash_7();
      flash_5();
      flash_6();
      flash_8();
      flash_9();
      flash_10();

         }

}

//



//P0;   //573 in
//P1;  //uln2803
//P2;  //573 LE

void print() interrupt 1     ;	//is the declaration of an interrupt function. It will be executed when an interrupt is fired.
{
         uchar i;		//defines a variable i of type uchar.
         static uchar layer=0;	//defines a static variable layer of type uchar and initializes it with a value of 0.
         P1=0;			//sets all the bits of P1 to 0.
         for (i=0;i<8;i++)	//enters a for loop that will run 8 times
         {
                   P2=1<<i;	//sets the bit at position i in P2 to 1.
                   delay(3);	//delay function and passes in a value of 3.
                   P0=display[layer][i];	// sets the value of P0 to the value of display at index layer and index i.
                   delay(3);			//delay function and passes in a value of 3.
         }
         P1=1<<layer;		//sets the value of P1 at position layer to 1.
         if (layer<7) 		////checks if the value of layer is less than 7.
                   layer++;	// If it is, it increments layer by 1. 
         else 
                   layer=0;	//If not, it sets layer back to 0.
         TH0=0xc0;		//sets TH0 to 0xc0.
         TL0=0;			//sets TL0 to 0.
}
