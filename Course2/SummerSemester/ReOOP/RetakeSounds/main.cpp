//
// Created by Sybatron on 8/14/2023.
//
#include "Sound.h"
#include "Effect.h"
#include "Playlist.h"

//Go through the sound and calculate the amplitude
//Calculate the coefficient to get to the amplitude boundary
//Give it as param to NormalFunctor and create effect with it
class NormalFunctor : public Functor<double> {
private:
    double normalCoeff;
public:
    virtual ~NormalFunctor() = default;

    NormalFunctor(double normalCoeff) : normalCoeff(normalCoeff) {}

    double operator()(double sample, size_t index) const override {
        return sample * normalCoeff;
    }
};

int main() {
    std::cout << "HELLO" << std::endl;
    try {
        Playlist playlist("playlist.txt");
        playlist.playPlaylist();
    } catch (std::runtime_error &err) {
        std::cout << err.what() << std::endl;
    } catch (std::out_of_range &err) {
        std::cout << err.what() << std::endl;
    } catch (std::exception &err) {
        std::cout << err.what() << std::endl;
    }
}