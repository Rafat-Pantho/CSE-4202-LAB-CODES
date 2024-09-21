#include <stdio.h>
int bitcountChar(unsigned char value){
    int bit_count=0;
    value = ~value;
    while(value!=0){
        bit_count ++;
        value>>=1;
    }
    return bit_count;
}
int bitcountShort(unsigned short value){
    int bit_count=0;
    value = ~value;
    while(value!=0){
        bit_count ++;
        value>>=1;
    }
    return bit_count;
}
int bitcountInt(unsigned int value){
    int bit_count=0;
    value = ~value;
    while(value!=0){
        bit_count ++;
        value>>=1;
    }
    return bit_count;
}
int bitcountLong(unsigned long value){
    int bit_count=0;
    value = ~value;
    while(value!=0){
        bit_count ++;
        value>>=1;
    }
    return bit_count;
}
int bitcountLongLong(unsigned long long value){
    int bit_count=0;
    value = ~value;
    while(value!=0){
        bit_count ++;
        value>>=1;
    }
    return bit_count;
}
int main(){
    unsigned char a=0;
    unsigned short b=0;
    unsigned int c=0;
    unsigned long d=0;
    unsigned long long e=0;
    printf("Unsigned char:  %d\nUnsigned short:  %d\nUnsigned int:  %d\nUnsigned long:  %d\nUnsigned long long:  %d\n",bitcountChar(a),bitcountShort(b),bitcountInt(c),bitcountLong(d),bitcountLongLong(e));

    return 0;
}