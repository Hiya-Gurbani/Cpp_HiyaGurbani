struct Multiplier {
    int factor;
    Multiplier(int f) : factor(f) {}
    int operator()(int x) const { return x * factor; }
};

int main() {
    Multiplier triple(3);
    Multiplier twice(2);

    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::vector<int> result(nums.size());

    std::transform(nums.begin(), nums.end(), result.begin(), triple);

    std::transform(nums.begin(), nums.end(), result.begin(), twice);
}
