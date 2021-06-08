#include <iostream>
#include <vector>
#include <cmath>
#include <unordered_set>

using namespace std;

int GetPrizePlace(size_t result_vas, const std::vector<size_t>& nums) {
    if (result_vas == 0) {
        return 0;
    }
    //Search for the maximum prize place that can be taken with the found number
    size_t max_prob_place = 0;
    for (size_t i = 0; i < nums.size(); ++i) {
        if (nums[i] > result_vas) {
            max_prob_place++;
        }
    }

    return max_prob_place + 1;
}

size_t DefineResultVasily(const std::vector<size_t>& nums) {
    if (nums.size() < 3u) {
        return 0;
    }

    bool find_el = false;
    size_t ind_need_el = 0;
    size_t ind_max = (nums[0] > nums.back()) ? 0 : nums.size() - 1u;

    //Search for the desired number that matches the search criteria
    for (size_t i = 1; i < nums.size() - 1; ++i) {
        size_t curr_el = nums[i];
        if (curr_el > nums[ind_max]) {
            find_el = false;
            ind_max = i;
        }

        else if (curr_el % 5 == 0 && curr_el % 2 != 0 && curr_el > nums[i + 1]) {
            if (find_el) {
                ind_need_el = (curr_el > nums[ind_need_el]) ? i : ind_need_el;
            }
            else {
                find_el = true;
                ind_need_el = i;
            }
        }
    }

    if (!find_el || (find_el && ind_need_el <= ind_max)) {
        return 0;
    }

    return nums[ind_need_el];
}

int main() {
    size_t size;
    cin >> size;
    std::vector<size_t> numbers(size);
    for (size_t i = 0; i < size; i++) {
        size_t a;
        cin >> a;
        numbers[i] = a;
    }

    std::cout << GetPrizePlace(DefineResultVasily(numbers), numbers) << std::endl;

    return 0;
}