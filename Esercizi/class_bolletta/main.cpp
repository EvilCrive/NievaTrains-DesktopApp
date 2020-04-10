#include <iostream>
#include "bolletta.h"
#include "testing_main.h"
using std::cout;
using std::cin;
using std::endl;


int main()
{
    std::string selezione;
    while(selezione!="exit"){
        cin>>selezione;
        if(selezione=="orario") testing_orario();
        if(selezione=="telefonata") testing_telefonata();
        if(selezione=="bolletta")   testing_bolletta();
        if(selezione=="william")    std::cout<<"DOG RATTTTT APEEEEEEEEE\nHope ur doing well lad :3 uwu owo <3\nby Crivez\nUr favorite dog\n\n";
    }





}

