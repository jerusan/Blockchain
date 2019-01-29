#include<iostream>
#include<ctime>
#include<cstdlib>

using namespace std;

string makePrivateKey(){
  //Generate private key of size 64 characters
  srand(unsigned(time(0)));
  const string hex = "0123456789ABCDEF";
  string address = "";

  for(int i=0; i<64; i++){
    address += hex[rand()%16];//Generates hex
    //character by choosing the index of the Hex string randomly
  }
  
  return address;
}

string makePublicKey(string privateAddr){
  //Generate public key of size 128 Hex characters
  //this is not real ECDSA algorithm, I'm just
  //duplicating the values to get the point across.
  //ECDSA(private address);
  string publicAddr = "";
  //publicAddr += privateAddr;

  for(int i = 0; i<128; i++){
    publicAddr += privateAddr[rand()%64];
  }
  
  return publicAddr;
}

string makeEthAddress(string publicAddr){
  string addr ="0x";
  //Keccak256 hashing algorithm is used to generate Ethereum address
  //I will be using some random hashing to genrate address
  //Keccak256() ==> string of 64 characters is generated
  //Only last 40 characters is chosen as address by appending 0x infront
  //to make it easy to recognize for human eye

  for(int i = 0; i<40; i++){
    addr += publicAddr[rand()%64];
  }

  return addr;
  
}
int main(){
  string privateKey = makePrivateKey();
  string publicKey = makePublicKey(privateKey);
  string EthAddress = makeEthAddress(publicKey);
  cout<<"Private Key: "<<privateKey<<endl;
  cout<<"Public Key: "<<publicKey<<endl;
  cout<<"Ethereum address: "<<EthAddress<<endl;
  return 0;
}
