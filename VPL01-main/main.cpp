#include <iostream>
#include <string>
using namespace std;
int main(){
 string palavra;
 int a=0,e=0,i=0,o=0,u=0;
 cin >> palavra;
 for(int x=0; x<palavra.size(); x++){
    if(palavra[x]=='a') a++;
    if(palavra[x]=='e') e++;
    if(palavra[x]=='i') i++;
    if(palavra[x]=='o') o++;
    if(palavra[x]=='u') u++;
 }

    if(a!=0) cout << "a "<< a << endl;
    if(e!=0) cout << "e "<< e << endl;
    if(i!=0) cout << "i "<< i << endl;
    if(o!=0) cout << "o "<< o << endl;
    if(u!=0) cout << "u "<< u << endl;

return 0 ;

}