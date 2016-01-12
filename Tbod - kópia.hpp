/*
    jednoduche riesenie jednorozmernej casovej rovnice.
    Spraví sa rada jednoduchý
*/

#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <complex>
#include "complexF01.hpp"

#include "global.hpp"
#include "funkcia1D.hpp"


using namespace std;

int main()
{
    // nastavenie konstant
    init_global();
    init_konstant();

    // vytvorenie sceny
    schr_funk ele01;
    ele01.init();

  /*  ele01.pix_dx=1;
    ele01.m.real(9.109/1000000000000000000000.0);
    ele01.m.imag(0);
    ele01.d.real(1.0/10000000000);
    ele01.d.imag(0);*/
    ele01.poz.x=150;
    ele01.poz.y=400;

    // je to vporiadku len treba e3te zazalohova5 do fii_old
    for (int i=0;i<500;i++){
        ele01.bod[i].fii_old=ele01.bod[i].fii;
    }

    for (int i=0;i<500;i++){
      //  cout << "pozx:  " << i << "  d2x:  real " << ele01.d2x(i).real() << " imag " << ele01.d2x(i).imag() << endl;
        cout << "takze pisane vnutorne: " << ele01.d2x_5bodov(i) << endl;
    }


    // Create the main window
    sf::RenderWindow app(sf::VideoMode(800, 600), "SFML window");
    app_pointer=&app;


	// Start the game loop
    while (app.isOpen())
    {
        // Process events
        sf::Event event;
        while (app.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                app.close();
        }

        // Clear screen
        app.clear();

        // Draw the scene
        ele01.make_step2();
        ele01.draw();

        // Update the window
        app.display();
    }

    //uvodna skuska
    complex<double> a;
    double b;
    a.real(10);
    a.imag(5);
    b=3;
    cout << " skuska komplexnych cisiel " << a+b << " ?";
    cout << "potvora " << a*b*1.0;

    // takže komplexné čísla fungujú
/*    complex<long double> a,b;
    a.real(1000);
    a.imag(4000);
    b.real(3);
    b.imag(5);
    a=sin(a);
    cout << "skuška complex: " << a.real() << "   " << a.imag() << endl;
    for (int i=1;i<30; i++){
        cout << "pecko  " << i << " je " << ele01.p[i] << endl;
    }
    cout << "fii v bode 10  " << ele01.bod[10].fii;
*/
    return EXIT_SUCCESS;
}









