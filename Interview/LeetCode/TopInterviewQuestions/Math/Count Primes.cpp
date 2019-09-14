/*
 * Copyright (c) 2019 ManuelCH.
 *
 * This file is part of Interview-solutions 
 * (see https://github.com/akotadi).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */
/*
Count the number of prime numbers less than a non-negative number, n.

Example:

Input: 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
*/

class Solution {
public:
    int countPrimes(int n) {
        if(n < 2) return 0;
        segmented_sieve(n-1);
        
        return count;
    }
private: 
    int64_t count = 0;
    
    /// Set your CPU's L1 data cache size (in bytes) here
    const int64_t L1D_CACHE_SIZE = 32768;

    /// Bitmasks needed to unset bits corresponding to multiples
    const int64_t unset_bit[16] =
    {
      ~(1 << 0), ~(1 << 0),
      ~(1 << 1), ~(1 << 1),
      ~(1 << 2), ~(1 << 2),
      ~(1 << 3), ~(1 << 3),
      ~(1 << 4), ~(1 << 4),
      ~(1 << 5), ~(1 << 5),
      ~(1 << 6), ~(1 << 6),
      ~(1 << 7), ~(1 << 7)
    };

    const int64_t popcnt[256] =
    {
      0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4,
      1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
      1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
      2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
      1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
      2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
      2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
      3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
      1, 2, 2, 3, 2, 3, 3, 4, 2, 3, 3, 4, 3, 4, 4, 5,
      2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
      2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
      3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
      2, 3, 3, 4, 3, 4, 4, 5, 3, 4, 4, 5, 4, 5, 5, 6,
      3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
      3, 4, 4, 5, 4, 5, 5, 6, 4, 5, 5, 6, 5, 6, 6, 7,
      4, 5, 5, 6, 5, 6, 6, 7, 5, 6, 6, 7, 6, 7, 7, 8
    };

    /// Generate primes using the segmented sieve of Eratosthenes.
    /// This algorithm uses O(n log log n) operations and O(sqrt(n)) space.
    /// @param limit  Sieve primes <= limit.
    ///
    void segmented_sieve(int64_t limit)
    {
      int64_t sqrt = (int64_t) std::sqrt(limit);
      int64_t sieve_size = std::max(sqrt, L1D_CACHE_SIZE);
      int64_t segment_size = sieve_size * 16;
      count = (limit == 1) ? -1 : 0;

      // we sieve primes >= 3
      int64_t i = 3;
      int64_t s = 3;

      // vector used for sieving
      std::vector<uint8_t> sieve(sieve_size);
      std::vector<uint8_t> is_prime(sqrt + 1, true);
      std::vector<int64_t> primes;
      std::vector<int64_t> multiples;

      for (int64_t low = 0; low <= limit; low += segment_size)
      {
        std::fill(sieve.begin(), sieve.end(), 0xff);

        // current segment = [low, high]
        int64_t high = low + segment_size - 1;
        high = std::min(high, limit);
        sieve_size = (high - low) / 16 + 1;

        // generate sieving primes using simple sieve of Eratosthenes
        for (; i * i <= high; i += 2)
          if (is_prime[i])
            for (int64_t j = i * i; j <= sqrt; j += i)
              is_prime[j] = false;

        // initialize sieving primes for segmented sieve
        for (; s * s <= high; s += 2)
        {
          if (is_prime[s])
          {
               primes.push_back(s);
            multiples.push_back(s * s - low);
          }
        }

        // sieve segment using bit array
        for (std::size_t i = 0; i < primes.size(); i++)
        {
          int64_t j = multiples[i];
          for (int64_t k = primes[i] * 2; j < segment_size; j += k)
            sieve[j >> 4] &= unset_bit[j & 15];
          multiples[i] = j - segment_size;
        }

        // unset bits > limit
        if (high == limit)
        {
          int64_t bits = 0xff << (limit % 16 + 1) / 2;
          sieve[sieve_size - 1] &= ~bits;
        }

        // count primes
        for (int64_t n = 0; n < sieve_size; n++)
          count += popcnt[sieve[n]];
      }
    }
};