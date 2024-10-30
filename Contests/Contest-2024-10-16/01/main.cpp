#include <iostream>

class Keeper{
    int trash;
    int secret;
    
public:
    Keeper(){
        std::cin >> secret;
    }
};

// Ваш код здесь


struct Hack {
    int trash;
    int secret;
};
int hack_it(Keeper keeper) {
    Hack* h = reinterpret_cast<Hack*>(&keeper);
    return h->secret;
}


int main(){
    Keeper keeper;
    int secret= hack_it(keeper);
    std::cout << secret;
}
