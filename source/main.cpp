#include"pokemon.hpp"

int main() {
    auto ull=pokemon::read_ull(
        [](unsigned long long num){
            return num>=1&&num<=18;
        },
        "num not in [1,18]"
    );
    return 0;
}
