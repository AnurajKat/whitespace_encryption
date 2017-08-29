/*
*	white space if 0
*	tab space if 1
*	
*	additions of ASCII values of even positions and subtraction of ASCII values of odd positions
*
*/

#include <iostream>
#include <fstream>
#include <string>
#include <bitset>

int main()
{
    std::ifstream infile("text.txt");
    std::ofstream ofile("temp.txt");
    std::string str, enckey="";
    std::cout<<"enter encryption key :";
    std::cin>>enckey;
    int mul_val=0;
    // please do suggest ideas to make the key stronger
    for(int i=0;i<enckey.length();i++)
    {
	    if(i%2==0)
	    	mul_val = mul_val + int(enckey.at(i));
	    else
		mul_val = mul_val - int(enckey.at(i));
    }
    std::cout<<"key :"<<mul_val<<std::endl;
    while (std::getline(infile,str))
    {
	int len=str.length();
        for(int i=0;i<len;i++)
	{ 
	    char ch=str.at(i);
            int asc_val= int(ch)+mul_val;	//inclusion of key factor
	    std::string newline="";
	    std::string BinaryValue = std::bitset<8>(asc_val).to_string();		//conversion to 8-bit binary
            for(unsigned int j=0;j<BinaryValue.size();j++)
            {
		if (BinaryValue.at(j) == '0')
			newline = newline + (char)32;		//ASCII values used as direct charecters were not working
		if(BinaryValue.at(j) == '1')
			newline = newline + (char)9;
            }
            ofile<<newline<<std::endl;
        }
	ofile<<std::endl;
    }
    std::cout<<"encryption complete."<<std::endl;
    ofile.close();
}
