#include <iostream>
#include <algorithm>
#include <omp.h>
#include <chrono>

bool foo(std::string s){
  bool res = false;
  for(int i = s.length() - 1; i > 0; i--){
    #pragma omp taskloop reduction(|:res)
    for(int j = 0; j < i-1; j++){
      
      std::string frst = s.substr(0,j+1);

      std::string r1str = frst;
      std::reverse(frst.begin(), frst.end());

      std::string srst = s.substr(j+1,i-j-1);

      std::string r2str = srst;
      std::reverse(srst.begin(), srst.end());

      std::string trst = s.substr(i, s.length()-i); 



      std::string r3str = trst;
      std::reverse(trst.begin(), trst.end());

      if((frst == r1str) && 
         (srst == r2str) &&
         (trst == r3str)){
           res |= true;
         }
    }
  }
  return res;
}

int main(){
  auto nw = std::chrono::system_clock::now();
  std::string str = "plbqrqbhafkaktrbsaaxpxiobebmkkeivlformfspcdtygcmgpbrekkwpgvujyfpysjsqeclwkkmntaahxferzsyxbivyrohptketkabbmzhxdffvdjbbdvpmeygvygsiglucsavhjdoyosysqmiobvcbwatprfyjnxuuihissatgfjmnzwmbhdfwjyxdxelsxsutugmsthjsblgrjtxylzwlifzuhpfvssovovblhwngcimcoxgmiirecxsawfsahwxdkpdctgozzpfdvnbrpsdevqaaxnrczldpcodubfkoevcpbonckkgnjibzxmztoilwqanashooiytjljrwwznjtmkbyhukvcqhmnnibypxcqevoggsanfgybnxujpjsecynkoguinzypssnsnmbkurkncqhgqiuglqvtwidvbprhkgdvvxgulzlacjmqtbpapdrvanifjuautebqqpfxsetvciazpdrxbtgscvczfnydhpydcbbrmlhjszigimcjjevrxqduaawvoarusqhwsjtpvygdfxyhyytwjyqyezzsrdwwbcrytgiwqqomjsusmhzjfqnihccufgcohdlxcwtitxbevzfuhytrbtqfcpedmfvuhvxsrqqxkrmnnxmyuvkngm";
  #pragma omp parallel
  #pragma omp single
  std::cout << foo(str) << std::endl;
  auto en = std::chrono::system_clock::now();
  auto duration = std::chrono::duration_cast<std::chrono::microseconds>(en-nw);
  std::cout << "Elapsed time(µSeconds): " << duration.count() << std::endl; 
}
