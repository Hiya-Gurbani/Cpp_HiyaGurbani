#include <vector>
#include <algorithm>

template <typename T>
class Repository
{
private:
    std::vector<T> items;

public:
    void add(const T& item) {
        items.push_back(item);
    }

    bool remove(const T& item) {
        auto it = std::find(items.begin(), items.end(), item);
        if (it != items.end())
        {
            items.erase(it);
            return true;
        }
        return false;
    }

    const std::vector<T>& getAll() {
        return items;
    }
};

int main() {
    Repository<int> numberRepo;
    numberRepo.add(10);
    numberRepo.add(20);

    Repository<std::string> stringRepo;
    stringRepo.add("Hello");
    stringRepo.add("World");
}
