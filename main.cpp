#include "includes.h"

enum class color_t: unsigned char {};
constexpr color_t operator"" _c(unsigned long long int v){return color_t(v);}

std::ostream& operator<< (std::ostream& os, color_t val){
    return os << "\033[38;5;" << static_cast<int>(val)<<'m';
}

struct green_state {
    [[nodiscard]] color_t color() const {
        return *(std::min(std::begin(kGreenColors)+dark, std::end(kGreenColors)-1));
    }

    void increase_darkness(){ ++dark; }
    void reset_darkness(){ dark = 0;}

private:
    constexpr static color_t kGreenColors[] = {22_c, 22_c, 28_c, 34_c};
    int dark = 0;
};


int main(){}