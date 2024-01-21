#include "bitset.hpp"

Bitset::Bitset() {
    //Creating the Bitset with a size 8 as default 
    Bitset_pointer = new uint8_t[8];
    //set length variable
    length = 8;
    //loop through bitset and set all bits to zero
    for(int i = 0; i < length; i++){
        *(Bitset_pointer + i) = 0;
        valid = true;
    }
}

Bitset::Bitset(intmax_t size) {
    //Create a bitset of the given size
    Bitset_pointer = new uint8_t[size];
    //set length to the inputed size
    length = size;
    //check  to see if the input length is valid
    if(length <= 0){
        //declare valid variable false if not
        valid = false;
    }else{
        //declare valid variable true if it is and loop through bitset and set all bits to zero
        for(int i = 0; i < length; i++){
            *(Bitset_pointer + i) = 0;
        }
        valid = true;
    }
    
}
 
Bitset::Bitset(const std::string & value) {
    //get length of value
    length  = value.length();
    //dynamically allocate array
    Bitset_pointer = new uint8_t[length];

    //loop through length of string
    for(int i = 0; i < length; i++){
        //if the value at the index is 1 set the Bitset at the index to 1 and make valid true
        if(value[i] == '1'){
            *(Bitset_pointer + i) = 1;
            valid = true;
        }else if(value[i] == '0'){
            *(Bitset_pointer + i) = 0;
            valid = true;
        }//if the value at that index is not 0 or 1, set valid to false and break loop
        else{
            valid = false;
            break;
        }
    }
}

Bitset::~Bitset() {
    //delete array and set pointer to null pointer
    delete[] Bitset_pointer;
    Bitset_pointer = nullptr;
}
 
intmax_t Bitset::size() const{
    //return size of arrayP
    return length;
}

bool Bitset::good() const{
    //return if array is valid
    return valid;
}

void Bitset::set(intmax_t index) {
    //check if index is in valid range
    if(index < 0 || index >= length){
        //make valid false if not in range
        valid = false;
    }
    else{
        //if in range, change value at index to 1
        *(Bitset_pointer + index) = 1;
    }
}


void Bitset::reset(intmax_t index){
    //check if index is in valid range
    if(index < 0 || index >= length){
        //make valid false if not in range
        valid = false;
    }
    else{
        //if in range, change value at index to 0
        *(Bitset_pointer + index) = 0;
    }
}


void Bitset::toggle(intmax_t index){
    //check if index is in valid range
    if(index < 0 || index >= length){
        //make valid false if not in range
        valid = false;
    }
    else if(*(Bitset_pointer + index) == 0){
        //if value at index is zero, change it to 1
        *(Bitset_pointer + index) = 1;
    }
    else{
        //if value at index is one, change it to 0
        *(Bitset_pointer + index) = 0;
    }
}


bool Bitset::test(intmax_t index){
    //check if index is in valid range
    if(index < 0 || index >= length){
        //make valid false if not in range and returns false
        valid = false;
        return false;
    }
    else{
        //return the value of Bitset at index
        return *(Bitset_pointer + index);
    }
}

std::string Bitset::asString() const{
    //declare empty string
    std::string str = "";
    //loop through length of Bitset
    for(int i = 0; i < length; i++){
        //if the value at the index is 1, add 1 to the string
        if(*(Bitset_pointer + i) == 1){
            str += '1';
        }
        //else add a 0 to the string
        else{
            str += '0';
        }
    }
    //return the made string
    return str;
}