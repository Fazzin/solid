#include <string>
#include <iostream>

class DiscountCalculator {
public:
    double vipDiscount(double amount) const {
        return amount * 0.90;
    }
    double loyalDiscount(double amount) const {
        return amount * 0.95;
    }
    double normalDiscount(double amount) const {
        return amount;
    }
};

// Included for demonstration
int main() {
    DiscountCalculator calc;
    double price = 1000;

    std::cout << "VIP Customer Price: " << calc.vipDiscount(price) << "\n";
    std::cout << "Loyal Customer Price: " << calc.loyalDiscount(price) << "\n";
    std::cout << "Other Customer Price: " << calc.normalDiscount(price) << "\n";
}
