#include <iostream>

class Move {
private:
    double x_;
    double y_;
public:
    Move(double a = 0, double b = 0) {
        x_ = a;
        y_ = b;
    }
    void showmove() const {
        for (int i = 0; i < 25; i++)
            std::cout << '*';
        std::cout << "\nx: "   << x_
                  << "\ny: " << y_ << "\n";
    }
    Move add(const Move &m) const {
        Move temp;
        temp.x_ = this->x_ + m.x_;
        temp.y_ = this->y_ + m.y_;
        return temp;
    }
    void reset(double a = 0, double b = 0) {
        x_ = a;
        y_ = b;
    }
};

int main() {
    Move first(3, 5), second(3);
    first.showmove();
    second.showmove();

    Move third = first.add(second);
    third.showmove();

    first.reset();
    first.showmove();

    return 0;
}

