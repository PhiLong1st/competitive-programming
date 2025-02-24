
/*
    Code by: KoKoDuDu
    Created: 27.11.2024 01:38:43
*/
#include <bits/stdc++.h>

using namespace std;

#define int long long
#define pll pair<int, int>

const int MOD = 1e9 + 7;


struct NumberTheory {
    // Calculate modular inverse using Extended Euclidean algorithm
    int inverse(int i, int MOD) {
        if (i == 1)
            return 1;
        return (MOD - (MOD / i) * inverse(MOD % i, MOD) % MOD + MOD) % MOD;
    }

    // Perform modular exponentiation (a * b % MOD)
    int mod_mul(int a, int b, int n) {
        int ret = 0;
        for (; b; b >>= 1) {
            if (b & 1) {
                ret = ret + a;
                if (ret >= n) ret %= n;
            }
            a = a + a;
            if (a >= n) a %= n;
        }
        return ret;
    }

    // Perform modular exponentiation (b ^ p % MOD)
    int mod_exp(int b, int p, int n) {
        int ret = 1;
        for (; p; p >>= 1) {
            if (p & 1) ret = mod_mul(ret, b, n);
            b = mod_mul(b, b, n);
        }
        return ret;
    }

    // Check if a number is a perfect square
    bool check_perfect_square(int n) {
        int t = sqrt(n);
        for (int di = -1; di < 2; ++di) {
            if ((t + di) * (t + di) == n) {
                return 1;
            }
        }
        return 0;
    }

    // Generate an array of minimum prime divisors for all numbers from 1 to n
    vector<int> get_array_min_prime_divisor(int n) {
        vector<int> min_prime(n + 1);
        iota(min_prime.begin(), min_prime.end(), 0);
        for (int i = 2; i * i <= n; ++i) {
            if (min_prime[i] == i) {
                for (int j = i * i; j <= n; j += i) {
                    if (min_prime[j] == j)
                        min_prime[j] = i;
                }
            }
        }
        return min_prime;
    }

    // Generate an array of modular inverses for the elements of array `a`
    // assuming MOD is a prime number (using Fermat's Little Theorem)
    vector<int> get_array_inverse(vector<int> a, int MOD) {
        int n = a.size() - 1;
        vector<int> ans(n + 1), suffix_mul(n + 1);

        int mul_product = 1, prefix_mul = 1;

        for (int i = n; i >= 1; --i)
        {
            a[i] %= MOD;
            suffix_mul[i] = (i == n) ? a[i] : (suffix_mul[i + 1] * a[i]) % MOD;
            mul_product = (mul_product * a[i]) % MOD;
        }

        mul_product = mod_exp(mul_product, MOD - 2, MOD);

        for (int i = 1; i <= n; ++i)
        {
            ans[i] = (prefix_mul * (i == n ? 1 : suffix_mul[i + 1]) % MOD) * mul_product % MOD;
            prefix_mul = (prefix_mul * a[i]) % MOD;
        }

        return ans;
    }

    //Get primes from 1 to n
    vector<int> sieve_eratosthenes(int n) {
        vector<int> isPrime(n + 1), sieve;
        isPrime[1] = 1;
        for (int i = 2; i <= n; ++i) {
            if (!isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = 1;
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            if (!isPrime[i]) {
                sieve.push_back(i);
            }
        }
        return sieve;
    }

    //Check n is prime
    bool MillerRabin(int n) {
        function<bool(int, int, int, int)> test = [&](int a, int n, int k, int m) {
            int mod = mod_exp(a, m, n);
            if (mod == 1 || mod == n - 1) return true;
            for (int l = 0; l < k; ++l) {
                mod = mod_mul(mod, mod, n);
                if (mod == n - 1) return true;
            }
            return false;
            };
        vector<int> checkSet = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41 };
        for (auto a : checkSet) if (n == a) return true;
        if (n < checkSet.back()) return false;
        int k = 0, m = n - 1;
        while (m % 2 == 0) {
            m /= 2;
            k++;
        }
        for (auto a : checkSet) if (!test(a, n, k, m)) return false;
        return true;
    }

    //Get euler's totient array
    vector<int> get_euler_totient(int n) {
        vector<int>ans(n + 1);
        iota(ans.begin(), ans.end(), 0);
        for (int i = 2; i <= n; ++i) {
            if (ans[i] == i) {
                for (int j = i; j <= n; j += i) {
                    ans[j] -= ans[j] / i;
                }
            }
        }
        return ans;
    }

    //Get Mobius Array
    vector<int> get_mobius_array(int n) {
        vector<int> mu(n + 1);
        mu[1] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 2 * i; j <= n; j += i) {
                mu[j] -= mu[i];
            }
        }
        return mu;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1), d(1000010);
    NumberTheory nb;
    for (int i = 1; i <= n; ++i) {
        cin >> a[i];
        d[a[i]]++;
    }
    vector<int> mu = nb.get_mobius_array(1000000);
    int ans = 0;
    for (int i = 1; i < 1000001;i++) {
        if (mu[i] == 0) continue;
        int res = 0;
        for (int j = i; j < 1000001; j += i) {
            res += d[j];
        }
        ans += (res * (res - 1)) / 2 * mu[i];
    }
    cout << ans;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}