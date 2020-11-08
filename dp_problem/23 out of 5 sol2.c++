
 
using namespace std;
 
int our = 23;
int number[5];
 
bool out(int pos, long long result){
    if (pos == 5){
			if(result == our)
				return true;
			return false;
    }
    return 	out(pos + 1, result - number[pos]) || 
						out(pos + 1, result + number[pos]) || 
						out(pos + 1, result * number[pos]);
}
 
int main(){
  while (true){
			int cnt = 0;
      for (int i = 0; i < 5; i++){
          cin >> number[i];
          cnt += number[i];
      }
      sort(number , number + 5);
      bool found = false;
      do{
				found |= out(1 , number[0]);
			}while(next_permutation(number , number + 5));
			if (!cnt)break;
			if (!found)cout << "Impossible\n";
			else cout << "Possible\n";
  }
}
