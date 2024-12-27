#include <bits/stdc++.h>
using namespace std;
const int mod = 1000000007;
void add(int&a, const int& b){
  if ((a+=b) >= mod) a -= mod;
}

int save[50007][1007];

int dp(int i, int k){//so luong xau do dai i, tong cac chu so <= k
  if (k < 0) return 0;
  if (i == 0) return 1;
  auto &ans = save[i][k];
  if (ans) return ans-1;
  for (int c = 0; c < 3; ++c)
    if (c <= k) add(ans, dp(i-1, k-c));
  return ans++;
}

namespace chatGPT{
  
// Hàm chia chuỗi biểu diễn số lớn cho 3 và trả về thương và số dư
std::pair<std::string, int> divideBy3(const std::string &num) {
    std::string result;
    int remainder = 0;
    
    for (char digit : num) {
        int current = remainder * 10 + (digit - '0');
        result += (current / 3) + '0';
        remainder = current % 3;
    }

    // Xóa các số 0 ở đầu nếu có
    result.erase(0, result.find_first_not_of('0'));
    
    // Nếu kết quả là rỗng (nghĩa là số 0), trả về "0"
    if (result.empty()) {
        result = "0";
    }

    return {result, remainder};
}

// Hàm chuyển từ thập phân sang tam phân với đầu vào là chuỗi biểu diễn số lớn
std::string decimalToBase3(std::string decimalNumber) {
    if (decimalNumber == "0") return "0";

    std::string base3 = "";
    while (decimalNumber != "0") {
        auto tmp = divideBy3(decimalNumber);
        auto quotient = tmp.first;
        auto remainder = tmp.second;
        base3 += std::to_string(remainder);
        decimalNumber = quotient;
    }

    std::reverse(base3.begin(), base3.end());
    return base3;
}

}

int main() 
{
  //cout << chatGPT::decimalToBase3("11");return 0;
  //cout<<dp(3, 2);return 0;//000, 001, 010, 100, 002, 011, 020, 101, 111, 200
  int T;
  cin >> T;
  while (T--){
    string L, R;
    int k;
    cin >> L >> R >> k;
    L = chatGPT::decimalToBase3(L);
    R = chatGPT::decimalToBase3(R);
    L = string(R.size()-L.size(), '0') + L;
    auto cal = [&](string R, int k){
      int ans = 0, sum = 0;
      for (int i = 0; i < R.size(); ++i){
        for (int c = '0'; c < R[i]; ++c){
          //X = R0R1...R[i-1]c.....
          add(ans, dp(R.size()-i-1, k-sum-(c-'0')));
        }
        sum += R[i]-'0';
      }
      add(ans, sum <= k);
      return ans;
    };
    //cout << cal("100", 1);return 0;000, 001, 010
    int ans = cal(R, k);
    {//--L
      int i = L.size()-1;
      while (L[i] == '0'){
        L[i] = '2';
        --i;
      }
      --L[i];
    }
    ans = (ans+mod-cal(L, k))%mod;
    cout << ans << '\n';
  }
}