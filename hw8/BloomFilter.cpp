#include "BloomFilter.h"


  BloomFilter::BloomFilter (unsigned int size ){
 if(size <= 11){
  size1 = 11;
 }
 else if(size <= 23){
  size1 = 23;
 }
 else if(size <= 47){
  size1 = 47;
 }
 else if(size <= 97){
  size1 = 97;
 }
 else if(size <= 197){
  size1 = 197;
 }
 else if(size <= 397){
  size1 = 397;
 }
 else if(size <= 797){
  size1 = 797;
 }
 else if(size <= 1597){
  size1 = 1597;
 }
 else if(size <= 3203){
 size1 = 3203;
 }
 else if(size <= 6421){
  size1 = 6421;
 }
 else if(size <= 12853){
  size1 = 12853;
 }
 else if(size <= 25717){
  size1 = 25717;
 }
 else if(size <= 51437){
size1 = 51437;
 }
 else{
  size1 = 51437;
 }

  		arr= new bool[size1];
  		for(unsigned int i=0;i<size1;i++){
  			arr[i]=false;
  		}
  }


  BloomFilter::~BloomFilter (){

	delete [] arr;
}

  void BloomFilter::insert (const std::string input){
  	int h1=hash1(input);
  	int h2=hash2(input);
  	int h3=hash3(input);

  	arr[h1]=true;
  	arr[h2]=true;
  	arr[h3]=true;
  }


  bool BloomFilter::contains (std::string input){
  	int h1=hash1(input);
  	int h2=hash2(input);
  	int h3=hash3(input);
  	if(arr[h1]==true&& arr[h2]==true &&arr[h3]==true){
  		return true;
  	}
  	else{
  		return false;
  	}
  	
  }

  int BloomFilter::hash1 (std::string input) const{
      int w[21];
      for(int i=0;i<21;i++){
        w[i]=0;
      }

      int a=20;

      for (int i=input.size()-1; i>=0; i--)
      {
        if ( (input.size()-i) % 3 == 0)
          {
            w[a] += 31*31*helper(input[i]);
            a--;
          }

        else if ((input.size()-i) % 3 == 1 )
        {
          w[a] += helper(input[i]);
        }

        else
        {
          w[a] += 31*helper(input[i]);
        }
      }

  			int r0=50161;int r1=22696;int r2=273;int  r3=19159;int r4=14692;int  r5=8255; 
  			int r6=20154; int r7=13109; int r8=11098;int  r9=866; int r10=15643;int  r11=11554; int r12= 38297;int  
  			r13= 42447;int  r14=9827;int  r15=9648;int  r16=45568;int  r17= 47227;int  r18= 48459;int  r19=30713;int  r20=9110;

  		int result = (long(r0*w[0])+long(r1*w[1])+long(r2*w[2])+long(r3*w[3])+long(r4*w[4])+long(r5*w[5])+long(r6*w[6])+long(r7*w[7])+long(r8*w[8])+long(r9*w[9])+long(r10*w[10])+long(r11*w[11])+long(r12*w[12])+
  			long(r13*w[13])+long(r14*w[14])+long(r15*w[15])+long(r16*w[16])+long(r17*w[17])+long(r18*w[18])+long(r19*w[19])+long(r20*w[20]))%size1;
      // cout<<w[20]<<endl;
      // cout<<w[19]<<endl;
      // cout<<w[18]<<endl;
      // cout<<w[17]<<endl;


  		return result;
  }

  int BloomFilter::hash2 (std::string input) const{
int p=0;
  		if(size1 <= 11){
  p = 7;
 }
 else if(size1 <= 23){
  p = 19;
 }
 else if(size1 <= 47){
 p = 43;
 }
 else if(size1 <= 97){
  p = 89;
 }
 else if(size1 <= 197){
 p = 193;
 }
 else if(size1 <= 397){
 p= 389;
 }
 else if(size1 <= 797){
  p = 787;
 }
 else if(size1 <= 1597){
  p = 1583;
 }
 else if(size1 <= 3203){
 p = 3191;
 }
 else if(size1 <= 6421){
  p = 6397;
 }
 else if(size1 <= 12853){
  p = 12841;
 }
 else if(size1 <= 25717){
  p = 25703;
 }
 else if(size1 <= 51437){
p= 51431;
 }
 else{
 p = 51431;
 }
      int w[21];
      for(int i=0;i<21;i++){
        w[i]=0;
      }

      int a=20;

      for (int i=input.size()-1; i>=0; i--)
      {
        if ( (input.size()-i) % 3 == 0)
          {
            w[a] += 31*31*helper(input[i]);
            a--;
          }

        else if ((input.size()-i) % 3 == 1 )
        {
          w[a] += helper(input[i]);
        }

        else
        {
          w[a] += 31*helper(input[i]);
        }
      }


      //cout << "p " << p << endl;
        int r0=50161;int r1=22696;int r2=273;int  r3=19159;int r4=14692;int  r5=8255; 
        int r6=20154; int r7=13109; int r8=11098;int  r9=866; int r10=15643;int  r11=11554; int r12= 38297;int  
        r13= 42447;int  r14=9827;int  r15=9648;int  r16=45568;int  r17= 47227;int  r18= 48459;int  r19=30713;int  r20=9110;

int result = p- (long(r0*w[0])+long(r1*w[1])+long(r2*w[2])+long(r3*w[3])+long(r4*w[4])+
  long(r5*w[5])+long(r6*w[6])+long(r7*w[7])+long(r8*w[8])+long(r9*w[9])+long(r10*w[10])+long(r11*w[11])+long(r12*w[12])+
        long(r13*w[13])+long(r14*w[14])+long(r15*w[15])+long(r16*w[16])+long(r17*w[17])+
        long(r18*w[18])+long(r19*w[19])+long(r20*w[20]))%p;

  		return result;

  }





  int BloomFilter::hash3 (std::string input) const{
  		int w[21];
  		for(int i=0;i<21;i++){
  			w[i]=0;
  		}

      int a=20;

      for (int i=input.size()-1; i>=0; i--)
      {
        if ( (input.size()-i) % 3 == 0)
          {
            w[a] += 31*31*helper(input[i]);
            a--;
          }

        else if ((input.size()-i) % 3 == 1 )
        {
          w[a] += helper(input[i]);
        }

        else
        {
          w[a] += 31*helper(input[i]);
        }
      }


 
  		  		
  		int result = (long(w[0])+long(w[1])+long(w[2])+long(w[3])+long(w[4])+long(w[5])+
        long(w[6])+long(w[7])+long(w[8])+long(w[9])+long(w[10])
        +long(w[11])+long(w[12])+
  			long(w[13])+long(w[14])+long(w[15])+long(w[16])+long(w[17])+long(w[18])+long(w[19])+long(w[20]))%size1;
  		return result;
  }



  int BloomFilter::helper(char& input) const{
    if(isalpha(input)){
      return input-92;
    }
  	 if(input=='.'){
  	 	return 1;
  	 }
  	 if(input=='/'){
  	 	return 2;
  	 }
  	 if(input==':'){
  	 	return 3;
  	 }
  	 else{
  	 	return 4;
  	 }
  	 
  }




// int main(){

// 	BloomFilter a(132);
// 	cout<<a.hash1("h/cs_rules");

// }
