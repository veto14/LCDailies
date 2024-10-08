#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

long long dividePlayers(vector<int>& skill) {
    int n = skill.size();
    long long total = accumulate(skill.begin(), skill.end(), 0LL);
    
    if (total % (n / 2) != 0) {
        return -1;  // If total skill can't be divided evenly.
    }

    int target = total / (n / 2);
    long long sum_chemistry = 0;
    
    sort(skill.begin(), skill.end());

    for (int i = 0; i < n / 2; ++i) {
        if (skill[i] + skill[n - i - 1] != target) {
            return -1;  // If we can't form a valid team.
        }
        sum_chemistry += 1LL * skill[i] * skill[n - i - 1];
    }
    
    return sum_chemistry;
}
