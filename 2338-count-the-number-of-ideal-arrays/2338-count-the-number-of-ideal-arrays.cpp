#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1e9+7;
const int MAX = 20000; // n + maxValue 대비 넉넉하게 준비 (9769+9557도 충분히 커버)

long long fact[MAX], invFact[MAX];

// 빠른 거듭제곱 (모듈러 역원 계산용)
long long power(long long x, long long y) {
    long long res = 1;
    x %= MOD;
    while (y > 0) {
        if (y & 1) res = res * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }
    return res;
}

// 조합수 계산: nCk = n! / (k! * (n-k)!)
long long comb(int n, int k) {
    if (n < k) return 0;
    return fact[n] * invFact[k] % MOD * invFact[n-k] % MOD;
}

class Solution {
public:
    int idealArrays(int n, int maxValue) {
        // 1. 팩토리얼과 역팩토리얼 준비
        fact[0] = 1;
        for (int i = 1; i < MAX; ++i)
            fact[i] = fact[i-1] * i % MOD;

        invFact[MAX-1] = power(fact[MAX-1], MOD-2);
        for (int i = MAX-2; i >= 0; --i)
            invFact[i] = invFact[i+1] * (i+1) % MOD;
        
        // 2. 소수 리스트 만들기 (에라토스테네스의 체)
        vector<int> prime;
        vector<bool> isPrime(maxValue+1, true);
        for (int i = 2; i <= maxValue; ++i) {
            if (isPrime[i]) {
                prime.push_back(i);
                for (int j = i+i; j <= maxValue; j += i)
                    isPrime[j] = false;
            }
        }
        
        // 3. 정답 계산
        long long ans = 0;
        for (int x = 1; x <= maxValue; ++x) {
            int val = x;
            long long res = 1;
            for (int p : prime) {
                if (p * p > val) break;
                int cnt = 0;
                while (val % p == 0) {
                    val /= p;
                    cnt++;
                }
                if (cnt > 0) {
                    res = res * comb(cnt + n - 1, cnt) % MOD;
                }
            }
            if (val > 1) {
                res = res * comb(1 + n - 1, 1) % MOD;
            }
            ans = (ans + res) % MOD;
        }
        
        return (int)ans;
    }
};
