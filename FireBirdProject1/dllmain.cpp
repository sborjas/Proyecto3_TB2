#include <fstream> 
#include <string> 
#include <iostream> 
#include "sys/stat.h" 
#ifdef WIN_NT 
#include <windows>
#include <cstring>
#define EXPORT __declspec(dllexport) 
#else 
#define EXPORT 
#endif 

using namespace std; 



extern "C" { 
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string> 
#include <iostream> 


using namespace std; 

string num;


EXPORT int test1(int* val) 
{ 
  int ret = *val * 10; 
  return ret; 
} 

EXPORT int ping(char* url) { 
    const char * ping = "ping ";

    std::string res(ping);
    res.append(url);
    int ret = system(res.c_str());
    if(ret==1){
        return 0;
    }
    else
    {
        return 1;
    }
  
}
EXPORT double pmt(double* tasa,int* periodos,double* prestamo){
    
    double v = (1 + (*tasa / 12));
    double t = (-(*periodos / 12) * 12);
    double result = (*prestamo * (*tasa / 12)) / (1 - pow(v, t));
    return result;
}

EXPORT int binADec(int* b){
    int d=0,e=0,c=0;
    while(*b>=01){
        c=0;
        while(*b>=10){

            *b=*b-10;
            c++;
        }
        d=d+*b*pow(2,e);
        e++;
        *b=c;
    }

    d=d+c*pow(2,e);
    return d;   
}

EXPORT char const* DecABin(int* numero){
    string binario = "";
    if(*numero >0){
        while(*numero>0){
            if(*numero%2 == 0){
                binario = "0" +binario;
                
            }else{
                 binario = "1"+binario;
                 
                
            }
            *numero = (int) *numero/2;
        }
    }else if(*numero==0){
        return "0";
    }else{
        return "no";
    }
    
    return binario.c_str();
    }
    
EXPORT int C2F(int *Celsius){
    return (9* *Celsius/5)+32;
}

EXPORT int F2C(int *Far){
    return (*Far -32)/(1.8);
}

EXPORT int fact(int* num){
    int res =1;
    for(int i=1;i<=*num;i++){
        res = res*i;
    }
    return res;
}

EXPORT int hex2dec(char* hexa){
    char *hexastr;
        int length = 0;
        const int base = 16;     
        int decinum = 0;
        int i;  
    
        for (hexastr = hexa; *hexastr != '\0'; hexastr++) 
        {
                length++;
        }

        hexastr = hexa;  
        for (i = 0; *hexastr != '\0' && i < length; i++, hexastr++)
        {
                
                if (*hexastr >= 48 && *hexastr <= 57) 
                {
                        decinum += (((int)(*hexastr)) - 48) * pow(base, length - i - 1);
                }
                else if ((*hexastr >= 65 && *hexastr <= 70))   
                {
                        decinum += (((int)(*hexastr)) - 55) * pow(base, length - i - 1);
                }
                else if (*hexastr >= 97 && *hexastr <= 102)   
                {
                        decinum += (((int)(*hexastr)) - 87) * pow(base, length - i - 1);
                }
                else
                {
                        cout<<"\n Invalid Hexadecimal Number...";
                }
        }
        return decinum;
}

EXPORT char const* dec2hex(int* dec_num){
    int r;
    string hexdec_num="";
    char hex[]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    string hexa(hex);
		
        while(*dec_num>0)
        {
            r = *dec_num % 16;
            hexdec_num = hexa[r] + hexdec_num;
            *dec_num = *dec_num/16;
        }
        return hexdec_num.c_str(); 
        
}

EXPORT int compareString(char* s1,char* s2){
    if(strlen(s1) == strlen(s2)){
        return 0;
        
    }else if(strlen(s1) < strlen(s2)){
    	return -1;
	}else{
		return 1;
	}
}

EXPORT char const * repetir(char *s1,int* cant){
	string temp = "";
    for(int x = 0; x<*cant; x++){
        temp+=s1;
    }
    return temp.c_str();
}

EXPORT char const* trimF(char* s1, char* remove){
	int found=-1;
	string word(s1);
	string rem (remove);
	
	do{
		found=word.find(rem,found+1);
		if(found!=-1){
			word=word.substr(0,found)+word.substr(found+rem.length());
		}	
		
	}while(found!=-1);
	return word.c_str();
} 
    
    
    
    
} 
